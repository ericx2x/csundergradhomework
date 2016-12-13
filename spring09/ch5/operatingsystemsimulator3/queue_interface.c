/***********************/
/* queue_interface.c   */
/***********************/

#include <stdio.h>
#include "globals.h"
#include "queue_interface.h"
#include "queue.h"
#include "heap.h"

static int cmp_runtime(job *p_job1, job *p_job2);

status qadd_job( queue *p_Q, int base, int elapse, int run ){

   job *p_j = (job *) malloc( sizeof(job) );

   if (p_j == NULL)
      return ERROR;

   p_j -> basetime = base;
   p_j -> elapsedtime = elapse;
   p_j -> runtime = run;

   if ( qadd(p_Q, (generic_ptr) p_j, cmp_runtime ) == ERROR){
      free(p_j);
      return ERROR;
   }

   return OK;
}


status qremove_job( queue *p_Q, int *p_base, int *p_elapse, int *p_run ){

   job *p_j;

   if (qremove(p_Q, (generic_ptr *) &p_j, cmp_runtime) == ERROR)
      return ERROR;

   *p_base = p_j -> basetime;
   *p_elapse = p_j -> elapsedtime;
   *p_run = p_j -> runtime;

   free(p_j);

   return OK;
}


static int cmp_runtime(job *p_job1, job *p_job2) {

   return p_job1 -> runtime - p_job2 -> runtime;
}
