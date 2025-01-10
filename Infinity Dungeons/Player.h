#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <vcclr.h>
#include "DungeonGenerator.h"
#include "Tile.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class Player {
public:
    int X;
    int Y;
    int Health;
    int MaxHealth;
    Bitmap^ playerSprite;
    Label^ healthLabel;

    Player(int startX, int startY, Form^ parentForm) {
        X = startX;
        Y = startY;
        MaxHealth = 300;
        Health = MaxHealth;

        // Загрузка спрайта игрока
        String^ baseDirectory = AppDomain::CurrentDomain->BaseDirectory;
        playerSprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "player.png")
        );
    }

    // Проверка возможности перемещения
    bool CanMoveTo(array<Tile^, 2>^ dungeonMap, int newX, int newY) {
        // Проверяем границы карты
        if (newX < 0 || newX >= dungeonMap->GetLength(0) ||
            newY < 0 || newY >= dungeonMap->GetLength(1)) {
            return false;
        }

        // Можно ходить только по path, room и start
        return dungeonMap[newX, newY]->isPath ||
            dungeonMap[newX, newY]->isRoom ||
            dungeonMap[newX, newY]->isStart;
    }

    // Перемещение игрока
    bool Move(array<Tile^, 2>^ dungeonMap, int newX, int newY) {
        // Проверяем границы карты
        if (newX < 0 || newX >= dungeonMap->GetLength(0) ||
            newY < 0 || newY >= dungeonMap->GetLength(1)) {
            return false;
        }

        // Можно ходить только по path, room и start
        if (dungeonMap[newX, newY]->isPath ||
            dungeonMap[newX, newY]->isRoom ||
            dungeonMap[newX, newY]->isStart) {
            X = newX;
            Y = newY;
            return true;
        }
        return false;
    }

    int TakeDamage(int damage) {
        Health -= damage;
        if (Health < 0) Health = 0;
        return Health;
    }
};