/**********************************************/
/* eventsubsystem.c                           */
/**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "eventsubsystem.h"
#include "globals.h"
#include "queue_interface.h"
#include "statisticalsubsystem.h"

#define MEANSUBMIT 8
#define MEANRUN 15
#define CPULIMIT 20

static int systemclock ;
static int EventTable[MAXEVENTS] ;

#define UNUSED 1000 ;

typedef struct {
  int basetime ;
  int elapsedtime ;
  int runtime ;
} job ;

static job currentjob ;

void init_events() {

  long now ;

  srand(time(&now)) ;

  EventTable[SUBMITONE] = expdistr(MEANSUBMIT) ;
  EventTable[SUBMITTWO] = expdistr(MEANSUBMIT) ;
  EventTable[CPUTIMEOUT] = UNUSED ;
  systemclock = 0 ;
  currentjob.runtime = 0 ;
}
int next_entry() {
  
  int event = 0 ;
  int i ;
  
  for (i=1 ; i < MAXEVENTS ; i++ )
    if ( EventTable[i] < EventTable[event])
      event = i ;
  
  advance_clock(EventTable[event]);
  return event ;

}
  
int advance_clock(int incr) {

  int i ;

  for ( i = 0 ; i < MAXEVENTS ; EventTable[i++] -= incr ) ;
  return systemclock += incr ;
}
status submitjob(queue p_Q, int event) {

  if (qadd_job(p_Q, systemclock, O, expdistr(MEANRUN)) == ERROR)
    return ERROR ;

  printf("%5d Submitting job\n", systemclock ) ;
  EventTable[event] = expdistr(MEANSUBMIT) ;
  return startjob(p_Q);
}

status startjob( queue *p_Q ) {

  int base, elapse, runtime ;

  if ( currentjob, runtime != 0 ) return OK ;

  if ( empty_queue(p_Q) == TRUE ) 
    return OK ;

  if (qremove_job(p_Q, &base, &elapse, &runtime) == ERROR)
    return ERROR ;

  currentjob.runtime = runtime ;
  currentjob.elapsedtime = elapse + systemclock - base ;
  EventTable[CPUTIMEOUT] = CPULIMIT ;
  EventTable[JOBCOMPLETE] = runtime ;
  printf("%5d Starting job\n", systemclock ) ; 
  return OK ;
}

status finishjob( queue *p_Q ) {

  EventTable[CPUTIMEOUT] = UNUSED ;
  EventTable[JOBCOMPLETE] = UNUSED ;
  accumulate_stats(currentjob.elapsedtime ) ;
  currentjob.runtime = 0 ;
  printf("%5d Finishing job\n", systemclock ) ;
  return startjob(p_Q) ;
}

status requeuejob(queue *p_Q) {
  EventTable[CPUTIMEOUT] = UNUSED ;
  EventTable[JOBCOMPLETE] = UNUSED ;
  if (qadd_job(p_Q, systemclock, currentjob.elapsedtime, currentjob.runtime - CPULIMIT) == ERROR )
    return ERROR ;
  currentjob.runtime = 0 ;
  printf("%5d Requeueing job\n", systemclock ) ;
  return startjob(p_Q) ;
}

int expdistr( int meantime ) {

  return (int) (-meantime * log( ( double ) rand() / RAND_MAX )) ;

}
