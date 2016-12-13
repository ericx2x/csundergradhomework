/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 73: Malloc Up A Two Dimenisional Array                            */
/*                                                                           */
/* Approximate completion time: 54 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int arraysum( int *n, int r, int c ) ;

int main( int argc, char *argv[] ) {
  
  int *n, i, j ;
  int r , c ;
  
  printf( "Please, enter in the number of rows.") ;
  scanf( "%d", &r ) ; 

  printf( "Please, enter in the number of columns.") ;
  scanf( "%d", &c ) ; 

  n = ( int* )malloc( r * c * sizeof( int ) ) ; 
  
  for( i = 0 ; i < r ; i++ ) 
    for( j = 0 ; j < c ; j++) 
      n[i * c + j ] = 6 ; 
  
  printf( "\n\n%d\n\n\n", arraysum( n, r, c ) )  ; 
  
  return 0 ;
  
}



int arraysum( int *n, int r, int c ) {
  
  int i, j, sum = 0 ;
  
  for( i = 0 ; i < r ; i++ ) 
    for( j = 0 ; j < c ; j++)
      sum += n[ i * c + j ] ; 
  
  return sum ;
  
}
