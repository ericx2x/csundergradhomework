/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 21: Tromino Tiling                        */
/*                                                   */
/* Approximate completion time: 7 hours              */
/*****************************************************/

#include <stdio.h>

#define MAX_WIDTH 128
#define HWIDTH ( width / 2 )

#define RIGHT ( (width / 2 ) + base_x )
#define LEFT ( ( ( width / 2 ) - 1 ) + base_x )
#define BOTTOM ( ( width / 2 )  + base_y )
#define TOP ( ( ( width / 2 ) - 1 _ + base_y )
	      
	      int symbol = ' ' ;
	      void tile ( int *board, int width, int base_x, int base_y, int unused_x, int unused y) ;
	      void fill( int *board, int x, int y ) ;
	      int find_quadrant( int width, int base_x, int base_y, int x, int y ) ;
	      
	      int main( int argc, char *argv[] ) {
		
		int board[MAX_WIDTH][MAX_WIDTH] ; 
		int width, unused_x, unused_y ;
		int i, j ;
		
		width = atoi( argv[1] ) ;
		unused_x = atoi( argv[2] ) ;
		unused_y = atoi( argv[3] ) ;
		
		file( board[0], unused_x, unused_y ) ;
		symbol = 32 ;
		
		tile( board[0], width, 0, 0, unused_x, unused_y ) ;
		
		for( i = 0 ; i < width ; i++ ){
		  for( j = 0 ; j < width ; j++)
		    printf("%c ", board[i][j]) ;
    putchar('\n') ;
  }
  return 0 ;
  
}
	      
	      void tile( int *board, int width, int base_x, int base_y, int unused_x, int unused_y) {
		
		if( width == 1 ) return ;
		
		symbol++ ;
		
		switch( find_quadrant( width, base_x, base_y, unused_x, unused_y )){
		  
		case 0 :
		  
    fill( board, RIGHT, TOP ) ;
    fill( board, LEFT, BOTTOM ) ;
    fill( board, RIGHT, BOTTOM ) ;

    tile( board, HWIDTH, base_x, base_y, unused_x, unused_y ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y, RIGHT, TOP ) ;
    tile( board, HWIDTH, base_x, base_y + HWIDTH, LEFT, BOTTOM ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y + HWIDTH, RIGHT, BOTTOM ) ;

    break ;

  case 1 :

    fill( board, LEFT, TOP ) ;
    fill( board, LEFT, BOTTOM ) ;
    fill( board, RIGHT, BOTTOM ) ;

    tile( board, HWIDTH, base_x, base_y, LEFT, TOP ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y, unused_x, unused_y ) ;
    tile( board, HWIDTH, base_x, base_y + HWIDTH, LEFT, BOTTOM ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y + HWIDTH, RIGHT, BOTTOM ) ;

 break ;

  case 2 :

    fill( board, LEFT, TOP ) ;
    fill( board, RIGHT, TOP ) ;
    fill( board, RIGHT, BOTTOM ) ;

    tile( board, HWIDTH, base_x, base_y, LEFT, TOP ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y, RIGHT, TOP ) ;
    tile( board, HWIDTH, base_x, base_y + HWIDTH, unused_x, unused_y ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y + HWIDTH, RIGHT, BOTTOM ) ;


 break ;

    case 3 ; 

    fill( board, LEFT, TOP ) ;
    fill( board, RIGHT, TOP ) ;
    fill( board, LEFT, BOTTOM ) ;

    tile( board, HWIDTH, base_x, base_y, LEFT, TOP ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y, RIGHT, TOP ) ;
    tile( board, HWIDTH, base_x, base_y + HWIDTH, LEFT, BOTTOM ) ;
    tile( board, HWIDTH, base_x + HWIDTH, base_y + HWIDTH, unused_x, unused_y ) ;

 break ;
  }
}

void fill( int *board, int x, int y ) {

  *( board + x + ( y * MAX_WIDTH ) ) = symbol ;

}

int find_quadrant( int width, int base_x, int base_y, int x, int y ) {

  if( x < HWIDTH + base_x )
    return ( y < HWIDTH + base_y) ? 0 : 2 ;
  else
    return ( y < HWIDTH + base_y ) ? 1 : 3 ;

}
