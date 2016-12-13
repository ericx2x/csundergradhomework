/*********************************************/
/* INITIAL PART OF PRODUCER.....             */
/*********************************************/

void	*producer ( void *arg )
{
  int			i, j, k;
  unsigned short 	xsub [3];
  struct timeval 	randtime;
  
  gettimeofday ( &randtime, ( struct timezone * ) 0 );
  xsub [0] = ( ushort )randtime.tv_usec;
  xsub [1] = ( ushort ) ( randtime.tv_usec >> 16 );
  xsub [2] = ( ushort ) ( pthread_self );
  
  while ( 1 ) {
    j = nrand48 ( xsub ) & 3;
    pthread_mutex_lock ( &prod [j] );
    while ( shared_ring.spaces [j] == 0 ) {
      pthread_cond_wait ( &prod_cond [j], &prod [j] );
    }
    
    shared_ring.serial[j] = shared_ring.serial[j] + 1;
    shared_ring.flavor[j][shared_ring.in_ptr[j]] = shared_ring.serial[j];
    shared_ring.in_ptr[j] = (shared_ring.in_ptr[j]) + 1 % NUMSLOTS;
    shared_ring.spaces[j] = shared_ring.spaces[j] - 1;
    pthread_mutex_unlock ( &prod [j] );
    
    pthread_mutex_lock ( &cons[j] );
    shared_ring.donuts[j] = shared_ring.donuts[j] + 1;
    pthread_mutex_unlock ( &cons[j] );
    pthread_cond_signal( &cons_cond[j] );
  }
    
  return NULL;
}



/*********************************************/
/* CONSUMER                                  */
/*********************************************/



void    *consumer ( void *arg )
{

  extern int counter;
  counter++;
  int thread = counter;
  char *name = (char*)malloc(sizeof(char)*10);
  sprintf(name, "consumer%d", counter);

  int     		i, j, k, m, x, id, u, o, q;
  unsigned short 	xsub [3];
  struct timeval 	randtime;
  int temp[4][12];
  int counter1 = 0;
  int counter2 = 0;
  int counter3 = 0;
  int counter4 = 0;
  struct tm* ptm;
  char timevar[40];
  long milliseconds;
  FILE *fp = fopen(name, "w");

  id = *( int * ) arg;
  gettimeofday ( &randtime, ( struct timezone * ) 0 );
  xsub [0] = ( ushort )randtime.tv_usec;
  xsub [1] = ( ushort ) ( randtime.tv_usec >> 16 );
  xsub [2] = ( ushort ) ( pthread_self );
  
  for( i = 0; i < 200; i++ ) {
    counter1 = 0;
    counter2 = 0;
    counter3 = 0;
    counter4 = 0;
    for( m = 0; m < 12; m++ ) {
      
      j = nrand48( xsub ) & 3;
      
      pthread_mutex_lock ( &cons [j] );
      
      while ( shared_ring.donuts [j] == 0 ) {
	pthread_cond_wait ( &cons_cond [j], &cons [j] );
      }
      
      x = shared_ring.flavor[j][shared_ring.outptr[j]];     
      
      switch(j){
      case 0:
	{
	  temp[j][counter1] = x;
	  counter1 = counter1 + 1;
	  break;
	}
      case 1:
        {
	  temp[j][counter2] = x;
	  counter2 = counter2 + 1;
	  break;
	}
      case 2:
        {
	  temp[j][counter3] = x;
	  counter3 = counter3 + 1;
	  break;
	}
      case 3:
        {
	  temp[j][counter4] = x;
	  counter4 = counter4 + 1;
	  break;
	}      
      } 

      if(shared_ring.outptr[j] >= NUMSLOTS)
	shared_ring.outptr[j] = 0;
      else
	shared_ring.outptr[j] = shared_ring.outptr[j] + 1; 

      shared_ring.donuts [j] = shared_ring.donuts [j] - 1;
      pthread_mutex_unlock ( &cons [j] );
      
      pthread_mutex_lock ( &prod [j] );
      shared_ring.spaces [j] = shared_ring.spaces [j] + 1;
      pthread_mutex_unlock ( &prod [j] );
      pthread_cond_signal(&prod_cond [j]);
    }

    if ( thread < 11){
      ptm = localtime (&randtime.tv_sec);
      strftime (timevar, sizeof (timevar), "%H:%M:%S", ptm);
      milliseconds = randtime.tv_usec / 1000;

      fprintf(fp, "\n\nThread : %d     ", thread);
      fprintf(fp, "time: %s.%03ld     ", timevar, milliseconds);                
      fprintf(fp, "dozen#: %d\n", i+1);

      fprintf(fp, "Plain \tJelly \tCoconut \tHoney-dip\n");
      for (q = 0; q < 12; q++){
	fprintf(fp, "%d \t%d \t%d \t\t%d\n", 
              temp[0][q], 
              temp[1][q], 
              temp[2][q], 
              temp[3][q]);
      }
      for(u = 0; u < 4; u++){
	for(o = 0; o < 12; o++){
	  temp[u][o] = 0;
	}
      }
    }
        
    usleep(1000);
  }
  fclose(fp);
  return NULL;
}

