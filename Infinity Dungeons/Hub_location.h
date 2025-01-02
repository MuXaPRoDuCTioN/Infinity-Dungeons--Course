#pragma once
#include "Inventory.h"

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
	private: Inventory^ formInventory;

	public:
		Hub_location(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Inventory^ formInventory = gcnew Inventory;
		}

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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->buttonInventory = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(98, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Task board";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(474, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Shop";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(98, 376);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 60);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Magick shop";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(474, 376);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(120, 60);
			this->button4->TabIndex = 3;
			this->button4->Text = L"To Dungeon";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// buttonInventory
			// 
			this->buttonInventory->Location = System::Drawing::Point(304, 432);
			this->buttonInventory->Name = L"buttonInventory";
			this->buttonInventory->Size = System::Drawing::Size(75, 23);
			this->buttonInventory->TabIndex = 4;
			this->buttonInventory->Text = L"Inventory";
			this->buttonInventory->UseVisualStyleBackColor = true;
			this->buttonInventory->Click += gcnew System::EventHandler(this, &Hub_location::buttonInventory_Click);
			// 
			// Hub_location
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(680, 480);
			this->Controls->Add(this->buttonInventory);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Hub_location";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Hub_location";
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
			formInventory->Show();
		}
};
}
