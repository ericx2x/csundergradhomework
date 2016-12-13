/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 55: Atoi                            */
/*                                             */
/* Approximate completion time: 43 minutes     */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

int digits( int x, int y ) {
  
  int count = 0, digit ;
  
  while( x > 0 ) {
    
    digit =  x % 10 ;
    
    if ( digit == y ) count++ ;
    
    x = x / 10 ;
    
  }
  
  return count ;
  
}

int main( int argc, char *argv[] ) {
  
  int x, y ;
  
  x = atoi( argv[1] ) ;
  
  y = atoi( argv[2] ) ;
  
  printf("\n\n") ;
  
  printf( "The number of times %d occurs in %d is %d.\n", y, x, digits( x, y ) ) ;
  
  printf("\n\n") ;
  
  return 0 ;
  
}
