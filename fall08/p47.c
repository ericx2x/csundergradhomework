/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 47:  Bits of Fun                                                  */
/*                                                                           */
/* Approximate completion time: 48 minutes                                   */
/*****************************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {
  
  int n, limit, count = 0, i ;
  
  FILE *fin = fopen( "testdata47", "r") ;
  
  limit = sizeof( int ) * 8 ;
  
  while( fscanf( fin, "%d", &n ) != EOF ) {
    
    for( i = 0 ; i < limit ; i++ ) {
      
      if( n % 2 != 0 )count++ ;
      
      n = n >> 1 ;
      
    }
    
    printf( "%d ", count ) ;
    
    count = 0 ;
    
  }
  
  fclose( fin ) ;
  
  return 0 ;
  
}
