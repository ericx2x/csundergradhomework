/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 82: Reverse the Last n Bits                                       */
/*                                                                           */
/* Approximate completion time: 49 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int reverse ( int x , int n ) {

    int answer = x, reversex = 0, i;

    for (i = 0; i < n; i++) {
      
      if (x % 2 == 1)
	reversex += 1;
      
      reversex = reversex << 1;
      x = x >> 1;
      
    }

    reversex = reversex >> 1;
    
    answer = answer >> n;
    answer = answer << n;
    answer = answer + reversex;


    return answer;
  
}

int main( int argc, char *argv[] ) {

  int i ;

  for ( i = 0 ; i < 16 ; i++ )

    printf( "%d %d \n", i, reverse( i, atoi( argv[1] ) ) ) ;

  return 0 ;

}
