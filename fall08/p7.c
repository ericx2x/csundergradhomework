/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 7: Bigger than 100?                 */
/*                                             */
/* Approximate completion time: 5 minutes      */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int code ;

  printf( "Please, input your number to check if it is bigger than 100.\n" ) ;

  scanf( "%d" , &code ) ;

  if ( code > 100 )
    printf( "The number is bigger than 100.\n" ) ;

  else 
    printf( "The number is not bigger than 100. \n") ;

  return 0 ;

}
