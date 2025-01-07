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

		// �����������
		ItemData(int id, String^ name) {
			ID = id;
			Name = name;
		}

		// �������������� ����� ToString() ��� ����������� ������ ��������
		virtual String^ ToString() override {
			return Name;
		}
	};
}