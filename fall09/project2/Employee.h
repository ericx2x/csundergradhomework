#ifndef _EMPLOYEE
#define _EMPLOYEE

#include <iostream>
#include "UniversityPerson.h"

class Employee : public UniversityPerson
{
 public:
  Employee(std::string name, std::string IDnumber, int wage);
  ~Employee(void);

  int getWage ();
  void setWage (const int wage);

  std::string toString();

 private:
  int wage;
};

#endif
