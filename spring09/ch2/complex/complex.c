/* Complex.c */

#include <stdio.h>
#include "complex.h"
#include "globals.h"

extern complex add_complex(complex complex1, complex complex2) {

  complex a;

  a.real = complex1.real + complex2.real ;

  a.imaginary = complex1.imaginary + complex2.imaginary ;

  return ( a );

}

extern complex subtract_complex(complex complex1, complex complex2) {

  complex a;

  a.real = complex1.real - complex2.real ;

  a.imaginary = complex1.imaginary - complex2.imaginary ;

  return ( a );

}


extern complex multiply_complex(complex complex1, complex complex2) {

  complex a;

  a.real = ( complex1.real * complex2.real ) - ( complex1.imaginary * complex2.imaginary ) ;

  a.imaginary = ( complex1.real * complex2.imaginary ) + ( complex1.imaginary * complex2.real ) ;

  return a;

}

extern complex load_complex(double real, double imaginary) {

  complex a ;

  a.real = real ;
  a.imaginary = imaginary ;

  return a ;

}

extern void retrieve(complex complex1, double *p_real, double *p_imaginary) {

  *p_real = complex1.real ;
  *p_imaginary = complex1.imaginary ;

  return ;

}

extern void print_complex ( complex complex1 ) {

  printf("%1f ", complex1.real ) ;
  printf("%1f ", complex1.imaginary ) ;

  return ;

}

extern bool equal_complex ( complex complex1, complex complex2 ) {

  return ( ( complex1.real == complex2.real ) && ( complex1.imaginary == complex2.imaginary ) ) ;

}

extern complex divide_complex ( complex complex1, complex complex2 ) {

  complex a ;

  a.real = ( ( complex1.real * complex2.real ) + ( complex1.imaginary * complex2.imaginary ) ) / ( ( complex2.real * complex2.real ) + ( complex2.imaginary * complex2.imaginary ) ) ;

  a.imaginary = ( ( complex1.imaginary * complex2.real ) + ( complex1.real * complex2.imaginary ) ) / ( ( complex2.real * complex2.real ) + ( complex2.imaginary * complex2.imaginary ) ) ;


  return a ;

}

