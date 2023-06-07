//---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormSettings : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelFontSize;
	TLabel *LabelTheme;
	TComboBox *ComboBoxFontSize;
	TComboBox *ComboBoxTheme;
	TButton *ButtonSave;
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSettings *FormSettings;
//---------------------------------------------------------------------------
#endif
