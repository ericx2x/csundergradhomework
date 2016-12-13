/************************/
/* treeinterface.c      */
/************************/

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "tree.h"
#include "treeinterface.h"

status number_bst_insert (tree *p_T, int n, int (*p_cmp_f)()){

   int *p_int = (int *) malloc(sizeof(int));

   if (p_int == NULL)
      return ERROR;

   *p_int = n;

   bst_insert(p_T, (generic_ptr) p_int, p_cmp_f);

   return OK;
}
