#define SUBMITONE 0 
#define SUBMITTWO 1
#define JOBCOMPLETE 2
#define CPUTIMEOUT 3

#define MAXEVENTS 4

main() {

  queue cpuq ;
  int entry ;

  init_events() ;
  init_stats() ;
  init_queue(&cpuq) ;

  while (jobscompleted() < 100 ) {
    switch (entry = next_entry()) {
    case SUBMITONE:
    case SUBMITTWO:
      submitjob(&cpuq, entry ) ;
      break ;
    case JOBCOMPLETE:
      finishjob(&cpuq);
      break;
    case CPUTIMEOUT:
      requeuejob(&cpuq);
      break;
    }
  }
  print_stats();
}

