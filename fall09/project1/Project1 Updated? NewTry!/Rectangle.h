#ifndef RECTANGLE
#define RECTANGLE

#include "Point.h" 

class Rectangle {

   public:
      Rectangle (Point *p, double width, double length);

   private:
      Point *p;
      double width, length;
   
};

#endif
