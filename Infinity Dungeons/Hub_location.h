#pragma once
#include "Inventory.h"
#include "Main_Menu.h"
#include "Dungeon.h"
#include "ShopForm.h"
#include "TasksForm.h"

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
	/// Сводка для Hub_location
	/// </summary>
	public ref class Hub_location : public System::Windows::Forms::Form
	{
	

	public:
		Hub_location(Main_Menu^ parent)
		{
			InitializeComponent();
			parentForm = parent;
		}	
	private: System::Windows::Forms::Button^ buttonExit;
	public:

		Main_Menu^ parentForm;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Hub_location()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonToTasks;
	protected:

	protected:

	private: System::Windows::Forms::Button^ buttonToShop;
	protected:


	private: System::Windows::Forms::Button^ buttonToDungeon;

	private: System::Windows::Forms::Button^ buttonInventory;

	

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Hub_location::typeid));
			this->buttonToTasks = (gcnew System::Windows::Forms::Button());
			this->buttonToShop = (gcnew System::Windows::Forms::Button());
			this->buttonToDungeon = (gcnew System::Windows::Forms::Button());
			this->buttonInventory = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonToTasks
			// 
			this->buttonToTasks->BackColor = System::Drawing::Color::Chocolate;
			this->buttonToTasks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonToTasks->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonToTasks->Location = System::Drawing::Point(79, 206);
			this->buttonToTasks->Name = L"buttonToTasks";
			this->buttonToTasks->Size = System::Drawing::Size(120, 60);
			this->buttonToTasks->TabIndex = 0;
			this->buttonToTasks->Text = L"К доске с заданиями";
			this->buttonToTasks->UseVisualStyleBackColor = false;
			this->buttonToTasks->Click += gcnew System::EventHandler(this, &Hub_location::buttonToTasks_Click);
			// 
			// buttonToShop
			// 
			this->buttonToShop->BackColor = System::Drawing::Color::Chocolate;
			this->buttonToShop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonToShop->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonToShop->Location = System::Drawing::Point(272, 206);
			this->buttonToShop->Name = L"buttonToShop";
			this->buttonToShop->Size = System::Drawing::Size(120, 60);
			this->buttonToShop->TabIndex = 1;
			this->buttonToShop->Text = L"В магазин";
			this->buttonToShop->UseVisualStyleBackColor = false;
			this->buttonToShop->Click += gcnew System::EventHandler(this, &Hub_location::buttonToShop_Click);
			// 
			// buttonToDungeon
			// 
			this->buttonToDungeon->BackColor = System::Drawing::Color::Chocolate;
			this->buttonToDungeon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonToDungeon->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonToDungeon->Location = System::Drawing::Point(272, 403);
			this->buttonToDungeon->Name = L"buttonToDungeon";
			this->buttonToDungeon->Size = System::Drawing::Size(120, 60);
			this->buttonToDungeon->TabIndex = 3;
			this->buttonToDungeon->Text = L"В подземелье";
			this->buttonToDungeon->UseVisualStyleBackColor = false;
			this->buttonToDungeon->Click += gcnew System::EventHandler(this, &Hub_location::buttonToDungeon_Click);
			// 
			// buttonInventory
			// 
			this->buttonInventory->BackColor = System::Drawing::Color::Chocolate;
			this->buttonInventory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonInventory->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonInventory->Location = System::Drawing::Point(475, 206);
			this->buttonInventory->Name = L"buttonInventory";
			this->buttonInventory->Size = System::Drawing::Size(120, 60);
			this->buttonInventory->TabIndex = 4;
			this->buttonInventory->Text = L"Инвентарь";
			this->buttonInventory->UseVisualStyleBackColor = false;
			this->buttonInventory->Click += gcnew System::EventHandler(this, &Hub_location::buttonInventory_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::Color::Chocolate;
			this->buttonExit->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonExit->Location = System::Drawing::Point(571, 12);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(58, 23);
			this->buttonExit->TabIndex = 5;
			this->buttonExit->Text = L"X";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Hub_location::buttonExit_Click);
			// 
			// Hub_location
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(641, 475);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonInventory);
			this->Controls->Add(this->buttonToDungeon);
			this->Controls->Add(this->buttonToShop);
			this->Controls->Add(this->buttonToTasks);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Hub_location";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Hub_location";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Hub_location::Hub_location_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Hub_location::Hub_location_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Hub_location::Hub_location_MouseDown);
			this->ResumeLayout(false);

		}


