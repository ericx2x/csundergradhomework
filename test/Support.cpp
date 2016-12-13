
#include <iostream>
#include <string>
#include "Support.h"
#include "Employee.h"

using std::string;

Support::Support(const string &name, const string &id, const double &pay, const string &bl)
:Employee (name, id, pay)
{
	Building = bl;
}

Support::~Support()
{
	this->Employee::~Employee();
}

void Support::Set_Building(const string &bl)
{
	Building = bl;
}

string Support::Get_Building() const
{
	return Building;
}

string Support::To_String() const
{
	string temp;

	temp += "Support Staff:\n";
	temp += this->Employee::To_String();
	temp += ("Building of Work: " + Building + "\n");

	return temp;
}
