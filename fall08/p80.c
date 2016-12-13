/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 80: Insertion Sort                                                */
/*                                                                           */
/* Approximate completion time: 1 hour and 23 minutes                        */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status insertionsort(int *A, int n ) {

  int i, j, next;
  
  for( i = 0 ; i < n ; i++ ) {
    next = A[i] ;
    j = i ;

    while( ( j > 0 ) && ( A[j-1] > next ) ) {

      A[j] = A[j - 1] ;
      j = j - 1 ;
    }

    A[j] = next ;

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

  insertionsort( A, n ) ;

  printf("The first five numbers are " ) ;
  for( i = 0 ; i < 5 ; i++ ) printf("%d ", A[i] ) ;

  putchar('.') ;
  putchar('\n') ;

  printf("The last five numbers are " ) ;
  for( i = n - 5  ; i < n ; i++ ) printf("%d ", A[i] ) ;

  putchar('.') ;
  putchar('\n') ;

  fclose( fin ) ; 

  return 0 ;

}
