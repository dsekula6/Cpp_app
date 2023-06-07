//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "Settings.h"
#include <Registry.hpp>
#include <string>
#include <System.JSON.hpp>
#include <sstream>
#include <jpeg.hpp>
#include <vector>


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

class Album {
private:
	String id, name, artist, coverUrl, tracklistCount, variant;

public:

	void LoadFromJSONArray(TJSONArray* ResultsArray, int i) {

		String name2 = ResultsArray->Items[i]->GetValue<UnicodeString>("title");
		id = ResultsArray->Items[i]->GetValue<UnicodeString>("id");
		artist = "";
		name = "";
		coverUrl = ResultsArray->Items[i]->GetValue<UnicodeString>("thumb");

		bool AlbumArtistBool = false;

		for (int j = 0; j < name2.Length(); j++) {
			 if (name2.SubString(j,1)=="-") {
				AlbumArtistBool = true;
			}
		}

		if (AlbumArtistBool) {
			for (int j = 1; j < name2.Length(); j++) {
				if (name2.SubString(j,1)=="-") {
					break;
				}
				else {
				artist += name2.SubString(j,1);
				}
			}
			int j = 1;
			bool AlbumNameBool = false;
			for (j = 1; j < name2.Length(); j++) {
				if (name2.SubString(j,1)=="-") {
					AlbumNameBool = true;
					break;
				}

			}
			if (AlbumNameBool) {
				for (int k = j+2; k < name2.Length()+1; k++) {
					name += name2.SubString(k,1);
				}
			}
		}
	  }
	  void LoadFromListItem(TListItem* Selected) {
		id = Selected->Caption;
		name = Selected->SubItems->ToStringArray()[0];
		artist = Selected->SubItems->ToStringArray()[1];
		coverUrl = Selected->SubItems->ToStringArray()[2];

      }

	  String GetId() {return id;}
	  String GetName() {return name;}
	  String GetArtist() {return artist;}
	  String GetCoverUrl() {return coverUrl;}
	  String GetTracklistCount() {return tracklistCount;}
	  String GetVariant() {return variant;}


};


void __fastcall TFormHome::ButtonSettingsClick(TObject *Sender)
{
	std::unique_ptr<TFormSettings> FormSettings(new TFormSettings(NULL));
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


	if (ini->ReadString("Application settings", "Font size", "medium")=="small") {
			FormHome->Font->Size = 7;
			ButtonAddNew->Font->Size = 7;
	}
	else if (ini->ReadString("Application settings", "Font size", "medium")=="large") {
			FormHome->Font->Size = 13;
			ButtonAddNew->Font->Size = 13;
	}
	else {
			FormHome->Font->Size = 9;
			ButtonAddNew->Font->Size = 9;
	}

	if (ini->ReadString("Application settings", "Theme", "light")=="dark") {
			FormHome->Color = cl3DDkShadow;
			FormHome->Font->Color = clBtnFace;
	}
	else {
			FormHome->Color = clBtnFace;
			FormHome->Font->Color = cl3DDkShadow;
	}

    TListColumn *ListCol;

	ListCol = ListView1->Columns->Add();
	ListCol->Caption = "id";
	ListCol->Width = 80;

	ListCol = ListView1->Columns->Add();
	ListCol->Caption = "Album name";
	ListCol->Width = 150;
	ListCol->Alignment = taRightJustify;

	ListCol = ListView1->Columns->Add();
	ListCol->Caption = "Artist";
	ListCol->Width = 100;
	ListCol->Alignment = taRightJustify;


	ListCol = ListView1->Columns->Add();
	ListCol->Caption = "url";
	ListCol->Width = 100;

    HINSTANCE resourceDll;
	if ((resourceDll = LoadLibrary(L"dllapp\\dll\\korisnik.dll")) == NULL) {
		ShowMessage("Cannot load korisnik.dll");
		return;
	}
	Image2->Picture->Bitmap->LoadFromResourceName((int)resourceDll, "USER_BMP");
	FreeLibrary(resourceDll);

	delete ini;
}
//---------------------------------------------------------------------------



void __fastcall TFormHome::ListView1DblClick(TObject *Sender)
{
	TFileStream* fs = new TFileStream("C:/Users/Daniel/Documents/Embarcadero/Studio/Projects/thumbs/slika3.jpg", fmCreate);
	String* url = new String(ListView1->Selected->SubItems->ToStringArray()[2]);
	Download->Get(*url, fs);


	delete fs;

	Image1->Picture->LoadFromFile("C:/Users/Daniel/Documents/Embarcadero/Studio/Projects/thumbs/slika3.jpg");
	delete url;
}
//---------------------------------------------------------------------------






void __fastcall TFormHome::ButtonSearchClick(TObject *Sender)
{
	RESTRequest1->Execute();

	// load json
	std::unique_ptr<TStringStream> jsonStream(new TStringStream(Memo1->Text));
	//jsonStream->LoadFromStream();


	//create json object
	TJSONObject* jsonFile = (TJSONObject*)TJSONObject::ParseJSONValue(jsonStream->DataString);
	//ShowMessage(jsonFile->ToString());

	TJSONArray* ResultsArray = (TJSONArray*)TJSONObject::ParseJSONValue(jsonFile->GetValue("results")->ToString());
	//ShowMessage(jsonArray->ToString());

	ListView1->Items->Clear();


	TListItem *ListIt;

	ListView1->ViewStyle = vsReport;

	//std::vector<Album> Albumi;


	int counter = 10;
	for (int i = 0; i < counter; i++) {

			String ResultType = ResultsArray->Items[i]->GetValue<UnicodeString>("type");
			if (ResultType == "release") {


				Album* album1 = new Album;
				album1->LoadFromJSONArray(ResultsArray, i);

				ListIt = ListView1->Items->Add();
				ListIt->Caption = album1->GetId();
				ListIt->SubItems->Add(album1->GetName());
				ListIt->SubItems->Add(album1->GetArtist());
				ListIt->SubItems->Add(album1->GetCoverUrl());

                delete album1;


			}
			else {
				counter++;
			}


	}
}
//---------------------------------------------------------------------------


void __fastcall TFormHome::ButtonAddNewClick(TObject *Sender)
{
	String sql1 = "insert into albums(idalbums, name, artist, coverUrl, variant) values(\"";
	String sql2 = "\",\"";
	String sql3 = "\");";

	Album* album1 = new Album;
	album1->LoadFromListItem(ListView1->Selected);


	sql1 =  sql1 + album1->GetId() +
			sql2 + album1->GetName() +
			sql2 + album1->GetArtist() +
			sql2 + album1->GetCoverUrl() +
			sql2 + album1->GetVariant() +
			sql3;

	SQLQuery1->SQL->Text = sql1;
	//ShowMessage(sql1);
	SQLQuery1->ExecSQL();

	delete album1;
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

void __fastcall TFormHome::DownloadWorkBegin(TObject *ASender, TWorkMode AWorkMode,
		  __int64 AWorkCountMax)
{
	ProgressBar1->Position = 0;
	ProgressBar1->Max = AWorkCountMax;
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::DownloadWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{
	ProgressBar1->Position = AWorkCount;
    Application->ProcessMessages();
}
//---------------------------------------------------------------------------


void __fastcall TFormHome::ButtonThrottle1Click(TObject *Sender)
{
	IdInterceptThrottler1->BitsPerSec = 200000;
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonThrottle2Click(TObject *Sender)
{
    IdInterceptThrottler1->BitsPerSec = 800000;
}
//---------------------------------------------------------------------------


