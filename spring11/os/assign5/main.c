/**************************/
/* main.c                */
/*************************/

#include <stdio.h>
#include <stdlib.h>

#include "firstfit.h"
#include "bestfit.h"
#include "buddy.h"

int main ( int argc, char *argv[] ) {

  if ( strcmp( argv[1], "First") == 0 ) { firstfit( atoi(argv[2] )) ; return 0 ; }
  if ( strcmp( argv[1], "Best Fit") == 0 )  { bestfit(  atoi(argv[2] )) ; return 0 ; }
  if ( strcmp( argv[1], "Buddy") == 0 ) { buddyfunc( atoi(argv[2] )) ; return 0 ; }
  
  printf( "Error: %s\n\n", argv[1] ) ;

  return 0 ;
}
