/*********************/
/* interface.c       */
/*********************/

#include <stdio.h>
#include "globals.h"
#include "stack.h"
#include "interface.h"

status push_xy(stack *p_S, int x, int y){

   point *pt = (point *) malloc(sizeof(point));

   if(pt == NULL) return ERROR;

   pt->x = x;
   pt->y = y;

   if(push(p_S, (char *) pt) == ERROR) {
      free(pt);
      return ERROR;
   }

   pt->x = x;
   pt->y = y;

   if (push(p_S, (char *) pt) == ERROR) {
      free(pt);
      return ERROR;
   }

   return OK;
}


status pop_xy(stack *p_S, int *p_x, int *p_y){

   point *pt;

   if (pop(p_S, (generic_ptr *) &pt) == ERROR) return ERROR;

   *p_x = pt->x;
   *p_y = pt->y;

   free(pt);

   return OK;
}

