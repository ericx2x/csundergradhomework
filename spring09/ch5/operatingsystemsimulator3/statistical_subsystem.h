/***************************/
/* statistical_subsystem.h */
/***************************/

#ifndef _statsubsys
#define _statsubsys

#include <stdio.h>
#include <stdlib.h>

void init_stats();
void accumulate_stats( int qtime );
void print_stats();
int jobscompleted();

#endif
