#ifndef _TEACHING
#define _TEACHING

#include <iostream>
#include <string>
#include "Faculty.h"

class Teaching : public Faculty
{
 public:
  Teaching(std::string name, std::string IDnumber, int wage, std::string office, std::string classroom, int nClasses);
  ~Teaching(void);

  void setNclasses (int nClasses);
  int getNclasses ();

  std::string toString ();

 private:
  int nClasses;
};

#endif
