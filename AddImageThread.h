//---------------------------------------------------------------------------

#ifndef AddImageThreadH
#define AddImageThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class AddImageThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall AddImageThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
