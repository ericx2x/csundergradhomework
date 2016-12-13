/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 76: Fun with Subtraction                                          */
/*                                                                           */
/* Approximate completion time: 53 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
  
  int corna, cornb, cornc, cornd, temp, count = 1 ;
  
  printf( "Please, insert the corners of the square at the upper right hand corner and continue clockwise. \n" ) ;

  printf( "Start             %d %d %d %d \n", corna, cornb, cornc, cornd )   ;
  
  while( 1 ) {

    if( ( corna == cornb ) && ( corna == cornc ) && ( corna == cornd ) )

      break ;

    temp = corna ;

    corna = abs( corna - cornb ) ;

    cornb = abs( cornb - cornc ) ;
    
    cornc = abs( cornc - cornd ) ;
    
    cornd = abs( cornd - temp )  ;
    
    printf( "Difference -%d     %d %d %d %d \n", count, corna, cornb, cornc, cornd ) ;
    
    count++ ;
  }
  
  return 0 ;
}
