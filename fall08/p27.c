/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 27: Inner Product of Two Vectors    */
/*                                             */
/* Approximate completion time: 46 minutes     */
/***********************************************/

#include <stdio.h>

float inner( float u[], float v[], int size ) ;

int main( int argc, char *argv[] ) {
  int size, i  ;
  float u[8]   ;
  float v[8]   ;
  
  printf( "Please, enter eight numbers into the first vector.\n") ;
  
  for(  i = 0 ; i < 8 ; i++ ) scanf( "%f" , &u[i] ) ;
  
  printf( "Please, enter eight numbers into the second vector.\n") ;
  
  for(  i = 0 ; i < 8 ; i++ ) scanf( "%f" , &v[i] ) ;
  
  printf( "%f\n" , inner( u, v, size ) ) ;
  
  return 0 ;
  
}

float inner( float u[], float v[], int size ) {
  
  int i    ;
  
  size = 0 ;
  
  for( i = 0 ; i < 8 ; i++ ) size = size + u[i] * v[i] ;
  
  return size  ;
  
}
