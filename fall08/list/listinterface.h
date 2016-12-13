/*******************************************************/
/* listinterface.h                                     */
/*******************************************************/

#ifndef _listinterface
#define _listinterface

#include "list.h"


extern status term_insert( list *p_L, int coef, int def ) ;

extern status term_delete( list *p_L, int *p_coef, int *p_deg ) ;


#endif
