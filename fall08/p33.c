/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 33: Area of a Triangle              */
/*                                             */
/* Approximate completion time: 19 minutes     */
/***********************************************/

#include <stdio.h>
#include <math.h>

float findarea( float x, float y, float z, float area ) ;

int main( int argc, char *argv[] ) {
  
  float x, y, z, area, a ;
  
  printf( "Please, enter in the lengths of the three sides of the triangle. " ) ;
  
  scanf( "%f%f%f" , &x, &y, &z ) ;
  
  a = findarea( x, y, z, area ) ;

  printf( "%f\n", a ) ;
  
  return 0 ;
  
}

float findarea( float x, float y, float z, float area ) {
  
  float s ;
  
  s  = ( x + y + z ) / 2 ;
  
  area = sqrt( s * ( s - x ) * ( s - y ) * ( s - z ) ) ;
  
  return area ; 
  
}
