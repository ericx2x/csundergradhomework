/*************************/
/* queue.h               */
/*************************/

#ifndef _queue
#define _queue

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "list.h"

typedef list queue;

status init_queue( queue *p_Q );
bool empty_queue( queue *p_Q );
status qadd( queue *p_Q, generic_ptr data );
status qremove( queue *p_Q, generic_ptr *p_data );

#endif
