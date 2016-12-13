
#ifndef _ACADEMIC_H
#define _ACADEMIC_H

#include <string>
#include <iostream>
#include "Employee.h"

using std::string;

class Academic: public Employee
{

public:

	//Constructor / Deconstructor
	Academic (const string &, const string &, const double &, const string &); //name id pay dept
	virtual ~Academic ();

	//Set Department
	void Set_Department (const string &);

	//Get Department.
	string Get_Department () const;

	//to string
	virtual string To_String () const;

protected:
	
	string Department;


};

#endif

