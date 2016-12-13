/*************************************/
/* fibonacci.h                       */
/*************************************/

#ifndef _fibonacci
#define _fibonacci

#include "globals.h"

typedef struct { int digit[10000] ; float size ; } integer ;

extern integer load ( integer n ) ;
extern float frequency ( integer n, float a ) ;
extern integer fibonacci ( integer a, int n )  ;
extern integer add ( integer n, integer b ) ;
extern integer digitcalc ( integer n ) ;

#endif
