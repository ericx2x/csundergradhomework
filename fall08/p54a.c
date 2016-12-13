/***************************************************/
/* Programmer: Eric Joesph Lima                    */
/*                                                 */
/* Program 54: Maximum Sum Subvector               */
/*                                                 */
/* Approximate completion time: 2 hours 52 minutes */
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int Max( int *x, int *n, int *sum, FILE *fin ) ;

int main( int argc, char *argv[] ) {
  
  FILE *fin ;
  int n, sum = 0 ;
  int *x = ( int* ) malloc ( sizeof( int ) * n ) ;
  
  fin = fopen( argv[1], "r" ) ;
  
  n = atoi( argv[2] ) ;
  
  Max( x, &n, &sum, fin ) ;
  
  printf( "The subvector with the largest sum is %d.\n", sum ) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}

int Max( int *x, int *n, int *sum, FILE *fin ) {
  
  int count = 0 , nlast = 0, last = 0 ;
  
  while( fscanf( fin, "%d", &x[count] ) != EOF && count < *n ) {
    if ( x[count] < 0 && count > last ) {
      
      nlast = nlast + x[count] ;
      
    }
    
    else if( x[count] > 0 && x[count] > nlast ) {
      
      *sum = *sum + x[count] + nlast ;
      
    }
    
    last = count ;
    
    count++ ;
    
  }
  
  return *sum ;
  
}
