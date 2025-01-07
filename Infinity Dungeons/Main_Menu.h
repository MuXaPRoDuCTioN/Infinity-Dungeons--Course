#pragma once
#include "New_Game.h"

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
	/// Сводка для Main_Menu
	/// </summary>
	public ref class Main_Menu : public System::Windows::Forms::Form
	{
	public:
		Main_Menu(void)
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
		~Main_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ To_New_Game;
	private: System::Windows::Forms::Button^ To_Save_Game;
	private: System::Windows::Forms::Button^ To_Load_Game;
	private: System::Windows::Forms::Button^ To_Exit;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_Menu::typeid));
			this->To_New_Game = (gcnew System::Windows::Forms::Button());
			this->To_Save_Game = (gcnew System::Windows::Forms::Button());
			this->To_Load_Game = (gcnew System::Windows::Forms::Button());
			this->To_Exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// To_New_Game
			// 
			this->To_New_Game->Location = System::Drawing::Point(214, 140);
			this->To_New_Game->Name = L"To_New_Game";
			this->To_New_Game->Size = System::Drawing::Size(214, 60);
			this->To_New_Game->TabIndex = 0;
			this->To_New_Game->Text = L"New Game";
			this->To_New_Game->UseVisualStyleBackColor = true;
			this->To_New_Game->Click += gcnew System::EventHandler(this, &Main_Menu::To_New_Game_Click);
			// 
			// To_Save_Game
			// 
			this->To_Save_Game->Enabled = false;
			this->To_Save_Game->Location = System::Drawing::Point(214, 206);
			this->To_Save_Game->Name = L"To_Save_Game";
			this->To_Save_Game->Size = System::Drawing::Size(214, 60);
			this->To_Save_Game->TabIndex = 0;
			this->To_Save_Game->Text = L"Save Game";
			this->To_Save_Game->UseVisualStyleBackColor = true;
			this->To_Save_Game->Click += gcnew System::EventHandler(this, &Main_Menu::To_Save_Game_Click);
			// 
			// To_Load_Game
			// 
			this->To_Load_Game->Location = System::Drawing::Point(214, 272);
			this->To_Load_Game->Name = L"To_Load_Game";
			this->To_Load_Game->Size = System::Drawing::Size(214, 60);
			this->To_Load_Game->TabIndex = 0;
			this->To_Load_Game->Text = L"Load Game";
			this->To_Load_Game->UseVisualStyleBackColor = true;
			this->To_Load_Game->Click += gcnew System::EventHandler(this, &Main_Menu::To_Load_Game_Click);
			// 
			// To_Exit
			// 
			this->To_Exit->Location = System::Drawing::Point(214, 338);
			this->To_Exit->Name = L"To_Exit";
			this->To_Exit->Size = System::Drawing::Size(214, 60);
			this->To_Exit->TabIndex = 0;
			this->To_Exit->Text = L"Exit Game";
			this->To_Exit->UseVisualStyleBackColor = true;
			this->To_Exit->Click += gcnew System::EventHandler(this, &Main_Menu::To_Exit_Click);
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(640, 480);
			this->ControlBox = false;
			this->Controls->Add(this->To_Exit);
			this->Controls->Add(this->To_Load_Game);
			this->Controls->Add(this->To_Save_Game);
			this->Controls->Add(this->To_New_Game);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Main_Menu";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main_Menu";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Main_Menu::Main_Menu_MouseDown_1);
			this->ResumeLayout(false);

		}

#pragma endregion
		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);

		// Метод для обработки перемещения окна
		private: System::Void Main_Menu_MouseDown_1(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// Отправляем системное сообщение о начале перемещения окна
			ReleaseCapture();
			SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		}
	
		private: System::Void To_New_Game_Click(System::Object^ sender, System::EventArgs^ e);

		public: Void SetSaveLoadEnabled(bool Set)
		{
			To_Save_Game->Enabled = Set;
			To_Load_Game->Enabled = Set;
		}

		private: System::Void To_Exit_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
		}

		private: System::Void To_Save_Game_Click(System::Object^ sender, System::EventArgs^ e) 
		{

		}

		private: System::Void To_Load_Game_Click(System::Object^ sender, System::EventArgs^ e)
		{

		}
	};
}
