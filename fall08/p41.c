/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 41: Random Numbers 1                */
/*                                             */
/* Approximate completion time: 33 minutes     */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myrand( int x ) ;

int main( int argc, char *argv[] ) {

  int x, i ;

  srand ( time(NULL) );

  for ( i = 0 ; i < 10 ; i++ ) printf( "%d\n", myrand( x ) ) ;

  return 0 ;

}

int myrand( int x ) {

  x = rand();

  x = x % 20 ;

  return x ;

}
