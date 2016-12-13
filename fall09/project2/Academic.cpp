#include <iostream>
#include <string>
#include <sstream>
#include "Academic.h"

Academic::Academic(std::string name, std::string IDnumber, int wage, std::string office) :
  Employee (name, IDnumber, wage)
{
  setOffice (office);

  if (shouldPrint()) std::cout << "con:Academic" << std::endl;
}

Academic::~Academic(void)
{
  if (shouldPrint()) std::cout << "des:Academic" << std::endl;
}

void Academic::setOffice (std::string office)
{
  this -> office = office;
}

std::string Academic::getOffice () { return office; }

std::string Academic::toString() {

  std::ostringstream oss;

  Employee u( getName(), getIDnumber(), getWage() );
  oss << u.toString();
  oss << "Office: " << getOffice() << std::endl;

  return oss.str();

}
