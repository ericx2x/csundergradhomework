/*********************/
/* tree.c            */
/*********************/

#include <stdio.h>
#include "globals.h"
#include "tree.h"
#include "queue.h"

static status preorder_traverse(tree T, status (*p_func_f)());
static status inorder_traverse(tree T, status (*p_func_f)());
static status postorder_traverse(tree T, status (*p_func_f)());
static status level_traverse(tree T, status (*p_func_f)());

status allocate_tree_node(tree *p_T, generic_ptr data){

   tree T = (tree) malloc(sizeof(tree_node));

   if (T == NULL)
      return ERROR;

   *p_T = T;
   DATA(T) = data;
   LEFT(T) = NULL;
   RIGHT(T) = NULL;

   return OK;
}


void free_tree_node(tree *p_T){

   free(*p_T);
   *p_T = NULL;

   return;
}


status init_tree(tree *p_T){

   *p_T = NULL;
   
   return OK;
}


bool empty_tree(tree T){

   return (T == NULL) ? TRUE : FALSE;
}


status make_root(tree *p_T, generic_ptr data, tree left, tree right){

   if (empty_tree(*p_T) == FALSE)
      return ERROR;

   if (allocate_tree_node(p_T, data) == ERROR)
      return ERROR;

   LEFT(*p_T) = left;
   RIGHT(*p_T) = right;

   return OK;
}


void destroy_tree(tree *p_T, void (*p_func_f)()){

   if (empty_tree(*p_T) == FALSE){

      destroy_tree(&LEFT(*p_T), p_func_f);
      destroy_tree(&RIGHT(*p_T), p_func_f);

      if (p_func_f != NULL)
         (*p_func_f)(DATA(*p_T));
      
      free_tree_node(p_T);
   }
}


status bst_insert(tree *p_T, generic_ptr element, int (*p_cmp_f)()){

   tree T;
   int cmp;

   
   if (empty_tree (*p_T) == TRUE) {

      init_tree(&T);
      if (allocate_tree_node(&T, element) == ERROR)
         return ERROR;
      
      *p_T = T;

      return OK;
   }
   else {

      cmp = ((*p_cmp_f)(element, DATA(*p_T)));

      if (cmp < 0)
         return bst_insert(&LEFT(*p_T), element, p_cmp_f);
      else if (cmp > 0)
         return  bst_insert(&RIGHT(*p_T), element, p_cmp_f);
      else
         return OK;
   }
}


status traverse_tree(tree T, status (*p_func_f)(), ORDER order){

   switch (order) {
      case PREORDER:  return preorder_traverse(T, p_func_f);
      case INORDER:   return inorder_traverse(T, p_func_f);
      case POSTORDER: return postorder_traverse(T, p_func_f);
      case LEVEL:     return level_traverse(T, p_func_f);
   }

   return ERROR;
}


static status preorder_traverse(tree T, status (*p_func_f)()){

   status rc;

   if (empty_tree(T) == TRUE)
      return OK;

   /* preorder: visit, left, right */
   
   rc = (*p_func_f)(DATA(T));
   
   if (rc == OK)
      rc = preorder_traverse(LEFT(T), p_func_f);
   
   if (rc == OK)
      rc = preorder_traverse(RIGHT(T), p_func_f);

   return rc;
}


static status inorder_traverse(tree T, status (*p_func_f)()){

   status rc;

   if (empty_tree(T) == TRUE)
      return OK;

   /* inorder: left, visit, right */
   
   rc = inorder_traverse(LEFT(T), p_func_f);
   
   if(rc == OK)
      rc = (*p_func_f)(DATA(T));

   if (rc == OK)
      rc = inorder_traverse(RIGHT(T), p_func_f);

   return rc;
}


static status postorder_traverse(tree T, status (*p_func_f)()){

   status rc;

   if (empty_tree(T) == TRUE)
      return OK;

   /* postorder: left, right, visit */
   
   rc = postorder_traverse(LEFT(T), p_func_f);
   
   if (rc == OK)
      rc = postorder_traverse(RIGHT(T), p_func_f);

   if (rc == OK)
      rc = (*p_func_f)(DATA(T));
   
   return rc;
}


static status level_traverse(tree T, status (*p_func_f)()){

   queue Q;
   init_queue( &Q );
   
   qadd( &Q, (generic_ptr) T );

   while (empty_queue( &Q ) == FALSE){

      qremove (&Q, (generic_ptr) &T);

      (*p_func_f)(DATA(T));

      if (LEFT(T) != NULL)
         qadd( &Q, (generic_ptr) LEFT(T));

      if (RIGHT(T) != NULL)
         qadd( &Q, (generic_ptr) RIGHT(T));
   }
   
   return OK;
}
