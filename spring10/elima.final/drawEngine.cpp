/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: drawEngine.cpp                             */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include <stdlib.h>
#include "drawEngine.h"
#include "sprite.h"

using namespace std ;

bool DrawEngine::curses_started = false;

DrawEngine::DrawEngine( int xSize, int ySize ) {

  startCurses() ;
  screenWidth = xSize ;
  screenHeight = ySize ;

  // set cursor visibility to false
  cursorVisibility( false ) ;
}

DrawEngine::~DrawEngine() {

  // set cursor visibility to true
  cursorVisibility( true ) ;
  endCurses() ;
}

int DrawEngine::createSprite( tsprite index, chtype c ) {

  // make sure index is within bounds of the array
  if ( index >= 0 && index < 16 ) {

    spriteImage[index] = c ;
    return 1 ;
  }

  // if out of range, return -1
  return -1 ;
}

void DrawEngine::deleteSprite( tsprite index ) {

  // In this implementation this is not needed, because we are not dynamically
  // allocating space for sprites.  It is here for conceptual purposes only.

}

void DrawEngine::drawSprite( tsprite index, int posx, int posy ) {

  // go to correct location
  gotoxy( posx, posy ) ;

  /*This is where color gets added. The mage (0) is yellow, snakes ($) are green, fireball (*) is red, and walls (#) are white. This is all done using ncurses functionality.*/

  if ( spriteImage[index] == '0' ) attron( COLOR_PAIR(1) );
  if ( spriteImage[index] == '$' ) attron( COLOR_PAIR(2) );
  if ( spriteImage[index] == '*' ) attron( COLOR_PAIR(3) );
  if ( spriteImage[index] == '#' ) attron( COLOR_PAIR(4) );

  // output the correct sprite to the buffer
  addch(spriteImage[index]) ;

}

void DrawEngine::eraseSprite( int posx, int posy ) {

  gotoxy( posx, posy ) ;

  addch(' ') ;
  
}

void DrawEngine::setMap( tile **data) {

  map = data ;
}

void DrawEngine::createBackgroundTile( tile index, chtype c ) {

  if ( index >= 0 && index < 16 )
    tileImage[index] = c ;
}

void DrawEngine::drawBackground( void ) {

  if ( map ) {

    for ( int y = 0 ; y < screenHeight ; y++ ) {			
      for ( int x = 0 ; x < screenWidth ; x++ ) {
	gotoxy(x, y);
	// output only wall tiles
	if (map[x][y] == TILE_WALL)
	  addch( tileImage[ map[x][y] ] );
      }
    }
  }
}

void DrawEngine::gotoxy( int posx, int posy ) {

  move( posy, posx ) ; //move  
	
}

void DrawEngine::cursorVisibility( bool visibility ) {

  curs_set( visibility ) ;
	
}


/*
 * This will exit curses mode and return the console to the usual
 * line-oriented input/output mode.  If it is called when curses
 * mode is not in effect, it will have no effect.
 *
 */
void DrawEngine::endCurses(void) {
  if (curses_started && !isendwin())
    endwin() ;
}

/*
 * This will put the console into curses mode.  If curses mode is being
 * entered for the first time, the screen will be cleared.  If it is 
 * being re-entered after a call to endCurses(), then the previous
 * screen contents will be restored.
 */
void DrawEngine::startCurses(void) {
  if (curses_started) {
    refresh() ;
  }
  else {
    initscr() ;
    cbreak() ;
    noecho() ;
    start_color() ; // start color console mode


    //This choses the forground and background for the pairs.    
    init_pair( 1, COLOR_YELLOW, COLOR_BLACK );
    init_pair( 2, COLOR_GREEN, COLOR_BLACK );
    init_pair( 3, COLOR_RED, COLOR_BLACK );
    init_pair( 4, COLOR_WHITE, COLOR_BLACK );

    intrflush(stdscr, false) ;
    keypad(stdscr, true) ;
    // Make sure endCurses() is called when program ends.
    atexit(DrawEngine::endCurses) ;  
    curses_started = true ;
  }
}
