/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 24: Reverse                         */
/*                                             */
/* Approximate completion time: 23 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int i ;

  for( i = argc ; i >= 0 ; i-- ) {

    printf( "%c\n" , argv[i] ) ;

  }
  

  return 0 ;

}
