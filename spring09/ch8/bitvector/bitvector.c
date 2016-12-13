/***********************************************/
/* bitvector.c                                 */
/***********************************************/

#include <stdlib.h>
#include "bitvector.h"
#include "globals.h"

static byte bit[BYTESIZE] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

status init_set( set *p_S, int size ) {
  
  int numbytes, i ; 
  
  numbytes = ( size + BYTESIZE - 1 ) / BYTESIZE ; 
  
  p_S -> bytestream = ( char * ) malloc( numbytes ) ;
  
  if ( p_S -> bytestream == NULL ) return ERROR ; 
  
  p_S -> setsize = numbytes * BYTESIZE ; 
  
  for ( i = 0 ; i < numbytes ; i++ ) p_S -> bytestream[i] = 0 ; 
  
  return OK ;

}

status set_insert( set *p_S, int element ) {

  if ( element < 0 || element >= p_S -> setsize ) return ERROR ; 

  p_S -> bytestream[ element / BYTESIZE ] |= bit[element % BYTESIZE] ;
 
  return OK ;
  
}

status set_delete( set *p_S, int element ) {
  
  if ( element < 0 || element >= p_S -> setsize ) return ERROR ;
  
  p_S -> bytestream[ element / BYTESIZE ] ^=  bit[element % BYTESIZE] ;
  
  return OK ;
  
}

bool set_member(set *p_S, int element ) {
  
  if ( element < 0 || element >= p_S -> setsize ) return FALSE ;
  
  return ( p_S -> bytestream[ element / BYTESIZE ] & bit[ element % BYTESIZE ] ) ? TRUE : FALSE ;
  
}

status set_union( set *p_S1, set *p_S2, set *p_S3 ) {
  
  int i, numbytes ; 
  
  numbytes = ( p_S1 -> setsize + BYTESIZE - 1 ) / BYTESIZE ; 
  
  for( i = 0 ; i < numbytes ; i++ ) 
    
    p_S3 -> bytestream[i] = p_S1 -> bytestream[i] | p_S2 -> bytestream[i] ; 
  
  return OK ; 
  
}

status set_intersection( set *p_S1, set *p_S2, set *p_S3 ) { 
  
  int i , numbytes ; 
  
  numbytes = ( p_S1 -> setsize + BYTESIZE - 1 ) / BYTESIZE ;
  
  for ( i = 0 ; i < numbytes ; i++ ) 
    
    p_S3 -> bytestream[i] = p_S1 -> bytestream[i] & p_S2 -> bytestream[i] ;
  
  return OK ; 
  
} 

status set_difference( set*p_S1, set *p_S2, set *p_S3 ) {
  
  int i , numbytes ; 
  set temp ; 
  init_set( &temp, p_S1 -> setsize ) ;
  
  numbytes = ( p_S1 -> setsize + BYTESIZE - 1 ) / BYTESIZE ; 
  
  for ( i = 0 ; i < numbytes ; i++ ) 
    
    temp.bytestream[i] = ~( p_S2 -> bytestream[i] ) ; 
  
  set_intersection( p_S1, &temp, p_S3 ) ; 
  
  return OK ; 
  
}
