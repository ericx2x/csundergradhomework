/*******************************************************/
/* Programmer: Eric J Lima                             */
/*                                                     */
/* Program: MinMax (recursive)                         */
/*                                                     */
/* Approximate Completion Time:  24 minutes            */
/*******************************************************/

#include <stdio.h>
#include <stdlib.h>

void minmax( int *numberlist, int n, int *p_min, int *p_max) ;

int main( int argc, char *argv[] ) {

  int *numberlist, n, p_min, p_max, i ;

  n =  atoi( argv[1] ) ;
  
  numberlist = (int *) malloc( sizeof( int ) * n ) ;
  
  for( i = 0 ; i < n ; i++ ) numberlist[i] = rand() % 1000;
  
  minmax( numberlist, n, &p_min, &p_max ) ;

  return 0 ;

}

void minmax( int *numberlist, int n, int *p_min, int *p_max) {

int min2, max2 ;

if( n ==1 ) 
     *p_min = *p_max = numberlist[0] ; 
     else if ( n == 2 ) { 
       if ( numberlist[0] < numberlist[1] ) {
	 *p_min = numberlist[0] ;
	 *p_max = numberlist[1] ;
       } else {
	 *p_min = numberlist[1] ;
	 *p_max = numberlist[0] ;
       }
     } else {
       minmax(numberlist, n / 2, p_min, p_max ) ;
       minmax(numberlist + n / 2, n - ( n / 2 ), &min2, &max2) ;
       if( min2 < *p_min )
	 *p_min = min2 ;
       if(max2 > *p_max ) ;
       *p_max = max2 ;
     }
}
