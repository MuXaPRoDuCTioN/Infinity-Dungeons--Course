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
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class Player {
public:
    int X;
    int Y;
    int Health;
    int MaxHealth;
    int Damage;
    int Defense;
    int InventorySlots;
    List<String^>^ Inventory;
    int Level;
    int Experience;
    int ExperienceToNextLevel;
    int Gold;
    String^ CurrentQuest;
    Bitmap^ playerSprite;
    Label^ healthLabel;
    int Strength, Intelligence, Agility;
    int SkillPoints;
    int Mana, MaxMana;

    Player(int startX, int startY, Form^ parentForm) {
        X = startX;
        Y = startY;

        // Загрузка характеристик из temp.txt
        String^ tempFilePath = GetFilePath("temp.txt");
        array<String^>^ lines = File::ReadAllLines(tempFilePath);

        // Загрузка атрибутов
        Strength = Int32::Parse(lines[0]);
        Intelligence = Int32::Parse(lines[1]);
        Agility = Int32::Parse(lines[2]);
        SkillPoints = 5; // При левелапе

        MaxHealth = Int32::Parse(lines[3]);
        Health = MaxHealth;
        MaxMana = Int32::Parse(lines[4]);
        Mana = MaxMana;
        Damage = Int32::Parse(lines[12]);
        Defense = Int32::Parse(lines[13]);
        InventorySlots = Int32::Parse(lines[5]);

        // Парсинг инвентаря
        Inventory = gcnew List<String^>(lines[7]->Split(','));

        Level = Int32::Parse(lines[11]);
        Experience = Int32::Parse(lines[14]);
        ExperienceToNextLevel = Int32::Parse(lines[15]);
        Gold = Int32::Parse(lines[9]);
        CurrentQuest = lines[10];

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
        // Проверяем, что новая позиция - соседняя
        bool isAdjacentCell =
            (Math::Abs(X - newX) <= 1 && Y == newY) ||
            (Math::Abs(Y - newY) <= 1 && X == newX);

        // Проверяем, что новая позиция допустима
        bool isValidMove =
            newX >= 0 && newX < dungeonMap->GetLength(0) &&
            newY >= 0 && newY < dungeonMap->GetLength(1) &&
            (dungeonMap[newX, newY]->isPath ||
                dungeonMap[newX, newY]->isRoom ||
                dungeonMap[newX, newY]->isStart);

        // Перемещаем только если соседняя клетка и допустимая
        if (isAdjacentCell && isValidMove) {
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

    // Метод для сохранения характеристик в temp.txt
    void SavePlayerStats() {
        String^ tempFilePath = GetFilePath("temp.txt");
        array<String^>^ lines = File::ReadAllLines(tempFilePath);

        // Сохраняем атрибуты
        lines[0] = Strength.ToString();
        lines[1] = Intelligence.ToString();
        lines[2] = Agility.ToString();

        lines[3] = MaxHealth.ToString();
        lines[4] = MaxMana.ToString();
        lines[12] = Damage.ToString();
        lines[13] = Defense.ToString();
        lines[5] = InventorySlots.ToString();
        lines[7] = String::Join(",", Inventory);
        lines[11] = Level.ToString();
        lines[14] = Experience.ToString();
        lines[15] = ExperienceToNextLevel.ToString();
        lines[9] = Gold.ToString();
        lines[10] = CurrentQuest;

        File::WriteAllLines(tempFilePath, lines);
    }

    static String^ GetFilePath(String^ filename)
    {
        String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
        return System::IO::Path::Combine(exeDirectory, filename);
    }

    // Расчет характеристик на основе атрибутов
    void RecalculateStats() {
        // Расчет здоровья
        MaxHealth = 50 +
            (Strength * 3) +     // Основной вклад силы
            (Agility * 2);       // Бонус от ловкости

        // Расчет маны
        MaxMana = 30 +
            (Intelligence * 4) +  // Основной вклад интеллекта
            (Agility * 1.5);      // Небольшой бонус от ловкости

        // Расчет слотов инвентаря
        InventorySlots = 10 +
            (Strength / 3) +     // Вклад силы
            (Intelligence / 2);  // Вклад интеллекта

        // Округление
        MaxHealth = Math::Round(MaxHealth);
        MaxMana = Math::Round(MaxMana);
        InventorySlots = Math::Floor(InventorySlots);

        // Восстановление до максимума
        Health = MaxHealth;
        Mana = MaxMana;
    }

    // Метод распределения очков навыков
    void DistributeSkillPoints(int strengthIncrease, int intelligenceIncrease, int agilityIncrease) {
        if (strengthIncrease + intelligenceIncrease + agilityIncrease <= SkillPoints) {
            Strength += strengthIncrease;
            Intelligence += intelligenceIncrease;
            Agility += agilityIncrease;
            SkillPoints -= (strengthIncrease + intelligenceIncrease + agilityIncrease);

            // Пересчет характеристик
            RecalculateStats();
        }
    }
};