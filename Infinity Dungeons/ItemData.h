#pragma once

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
	// Создаем класс для хранения элементов с ID и названием
	ref class ItemData {
	public:
		int ID;
		String^ Name;
		int Price;
		int EquipmentType; // Тип экипировки
		bool CanEquip;     // Можно ли экипировать

		// Конструктор
		ItemData(int id, String^ name) {
			ID = id;
			Name = name;
		}

		// Конструктор по умолчанию
		ItemData() : ID(0), Name(""), Price(0) {}

		// Конструктор с параметрами
		ItemData(int id, String^ name, int price)
			: ID(id), Name(name), Price(price) {}

		ItemData(int id, String^ name, int price, int equipType, bool canEquip) :
			ID(id),
			Name(name),
			Price(price),
			EquipmentType(equipType),
			CanEquip(canEquip) {}

		// Переопределяем метод ToString() для отображения только названия
		virtual String^ ToString() override {
			return Name;
		}		
		
		// Метод для получения полной информации о предмете
		String^ GetFullInfo() {
			return String::Format(
				"ID: {0}, Name: {1}, Price: {2}, Type: {3}, Equipable: {4}",
				ID, Name, Price, EquipmentType, CanEquip
			);
		}
	};
}