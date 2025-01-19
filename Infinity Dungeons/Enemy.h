#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <vcclr.h>
#include "DungeonGenerator.h"
#include "Tile.h"
#include "Player.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class Enemy {
public:
    int X;
    int Y;
    int Health;
    int MaxHealth;
    int Damage;
    int MinPlayerLevel;
    int ExperienceReward;
    int GoldReward;
    String^ ItemReward;
    Bitmap^ enemySprite;
    Random^ random;
    String^ Name;
    String^ Type;

    Enemy(int x, int y, Form^ parentForm) {
        X = x;
        Y = y;

        // Загрузка врагов из Enemies.txt
        String^ enemiesFilePath = GetFilePath("Enemies.txt");
        array<String^>^ enemyLines = File::ReadAllLines(enemiesFilePath);

        // Случайный выбор врага с учетом уровня игрока
        int playerLevel = GetPlayerLevel();
        List<array<String^>^>^ availableEnemies = gcnew List<array<String^>^>();

        for each (String ^ line in enemyLines) {
            array<String^>^ enemyData = line->Split(',');
            int minLevel = Int32::Parse(enemyData[4]);
            if (playerLevel >= minLevel) {
                availableEnemies->Add(enemyData);
            }
        }

        random = gcnew Random;

        // Случайный выбор врага из доступных
        if (availableEnemies->Count > 0) {
            array<String^>^ selectedEnemy = availableEnemies[random->Next(availableEnemies->Count)];

            Type = selectedEnemy[0];
            Name = selectedEnemy[1];
            MaxHealth = Int32::Parse(selectedEnemy[2]);
            Health = MaxHealth;
            Damage = Int32::Parse(selectedEnemy[3]);
            MinPlayerLevel = Int32::Parse(selectedEnemy[4]);
            ExperienceReward = Int32::Parse(selectedEnemy[5]);
            GoldReward = Int32::Parse(selectedEnemy[6]);
            ItemReward = selectedEnemy[7];
        }        

        // Загрузка спрайта
        String^ baseDirectory = AppDomain::CurrentDomain->BaseDirectory;
        enemySprite = gcnew Bitmap(
            System::IO::Path::Combine(baseDirectory, "Sprites", "enemy.png")
        );

        // После загрузки - рандомизация
        RandomizeEnemy();
    }

    // Метод атаки игрока
    int Attack() {
        return Damage;
    }

    int TakeDamage(int damage) {
        Health -= damage;
        if (Health < 0) Health = 0;
        return Health;
    }

    // Метод для получения уровня игрока
    int GetPlayerLevel() {
        String^ tempFilePath = GetFilePath("temp.txt");
        array<String^>^ lines = File::ReadAllLines(tempFilePath);
        return Int32::Parse(lines[11]);
    }

    static String^ GetFilePath(String^ filename)
    {
        String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
        return System::IO::Path::Combine(exeDirectory, filename);
    }

    // Случайная генерация врага с разнообразием
    void RandomizeEnemy() {
        Random^ random = gcnew Random();

        // Небольшой разброс характеристик
        double variationFactor = random->NextDouble() * 0.3 + 0.85; // 85-115%

        MaxHealth = Math::Round(MaxHealth * variationFactor);
        Health = MaxHealth;

        Damage = Math::Round(Damage * variationFactor);

        // Шанс выпадения предмета
        bool itemDropped = random->Next(100) < 25; // 25% шанс
        if (!itemDropped) {
            ItemReward = "None";
        }
    }
};