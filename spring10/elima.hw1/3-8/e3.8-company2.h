/*******************************/
/* Eric Lima                   */
/*******************************/


// Tomasz Muldner, September 2002
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 3.8
 // Write a class Employee that represents an employee with three attributes:
  // name, salary, and id. Id numbers for new employees are assigned values
  // 1000, 1001, etc. Carefully design the interface for this class.
  // Then, write the following classes:
  // - Company1, which represents a company that can hire up to 10 employees,
  // these employees are stored in an array
  // - Company2, which represents a company that can hire up to n employees, where
  // the value of n is determined in the constructor; these employees are stored in an array
  // Finally, write a main program to both classes.
  // The interface for Company2 consists of 3 queries that get an attribute of the i-th
  // employee or throw an exception if i is incorrect, and two setters, respectively for
  // the name and the salary  
  // file: e3.8-company2.h
#ifndef E3_8_COMPANY2_H
#define E3_8_COMPANY2_H
class Employee;
#include <string>
#include <stdexcept>

// Company2 is declared here. All the variables are made here and only current_ and staff_ are private.

  class Company2 {
  public:
    explicit Company2(int) throw(std::range_error);
    ~Company2();
    string name(int) const throw(std::range_error);
    double salary(int) const throw(std::range_error);
    long id(int) const throw(std::range_error);
    void setName(int, const string&)  throw(std::range_error);
    void setSalary(int, double) throw(std::range_error);
  private:
    int current_;
    Employee* staff_;
  };
#endif

