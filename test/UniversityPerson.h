
#ifndef _UNIVERSITY_PERSON
#define _UNIVERSITY_PERSON

#include <string>
#include <ostream>
#include <iostream>

using std::string;

class UniversityPerson
{

public:

	//Constructors / Deconstructors
	UniversityPerson (); //no info
	UniversityPerson (const string &); //name only
	UniversityPerson (const string &, const string &); //name & id
	virtual ~UniversityPerson (); //default deconstructor

	//Copy control
	UniversityPerson (const UniversityPerson &);
	UniversityPerson & operator= (const UniversityPerson &);

	//Check that name and id are there.
	bool IsSet () const {return (IsFN && IsIN);}

	//Convert UniversityPerson to string.
	virtual string To_String() const;

	//Set name and idnumber.
	void Set_Name (const string &other);
	void Set_IdNumber (const string &);

	//Get name and idnumber.
	string Get_Name () const {return FullName;}
	string Get_IdNumber () const {return IdNumber;}

	//Set email and phone.
	void Set_EmailAddress (const string &);
	void Set_PhoneNumber (const string &);

	//Get email and phone.
	string Get_EmailAddress () const {return EmailAddress;}
	string Get_PhoneNumber () const {return PhoneNumber;}

private: //Things that can only be edited by UniversityPerson.

	string FullName;
	string IdNumber;

protected: //Things that can be edited by children.

	string EmailAddress;
	string PhoneNumber;
	bool IsFN;
	bool IsIN;

}; //end UniveristyPerson


#endif

