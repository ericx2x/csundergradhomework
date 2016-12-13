/*******************************/
/* Eric Lima                   */
/*******************************/

// Tomasz Muldner, September 2001
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
  // The interface for Employee consists of 3 queries that get an attribute of the
  // employee, and two setters, respectively for the name and the salary   
  // file: e3.8-employee.cpp
  // Implementation of class Employee
#include <string>
#include "e3.8-employee.h"

// Definitons for the Employee class are here. The constructors that possibly make a new Employee and ID number are also here.

    long  Employee::currentId_ = 1000;

// currentID gives its value to the constructor to have the constructor make a new ID. The constructor makes sure it is impossible to get the same ID twice.
  
    Employee::Employee(const string& n, double s) : name_(n), salary_(s) {
       id_ = currentId_++; //id_ itteration
    }
    string Employee::name() const{
      return name_; //gives the name_ away
    }
    double Employee::salary() const{
      return salary_; //gives the salary_ away
    }
    long Employee::id() const{
      return id_; //gives the id_ away
    }
    void Employee::setName(const string& n) {
      name_ = n; //assigns n to name_
    }
    void Employee::setSalary(double d) {
      salary_ = d; //assigns salary_ to d
    } 

