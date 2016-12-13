#ifndef _ACADEMIC
#define _ACADEMIC

#include <iostream>
#include <string>
#include "Employee.h"

class Academic : public Employee
{
 public:
  Academic(std::string name, std::string IDnumber, int wage, std::string office);
  ~Academic(void);

  void setOffice (std::string office);
  std::string getOffice ();

  std::string toString();

 private:
  std::string office;
};

#endif
