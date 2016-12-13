/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 79: Selection Sort                                                */
/*                                                                           */
/* Approximate completion time: 1 hour and 23 minutes                        */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status selectionsort(int *A, int n ) {

  int i, j, min_index, temp ;
  
  for( i = 0 ; i < (n-1) ; i++ ) {
    min_index = i ;
    for( j = i + 1 ; j < n ; j++ ) 
      if( A[j] < A[min_index] ) min_index = j ;
    temp = A[i] ;
    A[i] = A[min_index] ;
    A[min_index] = temp ;
  }
  
  return OK;
  
}

int main( int argc, char *argv[] ) {
  
  FILE *fin = fopen( argv[1], "r" ) ; 
  int n, *A, i ;

  A = ( int * ) malloc ( sizeof ( int ) *n ) ;

  printf( "Please, enter in the amount of numbers you wish to sort.\n" ) ;

  scanf( "%d", &n ) ;

  for( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

  selectionsort( A, n ) ;

  printf("The first five numbers are " ) ;
  for( i = 0 ; i < 5 ; i++ ) printf("%d ", A[i] ) ;

  putchar('.') ;
  putchar('\n') ;

  printf("The last five numbers are " ) ;
  for( i = ( n - 5 ) ; i < n ; i++ ) printf("%d ", A[i] ) ;

  putchar('.') ;
  putchar('\n') ;

  fclose( fin ) ; 

  return 0 ;

}
