//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Search123.h"
#include <jpeg.hpp>
#include <System.JSON.hpp>
#include <Registry.hpp>
#include "MainForm.h"
#include "MainForm.cpp"
#include "JsonThread.h"
#include <memory>
#include "AddAlbumThread.h"
#include ".\\dllapp\\dynamic\\korisnik.h"
#include "Albumi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSearch *FormSearch;
//---------------------------------------------------------------------------
__fastcall TFormSearch::TFormSearch(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::ButtonSearchClick(TObject *Sender)
{

	TJsonThread *jsonThread = new TJsonThread(false);

}
//---------------------------------------------------------------------------


void __fastcall TFormSearch::ButtonAddNewClick(TObject *Sender)
{
	AddAlbumThread *albumThread = new AddAlbumThread(false);

//String sql1 = "insert into albums(idalbums, name, artist, coverUrl, albumVariant) values(\"";
//	String sql2 = "\",\"";
//	String sql3 = "\");";
//
//	Album* album1 = new Album;
//	album1->LoadFromListItem(ListView1->Selected);
//
//
//	sql1 =  sql1 + album1->GetId() +
//			sql2 + album1->GetName() +
//			sql2 + album1->GetArtist() +
//			sql2 + album1->GetCoverUrl() +
//			sql2 + album1->GetAlbumVariant() +
//			sql3;
//
//	SQLQuery1->SQL->Text = sql1;
//	//ShowMessage(sql1);
//	SQLQuery1->ExecSQL();
//
//	sql1 = "insert into ocjene(idUser, idAlbum, bodovi) values(\"";
////    String sql2 = "\",\"";
////	String sql3 = "\");";
//
//	sql1 =  sql1 + LabelUserId->Caption +
//			sql2 + album1->GetId() +
//			sql2 + "0" +
//			sql3;
//
//	SQLQuery1->SQL->Text = sql1;
//	//ShowMessage(sql1);
//	SQLQuery1->ExecSQL();
//
//
//	delete album1;
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::ButtonThrottle1Click(TObject *Sender)
{
    IdInterceptThrottler1->BitsPerSec = 200000;
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::ButtonThrottle2Click(TObject *Sender)
{
	IdInterceptThrottler1->BitsPerSec = 800000;
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::ListView1DblClick(TObject *Sender)
{
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	String ImageDir = ini->ReadString("Application settings", "ImageDir", "default");
	if (ImageDir == "default") {
		ImageDir = "./thumbs/";
	}
	String id = ListView1->Selected->Caption;
	ImageDir = ImageDir + id + ".jpg";
	TFileStream* fs = new TFileStream(ImageDir, fmCreate);

	String* url = new String(ListView1->Selected->SubItems->ToStringArray()[2]);
	Download->Get(*url, fs);


	delete fs;

	Image1->Picture->LoadFromFile(ImageDir);
	delete url;
    delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::ButtonAddImageClick(TObject *Sender)
{
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::DownloadWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{
	ProgressBar1->Position = AWorkCount;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::DownloadWorkBegin(TObject *ASender, TWorkMode AWorkMode,
          __int64 AWorkCountMax)
{
	ProgressBar1->Position = 0;
	ProgressBar1->Max = AWorkCountMax;
}
//---------------------------------------------------------------------------

