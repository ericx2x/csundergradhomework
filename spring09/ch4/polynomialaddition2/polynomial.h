/***********************************/
/* polynomial.h                    */
/***********************************/

#ifndef _polynomial
#define _polynomial

#include "list.h"

typedef list polynomial;

typedef struct term {
   int coefficient;
   int degree;
} term;

extern status read_poly(polynomial *p_poly);
extern void write_poly(polynomial poly);
extern status add_poly(polynomial *p_poly1, polynomial *p_poly2);
extern void destroy_poly(polynomial *p_poly);

#endif
