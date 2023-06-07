//---------------------------------------------------------------------------

#ifndef korisnikH
#define korisnikH
//---------------------------------------------------------------------------
#endif
#include <vcl.h>

#ifdef EXPORTS
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT __declspec(dllimport)
#endif

class IKorisnik {
public:
	virtual void SetUsername(String _username) = 0;
	virtual void SetPassword(String _password) = 0;
	virtual String GetUsername() = 0;
	virtual String GetPassword() = 0;
	virtual bool CompareUsername(String UserPass) = 0;
	virtual bool ComparePassword(String UserPass) = 0;
	virtual void Destroy() = 0;

};

class Korisnik : public IKorisnik{
private:
	String username;
	String password;
	String idUser;
public:
	void SetUsername(String _username);
	void SetPassword(String _password);
    void SetIdUser(String _id);
	String GetUsername();
	String GetPassword();
	String GetIdUser();
	bool CompareUsername(String UserPass);
	bool ComparePassword(String UserPass);
	void Destroy();


};
extern "C" Korisnik* DLL_EXPORT __stdcall CreateDllClassInstance();

