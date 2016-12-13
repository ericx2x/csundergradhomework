/*********************/
/* tree.h            */
/*********************/

#ifndef _bintree
#define _bintree

#include <stdio.h>
#include "globals.h"

typedef struct tree_node tree_node, *tree;

struct tree_node {
   generic_ptr datapointer;
   tree left;
   tree right;
};

typedef enum { PREORDER, INORDER, POSTORDER, LEVEL } ORDER;


status allocate_tree_node(tree *p_T, generic_ptr data);
void free_tree_node(tree *p_T);
status init_tree(tree *p_T);
bool empty_tree(tree T);
status make_root(tree *p_T, generic_ptr data, tree left, tree right);
void destroy_tree(tree *p_T, void (*p_func_f)());
status bst_insert(tree *p_T, generic_ptr data, int (*p_cmp_f)());
status traverse_tree(tree T, status (*p_func_f)(), ORDER order);
extern status bst_insert( tree *p_T, generic_ptr data, int ( *p_cmp_func)()) ;
extern status bst_delete( tree *p_T, generic_ptr key, int (*p_cmp_f)(), generic_ptr *p_match ) ;

#endif
