/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 75: Taxi! Taxi!                                                   */
/*                                                                           */
/* Approximate completion time:  3 hours 23 minutes                          */
/*****************************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {
  
  int n, i, j, r, r1, r2, r3, r4, count = 0, order = 0 ;
  
  printf("Please, enter a number to find the Ramanujan numbers less than that number.\n") ;
  
  scanf("%d", &n ) ;
  
  for( r = 0 ; r < n ; r++ ) {
    count = 0 ;
    for( i = 1 ; i < 30 ; i++ )
      for( j = 1 ; j < 30 ; j++ ) {
        if( r ==  j*j*j + i*i*i && i != r2 && j != r1 ){
	  count++;
	  if( count == 1 ) {
	    r1 = i ;
	    r2 = j ;
	  }
	  if( count == 2 ) {
	    r3 = i ;
	    r4 = j ;
	  }
        }
      }
    if( count >= 2 ) {
      order++;
      printf( "Ramanujan   First   Second    First  Second   Order\n" ) ;
      printf( "   Number    Cube     Cube     Root    Root        \n" ) ;
      printf( "_________   _____   ______    _____  ______   _____\n" ) ;
      printf( "%8d %8d %8d %8d %7d %8d\n\n", r, r1*r1*r1, r2*r2*r2, r1, r2, order ) ;

    } 
  }
  

  return 0 ;
  
}
