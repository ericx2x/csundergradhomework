/**********************************************************/
/* eventsubsystem.h                                       */
/**********************************************************/

#ifndef _event
#define _event

#include "queue.h"

typedef struct { int basetime ; int elapsedtime ; int runtime ; } job ;

extern void int_events ( void ) ;
extern int next_entry ( void ) ;
extern int advance_clock (int incr ) ;
extern status submitjob ( queue *p_Q, int event ) ;
extern status startjob ( queue *p_Q ) ;
extern status finishjob ( queue *p_Q  ) ;
extern status requeuejob ( queue *p_Q ) ;
extern int expdistr ( int meantime ) ;

#endif
