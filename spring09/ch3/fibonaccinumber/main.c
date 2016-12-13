/*************************************/
/* main.c                            */
/*************************************/

#include <stdio.h>
#include "fibonacci.h"

int main ( int argc, char *argv[] )
{

  int a, e ;
  integer n ;
  n.size = 1 ;
  n.digit[0] = 1 ;

  printf( "Input the Fibonacci index: " ) ;
  scanf ( "%d", &a ) ;

  printf( "Input the digit whose frequency is desired: " ) ;
  scanf ( "%d", &e ) ;

  n = fibonacci( n, a ) ;

  printf( "\n" );

  printf( "The digit %d occured with frequency: %lf \n\n", e, frequency(n, e) ) ;

  return 0  ;

}
