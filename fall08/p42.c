/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 42: Random Numbers 2                      */
/*                                                   */
/* Approximate completion time: 27 minutes           */
/*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myrand( int n ) ;
int main( int argc, char *argv[] ) {

  int n, i ;

  srand ( time(NULL) );

  n = atoi( argv[2] ) ;

  for( i = 0 ; i < 10 ; i++ ) printf( "%d\n", myrand( n ) ) ;

  return 0 ;

}

int myrand( int n ) {

  n = rand() ;
  
  n =  n % 40 ;
  
  if ( n > 19 ) n =  n % 20 * -1 ;      
  
  else  n =  n % 20 ;
  
  return n ;
  
}
