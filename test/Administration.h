
#ifndef _ADMINSTRATION_H
#define _ADMINSTRATION_H

#include <string>
#include <iostream>
#include "Academic.h"

using std::string;

class Administration: public Academic
{

public:

	//Constructor / Deconstructor
	Administration (const string &, const string &, const double &, const string &, const string &); //name id pay dept sect
	~Administration ();

	//Set Department
	void Set_Secretary (const string &);

	//Get Department.
	string Get_Secretary () const;

	//to string
	virtual string To_String () const;

protected:
	
	string Secretary;


};

//Chancellor

class Chancellor: public Administration
{

	public:

	//Constructor / Deconstructor
	Chancellor(const string &, const string &, const double &, const string &, const string &); //name id pay dept sect
	~Chancellor ();

	//to string
	virtual string To_String () const;

};

//Provost

class Provost: public Administration
{

	public:

	//Constructor / Deconstructor
	Provost(const string &, const string &, const double &, const string &, const string &); //name id pay dept sect
	~Provost ();

	//to string
	virtual string To_String () const;

};

//Dean

class Dean: public Administration
{

	public:

	//Constructor / Deconstructor
	Dean(const string &, const string &, const double &, const string &, const string &); //name id pay dept sect
	~Dean ();

	//to string
	virtual string To_String () const;

};


#endif

