/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 31: Brute Force Primes                    */
/*                                                   */
/* Approximate completion time: 19 minutes           */
/*****************************************************/

#include <stdio.h>

int IsPrime( int x ) ;
int main( int argc, char *argv[] ) {
  
  int x     ; 
  
  while( scanf( "%d", &x ) > 0 ) {
    
    if ( IsPrime( x ) == 1 ) printf( "The number is prime.\n" ) ;

    else printf("The number is not prime.\n" ) ;
    
  }
  
  return 0 ;
  
}

int IsPrime( int x ) {
  
  int i, count = 0 ;
  
  for( i = 1 ; i <= x ; i++ ) 

    if( (x % i) == 0 ){ count++ ;

    printf("a%d", i ) ;



}

  return ( count == 2 ) ;
  
}
