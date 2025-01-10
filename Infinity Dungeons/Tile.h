#pragma once
// Структура для хранения информации о тайле
ref struct Tile {
    bool isPath;
    bool isRoom;
    bool isStart;
    bool isWall; // Новое поле
};