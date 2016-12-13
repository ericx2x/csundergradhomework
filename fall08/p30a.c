/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program ^:                                          */
/*                                                                           */
/* Approximate completion time:                              */
/*****************************************************************************/

#include <stdio.h>
int gay( int a[][3] ){

  int i, sum ;

  for ( i=0;i<3;i++) sum = a[i][i];
  return sum ;


}



int main( int argc, char *argv[] ) {

  int a[3][3] = { { 1, 2, 3 } ,
	      { 1, 2, 3 } ,
	      { 1 ,2, 3 } } ;
  int i ;
  for( i = 0 ; i<3;i++)
  printf( "%d", gay(a) ) ;

  /* fclose( fin ) ; */

  return 0 ;

}
