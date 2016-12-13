/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 11: Equal to Zero?                  */
/*                                             */
/* Approximate completion time: 5 minutes      */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int num; 

  printf( "Please, enter a number to check if it is equal to zero." ) ;

  scanf( "%d" , &num ) ; 

  if( num != 0 ) 
    printf("The number is not equal to zero.\n");

  else
    printf("The number is equal to zero.\n");

  return 0 ;

}
