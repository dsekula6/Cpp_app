//---------------------------------------------------------------------------

#pragma hdrstop

#include "korisnik.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <IdHashMessageDigest.hpp>

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
	void SetUsername(String _username) {
		username = _username;
	}
	void SetPassword(String _password) {
		TIdHashMessageDigest5* md5Pass = new TIdHashMessageDigest5;
		password = md5Pass->HashStringAsHex(_password);

		delete md5Pass;

	}
	void SetIdUser(String _username) {
		username = _username;
	}
	String GetUsername() {
		return username;
	}
	String GetPassword() {
		return password;
	}
	String GetIdUser() {
        return idUser;
    }
	bool CompareUsername(String UserPass) {
		if (username.Compare(UserPass)==0){
			return true;
		}
		return false;
	}
	bool ComparePassword(String UserPass) {
		if (password.Compare(UserPass)==0){
			return true;
		}
		return false;
	}
	void Destroy() {
    	delete this;
	};

};
extern "C" Korisnik* DLL_EXPORT __stdcall CreateDllClassInstance();

Korisnik* CreateDllClassInstance() {
	return new Korisnik;
};

