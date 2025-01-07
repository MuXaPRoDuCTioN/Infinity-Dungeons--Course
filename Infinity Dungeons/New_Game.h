#pragma once
#include <vector>
#include <string>

namespace InfinityDungeons {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	
	// Константы для Windows API
	#define WM_NCLBUTTONDOWN 0x00A1
	#define HTCAPTION 2

	/// <summary>
	/// Сводка для New_Game
	/// </summary>
	public ref class New_Game : public System::Windows::Forms::Form
	{
	public:
		New_Game(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~New_Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBoxPlayer;
	private: System::Windows::Forms::Button^ buttonNextSprite;
	private: System::Windows::Forms::Button^ buttonPreviousSprite;

	private:
		int strengthPoints = 25;
		int intelligencePoints = 25;
		int agilityPoints = 25;
		int totalPoints = 20; // Дополнительные очки в банке

	// Производные параметры
		int healthPoints;
		int manaPoints;
		int inventorySlots;

	private: System::Windows::Forms::Label^ labelStrength;
	private: System::Windows::Forms::Button^ btnStrengthPlus1;
	private: System::Windows::Forms::Button^ btnStrengthPlus5;
	private: System::Windows::Forms::Button^ btnStrengthMinus1;
	private: System::Windows::Forms::Button^ btnStrengthMinus5;
	private: System::Windows::Forms::Label^ labelIntelligence;
	private: System::Windows::Forms::Label^ labelAgility;
	private: System::Windows::Forms::Label^ labelTotalPoints;
	private: System::Windows::Forms::Button^ btnIntelligencePlus1;
	private: System::Windows::Forms::Button^ btnIntelligencePlus5;
	private: System::Windows::Forms::Button^ btnIntelligenceMinus1;
	private: System::Windows::Forms::Button^ btnIntelligenceMinus5;
	private: System::Windows::Forms::Button^ btnAgilityMinus5;

	private: System::Windows::Forms::Button^ btnAgilityMinus1;

	private: System::Windows::Forms::Button^ btnAgilityPlus1;
	private: System::Windows::Forms::Button^ btnAgilityPlus5;
	private: System::Windows::Forms::Label^ labelHealth;
	private: System::Windows::Forms::Label^ labelMana;
	private: System::Windows::Forms::Label^ labelInventorySlots;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonBack;




	protected:

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
			this->pictureBoxPlayer = (gcnew System::Windows::Forms::PictureBox());
			this->buttonNextSprite = (gcnew System::Windows::Forms::Button());
			this->buttonPreviousSprite = (gcnew System::Windows::Forms::Button());
			this->labelStrength = (gcnew System::Windows::Forms::Label());
			this->btnStrengthPlus1 = (gcnew System::Windows::Forms::Button());
			this->btnStrengthPlus5 = (gcnew System::Windows::Forms::Button());
			this->btnStrengthMinus1 = (gcnew System::Windows::Forms::Button());
			this->btnStrengthMinus5 = (gcnew System::Windows::Forms::Button());
			this->labelIntelligence = (gcnew System::Windows::Forms::Label());
			this->labelAgility = (gcnew System::Windows::Forms::Label());
			this->labelTotalPoints = (gcnew System::Windows::Forms::Label());
			this->btnIntelligencePlus1 = (gcnew System::Windows::Forms::Button());
			this->btnIntelligencePlus5 = (gcnew System::Windows::Forms::Button());
			this->btnIntelligenceMinus1 = (gcnew System::Windows::Forms::Button());
			this->btnIntelligenceMinus5 = (gcnew System::Windows::Forms::Button());
			this->btnAgilityMinus5 = (gcnew System::Windows::Forms::Button());
			this->btnAgilityMinus1 = (gcnew System::Windows::Forms::Button());
			this->btnAgilityPlus1 = (gcnew System::Windows::Forms::Button());
			this->btnAgilityPlus5 = (gcnew System::Windows::Forms::Button());
			this->labelHealth = (gcnew System::Windows::Forms::Label());
			this->labelMana = (gcnew System::Windows::Forms::Label());
			this->labelInventorySlots = (gcnew System::Windows::Forms::Label());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayer))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxPlayer
			// 
			this->pictureBoxPlayer->Location = System::Drawing::Point(54, 33);
			this->pictureBoxPlayer->Name = L"pictureBoxPlayer";
			this->pictureBoxPlayer->Size = System::Drawing::Size(140, 210);
			this->pictureBoxPlayer->TabIndex = 0;
			this->pictureBoxPlayer->TabStop = false;
			// 
			// buttonNextSprite
			// 
			this->buttonNextSprite->Location = System::Drawing::Point(201, 132);
			this->buttonNextSprite->Name = L"buttonNextSprite";
			this->buttonNextSprite->Size = System::Drawing::Size(25, 23);
			this->buttonNextSprite->TabIndex = 1;
			this->buttonNextSprite->Text = L">";
			this->buttonNextSprite->UseVisualStyleBackColor = true;
			this->buttonNextSprite->Click += gcnew System::EventHandler(this, &New_Game::buttonNextSprite_Click);
			// 
			// buttonPreviousSprite
			// 
			this->buttonPreviousSprite->Location = System::Drawing::Point(23, 132);
			this->buttonPreviousSprite->Name = L"buttonPreviousSprite";
			this->buttonPreviousSprite->Size = System::Drawing::Size(25, 23);
			this->buttonPreviousSprite->TabIndex = 1;
			this->buttonPreviousSprite->Text = L"<";
			this->buttonPreviousSprite->UseVisualStyleBackColor = true;
			this->buttonPreviousSprite->Click += gcnew System::EventHandler(this, &New_Game::buttonPreviousSprite_Click);
			// 
			// labelStrength
			// 
			this->labelStrength->AutoSize = true;
			this->labelStrength->Location = System::Drawing::Point(341, 52);
			this->labelStrength->Name = L"labelStrength";
			this->labelStrength->Size = System::Drawing::Size(35, 13);
			this->labelStrength->TabIndex = 2;
			this->labelStrength->Text = L"label1";
			// 
			// btnStrengthPlus1
			// 
			this->btnStrengthPlus1->Location = System::Drawing::Point(382, 47);
			this->btnStrengthPlus1->Name = L"btnStrengthPlus1";
			this->btnStrengthPlus1->Size = System::Drawing::Size(27, 23);
			this->btnStrengthPlus1->TabIndex = 3;
			this->btnStrengthPlus1->Text = L"+1";
			this->btnStrengthPlus1->UseVisualStyleBackColor = true;
			this->btnStrengthPlus1->Click += gcnew System::EventHandler(this, &New_Game::btnStrengthPlus1_Click);
			// 
			// btnStrengthPlus5
			// 
			this->btnStrengthPlus5->Location = System::Drawing::Point(415, 47);
			this->btnStrengthPlus5->Name = L"btnStrengthPlus5";
			this->btnStrengthPlus5->Size = System::Drawing::Size(27, 23);
			this->btnStrengthPlus5->TabIndex = 3;
			this->btnStrengthPlus5->Text = L"+5";
			this->btnStrengthPlus5->UseVisualStyleBackColor = true;
			this->btnStrengthPlus5->Click += gcnew System::EventHandler(this, &New_Game::btnStrengthPlus5_Click);
			// 
			// btnStrengthMinus1
			// 
			this->btnStrengthMinus1->Location = System::Drawing::Point(308, 47);
			this->btnStrengthMinus1->Name = L"btnStrengthMinus1";
			this->btnStrengthMinus1->Size = System::Drawing::Size(27, 23);
			this->btnStrengthMinus1->TabIndex = 3;
			this->btnStrengthMinus1->Text = L"-1";
			this->btnStrengthMinus1->UseVisualStyleBackColor = true;
			this->btnStrengthMinus1->Click += gcnew System::EventHandler(this, &New_Game::btnStrengthMinus1_Click);
			// 
			// btnStrengthMinus5
			// 
			this->btnStrengthMinus5->Location = System::Drawing::Point(275, 47);
			this->btnStrengthMinus5->Name = L"btnStrengthMinus5";
			this->btnStrengthMinus5->Size = System::Drawing::Size(27, 23);
			this->btnStrengthMinus5->TabIndex = 3;
			this->btnStrengthMinus5->Text = L"-5";
			this->btnStrengthMinus5->UseVisualStyleBackColor = true;
			this->btnStrengthMinus5->Click += gcnew System::EventHandler(this, &New_Game::btnStrengthMinus5_Click);
			// 
			// labelIntelligence
			// 
			this->labelIntelligence->AutoSize = true;
			this->labelIntelligence->Location = System::Drawing::Point(341, 93);
			this->labelIntelligence->Name = L"labelIntelligence";
			this->labelIntelligence->Size = System::Drawing::Size(35, 13);
			this->labelIntelligence->TabIndex = 4;
			this->labelIntelligence->Text = L"label1";
			// 
			// labelAgility
			// 
			this->labelAgility->AutoSize = true;
			this->labelAgility->Location = System::Drawing::Point(341, 132);
			this->labelAgility->Name = L"labelAgility";
			this->labelAgility->Size = System::Drawing::Size(35, 13);
			this->labelAgility->TabIndex = 5;
			this->labelAgility->Text = L"label1";
			// 
			// labelTotalPoints
			// 
			this->labelTotalPoints->AutoSize = true;
			this->labelTotalPoints->Location = System::Drawing::Point(341, 175);
			this->labelTotalPoints->Name = L"labelTotalPoints";
			this->labelTotalPoints->Size = System::Drawing::Size(35, 13);
			this->labelTotalPoints->TabIndex = 6;
			this->labelTotalPoints->Text = L"label1";
			// 
			// btnIntelligencePlus1
			// 
			this->btnIntelligencePlus1->Location = System::Drawing::Point(382, 88);
			this->btnIntelligencePlus1->Name = L"btnIntelligencePlus1";
			this->btnIntelligencePlus1->Size = System::Drawing::Size(27, 23);
			this->btnIntelligencePlus1->TabIndex = 3;
			this->btnIntelligencePlus1->Text = L"+1";
			this->btnIntelligencePlus1->UseVisualStyleBackColor = true;
			this->btnIntelligencePlus1->Click += gcnew System::EventHandler(this, &New_Game::btnIntelligencePlus1_Click);
			// 
			// btnIntelligencePlus5
			// 
			this->btnIntelligencePlus5->Location = System::Drawing::Point(415, 88);
			this->btnIntelligencePlus5->Name = L"btnIntelligencePlus5";
			this->btnIntelligencePlus5->Size = System::Drawing::Size(27, 23);
			this->btnIntelligencePlus5->TabIndex = 3;
			this->btnIntelligencePlus5->Text = L"+5";
			this->btnIntelligencePlus5->UseVisualStyleBackColor = true;
			this->btnIntelligencePlus5->Click += gcnew System::EventHandler(this, &New_Game::btnIntelligencePlus5_Click);
			// 
			// btnIntelligenceMinus1
			// 
			this->btnIntelligenceMinus1->Location = System::Drawing::Point(308, 88);
			this->btnIntelligenceMinus1->Name = L"btnIntelligenceMinus1";
			this->btnIntelligenceMinus1->Size = System::Drawing::Size(27, 23);
			this->btnIntelligenceMinus1->TabIndex = 3;
			this->btnIntelligenceMinus1->Text = L"-1";
			this->btnIntelligenceMinus1->UseVisualStyleBackColor = true;
			this->btnIntelligenceMinus1->Click += gcnew System::EventHandler(this, &New_Game::btnIntelligenceMinus1_Click);
			// 
			// btnIntelligenceMinus5
			// 
			this->btnIntelligenceMinus5->Location = System::Drawing::Point(275, 88);
			this->btnIntelligenceMinus5->Name = L"btnIntelligenceMinus5";
			this->btnIntelligenceMinus5->Size = System::Drawing::Size(27, 23);
			this->btnIntelligenceMinus5->TabIndex = 3;
			this->btnIntelligenceMinus5->Text = L"-5";
			this->btnIntelligenceMinus5->UseVisualStyleBackColor = true;
			this->btnIntelligenceMinus5->Click += gcnew System::EventHandler(this, &New_Game::btnIntelligenceMinus5_Click);
			// 
			// btnAgilityMinus5
			// 
			this->btnAgilityMinus5->Location = System::Drawing::Point(275, 127);
			this->btnAgilityMinus5->Name = L"btnAgilityMinus5";
			this->btnAgilityMinus5->Size = System::Drawing::Size(27, 23);
			this->btnAgilityMinus5->TabIndex = 3;
			this->btnAgilityMinus5->Text = L"-5";
			this->btnAgilityMinus5->UseVisualStyleBackColor = true;
			this->btnAgilityMinus5->Click += gcnew System::EventHandler(this, &New_Game::btnAgilityMinus5_Click);
			// 
			// btnAgilityMinus1
			// 
			this->btnAgilityMinus1->Location = System::Drawing::Point(308, 127);
			this->btnAgilityMinus1->Name = L"btnAgilityMinus1";
			this->btnAgilityMinus1->Size = System::Drawing::Size(27, 23);
			this->btnAgilityMinus1->TabIndex = 3;
			this->btnAgilityMinus1->Text = L"-1";
			this->btnAgilityMinus1->UseVisualStyleBackColor = true;
			this->btnAgilityMinus1->Click += gcnew System::EventHandler(this, &New_Game::btnAgilityMinus1_Click);
			// 
			// btnAgilityPlus1
			// 
			this->btnAgilityPlus1->Location = System::Drawing::Point(382, 127);
			this->btnAgilityPlus1->Name = L"btnAgilityPlus1";
			this->btnAgilityPlus1->Size = System::Drawing::Size(27, 23);
			this->btnAgilityPlus1->TabIndex = 3;
			this->btnAgilityPlus1->Text = L"+1";
			this->btnAgilityPlus1->UseVisualStyleBackColor = true;
			this->btnAgilityPlus1->Click += gcnew System::EventHandler(this, &New_Game::btnAgilityPlus1_Click);
			// 
			// btnAgilityPlus5
			// 
			this->btnAgilityPlus5->Location = System::Drawing::Point(415, 127);
			this->btnAgilityPlus5->Name = L"btnAgilityPlus5";
			this->btnAgilityPlus5->Size = System::Drawing::Size(27, 23);
			this->btnAgilityPlus5->TabIndex = 3;
			this->btnAgilityPlus5->Text = L"+5";
			this->btnAgilityPlus5->UseVisualStyleBackColor = true;
			this->btnAgilityPlus5->Click += gcnew System::EventHandler(this, &New_Game::btnAgilityPlus5_Click);
			// 
			// labelHealth
			// 
			this->labelHealth->AutoSize = true;
			this->labelHealth->Location = System::Drawing::Point(252, 229);
			this->labelHealth->Name = L"labelHealth";
			this->labelHealth->Size = System::Drawing::Size(35, 13);
			this->labelHealth->TabIndex = 7;
			this->labelHealth->Text = L"label1";
			// 
			// labelMana
			// 
			this->labelMana->AutoSize = true;
			this->labelMana->Location = System::Drawing::Point(341, 229);
			this->labelMana->Name = L"labelMana";
			this->labelMana->Size = System::Drawing::Size(35, 13);
			this->labelMana->TabIndex = 7;
			this->labelMana->Text = L"label1";
			// 
			// labelInventorySlots
			// 
			this->labelInventorySlots->AutoSize = true;
			this->labelInventorySlots->Location = System::Drawing::Point(412, 229);
			this->labelInventorySlots->Name = L"labelInventorySlots";
			this->labelInventorySlots->Size = System::Drawing::Size(35, 13);
			this->labelInventorySlots->TabIndex = 7;
			this->labelInventorySlots->Text = L"label1";
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(382, 275);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 8;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &New_Game::buttonSave_Click);
			// 
			// buttonBack
			// 
			this->buttonBack->Location = System::Drawing::Point(12, 275);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(75, 23);
			this->buttonBack->TabIndex = 9;
			this->buttonBack->Text = L"Back";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &New_Game::buttonBack_Click);
			// 
			// New_Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(480, 320);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->labelInventorySlots);
			this->Controls->Add(this->labelMana);
			this->Controls->Add(this->labelHealth);
			this->Controls->Add(this->labelTotalPoints);
			this->Controls->Add(this->labelAgility);
			this->Controls->Add(this->labelIntelligence);
			this->Controls->Add(this->btnStrengthPlus5);
			this->Controls->Add(this->btnStrengthMinus5);
			this->Controls->Add(this->btnStrengthMinus1);
			this->Controls->Add(this->btnAgilityPlus5);
			this->Controls->Add(this->btnAgilityPlus1);
			this->Controls->Add(this->btnAgilityMinus1);
			this->Controls->Add(this->btnAgilityMinus5);
			this->Controls->Add(this->btnIntelligenceMinus5);
			this->Controls->Add(this->btnIntelligenceMinus1);
			this->Controls->Add(this->btnIntelligencePlus5);
			this->Controls->Add(this->btnIntelligencePlus1);
			this->Controls->Add(this->btnStrengthPlus1);
			this->Controls->Add(this->labelStrength);
			this->Controls->Add(this->buttonPreviousSprite);
			this->Controls->Add(this->buttonNextSprite);
			this->Controls->Add(this->pictureBoxPlayer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"New_Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"New_Game";
			this->Load += gcnew System::EventHandler(this, &New_Game::New_Game_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &New_Game::New_Game_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		// Список путей к картинкам
		List<String^>^ playerSprites;
		// Текущий индекс выбранной картинки
		int currentSpriteIndex = 0;

		// Список ID предметов
		array<int>^ inventoryItemIds;

		// Путь к спрайту 
		String^ spriteFilePath;

		private: System::Void New_Game_Load(System::Object^ sender, System::EventArgs^ e) 
		{
			// Создаем новый список
			playerSprites = gcnew List<String^>();
			currentSpriteIndex = 0;

			try {
				// Используем относительный путь
				String^ folderPath = System::IO::Path::Combine(
					Application::StartupPath,
					"PlayerSprites"
				);

				// Проверяем существование директории
				if (!Directory::Exists(folderPath)) {
					MessageBox::Show("Папка со спрайтами не найдена: " + folderPath);
					return;
				}

				// Получаем пути к файлам
				array<String^>^ files = Directory::GetFiles(folderPath, "*.png");

				// Добавляем файлы в список
				playerSprites->AddRange(files);

				// Загружаем первый спрайт, если есть
				if (playerSprites->Count > 0) {
					pictureBoxPlayer->Image = Image::FromFile(playerSprites[0]);
				}

				spriteFilePath = playerSprites[0];
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка загрузки спрайтов: " + ex->Message);
			}

			strengthPoints = 25;
			intelligencePoints = 25;
			agilityPoints = 25;
			totalPoints = 20;
			UpdatePointsLabels();

			// Первичный расчет производных параметров
			RecalculateDerivedStats();
		}

		private: System::Void buttonNextSprite_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (playerSprites == nullptr || playerSprites->Count == 0) return;

			currentSpriteIndex++;
			if (currentSpriteIndex >= playerSprites->Count) 
			{
				currentSpriteIndex = 0;
			}

			pictureBoxPlayer->Image = Image::FromFile(playerSprites[currentSpriteIndex]);

			spriteFilePath = playerSprites[currentSpriteIndex];
		}

		private: System::Void buttonPreviousSprite_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (playerSprites == nullptr || playerSprites->Count == 0) return;

			currentSpriteIndex--;
			if (currentSpriteIndex < 0) 
			{
				currentSpriteIndex = playerSprites->Count - 1;
			}

			pictureBoxPlayer->Image = Image::FromFile(playerSprites[currentSpriteIndex]);

			spriteFilePath = playerSprites[currentSpriteIndex];
		}

		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);

		// Метод для обработки перемещения окна
		private: System::Void New_Game_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// Отправляем системное сообщение о начале перемещения окна
			ReleaseCapture();
			SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		}

		private: Void UpdatePointsLabels() 
		{
			// Обновление текста Label для каждого атрибута
			labelStrength->Text = strengthPoints.ToString();
			labelIntelligence->Text = intelligencePoints.ToString();
			labelAgility->Text = agilityPoints.ToString();

			// Обновление Label с общим количеством очков
			labelTotalPoints->Text = "Points: " + totalPoints.ToString();

			// Блокировка кнопок с учетом ограничений
			btnStrengthPlus1->Enabled = (totalPoints >= 1);
			btnStrengthPlus5->Enabled = (totalPoints >= 5);
			btnStrengthMinus1->Enabled = (strengthPoints > 1);
			btnStrengthMinus5->Enabled = (strengthPoints > 5);

			// Аналогичные проверки для Intelligence и Agility
			btnIntelligencePlus1->Enabled = (totalPoints >= 1);
			btnIntelligencePlus5->Enabled = (totalPoints >= 5);
			btnIntelligenceMinus1->Enabled = (intelligencePoints > 1);
			btnIntelligenceMinus5->Enabled = (intelligencePoints > 5);

			btnAgilityPlus1->Enabled = (totalPoints >= 1);
			btnAgilityPlus5->Enabled = (totalPoints >= 5);
			btnAgilityMinus1->Enabled = (agilityPoints > 1);
			btnAgilityMinus5->Enabled = (agilityPoints > 5);

			// Пересчет производных параметров
			RecalculateDerivedStats();

			// Продолжить можно будет только после распределения очков
			buttonSave->Enabled = (totalPoints == 0);
		}

		private: System::Void RecalculateDerivedStats() 
		{
			// Расчет здоровья: зависит от силы и ловкости
			// Базовое значение + модификатор силы + бонус от ловкости
			healthPoints = 50 +
				(strengthPoints * 3) +  // Основной вклад силы
				(agilityPoints * 2);    // Бонус от ловкости

			// Расчет маны: зависит от интеллекта и ловкости
			// Базовое значение + модификатор интеллекта + бонус от ловкости
			manaPoints = 30 +
				(intelligencePoints * 4) +  // Основной вклад интеллекта
				(agilityPoints * 1.5);      // Небольшой бонус от ловкости

			// Расчет слотов инвентаря: зависит от силы и интеллекта
			// Базовое значение + модификатор силы и интеллекта
			inventorySlots = 10 +
				(strengthPoints / 3) +     // Вклад силы
				(intelligencePoints / 2);  // Вклад интеллекта

			// Округление дробных значений
			healthPoints = Math::Round(healthPoints);
			manaPoints = Math::Round(manaPoints);
			inventorySlots = Math::Floor(inventorySlots);

			// Обновление Label с производными параметрами
			labelHealth->Text = "HP: " + healthPoints.ToString();
			labelMana->Text = "MP: " + manaPoints.ToString();
			labelInventorySlots->Text = "INV: " + inventorySlots.ToString();
		}

		private: System::Void btnStrengthPlus1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 1) 
			{
				strengthPoints++;
				totalPoints--;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnStrengthPlus5_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 5) 
			{
				strengthPoints += 5;
				totalPoints -= 5;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnStrengthMinus1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (strengthPoints > 1) // Нельзя опускать ниже 1
			{  
				strengthPoints--;
				totalPoints++;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnStrengthMinus5_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (strengthPoints > 5) // Проверка, чтобы не опустить ниже 1
			{  
				int reduction = Math::Min(5, strengthPoints - 1);
				strengthPoints -= reduction;
				totalPoints += reduction;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnIntelligencePlus1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 1)
			{
				intelligencePoints++;
				totalPoints--;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnIntelligencePlus5_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 5)
			{
				intelligencePoints += 5;
				totalPoints -= 5;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnIntelligenceMinus1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 1)
			{
				intelligencePoints--;
				totalPoints++;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnIntelligenceMinus5_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (intelligencePoints > 5)
			{
				int reduction = Math::Min(5, intelligencePoints - 1);
				intelligencePoints -= reduction;
				totalPoints += reduction;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnAgilityPlus1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 1)
			{
				agilityPoints++;
				totalPoints--;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnAgilityPlus5_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 5)
			{
				agilityPoints += 5;
				totalPoints -= 5;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnAgilityMinus1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (totalPoints >= 1)
			{
				agilityPoints--;
				totalPoints++;
				UpdatePointsLabels();
			}
		}

		private: System::Void btnAgilityMinus5_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (agilityPoints > 5)
			{
				int reduction = Math::Min(5, agilityPoints - 1);
				agilityPoints -= reduction;
				totalPoints += reduction;
				UpdatePointsLabels();
			}
		}

		// Метод сохранения в текстовый файл
		bool SaveToFile() {
			try {
				// Создаем строки для записи
				array<String^>^ lines = {
					strengthPoints.ToString(),
					intelligencePoints.ToString(),
					agilityPoints.ToString(),
					healthPoints.ToString(),
					manaPoints.ToString(),
					inventorySlots.ToString(),
					spriteFilePath,
					// Сериализуем ID предметов
					String::Join(",", "1001,1003,1005"),
					String::Join(",", "None,None,None,None,None,None,None,None")
				};

				// Записываем в файл
				System::IO::File::WriteAllLines("temp.txt", lines);
				return true;
			}
			catch (Exception^ e) {
				return false;
			}
		}

		private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
		}

		private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			SaveToFile();
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	};
}
