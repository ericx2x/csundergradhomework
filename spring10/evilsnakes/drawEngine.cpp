/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: drawEngine.cpp                             */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include <stdlib.h>
#include <ncurses.h>
#include "drawEngine.h"
#include "sprite.h"

using namespace std ;

bool DrawEngine::curses_started = false ;

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

int DrawEngine::createSprite( int index, char c ) {

  // make sure index is within bounds of the array
  if ( index >= 0 && index < 16 ) {

    spriteImage[index] = c ;
    return 1 ;
  }

  // if out of range, return -1
  return -1 ;
}

void DrawEngine::deleteSprite( int index ) {

  // In this implementation this is not needed, becuase we are not 
  // dynamically allocating space for sprites. It is here for conceptual purposes only.
}

void DrawEngine::drawSprite( int index, int posx, int posy ) {

  // go to the correct location
  gotoxy( posx, posy ) ;

  // print the character in correct color
  
   if ( index == MAGE_CLASSID )
     addch(spriteImage[index] | COLOR_PAIR(2) ) ;

   else if ( index == FIREBALL_CLASSID )
     addch(spriteImage[index] | COLOR_PAIR(3) ) ;

   else if ( index == ENEMY_CLASSID )
     addch(spriteImage[index] | COLOR_PAIR(5) ) ;

}

void DrawEngine::eraseSprite( int posx, int posy ) {

  gotoxy( posx, posy ) ;

  addch(' ') ;
  
}

void DrawEngine::setMap( tile **data) {

  map = data ;
}

void DrawEngine::createBackgroundTile( int index, char c ) {

  if ( index >= 0 && index < 16 )
    tileImage[index] = c ;
}

void DrawEngine::drawBackground( void ) {

  if ( map ) {

    for ( int y = 0 ; y < screenHeight ; y++ ) {			

      // start at the correct spot
      gotoxy( 0, y ) ;

      for ( int x = 0 ; x < screenWidth ; x++ ) {
	// lookup the correct character to print using the index
	addch( tileImage[ map[x][y] ] | COLOR_PAIR(2) ) ;
	
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

   // initialize all color combinations used
    init_pair(1, COLOR_WHITE, COLOR_BLACK) ;   // color for player
    init_pair(2, COLOR_RED,     COLOR_GREEN) ; // color for fireball
    init_pair(3, COLOR_GREEN,   COLOR_WHITE) ; // color for snakes
    init_pair(4, COLOR_WHITE,   COLOR_BLUE) ; // color for background
    init_pair(5, COLOR_BLACK,   COLOR_RED) ; // color for walls


    intrflush(stdscr, false) ;
    keypad(stdscr, true) ;
    atexit(DrawEngine::endCurses) ;  // Make sure endCurses() is called when program ends.
    curses_started = true ;
  }
}
