#pragma once
#include "DungeonGenerator.h"
#include "Player.h"
#include "Enemy.h"
#include "Tile.h"
#include "SkillPointDistributionForm.h"

namespace InfinityDungeons {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Константы для Windows API
	#define WM_NCLBUTTONDOWN 0x00A1
	#define HTCAPTION 2

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
		array<String^>^ currentQuestData;
	private: System::Windows::Forms::Label^ playerHealthLabel;
	private: System::Windows::Forms::Label^ enemyHealthLabel;
	private: System::Windows::Forms::Label^ questProgressLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;



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
			this->questProgressLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->playerHealthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->playerHealthLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->playerHealthLabel->Location = System::Drawing::Point(688, 69);
			this->playerHealthLabel->Name = L"playerHealthLabel";
			this->playerHealthLabel->Size = System::Drawing::Size(58, 22);
			this->playerHealthLabel->TabIndex = 1;
			this->playerHealthLabel->Text = L"label1";
			// 
			// enemyHealthLabel
			// 
			this->enemyHealthLabel->AutoSize = true;
			this->enemyHealthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->enemyHealthLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->enemyHealthLabel->Location = System::Drawing::Point(646, 102);
			this->enemyHealthLabel->Name = L"enemyHealthLabel";
			this->enemyHealthLabel->Size = System::Drawing::Size(58, 22);
			this->enemyHealthLabel->TabIndex = 2;
			this->enemyHealthLabel->Text = L"label2";
			this->enemyHealthLabel->Visible = false;
			// 
			// questProgressLabel
			// 
			this->questProgressLabel->AutoSize = true;
			this->questProgressLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->questProgressLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->questProgressLabel->Location = System::Drawing::Point(646, 170);
			this->questProgressLabel->Name = L"questProgressLabel";
			this->questProgressLabel->Size = System::Drawing::Size(58, 22);
			this->questProgressLabel->TabIndex = 3;
			this->questProgressLabel->Text = L"label1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(642, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 22);
			this->label1->TabIndex = 4;
			this->label1->Text = L"HP:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Chocolate;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(836, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(31, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Dungeon::button1_Click);
			// 
			// Dungeon
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Sienna;
			this->ClientSize = System::Drawing::Size(879, 641);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->questProgressLabel);
			this->Controls->Add(this->enemyHealthLabel);
			this->Controls->Add(this->playerHealthLabel);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Dungeon";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dungeon";
			this->Load += gcnew System::EventHandler(this, &Dungeon::Dungeon_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Dungeon::Dungeon_MouseDown);
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

			// Проверка и отображение квеста
			CheckAndDisplayQuest();

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
				// Рассчет урона с учетом защиты
				int playerDamage = player->Damage;
				int enemyRemainingHealth = enemyAtPosition->TakeDamage(playerDamage);

				// Обновляем label врага
				UpdateEnemyHealthLabel(enemyAtPosition);

				// Ответная атака врага
				if (enemyRemainingHealth > 0) {
					int enemyDamage = Math::Max(1, enemyAtPosition->Damage - player->Defense);
					int playerRemainingHealth = player->TakeDamage(enemyDamage);

					// Обновляем label игрока
					UpdatePlayerHealthLabel();
				}

				// Убийство врага
				if (enemyRemainingHealth <= 0) {
					// Начисление опыта
					player->Experience += enemyAtPosition->ExperienceReward;

					// Начисление золота
					player->Gold += enemyAtPosition->GoldReward;

					// Проверка на повышение уровня
					if (player->Experience >= player->ExperienceToNextLevel) {
						player->Level++;
						player->Experience -= player->ExperienceToNextLevel;
						player->ExperienceToNextLevel *= 2; // Усложнение прокачки

						// Добавление очков навыков
						player->SkillPoints += 5;

						SkillPointDistributionForm^ distributionForm =
							gcnew SkillPointDistributionForm(player);
						distributionForm->ShowDialog();

						// Увеличение характеристик при повышении уровня
						player->RecalculateStats();

						UpdatePlayerHealthLabel();
					}

					// Добавление предмета в инвентарь
					if (!String::IsNullOrEmpty(enemyAtPosition->ItemReward) &&
						enemyAtPosition->ItemReward != "None" &&
						player->Inventory->Count < player->InventorySlots) {
						player->Inventory->Add(enemyAtPosition->ItemReward);
					}

					UpdateQuestProgress(enemyAtPosition);

					// Сохраняем статы игрока
					player->SavePlayerStats();

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

		static String^ GetFilePath(String^ filename)
		{
			String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
			String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
			return System::IO::Path::Combine(exeDirectory, filename);
		}

		void CheckAndDisplayQuest() {
			if (player->CurrentQuest != "None") {
				array<String^>^ questData = player->CurrentQuest->Split(',');

				questProgressLabel->Text =
					String::Format("Квест: убить {0} {1}\n{2}/{3}",
						questData[1],  // Количество убийств
						questData[0],  // Тип врага
						questData[2],  // Текущий прогресс
						questData[1]   // Всего требуется
					);
				questProgressLabel->Visible = true;
			}
			else {
				questProgressLabel->Text = "Нет активного квеста";
				questProgressLabel->Visible = true;
			}
		}

		void UpdateQuestProgress(Enemy^ defeatedEnemy) {
			if (player->CurrentQuest != "None") {
				array<String^>^ questData = player->CurrentQuest->Split(',');

				if (defeatedEnemy->Type == questData[0]) {
					int currentKills = Int32::Parse(questData[2]);
					int requiredKills = Int32::Parse(questData[1]);

					currentKills++;
					questData[2] = currentKills.ToString();

					// Обновляем квест
					player->CurrentQuest = String::Join(",", questData);

					// Обновляем отображение
					CheckAndDisplayQuest();

					if (currentKills >= requiredKills) {
						int reward = Int32::Parse(questData[3]);
						player->Gold += reward;

						MessageBox::Show(String::Format("Квест выполнен! Награда: {0} золота", reward));

						// Сброс квеста
						player->CurrentQuest = "None";
						CheckAndDisplayQuest();
					}
				}
			}
		}

		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);

	private: System::Void Dungeon_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Отправляем системное сообщение о начале перемещения окна
		ReleaseCapture();
		SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
