/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 30: Passing a Two Dimensional Array */
/*                                             */
/* Approximate completion time: 15 minutes     */
/***********************************************/

#include <stdio.h>

int sum( int A[][3], int r, int c ) ;

int main( int argc, char *argv[] ) {
  
  int i, j    ;
  int A[3][3] ;
  
  printf( "Please, enter in nine numbers to find the sum of those numbers.\n" ) ;
  
  for( i = 0 ; i < 3 ; i++ ) {
    for( j = 0 ; j < 3 ; j++ ) {
      scanf( "%d" , &A[i][j] ) ;      
    }
  }
  
  printf( "The sum of the numbers you've entered is %d.\n", sum( A, 3, 3 ) ) ;
  
  return 0 ;
  
}

int sum( int A[][3], int r, int c ) {
  
  int i, j    ;
  int sum = 0 ;
  
  for( i = 0 ; i < 3 ; i++ )
    for( j = 0 ; j < 3 ; j++ )
      sum = sum + A[i][j] ;
  
  return sum ;
  
}
