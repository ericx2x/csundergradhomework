/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 57: Goldbach's Conjecture                                         */
/*                                                                           */
/* Approximate completion time:     59 minutes                               */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int IsPrime( int x ) ;
int main( int argc, char *argv[] ) {

  int i, j ;

  int sum = 700, start, finish ;

  start = atoi( argv[1] ) ;

  finish = atoi( argv[2] ) ;

  for( i = 0 ; i < 1000 ; i++ ) {

    for( j = 0 ; j < 1000 ; j++ ) {

      if( ( IsPrime( j ) == 1 ) && ( IsPrime( i ) == 1 ) && ( i != j ) && i + j == sum ) {

        if( sum <= finish && sum >= start && sum % 2 == 0 ) printf( "%d = %d + %d\n", sum, i, j ) ;

        sum += 2 ;

      }

    }

  }

  return 0 ;

}

int IsPrime( int i ) {

  int k, count = 0 ;

  for( k = 1 ; k <= i ; k++ ) if( (i % k) == 0 ) count++ ;

  return ( count == 2 ) ;

}
