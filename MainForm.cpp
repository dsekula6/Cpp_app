//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "Settings.h"
#include "Login.h"
#include "Search123.h"
#include <Registry.hpp>
#include <System.JSON.hpp>
#include <jpeg.hpp>
#include "JsonThread.h"
#include "AddImageThread.h"
#include "Albumi.h"
#include "reinit.hpp"
#include <memory>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHome *FormHome;
//---------------------------------------------------------------------------
__fastcall TFormHome::TFormHome(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormHome::ButtonSettingsClick(TObject *Sender)
{
	std::unique_ptr<TFormSettings> FormSettings(new TFormSettings(NULL));
	FormSettings->EditUsername->Text = LabelUsername->Caption;
	FormSettings->ShowModal();


}
//---------------------------------------------------------------------------

void __fastcall TFormHome::FormClose(TObject *Sender, TCloseAction &Action)
{

	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteInteger("Main Window", "Left", Left);
	ini->WriteInteger("Main Window", "Width", Width);
	ini->WriteInteger("Main Window", "Top", Top);
	ini->WriteInteger("Main Window", "Height", Height);
	delete ini;
	SqlfreehostingConnection->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::FormCreate(TObject *Sender)
{
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	Left = ini->ReadInteger("Main Window", "Left", 0);
	Width = ini->ReadInteger("Main Window", "Width", 0);
	Top = ini->ReadInteger("Main Window", "Top", 1150);
	Height = ini->ReadInteger("Main Window", "Height", 700);

	if (
	ini->ReadString("Application settings", "Font size", "medium")=="small" ||
	ini->ReadString("Application settings", "Font size", "medium")=="malo") {
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
	else if (
	ini->ReadString("Application settings", "Font size", "medium")=="large" ||
	ini->ReadString("Application settings", "Font size", "medium")=="veliko") {
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


	if (
	ini->ReadString("Application settings", "Theme", "light")=="dark" ||
	ini->ReadString("Application settings", "Theme", "light")=="tamno") {
//			FormHome->Color = cl3DDkShadow;
//			FormHome->Font->Color = clBtnFace;
			TStyleManager::TrySetStyle("Charcoal Dark Slate");
	}
	else {
//			FormHome->Color = clBtnFace;
//			FormHome->Font->Color = cl3DDkShadow;
			TStyleManager::TrySetStyle("Aqua Light Slate");
	}

    // login

    std::unique_ptr<TFormLogin> FormLogin(new TFormLogin(NULL));
	// FormLogin->ShowModal();
	if (FormLogin->ShowModal() != mrOk) {
		ShowMessage("login failed");
        Application->Terminate();
	}
    LabelUsername->Caption = FormLogin->EditUsername->Text;
	LabelUserId->Caption = FormLogin->LabelUserId->Caption;

	SQLQuery1->SQL->Text = "SELECT COUNT(idalbums) FROM albums INNER JOIN ocjene ON albums.idalbums = ocjene.idAlbum INNER JOIN users ON ocjene.idUser = users.id WHERE users.id = \""+LabelUserId->Caption+"\";";

	SQLQuery1->Active = true;
    LabelAlbumCount->Caption = SQLQuery1->FieldValues["COUNT(idalbums)"];


	TestQuery1->SQL->Text = "SELECT albums.*, ocjene.bodovi FROM albums INNER JOIN ocjene ON albums.idalbums = ocjene.idAlbum INNER JOIN users ON ocjene.idUser = users.id WHERE users.id = \""+LabelUserId->Caption+"\";";

	TestQuery1->Active = true;

    // resource dll
    HINSTANCE resourceDll;
	if ((resourceDll = LoadLibrary(L"dllapp\\dynamic\\korisnik.dll")) == NULL) {
		ShowMessage("Cannot load korisnik.dll");
		return;
	}
	Image2->Picture->Bitmap->LoadFromResourceName((int)resourceDll, "USER_BMP");
	FreeLibrary(resourceDll);

	FDTable2->Active = true;



	delete ini;
}
//---------------------------------------------------------------------------









void __fastcall TFormHome::ButtonSearchClick(TObject *Sender)
{
    TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	if (ini->ReadString("Application settings", "Font size", "medium")=="small") {
			FormSearch->Font->Size = 7;
			FormSearch->ButtonAddNew->Font->Size = 7;
	}
	else if (ini->ReadString("Application settings", "Font size", "medium")=="large") {
			FormSearch->Font->Size = 13;
			FormSearch->ButtonAddNew->Font->Size = 13;
	}
	else {
			FormSearch->Font->Size = 9;
			FormSearch->ButtonAddNew->Font->Size = 9;
	}
	if (ini->ReadString("Application settings", "Theme", "light")=="dark") {
			FormSearch->Color = cl3DDkShadow;
			FormSearch->Font->Color = clBtnFace;
	}
	else {
			FormSearch->Color = clBtnFace;
			FormSearch->Font->Color = cl3DDkShadow;

	}
	TListColumn *ListCol;
	FormSearch->ListView1->ViewStyle = vsReport;

    ListCol = FormSearch->ListView1->Columns->Add();
	ListCol->Caption = "id";
	ListCol->Width = 80;

	ListCol = FormSearch->ListView1->Columns->Add();
	ListCol->Caption = "Album name";
	ListCol->Width = 150;
	ListCol->Alignment = taRightJustify;

	ListCol = FormSearch->ListView1->Columns->Add();
	ListCol->Caption = "Artist";
	ListCol->Width = 100;
	ListCol->Alignment = taRightJustify;


	ListCol = FormSearch->ListView1->Columns->Add();
	ListCol->Caption = "url";
	ListCol->Width = 100;



	//std::unique_ptr<TFormSearch> FormSearch(new TFormSearch(NULL));
	FormSearch->LabelUsername->Caption = LabelUsername->Caption;
	FormSearch->LabelUserId->Caption = LabelUserId->Caption;
	if (FormSearch->ShowModal() == mrOk) {
        //AddImageThread* imageThread = new AddImageThread(false);

		String ImageDir = ini->ReadString("Application settings", "ImageDir", "default");
		if (ImageDir == "default") {
			ImageDir = "./thumbs/";
		}
		String id = FormSearch->ListView1->Selected->Caption;
		ImageDir = ImageDir + id + ".jpg";
		TestQuery1->Edit();
		static_cast<TBlobField*>(TestQuery1->FieldByName("albumCover"))->LoadFromFile(ImageDir);
		TestQuery1->Post();



	}
	delete ini;

}
//---------------------------------------------------------------------------




void __fastcall TFormHome::ButtonExportXMLClick(TObject *Sender)
{
	String txt = "select * from albums";
	SQLQuery1->SQL->Text = txt;
	SQLQuery1->Active=true;
	std::unique_ptr<TStringStream> ss(new TStringStream);

	if (!SQLQuery1->Eof) {


		ss->WriteString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
		ss->WriteString("<data>\n");


			SQLQuery1->First();
			do {
				ss->WriteString("<row>\n");
				String id=SQLQuery1->FieldValues["idalbums"];
				String name=SQLQuery1->FieldValues["name"];
				String artist=SQLQuery1->FieldValues["artist"];
				String coverUrl=SQLQuery1->FieldValues["coverUrl"];
				String tracklist = "(NULL)";
				if (!SQLQuery1->FieldValues["tracklistCount"].IsNull()) {
					tracklist = SQLQuery1->FieldValues["tracklistCount"];
				}


				ss->WriteString("<idalbums>\"");
				ss->WriteString(id);
				ss->WriteString("\"</idalbums>\n");

				ss->WriteString("<name>");
				ss->WriteString(name);
				ss->WriteString("</name>\n");

				ss->WriteString("<artist>");
				ss->WriteString(artist);
				ss->WriteString("</artist>\n");

				ss->WriteString("<coverUrl>");
				ss->WriteString(coverUrl);
				ss->WriteString("</coverUrl>\n");

				ss->WriteString("<albumCover>");
				ss->WriteString("(NULL)");
				ss->WriteString("</albumCover>\n");

				ss->WriteString("<tracklistCount>");
				ss->WriteString(tracklist);
				ss->WriteString("</tracklistCount>\n");

				ss->WriteString("</row>\n");


				SQLQuery1->Next();
			} while (!SQLQuery1->Eof);

			ss->WriteString("</data>");
		}
	else {
		ShowMessage("error");
	}

	// String xmlstring = FDTable1->Fields->;

	ss->SaveToFile("export/albums.xml");


}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonExportJSONClick(TObject *Sender)
{
	String txt = "select * from albums";
	SQLQuery1->SQL->Text = txt;
	SQLQuery1->Active=true;
	std::unique_ptr<TStringStream> ss(new TStringStream);

	if (!SQLQuery1->Eof) {

		ss->WriteString("{\n");
		ss->WriteString("\"data\":{\n");
		ss->WriteString("\"row\":[");
		ss->WriteString("{\n");
			SQLQuery1->First();
			do {

				String id=SQLQuery1->FieldValues["idalbums"];
				String name=SQLQuery1->FieldValues["name"];
				String artist=SQLQuery1->FieldValues["artist"];
				String coverUrl=SQLQuery1->FieldValues["coverUrl"];
				String tracklist = "(NULL)";
				if (!SQLQuery1->FieldValues["tracklistCount"].IsNull()) {
					tracklist = SQLQuery1->FieldValues["tracklistCount"];
				}

				ss->WriteString("\"idalbums\": \"");
				ss->WriteString(id);
				ss->WriteString("\",\n");

				ss->WriteString("\"name\": \"");
				ss->WriteString(name);
				ss->WriteString("\",\n");

				ss->WriteString("\"artist\": \"");
				ss->WriteString(artist);
				ss->WriteString("\",\n");

				ss->WriteString("\"coverUrl\": \"");
				ss->WriteString(coverUrl);
				ss->WriteString("\",\n");

				ss->WriteString("\"albumCover\": \"");
				ss->WriteString("(NULL)");
				ss->WriteString("\",\n");

				ss->WriteString("\"tracklistCount\": \"");
				ss->WriteString("(NULL)");
				ss->WriteString("\"\n");

				ss->WriteString("},\n{\n");


				SQLQuery1->Next();
			} while (!SQLQuery1->Eof);
			ss->WriteString("}\n");

			ss->WriteString("]\n}\n}");
		}
	else {
		ShowMessage("error");
	}
	
	// String xmlstring = FDTable1->Fields->;

	ss->SaveToFile("export/albums.json");
}
//---------------------------------------------------------------------------



void __fastcall TFormHome::ButtonRateClick(TObject *Sender)
{
	SQLQuery1->SQL->Text ="UPDATE ocjene SET bodovi = \""+Edit2->Text+"\"WHERE idUser= \""+LabelUserId->Caption+"\" AND idAlbum= \""+DBEdit1->Text+"\";";
	SQLQuery1->ExecSQL();

	//DBNavigator1->Update();



}
//---------------------------------------------------------------------------


void __fastcall TFormHome::ButtonRemoveImageClick(TObject *Sender)
{
	TestQuery1->Edit();
	TestQuery1->FieldByName("albumCover")->Clear();
	TestQuery1->Post();
}
//---------------------------------------------------------------------------



void __fastcall TFormHome::ComboBoxSortByChange(TObject *Sender)
{
	TestQuery1->IndexFieldNames = ComboBoxSortBy->Text;
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ComboBoxFilterExit(TObject *Sender)
{
	TestQuery1->Filter = ComboBoxFilter->Text;
    TestQuery1->Filtered = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonAllImagesClick(TObject *Sender)
{
    ProgressBar1->Position = 0;
	ProgressBar1->Max = StrToInt(FormHome->LabelAlbumCount->Caption);
    //ProgressBar1->Max = 16;

	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	String ImageDir = ini->ReadString("Application settings", "ImageDir", "default");
	if (ImageDir == "default") {
		ImageDir = "./thumbs/";
	}


	//TestQuery1->SQL->Text = "SELECT albums.*, ocjene.bodovi FROM albums INNER JOIN ocjene ON albums.idalbums = ocjene.idAlbum INNER JOIN users ON ocjene.idUser = users.id WHERE users.id = \""+LabelUserId->Caption+"\";";
	int brojac = 0;
    TestQuery1->Edit();
	if (!TestQuery1->Eof) {
		 TestQuery1->First();
		 do {

			String id = TestQuery1->FieldValues["idalbums"];
			String ImageDir2 = ImageDir + id + ".jpg";
			TFileStream* fs = new TFileStream(ImageDir2, fmCreate);

			String url = TestQuery1->FieldValues["coverUrl"];
			FormSearch->Download->Get(url, fs);


			delete fs;
			TestQuery1->Next();
            ++brojac;
			ProgressBar1->Position = brojac;
         } while (!TestQuery1->Eof);
	}
	else {
        ShowMessage("error/no images to download");
    }
	delete ini;


}
//---------------------------------------------------------------------------


void __fastcall TFormHome::ButtonHRVClick(TObject *Sender)
{
	const int CROATIAN = (SUBLANG_CROATIAN_CROATIA << 10) | LANG_CROATIAN;
	if (LoadNewResourceModule(CROATIAN)) {
		ReinitializeForms();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonENGClick(TObject *Sender)
{
    const int ENGLISH = (SUBLANG_ENGLISH_UK << 10) | LANG_ENGLISH;
	if (LoadNewResourceModule(ENGLISH)) {
		ReinitializeForms();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonDeleteAlbumClick(TObject *Sender)
{
	SQLQuery1->SQL->Text = "DELETE FROM ocjene WHERE idAlbum = \""
				 +DBEdit1->Text + "\";" + "DELETE FROM albums WHERE idalbums = \""
				 + DBEdit1->Text + "\";";
	SQLQuery1->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonDeleteAccountClick(TObject *Sender)
{
    ShowMessage("Application will close");
	SQLQuery1->SQL->Text = "DELETE FROM ocjene WHERE idUser = \""
				 +LabelUserId->Caption + "\";" + "DELETE FROM users WHERE id = \""
				 + LabelUserId->Caption + "\";";
	SQLQuery1->ExecSQL();
	Application->Terminate();
}
//---------------------------------------------------------------------------



