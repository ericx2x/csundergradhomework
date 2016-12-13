#include <iostream>
#include <string>
#include <sstream>
#include "Teaching.h"

Teaching::Teaching(std::string name, std::string IDnumber, int wage, std::string office, std::string classroom, int nClasses) :
  Faculty (name, IDnumber, wage, office, classroom)
{
  this -> nClasses = nClasses;

  if (shouldPrint()) std::cout << "con:Teaching" << std::endl;
}

Teaching::~Teaching(void)
{
  if (shouldPrint()) std::cout << "des:Teaching" << std::endl;
}

void Teaching::setNclasses (int nClasses)
{
  this -> nClasses = nClasses;
}

int Teaching::getNclasses () { return nClasses; }

std::string Teaching::toString() {

  std::ostringstream oss;

  Faculty u( getName(), getIDnumber(), getWage(), getOffice(), getClassroom() );
  oss << u.toString();
  oss << "# of Classes: " << getNclasses() << std::endl;

  return oss.str();

}
