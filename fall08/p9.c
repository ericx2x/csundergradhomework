/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 9: Using a For Loop                 */
/*                                             */
/* Approximate completion time: 31 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  FILE *fin ;

  int num , j ;

  fin = fopen( "testdata9" , "r");

  for( j = 0 ; j < 5 ; j++ ) {

    fscanf( fin , "%d" , &num );

    printf( "\n%d\n" , num ) ;

  }

  fclose( fin );

  return 0 ;

}
