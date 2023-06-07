//---------------------------------------------------------------------------

#ifndef RegisterH
#define RegisterH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
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
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include <System.SysUtils.hpp>
#include "uTPLb_CryptographicLibrary.hpp"
//---------------------------------------------------------------------------
class TFormRegister : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditUsername;
	TEdit *EditPassword;
	TButton *ButtonRegister;
	TFDQuery *SQLQuery1;
	TCodec *Codec1;
	void __fastcall ButtonRegisterClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormRegister(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegister *FormRegister;
//---------------------------------------------------------------------------
#endif
