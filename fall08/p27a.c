/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program ^:                                          */
/*                                                                           */
/* Approximate completion time:                              */
/*****************************************************************************/

#include <stdio.h>

float gay( float a[], float b[] ) {
  int i ;
  float temp ;

  for( i = 0 ; i < 8 ; i++ ) {
    temp = a[i] * b[i];
  }

  return temp;

}
int main( int argc, char *argv[] ) {

  int i ;

  float a[8], b[8] ;

  for( i = 0 ; i < 8 ; i++ ) scanf( "%f", &a[i] ) ;

for( i = 0 ; i < 8 ; i++ ) scanf( "%f", &b[i] ) ;

printf( "%f",  gay( a, b ));



  /* fclose( fin ) ; */

  return 0 ;

}
