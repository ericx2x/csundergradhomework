// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ch7.point.cpp
#include "Point.h"
#include <iostream>
  
Point::Point(double x, double y): x_(x), y_(y) {}
Point::~Point() {} 
double Point::getX() const { return x_;}
double Point::getY() const { return y_;}
void Point::setX(double x) { x_ = x; }
void Point::setY(double y) { y_ = y; }
void Point::print() {
  std::cout << "(" << x_ << "," << y_ << ")\n";
}
