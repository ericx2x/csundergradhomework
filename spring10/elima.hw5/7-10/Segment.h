#ifndef _SEGMENT
#define _SEGMENT

#include "Point.h"

class Segment {

 protected:
  Point *p1, *p2;

 public:
  Segment();
  Segment(Point *one, Point *two);
  Point* getP1();
  Point* getP2();
  void print();

};

#endif
