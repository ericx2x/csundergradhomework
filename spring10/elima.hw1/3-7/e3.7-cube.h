/*******************************/
/* Eric Lima                   */
/*******************************/ 

// Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 3.7
  // implement a Cube class, which represents a cube whose sides are parallel to 
  // x-y-z axes. Write two constructors; one that uses the left, bottom 
  // corner and the length of a side; and the other that uses two corners to create a cube. 
  // The corner, or corners should be represented as pointers to objects of class Point. 
  // The constructor should throw an exception if its parameters are incorrect. 
  // Carefully design the interface for this class and include functions that appear to be 
  // useful for operating on points. 
  // File: e3.7-cube.h
#ifndef E3_7_CUBE_H
#define E3_7_CUBE_H
#include <stdexcept>
using namespace std;
// Cube class gets declared

  class Point;
  class Cube {
  public:
    explicit Cube(const Point&, double) throw(range_error);
    explicit Cube(const Point&, const Point&) throw(range_error);
    ~Cube();
    void show1_left() const;
    void show2_left() const;  
    void show3_left() const;  
    void show4_left() const;  
    void show1_right() const;  
    void show2_right() const;  
    void show3_right() const;  
    void show4_right() const;  
    void show_side() const;
  private:
    Point* left1_;
    Point* left2_;
    Point* left3_;
    Point* left4_;
    Point* right1_;
    Point* right2_;
    Point* right3_;
    Point* right4_;
    double side_;
};
#endif
 
