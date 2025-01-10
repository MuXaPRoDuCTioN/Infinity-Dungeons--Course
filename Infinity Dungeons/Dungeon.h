#pragma once
#include "DungeonGenerator.h"
#include "Player.h"
#include "Enemy.h"
#include "Tile.h"

namespace InfinityDungeons {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Dungeon
	/// </summary>
	public ref class Dungeon : public System::Windows::Forms::Form
	{
	private: 
		System::Windows::Forms::PictureBox^ pictureBox1;
		DungeonGenerator^ generator;
		Player^ player;
		array<Tile^, 2>^ currentDungeonMap;
		Bitmap^ dungeonMap;
		List<Enemy^>^ enemies;
		Random^ random;
	private: System::Windows::Forms::Label^ playerHealthLabel;
	private: System::Windows::Forms::Label^ enemyHealthLabel;


		   ProgressBar^ playerHealthBar;

	public:
		Dungeon(void)
		{
			InitializeComponent();
			// В конструкторе формы
			this->DoubleBuffered = true; // Уменьшает мерцание
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Dungeon()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->playerHealthLabel = (gcnew System::Windows::Forms::Label());
			this->enemyHealthLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 640);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Dungeon::pictureBox1_MouseClick);
			// 
			// playerHealthLabel
			// 
			this->playerHealthLabel->AutoSize = true;
			this->playerHealthLabel->Location = System::Drawing::Point(678, 28);
			this->playerHealthLabel->Name = L"playerHealthLabel";
			this->playerHealthLabel->Size = System::Drawing::Size(35, 13);
			this->playerHealthLabel->TabIndex = 1;
			this->playerHealthLabel->Text = L"label1";
			// 
			// enemyHealthLabel
			// 
			this->enemyHealthLabel->AutoSize = true;
			this->enemyHealthLabel->Location = System::Drawing::Point(678, 107);
			this->enemyHealthLabel->Name = L"enemyHealthLabel";
			this->enemyHealthLabel->Size = System::Drawing::Size(35, 13);
			this->enemyHealthLabel->TabIndex = 2;
			this->enemyHealthLabel->Text = L"label2";
			// 
			// Dungeon
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(827, 641);
			this->Controls->Add(this->enemyHealthLabel);
			this->Controls->Add(this->playerHealthLabel);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Dungeon";
			this->Text = L"Dungeon";
			this->Load += gcnew System::EventHandler(this, &Dungeon::Dungeon_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		private: System::Void Dungeon_Load(System::Object^ sender, System::EventArgs^ e) {
			generator = gcnew DungeonGenerator();
			Bitmap^ dungeonMap = generator->RenderDungeon();
			pictureBox1->Image = dungeonMap;

			// Сохраняем текущую карту
			currentDungeonMap = generator->GetDungeonMap();

			// Находим стартовую позицию для игрока
			int startX = 0, startY = 0;
			for (int x = 0; x < currentDungeonMap->GetLength(0); x++) {
				for (int y = 0; y < currentDungeonMap->GetLength(1); y++) {
					if (currentDungeonMap[x, y]->isStart) {
						startX = x;
						startY = y;
						break;
					}
				}
			}

			// Создаем игрока
			// Создаем игрока с передачей healthBar
			player = gcnew Player(startX, startY, this);

			// Генерация врагов
			random = gcnew Random;
			// Улучшенная генерация врагов
			enemies = gcnew List<Enemy^>();
			int enemyCount = random->Next(3, 7);

			for (int i = 0; i < enemyCount; i++) {
				Enemy^ newEnemy = nullptr;
				int maxAttempts = 200; // Увеличиваем количество попыток

				while (maxAttempts > 0 && newEnemy == nullptr) {
					int x = random->Next(currentDungeonMap->GetLength(0));
					int y = random->Next(currentDungeonMap->GetLength(1));

					// Более гибкая проверка спавна
					if ((currentDungeonMap[x, y]->isPath ||
						currentDungeonMap[x, y]->isRoom) &&
						!currentDungeonMap[x, y]->isStart &&
						!currentDungeonMap[x, y]->isWall) {

						// Дополнительная проверка расстояния
						bool tooCloseToPlayer =
							Math::Abs(x - player->X) <= 2 &&
							Math::Abs(y - player->Y) <= 2;

						bool tooCloseToOtherEnemies = false;
						for each (Enemy ^ existingEnemy in enemies) {
							if (Math::Abs(x - existingEnemy->X) <= 2 &&
								Math::Abs(y - existingEnemy->Y) <= 2) {
								tooCloseToOtherEnemies = true;
								break;
							}
						}

						if (!tooCloseToPlayer && !tooCloseToOtherEnemies) {
							newEnemy = gcnew Enemy(x, y, this);
							enemies->Add(newEnemy);
						}
					}

					maxAttempts--;
				}
			}

			UpdatePlayerHealthLabel();
			// Отрисовываем карту с игроком
			RenderDungeonWithPlayer();
		}

		private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			int tileSize = 32;
			int clickedX = e->X / tileSize;
			int clickedY = e->Y / tileSize;

			// Находим врага в позиции клика
			Enemy^ enemyAtPosition = FindEnemyAtPosition(clickedX, clickedY);

			if (enemyAtPosition != nullptr) {
				// Атака врага
				int playerDamage = random->Next(20, 40);
				int enemyRemainingHealth = enemyAtPosition->TakeDamage(playerDamage);

				// Обновляем label врага
				UpdateEnemyHealthLabel(enemyAtPosition);

				// Ответная атака врага
				if (enemyRemainingHealth > 0) {
					int enemyDamage = random->Next(10, 30);
					int playerRemainingHealth = player->TakeDamage(enemyDamage);

					// Обновляем label игрока
					UpdatePlayerHealthLabel();
				}

				// Удаление убитого врага
				if (enemyRemainingHealth <= 0) {
					enemies->Remove(enemyAtPosition);
				}

				RenderDungeonWithPlayer();
			}
			else {
				// Стандартное перемещение, если не враг
				if (player->Move(currentDungeonMap, clickedX, clickedY)) {
					RenderDungeonWithPlayer();
					CheckEnemyProximity();
				}
			}
		}

