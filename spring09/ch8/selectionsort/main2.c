/*******************************************************************/
/* Programmer: Eric J Lima                                         */
/*                                                                 */
/* Program: Using Polymorphic Selection Sort to Sort Four Integers */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "globals.h"
#include "selection.h"

int int_compare( generic_ptr x, generic_ptr y ) {

  if ( * (int *) x <  *(int *) y ) return -1 ;
  if ( * (int *) x == *(int *) y ) return  0 ;
  return 1 ;

}

int main( int argc, char *argv[] ) {

  int i ;
  int *data[4] ;

  data[0] = ( int * ) malloc( sizeof( int ) ) ;
  data[1] = ( int * ) malloc( sizeof( int ) ) ;
  data[2] = ( int * ) malloc( sizeof( int ) ) ;
  data[3] = ( int * ) malloc( sizeof( int ) ) ;

  *data[0] = 6 ;
  *data[1] = 511 ;
  *data[2] = 4 ;
  *data[3] = 32 ;

  selection_sort( ( generic_ptr *) data, 4, int_compare ) ;

  for( i = 0 ; i < 4 ; i++ ) printf("%d\n", *data[i] ) ;

  return 0 ;

}
