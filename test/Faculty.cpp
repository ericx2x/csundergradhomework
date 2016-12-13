
#include <iostream>
#include <string>
#include "Academic.h"
#include "Faculty.h"

Faculty::Faculty (const string &name, const string &id, const double &pay, const string &dept, const string &res)
:Academic (name, id, pay, dept)
{
	Research = res;
}

Faculty::~Faculty()
{
	this->Academic::~Academic();
}

void Faculty::Set_Research (const string &res)
{
	Research = res;
}

string Faculty::Get_Research() const
{
	return Research;
}

string Faculty::To_String() const
{

	string temp;
	
	temp += this->Academic::To_String();
	temp += ("Research: " + Research + "\n");

	return temp;
}

