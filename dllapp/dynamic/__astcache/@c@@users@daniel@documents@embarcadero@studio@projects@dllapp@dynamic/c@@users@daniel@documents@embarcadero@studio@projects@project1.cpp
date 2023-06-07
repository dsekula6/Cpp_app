//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include "Login.h"
#include "Register.h"
#include <memory>

//---------------------------------------------------------------------------
USEFORM("Register.cpp", FormRegister);
USEFORM("Settings.cpp", FormSettings);
USEFORM("Login.cpp", FormLogin);
USEFORM("MainForm.cpp", FormHome);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		// Application->CreateForm(__classid(TFLogin), &FLogin);
		std::unique_ptr<TFormLogin> FormLogin(new TFormLogin(NULL));

		if (FormLogin->ShowModal() == mrOk) {
			Application->CreateForm(__classid(TFormHome), &FormHome);
		Application->Run();

		}
		else
			ShowMessage("login data nevalja");

	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
