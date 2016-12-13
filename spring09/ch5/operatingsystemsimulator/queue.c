/*************************/
/* queue.c               */
/*************************/

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "queue.h"
#include "list.h"

status init_queue( queue *p_Q ){
   return init_list( p_Q );
}

bool empty_queue( queue *p_Q ){
   return empty_list( *p_Q );
}

status qadd( queue *p_Q, generic_ptr data ){
   return append( p_Q, data );
}

status qremove( queue *p_Q, generic_ptr *p_data ){
   return delete( p_Q, p_data );
}
