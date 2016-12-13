/*************************************/
/* treeinterface.c                   */
/*************************************/

#include "treeinterface.h"
#include <stdlib.h>

extern status number_bst_insert( tree *T, int a, int (*p_cmp_func)() ) {

  generic_ptr *c;

  c = ( generic_ptr ) malloc ( sizeof(int) );

  *(int*)c = a;

  bst_insert( T, c, p_cmp_func );

  return OK;

}

