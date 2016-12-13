/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 16: Area of a Rectangle             */
/*                                             */
/* Approximate completion time: 15 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  float height , length , area ;

  printf("Please, enter a length and a height of the \nrectangle to find its area. " ) ;

  scanf( "%f%f" , &length, &height ) ;

  area = length * height ;

  printf( "The area of the rectangle with the height and\n length you entered is %f.\n" , area ) ;


  return 0 ;

}
