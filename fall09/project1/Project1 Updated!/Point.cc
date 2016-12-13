#include "Point.h"

Point::Point (double x, double y) {
   this -> x = x;
   this -> y = y;
}

double& Point::getX(double& x) {
   return this -> x;
}

double& Point::getY(double& y) {
   return this -> y;
}

void Point::setNext (Point *next) {
   this -> next = next;
}
