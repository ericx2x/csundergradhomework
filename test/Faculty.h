
#ifndef _FACULTY_H
#define _FACULTY_H

#include <iostream>
#include <string>
#include "Academic.h"

using std::string;

class Faculty: public Academic
{

public:

	Faculty (const string&, const string&, const double&, const string&, const string&);
	~Faculty ();

	void Set_Research (const string&);

	string Get_Research () const;

	virtual string To_String() const;

protected:

	string Research;

};

#endif



