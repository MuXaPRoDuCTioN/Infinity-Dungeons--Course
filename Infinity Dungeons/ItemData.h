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
	// ������� ����� ��� �������� ��������� � ID � ���������
	ref class ItemData {
	public:
		int ID;
		String^ Name;
		int Price;
		int EquipmentType; // ��� ����������
		bool CanEquip;     // ����� �� �����������

		// �����������
		ItemData(int id, String^ name) {
			ID = id;
			Name = name;
		}

		// ����������� �� ���������
		ItemData() : ID(0), Name(""), Price(0) {}

		// ����������� � �����������
		ItemData(int id, String^ name, int price)
			: ID(id), Name(name), Price(price) {}

		ItemData(int id, String^ name, int price, int equipType, bool canEquip) :
			ID(id),
			Name(name),
			Price(price),
			EquipmentType(equipType),
			CanEquip(canEquip) {}

		// �������������� ����� ToString() ��� ����������� ������ ��������
		virtual String^ ToString() override {
			return Name;
		}		
		
		// ����� ��� ��������� ������ ���������� � ��������
		String^ GetFullInfo() {
			return String::Format(
				"ID: {0}, Name: {1}, Price: {2}, Type: {3}, Equipable: {4}",
				ID, Name, Price, EquipmentType, CanEquip
			);
		}
	};
}