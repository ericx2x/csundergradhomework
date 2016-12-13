/*********************************************/
/* Programmer: Eric Lima                     */
/*                                           */
/* Program: Ackermann's Function             */
/*                                           */
/* Time to complete: 25 mins                 */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>

int mann(int x, int y ) {

  if (x == 0)
    return y + 1;
  else if (y == 0)
    return mann(x - 1, 1);
  else
    return mann(x - 1, mann(x, y - 1));

}

int main( int argc, char *argv[] ) {

int x, y;

printf("Please, enter in two numbers.\n") ;
scanf( "%d%d", &x, &y ) ;

printf("The answer is %d.\n", mann( x, y ) ) ;

 return 0 ;

}
