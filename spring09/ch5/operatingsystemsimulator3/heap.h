/*****************************************/
/* heap.h                                */
/*****************************************/

#ifndef _heap
#define _heap

#define HEAPINCREMENT 128

#include "globals.h"

typedef struct { generic_ptr *base; int nextelement; int heapsize ; } heap ;

extern status init_heap( heap *p_H ) ;
extern bool   empty_heap( heap *p_H ) ;
extern status heap_insert( heap *p_H , generic_ptr data , int (*p_cmp_f) () ) ;
extern status heap_delete( heap *p_H, int element, generic_ptr *p_data, int (*p_cmp_f)() ) ;

#endif

