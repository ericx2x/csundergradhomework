  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 3.8
  // file: e3.8-employee.h
 // Write a class Employee that represents an employee with three attributes:
  // name, salary, and id. Id numbers for new employees are assigned values
  // 1000, 1001, etc. Carefully design the interface for this class.
  // Then, write the following classes:
  // - Company1, which represents a company that can hire up to 10 employees,
  // these employees are stored in an array
  // - Company2, which represents a company that can hire up to n employees, where
  // the value of n is determined in the constructor; these employees are stored in an array
  // Finally, write a main program to both classes.
  // The interface for Employee consists of 3 queries that get an attribute of the 
  // employee, and two setters, respectively for the name and the salary 
 
#ifndef E3_8_EMPLOYEE_H
#define E3_8_EMPLOYEE_H
#include <string>

using namespace std ;

// This segment declares the Employee class as well as the private members and public variables.

class Employee {

  public:
    explicit Employee(const string& = "", double = 0);
    string name() const;
    double salary() const;
    long id() const;
    void setName(const string&);
    void setSalary(double);
  private:
    string name_;
    double salary_;
    long id_;
    static long currentId_;
  };
#endif

