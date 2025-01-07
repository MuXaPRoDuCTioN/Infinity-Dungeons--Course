#pragma once
#include <fstream>
#include <string>
#include "ItemData.h"

namespace InfinityDungeons 
{

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
	/// Сводка для Inventory
	/// </summary>
	public ref class Inventory : public System::Windows::Forms::Form
	{
	public:
		Inventory(void)
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
		~Inventory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBoxPlayer;
	private: System::Windows::Forms::Label^ labelStrength;

	private: System::Windows::Forms::Label^ labelIntelligence;
	private: System::Windows::Forms::Label^ labelAgility;
	private: System::Windows::Forms::Label^ labelHP;
	private: System::Windows::Forms::Label^ labelMP;
	private: System::Windows::Forms::Label^ labelInvent;







	private: System::Windows::Forms::ListBox^ listBoxItems;
	private: System::Windows::Forms::Button^ buttonHelmet;
	private: System::Windows::Forms::Button^ buttonCuirass;
	private: System::Windows::Forms::Button^ buttonGreaves;
	private: System::Windows::Forms::Button^ buttonBoots;




	private: System::Windows::Forms::Button^ buttonGloves;
	private: System::Windows::Forms::Button^ buttonRing;
	private: System::Windows::Forms::Button^ buttonNecklace;
	private: System::Windows::Forms::Button^ buttonWeapon;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Label^ lblStrength;
	private: System::Windows::Forms::Label^ lblIntelligence;
	private: System::Windows::Forms::Label^ lblAgility;
	private: System::Windows::Forms::Label^ lblHP;
	private: System::Windows::Forms::Label^ lblMP;
	private: System::Windows::Forms::Label^ lblInv;











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
			this->labelStrength = (gcnew System::Windows::Forms::Label());
			this->labelIntelligence = (gcnew System::Windows::Forms::Label());
			this->labelAgility = (gcnew System::Windows::Forms::Label());
			this->labelHP = (gcnew System::Windows::Forms::Label());
			this->labelMP = (gcnew System::Windows::Forms::Label());
			this->labelInvent = (gcnew System::Windows::Forms::Label());
			this->listBoxItems = (gcnew System::Windows::Forms::ListBox());
			this->buttonHelmet = (gcnew System::Windows::Forms::Button());
			this->buttonCuirass = (gcnew System::Windows::Forms::Button());
			this->buttonGreaves = (gcnew System::Windows::Forms::Button());
			this->buttonBoots = (gcnew System::Windows::Forms::Button());
			this->buttonGloves = (gcnew System::Windows::Forms::Button());
			this->buttonRing = (gcnew System::Windows::Forms::Button());
			this->buttonNecklace = (gcnew System::Windows::Forms::Button());
			this->buttonWeapon = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->lblStrength = (gcnew System::Windows::Forms::Label());
			this->lblIntelligence = (gcnew System::Windows::Forms::Label());
			this->lblAgility = (gcnew System::Windows::Forms::Label());
			this->lblHP = (gcnew System::Windows::Forms::Label());
			this->lblMP = (gcnew System::Windows::Forms::Label());
			this->lblInv = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayer))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxPlayer
			// 
			this->pictureBoxPlayer->Location = System::Drawing::Point(55, 42);
			this->pictureBoxPlayer->Name = L"pictureBoxPlayer";
			this->pictureBoxPlayer->Size = System::Drawing::Size(140, 210);
			this->pictureBoxPlayer->TabIndex = 0;
			this->pictureBoxPlayer->TabStop = false;
			// 
			// labelStrength
			// 
			this->labelStrength->AutoSize = true;
			this->labelStrength->Location = System::Drawing::Point(466, 42);
			this->labelStrength->Name = L"labelStrength";
			this->labelStrength->Size = System::Drawing::Size(35, 13);
			this->labelStrength->TabIndex = 1;
			this->labelStrength->Text = L"label1";
			// 
			// labelIntelligence
			// 
			this->labelIntelligence->AutoSize = true;
			this->labelIntelligence->Location = System::Drawing::Point(466, 73);
			this->labelIntelligence->Name = L"labelIntelligence";
			this->labelIntelligence->Size = System::Drawing::Size(35, 13);
			this->labelIntelligence->TabIndex = 2;
			this->labelIntelligence->Text = L"label2";
			// 
			// labelAgility
			// 
			this->labelAgility->AutoSize = true;
			this->labelAgility->Location = System::Drawing::Point(466, 102);
			this->labelAgility->Name = L"labelAgility";
			this->labelAgility->Size = System::Drawing::Size(35, 13);
			this->labelAgility->TabIndex = 3;
			this->labelAgility->Text = L"label3";
			// 
			// labelHP
			// 
			this->labelHP->AutoSize = true;
			this->labelHP->Location = System::Drawing::Point(466, 178);
			this->labelHP->Name = L"labelHP";
			this->labelHP->Size = System::Drawing::Size(35, 13);
			this->labelHP->TabIndex = 4;
			this->labelHP->Text = L"label4";
			// 
			// labelMP
			// 
			this->labelMP->AutoSize = true;
			this->labelMP->Location = System::Drawing::Point(466, 201);
			this->labelMP->Name = L"labelMP";
			this->labelMP->Size = System::Drawing::Size(35, 13);
			this->labelMP->TabIndex = 5;
			this->labelMP->Text = L"label5";
			// 
			// labelInvent
			// 
			this->labelInvent->AutoSize = true;
			this->labelInvent->Location = System::Drawing::Point(466, 228);
			this->labelInvent->Name = L"labelInvent";
			this->labelInvent->Size = System::Drawing::Size(35, 13);
			this->labelInvent->TabIndex = 6;
			this->labelInvent->Text = L"label6";
			// 
			// listBoxItems
			// 
			this->listBoxItems->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBoxItems->FormattingEnabled = true;
			this->listBoxItems->Location = System::Drawing::Point(563, 42);
			this->listBoxItems->Name = L"listBoxItems";
			this->listBoxItems->Size = System::Drawing::Size(130, 208);
			this->listBoxItems->TabIndex = 7;
			this->listBoxItems->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Inventory::listBoxItems_MouseClick);
			// 
			// buttonHelmet
			// 
			this->buttonHelmet->Location = System::Drawing::Point(269, 46);
			this->buttonHelmet->Name = L"buttonHelmet";
			this->buttonHelmet->Size = System::Drawing::Size(40, 40);
			this->buttonHelmet->TabIndex = 8;
			this->buttonHelmet->Text = L"buttonHelmet";
			this->buttonHelmet->UseVisualStyleBackColor = true;
			this->buttonHelmet->Click += gcnew System::EventHandler(this, &Inventory::buttonHelmet_Click);
			// 
			// buttonCuirass
			// 
			this->buttonCuirass->Location = System::Drawing::Point(269, 102);
			this->buttonCuirass->Name = L"buttonCuirass";
			this->buttonCuirass->Size = System::Drawing::Size(40, 40);
			this->buttonCuirass->TabIndex = 8;
			this->buttonCuirass->Text = L"buttonCuirass";
			this->buttonCuirass->UseVisualStyleBackColor = true;
			this->buttonCuirass->Click += gcnew System::EventHandler(this, &Inventory::buttonCuirass_Click);
			// 
			// buttonGreaves
			// 
			this->buttonGreaves->Location = System::Drawing::Point(269, 151);
			this->buttonGreaves->Name = L"buttonGreaves";
			this->buttonGreaves->Size = System::Drawing::Size(40, 40);
			this->buttonGreaves->TabIndex = 8;
			this->buttonGreaves->Text = L"buttonGreaves";
			this->buttonGreaves->UseVisualStyleBackColor = true;
			this->buttonGreaves->Click += gcnew System::EventHandler(this, &Inventory::buttonGreaves_Click);
			// 
			// buttonBoots
			// 
			this->buttonBoots->Location = System::Drawing::Point(269, 201);
			this->buttonBoots->Name = L"buttonBoots";
			this->buttonBoots->Size = System::Drawing::Size(40, 40);
			this->buttonBoots->TabIndex = 8;
			this->buttonBoots->Text = L"buttonBoots";
			this->buttonBoots->UseVisualStyleBackColor = true;
			this->buttonBoots->Click += gcnew System::EventHandler(this, &Inventory::buttonBoots_Click);
			// 
			// buttonGloves
			// 
			this->buttonGloves->Location = System::Drawing::Point(324, 124);
			this->buttonGloves->Name = L"buttonGloves";
			this->buttonGloves->Size = System::Drawing::Size(40, 40);
			this->buttonGloves->TabIndex = 8;
			this->buttonGloves->Text = L"buttonGloves";
			this->buttonGloves->UseVisualStyleBackColor = true;
			this->buttonGloves->Click += gcnew System::EventHandler(this, &Inventory::buttonGloves_Click);
			// 
			// buttonRing
			// 
			this->buttonRing->Location = System::Drawing::Point(211, 124);
			this->buttonRing->Name = L"buttonRing";
			this->buttonRing->Size = System::Drawing::Size(40, 40);
			this->buttonRing->TabIndex = 8;
			this->buttonRing->Text = L"buttonRing";
			this->buttonRing->UseVisualStyleBackColor = true;
			this->buttonRing->Click += gcnew System::EventHandler(this, &Inventory::buttonRing_Click);
			// 
			// buttonNecklace
			// 
			this->buttonNecklace->Location = System::Drawing::Point(211, 73);
			this->buttonNecklace->Name = L"buttonNecklace";
			this->buttonNecklace->Size = System::Drawing::Size(40, 40);
			this->buttonNecklace->TabIndex = 8;
			this->buttonNecklace->Text = L"buttonNecklace";
			this->buttonNecklace->UseVisualStyleBackColor = true;
			this->buttonNecklace->Click += gcnew System::EventHandler(this, &Inventory::buttonNecklace_Click);
			// 
			// buttonWeapon
			// 
			this->buttonWeapon->Location = System::Drawing::Point(324, 73);
			this->buttonWeapon->Name = L"buttonWeapon";
			this->buttonWeapon->Size = System::Drawing::Size(40, 40);
			this->buttonWeapon->TabIndex = 9;
			this->buttonWeapon->Text = L"buttonWeapon";
			this->buttonWeapon->UseVisualStyleBackColor = true;
			this->buttonWeapon->Click += gcnew System::EventHandler(this, &Inventory::buttonWeapon_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(698, 13);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(23, 23);
			this->buttonExit->TabIndex = 10;
			this->buttonExit->Text = L"X";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Inventory::buttonExit_Click);
			// 
			// lblStrength
			// 
			this->lblStrength->AutoSize = true;
			this->lblStrength->Location = System::Drawing::Point(398, 42);
			this->lblStrength->Name = L"lblStrength";
			this->lblStrength->Size = System::Drawing::Size(53, 13);
			this->lblStrength->TabIndex = 11;
			this->lblStrength->Text = L"Strength: ";
			// 
			// lblIntelligence
			// 
			this->lblIntelligence->AutoSize = true;
			this->lblIntelligence->Location = System::Drawing::Point(398, 73);
			this->lblIntelligence->Name = L"lblIntelligence";
			this->lblIntelligence->Size = System::Drawing::Size(67, 13);
			this->lblIntelligence->TabIndex = 12;
			this->lblIntelligence->Text = L"Intelligence: ";
			// 
			// lblAgility
			// 
			this->lblAgility->AutoSize = true;
			this->lblAgility->Location = System::Drawing::Point(398, 102);
			this->lblAgility->Name = L"lblAgility";
			this->lblAgility->Size = System::Drawing::Size(40, 13);
			this->lblAgility->TabIndex = 13;
			this->lblAgility->Text = L"Agility: ";
			// 
			// lblHP
			// 
			this->lblHP->AutoSize = true;
			this->lblHP->Location = System::Drawing::Point(398, 178);
			this->lblHP->Name = L"lblHP";
			this->lblHP->Size = System::Drawing::Size(28, 13);
			this->lblHP->TabIndex = 14;
			this->lblHP->Text = L"HP: ";
			// 
			// lblMP
			// 
			this->lblMP->AutoSize = true;
			this->lblMP->Location = System::Drawing::Point(398, 201);
			this->lblMP->Name = L"lblMP";
			this->lblMP->Size = System::Drawing::Size(29, 13);
			this->lblMP->TabIndex = 15;
			this->lblMP->Text = L"MP: ";
			// 
			// lblInv
			// 
			this->lblInv->AutoSize = true;
			this->lblInv->Location = System::Drawing::Point(398, 228);
			this->lblInv->Name = L"lblInv";
			this->lblInv->Size = System::Drawing::Size(28, 13);
			this->lblInv->TabIndex = 16;
			this->lblInv->Text = L"Inv: ";
			// 
			// Inventory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 350);
			this->Controls->Add(this->lblInv);
			this->Controls->Add(this->lblMP);
			this->Controls->Add(this->lblHP);
			this->Controls->Add(this->lblAgility);
			this->Controls->Add(this->lblIntelligence);
			this->Controls->Add(this->lblStrength);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonWeapon);
			this->Controls->Add(this->buttonNecklace);
			this->Controls->Add(this->buttonRing);
			this->Controls->Add(this->buttonGloves);
			this->Controls->Add(this->buttonBoots);
			this->Controls->Add(this->buttonGreaves);
			this->Controls->Add(this->buttonCuirass);
			this->Controls->Add(this->buttonHelmet);
			this->Controls->Add(this->listBoxItems);
			this->Controls->Add(this->labelInvent);
			this->Controls->Add(this->labelMP);
			this->Controls->Add(this->labelHP);
			this->Controls->Add(this->labelAgility);
			this->Controls->Add(this->labelIntelligence);
			this->Controls->Add(this->labelStrength);
			this->Controls->Add(this->pictureBoxPlayer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Inventory";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Inventory";
			this->Load += gcnew System::EventHandler(this, &Inventory::Inventory_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Inventory::Inventory_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);

		// Метод для чтения ID из файла
		private: List<int>^ ReadIDsFromFile(String^ filename) {
			List<int>^ ids = gcnew List<int>();

			// Читаем все строки файла
			array<String^>^ lines = File::ReadAllLines(filename);

			// Получаем 8-ю строку (индекс 7)
			String^ sevenLine = lines[7];

			// Разбиваем строку по запятой
			array<String^>^ idStrings = sevenLine->Split(',');

			// Преобразуем каждый ID
			for each (String ^ idStr in idStrings) {
				int id;
				if (Int32::TryParse(idStr->Trim(), id)) {
					ids->Add(id);
				}
			}

			return ids;
		}

		private: Void LoadItemNames(List<int>^ itemIDs) 
		{
			try {
				// Чтение всех строк файла с предметами
				array<String^>^ itemLines = File::ReadAllLines("Items.txt");

				// Очищаем существующий ListBox
				listBoxItems->Items->Clear();

				// Перебираем каждый ID из списка
				for each (int targetID in itemIDs) {
					// Ищем соответствующую строку в файле
					for each (String ^ line in itemLines) {
						// Разбиваем строку на части
						array<String^>^ parts = line->Split(',');

						// Проверяем, совпадает ли ID
						if (parts->Length >= 3 &&
							Int32::Parse(parts[0]->Trim()) == targetID) {

							// Добавляем название предмета в ListBox
							listBoxItems->Items->Add(gcnew ItemData(targetID, parts[2]->Trim()));
							break; // Выходим из внутреннего цикла после находки
						}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка загрузки предметов: " + ex->Message);
			}
		}

		private: System::Void Inventory_Load(System::Object^ sender, System::EventArgs^ e) 
		{
			String^ fileName = "temp.txt";
			LoadImageFromFile();
			LoadStatsFromFile();
			List<int>^ IDs = ReadIDsFromFile(fileName);
			LoadItemNames(IDs);
			InitializeContextMenu();
			LoadEquipment(fileName);
		}

		private:
			// Объявляем контекстное меню
			System::Windows::Forms::ContextMenuStrip^ itemContextMenu;

			void InitializeContextMenu() 
			{
				// Создаем контекстное меню
				itemContextMenu = gcnew System::Windows::Forms::ContextMenuStrip();

				ToolStripMenuItem^ equipItem = gcnew ToolStripMenuItem("Экипировать");
				equipItem->Name = "EquipItem"; // Задаем имя

				equipItem->Click += gcnew EventHandler(this, &Inventory::OnEquipItem);

				// Добавляем пункты меню
				itemContextMenu->Items->Add(equipItem);
				itemContextMenu->Items->Add("Редактировать", nullptr, gcnew EventHandler(this, &Inventory::OnEditItem));
				itemContextMenu->Items->Add("Удалить", nullptr, gcnew EventHandler(this, &Inventory::OnDeleteItem));

				// Назначаем контекстное меню ListBox
				listBoxItems->ContextMenuStrip = itemContextMenu;
			}

			// Обработчики событий для пунктов меню
			void OnEquipItem(Object^ sender, EventArgs^ e)
			{
				if (listBoxItems->SelectedItem != nullptr) {
					// Чтение всех строк файла с предметами
					array<String^>^ itemLines = File::ReadAllLines("Items.txt");

					ItemData^ selectedItem = safe_cast<ItemData^>(listBoxItems->SelectedItem);
					int selectedID = selectedItem->ID;

					// Перебираем каждый ID из списка
					for each (String ^ line in itemLines) {
						// Разбиваем строку на части
						array<String^>^ parts = line->Split(',');

						// Проверяем, совпадает ли ID
						if (parts->Length >= 3 &&
							Int32::Parse(parts[0]->Trim()) == selectedID && 
							Int32::Parse(parts[3]->Trim())) {

							EquipItem(selectedID, listBoxItems->SelectedIndex);
						}
					}
				}				
			}

			void OnEditItem(Object^ sender, EventArgs^ e) 
			{
				if (listBoxItems->SelectedItem != nullptr) {
					String^ selectedItem = listBoxItems->SelectedItem->ToString();
					MessageBox::Show("Редактирование: " + selectedItem);
				}
			}

			void OnDeleteItem(Object^ sender, EventArgs^ e) 
			{
				if (listBoxItems->SelectedItem != nullptr) {
					int selectedIndex = listBoxItems->SelectedIndex;
					listBoxItems->Items->RemoveAt(selectedIndex);
				}
			}

		private: System::Void Inventory_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// Отправляем системное сообщение о начале перемещения окна
			ReleaseCapture();
			SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		}

		private: Void LoadImageFromFile() 
		{
			std::string filePath = "temp.txt";
			std::ifstream file(filePath);
			std::string line;
    
			// Пропускаем первые 6 строк
			for (int i = 0; i < 6; ++i) {
				std::getline(file, line);
			}
    
			// Читаем 7-ю строку (путь к картинке)
			std::getline(file, line);
    
			// Преобразуем std::string в System::String^
			String^ imagePath = gcnew String(line.c_str());
    
			// Загружаем изображение в существующий ImageBox
			if (System::IO::File::Exists(imagePath)) 
			{
				pictureBoxPlayer->Image = Image::FromFile(imagePath);
			}
		}

		private: Void LoadStatsFromFile()
		{
			std::string filePath = "temp.txt";
			std::ifstream file(filePath);
			std::string line;

			for (int i = 0; i < 6; i++) 
			{
				std::getline(file, line);

				// Преобразуем std::string в System::String^
				String^ labelText = gcnew String(line.c_str());

				// Устанавливаем текст в label
				if (i == 0)
					labelStrength->Text = labelText;
				else if (i == 1)
					labelIntelligence->Text = labelText;
				else if (i == 2)
					labelAgility->Text = labelText;
				else if (i == 3)
					labelHP->Text = labelText;
				else if (i == 4)
					labelMP->Text = labelText;
				else if (i == 5)
					labelInvent->Text = labelText;
			}			
		}
		
		private: Void LoadEquipment(String^ filename)
		{
			// Читаем все строки файла
			array<String^>^ lines = File::ReadAllLines(filename);

			// Получаем 9-ю строку (индекс 8)
			String^ eightLine = lines[8];

			// Разбиваем строку по запятой
			array<String^>^ idStrings = eightLine->Split(',');

			//Заглушка: заносим в текст кнопок None или название предмета
			int i = 0;
			if (idStrings[i] == "None")
				buttonWeapon->Text = idStrings[i];
			else
				buttonWeapon->Text = LoadItemName(Int32::Parse(idStrings[i]));
			i++;

			if (idStrings[i] == "None")
				buttonHelmet->Text = idStrings[i];
			else
				buttonHelmet->Text = LoadItemName(Int32::Parse(idStrings[i]));
			i++;

			if (idStrings[i] == "None")
				buttonCuirass->Text = idStrings[i];
			else
				buttonCuirass->Text = LoadItemName(Int32::Parse(idStrings[i]));
			i++;

			if (idStrings[i] == "None")
				buttonGloves->Text = idStrings[i];
			else
				buttonGloves->Text = LoadItemName(Int32::Parse(idStrings[i]));
			i++;

			if (idStrings[i] == "None")
				buttonGreaves->Text = idStrings[i];
			else
				buttonGreaves->Text = LoadItemName(Int32::Parse(idStrings[i]));
			i++;

			if (idStrings[i] == "None")
				buttonBoots->Text = idStrings[i];
			else
				buttonBoots->Text = LoadItemName(Int32::Parse(idStrings[i]));
			i++;

			if (idStrings[i] == "None")
				buttonNecklace->Text = idStrings[i];
			else
				buttonNecklace->Text = LoadItemName(Int32::Parse(idStrings[i]));
			i++;

			if (idStrings[i] == "None")
				buttonRing->Text = idStrings[i];
			else
				buttonRing->Text = LoadItemName(Int32::Parse(idStrings[i]));
		}

		private: String^ LoadItemName(Int32 itemID)
		{
			// Чтение всех строк файла с предметами
			array<String^>^ itemLines = File::ReadAllLines("Items.txt");


			// Перебираем каждый ID из списка
			for each (String ^ line in itemLines) {
				// Разбиваем строку на части
				array<String^>^ parts = line->Split(',');

				// Проверяем, совпадает ли ID
				if (parts->Length >= 3 &&
					Int32::Parse(parts[0]->Trim()) == itemID) {

					// Добавляем название предмета в ListBox
					return parts[2]->Trim();
				}
			}
		}

		private: Void EquipItem(int selectedID, int index)
		{
			// Чтение всех строк файла с предметами
			array<String^>^ itemLines = File::ReadAllLines("Items.txt");

			// Перебираем каждый ID из списка
			for each (String ^ line in itemLines) {
				// Разбиваем строку на части
				array<String^>^ parts = line->Split(',');

				// Проверяем, совпадает ли ID
				if (parts->Length >= 3 &&
					Int32::Parse(parts[0]->Trim()) == selectedID &&
					Int32::Parse(parts[1]->Trim()) == 0)
				{
					String^ tempString = buttonWeapon->Text;
					buttonWeapon->Text = parts[2]->Trim();
					listBoxItems->Items->RemoveAt(index);
					if (tempString != "None")
					{
						ReplaceItem(selectedID, index);
					}
					else
					{
						FromInventory(selectedID, index);
					}
					
				}
			}
		}

		private: Int32 FindID(String^ IDlessString)
		{
			// Чтение всех строк файла с предметами
			array<String^>^ itemLines = File::ReadAllLines("Items.txt");

			// Перебираем каждый ID из списка
			for each (String ^ line in itemLines) {
				// Разбиваем строку на части
				array<String^>^ parts = line->Split(',');

				// Проверяем, совпадает ли ID
				if (parts->Length >= 3 &&
					parts[2]->Trim() == IDlessString)
				{
					return Int32::Parse(parts[0]->Trim());
				}
			}
		}

		private: Void FromInventory(int selectedID, int index)
		{
			// Чтение всех строк файла с предметами
			array<String^>^ itemLines = File::ReadAllLines("Items.txt");
			array<String^>^ lines = File::ReadAllLines("temp.txt");
			
			// Разделяем строку на элементы
			array<String^>^ elements = lines[7]->Split(',');
			// Заменяем нужный элемент
			List<String^>^ newElements = gcnew List<String^>(elements);
			newElements->RemoveAt(index);

			// Собираем строку обратно
			lines[7] = String::Join(",", newElements->ToArray());

			elements = lines[8]->Split(',');
			// Перебираем каждый ID из списка
			for each (String ^ line in itemLines) {
				// Разбиваем строку на части
				array<String^>^ parts = line->Split(',');

				// Проверяем, совпадает ли ID
				if (parts->Length >= 3 &&
					Int32::Parse(parts[0]->Trim()) == selectedID)
				{
					elements[Int32::Parse(parts[1]->Trim())] = selectedID.ToString();
				}
			}
			lines[8] = String::Join(",", elements);	

			// Перезаписываем файл
			File::WriteAllLines("temp.txt", lines);
		}

		private: Void ReplaceItem(int selectedID, int index)
		{
			// Чтение всех строк файла с предметами
			array<String^>^ itemLines = File::ReadAllLines("Items.txt");
			array<String^>^ lines = File::ReadAllLines("temp.txt");

			// Разделяем строку на элементы
			array<String^>^ elements = lines[7]->Split(',');
			// Заменяем нужный элемент
			List<String^>^ newElements = gcnew List<String^>(elements);
			newElements->RemoveAt(index);

			elements = lines[8]->Split(',');
			// Перебираем каждый ID из списка
			for each (String ^ line in itemLines) {
				// Разбиваем строку на части
				array<String^>^ parts = line->Split(',');

				// Проверяем, совпадает ли ID
				if (parts->Length >= 3 &&
					Int32::Parse(parts[0]->Trim()) == selectedID)
				{
					Int32 temp = Int32::Parse(elements[Int32::Parse(parts[1]->Trim())]);
					elements[Int32::Parse(parts[1]->Trim())] = selectedID.ToString();
	
					// Добавляем название предмета в ListBox
					listBoxItems->Items->Add(gcnew ItemData(temp, LoadItemName(temp)));
					newElements->Add(temp.ToString());
				}
			}

			// Собираем строку обратно
			lines[7] = String::Join(",", newElements->ToArray());
			lines[8] = String::Join(",", elements);

			// Перезаписываем файл
			File::WriteAllLines("temp.txt", lines);
		}

		private: Void FromEquipToInv(int IndexOfItem)
		{
			// Чтение всех строк файла с предметами
			array<String^>^ lines = File::ReadAllLines("temp.txt");

			// Разделяем строку на элементы
			array<String^>^ elements = lines[8]->Split(',');
			Int32 temp = Int32::Parse(elements[IndexOfItem]->Trim());
			elements[IndexOfItem] = "None";
			lines[8] = String::Join(",", elements);

			listBoxItems->Items->Add(gcnew ItemData(temp, LoadItemName(temp)));
			elements = lines[7]->Split(',');
			List<String^>^ newElements = gcnew List<String^>(elements);
			newElements->Add(temp.ToString());

			// Собираем строку обратно
			lines[7] = String::Join(",", newElements->ToArray());

			// Перезаписываем файл
			File::WriteAllLines("temp.txt", lines);
		}

		private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
		}

		private: System::Void buttonWeapon_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonWeapon->Text = "None";
			FromEquipToInv(0);
		}

		private: System::Void buttonHelmet_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonHelmet->Text = "None";
			FromEquipToInv(1);
		}

		private: System::Void buttonCuirass_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonCuirass->Text = "None";
			FromEquipToInv(2);
		}

		private: System::Void buttonGloves_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonGloves->Text = "None";
			FromEquipToInv(3);
		}

		private: System::Void buttonGreaves_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonGreaves->Text = "None";
			FromEquipToInv(4);
		}

		private: System::Void buttonBoots_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonBoots->Text = "None";
			FromEquipToInv(5);
		}

		private: System::Void buttonNecklace_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonNecklace->Text = "None";
			FromEquipToInv(6);
		}

		private: System::Void buttonRing_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			buttonRing->Text = "None";
			FromEquipToInv(7);
		}

		private: System::Void listBoxItems_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			ItemData^ selectedItem = dynamic_cast<ItemData^>(listBoxItems->SelectedItem);

			if (selectedItem != nullptr)
			{
				// Чтение всех строк файла с предметами
				array<String^>^ itemLines = File::ReadAllLines("Items.txt");

				// Перебираем каждый ID из списка
				for each (String ^ line in itemLines) {
					// Разбиваем строку на части
					array<String^>^ parts = line->Split(',');

					// Проверяем, совпадает ли ID
					if (parts->Length >= 3 &&
						Int32::Parse(parts[0]->Trim()) == selectedItem->ID &&
						Int32::Parse(parts[3]->Trim()) == 0)
					{
						listBoxItems->ContextMenuStrip->Items[0]->Visible = false;
						break;
					}
					else
						listBoxItems->ContextMenuStrip->Items[0]->Visible = true;
				}
			}
		}
	};
}
