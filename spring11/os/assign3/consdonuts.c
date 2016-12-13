/***********************************************/
/* Programmer: Eric Lima                       */
/*							       */
/* File: consdonuts.c				       */
/*				                        */
/* Date: March 23, 2011  	     		       */
/***********************************************/

#include "donuts.h"

int main(int argc, char *argv[]){

  int a, b, c, d, i, j, k, counter1, counter2, counter3, counter4;
  int shmid, semid[3];
  int temp[4][12];
  char time[40];
  long ms;
  struct donut_ring *shared_ring;
  struct timeval randtime;
  struct tm* ptm;
  FILE *fin;
  
  for(b = 0; b < 4; b++){
      for(c = 0; c < 12; c++){
	temp[b][c] = 0;
      }
  }

    if((shmid = shmget (MEMKEY, 0, 0)) == -1){
	  perror("The consumer shared get has failed. ");
	  exit(1);
  }

  if((shared_ring = (struct donut_ring *) 
			   shmat (shmid, NULL, 0)) == -1){
	  perror("The consumer shared attach failed. ");
	  exit(1);
  }

  for ( i=0; i < NUMSEMIDS; i++ ) 
    if ( (semid[i] = semget (SEMKEY+i, NUMFLAVORS, IPC_CREAT | 0600 ) ) == -1 ) {
      perror( "The consumer::sem attach has failed." );
      exit(1);
    }

  for(i = 0; i < 10; i++){
    counter1 = 0;
    counter2 = 0;
    counter3 = 0;
    counter4 = 0;
    counter = 0;
    for( j = 0; j < 12; j++){      

      gettimeofday (&randtime, (struct timezone *)0);
      unsigned short xsub1[3];
      xsub1[0] = (ushort) randtime.tv_usec;
      xsub1[1] = (ushort)(randtime.tv_usec >> 16);
      xsub1[2] = (ushort)(getpid());
      k = nrand48(xsub1) & 3;
      
      if ( p(semid[CONSUMER], k) == -1 ) {
	perror( " The consumer::consumer p operation has failed." );
	exit(1);
      }
      if ( p(semid[OUTPTR], k) == -1 ) {
	perror( "The consumer::outptr p operation has failed." );
	exit(1);
      }

      a = shared_ring->flavor[k][shared_ring->outptr[k]];     
      shared_ring->outptr[k] = (shared_ring->outptr[k] + 1) % NUMSLOTS;
      
      switch(k){
      case 0:
	{
	  temp[k][counter1] = a;
	  counter1 = counter1 + 1;
	  break;
	}
      case 1:
        {
	  temp[k][counter2] = a;
	  counter2 = counter2 + 1;
	  break;
	}
      case 2:
        {
	  temp[k][counter3] = a;
	  counter3 = counter3 + 1;
	  break;
	}
      case 3:
        {
	  temp[k][counter4] = a;
	  counter4 = counter4 + 1;
	  break;
	}      
      }  

      if ( v(semid[OUTPTR], k) == -1 ) {
	perror( " The consumer::outptr v operation has failed.");
	exit(1);
      }
      if ( v(semid[PROD], k) == -1 ) {
	perror( " The consumer::producer v operation has failed." );
	exit(1);
      }
      
      
    }
    ptm = localtime (&randtime.tv_sec);
    strftime (time, sizeof (time), "%H:%M:%S", ptm);
    ms = randtime.tv_usec / 1000;    


printf("\n\nProcess PID: %d\nTime: %s.%031d\nDozen: %d\n", getpid(), time,ms, ++i);

    printf("Plain \tJelly \tCoconut \tHoney-dip\n");
    for ( d = 0; d < 12; d++){ 

       if ( temp[0][d] == 0 ) printf( " \t" );
       else printf( "%d\t", temp[0][d] );
       
       if ( temp[1][d] == 0 ) printf( " \t" );
       else printf( "%d\t", temp[1][d] );
       
       if ( temp[2][d] == 0 ) printf( " \t" );
       else printf( "%d\t", temp[2][d] );
       
       if ( temp[3][d] == 0 ) printf( " \t" );
       else printf( "%d\t", temp[3][d] );
       
     }    

    for(b = 0; b < 4; b++){
      for(c = 0; c < 12; c++){
	temp[b][c] = 0;
      }
    }

  } 

  return 0;

}
