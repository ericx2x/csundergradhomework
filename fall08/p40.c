/*********************************************************/
/* Programmer: Eric Joesph Lima                          */
/*                                                       */
/* Program 39: Recursive Factorial                       */
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

  if( n == 0 ) return 1 ;

  return  n * factorial( n - 1 ) ;

}
