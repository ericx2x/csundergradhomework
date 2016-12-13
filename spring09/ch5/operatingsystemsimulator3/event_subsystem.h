/*************************/
/* event_subsystem.h     */
/*************************/

#ifndef _eventsubsys
#define _eventsubsys

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "globals.h"
#include "queue.h"
#include "heap.h"
#include "queue_interface.h"
#include "event_subsystem.h"
#include "statistical_subsystem.h"

#define SUBMITONE 0
#define SUBMITTWO 1
#define JOBCOMPLETE 2
#define CPUTIMEOUT 3

#define MAXEVENTS 4

void init_events();
int next_entry();
int advance_clock( int incr );
status submitjob( queue *p_Q, int event);
status startjob( queue *p_Q );
status finishjob( queue *p_Q );
status requeuejob( queue *p_Q );
int expdistr( int meantime );

#endif
