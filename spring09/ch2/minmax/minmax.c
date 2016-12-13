/*******************************************************/
/* Programmer: Eric J Lima                             */
/*                                                     */
/* Program: MinMax (iterative)                         */
/*                                                     */
/* Approximate Completion Time:  24 minutes            */
/*******************************************************/


#include <stdio.h>
#include <stdlib.h>

void minmax( int *a, int n, int *p_min, int *p_max) ;

int main( int argc, char *argv[] ) {

  int *a, n, p_min, p_max, i ;

  n =  atoi( argv[1] ) ;

  a = (int *) malloc( sizeof(int)*n) ;

  for( i = 0 ; i < n ; i++ ) a[i] = rand() % 1000;

  minmax( a, n, &p_min, &p_max ) ; 

  return 0 ;

}


void minmax( int *a, int n, int *p_max, int *p_min ) {

  int i ;

  *p_max = *p_min = a[0] ; 

  for ( i = 1 ; i < n ; i++ ) {
    if( a[i] > *p_max ) 
      *p_max = a[i] ;
    if( a[i] < *p_min) 
      *p_min = a[i] ;
 
  }
}
