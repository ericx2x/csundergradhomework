
#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
#include <iostream>
#include "UniversityPerson.h"

using std::string;

class Student: public UniversityPerson
{

public:

	//Constructor / Deconstructor
	Student (const string &, const string &, const string &, const string &, const double &);
	virtual ~Student ();

	//Set Major Set GY
	void Set_Major (const string &);
	void Set_GY (const string &);

	//Get Major, GY, GPA.
	string Get_Major () const;
	string Get_GY () const;
	string Get_GPA () const;

	//to string
	virtual string To_String () const;

protected:
	
	string Major;
	string GY;
	double GPA;

};

//Freshman Declerations

class Freshman: public Student
{

public:

	Freshman (const string &, const string &, const string &, const string &, const double &);
	virtual ~Freshman();

	virtual string To_String() const;

};

//Sophomore Declerations

class Sophomore: public Student
{

public:

	Sophomore (const string &, const string &, const string &, const string &, const double &);
	virtual ~Sophomore();

	virtual string To_String() const;

};

//Junior Declerations

class Junior: public Student
{

public:

	Junior (const string &, const string &, const string &, const string &, const double &);
	virtual ~Junior();

	virtual string To_String() const;

};

//Senior Declerations

class Senior: public Student
{

public:

	Senior (const string &, const string &, const string &, const string &, const double &);
	virtual ~Senior();

	virtual string To_String() const;

};

//Graduate Declerations

class Graduate: public Student
{

public:

	Graduate (const string &, const string &, const string &, const string &, const double &);
	virtual ~Graduate();

	virtual string To_String() const;

};


#endif


