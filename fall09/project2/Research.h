#ifndef _RESEARCH
#define _RESEARCH

#include <iostream>
#include <string>
#include "Faculty.h"

class Research : public Faculty
{
 public:
  Research(std::string name, std::string IDnumber, int wage, std::string office, std::string classroom);
  ~Research(void);
};

#endif
