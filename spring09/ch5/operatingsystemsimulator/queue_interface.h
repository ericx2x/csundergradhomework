/******************************************/
/* queue_interface.h                      */
/******************************************/
#ifndef _queueinterface
#define _queueinterface

#include "queue.h"

extern status qadd_job (queue *p_Q, int base, int elapse, int run ) ;

extern status qremove_job (queue *p_Q, int *p_base, int *p_elapse, int *p_run);

#endif
