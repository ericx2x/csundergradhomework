/***************************************************/
/* Programmer: Eric Joesph Lima                    */
/*                                                 */
/* Program 54: Maximum Sum Subvector               */
/*                                                 */
/* Approximate completion time:  2 hour 34 minutes */
/***************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  FILE *fin ;
  int n, count = 0, sum = 0, last = 0, negsum = 0 ;
  int *x = ( int* ) malloc ( sizeof( int ) *n ) ;
  
  fin = fopen( argv[1], "r" ) ;
  
  n = atoi( argv[2] ) ;
  
  while( fscanf( fin, "%d", &x[count] ) != EOF && count < n ) {

    if ( x[count] < 0 && count > last ) negsum = negsum + x[count] ;

    else if( x[count] > 0 && x[count] > negsum ) sum = sum + x[count] + negsum ;
    
    last = count ;
    
    count++ ;
    
  }
  
  printf( "The largest sum found in a subvector is %d.\n", sum ) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}
