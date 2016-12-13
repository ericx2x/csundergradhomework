/******************************************************/
/* bitvector.h                                        */
/******************************************************/

#ifndef _bitvector
#define _bitvector

#include "globals.h"

#define BYTESIZE 8

typedef char byte ; 

typedef struct { int setsize ; byte *bytestream ; } set ; 

extern status init_set( set *p_S , int size ) ;
extern status set_insert( set *p_S , int element ) ;
extern bool   set_member( set *p_S , int element ) ;
extern status set_delete( set *p_S , int element ) ;
extern status set_union( set *p_S1, set *p_S2, set *p_S3 ) ;
extern status set_intersection( set *p_S1, set *p_S2, set *p_S3 ) ;
extern status set_difference( set *p_S1, set *p_S2, set *p_S3 ) ;

#endif 
