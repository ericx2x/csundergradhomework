
#include <iostream>
#include <string>
#include "Faculty.h"
#include "Teaching.h"

Teaching::Teaching (const string &name, const string &id, const double &pay, 
					const string &dept, const string &res, const string &cl)
:Faculty (name, id, pay, dept, res)
{
	Classes = cl;
}

Teaching::~Teaching()
{
	this->Faculty::~Faculty();
}

void Teaching::Set_Classes (const string &cl)
{
	Classes = cl;
}

string Teaching::Get_Classes() const
{
	return Classes;
}

string Teaching::To_String() const
{

	string temp;
	
	temp += "Teaching:\n";
	temp += this->Faculty::To_String();
	temp += ("Classes: " + Classes + "\n");

	return temp;
}

//Professor

Professor::Professor (const string &name, const string &id, const double &pay, 
					const string &dept, const string &res, const string &cl)
:Teaching (name, id, pay, dept, res, cl)
{}

Professor::~Professor()
{
	this->Teaching::~Teaching();
}

string Professor::To_String() const
{
	string temp;

	temp += "Professor:\n";
	temp += this->Teaching::To_String();
	
	return temp;

}
