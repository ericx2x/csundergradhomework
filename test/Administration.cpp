
#include <iostream>
#include <string>
#include "Academic.h"
#include "Administration.h"

using std::string;

Administration::Administration(const std::string &name, const std::string &id, const double &pay, const std::string &dept, const std::string &sect)
:Academic (name, id, pay, dept)
{

	Secretary = sect;

}

Administration::~Administration() 
{ 
	this->Academic::~Academic();
}


void Administration::Set_Secretary(const std::string &sect)
{
	Secretary = sect;
}

string Administration::Get_Secretary() const
{
	return Secretary;
}

string Administration::To_String() const
{
	string temp;

	temp += this->Academic::To_String();
	temp += ("Secretary: " + Secretary + "\n");

	return temp;
}

//Chancellor

Chancellor::Chancellor(const std::string &name, const std::string &id, const double &pay, const std::string &dept, const std::string &sect)
:Administration (name, id, pay, dept, sect)
{}

Chancellor::~Chancellor()
{
	this->Administration::~Administration();
}

string Chancellor::To_String() const
{
	string temp;

	temp += "Chancellor:\n";
	temp += this->Administration::To_String();

	return temp;

}

//Provost

Provost::Provost(const std::string &name, const std::string &id, const double &pay, const std::string &dept, const std::string &sect)
:Administration (name, id, pay, dept, sect)
{}

Provost::~Provost()
{
	this->Administration::~Administration();
}
string Provost::To_String() const
{
	string temp;

	temp += "Provost:\n";
	temp += this->Administration::To_String();

	return temp;

}

//Dean

Dean::Dean(const std::string &name, const std::string &id, const double &pay, const std::string &dept, const std::string &sect)
:Administration (name, id, pay, dept, sect)
{}

Dean::~Dean()
{
	this->Administration::~Administration();
}

string Dean::To_String() const
{
	string temp;

	temp += "Dean:\n";
	temp += this->Administration::To_String();

	return temp;

}


