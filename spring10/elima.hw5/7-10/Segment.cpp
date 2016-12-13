#include "Segment.h"

Segment::Segment(Point *one, Point *two) : p1(one), p2(two) {}

Segment::Segment() {}

Point* Segment::getP1() {
  return p1;
}

Point* Segment::getP2() {
  return p2;
}

void Segment::print() {
  p1->print();
  p2->print();
}
