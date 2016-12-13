/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 67: String Pattern Matching - Naive Approach                      */
/*                                                                           */
/* Approximate completion time: 6 hours and 12 minutes                       */
/*****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int str( char a[], char b[] ){
  int i, start = 0, pos = 0 ;

  for( i = 0 ; i < strlen(b) ; i++ ){ 
      start = i ;
    if( a[pos] == b[i] ) {
      pos += 1 ;
      if( pos == strlen(a) )
	return start;
    }
    else {
      pos = 0 ;
      start = 0 ;
    }
  }
  return -1 ;
}

int main( int argc, char *argv[] ) {

  char a[11] ;
  char b[256] ;

  printf("Please, enter in a string less than 10 characters. \n") ;
  
  gets( a ) ;
  
  while ( 1 ) { 

    gets( b ) ;

    if( !(strcmp( b, "")) ) break;

    if( str( a, b ) != -1 ) printf( "Yes  %d\n", str(a, b) ) ;
  }
  
  return 0 ;
  
}
