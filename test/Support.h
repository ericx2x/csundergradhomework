
#ifndef _SUPPORT_H
#define _SUPPORT_H

#include <string>
#include <iostream>
#include "Employee.h"

using std::string;

class Support: public Employee
{

public:

	//Constructor / Deconstructor
	Support (const string &, const string &, const double &, const string &); //name id pay dept
	virtual ~Support ();

	//Set Building
	void Set_Building (const string &);

	//Get Building
	string Get_Building () const;

	//to string
	virtual string To_String () const;

protected:
	
	string Building;


};

#endif

