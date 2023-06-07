//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <SimpleDS.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdAuthentication.hpp>
#include <IdServerIOHandler.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
//---------------------------------------------------------------------------
class TFormHome : public TForm
{
__published:	// IDE-managed Components
	TDataSource *DataSource1;
	TButton *ButtonSettings;
	TButton *ButtonAddNew;
	TButton *ButtonSortBy;
	TButton *ButtonView;
	TFDTable *FDTable1;
	TFDQuery *SQLQuery1;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TMemo *Memo1;
	TBindingsList *BindingsList1;
	TLinkControlToField *LinkControlToField1;
	TEdit *Edit1;
	TLinkControlToField *LinkControlToField2;
	TListView *ListView1;
	TIdHTTP *Download;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TButton *Button2;
	TImage *Image1;
	TFDConnection *SqlfreehostingConnection;
	TLabel *Label1;
	TLabel *Label2;
	TButton *ButtonSearch;
	TFDAutoIncField *FDTable1idalbums;
	TStringField *FDTable1name;
	TStringField *FDTable1artist;
	TStringField *FDTable1coverUrl;
	TBlobField *FDTable1albumCover;
	TIntegerField *FDTable1tracklistCount;
	TLabel *Label3;
	TDBEdit *DBEdit1;
	TLabel *Label4;
	TDBEdit *DBEdit2;
	TLabel *Label5;
	TDBEdit *DBEdit3;
	TLabel *Label6;
	TDBEdit *DBEdit4;
	TLabel *Label8;
	TDBEdit *DBEdit5;
	TDBNavigator *DBNavigator1;
	TButton *ButtonExportXML;
	TButton *ButtonExportJSON;
	TDBLookupComboBox *DBLookupComboBox1;
	TFDTable *FDTable2;
	TDBGrid *DBGrid1;
	TStringField *FDTable1variant;
	TDataSource *DataSource2;
	TLabel *Label7;
	TProgressBar *ProgressBar1;
	TIdInterceptThrottler *IdInterceptThrottler1;
	TButton *ButtonThrottle1;
	TButton *ButtonThrottle2;
	TImage *Image2;
	void __fastcall ButtonSettingsClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ListView1DblClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ButtonAddNewClick(TObject *Sender);
	void __fastcall ButtonExportXMLClick(TObject *Sender);
	void __fastcall ButtonExportJSONClick(TObject *Sender);
	void __fastcall DownloadWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall DownloadWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall ButtonThrottle1Click(TObject *Sender);
	void __fastcall ButtonThrottle2Click(TObject *Sender);





private:	// User declarations
public:		// User declarations
	__fastcall TFormHome(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHome *FormHome;
//---------------------------------------------------------------------------
#endif
