#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <vcclr.h>
#include "Enemy.h"
#include "Tile.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class DungeonGenerator {
private:
    // ������� ������
    const int TILE_SIZE = 32;
    Random^ random; // ��������� ��������� ���� ��� ���������� ��������� �����

    // 2D ������ ������
    array<Tile^, 2>^ dungeonMap;

    int mapWidth = 20;
    int mapHeight = 20;

    // ��������� ����������� ��������
    enum class Direction {
        Right,
        Left,
        Up,
        Down
    };

    // ������� ���� ��� ��������� �����
    void CreateStart(int x, int y) {
        dungeonMap[x, y]->isStart = true;
    }

    // ��������� ����������
    void GenerateDungeon() {
        // �������� �������
        dungeonMap = gcnew array<Tile^, 2>(mapWidth, mapHeight);
        random = gcnew Random;

        // ������������� ����� ������� �������
        for (int x = 0; x < mapWidth; x++) {
            for (int y = 0; y < mapHeight; y++) {
                dungeonMap[x, y] = gcnew Tile();
            }
        }

        // ��������� ����� ��� ����� (������ 3 ����� �� ����)
        int startX = random->Next(3, mapWidth / 4);
        int startY = random->Next(3, mapHeight / 4);
        dungeonMap[startX, startY]->isStart = true;

        int currentX = startX;
        int currentY = startY;

        array<Direction>^ initialDirections = {
            Direction::Right,
            Direction::Down
        };
        Direction currentDirection = initialDirections[random->Next(2)];
        Direction lastDirection = currentDirection;

        int pathCount = random->Next(4, 9);
        for (int path = 0; path < pathCount; path++) {
            // �������� �������� � �����
            bool canContinueDirection = CanContinueInCurrentDirection(
                currentX, currentY, currentDirection, 3
            );

            if (path > 1 && !canContinueDirection) {
                // �������� ��������������� ��� ���������������� �����������
                currentDirection = GetAlternativeDirection(currentDirection);
            }
            else if (path > 1) {
                // ��������� ���������� ���������� �����������
                array<Direction>^ possibleDirections = GetPossibleDirections(lastDirection);
                currentDirection = possibleDirections[random->Next(possibleDirections->Length)];
            }

            int corridorLength = random->Next(3, 7);

            // �������� ��������
            CreateCorridor(currentX, currentY, corridorLength, currentDirection);

            // ���������� ������� �������
            switch (currentDirection) {
            case Direction::Right: currentX += corridorLength; break;
            case Direction::Left: currentX -= corridorLength; break;
            case Direction::Up: currentY -= corridorLength; break;
            case Direction::Down: currentY += corridorLength; break;
            }

            // �������� ������� �� ��������
            if (currentDirection != lastDirection) {
                CreateRoom(currentX, currentY);
            }

            lastDirection = currentDirection;
        }

        GenerateWalls();
    }

    // �������� ����������� ����������� � ������� �����������
    bool CanContinueInCurrentDirection(int currentX, int currentY, Direction direction, int safetyMargin) {
        switch (direction) {
        case Direction::Right:
            return (mapWidth - currentX) > (safetyMargin + 3);
        case Direction::Left:
            return currentX > (safetyMargin + 3);
        case Direction::Down:
            return (mapHeight - currentY) > (safetyMargin + 3);
        case Direction::Up:
            return currentY > (safetyMargin + 3);
        default:
            return false;
        }
    }

    // ��������� ��������������� �����������
    Direction GetAlternativeDirection(Direction currentDirection) {
        switch (currentDirection) {
        case Direction::Right: return Direction::Left;
        case Direction::Left: return Direction::Right;
        case Direction::Up: return Direction::Down;
        case Direction::Down: return Direction::Up;
        default: return Direction::Right;
        }
    }

    // ��������� ��������� �����������
    array<Direction>^ GetPossibleDirections(Direction lastDirection) {
        List<Direction>^ directions = gcnew List<Direction>();
        for each (Direction dir in (array<Direction>^)Enum::GetValues(Direction::typeid)) {
            if (dir != lastDirection) {
                directions->Add(dir);
            }
        }
        return directions->ToArray();
    }

    void CreateCorridor(int startX, int startY, int length, Direction direction) {
        int maxWidth = dungeonMap->GetLength(0);
        int maxHeight = dungeonMap->GetLength(1);

        switch (direction) {
        case Direction::Right:
            for (int x = startX;
                x < Math::Min(startX + length, maxWidth) && x >= 0;
                x++) {
                if (x >= 0 && x < maxWidth && startY >= 0 && startY < maxHeight) {
                    dungeonMap[x, startY]->isPath = true;
                }
            }
            break;
        case Direction::Left:
            for (int x = startX;
                x > Math::Max(startX - length, 0) && x >= 0;
                x--) {
                if (x >= 0 && x < maxWidth && startY >= 0 && startY < maxHeight) {
                    dungeonMap[x, startY]->isPath = true;
                }
            }
            break;
        case Direction::Up:
            for (int y = startY;
                y > Math::Max(startY - length, 0) && y >= 0;
                y--) {
                if (startX >= 0 && startX < maxWidth && y >= 0 && y < maxHeight) {
                    dungeonMap[startX, y]->isPath = true;
                }
            }
            break;
        case Direction::Down:
            for (int y = startY;
                y < Math::Min(startY + length, maxHeight) && y >= 0;
                y++) {
                if (startX >= 0 && startX < maxWidth && y >= 0 && y < maxHeight) {
                    dungeonMap[startX, y]->isPath = true;
                }
            }
            break;
        }
    }

    // �������� ������� � �������� �� 4*4
    void CreateRoom(int centerX, int centerY) {
        int roomWidth = random->Next(2, 5);
        int roomHeight = random->Next(2, 5);

        for (int x = Math::Max(0, centerX - roomWidth / 2);
            x < Math::Min(mapWidth, centerX + roomWidth / 2 + 1);
            x++) {
            for (int y = Math::Max(0, centerY - roomHeight / 2);
                y < Math::Min(mapHeight, centerY + roomHeight / 2 + 1);
                y++) {
                if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
                    dungeonMap[x, y]->isRoom = true;
                }
            }
        }
    }

    // ������� ����������� �� 90 ��������
    Direction RotateDirection(Direction current) {
        switch (current) {
        case Direction::Right: return Direction::Down;
        case Direction::Left: return Direction::Up;
        case Direction::Up: return Direction::Right;
        case Direction::Down: return Direction::Left;
        default: return Direction::Right;
        }
    }

    // ���������� ����� ��������� ����
    // ��������� ����
    // ��������� ���� (��������)
    void GenerateWalls() {
        for (int x = 0; x < mapWidth; x++) {
            for (int y = 0; y < mapHeight; y++) {
                // �������� ����� �����
                if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1) {
                    if (dungeonMap[x, y]->isPath ||
                        dungeonMap[x, y]->isRoom ||
                        dungeonMap[x, y]->isStart) {
                        // ���� �� ���� ���� ���-�� ����� ������� - ������ �����
                        dungeonMap[x, y]->isWall = true;
                    }
                }

                // ����������� ������ ��������� ����
                if (dungeonMap[x, y]->isPath ||
                    dungeonMap[x, y]->isRoom ||
                    dungeonMap[x, y]->isStart) {

                    array<Point>^ directions = {
                        Point(x + 1, y), Point(x - 1, y),
                        Point(x, y + 1), Point(x, y - 1)
                    };

                    for each (Point dir in directions) {
                        if (dir.X >= 0 && dir.X < mapWidth &&
                            dir.Y >= 0 && dir.Y < mapHeight) {
                            if (!dungeonMap[dir.X, dir.Y]->isPath &&
                                !dungeonMap[dir.X, dir.Y]->isRoom &&
                                !dungeonMap[dir.X, dir.Y]->isStart) {
                                dungeonMap[dir.X, dir.Y]->isWall = true;
                            }
                        }
                    }
                }
            }
        }
    }

