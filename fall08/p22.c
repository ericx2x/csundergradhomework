/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 22: Sum of a Bunch                  */
/*                                             */
/* Approximate completion time:  20 minutes    */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  FILE *fin ;
  int x , z = 0 ;

  fin = fopen( "testdata22" , "r" ) ;

  while( fscanf( fin , "%d" , &x )  != EOF ) {

    z = x + z ;

  }

  printf ( "%d\n" , z ) ;

  fclose( fin ) ;

  return 0 ;

}