#pragma endregion

		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);	

		private: System::Void Hub_location_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// Отправляем системное сообщение о начале перемещения окна
			ReleaseCapture();
			SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		}
		
		private: System::Void buttonInventory_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Inventory^ formInventory = gcnew Inventory;		
			formInventory->FormClosed += gcnew FormClosedEventHandler(this, &Hub_location::Inventory_Closed);
			buttonInventory->Enabled = false;
			parentForm->SetSaveEnabled(false);
			formInventory->Show();
		}

		private: Void Inventory_Closed(Object^ sender, FormClosedEventArgs^ e)
		{
			// Код, который выполнится после закрытия дочерней формы
			parentForm->SetSaveEnabled(true);
			buttonInventory->Enabled = true;
		}

		private: System::Void Hub_location_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) 
		{
			parentForm->SetLoadEnabled(true);
			parentForm->SetSaveEnabled(false);
			parentForm->SetNewEnabled(true);
		}

		private: System::Void Hub_location_Load(System::Object^ sender, System::EventArgs^ e)
		{
			parentForm->SetLoadEnabled(false);
			parentForm->SetSaveEnabled(true);
			parentForm->SetNewEnabled(false);
		}

		private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
		}

		private: System::Void buttonToDungeon_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Dungeon^ ToDungeon = gcnew Dungeon;
			buttonToDungeon->Enabled = false;
			ToDungeon->FormClosed += gcnew FormClosedEventHandler(this, &Hub_location::Dungeon_Closed);
			ToDungeon->Show();
			this->Hide();
			parentForm->Hide();
		}

		private: Void Dungeon_Closed(Object^ sender, FormClosedEventArgs^ e)
		{
			// Код, который выполнится после закрытия дочерней формы
			buttonToDungeon->Enabled = true;
			CheckActiveQuest();
			this->Show();
			parentForm->Show();
		}

		private: System::Void buttonToShop_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			ShopForm^ Shop = gcnew ShopForm;
			buttonToShop->Enabled = false;
			Shop->FormClosed += gcnew FormClosedEventHandler(this, &Hub_location::Shop_Closed);
			Shop->Show();
			this->Hide();
			parentForm->Hide();
		}

		private: Void Shop_Closed(Object^ sender, FormClosedEventArgs^ e)
		{
			// Код, который выполнится после закрытия дочерней формы
			buttonToShop->Enabled = true;
			this->Show();
			parentForm->Show();
		}

		private: System::Void buttonToTasks_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			TasksForm^ TaskDesk = gcnew TasksForm;
			TaskDesk->FormClosed += gcnew FormClosedEventHandler(this, &Hub_location::Task_Closed);
			TaskDesk->Show();
			this->Hide();
			parentForm->Hide();
		}

		private: Void Task_Closed(Object^ sender, FormClosedEventArgs^ e)
		{
			// Код, который выполнится после закрытия дочерней формы
			CheckActiveQuest();
			this->Show();
			parentForm->Show();
		}

		private: void CheckActiveQuest() 
		{
			array<String^>^ lines = File::ReadAllLines(GetFilePath("temp.txt"));

			// Проверяем 11-ю строку (индекс 10)
			if (lines[10] != "None") {
				// Есть активное задание - блокируем кнопку
				buttonToTasks->Enabled = false;
			}
			else {
				// Нет активного задания - кнопка активна
				buttonToTasks->Enabled = true;
			}
		}

		private: static String^ GetFilePath(String^ filename) 
		{
			String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
			String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
			return System::IO::Path::Combine(exeDirectory, filename);
		}
	};
}
