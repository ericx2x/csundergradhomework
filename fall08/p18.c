/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 18: Argv                            */
/*                                             */
/* Approximate completion time: 20 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int i ;

  for( i = 0 ; i < argc ; i++ ) printf("%s\n" , argv[i] ) ;

  return 0 ;

}
