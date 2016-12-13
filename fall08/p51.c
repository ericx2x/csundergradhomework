/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 51: Close Enough for All Practical Purposes                       */
/*                                                                           */
/* Approximate completion time: 58 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
      
  float x, e, a, a2 = 1 ;
  
  a = atof( argv[1] ) ;
  
  e = atof( argv[2] ) ;
  
  while( abs( ( ( a2 * a2 ) - a ) ) >= e ) {
    
    x =  0.50  * ( a2 + a/a2 ) ;

    a2 = x ;

  }
  
    x =  0.50  * ( a2 + a/a2 ) ;

    printf("The square root of %f is %f.\n", a, x ) ;
  
  return 0 ;
  
}
