/***********************************************************************/
/* Programmer: Eric Joesph Lima                                        */
/*                                                                     */
/* Program 46: Relatively Prime to 351                                 */
/*                                                                     */
/* Approximate completion time: 51 minutes                             */
/***********************************************************************/

#include <stdio.h>


int gcd( int n, int m ) ;
int main( int argc, char *argv[] ) {
  
  int  i = 1 ;
  
  while( i < 351 ) {
    
    if ( gcd( i, 351 ) == 1 ) printf( "The numbers %d and 351 are relatively prime.\n", i ) ;
    
    i += 1 ;
    
  }
  
  return 0 ;
  
}

int gcd( int n, int m ) {
  
  if( n % m == 0 ) return ( m == 1 ) ;
  
  return gcd( m, n % m ) ;
  
}
