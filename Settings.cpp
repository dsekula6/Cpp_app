//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Settings.h"
#include "MainForm.h"
#include <Registry.hpp>
#include "Albumi.h"
#include "Register.h"
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma resource "*.dfm"
TFormSettings *FormSettings;
//---------------------------------------------------------------------------
__fastcall TFormSettings::TFormSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSettings::ButtonSaveClick(TObject *Sender)
{

	// bla bla
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteInteger("Settings Window", "Left", Left);
	ini->WriteInteger("Settings Window", "Width", Width);
	ini->WriteInteger("Settings Window", "Top", Top);
	ini->WriteInteger("Settings Window", "Height", Height);

	ini->WriteString("Application settings", "Font size", ComboBoxFontSize->Text);
	ini->WriteString("Application settings", "Theme", ComboBoxTheme->Text);


	if (ComboBoxFontSize->Text=="small" ||
	ComboBoxFontSize->Text=="malo") {
			FormHome->Font->Size = 7;
			FormHome->DBEdit1->Font->Size = 7;
			FormHome->DBEdit2->Font->Size = 7;
			FormHome->DBEdit3->Font->Size = 7;
			FormHome->DBEdit4->Font->Size = 7;
			FormHome->DBEdit5->Font->Size = 7;
			FormHome->ComboBoxSortBy->Font->Size = 7;
			FormHome->ComboBoxFilter->Font->Size = 7;
			FormHome->DBGrid1->Font->Size = 8;

	}
	else if (ComboBoxFontSize->Text=="large" ||
	ComboBoxFontSize->Text=="veliko") {
			FormHome->Font->Size = 13;
			FormHome->DBEdit1->Font->Size = 13;
			FormHome->DBEdit2->Font->Size = 13;
			FormHome->DBEdit3->Font->Size = 13;
			FormHome->DBEdit4->Font->Size = 13;
			FormHome->DBEdit5->Font->Size = 13;
			FormHome->ComboBoxSortBy->Font->Size = 13;
			FormHome->ComboBoxFilter->Font->Size = 13;
			FormHome->DBGrid1->Font->Size = 13;

	}
	else {
			FormHome->Font->Size = 9;
			FormHome->DBEdit1->Font->Size = 9;
			FormHome->DBEdit2->Font->Size = 9;
			FormHome->DBEdit3->Font->Size = 9;
			FormHome->DBEdit4->Font->Size = 9;
			FormHome->DBEdit5->Font->Size = 9;
			FormHome->ComboBoxSortBy->Font->Size = 9;
			FormHome->ComboBoxFilter->Font->Size = 9;
			FormHome->DBGrid1->Font->Size = 11;

	}


	if (ComboBoxTheme->Text=="dark" ||
	ComboBoxTheme->Text=="tamno") {
//			FormHome->Color = cl3DDkShadow;
//			FormHome->Font->Color = clBtnFace;
			TStyleManager::TrySetStyle("Charcoal Dark Slate");
	}
	else {
//			FormHome->Color = clBtnFace;
//			FormHome->Font->Color = cl3DDkShadow;
			TStyleManager::TrySetStyle("Aqua Light Slate");
	}

	if (EditUsername->Visible == true) {
		String sql1 = "UPDATE users SET username = \"";
		String sql2 = "\" WHERE id=\"";
		String sql3 = "\";";
		String encodedUsername;
		//TCodec* Codec1 = new TCodec(NULL);
		Codec1->Password = "qaywsxfghkiuztrfgnmj2345t";
		Codec1->EncryptString(EditUsername->Text, encodedUsername, TEncoding::UTF8);


		sql1 = sql1 + encodedUsername + sql2 + FormHome->LabelUserId->Caption +
					sql3;


		FormHome->SQLQuery1->SQL->Text = sql1;
		FormHome->SQLQuery1->ExecSQL();

	}

    if (EditImageDir->Visible == true) {
		ini->WriteString("Application settings", "ImageDir", EditImageDir->Text);

	}


	delete ini;

	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormSettings::FormCreate(TObject *Sender)
{
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	Left = ini->ReadInteger("Settings Window", "Left", 0);
	Width = ini->ReadInteger("Settings Window", "Width", 0);
	Top = ini->ReadInteger("Settings Window", "Top", 500);
	Height = ini->ReadInteger("Settings Window", "Height", 300);

    ComboBoxFontSize->Text = ini->ReadString("Application settings", "Font size", "medium");
	ComboBoxTheme->Text = ini->ReadString("Application settings", "Theme", "light");
    EditImageDir->Text = ini->ReadString("Application settings", "ImageDir", "default");

	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSettings::LabelUsernameDblClick(TObject *Sender)
{
	if (EditUsername->Visible == true) {
		EditUsername->Visible = false;
	}
	else {
		EditUsername->Visible = true;
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormSettings::LabelImageDirClick(TObject *Sender)
{
if (EditImageDir->Visible == true) {
		EditImageDir->Visible = false;
	}
	else {
		EditImageDir->Visible = true;
	}
}
//---------------------------------------------------------------------------





