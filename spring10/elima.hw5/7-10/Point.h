// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ch7.point.h
#ifndef CH7_POINT_H
#define CH7_POINT_H      
class Point { 
 public:
  Point(double = 0, double = 0);
  virtual ~Point();  // just in case
  double getX() const;
  double getY() const;

  void setX(double) ;
  void setY(double) ;
  void print();
 private:
  double x_;
  double y_;
};
#endif

