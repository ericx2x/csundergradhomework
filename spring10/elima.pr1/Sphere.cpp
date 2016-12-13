/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project1                                     */
/*                                               */
/*  February 29, 2010                            */
/*************************************************/

#include <iostream>
#include <math.h>
#include "Sphere.h"
#include "Point.h"

using namespace std;
using namespace PointNS ;
using namespace SphereNS ;

Sphere::Sphere( Point p, float r ) : Point(p) , radius(r) {}

Sphere::Sphere( const Sphere& s ) : Point(s) , radius(s.radius) {}

Sphere::~Sphere() {}

Point Sphere::getCenter() {

  return *this ;

}

float Sphere::getRadius() {

  return this->radius;
}

bool Sphere::within( Point& p ) {

  double dx, dy, dz ;
  double sq ;
 
  dx = pow(p.getx() - getx(),2);
  dy = pow(p.gety() - gety(),2);
  dz = pow(p.getz() - getz(),2);
  dx = dx + dy + dz;

  sq = sqrt(dx);

  if ( (int)sq == getRadius() )
    return true;

  else return false ;
}

Sphere* Sphere::clone( const float radius ) {


  Sphere* s = new Sphere( (Point)*this, radius ) ;

  SphereNS::info( *s) ;

  return s ;

}

Sphere& Sphere::operator=( Sphere& rhs ) {


  if ( this != &rhs ) {

    Point::operator=(rhs) ;

    this->radius = rhs.radius ;

  }

  return *this ;

}

void SphereNS::info ( Sphere s ) {

cout << "\n( " << s.getx() << ", " << s.gety() << ", " << s.getz() << " )" << endl;

 cout << "Radius is " << s.getRadius() << endl ;

}

 

			     
