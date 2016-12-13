/********************************/
/* bestfit.c                   */
/********************************/
#include <stdio.h>
#include <stdlib.h>
#include "bestfit.h"
#include "print.h"

int bestfit ( int memsize ) {


  int memavaliable, elementsonfreelist, memchunk ;
  int i, seqnum, typeval, totalalloc = 0 ;
  char type[20] ;
  FILE *fp ;
  struct freelist *p ;
  listcounter = 0 ;
  totalfreespace = totalfree = (memsize*1024) ;

  for ( i = 0 ; i < NUMBERENTRIES ; i++ ) {
    reqarray[i].isreg = FALSE ;
    reqarray[i].isallocated = FALSE ;
  }

  if ( (top = malloc(sizeof(struct freelist))) == NULL ) {
    printf("Error") ;
    exit(1) ;
  }

  top->next = NULL ;
  top->prev = &listhead ;
  top->blocksize = totalfreespace ;
  top->blockadr = 0 ;
  top->adjacentadr = totalfreespace ;

  listhead.next = top ;
  listhead.prev = NULL ;
  listhead.blocksize = -1 ;

  fp = fopen( "./proj5data", "r" ) ;

  while ( fscanf( fp, "%d %s %d", &seqnum, type, &typeval ) != EOF ) {
    
    if ( strcmp( type, "alloc" ) == 0 ) {
      reqarray[seqnum].isreg = TRUE ;
      reqarray[seqnum].size = typeval ;
      bestallocatememory( &reqarray[seqnum] ) ;
      reqarray[seqnum].elementsonfreelist = 0 ;
      for ( p = listhead.next ; p ; p = p->next ) {
	++reqarray[seqnum].elementsonfreelist ;
	if ( p->blocksize > reqarray[seqnum].memchunk )
	  reqarray[seqnum].memchunk = p->blocksize ;
      }
    } else {
      reqarray[seqnum].size = reqarray[typeval].size ;
      reqarray[seqnum].isallocated = reqarray[typeval].isallocated ;
      updatelist( typeval ) ;
      reqarray[seqnum].memavaliable = totalfree ;
      reqarray[seqnum].elementsonfreelist = 0 ;
      reqarray[seqnum].memchunk = 0 ;
      for ( p = listhead.next ; p ; p = p->next ) {
	++reqarray[seqnum].elementsonfreelist ;
	if ( p->blocksize > reqarray[seqnum].memchunk ) {
	  reqarray[seqnum].memchunk = p->blocksize ;
	}
      }
    }
  }

  printarray( reqarray, "Best Fit", memsize) ;

  printf( "Completed.\n" ) ;

  return 0 ;
}
