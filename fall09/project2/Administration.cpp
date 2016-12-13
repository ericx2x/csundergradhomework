#include <iostream>
#include <string>
#include <sstream>
#include "Administration.h"

Administration::Administration(std::string name, std::string IDnumber, int wage, std::string office, std::string secretary) :
  Academic (name, IDnumber, wage, office)
{
  setSecretary (secretary);

  if (shouldPrint()) std::cout << "con:Administration" << std::endl;
}

Administration::~Administration(void)
{
  if (shouldPrint()) std::cout << "des:Administration" << std::endl;
}

void Administration::setSecretary (std::string secretary)
{
  this -> secretary = secretary;
}


std::string Administration::getSecretary () { return secretary; }

std::string Administration::toString() {

  std::ostringstream oss;

  Academic u( getName(), getIDnumber(), getWage(), getOffice() );
  oss << u.toString();
  oss << "secretary: " << getSecretary() << std::endl;

  return oss.str();

}
