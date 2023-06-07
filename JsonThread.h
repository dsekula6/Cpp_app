//---------------------------------------------------------------------------

#ifndef JsonThreadH
#define JsonThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TJsonThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TJsonThread(bool CreateSuspended);
	void __fastcall UpdateCaptionDone();
    void __fastcall UpdateCaptionWorking();
};
//---------------------------------------------------------------------------
#endif
