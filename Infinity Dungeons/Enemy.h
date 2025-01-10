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

public ref class Enemy {
public:
    int X;
    int Y;
    int Health;
    int MaxHealth;
    Bitmap^ enemySprite;
    Random^ random;
    String^ Name;
    Label^ healthLabel;

    Enemy(int x, int y, Form^ parentForm) {
        X = x;
        Y = y;
        MaxHealth = 100;
        Health = MaxHealth;
        Name = "Goblin";

        random = gcnew Random;

        // Загрузка спрайта
        String^ baseDirectory = AppDomain::CurrentDomain->BaseDirectory;
        enemySprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "enemy.png")
        );
    }

    // Метод атаки игрока
    int Attack() {
        return random->Next(10, 30); // Урон от 10 до 30
    }

    int TakeDamage(int damage) {
        Health -= damage;
        if (Health < 0) Health = 0;
        return Health;
    }
};