#ifndef _TEACHING_H
#define _TEACHING_H

#include <iostream>
#include <string>
#include "Faculty.h"

using std::string;

class Teaching: public Faculty
{

public:

	Teaching (const string&, const string&, const double&, 
		const string&, const string&, const string&);
	~Teaching ();

	void Set_Classes (const string&);

	string Get_Classes () const;

	virtual string To_String() const;

protected:

	string Classes;

};

class Professor:  public Teaching
{

public:

	Professor (const string&, const string&, const double&, 
		const string&, const string&, const string&);
	~Professor ();

	virtual string To_String() const;

};


#endif

