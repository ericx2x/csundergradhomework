/***********************/
/* queue_interface.h   */
/***********************/

#ifndef _queueinterface
#define _queueinterface

typedef struct {
   int basetime;
   int elapsedtime;
   int runtime;
} job;

#include <stdio.h>
#include "globals.h"
#include "queue.h"
#include "heap.h"

status qadd_job( queue *p_Q, int base, int elapse, int run );
status qremove_job( queue *p_Q, int *p_base, int *p_elapse, int *p_run );

#endif
