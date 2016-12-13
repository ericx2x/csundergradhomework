  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 3.8
  // Sample main program


#include <iostream>
using namespace std;
#include "e3.8-company1.h"
#include "e3.8-company2.h"


// This is the main program. As you can see exception handling has been taken care of and testing has occured.

  int main() {
    Company1 c1;
    try {
      c1.setName(-1, "john");
    } catch(range_error& e) {
      cout << "setting name " << e.what() << endl;
    }
    try {
      c1.setName(0, "john");
      c1.setSalary(0, 20);
      cout << "name should be john " << c1.name(0) <<  " salary should be 20 " << 
          c1.salary(0) << endl;
    } catch(range_error& e) {
      cout << e.what() << endl;
    }    
     try {
      Company2 c2(-1);
    } catch(range_error& e) {
      cout << "creating 2nd company " << e.what() << endl;
    }     
    try {
     Company2 c2(1);
     cout << c2.id(1) << endl;
    }  catch(range_error& e) {
      cout << "accessing 1-st employee " << e.what() << endl;
    }     
    try {
     Company2 c2(1);
     cout << "id = " << c2.id(0) << endl;
     c2.setName(0, "Mary");
     c2.setSalary(0, 20000);
     cout << "name = " << c2.name(0) << " salary = " << c2.salary(0) << endl;
     }  catch(range_error& e) {
      cout << "accessing 1-st employee " << e.what() << endl;
    }  
}


