/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 29: Simulating Call by Reference    */
/*                                             */
/* Approximate completion time:  21 minutes    */
/***********************************************/

#include <stdio.h>

void swap( int a , int b ) {

  int temp  ;

  temp = a ;
  a = b    ;
  b = temp ;

}

int main( int argc, char *argv[] ) {
 
  int *a , *b ;

  printf( "Please, enter two numbers to have them swapped.\n" ) ;

  scanf( "%d%d", a, b ) ;

  swap( a, b ) ;

  printf( "%d %d\n", a, b ) ;

  return 0 ;

}
