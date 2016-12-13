/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 71: Wallpaper                                                     */
/*                                                                           */
/* Approximate completion time: 45 minutes                                   */
/*****************************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {
  
  float corna, cornb, side, x, y ; 

  int c, i, j ;
  char a[100][100] ;
  
  printf("Please, enter in the corna number. \n" ) ;
  scanf( "%f", &corna ) ;
  printf("Please, enter in the cornb number. \n" ) ;
  scanf( "%f", &cornb ) ;
  printf("Please, enter in the side number. \n" ) ;
  scanf( "%f", &side ) ;

  for( i = 0 ; i < 100 ; i++ ) {

    for( j = 0 ; j < 100 ; j++ ) {

      x = corna + ( i * ( side / 100 ) ) ;
      y = cornb + ( i * ( side / 100 ) ) ; 
      c = (int)( ( x*x ) + ( y*y ) ) ;

      if ( (c % 2) == 0 ) a[i][j]= '7' ;
     
      else a[i][j] = '9';  
			  
  }
}

  for( i = 0 ; i < 100 ; i++ )
     for( j = 0 ; j < 100 ; j++ ) 
       printf("%c", a[i][j]) ;

  putchar('\n'); 

  return 0 ;

}
