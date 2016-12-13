/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 23: fgetc and toupper               */
/*                                             */
/* Approximate completion time: 40 minutes     */
/***********************************************/

#include <stdio.h>
#include <ctype.h>

int main( int argc, char *argv[] ) {

  FILE *fin ;
  int c    ;


  fin = fopen( "testdata23" , "r" ) ;


  while( ( c = fgetc( fin ) ) != EOF ) {

    c = toupper( c ) ;

    putchar( c )     ;

  }

  fclose( fin ) ;

  return 0      ;

}
