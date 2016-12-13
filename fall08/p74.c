/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 74: Complex Number module                                         */
/*                                                                           */
/* Approximate completion time: 4 hours                                      */
/*****************************************************************************/

#include <stdio.h> 
#include "complex.h"
#include "complex.c"

int main( int argc, char *argv[] ) {

  complex A, B, C, D ;
  double r, im ;

  printf( "Enter in a real and imaginary component. " ) ; 
  scanf("%lf%lf", &r, &im ) ;

  A.r = r ;

  A.im = im ;

  printf( "Enter in a real and imaginary component. " ) ; 
  scanf("%lf%lf", &r, &im ) ;

  B.r = r ;
  B.im = im ;

  C = ADD_complex( A, B) ;
  printf("%lf %lf", C.r, C.im ) ;

  putchar('\n');

  D = MULT_complex( A, B) ;
  printf("%lf %lf", D.r, D.im ) ; 

  putchar('\n');

  return 0 ;

}
