/***********************************************************************/
/* Programmer: Eric Joesph Lima                                        */
/*                                                                     */
/* Program 37: Greatest Common Divisor  (Non-recursive Euclid Method)  */
/*                                                                     */
/* Approximate completion time: 42 minutes                             */
/***********************************************************************/

#include <stdio.h>


int gcd( int n, int m ) ;
int main( int argc, char *argv[] ) {
  
  FILE *fin = fopen( argv[1], "r" ) ;
  int n, m ;
  
  while( fscanf( fin, "%d%d", &n, &m ) != EOF ) printf( "The greatest common divisor between %d and %d is %d. \n", n, m, gcd( n, m ) ) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}

int gcd( int n, int m ) {
  
  int temp = 0 ;
  
  while( m != 0 ) {
    
    temp = n % m;
    
    n = m ;
    
    m = temp ;
    
  }
  
  return n ;
  
}
