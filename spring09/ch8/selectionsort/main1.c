/*******************************************************************/
/* Programmer: Eric J Lima                                         */
/*                                                                 */
/* Program: Using Polymorphic Selection Sort to Sort Four Integers */
/*******************************************************************/

#include <stdio.h>
#include <strings.h>
#include "selection.h"

int main( int argc, char *argv[] ) {

  int i ;
  int *data[] = { "foo", "bar", "hello", "goodbye" } ;

  selection_sort( data, 4, strcmp ) ;

  for( i = 0 ; i < 4 ; i++ ) printf("%s\n", *data[i] ) ;

  return 0 ;

}
