/*******************************/
/* Eric Lima                   */
/*******************************/ 

// Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 3.7
  // Write a class Point that represents a point in a three-dimensional space. 
  // Then, implement a Cube class, which represents a cube whose sides are parallel to 
  // x-y-z axes. Write two constructors; one that uses the left, bottom 
  // corner and the length of a side; and the other that uses two corners to create a cube. 
  // The corner, or corners should be represented as pointers to objects of class Point. 
  // The constructor should throw an exception if its parameters are incorrect. 
  // Carefully design the interface for this class and include functions that appear to be 
  // useful for operating on points. Finally, write a program to test both classes.
  // File: e3.7.cpp
  // Sample main program
#include <iostream>
using namespace std;
#include "e3.7-point.h"
#include "e3.7-cube.h"

// Displays all corners on the cube.

  void show(const Cube& c) {
     c.show1_left();
     c.show2_left();  
     c.show3_left();  
     c.show4_left();  
     c.show1_right();  
     c.show2_right();  
     c.show3_right();  
     c.show4_right();  
     c.show_side();
  }

// Two constructors that make the points and cubes.

  int main() {
    Point p(1,2,3);
    Cube c(p, 1);   //initializes point and cube constructors.
    show(c); 
    Point q(2,3,4);
    Cube d(p,q);
    show(d); 
    try {
      Cube e(p, p);
      show(e);
    } catch (range_error& ee) { 
       cout << ee.what() << endl; 
   }
  }

