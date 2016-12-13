/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 49: Integer Decomposition                                         */
/*                                                                           */
/* Approximate completion time: 49 minutes                                   */
/*****************************************************************************/

#include <stdio.h>

int gcd( int n, int m ) ;

int main( int argc, char *argv[] ) {
  
  FILE *fin = fopen( "testdata49", "r" ) ;
  int n, a , b , c, solution ;
  
  while( fscanf( fin, "%d ", &n ) != EOF ) {
    
    solution = 0 ;
    for( a = 2 ; a < n - 1 && solution == 0 ; a++ )
      for( b = 3 ; b < n - 1 && solution == 0 ; b++ ){
	c = n - ( a + b ) ;    
	
	if( gcd( a, b) == 1 && gcd(a, c) == 1 && gcd( b, c ) == 1 && c != 1 ) { 
	  printf( "%d = %d + %d + %d\n", n, a, b, c ) ;
	  solution++ ;
	  
	}
      }
  }  

  fclose( fin ) ;
  
  return 0 ; 
  
}


int gcd( int n, int m ) {
  
  if( m % n == 0 ) return n ;

  return gcd( m, m % n ) ;

}
