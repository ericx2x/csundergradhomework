/* Complex.h */

#ifndef _complex
#define _complex

#include "globals.h"

typedef struct complex {double real ; double imaginary; } complex;

extern complex load_complex(double real, double imaginary) ;
extern void retrieve(complex complex1, double *p_real, double *p_imaginary);
extern complex add_complex( complex complex1, complex complex2 ) ;
extern complex multiply_complex ( complex complex1, complex complex2 ) ;
extern complex subtract_complex (  complex complex1, complex complex2 ) ;
extern bool equal_complex ( complex complex1, complex complex2 ) ;
extern complex divide_complex ( complex complex1, complex complex2 ) ;
extern void print_complex ( complex complex1 ) ;

#endif
