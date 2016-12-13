/*********************************************/
/*                                           */
/* queue.c //                                */
/*                                           */
/* Eric Lima                                 */
/* 26 MARCH 2009                             */
/*                                           */
/*********************************************/
#include <stdlib.h>
#include <stdio.h> /*Get rid of */
#include "globals.h"
#include "queue.h"
#include "list.h"

extern status qprint( queue *p_Q, status printnum() ) {

  queue *tmpqueue = NULL ; 
  
  /*  for (tmpqueue = p_Q; tmpqueue!=NULL; tmpqueue=NEXT(*tmpqueue)) {*/

  while( ( tmpqueue = list_iterator( *p_Q, tmpqueue )) != NULL ){
    
    printnum( DATA (*tmpqueue) ) ;
    /*    printf("%d", (int)*DATA(*tmpqueue)) ; */
    
  }

  return OK ;

}

extern status init_queue( queue *p_Q)
{
  return init_list(p_Q) ;

}

extern bool empty_queue( queue *p_Q ) 
{
  return empty_list(*p_Q) ;
}

extern status qadd(queue *p_Q, generic_ptr data) {

  return append(p_Q, data ) ;

}

extern status qremove(queue *p_Q, generic_ptr *p_data ) {

  return delete( p_Q, p_data) ;

}
