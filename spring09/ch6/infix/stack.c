/******************/
/* stack.c        */
/******************/

#include <stdio.h>
#include "globals.h"
#include "list.h"

typedef list stack;

status init_stack(stack *p_S){

   return init_list(p_S);
}

bool empty_stack(stack *p_S){

   return empty_list(*p_S);
}

status push(stack *p_S, generic_ptr data){

   return insert(p_S, data);
}

status pop(stack *p_S, generic_ptr *p_data){

   return delete(p_S, p_data);
}

status top(stack *p_S, generic_ptr *p_data){

   if (pop(p_S, p_data) == ERROR) return ERROR;

   return push(p_S, *p_data);
}

