//---------------------------------------------------------------------------

#ifndef AddAlbumThreadH
#define AddAlbumThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class AddAlbumThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall AddAlbumThread(bool CreateSuspended);
    void __fastcall UpdateAddAlbum();
};
//---------------------------------------------------------------------------
#endif
