/*************************************/
/* Fibonacci.c                       */
/*************************************/

#include <stdlib.h>
#include <stdio.h>
#include "fibonacci.h"

extern integer load ( integer n )
{

  int i ;

  for ( i = 1 ; i <= n.size + 1 ; i++ ) n.digit[i] = -1 ;

  return n ;

}

extern float frequency ( integer n, float a )
{

  int i ;

  float count = 0 ;

  for ( i = 0 ; i < n.size ; i++ )
    {
      if ( n.digit[i] == a ) count++ ;
    }

  return ( count / n.size ) ;

}

extern integer fibonacci ( integer a, int n )
{

  integer c ;
  integer temp ;

  c.size = 1 ;
  c.digit[0] = 1 ;

  temp.size = 1 ;
  temp.digit[0] = 1 ;

  load( temp ) ;
  load( c ) ;

  int i = 1 ;

  do {

    a = add(temp,c) ;

    temp = c ;

    c = a ;

    i++ ;

  }

  while ( i <= ( DATA(a) - 2 ) ) ;

  return a ;

}

extern integer add ( integer n, integer b )
{

  int i = 0 ;

  for ( i = 0 ; i < b.size ; i++ )
    {

      n.digit[i] += b.digit[i] ;

      if ( n.digit[i] > 9 )
	{
	  n.digit[i] %= 10 ;
	  n.digit[i+1] += 1 ;
	  n.size++ ;
	}
    }

  return n ;

}

extern integer digitcalc ( integer n )
{
  int i = 0, count = 1 ;

  while ( n.digit[i] != -1 )
    {
      i++ ;
      count ++ ;
    }

  n.size = count ;

  return n ;
}


