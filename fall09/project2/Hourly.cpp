#include <iostream>
#include <string>
#include "Hourly.h"

Hourly::Hourly(std::string name, std::string IDnumber, int wage) :
  Employee (name, IDnumber, wage)
{
  if (shouldPrint()) std::cout << "con:Hourly" << std::endl;
}

Hourly::~Hourly(void)
{
  if (shouldPrint()) std::cout << "des:Hourly" << std::endl;
}
