/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 78: State Transition Machine                                      */
/*                                                                           */
/* Approximate completion time: 1 hour and 58 minutes                        */
/*****************************************************************************/
#include <stdio.h>

int main ( int argc, char *argv[] ) {

  int A[5] = { 1, 2, 3, 4, 0 } ;
  int B[5] = { 2, 3, 4, 0, 1 } ;
  int C[5] = { 3, 4, 0, 1, 2 } ;
  int D[5] = { 4, 0, 1, 2, 3 } ;
  int E[5] = { 0, 1, 2, 3, 4 } ;

  char state          ;
  int s, i, count = 0 ;

  printf( "Please, enter the starting state. \n" ) ;
  scanf( "%c", &state ) ;

  printf( "Please, enter a column number. \n" ) ;
  scanf( "%d", &i ) ;

  while( i >= 0 ) {

    if( count == 0 ) {

      if( state == 'A' ) s = A[i] ;

      else if( state == 'B' ) s = B[i] ;

      else if( state == 'C' ) s = C[i] ;

      else if( state == 'D' ) s = D[i] ;

      else s = E[i] ;

      count = 1 ;
    }

    else {

      if( s == 0 ) s = A[i] ;

      else if( s == 1 ) s = B[i] ;

      else if( s == 2 ) s = C[i] ;

      else if( s == 3 ) s = D[i] ;

      else s = E[i] ;

    }

    printf( "Please enter a column number. \n" ) ;

    scanf( "%d", &i ) ;

  }

  if( s == 0 ) printf( "Final state is A.\n" ) ;

  else if( s == 1 ) printf( "Final state is B.\n" ) ;

  else if( s == 2 ) printf( "Final state is C.\n" ) ;

  else if( s == 3 ) printf( "Final state is D.\n" ) ;

  else printf( "Final state is E.\n" ) ;

  return 0;
}


