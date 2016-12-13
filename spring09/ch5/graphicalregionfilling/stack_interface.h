/******************************/
/* stack_interface.h          */
/******************************/

#ifndef _stack_interface
#define _stack_interface

#include <stdlib.h>
#include "stack.h"
#include "stdio.h"
#include "globals.h"

extern status push_char ( stack *p_S , char c ) {

  char *p_c = (char *) malloc ( sizeof(char)) ;

  if ( p_c == NULL ) return ERROR ; 

  *p_c = c ; 

  if ( push ( p_S, ( generic_ptr ) p_c) == ERROR ) { 
    free (p_c) ; return ERROR ; 
  }
  return OK ;

}

extern status pop_char ( stack *p_S, char *p_c ) {
  char *p_data ; 

  if ( pop ( p_S, (generic_ptr * ) &p_data ) == ERROR ) 
    return ERROR ;

  *p_c = *p_data ; 
  free (p_data) ; 

  return OK ; 

}

extern status top_char ( stack *p_S, char * p_c ) { 

  char * p_data ;

  if ( top (p_S, (generic_ptr * ) &p_data ) = ERROR ) 
    return ERROR ; 

  *p_c = *p_data ; 

  return OK ; 

}

#endif