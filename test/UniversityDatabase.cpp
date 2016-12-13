
#include "UniversityDatabase.h"
#include <iostream>
#include <ostream>
#include <map>
#include <string>

using std::string;
using std::map;

void UniversityDatabase::Print ()
{

	std::cout << "A Complete Listing" << std::endl;
	std::cout << "------------------" << std::endl;

	map<const string, UniversityPerson*>::key_compare mycomp;
	map<const string, UniversityPerson*>::iterator it;
	string highest;

	mycomp = _Name.key_comp();

	highest = _Name.rbegin()->first;     // key value of last element

	it = _Name.begin();
	do {
		std::cout /*<< (*it).first << " => "*/ << it->second->To_String() << std::endl << std::endl;
	} while ( mycomp((*it++).first, highest) );

	std::cout << std::endl;

}

void UniversityDatabase::add_user(UniversityPerson *tuser)
{

	this->_Name[tuser->Get_Name()] = tuser;
	this->_ID[tuser->Get_IdNumber()] = tuser;

}

UniversityPerson* UniversityDatabase::get_user_Name(const std::string &name)
{

	return (this->_Name[name]);

}

UniversityPerson* UniversityDatabase::get_user_ID(const std::string &id)
{

	return (this->_ID[id]);

}

