/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 24: Reverse                         */
/*                                             */
/* Approximate completion time: 23 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int i , j[10] ;

  for( i = 0 ; i < 10 ; i++ ) scanf( "%d" , &j[i] ) ;

  for( i = 9 ; i >= 0 ; i-- ) {

    printf( "%d\n" , j[i] ) ;

  }
  

  return 0 ;

}
