//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "AddAlbumThread.h"
#include "Search123.h"
#include "MainForm.h"
#include <vcl.h>
#include "Albumi.cpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
void __fastcall AddAlbumThread::UpdateAddAlbum()
{
	FormSearch->LabelSearch->Caption = "Added album";
}
//---------------------------------------------------------------------------

__fastcall AddAlbumThread::AddAlbumThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall AddAlbumThread::Execute()
{
	FreeOnTerminate = true;

    String sql1 = "insert into albums(idalbums, name, artist, coverUrl, albumVariant) values(\"";
	String sql2 = "\",\"";
	String sql3 = "\");";

	Album* album1 = new Album;
	album1->LoadFromListItem(FormSearch->ListView1->Selected);


	sql1 =  sql1 + album1->GetId() +
			sql2 + album1->GetName() +
			sql2 + album1->GetArtist() +
			sql2 + album1->GetCoverUrl() +
			sql2 + album1->GetAlbumVariant() +
			sql3;

	TFDQuery* SQLQuery1 = new TFDQuery(NULL);
    SQLQuery1->Connection = FormHome->SqlfreehostingConnection;
	SQLQuery1->SQL->Text = sql1;
	//ShowMessage(sql1);
	SQLQuery1->ExecSQL();

	sql1 = "insert into ocjene(idUser, idAlbum, bodovi) values(\"";
//    String sql2 = "\",\"";
//	String sql3 = "\");";

	sql1 =  sql1 + FormSearch->LabelUserId->Caption +
			sql2 + album1->GetId() +
			sql2 + "0" +
			sql3;

	SQLQuery1->SQL->Text = sql1;
	//ShowMessage(sql1);
	SQLQuery1->ExecSQL();


	delete album1;
	delete SQLQuery1;
	Synchronize(UpdateAddAlbum);
}
//---------------------------------------------------------------------------
