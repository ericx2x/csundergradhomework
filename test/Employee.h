#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
#include <iostream>
#include "UniversityPerson.h"

using std::string;

class Employee: public UniversityPerson
{

public:

	//Constructor / Deconstructor
	Employee (const string &, const string &, const double &); //name id pay
	virtual ~Employee ();

	//Set Pay
	void Set_Pay (const double &);

	//Get Pay.
	string Get_Pay () const;

	//to string
	virtual string To_String () const;

protected:
	
	double Pay;


};

#endif



