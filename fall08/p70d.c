/******************************************************/
/* Programmer: Eric Joesph Lima                       */
/*                                                    */
/* Program 70: Quick Sort                             */
/*                                                    */
/* Approximate completion time: 3 hours and 12 minutes*/
/******************************************************/

#include <stdio.h>
#include <stdlib.h>

void quicksort( int A[], int left, int right ) ;

void readfile( FILE *fin, int A[], int n ) ;

void printsort( int A[], int n ) ;

int main( int argc, char *argv[] ) {
  int n, left = -1 ;

  FILE *fin = fopen( argv[2], "r" ) ;
  
  n = atoi( argv[1] ) ;

  int right = n ;

  int *A = ( int* ) malloc ( sizeof( int ) * n ) ; 
  
  readfile( fin, A, n ) ;
 
  quicksort( A, left + 1 , right ) ;
  
  printsort( A, n ) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}

void readfile( FILE *fin, int A[], int n ) {

  int i ;

  for( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

}


void quicksort( int A[], int left, int right ) {
  
  int i = left, j = right, pivot = A[right] ;
  
  while( right < left ) {
    while( ( A[left] >= pivot ) && ( left < right ) ) left ++ ;
    if( right != left ) {
      A[right] = A[left];
      right--;
    }
    while( ( A[right] <= pivot ) && ( left < right ) ) right-- ;
    if( right != left ) {
      A[left] = A[right] ;
      left++ ;
    } 
  }
  A[right] = pivot ;
  pivot = right ;
  left = i ;
  right = j;
  if ( right < pivot )
    quicksort( A, pivot + 1, right ) ;
  if ( left > pivot )
    quicksort( A, left, right + 1 ) ;
}



void printsort( int A[], int n ) {
  
  int i ; 
  
  for( i = 0 ; i < n ; i++ )  printf( "%d\n", A[i] ) ;
  
}
