/*********************************************/
/* Programmer: Eric Lima                     */
/*                                           */
/* Program: Combination                      */
/*                                           */
/* Time to complete: 15 mins                 */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>

int combo(int x, int y ) {

if ( x == 0 || y == 0 || y == x ) return 1 ;

return ( combo( x - 1, y ) + combo( x - 1, y - 1 ) );

}

int main( int argc, char *argv[] ) {

int x, y;

printf("Please, enter in two numbers.\n") ;
scanf( "%d%d", &x, &y ) ;

printf("The answer is %d.\n", combo( x, y ) ) ;

 return 0 ;

}
