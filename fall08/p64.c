/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 64: Recursive Tiling                                              */
/*                                                                           */
/* Approximate completion time: 5 hours and 13 minutes                       */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define HWIDTH (width / 2)
#define edgewidth 128

#define RIGHT ( (width / 2) + x1 )
#define LEFT ( ( ( width / 2 ) - 1 ) + x1 )
#define BOTTOM ( ( width / 2 ) + y1 )
#define TOP ( ( ( width / 2 ) - 1 ) + y1 )

int character = ' ' ;

void place( int *A, int width, int x1, int y1, int move_x, int move_y) ;

void walk( int *A, int x, int y ) ;

int find_quadrant( int width, int x1, int y1, int x, int y ) ;

int main ( int argc, char *argv[] ) {

  int A[edgewidth][edgewidth] ;
  int width, move_x, move_y ;
  int i, j ;

  width = atoi( argv[1] ) ;
  move_x = atoi( argv[2] ) - 1 ;
  move_y = atoi( argv[3] ) - 1 ;

  walk( A[0], move_x, move_y );
  character = 32 ;

  place( A[0], width, 0, 0, move_x, move_y ) ;

  for( i = 0; i < width ; i++ ) {

    for( j = 0; j < width ; j++ )
      printf("%c ", A[j][i]) ;

    putchar( '\n' ) ;

  }

  return 0;

}

void place( int *A, int width, int x1, int y1, int move_x, int move_y){

  if( width == 1) return ;

  character++ ;

  switch( find_quadrant( width, x1, y1, move_x, move_y ) ) {

  case 0:

    walk( A, RIGHT, TOP ) ;
    walk( A, LEFT, BOTTOM ) ;
    walk( A, RIGHT, BOTTOM ) ;

    place( A, HWIDTH, x1, y1, move_x, move_y ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1, RIGHT, TOP ) ;
    place( A, HWIDTH, x1, y1 + HWIDTH, LEFT, BOTTOM ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1 + HWIDTH, RIGHT, BOTTOM ) ;

    break ;

  case 1:

    walk( A, LEFT, TOP ) ;
    walk( A, LEFT, BOTTOM ) ;
    walk( A, RIGHT, BOTTOM ) ;

    place( A, HWIDTH, x1, y1, LEFT, TOP ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1, move_x, move_y ) ;
    place( A, HWIDTH, x1, y1 + HWIDTH, LEFT, BOTTOM ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1 + HWIDTH, RIGHT, BOTTOM ) ;

    break;

  case 2:

    walk( A, LEFT, TOP ) ;
    walk( A, RIGHT, TOP ) ;
    walk( A, RIGHT, BOTTOM ) ;

    place( A, HWIDTH, x1, y1, LEFT, TOP ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1, RIGHT, TOP ) ;
    place( A, HWIDTH, x1, y1 + HWIDTH, move_x, move_y ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1 + HWIDTH, RIGHT, BOTTOM ) ;

    break ;

  case 3:

    walk( A, LEFT, TOP ) ;
    walk( A, RIGHT, TOP ) ;
    walk( A, LEFT, BOTTOM ) ;

    place( A, HWIDTH, x1, y1, LEFT, TOP ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1, RIGHT, TOP ) ;
    place( A, HWIDTH, x1, y1 + HWIDTH, LEFT, BOTTOM ) ;
    place( A, HWIDTH, x1 + HWIDTH, y1 + HWIDTH, move_x, move_y ) ;

    break ;

  }

}


void walk( int *A, int x, int y ) {

  *(A + x + ( y * edgewidth ) ) = character ;

}


int find_quadrant( int width, int x1, int y1, int x, int y ) {

  if( x < HWIDTH + x1 )
    return ( y < HWIDTH + y1 ) ? 0 : 2 ;
  else
    return ( y < HWIDTH + y1 ) ? 1 : 3 ;

}
