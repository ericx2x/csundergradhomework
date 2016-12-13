
#ifndef _UNIVERSITY_DATABASE
#define  _UNIVERSITY_DATABASE

#include <map>
#include <string>
#include <ostream>
#include "UniversityPerson.h"


	class UniversityDatabase
	{

	public:

		void Print ();

		void add_user (UniversityPerson*);
		UniversityPerson* get_user_Name (const std::string &);
		UniversityPerson* get_user_ID (const std::string &);

	private:

		std::map <const std::string, UniversityPerson*> _Name; 
		std::map <const std::string, UniversityPerson*> _ID;
		
	};



#endif

