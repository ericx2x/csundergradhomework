#include <iostream>
#include <string>
#include "Research.h"

Research::Research(std::string name, std::string IDnumber, int wage, std::string office, std::string classroom) :
  Faculty (name, IDnumber, wage, office, classroom)
{
  if (shouldPrint()) std::cout << "con:Research" << std::endl;
}

Research::~Research(void)
{
  if (shouldPrint()) std::cout << "des:Research" << std::endl;
}
