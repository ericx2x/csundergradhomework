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
  int n ;

  FILE *fin = fopen( argv[2], "r" ) ;
  
  n = atoi( argv[1] ) ;

  int *A = ( int* ) malloc ( sizeof( int ) * n ) ; 
  
  readfile( fin, A, n ) ;
 
  quicksort( A, 0, n - 1 ) ;
  
  printsort( A, n ) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}

void readfile( FILE *fin, int A[], int n ) {

  int i ;

  for( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

}


void quicksort( int A[], int i, int j ) {
  
  int left = i, right = j, pivot = A[left] ;  

  while (i < j)
    {
      while ((A[j] >= pivot) && (i < j))
        j--;
      if (i != j)
        {
          A[i] = A[j];
          i++;
        }
      while ((A[i] <= pivot) && (i < j))
        i++;
      if (i != j)
        {
          A[j] = A[i];
          j--;
        }
    }
  A[i] = pivot;
  pivot = j;
  i = left ;
  j = right ;
  if (i < pivot)
    quicksort(A, i, pivot-1);
  if (j > pivot)
    quicksort(A, pivot+1, j);


}



void printsort( int A[], int n ) {
  
  int i ; 
    for( i = 0 ; i < n ; i++ )  printf( "%d\n", A[i] ) ;
  
}
