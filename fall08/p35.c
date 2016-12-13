/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 35: Left Shift Plus                       */
/*                                                   */
/* Approximate completion time: 32 minutes           */
/*****************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {
  
  int x = 1 ;
  unsigned int y = 1 ; 
  int limit ;
  int i ;
  
  limit = sizeof( int ) * 8 ;
  
  printf("\nColumn X       Column Y\n\n" ) ;
  
  printf("%-12d   %u\n", x, y ) ;
  
  for( i = 0 ; i < limit - 1 ; i++ ) {
    
    x = x << 1 ;
    
    y = y << 1 ;
    
    printf( "%-12d   %u\n", x, y ) ;
    
  }
  
  printf( "\n" ) ;
  
  return 0 ;
  
}
