/*********************************************/
/* Programmer: Eric Lima                     */
/*                                           */
/* Program: Multiply with Recursive Addition */
/*                                           */
/* Time to complete: 15 mins                 */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>

int mult(int x, int y ) {

if ( y == 1 ) return x ;

return ( x + mult(x, --y) );

}

int main( int argc, char *argv[] ) {

int x, y;

printf("Please, enter in two numbers.\n") ;
scanf( "%d%d", &x, &y ) ;

printf("The answer is %d.\n", mult( x, y ) ) ;

 return 0 ;

}
