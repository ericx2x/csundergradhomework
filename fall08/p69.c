/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 69: Partition Problem                                             */
/*                                                                           */
/* Approximate completion time: 3 hours                                      */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  FILE *fin = fopen( "testdata69", "r" ) ; /*argv*/
  int i, n, count = 0, *A, *B, sum = 0, compare = 0 ;

  printf("Please, enter in the amount of numbers you wish to read in. ") ;

  scanf( "%d", &n ) ;

  A = ( int* ) malloc ( sizeof( int ) *n ) ;
  B = ( int* ) malloc ( sizeof( int ) *n ) ;

  for( i = 0 ; i < n ; i++ ) { 

    fscanf( fin, "%d", &A[i] ) ;

    sum += A[i] ;

    count++ ;

  }

  sum /= 2  ;

  while(1){



 if( sum == A[

  }

  for( i = 0 ; i < n ; i++ ) printf( "%d ", A[i] ) ;

  fclose( fin ) ; 

  return 0 ;

}
