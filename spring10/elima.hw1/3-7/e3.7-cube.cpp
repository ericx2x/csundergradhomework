/*******************************/
/* Eric Lima                   */
/*******************************/ 

// Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison_Wesley, 2002
  // Exercise 3.7
  // implement a Cube class, which represents a cube whose sides are parallel to 
  // x_y_z axes. Write two constructors; one that uses the left, bottom 
  // corner and the length of a side; and the other that uses two corners to create a cube. 
  // The corner, or corners should be represented as nested objects of class Point. 
  // The constructor should throw an exception if its parameters are incorrect. 
  // Carefully design the interface for this class and include functions that appear to be 
  // useful for operating on points. 
  // File: e3.7_cube.cpp
  // Implementation of class Cube
  #include "e3.7-point.h"
  #include "e3.7-cube.h"
  #include <cmath>
  #include <iostream>
using namespace std;

// All 8 corners are computed by using one corner at a time and the side length

    Cube::Cube(const Point& p, double side) throw (range_error) { //Makes a cube with a point and side. Points are made on the heap and used as a reference.
      if(side <= 0)
        throw range_error("non_positive side");
      left1_ = new Point(p);
      left2_ = new Point(p.x() + side, p.y(), p.z());
      left3_ = new Point(p.x() + side, p.y() + side, p.z());
      left4_ = new Point(p.x(), p.y() + side, p.z());
      right1_ = new Point(p.x(), p.y(), p.z() + side);
      right2_ = new Point(left2_->x(), left2_->y(), left2_->z() + side);
      right3_ = new Point(left3_->x(), left3_->y(), left3_->z() + side); 
      right4_ = new Point(left4_->x(), left4_->y(), left4_->z() + side); 
      side_ = side;
    }

// Two points are used for construction, error handing is taken care of.

    Cube::Cube(const Point& p, const Point& q) throw (range_error) { 
      double d = sqrt(pow(p.x()-q.x(),2)+pow(p.y()-q.y(),2)+pow(p.z()-q.z(),2));
      if(d == 0)
        throw range_error("equal points");
      side_ = d/sqrt(3);
      left1_ = new Point(p);
      left2_ = new Point(p.x() + side_, p.y(), p.z());
      left3_ = new Point(p.x() + side_, p.y() + side_, p.z());
      left4_ = new Point(p.x(), p.y() + side_, p.z());
      right1_ = new Point(p.x(), p.y(), p.z() + side_);
      right2_ = new Point(left2_->x(), left2_->y(), left2_->z() + side_);
      right3_ = new Point(left3_->x(), left3_->y(), left3_->z() + side_);
      right4_ = new Point(left4_->x(), left4_->y(), left4_->z() + side_);
   } 

// allocated space is freed by this destructor.

   Cube::~Cube() {
      delete left1_;
      delete left2_;
      delete left3_;
      delete left4_;
      delete right1_;
      delete right2_;
      delete right3_;
      delete right4_;
   }

// Member functions that output the corners

    void Cube::show1_left() const { 
      cout << "left1_ = (" << left1_->x() << " " << left1_->y() << " " << left1_->z() << ")" << endl; 
    }

    void Cube::show2_left() const {   
       cout << "left2_ = (" << left2_->x() << " " << left2_->y() << " " << left2_->z() << ")" << endl; 
    }   
    void Cube::show3_left() const {   
      cout << "left3_ = (" << left3_->x() << " " << left3_->y() << " " << left3_->z() << ")" << endl; 
    }   
    void Cube::show4_left() const {   
      cout << "left4_ = (" << left4_->x() << " " << left4_->y() << " " << left4_->z() << ")" << endl; 
    }   
    void Cube::show1_right() const {   
      cout << "right1 = (" << right1_->x() << " " << right1_->y() << " " << right1_->z() << ")" << endl; 
    }   
    void Cube::show2_right() const {   
      cout << "right2 = (" << right2_->x() << " " << right2_->y() << " " << right2_->z() << ")" << endl; 
    }   
    void Cube::show3_right() const {   
      cout << "right3 = (" << right3_->x() << " " << right3_->y() << " " << right3_->z() << ")" << endl;
    }   
    void Cube::show4_right() const {   
      cout << "right4 = (" << right4_->x() << " " << right4_->y() << " " << right4_->z() << ")" << endl; 
    }   
   void Cube::show_side() const {
     cout << "side = (" << side_ << ")" << endl;
  }
    
