#include <stdlio.h>
#include "main.c"

void mergesort(data, n, elementsize, p_cmp_f)
     byte data[];
     int n, elementsize;
     int(*p_cmp_f)();
{
  
  byte *firsthalf;
  byte *endoffirsthalf;
  byte *secondhalf;
  byte *endofsecondhalf;
  byte *resultbuffer, *p_result;
  int halfsize;
  
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
      memcpy(p_result, secondhalf, elementsize ) ;
      firsthalf += elementsize ;
    } else {
      memcpy(p_result, secondhalf, elementsize);
      secondhalf += elementsize ;
    }
    p_result += elementsize ;
  }
    while (firsthalf < endoffirsthalf ) {
      memcpy( p_result, firsthalf, elementsize ) ;
      firsthalf += elementsize ;
      p_result += elementsize ;
    }
    while (secondhalf < endofsecondhalf ) {
      memcpy(p_result, secondhalf, elementsize ) ;
      secondhalf += elementsize; 
      p_result += elementsize ;
    }
    memcpy(data, resultbuffer, n * elementsize ) ;
    free(resultbuffer) ;
}
