#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"

Employee::Employee(std::string name, std::string IDnumber, int wage) :
  UniversityPerson( name, IDnumber )
{
  setWage (wage);

  if (shouldPrint()) std::cout << "con:Employee" << std::endl;
}

Employee::~Employee(void)
{
  if (shouldPrint()) std::cout << "des:Employee" << std::endl;
}

int Employee::getWage () { return wage; }

void Employee::setWage (const int wage) {
  this -> wage = wage;
}

std::string Employee::toString() {

  std::ostringstream oss;

  UniversityPerson u(getName(), getIDnumber());
  oss << u.toString();
  oss << "Wage: " << getWage() << std::endl;

  return oss.str();

}
