/* rational.c */

#include <stdio.h>
#include "rational.h"

extern int gcd( int n, int d ) 
{

  if( n % d == 0 ) return d ;

  return( gcd( d, n%d ) );

}

extern rational load_rational( int numerator, int denominator )
{

  rational temp ;

  temp.n = numerator ;
  temp.d = denominator ;

  return temp ;

}

extern void print_rational( rational temp ) 
{

  printf( "%d ", temp.n ) ;
  printf( "/ " ) ;
  printf( "%d ", temp.d ) ;

  return ;

}


extern void retrieve_rational( rational rational1, int *p_numerator, int *p_denominator )
{

  *p_numerator = rational1.n ;
  *p_denominator = rational1.d ;

  return ;

}

extern rational add_rational( rational rational1, rational rational2 ) 
{

  int tmp ;

  rational temp ;

  if( rational1.d != rational2.d ) 
    {
      rational1.n *= rational2.d ;
      rational2.n *= rational2.n ;
      rational1.d *= rational2.d ;
    }

  temp.n = rational1.n + rational2.n ;
  temp.d = rational1.d ;

  tmp = gcd( temp.n, temp.d ) ;

  if( tmp != 1 ) 
    {
      temp.n /= tmp ;
      temp.d /= tmp ;
    }

  return temp ;

}

extern rational subtract_rational( rational rational1, rational rational2 ) 
{


  int tmp ;

  rational temp ;

  if ( rational1.d != rational2.d ) 
    {
      rational1.n *= rational2.d ;
      rational2.n *= rational2.n ;
      rational1.d *= rational2.d ;
    }

  temp.d = rational1.d ;
  temp.n = rational1.n - rational2.n ;

  tmp = gcd( temp.n, temp.d ) ;

  if( tmp != 1 ) 
    {
      temp.n /= tmp ;
      temp.d /= tmp ;
    }

  return temp ;

}

extern rational multiply_rational( rational rational1, rational rational2 ) 
{

  int tmp ;

  rational temp ;

  temp.n = rational1.n * rational2.n ;
  temp.d = rational1.d * rational2.d ;

  tmp = gcd( temp.n, temp.d ) ;

  if( tmp != 1 ) 
    {
      temp.n /= tmp ;
      temp.d /= tmp ;
    }

  return temp ;

}

extern rational divide_rational( rational rational1, rational rational2 ) 
{

  int tmp ;

  rational temp ;

  temp.n = rational1.n * rational2.d ;
  temp.d = rational1.d * rational2.n ;

  tmp = gcd( temp.n, temp.d );

  if( tmp != 1 ) 
    {
      temp.n /= tmp ;
      temp.d /= tmp ;
    } 

  return temp;

}

extern bool equal_rational( rational rational1, rational rational2 ) 
{

  return( ( rational1.n == rational2.n ) && ( rational1.d == rational2.d ) ) ;

}
