#include "print.h"
#include "buddy.h"
#include <stdio.h>
#include <stdlib.h>

void printarray(struct request *reqarray, char *policy, int memsize){

  int i, errcount = 0;
  char temp[6];

  printf("\nMANAGEMENT POLICY: %s      POOL SIZE: %dk\n\n", policy, memsize);

  printf("\nSERIAL-NUM      REQUEST         SIZE    ALLOC-ADR       TOTAL-FREE      LARGEST-PART\n");
  for(i = 1; i < NUMBERENTRIES; i++){

    if(reqarray[i].isreg == TRUE)
      sprintf(temp, "%s", "alloc");
    else
      sprintf(temp, "%s", "free");
    
    if ( reqarray[i].isallocated == FALSE ) {
      reqarray[i].baseadr = -1;
      errcount++;
    }

    printf("\t%d \t%s \t\t%d \t%d \t\t%d \t\t%d\n", 
	   i, 
	   temp,
	   reqarray[i].size, 
	   reqarray[i].baseadr, 
	   reqarray[i].memoryleft, 
	   reqarray[i].largestchunk );
  }
  printf( "%d number of errors have occurred.\n\n", errcount/2 );
}

int bestallocatememory( struct request *req ) {
  
  struct freelist *p, *tmp;

  for ( p = listhead.next; p; p = p->next ) {

    if ( req->size <= p->blocksize ) {
      for ( tmp = p; tmp->next != NULL; tmp = tmp->next ) {
	if ( (req->size <= tmp->blocksize) && (tmp->blocksize > p->blocksize) )
	  p = tmp;
      }
      req->isallocated = TRUE;
      req->baseadr = p->blockadr;
      req->nextboundaryadr = req->baseadr + req->size;
      totalfree = totalfree - req->size;
      req->memoryleft = totalfree;
      if (( p->blocksize = p->blocksize - req->size ) == 0) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        return 0;
      }
      p->blockadr += req->size;
      return 0;
    }
  }

  req->memoryleft = totalfree;
  return 0;
}


int allocatememory( struct request *req ) {
  struct freelist *p;

  for ( p = listhead.next; p; p = p->next ) {
  
    if ( req->size <= p->blocksize ) {
      req->isallocated = TRUE;
      req->baseadr = p->blockadr;
      req->nextboundaryadr = req->baseadr + req->size;
      totalfree = totalfree - req->size;
      req->memoryleft = totalfree;
      if (( p->blocksize = p->blocksize - req->size ) == 0) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	return 0;
      }
      p->blockadr += req->size; 
      return 0;
    }
  }
  
  req->memoryleft = totalfree;
  return 0;
}

int updatelist( int arrayindex ) {
  struct freelist *p, *q, *r;

  if( reqarray[arrayindex].isallocated == FALSE ) return;
  
  reqarray[arrayindex].isallocated = DONE;
  totalfree = totalfree + reqarray[arrayindex].size;
  
  for ( p = listhead.next; p; p = p->next ) {
    if ( reqarray[arrayindex].baseadr > p->blockadr ) continue;
    if ( (q = malloc(sizeof(struct freelist))) == NULL ) {
      printf( "Error" );
      exit(1);
    } else {
      q->blocksize = reqarray[arrayindex].size;
      q->blockadr = reqarray[arrayindex].baseadr;
      q->adjacentadr = q->blockadr + q->blocksize;
      q->next = p;
      p->prev->next = q;
      q->prev = p->prev;
      p->prev = q;
    }

    if ( q->adjacentadr == q->next->blockadr ) {
      r = q->next;
      q->blocksize = q->next->blocksize + q->blocksize;
      q->adjacentadr = q->next->adjacentadr;
      q->next = r->next; 
      if ( q->next ) q->next->prev = q;
      free(r);
      return 0;
    }

    if ( q->prev->adjacentadr == q->blockadr ) {
      q->prev->blocksize = q->blocksize + q->prev->blocksize;
      q->prev->adjacentadr = q->adjacentadr;
      q->prev->next = q->next;
      if ( q->next ) q->next->prev = q->prev;
      free(q);
      return 0;
    }
    return 0;
  }
}
