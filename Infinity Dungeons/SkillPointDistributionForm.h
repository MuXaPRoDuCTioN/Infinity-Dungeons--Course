#pragma once
#include "Player.h"

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
	/// Сводка для SkillPointDistributionForm
	/// </summary>
	public ref class SkillPointDistributionForm : public System::Windows::Forms::Form
	{
	private:
		Player^ player;

	public:
		SkillPointDistributionForm(Player^ currentPlayer)
		{
			player = currentPlayer;
			InitializeComponent();
			availablePointsLabel->Text = String::Format("Доступные очки навыков: {0}", player->SkillPoints);

			// Устанавливаем начальные значения с текущими характеристиками
			strengthUpDown->Minimum = player->Strength;
			strengthUpDown->Value = player->Strength;

			intelligenceUpDown->Minimum = player->Intelligence;
			intelligenceUpDown->Value = player->Intelligence;

			agilityUpDown->Minimum = player->Agility;
			agilityUpDown->Value = player->Agility;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SkillPointDistributionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ strengthUpDown;
	private: System::Windows::Forms::NumericUpDown^ intelligenceUpDown;
	private: System::Windows::Forms::NumericUpDown^ agilityUpDown;
	private: System::Windows::Forms::Label^ availablePointsLabel;
	private: System::Windows::Forms::Button^ confirmButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


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
			this->strengthUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->intelligenceUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->agilityUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->availablePointsLabel = (gcnew System::Windows::Forms::Label());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->strengthUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intelligenceUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->agilityUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// strengthUpDown
			// 
			this->strengthUpDown->Location = System::Drawing::Point(180, 19);
			this->strengthUpDown->Name = L"strengthUpDown";
			this->strengthUpDown->Size = System::Drawing::Size(47, 20);
			this->strengthUpDown->TabIndex = 0;
			this->strengthUpDown->ValueChanged += gcnew System::EventHandler(this, &SkillPointDistributionForm::UpdateAvailablePoints);
			// 
			// intelligenceUpDown
			// 
			this->intelligenceUpDown->Location = System::Drawing::Point(180, 45);
			this->intelligenceUpDown->Name = L"intelligenceUpDown";
			this->intelligenceUpDown->Size = System::Drawing::Size(47, 20);
			this->intelligenceUpDown->TabIndex = 1;
			this->intelligenceUpDown->ValueChanged += gcnew System::EventHandler(this, &SkillPointDistributionForm::UpdateAvailablePoints);
			// 
			// agilityUpDown
			// 
			this->agilityUpDown->Location = System::Drawing::Point(180, 71);
			this->agilityUpDown->Name = L"agilityUpDown";
			this->agilityUpDown->Size = System::Drawing::Size(47, 20);
			this->agilityUpDown->TabIndex = 2;
			this->agilityUpDown->ValueChanged += gcnew System::EventHandler(this, &SkillPointDistributionForm::UpdateAvailablePoints);
			// 
			// availablePointsLabel
			// 
			this->availablePointsLabel->AutoSize = true;
			this->availablePointsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->availablePointsLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->availablePointsLabel->Location = System::Drawing::Point(21, 103);
			this->availablePointsLabel->Name = L"availablePointsLabel";
			this->availablePointsLabel->Size = System::Drawing::Size(46, 17);
			this->availablePointsLabel->TabIndex = 3;
			this->availablePointsLabel->Text = L"label1";
			// 
			// confirmButton
			// 
			this->confirmButton->BackColor = System::Drawing::Color::Chocolate;
			this->confirmButton->Enabled = false;
			this->confirmButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->confirmButton->Location = System::Drawing::Point(145, 132);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(82, 28);
			this->confirmButton->TabIndex = 4;
			this->confirmButton->Text = L"Подтвердить";
			this->confirmButton->UseVisualStyleBackColor = false;
			this->confirmButton->Click += gcnew System::EventHandler(this, &SkillPointDistributionForm::ConfirmDistribution);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(21, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Сила:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(21, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Интеллект:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(21, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Ловкость:";
			// 
			// SkillPointDistributionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Sienna;
			this->ClientSize = System::Drawing::Size(239, 172);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->availablePointsLabel);
			this->Controls->Add(this->agilityUpDown);
			this->Controls->Add(this->intelligenceUpDown);
			this->Controls->Add(this->strengthUpDown);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"SkillPointDistributionForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SkillPointDistributionForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &SkillPointDistributionForm::SkillPointDistributionForm_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->strengthUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intelligenceUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->agilityUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		void UpdateAvailablePoints(Object^ sender, EventArgs^ e) {
			int totalAllocated =
				Decimal::ToInt32(strengthUpDown->Value) - player->Strength +
				Decimal::ToInt32(intelligenceUpDown->Value) - player->Intelligence +
				Decimal::ToInt32(agilityUpDown->Value) - player->Agility;

			// Блокировка превышения доступных очков
			if (totalAllocated > player->SkillPoints) {
				// Сбрасываем последнее изменение
				NumericUpDown^ changedUpDown = safe_cast<NumericUpDown^>(sender);
				changedUpDown->Value = changedUpDown->Value - 1;
				totalAllocated = player->SkillPoints;
			}

			// Обновляем метку
			availablePointsLabel->Text = String::Format(
				"Доступные очки навыков: {0}",
				player->SkillPoints - totalAllocated
			);

			// Активируем кнопку только если все очки распределены
			confirmButton->Enabled = (totalAllocated == player->SkillPoints);
		}

		void ConfirmDistribution(Object^ sender, EventArgs^ e) {
			int strengthIncrease = Decimal::ToInt32(strengthUpDown->Value) - player->Strength;
			int intelligenceIncrease = Decimal::ToInt32(intelligenceUpDown->Value) - player->Intelligence;
			int agilityIncrease = Decimal::ToInt32(agilityUpDown->Value) - player->Agility;

			int totalAllocated = strengthIncrease + intelligenceIncrease + agilityIncrease;

			// Если распределены не все очки, возвращаем остаток
			if (totalAllocated < player->SkillPoints) {
				player->SkillPoints -= totalAllocated;
			}

			// Распределяем очки
			player->DistributeSkillPoints(
				strengthIncrease,
				intelligenceIncrease,
				agilityIncrease
			);

			// Сохраняем изменения
			player->SavePlayerStats();

			this->DialogResult = Windows::Forms::DialogResult::OK;
			this->Close();
		}

		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);


	private: System::Void SkillPointDistributionForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Отправляем системное сообщение о начале перемещения окна
		ReleaseCapture();
		SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}
};
}
