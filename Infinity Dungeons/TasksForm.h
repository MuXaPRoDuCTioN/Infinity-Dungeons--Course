#pragma once
#include <fstream>
#include <string>
#include "Quest.h"

namespace InfinityDungeons {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;

	// Константы для Windows API
	#define WM_NCLBUTTONDOWN 0x00A1
	#define HTCAPTION 2

	/// <summary>
	/// Сводка для TasksForm
	/// </summary>
	public ref class TasksForm : public System::Windows::Forms::Form
	{
	public:
		TasksForm(void)
		{
			InitializeComponent();
			InitializeQuestForm();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TasksForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ buttonExit;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Chocolate;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TasksForm::SelectQuest);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Chocolate;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(12, 102);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 55);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &TasksForm::SelectQuest);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Chocolate;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(12, 189);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(159, 55);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &TasksForm::SelectQuest);
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::Color::Chocolate;
			this->buttonExit->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonExit->Location = System::Drawing::Point(203, 12);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(40, 23);
			this->buttonExit->TabIndex = 3;
			this->buttonExit->Text = L"X";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &TasksForm::buttonExit_Click);
			// 
			// TasksForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Sienna;
			this->ClientSize = System::Drawing::Size(255, 272);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TasksForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TasksForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TasksForm::TasksForm_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);



		int GetPlayerLevel() {
			array<String^>^ lines = File::ReadAllLines(GetFilePath("temp.txt"));
			return Int32::Parse(lines[11]); // 12-я строка (индекс 11)
		}

		List<array<String^>^>^ LoadEnemies() {
			String^ enemiesFilePath = GetFilePath("Enemies.txt");
			array<String^>^ enemyLines = File::ReadAllLines(enemiesFilePath);

			int playerLevel = GetPlayerLevel();
			List<array<String^>^>^ availableEnemies = gcnew List<array<String^>^>();

			for each (String ^ line in enemyLines) {
				array<String^>^ enemyData = line->Split(',');

				// Проверяем уровень доступности врага
				int minLevel = Int32::Parse(enemyData[4]);
				if (playerLevel >= minLevel) {
					availableEnemies->Add(enemyData);
				}
			}

			return availableEnemies;
		}

		static String^ GetFilePath(String^ filename) {
			String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
			String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
			return System::IO::Path::Combine(exeDirectory, filename);
		}

        // Генерация случайных заданий
        array<Quest^>^ GenerateQuests() {
            List<array<String^>^>^ enemies = LoadEnemies();
            array<Quest^>^ quests = gcnew array<Quest^>(3);
            Random^ random = gcnew Random();

            for (int i = 0; i < 3; i++) {
                int enemyIndex = random->Next(enemies->Count);
                array<String^>^ selectedEnemy = enemies[enemyIndex];

                Quest^ quest = gcnew Quest();
                quest->EnemyType = selectedEnemy[0];
                quest->EnemyName = selectedEnemy[1];
                quest->RequiredKills = random->Next(5, 15); // От 5 до 15 убийств
                quest->Reward = quest->RequiredKills * 10; // Награда золотом

                quests[i] = quest;
            }

            return quests;
        }

        // Инициализация формы
		void InitializeQuestForm() {
			array<Quest^>^ quests = GenerateQuests();
			int playerLevel = GetPlayerLevel();

			// Используем существующие кнопки
			button1->Text = String::Format(
				"Убить {0} {1}. Награда: {2} золота",
				quests[0]->RequiredKills,
				quests[0]->EnemyType,  // Только тип врага 
				quests[0]->Reward);
			button1->Tag = quests[0];

			button2->Text = String::Format(
				"Убить {0} {1}. Награда: {2} золота",
				quests[1]->RequiredKills,
				quests[1]->EnemyType,  // Только тип врага
				quests[1]->Reward);
			button2->Tag = quests[1];

			button3->Text = String::Format(
				"Убить {0} {1}. Награда: {2} золота",
				quests[2]->RequiredKills,
				quests[2]->EnemyType,  // Только тип врага
				quests[2]->Reward);
			button3->Tag = quests[2];
		}

        // Метод для обновления прогресса и выдачи награды
		// Обновленный метод проверки прогресса квеста
		void UpdateQuestProgress(String^ enemyType) {
			array<String^>^ lines = File::ReadAllLines(GetFilePath("temp.txt"));

			// Проверяем текущее задание
			array<String^>^ questData = lines[10]->Split(',');

			// Сравниваем тип врага, а не конкретное имя
			if (enemyType->Contains(questData[0])) {
				int currentKills = Int32::Parse(questData[2]);
				int requiredKills = Int32::Parse(questData[1]);

				currentKills++;
				questData[2] = currentKills.ToString();

				// Проверка на выполнение задания
				if (currentKills >= requiredKills) {
					// Начисляем награду
					int currentGold = Int32::Parse(lines[5]); // Золото в 6-й строке
					int reward = Int32::Parse(questData[3]);

					lines[5] = (currentGold + reward).ToString();

					// Сбрасываем задание
					lines[10] = "None";

					MessageBox::Show("Задание выполнено! Награда: {reward} золота");
				}
				else {
					// Обновляем прогресс, если задание не завершено
					lines[10] = String::Join(",", questData);
				}

				File::WriteAllLines(GetFilePath("temp.txt"), lines);
			}
		}

		// Обработчик выбора задания
		void SelectQuest(Object^ sender, EventArgs^ e) {
			Button^ button = safe_cast<Button^>(sender);
			Quest^ selectedQuest = safe_cast<Quest^>(button->Tag);

			// Сохраняем задание в 11-й строке temp.txt
			array<String^>^ lines = File::ReadAllLines(GetFilePath("temp.txt"));
			lines[10] = String::Format("{0},{1},{2},{3}",
				selectedQuest->EnemyType,     // Тип врага
				selectedQuest->RequiredKills, // Требуемое количество убийств
				0,                            // Текущий прогресс убийств
				selectedQuest->Reward);        // Награда золотом

			File::WriteAllLines(GetFilePath("temp.txt"), lines);
			this->Close();
		}

	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void TasksForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Отправляем системное сообщение о начале перемещения окна
		ReleaseCapture();
		SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}
	};
}
