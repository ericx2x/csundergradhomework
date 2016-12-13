/*********************************************************/
/* Programmer: Eric Joesph Lima                          */
/*                                                       */
/* Program 39: Non recursive Factorial - Use a function! */
/*                                                       */
/* Approximate completion time: 45 minutes               */
/*********************************************************/

#include <stdio.h>
#include <stdlib.h>

int factorial( int n ) ;
int main( int argc, char *argv[] ) {
  
  int n = atoi( argv[1] ) ;
  
  printf( "The factorial of %d is %d.\n", n, factorial( n ) ) ;
  
  return 0 ;
  
}

int factorial( int n ) {
  
  int product = 1 ;
  
  int i ;
  
  if( n == 0 ) return 1 ;
  
  for( i = n ; i > 1 ; i-- ) product = product *  i  ;
  
  return product ;
  
}
