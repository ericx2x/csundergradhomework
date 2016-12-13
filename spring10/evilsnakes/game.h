/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: game.h                                     */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#ifndef GAME_H
#define GAME_H

#include "drawEngine.h"
#include "level.h"
#include "character.h"
#include "mage.h"

class Game {

 public: 

  Game(int w, int h) : drawArea(w,h) {}
  bool run(void) ;
  bool menu(void) ;

 private:

  Level *level ;

  long frameCount ;
  double lastTime ;

  DrawEngine drawArea ;

 protected:

  Mage *player ;

  bool getInput( char* key ) ;
  void timerUpdate(void) ;

} ;

#endif 
