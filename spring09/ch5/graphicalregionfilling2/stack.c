/******************/
/* stack.c        */
/******************/

#include <stdio.h>
#include "globals.h"
#include "stack.h"
#include <stdlib.h>

status init_stack(stack *p_S){
   
   p_S->base = (generic_ptr *) malloc (STACKINCREMENT*sizeof(generic_ptr));
   if (p_S->base == NULL)
      return ERROR;

   p_S->top = p_S->base;
   p_S->stacksize = STACKINCREMENT;

   return OK;
}

bool empty_stack(stack *p_S){

   return (p_S->top == p_S->base) ? TRUE : FALSE;
}

status push(stack *p_S, generic_ptr data){

   if (current_stacksize(p_S) == p_S->stacksize) {

      generic_ptr *newstack = (generic_ptr *) realloc(p_S->base, (p_S->stacksize+STACKINCREMENT)*sizeof(generic_ptr *));

      if (newstack == NULL)
         return ERROR;

      p_S->base = newstack;
      p_S->top = p_S->base + p_S->stacksize;
      p_S->stacksize += STACKINCREMENT;
   }

   *p_S->top = data;
   p_S->top++;
   
   return OK;
}

status pop(stack *p_S, generic_ptr *p_data){

   if ( empty_stack(p_S) == TRUE ) return ERROR;

   (p_S -> top) -- ;

   *p_data = *p_S -> top;

   return OK;
}

status top(stack *p_S, generic_ptr *p_data){

   if (pop(p_S, p_data) == ERROR) return ERROR;

   return push(p_S, *p_data);
}

