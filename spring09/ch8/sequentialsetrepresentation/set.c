/***************************************************************/
/* set.c - A sequential representation using dynamic arrays.   */
/***************************************************************/

#define MAX(a , b) ( ( (a) > (b) ) ? (a) : (b) ) 
#define MINIMUM_INCREMENT 100
#define member_count(p_S) ((p_S) -> free - (p_S) -> base ) 

#include <stdio.h>
#include <stdlib.h>

#include "set.h"
#include "globals.h"

typedef char byte ; 

static status memcopy( byte *to, byte *from, int count ) {
  
  while( count--> 0 ) *to++ = *from++ ;
  return OK ;
}

extern status init_set( set *p_S, int size ) {
  
  p_S -> universe_size = MAX( size, MINIMUM_INCREMENT ) ;
  
  p_S -> base = (generic_ptr *) malloc(p_S -> universe_size * sizeof(generic_ptr) ) ;
  
  if ( p_S -> base == NULL ) return ERROR ;
  
  p_S -> free = p_S -> base ; 
  
  return OK ;
  
}

extern status set_insert( set *p_S , generic_ptr element, int (*p_cmp_f)()) {
  
  if ( set_member( p_S, element, p_cmp_f ) == TRUE ) return OK ;
  
  if ( p_S -> universe_size == member_count(p_S) ) {
    
    generic_ptr *newset = ( generic_ptr *) realloc( p_S -> base, (p_S -> universe_size + MINIMUM_INCREMENT) * sizeof( generic_ptr * ) ) ;
    
    if (newset == NULL ) return ERROR ;
    
    p_S -> base = newset ;
    p_S -> free = p_S -> base + p_S -> universe_size ;
    p_S -> universe_size += MINIMUM_INCREMENT ;
    
  }
  
  *p_S -> free = element ; 
  p_S -> free++ ; 
  
  return OK ;
}

bool set_member ( set *p_S, generic_ptr element, int (*p_cmp_f)()) { 
  
  generic_ptr *item ; 
  
  for (item = p_S -> base ; item < p_S -> free ; item++ ) {
    
    if ((*p_cmp_f)(*item, element) == 0 ) return TRUE ;
    
  }
  
  return FALSE ;
  
}

extern status set_write( set *p_S, status (*p_write_f)()) {
  generic_ptr *item ;
  
  for ( item = p_S -> base ; item < p_S -> free ; item++ ) 
    
    (*p_write_f)(*item) ;
  
  return OK ;
  
}

extern status set_delete( set *p_S, generic_ptr element, int (*p_cmp_f)()){
  
  generic_ptr *item ;
  
  for( item = p_S -> base ; item < p_S -> free ; item++ ) {
    
    if(( *p_cmp_f)(*item, element) == 0 ) { 
      
      free(*item ) ;
      p_S -> free-- ;
      *item = *(p_S -> free ) ;
      *(p_S -> free ) = NULL ;
      
    }
    
  }

  return OK ;

}

extern status set_union( set *p_S1, set *p_S2, set *p_S3, int (*p_func_cmp)(), int sizeofdata ) {

  int i ; 
  generic_ptr element ;

  for ( i = 0 ; i < member_count( p_S1 ) ; i++ ) {

    if ( set_member( p_S3, p_S2 -> base[i], p_func_cmp ) == FALSE ) {

      element = ( generic_ptr ) malloc( sizeofdata ) ;
      memcopy( element, p_S1 -> base[i], sizeofdata ) ;
      set_insert( p_S3, element, p_func_cmp ) ;
    }
  }

  for( i = 0 ; i < member_count( p_S2 ) ; i++ ) {

    if ( set_member( p_S3, p_S2 -> base[i], p_func_cmp ) == FALSE ) {

      element = ( generic_ptr ) malloc( sizeofdata ) ;
      memcopy( element, p_S2 -> base[i], sizeofdata ) ;
      set_insert( p_S3, element, p_func_cmp ) ;
    }
  }
  return OK ;

}

extern status set_intersection( set *p_S1, set *p_S2, set *p_S3, int (*p_func_cmp)(), int sizeofdata ) {

  int i ; 
  generic_ptr element ;

  for ( i = 0 ; i < member_count ( p_S1 ) ; i++ ) { 

    if ( set_member( p_S2, p_S1 -> base[i], p_func_cmp ) == TRUE ) { 

      element = ( generic_ptr ) malloc( sizeofdata ) ;
      memcopy( element, p_S1 -> base[i], sizeofdata ) ; 
      set_insert( p_S3, element, p_func_cmp ) ;
    }
  } 
  return OK ;

}
