/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 53: Fibonacci Sequence (Recursive)        */
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

  if( n == 1 ) return 1 ;
  if( n == 2 ) return 1 ;

  return ( fib( n - 1 )+ fib( n - 2 ) ) ;

}
