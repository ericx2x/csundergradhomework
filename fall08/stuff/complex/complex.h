/* Complex.h */

#ifndef _complex
#define _complex

typedef struct complex {double r ; double im; } complex;

extern complex ADD_complex(complex A, complex B) ;
extern complex MULT_complex(complex A, complex B) ;
extern complex SUBTRACT_complex(complex A, complex B) ;
extern complex DIVIDE_complex(complex A, complex B) ;

#endif
