/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 62: Square Deal                                                   */
/*                                                                           */
/* Approximate completion time: 5 hours and 28 minutes                       */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int IsPrime( int x ) ;

int main(int argc, char *argv[]) {
  
  int I = 1000 ;
  int n = 0, i, dist = 1, j, x, y ;
  int **A;
  
  printf("Please, enter in N. " ) ;
  while( !( n % 2 == 1 && n > 2 && n < 16) ) scanf( "%d", &n ) ;
  
  printf("Please, enter in I. " ) ;
  
  while( I + n * n > 1001 ) scanf( "%d", &I ) ;
  
  A = ( int** ) malloc ( sizeof( int* )*n ) ;
  
  for( i = 0 ; i < n ; i++ ) A[i]= ( int* ) malloc ( sizeof( int ) * n ) ;

  x = y = n / 2 ;
  
  A[x][y] = I ;
  
  while( dist < n ) {
    
    for( i = 0 ; i < dist; i++ ) {

      ++y ;

      ++I ;

      A[x][y] = I ;

    }
    
    for( i = 0 ; i < dist; i++ ) {

      --x ;

      ++I ;

      A[x][y] = I ;

    }

    dist++;
    
    for( i = 0 ; i < dist; i++ ) {

      --y ;

      ++I ;

      A[x][y] = I ;

    }
    
    for( i = 0 ; i < dist; i++ ) {

      ++x ;

      ++I ;

      A[x][y] = I ;

    }
    
    dist++ ;
    
  }
  
  for( i = 0 ; i < dist - 1; i++ ) {

    ++y ;

    ++I ;

    A[x][y] = I ;

  }
  
  
  
  for( i = 0 ; i < n; i++ ) {

    printf("\n");

    for( j = 0 ; j < n ; j++ ) {

      if( IsPrime(A[i][j]) )

	printf("%4d", A[i][j]) ;

      else

	printf( " ***" );
    }

  }
  
  printf("\n");

  return 0 ;
  
}

int IsPrime( int x ) {
  
  int i, count = 0 ;
  
  for( i = 2 ; i <= ( x - 2 ) ; i++ ) if( (x % i) == 0 ) count++ ;
  
  return ( count == 0 ) ;
  
}
