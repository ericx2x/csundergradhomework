/******************************************************/
/* Programmer: Eric Joesph Lima                       */
/*                                                    */
/* Program 70: Quick Sort                             */
/*                                                    */
/* Approximate completion time: 1 hour and 23 minutes */
/******************************************************/

#include <stdio.h>
#include <stdlib.h>

void quicksort( int A[], int size ) ;

void readfile( FILE *fin, int A[], int n ) ;

void printsort( int A[], int n ) ;

int main( int argc, char *argv[] ) {
  int n     ;
  FILE *fin = fopen( argv[2], "r" ) ;;
  
  n = atoi( argv[1] ) ;

  int *A = ( int* ) malloc ( sizeof( int ) * n ) ; 
  
  readfile( fin, A, n ) ;
 
  quicksort( A, n ) ;
  
  printsort( A, n ) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}

void readfile( FILE *fin, int A[], int n ) {

  int i ;

  for( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

}


void quicksort( int A[], int n ) {
  
  int i, j, temp ;

  for( i = 0 ; i < n ; i++ )   
    for( j = 0 ; j < n - 1; j++ ) 
      if( A[j] > A[j+1] ) {
	
	temp = A[j]     ;
	
	A[j] = A[j+1]   ; 
	
	A[j+1] = temp   ;
	
      }
  
}

void printsort( int A[], int n ) {
  
  int i ; 

  for( i = 0 ; i < n ; i++ )  printf( "%d\n", A[i] ) ;
  
}
