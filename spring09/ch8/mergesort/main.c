/**************************************************************************************/
/* Programmer: Eric J Lima                                                            */
/*                                                                                    */
/* Program: mergesort                                                                 */
/*                                                                                    */
/* Approximate Time to Completion:  5 hours                                           */
/**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef char byte ;

void memcopy( byte *to, byte *from, int count ) {  
  
  while (count-- > 0 )
    *to++ = *from++ ;
  
}

int compare(  byte *a , byte *b ) {

  if( *( int *)b > *( int * ) a ) return -1 ;
  if( *( int *)b < *( int * ) a )  return 1 ;
  
  return 0;

}

void mergesort( byte data[], int n, int elementsize, int (*p_cmp_f)( ) ) ;

int main( int argc, char *argv[] ) {

  int A[500000] ;
  int n , i ;

  n = atoi( argv[1] ) ;

  for ( i = 0 ; i <= n ; i++ ) A[i] = rand() % 10000 ; 
 
  for ( i = 0 ; i <= 19 ; i++ ) printf(" %d ", A[i] ) ;
  printf("\n") ;

  mergesort( (byte *) A, n , sizeof(int) , compare ) ;

  printf("\n") ;
  for ( i = 0 ; i <= 19 ; i++ ) printf(" %d ", A[i] ) ;
  printf("\n") ;

  return 0 ;

}

void mergesort( byte data[], int n, int elementsize, int (*p_cmp_f)( ) )  {

  byte *firsthalf;
  byte *endoffirsthalf;
  byte *secondhalf;
  byte *endofsecondhalf;
  byte *resultbuffer, *p_result;

  int halfsize ;

  if (n<=1)
    return;

  halfsize = n / 2 ;
  firsthalf = data ;
  secondhalf = data + halfsize * elementsize ;

  mergesort( firsthalf, halfsize, elementsize, p_cmp_f ) ;
  mergesort( secondhalf, n - halfsize, elementsize, p_cmp_f);

  endoffirsthalf = secondhalf ;
  endofsecondhalf = data + n * elementsize ;
  resultbuffer = (byte *) malloc(n * elementsize) ;
  p_result = resultbuffer ;

  while (firsthalf < endoffirsthalf && secondhalf < endofsecondhalf ) {
    if (( *p_cmp_f)(firsthalf, secondhalf) < 0 ) {
      memcopy(p_result, secondhalf, elementsize ) ;
      firsthalf += elementsize ;
    } else {
      memcopy(p_result, secondhalf, elementsize);
      secondhalf += elementsize ;
    }
    p_result += elementsize ;
  }
  while (firsthalf < endoffirsthalf ) {
    memcopy( p_result, firsthalf, elementsize ) ;
    firsthalf += elementsize ;
    p_result += elementsize ;
  }
  while (secondhalf < endofsecondhalf ) {
    memcopy(p_result, secondhalf, elementsize ) ;
    secondhalf += elementsize;
    p_result += elementsize ;
  }
  memcopy(data, resultbuffer, n * elementsize ) ;
  free(resultbuffer) ;

}
