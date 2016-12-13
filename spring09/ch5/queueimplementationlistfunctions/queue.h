#ifndef _queue
#define _queue

#include "globals.h"
#include "list.h"
typedef list queue ;

extern status qprintf( queue *p_Q, status printnum() ) ;

extern status init_queue(queue *p_Q) ;

extern bool empty_queue( queue *p_Q ) ;

extern status qadd(queue *p_Q, generic_ptr data) ;

extern status qremove(queue *p_Q, generic_ptr *p_data ) ;

extern status allocate_node(queue *p_L, generic_ptr data) ;

extern void free_node(queue *p_L) ;

extern status delete_node(queue *p_L, queue node) ;

#endif
