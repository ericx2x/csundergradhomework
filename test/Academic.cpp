
#include <iostream>
#include <string>
#include "Academic.h"
#include "Employee.h"

using std::string;

Academic::Academic(const string &name, const string &id, const double &pay, const string &dept)
:Employee (name, id, pay)
{
	Department = dept;
}

Academic::~Academic()
{
	this->Employee::~Employee();
}

void Academic::Set_Department(const string &dept)
{
	Department = dept;
}

string Academic::Get_Department() const
{
	return Department;
}

string Academic::To_String() const
{
	string temp;

	temp += this->Employee::To_String();
	temp += ("Department: " + Department + "\n");

	return temp;
}
