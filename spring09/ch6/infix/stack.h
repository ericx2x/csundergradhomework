/*************************/
/* stack.h               */
/*************************/

#ifndef _stack
#define _stack

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

#define current_stacksize(p_S) ((p_S)->top - (p_S)->base)
#define STACKINCREMENT 100

typedef struct {
   generic_ptr *base;
   generic_ptr *top;
   int stacksize;
} stack;

status init_stack(stack *p_S);
bool empty_stack(stack *p_S);
status push(stack *p_S, generic_ptr data);
status pop(stack *p_S, generic_ptr *p_data);
status top(stack *p_S, generic_ptr *p_data);

#endif
