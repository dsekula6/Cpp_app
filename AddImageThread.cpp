//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "AddImageThread.h"
#include "MainForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall AddImageThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall AddImageThread::AddImageThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall AddImageThread::Execute()
{
	FreeOnTerminate = true;
//	FormHome->TestQuery1->Edit();
//	static_cast<TBlobField*>(FormHome->TestQuery1->FieldByName("albumCover"))->LoadFromFile("./thumbs/slika3.jpg");
//	FormHome->TestQuery1->Post();
}
//---------------------------------------------------------------------------
