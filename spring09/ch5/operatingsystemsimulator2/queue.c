/*************************/
/* queue.c               */
/*************************/

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "queue.h"
#include "list.h"

status init_queue( queue *p_Q ){
   
   FRONT(p_Q) = NULL;
   REAR(p_Q) = NULL;

   return OK;
}

bool empty_queue( queue *p_Q ){

   return (FRONT(p_Q) == NULL) ? TRUE : FALSE;
}

status qadd( queue *p_Q, generic_ptr data ){

   list newnode;

   if (allocate_node(&newnode, data) == ERROR)
      return ERROR;

   if (empty_queue(p_Q) == FALSE){
      NEXT(REAR(p_Q)) = newnode;
      REAR(p_Q) = newnode;
   } else
      FRONT(p_Q) = REAR(p_Q) = newnode;

   return OK;
}

status qremove( queue *p_Q, generic_ptr *p_data ){

   list nodeinfront;

   if (empty_queue(p_Q) == TRUE)
      return ERROR;

   nodeinfront = FRONT(p_Q);
   *p_data = DATA(nodeinfront);

   if (REAR(p_Q) == FRONT(p_Q))
      REAR(p_Q) = FRONT(p_Q) = NULL;
   else
      FRONT(p_Q) = NEXT(nodeinfront);

   free_node(&nodeinfront);

   return OK;
}
