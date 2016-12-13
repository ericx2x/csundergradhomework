/***************************/
/* statistical_subsystem.c */
/***************************/

#include <stdio.h>
#include <stdlib.h>
#include "statistical_subsystem.h"

static long total_qtime;
static int jobcount;

void init_stats(){

   total_qtime = 0;
   jobcount = 0;

   return;
}
void accumulate_stats( int qtime ){

   jobcount++;
   total_qtime += qtime;

   return;
}

void print_stats(){
   
   printf("%-10s%-10s%s\n", " ", "Total", "Average");
   printf("%-10s%-10ld%.2f\n", "CPU Q:", total_qtime, total_qtime / (float) jobcount );

   return;
}

int jobscompleted(){

   return jobcount;
}
