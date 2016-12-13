#include <stdio.h>
#include "queue.h"
#include "event_subsystem.h"
#include "statistical_subsystem.h"

int main( int argc, char *argv[]){

   queue cpuq;
   int entry;

   init_events();
   init_stats();
   init_queue( &cpuq );

   while ( jobscompleted() < 100 ) {

      switch ( entry = next_entry() ) {

         case SUBMITONE:
         case SUBMITTWO:

            submitjob( &cpuq, entry );
            break;

         case JOBCOMPLETE:

            finishjob( &cpuq );
            break;

         case CPUTIMEOUT:

            requeuejob( &cpuq );
            break;

      }
   }

   print_stats();

   return 0;
}
