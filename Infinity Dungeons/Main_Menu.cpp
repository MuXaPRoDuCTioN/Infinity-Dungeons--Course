#include "Main_Menu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	InfinityDungeons::Main_Menu form;
	Application::Run(% form);
	return 0;
}