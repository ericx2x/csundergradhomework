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
  int i, j ;
  int sum  ;

  limit = sizeof( int ) * 8 ;
  
  printf("%d  %u\n", x, y ) ;
  
  for( i = 0 ; i < limit - 1 ; i++ ) {
    
    x = x << 1;
    
    y = y << 1;

    printf( "%d", x ) ;

    j = limit;

    for( j = limit ; j > 0 ; j-- ) {

      printf( " " ) ;

    }
    sum = x ;
    while( sum > 0 ){
      limit = limit - 1 ;
      sum = sum % 10 ;
      sum = sum / 10 ;
    }
   
    printf( "%u\n", y ) ;

  }
  
  return 0 ;
  
}
