#include "Main_Menu.h"
#include "Hub_location.h"
#include "New_Game.h"

using namespace System;
using namespace System::Windows::Forms;

namespace InfinityDungeons {
	System::Void Main_Menu::To_New_Game_Click(System::Object^ sender, System::EventArgs^ e) {
		New_Game^ formNewGame = gcnew New_Game;
		formNewGame->ShowDialog();
		if (formNewGame->DialogResult == System::Windows::Forms::DialogResult::OK)
		{
			Hub_location^ formStartNewGame = gcnew Hub_location(this);
			formStartNewGame->Owner = this;
			To_New_Game->Enabled = false;
			To_Save_Game->Enabled = true;
			formStartNewGame->Show();
		}
	}
}

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	InfinityDungeons::Main_Menu form;
	//Старт программы
	Application::Run(% form);
	return 0;
}