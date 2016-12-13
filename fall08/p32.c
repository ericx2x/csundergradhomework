/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 32: Perfect Numbers                       */
/*                                                   */
/* Approximate completion time: 58 minutes           */
/*****************************************************/

#include <stdio.h>

int IsPerfect( int n ) ; 

int main( int argc, char *argv[] ) {
  
  int n = 1, i ;
  
  printf( "\n" ) ;
  
  for( i = 0 ; i < 100000 ; i++ ) if( IsPerfect( n ) == 1 ) printf("%d \n", n ) ;

  printf( "\n\n" ) ;
  
  return 0 ;
  
}

int IsPerfect( int n ) {
  
  int i, sum = 0 ;
  
  for( i = 1 ; i < n ; i++ ) if ( n % i == 0 ) sum += i ; 
  
  n += 1 ;
  
  return ( sum == n ) ; 
  
}
