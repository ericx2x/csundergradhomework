/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 15: Using the sqrt Function         */
/*                                             */
/* Approximate completion time: 15 minutes     */
/***********************************************/

#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] ) {

  float num ; 

  printf( "Please, enter a floating point number to find \nwhat the square root of that number is. " ) ;

  scanf( "%f" , &num ) ;

  printf( "The square root of the number you entered is %f.\n" , sqrt( num ) ) ;


  return 0 ;

}
