/*******************/
/* interface.h     */
/*******************/

#ifndef _interface
#define _interface

#include "globals.h"
#include "stack.h"

typedef struct {
   int x, y;
} point;

status push_xy(stack *p_S, int x, int y);
status pop_xy(stack *p_S, int *p_x, int *p_y);

#endif
