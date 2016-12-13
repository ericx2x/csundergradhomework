/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 73: Malloc Up A Two Dimenisional Array                            */
/*                                                                           */
/* Approximate completion time: 54 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void arraywalk( int *n, int r, int c ) ;

int arraysum( int *n, int r, int c ) ;

int main( int argc, char *argv[] ) {
  
  int *n ;
  int r , c ;
  
  printf( "Please, enter in the number of rows. \n") ;
  scanf( "%d", &r ) ; 
  
  printf( "Please, enter in the number of columns. \n") ;
  scanf( "%d", &c ) ; 
  
  n = ( int* )malloc( r * c * sizeof( int ) ) ; 
  
  arraywalk( n, r, c ) ;
  
  printf( "\n\nThe sum of all of the cells inside the two dimensional array is %d. \n\n\n", arraysum( n, r, c ) )  ; 
  
  return 0 ;
  
}

void arraywalk( int *n, int r, int c ) {

  int i, j ;

  for( i = 0 ; i < r ; i++ )
    for( j = 0 ; j < c ; j++)
      n[i * c + j ] = 6 ;

}


int arraysum( int *n, int r, int c ) {
  
  int i, j, sum = 0 ;
  
  for( i = 0 ; i < r ; i++ ) 
    for( j = 0 ; j < c ; j++)
      sum += n[ i * c + j ] ; 
  
  return sum ;
  
}
