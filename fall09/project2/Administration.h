#ifndef _ADMINISTRATION
#define _ADMINISTRATION

#include <iostream>
#include <string>
#include "Academic.h"

class Administration : public Academic
{
 public:
  Administration(std::string name, std::string IDnumber, int wage, std::string office, std::string secretary);
  ~Administration(void);

  void setSecretary (std::string secretary);
  std::string getSecretary ();

  std::string toString();

 private:
  std::string secretary;
};

#endif
