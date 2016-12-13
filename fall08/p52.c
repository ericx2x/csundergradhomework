/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 52: Fibonacci Sequence (Non-recursive)    */
/*                                                   */
/* Approximate completion time: 39 minutes           */
/*****************************************************/

#include <stdio.h>
#include <stdlib.h>

int fib( int n ) ;
int main( int argc, char *argv[] ) {

  int n ;

  n = atoi( argv[1] ) ;

  printf( "The fibonacci of %d is %d.\n", n, fib( n ) ) ;

  return 0 ;

}
int fib( int n ) {

  int i, a = 1, b = 1 , temp = 0 ;
  
  for( i = 0 ; i < n - 2 ; i++ ) {

      temp = b ;

      b = add( a, b) ; 

      a = temp ; 

  }

  return b ; 

}
