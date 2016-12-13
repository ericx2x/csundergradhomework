/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 56: Guardian Angles                                               */
/*                                                                           */
/* Approximate completion time: 45 minutes                                   */
/*****************************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int a, b, c ;

  scanf( "%d%d%d", &a, &b, &c ) ;
  
  printf( "%d %d %d ", a, b, c ) ;
  
  if ( ( a != b && b != c && a != c ) && a + b > c && a + c > b && b + c > a ) {
    
    printf("is a scalene" ) ;
    
    if ( (a*a) + (b*b) == (c*c) ) printf(" right" ) ;
    
    printf(" triangle." ) ;
    
  }
  
  else if ( ( a == b || a == c || b == c) && ( a != c || a != b || b != c ) && a + b > c && a + c > b && b + c > a ) {
    
    printf("is a isosceles" ) ;
    
    if ( (a*a) + (b*b) == (c*c) ) printf(" right" ) ;
    
    printf(" triangle." ) ;
    
  }
  
  else if ( a == b && b == c ) printf("is a equilateral triangle." ) ;
  
  else  printf("is not a triangle." ) ;
  
  putchar('\n');
  
  return 0 ;
  
}
