#include <iostream>
#include <string>
#include "Alumnus.h"

Alumnus::Alumnus(std::string name, std::string IDnumber) :
  UniversityPerson (name, IDnumber)
{
  if (shouldPrint()) std::cout << "con:Alumnus" << std::endl;
}

Alumnus::~Alumnus(void)
{
  if (shouldPrint()) std::cout << "des:Alumnus" << std::endl;
}
