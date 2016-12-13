/***********************/
/* job_interface.h     */
/***********************/

#ifndef _jobinterface
#define _jobinterface

#include <stdio.h>
#include "globals.h"
#include "job.h"
#include "queue.h"

status qadd_job( queue *p_Q, int base, int elapse, int run );
status qremove_job( queue *p_Q, int *p_base, int *p_elapse, int *p_run );

#endif
