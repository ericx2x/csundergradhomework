/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 21: One Dimensional Array           */
/*                                             */
/* Approximate completion time:  25 minutes    */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {
  
  FILE *fin ;
  int  i , j[15] ; 
  
  fin = fopen( "testdata21" , "r" ) ;
  
  for( i = 0 ; i < 15  ; i++ ) fscanf( fin , "%d" , &j[i] ) ;
  
  for( i = 14 ; i >= 0  ; i-- ) printf( "%d\n" , j[i] ) ; 
  
  fclose( fin ) ;
  
  return 0 ;
  
}
