/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 50: Matrix Multiplication                                         */
/*                                                                           */
/* Approximate completion time:  3 hour and 45 minutes                       */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int inner (int *a, int *b, int size) ;

int **MatrixMult (int **x, int **z, int size) ;

int main( int argc, char *argv[] ) {
  
  FILE *fin =  fopen( argv[1], "r" ) ;
  int n, i, j ;
  
  fscanf( fin, "%d", &n );
  
  int **A = ( int** )malloc( sizeof( int ) *n ) ;
  int **B = ( int** )malloc( sizeof( int ) *n ) ;
  int **C = ( int** )malloc( sizeof( int ) *n ) ;
  
  for( i = 0 ; i < n ; i++ ) {
    A[i] = ( int* )malloc( sizeof( int ) *n ) ;
    B[i] = ( int* )malloc( sizeof( int ) *n ) ;
    C[i] = ( int* )malloc( sizeof( int ) *n ) ;
  }
  
  for( i = 0 ; i < n ; i++ ) 
    for( j = 0 ; j < n ; j++)
      fscanf( fin, "%d", &A[i][j] ) ;
  
  for( i = 0 ; i < n ; i++ )
    for( j = 0 ; j < n ; j++)
      fscanf( fin, "%d", &B[i][j] ) ;
  
  for( i = 0 ; i < n ; i++ ) {
    
    for( j = 0 ; j < n ; j++ ) printf("%3d",A[i][j] ) ;
    
    printf("\n") ;
    
  }
  
  printf ("*\n");
  
  for( i = 0 ; i < n ; i++ ) {
    
    for( j = 0 ; j < n ; j++ ) printf("%3d",B[i][j] ) ;
    printf("\n") ;
  }
  
  printf ("=\n");
  
  C = MatrixMult (A, B, n);
  
  for (i = 0; i < n; i++) {
    
    for (j = 0; j < n; j++)
      
      printf ("%3d", C[i][j]);
    
    printf ("\n");
    
  }
  
  fclose( fin ) ; 
  
  return 0 ;
}

int **MatrixMult (int **x, int **z, int size) {
  
  int i, j, k ;
  int *v = (int *) malloc ( sizeof (int) *size);
  int **D = (int **) malloc (sizeof (int *) *size);
  
  for (i = 0; i < size; i++) D[i] = (int *) malloc ( sizeof (int) *size);
  
  for (i = 0; i < size; i++) {
    
    for (j = 0; j < size; j++) {
      
      for (k = 0; k < size; k++) v[k] = z[k][j];
      
      D[i][j] = inner (x[i], v, size);
      
    }
    
  }
  
  return D;
}

int inner (int *a, int *b, int size) {
  
  int i, sum = 0 ;
  
  for (i = 0; i < size; i++) sum += (a[i] * b[i]) ;
  
  return sum;
  
}
