#include "statisticalsubsystem.h"

static long total_qtime ;
static int jobcount ;

void init_stats() {

  total_qtime = 0 ;
  jobcount = 0 ;
}

void accumulate_stats(int qtime) {

  jobcount++;
  total_qtime += qtime ;
}

void print_stats(){

  printf("%-10s%s\n", " ", "Total", "Average");
  printf("%-10s%-10ld%.2f\n", "CPU Q:", total_qtime, total_qtime / (float) jobcount);
}

int jobscompleted(){
  return jobcount ;
}
