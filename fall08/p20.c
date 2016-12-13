/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 20: Scanf Returns What?             */
/*                                             */
/* Approximate completion time: 30 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  FILE *fin ;
  int x     ;

  fin = fopen( "testdata20" , "r" ) ;

  while( fscanf( fin , "%d" , &x)  != EOF ) {

    printf( "%d\n" , x ) ;

  }

  fclose( fin ) ;

  return 0 ;

}
