/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: drawEngine.h                               */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#ifndef DRAWENGINE_H
#define DRAWENGINE_H

#include <ncurses.h>
#include "typedefs.h"

class DrawEngine {

  friend class Level;

 public:

  DrawEngine( int xSize = 30, int ySize = 20 ) ;
  ~DrawEngine() ;

  int createSprite( tsprite, chtype ) ;
  void deleteSprite( tsprite ) ;

  void drawSprite( tsprite, int, int ) ;
  void eraseSprite( int, int ) ;

  void setMap( tile ** ) ;
  void createBackgroundTile( tile, chtype ) ;
  void drawBackground( void ) ;

 protected:

  tile **map ;
  int screenWidth, screenHeight ;
  // hold 16 unique sprites
  chtype spriteImage[16] ;
  // hold 16 unique background tiles
  chtype tileImage[16] ;

 private:

  void gotoxy( int posx, int posy ) ;
  void cursorVisibility( bool visibility ) ;
  // This is set to true the first time the program enters curses mode.
  static bool curses_started;
  static void startCurses(void);
  static void endCurses(void);
} ;

#endif
