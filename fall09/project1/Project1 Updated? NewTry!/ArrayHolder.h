#ifndef ARRAY_HOLDER
#define ARRAY_HOLDER

#include "Point.h"
#include "Rectangle.h"

const int MAX = 50;

class ArrayHolder {

   public:
      ArrayHolder();
      //void init_listp() {
      void getPoints();
      void getRect();
      void draw();
      void addPoint(const double& x, const double& y);
      
   private:
      char a[MAX][MAX];
      Point *listpointer;
};

#endif
