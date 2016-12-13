/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 66: Word Reversal (medium difficulty)                             */
/*                                                                           */
/* Approximate completion time: 4 hours and 23 mintues                       */
/*****************************************************************************/

#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ) {

  char* a = "hello world";

  char* tmp = " ";

  strncpy(tmp, a, 5);

  strncpy(a, a+6, 5);

  strcpy( a+6 ,tmp);

  return 0 ;

}
