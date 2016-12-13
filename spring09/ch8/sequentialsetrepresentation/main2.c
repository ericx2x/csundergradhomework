/***************************************************************************************************************/
/* Programmer: Jim Canning                                                                                     */
/*                                                                                                             */
/* Using a sequential set implementation to store a set of words (dynamic arrays).                             */ 
/*                                                                                                             */
/* In order to achieve polymorphic sets, it must be the case that the size of the data remains the same.       */
/* Doing so allows us to use a memcopy function within set.c. This is necessary when implementing set union    */
/* and set intersection.                                                                                       */
/*                                                                                                             */
/* Thus, I have arbitrarily fixed the size of a word to be at most 20 characters + the null byte.              */
/* Without doing this, strings of varying length would need to be handled in a different way.                  */
/***************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "globals.h"
#include "ctype.h"

#define n 100

extern status write_word( generic_ptr word ) {

  printf("%s", (char *) word ) ;
  printf("\n") ;
  return OK ;

}

char *getword ( FILE *fin ) {

  int c ;
  int i ;
  char *s ;
  char temp[21] ;
  int state = 1 ;

  for ( i = 0 ; i < 21 ; i++ ) temp[i] = '\0' ;

  i = 0 ;

  while ( ( c = getc( fin ) ) != EOF  ) {

    c = toupper( c ) ; 
    if ( ( state == 1 ) && ( ( c < 65 ) || ( c > 91  ) ) ) { state = 1 ;  continue ; }
    if ( ( state == 1 ) && ( ( 65 <= c) && (c <= 90  ) ) ) { state = 2 ; temp[i] = c ; i++ ; continue ; }
    if ( ( state == 2 ) && ( ( 65 <= c) && (c <= 90  ) ) ) { state = 2 ; temp[i] = c ; i++ ; continue ; }
    if ( ( state == 2 ) && ( ( c < 65 ) || ( c > 91  ) ) ) break ;

  }

  s = (char *) malloc( 21 ) ;
  for ( i = 0 ; i < 21 ; i++ ) s[i] = temp[i] ;

  return s ;
}

int compare( generic_ptr word1, generic_ptr word2 ) {

  return strcmp( (char *) word1, (char *) word2 )  ;

}

int main( int argc, char *argv[] ) {

  set setofwords1 ;
  set setofwords2 ;
  set setofwords3 ;
  set setofwords4 ;

  FILE *fin1 ;
  FILE *fin2 ;
  char *word ;

  fin1 =  fopen(argv[1] , "r" ) ;
  fin2 =  fopen(argv[2] , "r" ) ;

  init_set( &setofwords1 , n ) ; 
  init_set( &setofwords2 , n ) ; 
  init_set( &setofwords3 , n ) ; 
  init_set( &setofwords4 , n ) ; 

  while ( strlen( word = getword( fin1 ) ) != 0 ) set_insert( &setofwords1, (generic_ptr) word, compare ) ;
  printf("Set 1:\n" );   set_write( &setofwords1, write_word ) ;

  while ( strlen( word = getword( fin2 ) ) != 0 ) set_insert( &setofwords2, (generic_ptr) word, compare ) ;
  printf("\n\nSet 2:\n" ) ;
  set_write( &setofwords2, write_word ) ;

  printf( "\n\nThe union of these two sets of words is: \n") ;
  set_union( &setofwords1, &setofwords2, &setofwords3, compare, 21 ) ;
  set_write( &setofwords3, write_word ) ;

  printf( "\n\nThe intersection of these two sets of words is: \n") ;
  set_intersection( &setofwords1, &setofwords2, &setofwords4, compare, 21 ) ;
  set_write( &setofwords4, write_word ) ;
  
  printf("\n\n") ;

  fclose( fin1 ) ;
  fclose( fin2 ) ;

  return 0 ;

}
