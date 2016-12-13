/************************************************************/
/* Programmer: Eric J Lima                                  */
/*                                                          */
/* Program: Selection Sorting of Four Words                 */
/************************************************************/

#include <stdio.h>
#include <strings.h>
#include "selection.h"

int main( int argc, char *argv[] ) {

  int i ;
  char *data[] = { "foo", "bar", "hello", "goodbye" } ;

  selection_sort( data, 4, strcmp ) ;

  for ( i = 0 ; i < 4 ; i++ ) printf( "%s\n", data[i] ) ;

  return 0 ;

}
