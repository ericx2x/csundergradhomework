/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 45: Twin Primes                           */
/*                                                   */
/* Approximate completion time: 39 minutes           */
/*****************************************************/

#include <stdio.h>

int IsPrime( int x ) ;
int main( int argc, char *argv[] ) {

  int x  ; 

  printf( "This program will print out all twin prime numbers less than 3,000. \n" ) ;

  for( x = 0 ; x < 3000 ; x++ ) {

  if ( IsPrime( x ) == 1 ) 
    if ( IsPrime( x + 2 ) == 1 && x + 2 < 3000 ) 
      printf( "The numbers %d and %d are twin numbers. \n", x, x+2 ) ;
  
  }
  
  return 0 ;
  
}

int IsPrime( int x ) {
  
  int i, count = 0 ;
  
  for( i = 1 ; i <= x ; i++ ) if( (x % i) == 0 ) count++ ;

  return ( count == 2 ) ;

}
