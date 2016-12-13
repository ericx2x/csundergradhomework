/**************************************************************************/
/* Programmer: Jim Canning                                                */
/*                                                                        */
/* This is a test driver to see if you have copylist and appendlist       */
/* working. You should review this code. If there is something about      */
/* this code that you do not understand then you should ask a question.   */
/*                                                                        */
/* It is your job to be able to read and understand this code.            */
/**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "globals.h"
#include "list.h"

status  write_int( generic_ptr p_n ) {

  printf(" %d ", *(int *) p_n ) ;
  return OK ;

}

int main ( int argc, char *argv[] ) {

  list L1, L2                        ;
  int   *data                        ;
  int   n                            ;
  FILE *fin = fopen( argv[1] , "r" ) ;

  init_list ( &L1 ) ;
  init_list ( &L2 ) ;

  while ( fscanf( fin, "%d", &n ) != EOF ) {

    data = ( int * ) malloc( sizeof(int) ) ;
    *data = n ; 
    insert( &L1, (generic_ptr) data ) ;

  }
  printf("\nList 1: ") ; traverse( L1, write_int ) ;

  printf("\nNow we make a copy of List 1.\n") ;
  copylist( L1, &L2, sizeof( int ) ) ;

  printf("\nList 2: ") ; traverse( L2, write_int ) ;

  printf("\nNow we append List 1 to the end of List 2.") ;
  appendlist( &L1, &L2 ) ;

  printf("\nList 1: ") ;  traverse( L1, write_int ) ;
 
  printf("\nList 2: ") ; traverse( L2, write_int ) ;
  printf("\n");

  fclose( fin ) ;
  return 0 ;

}
