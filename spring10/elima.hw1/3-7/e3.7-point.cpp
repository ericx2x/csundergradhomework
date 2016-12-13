/*******************************/
/* Eric Lima                   */
/*******************************/ 

// Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 3.7
  // file: e3.7-point.cpp
  // Implementation of class Point
 #include "e3.7-point.h"

  Point::Point(double x, double y, double z): x_(x), y_(y), z_(z) { }

  double Point::x() const { return x_; }
  double Point::y() const { return y_; }
  double Point::z() const { return z_; } 
