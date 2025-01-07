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

		// Конструктор
		ItemData(int id, String^ name) {
			ID = id;
			Name = name;
		}

		// Переопределяем метод ToString() для отображения только названия
		virtual String^ ToString() override {
			return Name;
		}
	};
}