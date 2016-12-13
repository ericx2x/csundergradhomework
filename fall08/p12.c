/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 12: Positive, Negative, or Zero?    */
/*                                             */
/* Approximate completion time: 3 minutes      */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int num ; 

  printf( "Please, enter a number to check if it is \npositive, negative, or zero. " ) ;

  scanf( "%d" , &num ) ; 

  if( num == 0 ) printf("The number is zero.\n" ) ;
  else if( num > 0 ) printf( "The number is positive.\n" ) ;
  else printf("The number is negative.\n" ) ; 

  return 0 ;

}
