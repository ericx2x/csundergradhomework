#ifndef _HOURLY
#define _HOURLY

#include <iostream>
#include <string>
#include "Employee.h"

class Hourly : public Employee
{
 public:
  Hourly(std::string name, std::string IDnumber, int wage);
  ~Hourly(void);
};

#endif
