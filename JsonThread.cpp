//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "JsonThread.h"
#include "Search123.h"
#include "MainForm.h"
#include "Albumi.cpp"
#include <System.JSON.hpp>
#include <memory>
#pragma package(smart_init)
//USEFORM("Search123.cpp", FormSearch);
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
void __fastcall TJsonThread::UpdateCaptionDone()
{
	FormSearch->LabelSearch->Caption = "Done!";
}
void __fastcall TJsonThread::UpdateCaptionWorking()
{
	FormSearch->LabelSearch->Caption = "Working!";
}
//---------------------------------------------------------------------------

__fastcall TJsonThread::TJsonThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TJsonThread::Execute()
{
	FreeOnTerminate = true;
	//std::unique_ptr<TFormSearch> FormSearch(new TFormSearch(NULL));
	//FormSearch->RESTRequest1->Execute();
	TRESTRequest* RESTRequest1= new TRESTRequest(NULL);
	TRESTClient* RESTClient1= new TRESTClient(NULL);
	TRESTResponse* RESTResponse1= new TRESTResponse(NULL);
	RESTRequest1->Client = RESTClient1;
	RESTRequest1->Response = RESTResponse1;
	RESTClient1->BaseURL = "https://api.discogs.com/database/search";
	//TRESTRequestParameterList* parametri[1];
	RESTRequest1->Params =  FormSearch->RESTRequest1->Params;


	RESTRequest1->Execute();


	// load json
	std::unique_ptr<TStringStream> jsonStream(new TStringStream(RESTResponse1->Content));
	//jsonStream->LoadFromStream();


	//create json object
	TJSONObject* jsonFile = (TJSONObject*)TJSONObject::ParseJSONValue(jsonStream->DataString);
	//ShowMessage(jsonFile->ToString());

	TJSONArray* ResultsArray = (TJSONArray*)TJSONObject::ParseJSONValue(jsonFile->GetValue("results")->ToString());
	//ShowMessage(jsonArray->ToString());

	FormSearch->ListView1->Items->Clear();
	TListItem *ListIt;

	//FormSearch->ListView1->ViewStyle = vsReport;

	int counter = 10;
	for (int i = 0; i < counter; i++) {

			String ResultType = ResultsArray->Items[i]->GetValue<UnicodeString>("type");
			if (ResultType == "release") {


				Album* album1 = new Album;
				album1->LoadFromJSONArray(ResultsArray, i);

				ListIt = FormSearch->ListView1->Items->Add();
				ListIt->Caption = album1->GetId();
				ListIt->SubItems->Add(album1->GetName());
				ListIt->SubItems->Add(album1->GetArtist());
				ListIt->SubItems->Add(album1->GetCoverUrl());

				delete album1;

				Synchronize(UpdateCaptionWorking);

			}
			else {
				counter++;
			}


	}
	Synchronize(UpdateCaptionDone);
}
//---------------------------------------------------------------------------
