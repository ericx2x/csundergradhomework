/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project1                                     */
/*                                               */
/*  February 29, 2010                            */
/*************************************************/

#ifndef POINT_H
#define POINT_H

namespace PointNS {

class Point {

 public:

  Point( const Point& p ) ;
  Point( float x, float y, float z ) ;
  ~Point() ;

  float getx() ;
  float gety() ;
  float getz() ;

  void setx( float X ) ;
  void sety( float Y ) ;
  void setz( float Z ) ;

  bool equal( Point p ) ;
  Point& operator=( Point& rhs ) ;

 protected:

  float x ;
  float y ;
  float z ;

} ;

 void info( Point p ) ;

}

#endif
