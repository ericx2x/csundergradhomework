/***********************************************************************************/
/* numberinterface.c                                                               */
/***********************************************************************************/

#include <stdlib.h>
#include "numberinterface.h"
#include "globals.h"
#include "list.h"

extern status appendanumber( list *p_L , int n ) {

  int *t_ptr ;

  t_ptr = ( generic_ptr )malloc(sizeof(generic_ptr)) ;

  *t_ptr = n ;

  append ( p_L , t_ptr ) ; 

  return OK ;

}


extern status getnextnumber( list *p_L, int *p_n ) {

  int **temp ;

  temp = ( int ** ) malloc ( sizeof ( int ) ) ;

  *temp = DATA(*p_L) ;
  
  delete ( p_L, (generic_ptr * ) p_n ) ;

  *p_n = **temp ; 

  return OK ;

}

