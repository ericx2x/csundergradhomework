/* Complex.c */

#include <stdio.h>
#include "complex.h"
#include "globals.h"

extern complex ADD_complex(complex A, complex B) {

  complex temp;

  temp.r = A.r + B.r ;

  temp.im = A.im + B.im ;

  return temp;

}

extern complex MULT_complex(complex A, complex B) {

  complex temp;

  temp.r = ( A.r * B.r ) - ( A.im * B.im ) ;

  temp.im = ( A.r * B.im ) + ( A.im * B.r ) ;

  return temp;

}

extern complex SUBTRACT_complex(complex A, complex B) {

  complex temp;

  temp.r = A.r - B.r ;

  temp.im = A.im - B.im ;

  return temp;

}

extern complex DIVIDE_complex(complex A, complex B) {

  complex temp;

  temp.r = (( A.r * B.r ) + ( A.im * B.im )) / ((B.r * B.r ) + ( B.im * B.im ))  ;

  temp.im = (( A.im * B.r ) - ( A.r * B.im )) / (( B.r * B.r ) + (B.im * B.im)) ;

  return temp;

}
