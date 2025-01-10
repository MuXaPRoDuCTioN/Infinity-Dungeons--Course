#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <vcclr.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class DungeonGenerator {
private:
	// Размеры тайлов
    const int TILE_SIZE = 32;
    Random^ random; // Добавляем приватное поле для генератора случайных чисел
	
	// Структура для хранения информации о тайле
    ref struct Tile {
        bool isPath;
        bool isRoom;
        bool isStart;
        bool isWall; // Новое поле
    };
	
	// 2D массив тайлов
    array<Tile^, 2>^ dungeonMap;
	
	// Случайное направление коридора
    enum class Direction {
        Right,
        Left,
        Up,
        Down
    };
	
	// Добавим флаг для стартовой точки
    void CreateStart(int x, int y) {
        dungeonMap[x, y]->isStart = true;
    }
	
	// Генерация подземелья
    void GenerateDungeon() {
        random = gcnew Random(); // Инициализируем в конструкторе
        // Максимальный размер карты
        int mapWidth = 30;
        int mapHeight = 30;
        dungeonMap = gcnew array<Tile^, 2>(mapWidth, mapHeight);

        // Инициализация пустой карты
        for (int x = 0; x < mapWidth; x++) {
            for (int y = 0; y < mapHeight; y++) {
                dungeonMap[x, y] = gcnew Tile();
            }
        }

        // Начальная позиция
        int currentX = random->Next(3, 5); // Отступ от левого края
        int currentY = random->Next(3, 5); // Отступ от верхнего края

        // Создаем вход
        int corridorLength = random->Next(3, 7);
        // Определение первоначального направления
        Direction currentDirection;
        int firstDirectionChoice = random->Next(2);
        if (firstDirectionChoice == 0) {
            currentDirection = Direction::Right;
        }
        else {
            currentDirection = Direction::Down;
        }

        // Генерируем подземелье
        int roomCount = random->Next(4, 9);
        // Создаем стартовую точку
        CreateStart(currentX, currentY);

        int directionChangeCounter = 0;
        Direction lastDirection = currentDirection;

        for (int room = 0; room < roomCount; room++) {
            // Создаем коридор
            CreateCorridor(currentX, currentY, corridorLength, currentDirection);

            // Обновляем позицию после коридора
            switch (currentDirection) {
            case Direction::Right: currentX += corridorLength; break;
            case Direction::Left: currentX -= corridorLength; break;
            case Direction::Up: currentY -= corridorLength; break;
            case Direction::Down: currentY += corridorLength; break;
            }

            // Создаем комнату с отступом
            CreateRoom(currentX, currentY);

            // Обновляем счетчики и направления
            lastDirection = currentDirection;
            directionChangeCounter++;
            corridorLength = random->Next(3, 7);
        }
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
	
	// Создание комнаты
    void CreateRoom(int centerX, int centerY) {
        int roomSize = 3; // Размер комнаты
        for (int x = Math::Max(0, centerX - roomSize / 2);
            x < Math::Min(dungeonMap->GetLength(0), centerX + roomSize / 2 + 1);
            x++) {
            for (int y = Math::Max(0, centerY - roomSize / 2);
                y < Math::Min(dungeonMap->GetLength(1), centerY + roomSize / 2 + 1);
                y++) {
                if (x >= 0 && x < dungeonMap->GetLength(0) &&
                    y >= 0 && y < dungeonMap->GetLength(1)) {
                    dungeonMap[x, y]->isRoom = true;
                }
            }
        }
    }
}