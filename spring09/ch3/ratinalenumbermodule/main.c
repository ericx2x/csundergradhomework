/*******************************************************************************/
/* Programmer:     Jim Canning                                                 */
/*                                                                             */
/* Main driver to test rational number module.                                 */
/*******************************************************************************/

#include <stdio.h>
#include "globals.h"
#include "rational.h"

int main( int argc, char *argv[] ) {

  rational rational1, rational2, rational3 ;
  int n, d ;

  printf( "Rational1: Please enter two integer values:  " ) ;
  scanf("%d", &n) ;  scanf("%d", &d ) ;

  rational1 = load_rational( n , d ) ;

  printf("\nThe rational number is " );  print_rational( rational1 ) ;
  printf("\n");

  
  printf( "Rational2: Please enter two integer values:  " ) ;
  scanf("%d", &n) ;   scanf("%d", &d ) ;

  rational2 = load_rational( n, d ) ;

  printf("\nThe rational number is " ); print_rational( rational2 ) ;
  printf("\n");

  rational3 = add_rational( rational1, rational2 ) ;

  printf("The addition of the two rational numbers is ");   print_rational( rational3 ) ;
  printf("\n") ;

  rational3 = subtract_rational( rational1, rational2 ) ;

  printf("The subtraction of the two rational numbers is ");  print_rational( rational3 ) ;
  printf("\n") ;

  rational3 = multiply_rational( rational1, rational2 ) ;

  printf( "The multiplication of the two rational numbers is " );  print_rational( rational3 ) ;
  printf("\n") ;

  rational3 = divide_rational(rational1, rational2 ) ;

  printf( "The division of the two rational numbers is " );  print_rational( rational3 ) ;
  printf("\n") ;

  if ( equal_rational( rational1, rational2 ) )  printf("\nThey are two equal rational numbers.\n");

  else printf("\nThey are not equal.\n") ;

  return 0 ;

}
