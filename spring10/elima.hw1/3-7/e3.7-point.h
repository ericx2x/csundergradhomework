/*******************************/
/* Eric Lima                   */
/*******************************/ 

// Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 3.7
  // file: e3.7-point.h
#ifndef E3_7_POINT_H
#define E3_7_POINT_H
  class Point { 
  public:
    explicit Point(double = 0, double = 0, double = 0);
    double x() const;
    double y() const;
    double z() const;
  private:
    double x_;
    double y_;
    double z_;
  };
#endif

