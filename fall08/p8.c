/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 8: One Line of Asterisks            */
/*                                             */
/* Approximate completion time: 27 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int num , j ;

  FILE *fin ;

  fin = fopen("testdata8" , "r");

  fscanf( fin , "%d" , &num ) ;

  printf( "\n" ) ;

  for ( j = 0 ; j < num ; j++) {

    printf( "*" ) ;

  }

  printf( "\n\n" ) ;

  fclose( fin ) ;

  return 0 ;

}
