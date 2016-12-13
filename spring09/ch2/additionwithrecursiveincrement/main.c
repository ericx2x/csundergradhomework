/************************************************/
/* Programmer: Eric Lima                        */
/*                                              */
/* Program: Addition with Recursive Increment   */
/*                                              */
/* Time to complete: 15 mins                    */
/************************************************/

#include <stdio.h>
#include <stdlib.h>

int add(int x, int y ) {

if ( y == 0 ) return x ;

return ( add( ++x, --y) );

}

int main( int argc, char *argv[] ) {

int x, y;

printf("Please, enter in two numbers.\n") ;
scanf( "%d%d", &x, &y ) ;

printf("The answer is %d.\n", add( x, y ) ) ;

 return 0 ;

}
