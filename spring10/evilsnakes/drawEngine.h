/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: drawEngine.h                               */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#ifndef DRAWENGINE_H
#define DRAWENGINE_H

#include "typedefs.h"

class DrawEngine {

  friend class Level;

 public:

  DrawEngine( int xSize = 30, int ySize = 20 ) ;
  ~DrawEngine() ;

  int createSprite( int index, char c ) ;
  void deleteSprite( int index ) ;

  void drawSprite( int index, int posx, int posy ) ;
  void eraseSprite( int posx, int posy ) ;

  void setMap( tile ** ) ;
  void createBackgroundTile( int index, char c ) ;
  void drawBackground( void ) ;

 protected:

  tile **map ;
  int screenWidth, screenHeight ;
  // static space to hold 16 unique sprites
  char spriteImage[16] ;
  char tileImage[16] ;

 private:

  void gotoxy( int posx, int posy ) ;
  void cursorVisibility( bool visibility ) ;
  static bool curses_started;   // This is set to true the first time
  // the program enters curses mode.
  static void startCurses(void);
  static void endCurses(void);
} ;

#endif
