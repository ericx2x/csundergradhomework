/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 57: Goldbach's Conjecture                                         */
/*                                                                           */
/* Approximate completion time: 59 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int IsPrime( int x ) ;
int main( int argc, char *argv[] ) {
  
  int i, j, start = atoi( argv[1]), finish = atoi( argv[2] ) ;
  
  int sum = start ;
  
  for( i = 0 ; i < finish ; i++ ) {
    
    for( j = 0 ; j < finish ; j++ ) {
      
      if( IsPrime( j ) == 1 && IsPrime( i ) == 1 && i != j && i + j == sum && sum <= finish && sum >= start ) {
	
	printf( "%d = %d + %d\n", sum, i, j )  ;     
	
        sum += 2 ;
	
	i = 0 ;

      }
      
    }
    
  }
  
  return 0 ;
  
}

int IsPrime( int i ) {
  
  int k, count = 0 ;
  
  for( k = 1 ; k <= i ; k++ ) if( (i % k) == 0 ) count++ ;
  
  return ( count == 2 ) ;
  
}
