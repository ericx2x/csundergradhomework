/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project1                                     */
/*                                               */
/*  February 29, 2010                            */
/*************************************************/


#ifndef SPHERE_H
#define SPHERE_H

#include "Point.h"

using namespace PointNS ;

namespace SphereNS {

class Sphere : public Point {

 public:


    Sphere( Point p, float radius ) ;

    Sphere( const Sphere& s ) ;

    ~Sphere() ;

    Point getCenter() ;

    float getRadius() ;

    bool within( Point& p ) ;

    Sphere* clone( const float radius ) ;

    Sphere& operator=( Sphere& rhs ) ;


 private:

    float radius ;

} ;

  void info( Sphere s ) ;
}
			     
#endif
