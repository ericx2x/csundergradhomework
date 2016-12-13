/***************************************************************/
/* main.c                                                      */
/*                                                             */
/* This main.c must be used for the tree traversal assignment. */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "treeprimitives.h"
#include "treeinterface.h"

status write_number ( int *a ) {

  printf(" %d ", *a ) ;
  return OK ;

}

int compare_numbers ( int *a , int *b ) {

  if ( *a < *b ) return -1 ;
  if ( *a == *b ) return  0 ;
  if ( *a > *b  ) return  1 ;

}

int main ( int argc, char *argv[] ) {

  int i, n, number      ;
  tree T                ;

  printf("How many keys would you like to insert? ") ;
  scanf("%d", &n ) ;
  printf("The numbers are: ");
  init_tree ( &T ) ;

  for ( i = 1 ; i <= n ; i++ ) {

    number = rand() % 1000 + 1       ;
    printf(" %d ", number ) ;
    number_bst_insert( &T, number, compare_numbers ) ;  
  }

  printf("\n INORDER: ");      traverse_tree( T, write_number, INORDER ) ;
  printf("\n PREORDER:");      traverse_tree( T, write_number, PREORDER ) ;
  printf("\n POSTORDER: ");    traverse_tree( T, write_number, POSTORDER ) ;
  printf("\n LEVEL ORDER: ");  traverse_tree( T, write_number, LEVEL ) ;
  printf("\n");  

  return 0 ;

}
