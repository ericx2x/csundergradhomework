#include "buddy.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gAllocbcount = 0;

int buddyfunc( int memsize ) {

  int sequencenumber, typeval, i, exponentnum;
  char type[20];
  struct lel *temp;
  FILE *fp;
  totalfreespace = totalfree = (memsize*1024);

   struct lel *first = makelel( 0 );

  for ( i = 0; i < 21; i++ )
    exponentfield[i].head = NULL;

  exponentfield[20].head = first;
  
  for ( i = 0; i < NUMBERENTRIES; i++ ) {
    buddyreqarray[i].isreq = FALSE;
    buddyreqarray[i].isallocated = FALSE;
  }

  fp = fopen( "./proj5data", "r" );

  while ( fscanf( fp, "%d %s %d", &sequencenumber, type, &typeval ) != EOF ) {

    if ( strcmp( type, "alloc" ) == 0 ) {
      buddyreqarray[sequencenumber].isreq = TRUE;
      buddyreqarray[sequencenumber].size = typeval;
      exponentnum = exponent(typeval);
      buddyreqarray[sequencenumber].actsize = exponentnum;
      temp = makelel( exponentnum );
      totalfree = totalfree - exponentnum3(2, exponentnum);
      buddyallocate( &buddyreqarray[sequencenumber], temp, exponentnum );
      buddyreqarray[sequencenumber].elementsonfreelist = 0;
     } else {
      buddyreqarray[sequencenumber].size = buddyreqarray[typeval].size;
      buddyreqarray[sequencenumber].isallocated = buddyreqarray[typeval].isallocated;
      buddyupdatelist( typeval );
      buddyreqarray[sequencenumber].memoryleft = totalfree;
      buddyreqarray[sequencenumber].elementsonfreelist = 0;
       }
  }

  buddyprintarray( buddyreqarray, "Buddy System", memsize);

  return 0;
}

struct lel *makelel( int adr ) {

  struct lel *tmp = (struct lel*)malloc(sizeof(struct lel));

  tmp->next = NULL;
  tmp->prev = NULL;
  tmp->adr = adr;
  tmp->budadr = -1;
  tmp->bit = 1; 
  return tmp;
}

int exponent( int size ) {

  int count = 0;
  double check = (double)size;

  while ( size > 1 ) {
    size = size/2;
    count++;
  }

  if ( exponentnum3(2, count) == check )
    return count;

  return ++count;
}

int buddyallocate( struct buddyrequest *req, struct lel *memory, int exponentnum ) {

  gAllocbcount++;

  int exponentnum2 = exponentnum;
  int tmpadr = 0;
  struct lel *counter = NULL;

  if ( totalfree < req->size ) {
    printf( "%d", totalfree );
    return;
  }



  if ( exponentfield[exponentnum].head != NULL )
    for ( counter = exponentfield[exponentnum].head; counter->next != NULL; counter = counter->next);

  if ( (exponentfield[exponentnum].head != NULL) && (counter->bit == 1)) {
    counter->bit = 0;
    req->thisreq = counter;    
    req->isallocated = TRUE;
    return 0;
  } else { 
      while( exponentnum2 < 22 ) {
      exponentnum2++; 
      if ( exponentfield[exponentnum2].head != NULL ) {
	for ( counter = exponentfield[exponentnum2].head; counter->next != NULL; counter = counter->next);
	if ( counter->bit == 0 ) {
	  tmpadr = counter->adr; 

	  if ( counter->prev != NULL )
	    counter->prev->next = NULL;
	  else 
	    exponentfield[exponentnum2].head == NULL;
	  free(counter); 

	  break;
	}
      }
    }
    while ( exponentnum2 != exponentnum ) {
      exponentnum2--;
      if ( exponentfield[exponentnum2].head != NULL ) { 
	for ( counter = exponentfield[exponentnum2].head; counter->next != NULL; counter = counter->next);



/*RAN OUT OF TIME*/
  
  return 0;
}

int buddyupdatelist( int arrayindex ) {

  int x = buddyreqarray[arrayindex].actsize;
  int i;
  struct lel *tmp = buddyreqarray[arrayindex].thisreq;

  if (tmp == NULL ) return;

  if ( buddyreqarray[arrayindex].isallocated == FALSE ) return;

  printf( "\nFree\n" );
  
  buddyreqarray[arrayindex].isallocated = DONE;
  totalfree = totalfree + (int)exponentnum3( 2, buddyreqarray[arrayindex].actsize);


  
  if ( tmp->next != NULL && tmp->prev != NULL) {
      
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;

  } else if ( tmp->next != NULL && tmp->prev == NULL ) {

    tmp->next->prev = NULL;
    exponentfield[x].head = tmp->next;
    
  } else if ( tmp->next == NULL && tmp->prev != NULL ) {

    tmp->prev->next = NULL;

  } else  {
    
    exponentfield[x].head = NULL;

  }
    
  if( buddyreqarray[arrayindex].thisreq->budadr != -1 ) {

    for ( i = 0; i < NUMBERENTRIES; i++ ) {
      if ( buddyreqarray[i].thisreq != NULL ) {
	if ( ( buddyreqarray[i].thisreq->adr == buddyreqarray[arrayindex].thisreq->budadr ) && ( i != arrayindex ) && (buddyreqarray[i].thisreq->bit == 1 ) ) {
	  buddyupdatelist( i );
	  break;
	}
      }
    }
    if ( i == NUMBERENTRIES -1 ) printf( "Alloc was not located\n\n");
  }
  
  free(tmp);
  buddyreqarray[arrayindex].thisreq = NULL;
  
  return 0;

}

void buddyprintarray(struct buddyrequest *reqarray, char *policy, int memsize){

  int i, errors = 0;
  char temp[6];

  printf("\nMANAGEMENT POLICY = %s      POOL SIZE = %dk\n\n", policy, memsize);

  printf("\nSERIAL-NUM      REQUEST         SIZE    ACTSIZE       THISREQ      BASEADR\n");
  for(i = 1; i < NUMBERENTRIES; i++){

    if(reqarray[i].isreq == TRUE)
      sprintf(temp, "%s", "alloc");
    else
      sprintf(temp, "%s", "free");

    if ( reqarray[i].isallocated == FALSE ) {
      reqarray[i].baseadr = -1;
      errors++;
    }

    printf("\t%d \t%s \t\t%d \t%0.0f \t\t%d \t\t%d\n",
           i,
           temp,
           reqarray[i].size,
           exponentnum3( 2, reqarray[i].actsize),
           reqarray[i].thisreq,
           reqarray[i].baseadr );
  }
  printf( "%d errors have occurred.\n\n", errors/2 );
}
