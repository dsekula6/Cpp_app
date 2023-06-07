//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#pragma hdrstop

#include "Register.h"
#include "Albumi.h"
#include ".\\dllapp\\dynamic\\korisnik.h"
#include <IdHashMessageDigest.hpp>
//#include "MainForm.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma resource "*.dfm"
TFormRegister *FormRegister;
//---------------------------------------------------------------------------
__fastcall TFormRegister::TFormRegister(TComponent* Owner)
	: TForm(Owner)
{
}

//----------------------------------------------------------------------

void __fastcall TFormRegister::ButtonRegisterClick(TObject *Sender)
{
		//Codec1->CryptoLibrary = FormLogin->CryptographicLibrary1;
		//Codec1->BlockCipherId = "native.AES-256";
		//Codec1->ChainModeId = "native.CBC";
		Codec1->Password = "qaywsxfghkiuztrfgnmj2345t";
        HINSTANCE kori;
		typedef Korisnik* (*__stdcall pCreateDllClassInstance)();
		pCreateDllClassInstance CreateDllClassInstance;
			if ((kori = LoadLibrary(L".\\dllapp\\dynamic\\korisnik.dll")) == NULL) {
			ShowMessage("Cannot load DLL1");
			return;

		}
		if ((CreateDllClassInstance = (pCreateDllClassInstance)GetProcAddress(kori,
			"CreateDllClassInstance")) == NULL) {
			ShowMessage("Cannot load DLL2");
			return;
		}

		Korisnik* kor_reg = CreateDllClassInstance();
		String encodedUsername;
		Codec1->EncryptString(EditUsername->Text, encodedUsername, TEncoding::UTF8);
        kor_reg->SetUsername(encodedUsername);
		kor_reg->SetPassword(EditPassword->Text);



		String txt = "select * from users";
		String c_u, c_p;
		SQLQuery1->SQL->Text = txt;
		SQLQuery1->Active=true;



		if (!SQLQuery1->Eof) {

			SQLQuery1->First();
			ModalResult = mrOk;
			do {
				c_u=SQLQuery1->FieldValues["username"];
				c_p=SQLQuery1->FieldValues["pass"];


					if (kor_reg->CompareUsername(c_u)) {

							ModalResult = mrNo;
					}

				SQLQuery1->Next();
			} while (!SQLQuery1->Eof);

		}
		else {
			ShowMessage("error");
		}
		if (ModalResult == mrOk) {
			String sql1 = "insert into users(username, pass) values(\"";
			String sql2 = "\",\"";
			String sql3 = "\");";

			sql1 = sql1+kor_reg->GetUsername()+sql2+kor_reg->GetPassword()+sql3;
			SQLQuery1->SQL->Text = sql1;
			//ShowMessage(sql1);
			SQLQuery1->ExecSQL();
		}
		else {
			ShowMessage("Account already exists");
		}

		SQLQuery1->Active=false;
		//delete kor_reg;

Close();
}
//---------------------------------------------------------------------------

