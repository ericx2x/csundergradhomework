#ifndef _ALUMNUS
#define _ALUMNUS

#include <iostream>
#include "UniversityPerson.h"

class Alumnus : public UniversityPerson
{
 public:
  Alumnus(std::string name, std::string IDnumber);
  ~Alumnus(void);
};

#endif