public:
    // ��������� ����������
    Bitmap^ RenderDungeon() {
        GenerateDungeon();
        GenerateWalls();

        Bitmap^ dungeonBitmap = gcnew Bitmap(
            dungeonMap->GetLength(0) * TILE_SIZE,
            dungeonMap->GetLength(1) * TILE_SIZE
        );
        Graphics^ g = Graphics::FromImage(dungeonBitmap);

        // �������� ��������
        String^ baseDirectory = AppDomain::CurrentDomain->BaseDirectory;
        Bitmap^ emptySprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "empty.png")
        );
        Bitmap^ pathSprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "path.png")
        );
        Bitmap^ roomSprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "room.png")
        );
        Bitmap^ startSprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "start.png")
        );
        Bitmap^ wallSprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "wall.png")
        );

        // ��������� ������
        for (int x = 0; x < dungeonMap->GetLength(0); x++) {
            for (int y = 0; y < dungeonMap->GetLength(1); y++) {
                Bitmap^ currentSprite = emptySprite;

                if (dungeonMap[x, y]->isWall)
                    currentSprite = wallSprite;
                else if (dungeonMap[x, y]->isStart)
                    currentSprite = startSprite;
                else if (dungeonMap[x, y]->isPath)
                    currentSprite = pathSprite;
                else if (dungeonMap[x, y]->isRoom)
                    currentSprite = roomSprite;

                g->DrawImage(currentSprite, x * TILE_SIZE, y * TILE_SIZE);
            }
        }

        return dungeonBitmap;
    }

    array<Tile^, 2>^ GetDungeonMap() {
        return dungeonMap;
    }
};