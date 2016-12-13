/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: game.cpp                                   */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include <sys/time.h>
#include <ncurses.h>
#include "game.h"

//We can use this macro to limit the frames per second of the game
// EASY=60 MEDIUM=30 HARD=15
#define GAME_SPEED 50

bool Game::menu( void ) {



}	

bool Game::run(void) {	    //This is the game loop-the heart of the program.

  struct timeval tv ;

  level = new Level( &drawArea );
  
  drawArea.createBackgroundTile( TILE_EMPTY, ' ' ) ;
  drawArea.createBackgroundTile( TILE_WALL, '#' ) ; 
  
  drawArea.createSprite( SPRITE_PLAYER, '0' ) ;
  drawArea.createSprite( SPRITE_ENEMY, '$' ) ;
  drawArea.createSprite( SPRITE_FIREBALL, '*' ) ;
  
  player = new Mage( level, &drawArea, 0 ) ;
  
  level->draw() ;	
  
  level->addPlayer( player ) ;
  level->addEnemies( 3 ) ;
  
  char key = ' ' ;
  timeout(0);			// makes ncurses not wait for a keypress
  gettimeofday( &tv, 0 ) ;
  lastTime = tv.tv_sec*1000 + tv.tv_usec/1000;

  frameCount = 0 ;
  
  while ( key != 'q' ) {
    
    while ( !getInput( &key) ) {
      
      timerUpdate() ;
      
    }    

    level->keyPress( key ) ;
    	
  }
  
  delete player ;
  
  return true ;
}

//This function checks whether the keyboard is pressed,
// and stores the value of the key if it is.
bool Game::getInput( char* c ){ 	

  *c = getch();
  return (*c==ERR ? false : true);
}

//This function controls the FPS of the game by comparing
//the current elapsed time to the set GAME_SPEED
void Game::timerUpdate(){           

  struct timeval tv ;

  gettimeofday( &tv, 0 ) ;

  double diff =  (tv.tv_sec*1000 + tv.tv_usec/1000) - lastTime ;

  if ( diff < GAME_SPEED ) 
    return ;

  level->update() ;
  refresh();

  frameCount++ ;	   //If enough time has elapsed, then update the frame
  gettimeofday( &tv, 0 ) ; //update tv

  mvprintw( 30, 0, "Time : %d", frameCount );

  lastTime = tv.tv_sec*1000 + tv.tv_usec/1000;   //reset lastTime current system time
}

