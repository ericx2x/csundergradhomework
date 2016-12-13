/**************************/
/* buddy.h               */
/*************************/

#ifndef BUDDY
#define BUDDY

#include <stdio.h>
#include "print.h"

struct lel {
  struct lel *next ;
  struct lel *prev ;
  int adr ;
  int budadr ;
  int bit ;
}  ;

struct lh {
  struct lel *head ;
  int cnt ;
} graph[21] ;

struct buddyrequest {
  int isreq ;
  int isallocated ;
  int size ;
  int actsize ;
  int baseadr ;
  int nextboundaryadr ;
  int memoryleft ;
  int largestchunk ;
  int elementsonfreelist ;
  struct lel *thisreq ;
} buddyreqarray[ NUMBERENTRIES ] ;

int buddysys( int arg ) ;
int exponent( int size ) ;

struct lel *makelel( int adr ) ;

void buddyprintarray(struct buddyrequest *reqarray, char *policy, int memsize) ;

#endif
