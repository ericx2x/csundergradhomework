/**************************************************/
/* Alligators and Ducks                           */
/**************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int num ; struct Node * next ; } NODE ;

int main ( int argc, char *argv[] ) {

  int n, m, i ;
  NODE *p , *q, *this, *before ;

  do printf("Input n and m: " ) ;
  while ( scanf( "%d%d" , &n, &m ) != 2 ) ;

  this = p = ( NODE * ) malloc ( sizeof(NODE) ) ;
  p -> num = 1 ;

  for ( i = 2 ; i <= n ; i++ ) {
    
    q = ( NODE * ) malloc ( sizeof( NODE ) ) ;
    q -> num = i ;
    p -> next = q ;
    p = q ;

  }
  
  p -> next = this ;
  before = this ;
    this = this -> next ;
    
    while ( before != this ) { 
      
      for ( i = 1 ; i < m ; i++ ) {

	before = this ;
	this = this -> next ; 
      }

      printf( "%d\n", this -> num ) ;
      q = this ;
      this = this -> next ; 
      before -> next = this ;
      free ( q ) ;
      
    }
    
    printf( "%d\n", this -> num ) ;
    free( this ) ;
    return 0 ;
}
