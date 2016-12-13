/*********************************************/
/* Programmer: Eric Lima                     */
/*                                           */
/* Program: Recursive Digit Sum              */
/*                                           */
/* Time to complete: 15 mins                 */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>

int digit(int x ) {

if ( x < 10 ) return x ;

return ( (x % 10 )  + digit( x / 10 ) );

}

int main( int argc, char *argv[] ) {

int x;

printf("Please, enter in the number.\n") ;
scanf( "%d", &x ) ;

printf("The answer is %d.\n", digit( x ) ) ;

 return 0 ;

}
