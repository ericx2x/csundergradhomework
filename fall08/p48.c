/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 48: Non-polymorphic Linked List                                   */
/*                                                                           */
/* Approximate completion time: 24 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node { int num ; struct node *next ; } NODE ;  

void printlist( NODE *l ) {

  if ( l == NULL )  return ;
  printlist( l -> next ) ;
  printf( " %d ", l -> num ) ;
  return ;

}

int main( int argc, char *argv[] ) {

  NODE *p ;
  NODE *temp ;
  int n ; 
  int i ;
  int number ;

  printf("\nHow many numbers do you want to enter? ") ;

  scanf( "%d", &n ) ;

  p = NULL ;

  for ( i = 1 ; i <= n ; i++ ) {

    temp = ( NODE * ) malloc ( sizeof ( NODE ) ) ;

    printf( "Please enter a number: " ) ;

    scanf( "%d", &number ) ;

    temp -> num = number ;

    temp -> next = p ;

    p = temp ;

  }

  printf( "\n\n" ) ;

  printlist ( p ) ;

  printf( "\n\n" ) ;

  return 0 ;

}
