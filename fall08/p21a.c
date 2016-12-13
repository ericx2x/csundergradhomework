/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 20: Scanf Returns What?             */
/*                                             */
/* Approximate completion time:  30 minutes    */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  FILE *fin ;
  int x  , y[15]   ;

  fin = fopen( "testdata20" , "r" ) ;

  while( fscanf( fin , "%d" , &x)  != EOF ) {
    printf( "%d\n" , x ) ;
  }
  for( y= 14 ; y >= 0 ; y--) {
    printf("%d",y[x]
  }

  fclose( fin ) ;


  return 0 ;

}
