/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 42: Random Numbers 2                      */
/*                                                   */
/* Approximate completion time: 30 minutes           */
/*****************************************************/

#include <stdio.h>
#include <stdlib.h>

int myrand( int n ) ;
int main( int argc, char *argv[] ) {

  int n, i ;

  n = atoi( argv[2] ) ;

  for( i = 0 ; i < 10 ; i++ ) printf( "%d\n", myrand( n ) ) ;

  return 0 ;

}

int myrand( int n ) {

  int negrand ;

  n = rand() ;

  negrand = rand() ;

  while( n > 19 ){

    n =  n % 20 ;

    if( negrand % 2 == 0 && n != 0)

      n = n * -1 ;

   }

  return n ;

}
