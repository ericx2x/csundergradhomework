/************************/
/* treeinterface.h      */
/************************/

#include <stdio.h>
#include "globals.h"
#include "tree.h"

status number_bst_insert (tree *T, int n, int (*p_cmp_f)());
