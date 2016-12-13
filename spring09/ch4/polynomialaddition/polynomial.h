/*****************************************************************************/
/* Polynomial Addition Program - polynomial.h                                */
/* Eric J Lima                                                               */
/* Last Modified January 30, 2009                                            */
/*****************************************************************************/
#ifndef INC_POLYNOMIAL_H
#define INC_POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "globals.h"

typedef list polynomial;

typedef struct term {
    int coefficient;
    int degree;
} term; 

extern status read_poly(polynomial *p_poly);
extern void write_poly(polynomial poly);
extern status add_poly(polynomial *p_poly1, polynomial *p_poly2);
extern void destroy_poly(polynomial *p_poly);

extern int cmp_degree(term *p_term1,term *p_term2);
extern status write_term(term *p_term); 
extern bool equal_term(term *p_poly1, term *p_poly2);

#endif /* INC_POLYNOMIAL_H */
