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
	private:
		// Константы
		static String^ ITEMS_FILE = "Items.txt";
		static String^ TEMP_FILE = "temp.txt";
		int MAX_INVENTORY_SLOTS;

	public:
		Inventory(void)
		{
			ITEMS_FILE = GetFilePath("Items.txt");
			TEMP_FILE = GetFilePath("temp.txt");
			int MAX_INVENTORY_SLOTS;

			InitializeComponent();
			LoadPlayerImage();
			LoadPlayerStats();
			LoadPlayerInventory();
			LoadPlayerEquipment();
			SetupListBoxHandlers();
			SetupExitButton();
			InitializeContextMenu();
			CreateUnequipMethods();
			UpdateInventoryLabel(); // Устанавливаем initial label
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
			// 
			// buttonHelmet
			// 
			this->buttonHelmet->Location = System::Drawing::Point(269, 46);
			this->buttonHelmet->Name = L"buttonHelmet";
			this->buttonHelmet->Size = System::Drawing::Size(40, 40);
			this->buttonHelmet->TabIndex = 8;
			this->buttonHelmet->Text = L"buttonHelmet";
			this->buttonHelmet->UseVisualStyleBackColor = true;
			// 
			// buttonCuirass
			// 
			this->buttonCuirass->Location = System::Drawing::Point(269, 102);
			this->buttonCuirass->Name = L"buttonCuirass";
			this->buttonCuirass->Size = System::Drawing::Size(40, 40);
			this->buttonCuirass->TabIndex = 8;
			this->buttonCuirass->Text = L"buttonCuirass";
			this->buttonCuirass->UseVisualStyleBackColor = true;
			// 
			// buttonGreaves
			// 
			this->buttonGreaves->Location = System::Drawing::Point(269, 151);
			this->buttonGreaves->Name = L"buttonGreaves";
			this->buttonGreaves->Size = System::Drawing::Size(40, 40);
			this->buttonGreaves->TabIndex = 8;
			this->buttonGreaves->Text = L"buttonGreaves";
			this->buttonGreaves->UseVisualStyleBackColor = true;
			// 
			// buttonBoots
			// 
			this->buttonBoots->Location = System::Drawing::Point(269, 201);
			this->buttonBoots->Name = L"buttonBoots";
			this->buttonBoots->Size = System::Drawing::Size(40, 40);
			this->buttonBoots->TabIndex = 8;
			this->buttonBoots->Text = L"buttonBoots";
			this->buttonBoots->UseVisualStyleBackColor = true;
			// 
			// buttonGloves
			// 
			this->buttonGloves->Location = System::Drawing::Point(324, 124);
			this->buttonGloves->Name = L"buttonGloves";
			this->buttonGloves->Size = System::Drawing::Size(40, 40);
			this->buttonGloves->TabIndex = 8;
			this->buttonGloves->Text = L"buttonGloves";
			this->buttonGloves->UseVisualStyleBackColor = true;
			// 
			// buttonRing
			// 
			this->buttonRing->Location = System::Drawing::Point(211, 124);
			this->buttonRing->Name = L"buttonRing";
			this->buttonRing->Size = System::Drawing::Size(40, 40);
			this->buttonRing->TabIndex = 8;
			this->buttonRing->Text = L"buttonRing";
			this->buttonRing->UseVisualStyleBackColor = true;
			// 
			// buttonNecklace
			// 
			this->buttonNecklace->Location = System::Drawing::Point(211, 73);
			this->buttonNecklace->Name = L"buttonNecklace";
			this->buttonNecklace->Size = System::Drawing::Size(40, 40);
			this->buttonNecklace->TabIndex = 8;
			this->buttonNecklace->Text = L"buttonNecklace";
			this->buttonNecklace->UseVisualStyleBackColor = true;
			// 
			// buttonWeapon
			// 
			this->buttonWeapon->Location = System::Drawing::Point(324, 73);
			this->buttonWeapon->Name = L"buttonWeapon";
			this->buttonWeapon->Size = System::Drawing::Size(40, 40);
			this->buttonWeapon->TabIndex = 9;
			this->buttonWeapon->Text = L"buttonWeapon";
			this->buttonWeapon->UseVisualStyleBackColor = true;
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(698, 13);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(23, 23);
			this->buttonExit->TabIndex = 10;
			this->buttonExit->Text = L"X";
			this->buttonExit->UseVisualStyleBackColor = true;
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

		private:
			// Объявляем контекстное меню
			System::Windows::Forms::ContextMenuStrip^ itemContextMenu;		

		private: System::Void Inventory_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// Отправляем системное сообщение о начале перемещения окна
			ReleaseCapture();
			SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		}
			   String^ ReadSpecificLine(String^ filename, int lineNumber) {
				   try {
					   // Читаем все строки файла
					   array<String^>^ lines = File::ReadAllLines(filename);

					   // Проверяем, существует ли указанная строка
					   if (lineNumber > 0 && lineNumber <= lines->Length) {
						   // Возвращаем строку (с учетом, что нумерация начинается с 1)
						   return lines[lineNumber - 1]->Trim();
					   }
					   else {
						   // Возвращаем пустую строку, если строка не найдена
						   return String::Empty;
					   }
				   }
				   catch (Exception^ ex) {
					   // В случае ошибки выводим сообщение и возвращаем пустую строку
					   MessageBox::Show("Ошибка чтения файла: " + ex->Message);
					   return String::Empty;
				   }
			   }

			   void LoadPlayerImage() {
				   try {
					   String^ imagePath = ReadSpecificLine(TEMP_FILE, 7);
					   if (File::Exists(imagePath)) {
						   pictureBoxPlayer->Image = Image::FromFile(imagePath);
					   }
				   }
				   catch (Exception^ ex) {
					   MessageBox::Show("Ошибка загрузки изображения: " + ex->Message);
				   }
			   }

			   void LoadPlayerStats() {
				   try {
					   array<String^>^ statsLines = File::ReadAllLines(TEMP_FILE);

					   labelStrength->Text = statsLines[0];
					   labelIntelligence->Text = statsLines[1];
					   labelAgility->Text = statsLines[2];
					   labelHP->Text = statsLines[3];
					   labelMP->Text = statsLines[4];
					   labelInvent->Text = statsLines[5];

					   // Парсим максимальный размер инвентаря из 6 строки
					   if (Int32::TryParse(statsLines[5]->Trim(), MAX_INVENTORY_SLOTS)) {
						   // Обновляем label с учетом текущего количества предметов
						   UpdateInventoryLabel();
					   }
					   else {
						   // Значение по умолчанию, если парсинг не удался
						   MAX_INVENTORY_SLOTS = 20;
					   }
				   }
				   catch (Exception^ ex) {
					   MessageBox::Show("Ошибка загрузки статов: " + ex->Message);
				   }
			   }
		
			   void LoadPlayerInventory() {
				   try {
					   // Логика загрузки инвентаря
					   List<int>^ inventoryIDs = ParseInventoryIDs(TEMP_FILE);
					   PopulateInventoryListBox(inventoryIDs);
				   }
				   catch (Exception^ ex) {
					   MessageBox::Show("Ошибка загрузки инвентаря: " + ex->Message);
				   }
			   }

			   List<int>^ ParseInventoryIDs(String^ filename) {
				   List<int>^ ids = gcnew List<int>();
				   array<String^>^ lines = File::ReadAllLines(filename);

				   array<String^>^ idStrings = lines[7]->Split(',');
				   for each (String ^ idStr in idStrings) {
					   int id;
					   if (Int32::TryParse(idStr->Trim(), id)) {
						   ids->Add(id);
					   }
				   }
				   return ids;
			   }

			   void PopulateInventoryListBox(List<int>^ itemIDs) {
				   listBoxItems->Items->Clear();

				   array<String^>^ itemLines = File::ReadAllLines(ITEMS_FILE);

				   for each (int targetID in itemIDs) {
					   for each (String ^ line in itemLines) {
						   array<String^>^ parts = line->Split(',');

						   if (parts->Length >= 3 &&
							   Int32::Parse(parts[0]->Trim()) == targetID) {

							   listBoxItems->Items->Add(
								   gcnew ItemData(targetID, parts[2]->Trim())
							   );
							   break;
						   }
					   }
				   }
			   }

			   void LoadPlayerEquipment() {
				   try {
					   array<String^>^ lines = File::ReadAllLines(TEMP_FILE);
					   array<String^>^ equipmentIDs = lines[8]->Split(',');

					   UpdateEquipmentButtons(equipmentIDs);
				   }
				   catch (Exception^ ex) {
					   MessageBox::Show("Ошибка загрузки экипировки: " + ex->Message);
				   }
			   }

			   List<Button^>^ GetEquipmentButtons() {
				   List<Button^>^ buttons = gcnew List<Button^>();
				   buttons->Add(buttonWeapon);
				   buttons->Add(buttonHelmet);
				   buttons->Add(buttonCuirass);
				   buttons->Add(buttonGloves);
				   buttons->Add(buttonGreaves);
				   buttons->Add(buttonBoots);
				   buttons->Add(buttonNecklace);
				   buttons->Add(buttonRing);
				   return buttons;
			   }

			   void UpdateEquipmentButtons(array<String^>^ equipmentIDs) {
				   List<Button^>^ buttons = GetEquipmentButtons();

				   for (int i = 0; i < buttons->Count; i++) {
					   if (equipmentIDs[i] == "None")
						   buttons[i]->Text = "None";
					   else
						   buttons[i]->Text = GetItemNameById(Int32::Parse(equipmentIDs[i]));
				   }
			   }

			   String^ GetItemNameById(int itemID) {
				   array<String^>^ itemLines = File::ReadAllLines(ITEMS_FILE);

				   for each (String ^ line in itemLines) {
					   array<String^>^ parts = line->Split(',');

					   if (parts->Length >= 3 &&
						   Int32::Parse(parts[0]->Trim()) == itemID) {
						   return parts[2]->Trim();
					   }
				   }

				   return "Unnamed";
			   }
			   

			   void InitializeContextMenu() {
				   itemContextMenu = gcnew System::Windows::Forms::ContextMenuStrip();

				   // Создаем пункт "Экипировать" с именем
				   ToolStripMenuItem^ equipItem =
					   gcnew ToolStripMenuItem("Экипировать");
				   equipItem->Name = "EquipItem"; // Важно задать имя

				   equipItem->Click +=
					   gcnew EventHandler(this, &Inventory::OnEquipItem);

				   // Добавляем пункты меню
				   itemContextMenu->Items->Add(equipItem);
				   itemContextMenu->Items->Add(
					   "Редактировать",
					   nullptr,
					   gcnew EventHandler(this, &Inventory::OnEditItem)
				   );
				   itemContextMenu->Items->Add(
					   "Удалить",
					   nullptr,
					   gcnew EventHandler(this, &Inventory::OnDeleteItem)
				   );

				   // Назначаем контекстное меню ListBox
				   listBoxItems->ContextMenuStrip = itemContextMenu;

				   // Добавляем пункты только для экипируемых предметов
				   listBoxItems->MouseClick +=
					   gcnew MouseEventHandler(this, &Inventory::UpdateContextMenu);
			   }

			   void UpdateContextMenu(Object^ sender, MouseEventArgs^ e) {
				   // Очищаем существующее меню
				   itemContextMenu->Items->Clear();

				   ItemData^ selectedItem =
					   dynamic_cast<ItemData^>(listBoxItems->SelectedItem);

				   if (selectedItem != nullptr && CanEquipItem(selectedItem->ID)) {
					   // Добавляем пункты только для экипируемых предметов
					   ToolStripMenuItem^ equipItem =
						   gcnew ToolStripMenuItem("Экипировать");
					   equipItem->Click +=
						   gcnew EventHandler(this, &Inventory::OnEquipItem);

					   itemContextMenu->Items->Add(equipItem);
					   itemContextMenu->Items->Add(
						   "Редактировать",
						   nullptr,
						   gcnew EventHandler(this, &Inventory::OnEditItem)
					   );
					   itemContextMenu->Items->Add(
						   "Удалить",
						   nullptr,
						   gcnew EventHandler(this, &Inventory::OnDeleteItem)
					   );
				   }
				   else if (selectedItem != nullptr) {
					   // Для неэкипируемых - только редактирование и удаление
					   itemContextMenu->Items->Add(
						   "Редактировать",
						   nullptr,
						   gcnew EventHandler(this, &Inventory::OnEditItem)
					   );
					   itemContextMenu->Items->Add(
						   "Удалить",
						   nullptr,
						   gcnew EventHandler(this, &Inventory::OnDeleteItem)
					   );
				   }

				   // Назначаем контекстное меню
				   listBoxItems->ContextMenuStrip = itemContextMenu;
			   }

			   void ListBoxMouseClickHandler(Object^ sender, MouseEventArgs^ e) {
				   ItemData^ selectedItem =
					   dynamic_cast<ItemData^>(listBoxItems->SelectedItem);

				   if (selectedItem != nullptr) {
					   UpdateContextMenuVisibility(selectedItem->ID);
				   }
			   }

			   void OnEquipItem(Object^ sender, EventArgs^ e) {
				   ItemData^ selectedItem = GetSelectedInventoryItem();
				   if (selectedItem == nullptr) return;

				   if (CanEquipItem(selectedItem->ID)) {
					   EquipSelectedItem(selectedItem);
				   }
			   }

			   void UpdateContextMenuVisibility(int itemID) {
				   bool canEquip = CanEquipItem(itemID);

				   if (itemContextMenu->Items->Count > 0) {
					   // Находим пункт "Экипировать"
					   ToolStripMenuItem^ equipItem =
						   dynamic_cast<ToolStripMenuItem^>(
							   itemContextMenu->Items->Find("EquipItem", true)
							   );

					   if (equipItem != nullptr) {
						   equipItem->Visible = canEquip;
					   }
				   }
			   }

			   int GetItemSlotIndex(int itemID) {
				   array<String^>^ itemLines = File::ReadAllLines(ITEMS_FILE);

				   for each (String ^ line in itemLines) {
					   array<String^>^ parts = line->Split(',');

					   if (parts->Length >= 4 &&
						   Int32::Parse(parts[0]->Trim()) == itemID) {
						   return Int32::Parse(parts[1]->Trim()); // Возвращаем значение 2 столбца
					   }
				   }
				   return -1;
			   }

			   ItemData^ GetSelectedInventoryItem() {
				   return dynamic_cast<ItemData^>(listBoxItems->SelectedItem);
			   }

			   bool CanEquipItem(int itemID) {
				   array<String^>^ itemLines = File::ReadAllLines(ITEMS_FILE);

				   for each (String ^ line in itemLines) {
					   array<String^>^ parts = line->Split(',');

					   if (parts->Length >= 4 &&
						   Int32::Parse(parts[0]->Trim()) == itemID &&
						   Int32::Parse(parts[3]->Trim()) == 1) {  // Проверка на 1 во 4 столбце
						   return true;
					   }
				   }
				   return false;
			   }

			   void EquipSelectedItem(ItemData^ item) {
				   int slotIndex = GetItemSlotIndex(item->ID);
				   if (slotIndex == -1) return;

				   array<String^>^ lines = File::ReadAllLines(TEMP_FILE);
				   List<String^>^ inventoryItems =
					   gcnew List<String^>(lines[7]->Split(','));
				   List<String^>^ equipmentItems =
					   gcnew List<String^>(lines[8]->Split(','));

				   // Если слот занят, возвращаем текущий предмет в инвентарь
				   if (equipmentItems[slotIndex] != "None") {
					   int currentItemId = Int32::Parse(equipmentItems[slotIndex]);
					   inventoryItems->Add(currentItemId.ToString());
				   }

				   // Экипируем новый предмет
				   equipmentItems[slotIndex] = item->ID.ToString();

				   // Удаляем предмет из инвентаря
				   int inventoryIndex = inventoryItems->IndexOf(item->ID.ToString());
				   if (inventoryIndex != -1) {
					   inventoryItems->RemoveAt(inventoryIndex);
				   }

				   // Обновляем файл
				   lines[7] = String::Join(",", inventoryItems->ToArray());
				   lines[8] = String::Join(",", equipmentItems->ToArray());
				   File::WriteAllLines(TEMP_FILE, lines);

				   // Обновляем интерфейс
				   UpdateEquipmentButtons(equipmentItems->ToArray());
				   LoadPlayerInventory();
				   UpdateInventoryLabel(); // Обновляем label после экипирования
			   }

			   int FindItemTypeIndex(int itemID) {
				   array<String^>^ itemLines = File::ReadAllLines(ITEMS_FILE);

				   for each (String ^ line in itemLines) {
					   array<String^>^ parts = line->Split(',');

					   if (parts->Length >= 4 &&
						   Int32::Parse(parts[0]->Trim()) == itemID) {
						   return Int32::Parse(parts[1]->Trim());
					   }
				   }
				   return -1;
			   }

			   void OnEditItem(Object^ sender, EventArgs^ e) {
				   ItemData^ selectedItem = GetSelectedInventoryItem();
				   if (selectedItem != nullptr) {
					   MessageBox::Show("Редактирование: " + selectedItem->Name);
				   }
			   }

			   void OnDeleteItem(Object^ sender, EventArgs^ e) {
				   int selectedIndex = listBoxItems->SelectedIndex;
				   if (selectedIndex != -1) {
					   // Удаление из файла
					   RemoveItemFromFile(selectedIndex);

					   // Удаление из ListBox
					   listBoxItems->Items->RemoveAt(selectedIndex);

					   // Обновляем label после удаления
					   UpdateInventoryLabel();
				   }
			   }

			   void RemoveItemFromFile(int index) {
				   array<String^>^ lines = File::ReadAllLines(TEMP_FILE);
				   List<String^>^ inventoryItems =
					   gcnew List<String^>(lines[7]->Split(','));

				   if (index >= 0 && index < inventoryItems->Count) {
					   inventoryItems->RemoveAt(index);

					   lines[7] = String::Join(",", inventoryItems->ToArray());
					   File::WriteAllLines(TEMP_FILE, lines);
				   }
			   }

			   void UnequipItem(int equipmentIndex) {
				   array<String^>^ lines = File::ReadAllLines(TEMP_FILE);
				   List<String^>^ inventoryItems =
					   gcnew List<String^>(lines[7]->Split(','));
				   List<String^>^ equipmentItems =
					   gcnew List<String^>(lines[8]->Split(','));

				   // Проверяем место в инвентаре
				   if (inventoryItems->Count >= MAX_INVENTORY_SLOTS) {
					   MessageBox::Show("Инвентарь полон!");
					   return;
				   }

				   if (equipmentItems[equipmentIndex] != "None") {
					   int currentItemId = Int32::Parse(equipmentItems[equipmentIndex]);

					   // Возвращаем предмет в инвентарь
					   inventoryItems->Add(currentItemId.ToString());
					   equipmentItems[equipmentIndex] = "None";

					   // Обновляем файл
					   lines[7] = String::Join(",", inventoryItems->ToArray());
					   lines[8] = String::Join(",", equipmentItems->ToArray());
					   File::WriteAllLines(TEMP_FILE, lines);

					   // Обновляем интерфейс
					   UpdateEquipmentButtons(equipmentItems->ToArray());
					   LoadPlayerInventory();
					   UpdateInventoryLabel(); // Обновляем label после снятия
				   }
			   }

			   // Методы для кнопок снятия экипировки
			   void CreateUnequipMethods() {
				   buttonWeapon->Click += gcnew EventHandler(this, &Inventory::OnWeaponUnequip);
				   buttonHelmet->Click += gcnew EventHandler(this, &Inventory::OnHelmetUnequip);
				   buttonCuirass->Click += gcnew EventHandler(this, &Inventory::OnCuirassUnequip);
				   buttonGloves->Click += gcnew EventHandler(this, &Inventory::OnGlovesUnequip);
				   buttonGreaves->Click += gcnew EventHandler(this, &Inventory::OnGreavesUnequip);
				   buttonBoots->Click += gcnew EventHandler(this, &Inventory::OnBootsUnequip);
				   buttonNecklace->Click += gcnew EventHandler(this, &Inventory::OnNecklaceUnequip);
				   buttonRing->Click += gcnew EventHandler(this, &Inventory::OnRingUnequip);
			   }

			   void OnWeaponUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(0); // Индекс оружия
				   buttonWeapon->Text = "None";
			   }

			   void OnHelmetUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(1); // Индекс шлема
				   buttonHelmet->Text = "None";
			   }

			   void OnCuirassUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(1); // Индекс шлема
				   buttonHelmet->Text = "None";
			   }

			   void OnGlovesUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(1); // Индекс шлема
				   buttonHelmet->Text = "None";
			   }

			   void OnGreavesUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(1); // Индекс шлема
				   buttonHelmet->Text = "None";
			   }

			   void OnBootsUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(1); // Индекс шлема
				   buttonHelmet->Text = "None";
			   }

			   void OnNecklaceUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(1); // Индекс шлема
				   buttonHelmet->Text = "None";
			   }

			   void OnRingUnequip(Object^ sender, EventArgs^ e) {
				   UnequipItem(1); // Индекс шлема
				   buttonHelmet->Text = "None";
			   }

			   // Расширенная обработка клика по элементам ListBox
			   void SetupListBoxHandlers() {
				   listBoxItems->MouseClick +=
					   gcnew MouseEventHandler(this, &Inventory::ListBoxMouseClickHandler);
			   }

			   bool CheckItemEquipPossibility(int itemID) {
				   array<String^>^ itemLines = File::ReadAllLines(ITEMS_FILE);

				   for each (String ^ line in itemLines) {
					   array<String^>^ parts = line->Split(',');

					   if (parts->Length >= 4 &&
						   Int32::Parse(parts[0]->Trim()) == itemID) {

						   // Проверяем возможность экипировки
						   return Int32::Parse(parts[3]->Trim()) == 0;
					   }
				   }

				   return false;
			   }

			   // Безопасное закрытие формы
			   void SetupExitButton() {
				   buttonExit->Click +=
					   gcnew EventHandler(this, &Inventory::SafeFormClose);
			   }

			   void SafeFormClose(Object^ sender, EventArgs^ e) {
				   try {
					   // Можно добавить дополнительную логику перед закрытием
					   SaveInventoryState();
					   this->Close();
				   }
				   catch (Exception^ ex) {
					   MessageBox::Show("Ошибка при закрытии: " + ex->Message);
				   }
			   }

			   void SaveInventoryState() {
				   try {
					   array<String^>^ lines = File::ReadAllLines(TEMP_FILE);

					   // Обновляем инвентарь
					   List<String^>^ inventoryItems =
						   CollectCurrentInventoryItems();

					   // Обновляем экипировку
					   List<String^>^ equipmentItems =
						   CollectCurrentEquipmentItems();

					   // Перезаписываем соответствующие строки
					   lines[7] = String::Join(",", inventoryItems->ToArray());
					   lines[8] = String::Join(",", equipmentItems->ToArray());

					   File::WriteAllLines(TEMP_FILE, lines);
				   }
				   catch (Exception^ ex) {
					   MessageBox::Show("Ошибка сохранения состояния: " + ex->Message);
				   }
			   }

			   List<String^>^ CollectCurrentInventoryItems() {
				   List<String^>^ items = gcnew List<String^>();

				   for each (ItemData ^ item in listBoxItems->Items) {
					   items->Add(item->ID.ToString());
				   }

				   return items;
			   }

			   List<String^>^ CollectCurrentEquipmentItems() {
				   List<Button^>^ equipmentButtons = GetEquipmentButtons();

				   List<String^>^ equipmentItems = gcnew List<String^>();

				   for each (Button ^ button in equipmentButtons) {
					   if (button->Text == "None") {
						   equipmentItems->Add("None");
					   }
					   else {
						   int itemId = FindItemIdByName(button->Text);
						   equipmentItems->Add(itemId.ToString());
					   }
				   }

				   return equipmentItems;
			   }

			   int FindItemIdByName(String^ itemName) {
				   array<String^>^ itemLines = File::ReadAllLines(ITEMS_FILE);

				   for each (String ^ line in itemLines) {
					   array<String^>^ parts = line->Split(',');

					   if (parts->Length >= 3 &&
						   parts[2]->Trim() == itemName) {
						   return Int32::Parse(parts[0]->Trim());
					   }
				   }

				   return -1;
			   }

			   static String^ GetFilePath(String^ filename) {
				   String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
				   String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
				   return System::IO::Path::Combine(exeDirectory, filename);
			   }

			   void UpdateInventoryLabel() {
				   int currentItems = listBoxItems->Items->Count;
				   labelInvent->Text = String::Format("{0}/{1}",
					   currentItems,  // Занятое место
					   MAX_INVENTORY_SLOTS);  // Максимальное число предметов
			   }
	};
}
