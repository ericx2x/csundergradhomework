#include "queue_interface.h"

typedef struct {
  int basetime;
  int elapsedtime;
  int runtime;
} job ;

status qadd_job(queue *p_Q, int base, int elapse, int run ){
  job *p_j = (job * ) malloc(sizeof(job));
  
  if(p_j == NULL )
    return ERROR ;
  
  p_j->basetime = base ;
  p_j->elapsedtime = elapse ;
  p_j->runtime = run ;
  
  if(qadd(p_Q, (generic_ptr) p_j) == ERROR ) {
    free(p_j);
    return ERROR ;
  }
  return OK ;
}

status qremove_job(queue *p_Q, int *p_base, int *p_elapse, int *p_run ) {
  
  job *p_j ;
  
  if(qremove(p_Q, (generic_ptr * ) &p_j) == ERROR )
    return ERROR ;
  
  *p_base = p_j->basetime;
  *p_elapse = p_j->elapsedtime;
  *p_run=p_j->runtime;
  
  free(p_j) ;
  return OK ;
}
