/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 13: The abs Function                */
/*                                             */
/* Approximate completion time: 10 minutes     */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int num   ;

  printf("Please, enter in a number to see what its absolute value is. " ) ;

  scanf( "%d" , &num ) ;

  printf("The absolute value of the number you entered is %d. \n" , abs( num ) ) ;


  return 0 ;

}
