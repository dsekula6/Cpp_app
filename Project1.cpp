//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include "Login.h"
#include "Register.h"
#include "Search123.h"
#include <memory>

//---------------------------------------------------------------------------

#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Register.cpp", FormRegister);
USEFORM("Search123.cpp", FormSearch);
USEFORM("Settings.cpp", FormSettings);
USEFORM("MainForm.cpp", FormHome);
USEFORM("Login.cpp", FormLogin);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{

	HANDLE hMutex = CreateMutex(NULL, FALSE, L"MyAlbums");
	if (hMutex==NULL) {
		ShowMessage(GetLastError());
	}
	else if (GetLastError()==ERROR_ALREADY_EXISTS) {
            ShowMessage("An instance of the application is already opened");

			if (SetForegroundWindow(FindWindow(L"TFormRegister", NULL)) == NULL) {
			if (SetForegroundWindow(FindWindow(L"TFormLogin", NULL)) == NULL) {
			if (SetForegroundWindow(FindWindow(L"TFormHome", NULL)) == NULL) {
			if (SetForegroundWindow(FindWindow(L"TFormSearch", NULL)) == NULL) {
			SetForegroundWindow(FindWindow(L"TFormSettings", NULL));
			}}}}

			return -1;

	}
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		// Application->CreateForm(__classid(TFLogin), &FLogin);
		// std::unique_ptr<TFormLogin> FormLogin(new TFormLogin(NULL));


		//TStyleManager::TrySetStyle("Charcoal Dark Slate");
		//TStyleManager::TrySetStyle("Aqua Light Slate");
		Application->CreateForm(__classid(TFormHome), &FormHome);
		Application->CreateForm(__classid(TFormSearch), &FormSearch);
		Application->Run();



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
