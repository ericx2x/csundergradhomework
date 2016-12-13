/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project1                                     */
/*                                               */
/*  February 29, 2010                            */
/*************************************************/

#include "Point.h" ;

using namespace PointNS ;

Point::Point( float X, float Y, float Z ) : x(X), y(Y), z(Z) {}

Point::Point( const Point& p ) {

  this->x = p.x ;
  this->y = p.y ;
  this->z = p.z ;
} 

Point::~Point() {}

float Point::getx() {

  return this->x ;

}

float Point::gety() {

  return this->y ;

}

float Point::getz() {

  return this->z ;

}

void Point::setx( float X ) {

  this->x = X ;  

}

void Point::sety( float Y ) {

  this->y = Y ;

}

void Point::setz( float Z ) {

  this->z = Z ;

}

bool Point::equal( Point p ) {

  return ( (this->x == p.x) && (this->y == p.y) && (this->z == p.z) ) ;

}

Point& Point::operator =( Point& rhs ) {

  if ( this != &rhs ) {
    
    x = rhs.getx();
    y = rhs.gety();
    z = rhs.getz();

  }

  return *this;
}

