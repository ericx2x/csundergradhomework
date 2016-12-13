
#include <string>
#include <iostream>
#include <sstream>
#include "UniversityPerson.h"
#include "Employee.h"

using std::string;

Employee::Employee(const string &name, const string &id, const double &pay)
:UniversityPerson (name , id)
{
	Pay = pay;
}

Employee::~Employee()
{
	this->UniversityPerson::~UniversityPerson();
}

void Employee::Set_Pay (const double &pay)
{
	Pay = pay;
}

string Employee::Get_Pay() const
{

	std::ostringstream buf;
	buf << Pay;

	return (buf.str());
}

string Employee::To_String () const
{

	string temp;

	temp += this->UniversityPerson::To_String();
	temp += ("Pay: " + this->Get_Pay() + "\n");

	return temp;

}
