/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 66: Word Reversal (medium difficulty)                             */
/*                                                                           */
/* Approximate completion time: 4 hours and 23 mintues                       */
/*****************************************************************************/

#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] ) {

  char s[60] ;
  char last ;
  char store[20][60];
  int i = 0 ;

  while(1){

    i = 0 ;

    do{

      scanf( "%s", &s ) ;
      last = s[strlen(s) - 1] ;

      strcpy( store[i], s ) ;

      i++;

    }while( last != '.');

    store[i - 1][strlen(s) - 1] = '\0';

    i--;

    for(; i >= 0 ; i-- ) {

      printf( "%s ", store[i] ) ;

    }

    putchar('\n');

  }

  return 0 ;

}
