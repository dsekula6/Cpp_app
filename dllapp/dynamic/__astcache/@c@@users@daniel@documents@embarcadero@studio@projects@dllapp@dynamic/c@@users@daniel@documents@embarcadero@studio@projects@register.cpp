﻿//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#pragma hdrstop

#include "Register.h"
#include "Login.cpp"
#include <IdHashMessageDigest.hpp>
#include "MainForm.cpp"
#include "dllapp\\dynamic\\classKorisnik.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
		Korisnik* kor_reg = CreateDllClassInstance();
		kor_reg->SetUsername(EditUsername->Text);
		kor_reg->SetPassword(EditPassword->Text);

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
		delete kor_reg;

Close();
}
//---------------------------------------------------------------------------

