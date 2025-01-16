#pragma once
#include <fstream>
#include <string>
#include "ItemData.h"
#include <vector>
#include <random>

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
	/// Сводка для ShopForm
	/// </summary>
	public ref class ShopForm : public System::Windows::Forms::Form
	{
	private:
		List<ItemData^>^ allItems;
		int maxInventorySize;
		int playerGold; // Для хранения золота
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Label^ labelInventorySpace;
	private: System::Windows::Forms::Label^ labelPlayerGold;


		   List<int>^ playerInventory;

	public:
		ShopForm(void)
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
		~ShopForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxBuyItems;
	private: System::Windows::Forms::ListBox^ listBoxSellItems;
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
			this->listBoxBuyItems = (gcnew System::Windows::Forms::ListBox());
			this->listBoxSellItems = (gcnew System::Windows::Forms::ListBox());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->labelInventorySpace = (gcnew System::Windows::Forms::Label());
			this->labelPlayerGold = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBoxBuyItems
			// 
			this->listBoxBuyItems->FormattingEnabled = true;
			this->listBoxBuyItems->Location = System::Drawing::Point(217, 47);
			this->listBoxBuyItems->Name = L"listBoxBuyItems";
			this->listBoxBuyItems->Size = System::Drawing::Size(125, 173);
			this->listBoxBuyItems->TabIndex = 0;
			// 
			// listBoxSellItems
			// 
			this->listBoxSellItems->FormattingEnabled = true;
			this->listBoxSellItems->Location = System::Drawing::Point(12, 47);
			this->listBoxSellItems->Name = L"listBoxSellItems";
			this->listBoxSellItems->Size = System::Drawing::Size(125, 173);
			this->listBoxSellItems->TabIndex = 1;
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(314, 12);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(28, 23);
			this->buttonExit->TabIndex = 2;
			this->buttonExit->Text = L"X";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &ShopForm::buttonExit_Click);
			// 
			// labelInventorySpace
			// 
			this->labelInventorySpace->AutoSize = true;
			this->labelInventorySpace->Location = System::Drawing::Point(12, 242);
			this->labelInventorySpace->Name = L"labelInventorySpace";
			this->labelInventorySpace->Size = System::Drawing::Size(35, 13);
			this->labelInventorySpace->TabIndex = 3;
			this->labelInventorySpace->Text = L"label1";
			// 
			// labelPlayerGold
			// 
			this->labelPlayerGold->AutoSize = true;
			this->labelPlayerGold->Location = System::Drawing::Point(12, 267);
			this->labelPlayerGold->Name = L"labelPlayerGold";
			this->labelPlayerGold->Size = System::Drawing::Size(35, 13);
			this->labelPlayerGold->TabIndex = 4;
			this->labelPlayerGold->Text = L"label1";
			// 
			// ShopForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(354, 298);
			this->Controls->Add(this->labelPlayerGold);
			this->Controls->Add(this->labelInventorySpace);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->listBoxSellItems);
			this->Controls->Add(this->listBoxBuyItems);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ShopForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ShopForm";
			this->Load += gcnew System::EventHandler(this, &ShopForm::ShopForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ShopForm::ShopForm_MouseDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Импортируем Windows API функций
		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static bool ReleaseCapture();

		[System::Runtime::InteropServices::DllImport("user32.dll")]
		static IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);

		Void ShopForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			// Отправляем системное сообщение о начале перемещения окна
			ReleaseCapture();
			SendMessage(this->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		}

		void LoadItemsFromFile() {
			allItems = gcnew System::Collections::Generic::List<ItemData^>();

			try {
				array<String^>^ lines = System::IO::File::ReadAllLines(GetFilePath("Items.txt"), System::Text::Encoding::Default);

				for each (String ^ line in lines) {
					array<String^>^ parts = line->Split(',');

					if (parts->Length >= 5) {
						ItemData^ item = gcnew ItemData();
						item->ID = Convert::ToInt32(parts[0]);
						item->EquipmentType = Convert::ToInt32(parts[1]);
						item->Name = parts[2]->Trim();
						item->CanEquip = (Convert::ToInt32(parts[3]) == 1);
						item->Price = Convert::ToInt32(parts[4]);

						allItems->Add(item);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка при загрузке файла: " + ex->Message);
			}
		}

		String^ GetFilePath(String^ filename) {
			String^ exePath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
			String^ exeDirectory = System::IO::Path::GetDirectoryName(exePath);
			return System::IO::Path::Combine(exeDirectory, filename);
		}

		void LoadPlayerInventory() {
			playerInventory = gcnew System::Collections::Generic::List<int>();

			try {
				array<String^>^ lines = System::IO::File::ReadAllLines(GetFilePath("temp.txt"));

				// Максимальный размер инвентаря из 6-й строки
				if (lines->Length >= 6) {
					maxInventorySize = Convert::ToInt32(lines[5]->Trim());
				}

				// ID предметов из 7-й строки
				if (lines->Length >= 7) {
					array<String^>^ itemIds = lines[7]->Split(',');

					for each (String ^ idStr in itemIds) {
						playerInventory->Add(Convert::ToInt32(idStr->Trim()));
					}
				}

				// Золото из 10-й строки
				if (lines->Length >= 9) {
					playerGold = Convert::ToInt32(lines[9]->Trim());
				}

				UpdateInventorySpaceLabel();
				UpdatePlayerGoldLabel();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка при загрузке инвентаря: " + ex->Message);
			}
		}

		// Метод обновления label остается прежним
		void UpdateInventorySpaceLabel() {
			if (labelInventorySpace != nullptr) {
				int freeSpace = maxInventorySize - playerInventory->Count;
				labelInventorySpace->Text = String::Format("Свободно мест: {0}/{1}",
					freeSpace, maxInventorySize);
			}
		}

		// Обновление label с золотом
		void UpdatePlayerGoldLabel() {
			if (labelPlayerGold != nullptr) {
				labelPlayerGold->Text = "Золото: " + playerGold;
			}
		}

		void GenerateBuyItems() {
			if (allItems == nullptr || allItems->Count == 0) {
				return;
			}

			Random^ random = gcnew Random();
			listBoxBuyItems->BeginUpdate(); // Начинаем обновление
			listBoxBuyItems->Items->Clear();

			for (int i = 0; i < 10; i++) {
				int index = random->Next(allItems->Count);
				ItemData^ item = allItems[index];

				listBoxBuyItems->Items->Add(item->Name);
			}

			listBoxBuyItems->EndUpdate(); // Завершаем обновление
			listBoxBuyItems->Refresh(); // Принудительная перерисовка
		}

		ItemData^ FindItemByName(String^ name) {
			for each (ItemData ^ item in allItems) {
				if (item->Name == name) {
					return item;
				}
			}
			return nullptr;
		}

		ItemData^ FindItemById(int id) {
			for each (ItemData ^ item in allItems) {
				if (item->ID == id) {
					return item;
				}
			}
			return nullptr;
		}

		void LoadPlayerItemsToListBox() {
			listBoxSellItems->Items->Clear();

			for each (int itemId in playerInventory) {
				ItemData^ item = FindItemById(itemId);

				if (item != nullptr) {
					listBoxSellItems->Items->Add(item->Name);
				}
			}
		}

		// Объявляем контекстное меню
		System::Windows::Forms::ContextMenuStrip^ buyContextMenu;
		System::Windows::Forms::ContextMenuStrip^ sellContextMenu;

		void CreateBuyContextMenu() {
			// Контекстное меню для покупки
			buyContextMenu = gcnew System::Windows::Forms::ContextMenuStrip();

			ToolStripMenuItem^ buyItem = gcnew ToolStripMenuItem("Купить");
			buyItem->Click += gcnew EventHandler(this, &ShopForm::BuyItem_Click);

			ToolStripMenuItem^ buyPriceItem = gcnew ToolStripMenuItem("Цена");
			buyPriceItem->Click += gcnew EventHandler(this, &ShopForm::ShowBuyItemPrice_Click);

			buyContextMenu->Items->Add(buyItem);
			buyContextMenu->Items->Add(buyPriceItem);
			listBoxBuyItems->ContextMenuStrip = buyContextMenu;

			// Контекстное меню для продажи (аналогично)
			
		}

		void CreateSellContextMenu() {
			sellContextMenu = gcnew System::Windows::Forms::ContextMenuStrip();

			ToolStripMenuItem^ sellItem = gcnew ToolStripMenuItem("Продать");
			sellItem->Click += gcnew EventHandler(this, &ShopForm::SellItem_Click);

			ToolStripMenuItem^ sellPriceItem = gcnew ToolStripMenuItem("Цена");
			sellPriceItem->Click += gcnew EventHandler(this, &ShopForm::ShowSellItemPrice_Click);

			sellContextMenu->Items->Add(sellItem);
			sellContextMenu->Items->Add(sellPriceItem);
			listBoxSellItems->ContextMenuStrip = sellContextMenu;
		}

		// Метод покупки с учетом цены
		void BuyItem_Click(Object^ sender, EventArgs^ e) {
			if (listBoxBuyItems->SelectedIndex != -1) {
				// Проверка вместимости инвентаря
				if (playerInventory->Count >= maxInventorySize) {
					MessageBox::Show("Инвентарь полон! Невозможно купить предмет.");
					return;
				}

				String^ selectedItemName = listBoxBuyItems->SelectedItem->ToString();
				ItemData^ item = FindItemByName(selectedItemName);

				if (item != nullptr) {
					// Проверка хватает ли золота
					if (playerGold < item->Price) {
						MessageBox::Show("Недостаточно золота для покупки!");
						return;
					}

					// Списываем золото
					playerGold -= item->Price;

					listBoxSellItems->Items->Add(item->Name);
					listBoxBuyItems->Items->RemoveAt(listBoxBuyItems->SelectedIndex);
					playerInventory->Add(item->ID);

					UpdateInventorySpaceLabel();
					UpdatePlayerGoldLabel();
				}
			}
		}

		void ShowBuyItemPrice_Click(Object^ sender, EventArgs^ e) {
			if (listBoxBuyItems->SelectedIndex != -1) {
				String^ selectedItemName = listBoxBuyItems->SelectedItem->ToString();
				ItemData^ item = FindItemByName(selectedItemName);

				if (item != nullptr) {
					MessageBox::Show("Цена: " + item->Price + " монет");
				}
			}
		}

		// Метод продажи с учетом цены
		void SellItem_Click(Object^ sender, EventArgs^ e) {
			if (listBoxSellItems->SelectedIndex != -1) {
				String^ selectedItemName = listBoxSellItems->SelectedItem->ToString();
				ItemData^ item = FindItemByName(selectedItemName);

				if (item != nullptr) {
					// Начисляем золото при продаже (можно сделать с коэффициентом)
					playerGold += item->Price / 2; // Продаем за половину стоимости

					listBoxBuyItems->Items->Add(item->Name);
					listBoxSellItems->Items->RemoveAt(listBoxSellItems->SelectedIndex);

					playerInventory->Remove(item->ID);

					UpdateInventorySpaceLabel();
					UpdatePlayerGoldLabel();
				}
			}
		}

		void ShowSellItemPrice_Click(Object^ sender, EventArgs^ e) {
			if (listBoxSellItems->SelectedIndex != -1) {
				String^ selectedItemName = listBoxSellItems->SelectedItem->ToString();
				ItemData^ item = FindItemByName(selectedItemName);

				if (item != nullptr) {
					MessageBox::Show("Цена продажи: " + item->Price + " монет");
				}
			}
		}

		Void ShopForm_Load(System::Object^ sender, System::EventArgs^ e) {
			// Находим label по имени (убедитесь, что имя совпадает)
			labelInventorySpace = dynamic_cast<Label^>(this->Controls->Find("labelInventorySpace", true)[0]);
			// Находим label для золота
			labelPlayerGold = dynamic_cast<Label^>(this->Controls->Find("labelPlayerGold", true)[0]);

			LoadItemsFromFile();
			LoadPlayerInventory();

			// Генерация после инициализации компонентов
			if (listBoxBuyItems != nullptr) {
				GenerateBuyItems();
			}

			LoadPlayerItemsToListBox();
			CreateBuyContextMenu();
			CreateSellContextMenu();
		}

	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Читаем существующие строки
			array<String^>^ existingLines = System::IO::File::ReadAllLines(GetFilePath("temp.txt"), System::Text::Encoding::Default);

			// Создаем новый массив строк
			array<String^>^ updatedLines = gcnew array<String^>(existingLines->Length);

			// Копируем первые 6 строк без изменений
			for (int i = 0; i < 7; i++) {
				updatedLines[i] = existingLines[i];
			}

			// 8-я строка - ID предметов инвентаря
			array<String^>^ itemIdStrings = gcnew array<String^>(playerInventory->Count);
			for (int i = 0; i < playerInventory->Count; i++) {
				itemIdStrings[i] = ConvertIntToString(playerInventory[i]);
			}
			updatedLines[7] = String::Join(",", itemIdStrings);

			// Заполняем оставшиеся строки из оригинального файла
			for (int i = 8; i < 9; i++) {
				updatedLines[i] = existingLines[i];
			}

			// 10-я строка - обновленное количество золота
			updatedLines[9] = playerGold.ToString();

			// Оставшиеся строки (если есть)
			for (int i = 10; i < existingLines->Length; i++) {
				updatedLines[i] = existingLines[i];
			}

			// Сохраняем обновленные данные
			System::IO::File::WriteAllLines(GetFilePath("temp.txt"), updatedLines, System::Text::Encoding::Default);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при сохранении данных: " + ex->Message);
		}

		this->Close();
	}

		   // Метод для преобразования ID в строку
		   String^ ConvertIntToString(int id) {
			   return id.ToString();
		   }
};
}
