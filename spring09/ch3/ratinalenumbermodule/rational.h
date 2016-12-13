/* rational.h */

#ifndef _rational
#define _rational

#include "globals.h"

typedef struct { int n ; int d; } rational ;

extern int gcd( int n , int d) ;

extern rational load_rational( int numerator, int denominator ) ;
extern void print_rational( rational a ) ;
extern void retrieve_rational( rational rational1, int *p_numerator, int *p_denominator ) ;
extern rational add_rational( rational rational1, rational rational2 ) ;
extern rational subtract_rational( rational rational1, rational rational2 ) ;
extern rational multiply_rational( rational rational1, rational rational2 ) ;
extern rational divide_rational( rational rational1, rational rational2 ) ;
extern bool equal_rational( rational rational1, rational rational2 ) ;


#endif
