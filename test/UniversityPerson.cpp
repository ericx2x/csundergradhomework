
#include <string>
#include <iostream>
#include "UniversityPerson.h"

const bool Sort = true; //0-by-id, 1-by-name.

using std::string;

UniversityPerson::UniversityPerson ()
{
	IsFN = false;
	IsIN = false;
	EmailAddress = "";
	PhoneNumber = "";
}

UniversityPerson::UniversityPerson (const string &name)
{
	IsFN = true;
	IsIN = false;
	FullName = name;
}

UniversityPerson::UniversityPerson (const string &name, const string &id)
{
	IsFN =  true;
	IsIN = true;
	FullName = name;
	IdNumber = id;

	EmailAddress = "";
	PhoneNumber = "";
}

UniversityPerson::~UniversityPerson ()
{
//nothing to do out of the ordinary.
}

UniversityPerson::UniversityPerson (const UniversityPerson &other)
{
	FullName = other.Get_Name();
	IdNumber = other.Get_IdNumber();
	IsFN = true;
	IsIN = true;

	EmailAddress = other.Get_EmailAddress();
	PhoneNumber = other.Get_PhoneNumber();

}

UniversityPerson &UniversityPerson::operator= (const UniversityPerson &other)
{

		this->FullName = other.Get_Name();
		this->IdNumber = other.Get_IdNumber();
		this->EmailAddress = other.Get_EmailAddress();
		this->PhoneNumber = other.Get_PhoneNumber();

	return *this;

}

string UniversityPerson::To_String () const
{

	std::string os;
	if (this->IsSet()) {

		os += ("Name: " + this->Get_Name() + "\n");
		
		os += ("ID: " + this->Get_IdNumber() + "\n");

		string email = this->Get_EmailAddress();
		string phone = this->Get_PhoneNumber();

		if (!email.empty())
			os += ("Email: " + email + "\n");

		if (!phone.empty())
			os += ("Phone: " + phone + "\n");

	} else {
	
		os += "";
	}

	return os;

}

void UniversityPerson::Set_Name(const std::string &name)
{
	if (!IsFN)
		FullName = name;
}

void UniversityPerson::Set_IdNumber(const std::string &ID)
{
	if (!IsIN)
		IdNumber = ID;
}

void UniversityPerson::Set_EmailAddress(const std::string &email)
{
	EmailAddress = email;
}

void UniversityPerson::Set_PhoneNumber(const std::string &phone)
{
	PhoneNumber = phone;

}
