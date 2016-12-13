/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 34: Blank Removal                   */
/*                                             */
/* Approximate completion time: 43  minutes    */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int c ;
  FILE *fin        ;
 
  fin = fopen( argv[1], "r" ) ;

  while( ( c = fgetc( fin ) ) != EOF ) {

    if ( c != ' ') putchar( c ) ;  
      
  else if (c == ' ') {
    while( ( c == ' ' ) && ( c = fgetc( fin ) ) != EOF ) ;
	   putchar( ' ' ) ;
	   putchar( c ) ;

    }
  } 

  
  return 0 ;

}
