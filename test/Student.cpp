
#include <string>
#include <iostream>
#include <sstream>
#include "UniversityPerson.h"
#include "Student.h"

using std::string;

Student::Student (const string &name, const string &id, const string &major, const string &gy, const double &gpa) 
				  : UniversityPerson (name, id)
{

	Major = major;
	GY = gy;
	GPA = gpa;

}

Student::~Student () 
{
	this->UniversityPerson::~UniversityPerson();
}

void Student::Set_Major (const string &major)
{
	Major = major;
}

void Student::Set_GY(const std::string &gy)
{
	GY = gy;
}

string Student::Get_Major() const
{
	return (Major);
}

string Student::Get_GY () const
{
	return (GY);
}

string Student::Get_GPA () const
{
	std::ostringstream buf;
	buf << GPA;

	return (buf.str());

}

string Student::To_String () const
{

	string temp;

	temp += this->UniversityPerson::To_String();
	temp += ("Major: " + this->Get_Major() + "\n");
	temp += ("GY: " + this->Get_GY() + "\n");
	temp += ("GPA: " + this->Get_GPA() + "\n");

	return temp;

}

//Freshman Definitions.

Freshman::Freshman(const string &name, const string &id, const string &major, const string &gy, const double &gpa)
:Student (name, id, major, gy, gpa)
{}

Freshman::~Freshman() {}

string Freshman::To_String() const
{

	string temp;
	
	temp += "Freshman:\n";
	temp += this->Student::To_String();

	return temp;

}

//Sophomore Definitions.

Sophomore::Sophomore(const string &name, const string &id, const string &major, const string &gy, const double &gpa)
:Student (name, id, major, gy, gpa)
{}

Sophomore::~Sophomore() {}

string Sophomore::To_String() const
{

	string temp;
	
	temp += "Sophomore:\n";
	temp += this->Student::To_String();

	return temp;

}

//Junior Definitions.

Junior::Junior(const string &name, const string &id, const string &major, const string &gy, const double &gpa)
:Student (name, id, major, gy, gpa)
{}

Junior::~Junior() {}

string Junior::To_String() const
{

	string temp;
	
	temp += "Junior:\n";
	temp += this->Student::To_String();

	return temp;

}

//Senior Definitions.

Senior::Senior(const string &name, const string &id, const string &major, const string &gy, const double &gpa)
:Student (name, id, major, gy, gpa)
{}

Senior::~Senior() {}

string Senior::To_String() const
{

	string temp;
	
	temp += "Senior:\n";
	temp += this->Student::To_String();

	return temp;

}

//Graduate Definitions.

Graduate::Graduate(const string &name, const string &id, const string &major, const string &gy, const double &gpa)
:Student (name, id, major, gy, gpa)
{}

Graduate::~Graduate() {}

string Graduate::To_String() const
{

	string temp;
	
	temp += "Graduate:\n";
	temp += this->Student::To_String();

	return temp;

}

