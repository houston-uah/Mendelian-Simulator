//====================================================================
// MendelianSimForm.cpp
// Author: Houston Calvert
//====================================================================

#include "MendelianSimForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
	AllocConsole();
	std::cout << "All of the input is done through GUI. This is another output window" << std::endl;

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MendelianSimGUI::MendelianSimForm form;
	Application::Run(%form);
}