		Enemy^ FindEnemyAtPosition(int x, int y) {
			for each (Enemy^ enemy in enemies) {
				if (enemy->X == x && enemy->Y == y) {
					return enemy;
				}
			}
			return nullptr;
		}

		// Ход врагов
		void EnemyTurn() {
			for each (Enemy^ enemy in enemies) {
				// Если враг рядом с игроком - атакует
				if (Math::Abs(enemy->X - player->X) <= 1 && 
					Math::Abs(enemy->Y - player->Y) <= 1) {
					int enemyDamage = enemy->Attack();
					player->Health -= enemyDamage;
				}
			}
			RenderDungeonWithPlayer();
		}

		void RenderDungeonWithPlayer() {
			// Создаем новую bitmap с нуля
			Bitmap^ dungeonBitmap = gcnew Bitmap(
				pictureBox1->Width, 
				pictureBox1->Height
			);
			Graphics^ g = Graphics::FromImage(dungeonBitmap);

			// Размер тайла
			int tileSize = 32;

			String^ baseDirectory = AppDomain::CurrentDomain->BaseDirectory;

			Bitmap^ emptySprite = gcnew Bitmap(
				System::IO::Path::Combine(baseDirectory, "Sprites", "empty.png")
			);
			Bitmap^ wallSprite = gcnew Bitmap(
				System::IO::Path::Combine(baseDirectory, "Sprites", "wall.png")
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

			// Перерисовываем все тайлы
			for (int x = 0; x < currentDungeonMap->GetLength(0); x++) {
				for (int y = 0; y < currentDungeonMap->GetLength(1); y++) {
					Bitmap^ currentSprite = emptySprite;

					if (currentDungeonMap[x, y]->isWall) 
						currentSprite = wallSprite;
					else if (currentDungeonMap[x, y]->isStart)
						currentSprite = startSprite;
					else if (currentDungeonMap[x, y]->isPath) 
						currentSprite = pathSprite;
					else if (currentDungeonMap[x, y]->isRoom) 
						currentSprite = roomSprite;

					if (currentSprite != nullptr) {
						g->DrawImage(currentSprite, x * tileSize, y * tileSize);
					}
				}
			}

			// Отрисовка врагов
			for each (Enemy ^ enemy in enemies) {
				g->DrawImage(enemy->enemySprite,
					enemy->X * tileSize,
					enemy->Y * tileSize
				);
			}

			// Рисуем игрока поверх
			g->DrawImage(player->playerSprite, 
				player->X * tileSize, 
				player->Y * tileSize
			);

			pictureBox1->Image = dungeonBitmap;			
		}

		void CheckEnemyProximity() {
			Enemy^ nearestEnemy = nullptr;
			double minDistance = 1.0;

			for each (Enemy ^ enemy in enemies) {
				double distance = Math::Sqrt(
					Math::Pow(player->X - enemy->X, 2) +
					Math::Pow(player->Y - enemy->Y, 2)
				);

				if (distance <= minDistance) {
					nearestEnemy = enemy;
					break;
				}
			}

			// Показ/скрытие label врага
			if (nearestEnemy != nullptr) {
				enemyHealthLabel->Visible = true;
				UpdateEnemyHealthLabel(nearestEnemy);
			}
			else {
				enemyHealthLabel->Visible = false;
			}
		}

		void UpdatePlayerHealthLabel() {
			if (playerHealthLabel != nullptr) {
				playerHealthLabel->Text =
					String::Format("{0}/{1}",
						player->Health,
						player->MaxHealth);
			}
		}

		void UpdateEnemyHealthLabel(Enemy^ enemy) {
			if (enemyHealthLabel != nullptr) {
				enemyHealthLabel->Text =
					String::Format("{0}: {1}/{2}",
						enemy->Name,
						enemy->Health,
						enemy->MaxHealth);
			}
		}
	};
}
