/*********************************************************/
/* Programmer: Eric Lima                                 */
/*                                                       */
/* Main driver to test complex number module.            */
/*********************************************************/

#include <stdio.h>
#include "globals.h" 
#include "complex.h"

int main ( int argc, char *argv[] ) {

  complex complex1, complex2, complex3 ;
  double r, i ;

 printf( "Complex 1: Please enter two floating point values: " ) ;
 scanf( "%lf", &r) ; scanf("%lf", &i ) ;
 complex1 = load_complex( r , i ) ;
 printf("\nThe complex number is " ) ; print_complex( complex1 ) ;
 printf("\n") ;

 printf( "Complex 2: Please enter two floating point values: " ) ;
 scanf( "%lf", &r) ; scanf("%lf", &i ) ;
 complex2 = load_complex( r , i ) ;
 printf("\nThe complex number is " ) ; print_complex( complex2 ) ;
 printf("\n") ;

 complex3 = add_complex( complex1, complex2 ) ;
 printf("The addition of the two complex numbers is ") ;
 print_complex( complex3 ) ;
 printf("\n") ;

 complex3 = subtract_complex( complex1, complex2 ) ;
 printf("The subtraction of the two complex numbers is ") ;
 print_complex( complex3 ) ;
 printf("\n") ;

 complex3 = multiply_complex( complex1, complex2 ) ;
 printf("The multiplication of the two complex numbers is ") ;
 print_complex( complex3 ) ;
 printf("\n") ;

 complex3 = divide_complex( complex1, complex2 ) ;
 printf("The division of the two complex numbers is ") ;
 print_complex( complex3 ) ;
 printf("\n") ;

 if( equal_complex( complex1, complex2 ) ) printf("\nThey are two equal complex numbers.\n");

 else printf("\nThe numbers are not equal.\n");

 return 0 ;

}
