//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "Register.h"
#include "MainForm.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "dllapp\\dynamic\\classKorisnik.cpp"
#include <IdHashMessageDigest.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLogin *FormLogin;
//---------------------------------------------------------------------------




__fastcall TFormLogin::TFormLogin(TComponent* Owner)
: TForm(Owner)
{
}



//---------------------------------------------------------------------------
void __fastcall TFormLogin::ButtonLoginClick(TObject *Sender)
{

		//pointer function
		HINSTANCE kori;
		typedef Korisnik* (*__stdcall pCreateDllClassInstance)();
		pCreateDllClassInstance CreateDllClassInstance;

		if ((kori = LoadLibrary(L"dllapp\\dynamic\\korisnik.dll")) == NULL) {
			ShowMessage("Cannot load DLL");
			return;

		}
		if ((CreateDllClassInstance = (pCreateDllClassInstance)GetProcAddress(kori, "CreateDllClassInstance")) == NULL) {
			ShowMessage("Cannot load DLL");
			return;
		}


		String txt = "select * from users";
		String c_u, c_p;
		SQLQuery1->SQL->Text = txt;
		SQLQuery1->Active=true;
		Korisnik* kor = CreateDllClassInstance();
		
		if (!SQLQuery1->Eof) {
			kor->SetUsername(EditUsername->Text);
			kor->SetPassword(EditPassword->Text);
			SQLQuery1->First();
			do {
				c_u=SQLQuery1->FieldValues["username"];
				c_p=SQLQuery1->FieldValues["pass"];


					if (kor->CompareUsername(c_u)) {

							if (kor->ComparePassword(c_p)) {

								ModalResult = mrOk;

							}
					}

				SQLQuery1->Next();
			} while (!SQLQuery1->Eof);

		}
		else {
			ShowMessage("error");
		}
		if (ModalResult != mrOk) {
			ShowMessage("wrong credentials");
		}


		SQLQuery1->Active=false;
        kor->Destroy();

}
//---------------------------------------------------------------------------


void __fastcall TFormLogin::ButtonRegisterClick(TObject *Sender)
{

	std::unique_ptr<TFormRegister> FormRegister(new TFormRegister(NULL));
    SqlfreehostingConnection->Close();
    FormRegister->ShowModal();


}
//---------------------------------------------------------------------------

void __fastcall TFormLogin::FormCreate(TObject *Sender)
{
	HINSTANCE resourceDll;
	if ((resourceDll = LoadLibrary(L"dllapp\\dynamic\\korisnik.dll")) == NULL) {
		ShowMessage("Cannot load korisnik.dll");
		return;
	}
	Image1->Picture->Bitmap->LoadFromResourceName((int)resourceDll, "USER_BMP");
    FreeLibrary(resourceDll);

}
//---------------------------------------------------------------------------

