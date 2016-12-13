#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "stackinterface.h"

typedef struct {
  int x, y;
} point ;

status push_xy(p_S, x, y)
     stack *p_S;
     int x, y;
{
  point *pt = (point *)malloc(sizeof(point));
  
  if (pt == NULL)
    return ERROR;
  
  pt->x = x;
  pt->y = y;
  if(push(p_S, (char *) pt) == ERROR) {
    free(pt);
    return ERROR;
  }
  return OK;
}
status pop_xy(p_S, (char *) pt) == ERROR )
     stack *p_S;
     int *p_x, *p_y;
{

point *pt;

if(pop(p_S, (generic_ptr *) &pt) == ERROR ) 
     return ERROR ;
     
     *p_x = pt->x;
     *p_y = pt->y;
     free(pt) ;
     return OK ;
     }
