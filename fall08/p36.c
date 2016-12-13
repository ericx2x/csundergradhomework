/***********************************************************************/
/* Programmer: Eric Joesph Lima                                        */
/*                                                                     */
/* Program 36: Greatest Common Divisor  (Brute Force Method)           */
/*                                                                     */
/* Approximate completion time: 49 minutes                             */
/***********************************************************************/

#include <stdio.h>


int gcd( int n, int m ) ;
int main( int argc, char *argv[] ) {
  
  FILE *fin = fopen( argv[1], "r" ) ;
  int n, m ;
  
  while(  fscanf( fin, "%d%d", &n, &m ) != EOF ) printf( "The greatest common divior between %d and %d is %d. \n", n, m, gcd( n, m ) ) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}

int gcd( int n, int m ) {
  
  int i, divisor = 0 ;
  
  for( i = 1 ; i <= n ; i++ ) if( n % i == 0 && m % i == 0 ) divisor = i ;
  
  return divisor ;
  
}
