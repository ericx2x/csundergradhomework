/*******************************************************************/
/* set.h                                                           */
/*                                                                 */
/* This is for dynamic array sequential set implementation.        */
/*******************************************************************/

#ifndef _set
#define _set

#include "globals.h"

typedef struct { generic_ptr *base ; generic_ptr *free ; int universe_size ; }
set ;

extern status set_insert( set *p_S, generic_ptr element, int (*p_cmp_f)()) ;
extern status set_delete( set *p_S, generic_ptr element, int (*p_cmp_f)()) ;

extern status int_set( set *p_S, int size ) ;
extern bool set_member( set *p_S, generic_ptr element, int (*p_cmp_f)());
extern status set_write( set *p_S, status (*p_write_f)());

extern status set_delete( set *p_S, generic_ptr element, int (*p_cmp_f)()) ;
extern status set_union( set *p_S1, set *p_S2, set *p_S3, int (*p_func_cmp)(),int sizeofdata ) ;

extern status set_intersection( set *p_S1, set *p_S2, set *p_S3, int (*p_func_cmp)(), int sizeofdata ) ;

#endif
