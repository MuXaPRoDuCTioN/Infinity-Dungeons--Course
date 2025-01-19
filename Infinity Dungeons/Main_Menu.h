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
	private: System::Windows::Forms::Label^ label1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// To_New_Game
			// 
			this->To_New_Game->BackColor = System::Drawing::Color::Chocolate;
			this->To_New_Game->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->To_New_Game->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->To_New_Game->Location = System::Drawing::Point(214, 140);
			this->To_New_Game->Name = L"To_New_Game";
			this->To_New_Game->Size = System::Drawing::Size(214, 60);
			this->To_New_Game->TabIndex = 0;
			this->To_New_Game->Text = L"Новая игра";
			this->To_New_Game->UseVisualStyleBackColor = false;
			this->To_New_Game->Click += gcnew System::EventHandler(this, &Main_Menu::To_New_Game_Click);
			// 
			// To_Save_Game
			// 
			this->To_Save_Game->BackColor = System::Drawing::Color::Chocolate;
			this->To_Save_Game->Enabled = false;
			this->To_Save_Game->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->To_Save_Game->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->To_Save_Game->Location = System::Drawing::Point(214, 206);
			this->To_Save_Game->Name = L"To_Save_Game";
			this->To_Save_Game->Size = System::Drawing::Size(214, 60);
			this->To_Save_Game->TabIndex = 0;
			this->To_Save_Game->Text = L"Сохранить игру";
			this->To_Save_Game->UseVisualStyleBackColor = false;
			this->To_Save_Game->Click += gcnew System::EventHandler(this, &Main_Menu::To_Save_Game_Click);
			// 
			// To_Load_Game
			// 
			this->To_Load_Game->BackColor = System::Drawing::Color::Chocolate;
			this->To_Load_Game->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->To_Load_Game->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->To_Load_Game->Location = System::Drawing::Point(214, 272);
			this->To_Load_Game->Name = L"To_Load_Game";
			this->To_Load_Game->Size = System::Drawing::Size(214, 60);
			this->To_Load_Game->TabIndex = 0;
			this->To_Load_Game->Text = L"Загрузать игру";
			this->To_Load_Game->UseVisualStyleBackColor = false;
			this->To_Load_Game->Click += gcnew System::EventHandler(this, &Main_Menu::To_Load_Game_Click);
			// 
			// To_Exit
			// 
			this->To_Exit->BackColor = System::Drawing::Color::Chocolate;
			this->To_Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->To_Exit->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->To_Exit->Location = System::Drawing::Point(214, 338);
			this->To_Exit->Name = L"To_Exit";
			this->To_Exit->Size = System::Drawing::Size(214, 60);
			this->To_Exit->TabIndex = 0;
			this->To_Exit->Text = L"Выйти из игры";
			this->To_Exit->UseVisualStyleBackColor = false;
			this->To_Exit->Click += gcnew System::EventHandler(this, &Main_Menu::To_Exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Sienna;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 28, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(178, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(291, 38);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Infinity Dungeons";
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(640, 480);
			this->ControlBox = false;
			this->Controls->Add(this->label1);
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
			this->PerformLayout();

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

		public: Void SetSaveEnabled(bool Set)
		{
			To_Save_Game->Enabled = Set;
		}

		private: System::Void To_Exit_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
		}

		private: System::Void To_Save_Game_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Путь к папке для сохранения рядом с exe
			String^ saveFolder = GetFilePath("SavedFiles\\");

			// Создаем папку, если она не существует
			if (!Directory::Exists(saveFolder)) {
				Directory::CreateDirectory(saveFolder);
			}

			// Создаем форму для ввода имени файла
			Form^ inputForm = gcnew Form();
			inputForm->Text = "Сохранение файла";
			inputForm->Size = System::Drawing::Size(300, 200);
			inputForm->StartPosition = FormStartPosition::CenterScreen;

			Label^ labelFileName = gcnew Label();
			labelFileName->Text = "Введите название файла:";
			labelFileName->Location = Point(10, 20);
			labelFileName->AutoSize = true;

			TextBox^ textBoxFileName = gcnew TextBox();
			textBoxFileName->Location = Point(10, 50);
			textBoxFileName->Size = System::Drawing::Size(260, 25);

			Button^ btnSaveFile = gcnew Button();
			btnSaveFile->Text = "Сохранить";
			btnSaveFile->Location = Point(100, 100);
			btnSaveFile->DialogResult = System::Windows::Forms::DialogResult::OK;

			inputForm->Controls->Add(labelFileName);
			inputForm->Controls->Add(textBoxFileName);
			inputForm->Controls->Add(btnSaveFile);
			inputForm->AcceptButton = btnSaveFile;

			// Показываем форму
			if (inputForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				// Получаем введенное имя файла
				String^ userFileName = textBoxFileName->Text;

				// Проверяем, что имя не пустое
				if (String::IsNullOrWhiteSpace(userFileName)) {
					MessageBox::Show("Имя файла не может быть пустым!", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Добавляем расширение, если не указано
				if (!userFileName->EndsWith(".txt")) {
					userFileName += ".txt";
				}

				// Полный путь к файлу
				String^ fullPath = Path::Combine(saveFolder, userFileName);
				String^ tempFilePath = GetFilePath("temp.txt");

				try {
					// Проверяем существование файла
					if (File::Exists(fullPath)) {
						auto result = MessageBox::Show("Файл с таким именем уже существует. Перезаписать?",
							"Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

						if (result == System::Windows::Forms::DialogResult::No) {
							return;
						}
					}

					// Копируем файл
					File::Copy(tempFilePath, fullPath, true);

					MessageBox::Show("Файл успешно сохранен!", "Успех",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Ошибка сохранения: " + ex->Message, "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

			   String^ GetFilePath(String^ filename) {
				   String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
				   String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
				   return System::IO::Path::Combine(exeDirectory, filename);
			   }

		Form^ loadFileForm;

		private: System::Void To_Load_Game_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Создаем новую форму загрузки файлов
			loadFileForm = gcnew Form();
			loadFileForm->Text = "Загрузка файла";
			loadFileForm->Size = System::Drawing::Size(400, 500);
			loadFileForm->StartPosition = FormStartPosition::CenterScreen;

			// Создаем ListBox
			ListBox^ listBoxFiles = gcnew ListBox();
			listBoxFiles->Dock = DockStyle::Fill;
			listBoxFiles->Font = gcnew System::Drawing::Font("Arial", 10);
			listBoxFiles->DoubleClick += gcnew EventHandler(this, &Main_Menu::listBoxFiles_DoubleClick);

			// Загружаем список файлов
			LoadFileList(listBoxFiles);

			// Добавляем ListBox на форму
			loadFileForm->Controls->Add(listBoxFiles);

			// Показываем форму
			loadFileForm->ShowDialog();
		}

		// Метод загрузки списка файлов
		private: System::Void LoadFileList(ListBox^ listBox) {
			// Очищаем существующий список
			listBox->Items->Clear();

			// Путь к папке с сохраненными файлами
			String^ saveFolder = Application::StartupPath + "\\SavedFiles\\";

			try {
				// Проверяем существование папки
				if (!Directory::Exists(saveFolder)) {
					Directory::CreateDirectory(saveFolder);
				}

				// Получаем список всех текстовых файлов
				array<String^>^ files = Directory::GetFiles(saveFolder, "*.txt");

				// Добавляем имена файлов в ListBox
				for each (String ^ file in files) {
					listBox->Items->Add(Path::GetFileName(file));
				}

				// Если файлов нет, показываем сообщение
				if (files->Length == 0) {
					MessageBox::Show("В папке нет файлов.", "Информация",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка получения списка файлов: " + ex->Message, "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		// Обработчик двойного клика по файлу
		private: System::Void listBoxFiles_DoubleClick(Object^ sender, EventArgs^ e) {
			// Получаем ListBox
			ListBox^ listBox = safe_cast<ListBox^>(sender);

			// Проверяем, выбран ли файл
			if (listBox->SelectedItem == nullptr) {
				MessageBox::Show("Выберите файл!", "Внимание",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Получаем имя выбранного файла
			String^ selectedFileName = listBox->SelectedItem->ToString();
			String^ saveFolder = Application::StartupPath + "\\SavedFiles\\";

			// Путь к временному файлу
			String^ tempFilePath = Application::StartupPath + "\\temp.txt";

			try {
				// Полный путь к исходному файлу
				String^ fullFilePath = Path::Combine(saveFolder, selectedFileName);

				// Читаем содержимое файла
				String^ fileContent = File::ReadAllText(fullFilePath);

				// Сохраняем содержимое во временный файл
				File::WriteAllText(tempFilePath, fileContent);

				// Закрываем форму выбора файлов
				loadFileForm->Close();

				LoadGame();

				// Дополнительно можно открыть временный файл 
				// или выполнить другие действия
				// System::Diagnostics::Process::Start(tempFilePath);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка загрузки файла: " + ex->Message, "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void LoadGame();

		public: System::Void SetLoadEnabled(bool Set)
		{
			To_Load_Game->Enabled = Set;
		}

		public: System::Void SetNewEnabled(bool Set)
		{
			To_New_Game->Enabled = Set;
		}
	};
}
