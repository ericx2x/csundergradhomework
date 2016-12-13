/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 57: Goldbach's Conjecture                                         */
/*                                                                           */
/* Approximate completion time:     59 minutes                               */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int goldbach( int start, int finish, int sum, int i, int j ) ;

int IsPrime( int x ) ;

int main( int argc, char *argv[] ) {
  
  int start, finish ;
  
  start = atoi( argv[1] ) ;
  
  int i, j , sum = start ;
  
  finish = atoi( argv[2] ) ;
  
  for( i = 0 ; i < 1000 ; i++ ) {
    
    for( j = 0 ; j < 1000 ; j++ ) {
      
         printf( "%d\n", goldbach( start, finish, sum, i, j ) ) ;
      
      /*      goldbach( start, finish, sum, i, j ) ;*/
      
    }
    
  }
  
  return 0 ;
  
}

int goldbach( int start, int finish, int sum, int i, int j ) {
  
  return ( ( IsPrime( j ) == 1 ) && ( IsPrime( i ) == 1 ) && ( i != j ) && i + j == sum && sum <= finish && sum >= start ) ;
  
  /* printf ( "%d %d %d", sum, i, j ) ;*/
  
  sum += 2 ;
  
}

int IsPrime( int i ) {
  
  int k, count = 0 ;

  for( k = 1 ; k <= i ; k++ ) if( (i % k) == 0 ) count++ ;
  
  return ( count == 2 ) ;
  
}
