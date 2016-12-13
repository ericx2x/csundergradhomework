/**************************************************************************/
/* Programmer: Jim Canning                                                */
/*                                                                        */
/* This is a test driver to see if you have set_equal working.            */
/* You should review this code. If there is something about this code     */
/* that you do not understand then you should ask a question.             */
/*                                                                        */
/* It is your job to be able to read and understand this code.            */
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "list.h"

status write_int( generic_ptr p_n ) {

  printf(" %d ", *(int *) p_n ) ;
  return OK ;

}

int compare_int( int *x , int *y ) {

  if ( *x < *y ) return -1 ;
  if ( *x > *y ) return 1  ;
  return 0 ;

}


int main ( int argc, char *argv[] ) {

  list L1, L2                        ;
  int   n, num, i, *p_int            ;

  init_list ( &L1 ) ;
  init_list ( &L2 ) ;

  printf("\nHow many numbers are there in List 1? ");
  scanf("%d", &n ) ;

  for ( i = 1 ; i <= n ; i++ ) {

    printf( "\nEnter a number: " ) ;
    scanf( "%d", &num ) ;
    p_int = (int *) malloc( sizeof(int) ) ;
    *p_int = num ;
    append( &L1, (generic_ptr) p_int ) ;

  }

  printf("\nList 1: ") ; traverse( L1, write_int ) ;

  printf("\n\nHow many numbers are there in List 2? ");
  scanf("%d", &n ) ;

  for ( i = 1 ; i <= n ; i++ ) {

    printf( "\nEnter a number: " ) ;
    scanf( "%d", &num ) ;
    p_int = (int *) malloc( sizeof(int) ) ;
    *p_int = num ;
    append( &L2, (generic_ptr) p_int ) ;

  }

  printf("\n\nList 2: ") ; traverse( L2, write_int ) ;

  if ( set_equal( L1, L2, compare_int ) ) printf("\n\nThe two lists are set equal.\n\n") ;
  else printf("\n\nThe two lists are not set equal.\n\n");

  return 0 ;

}
