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
#include <time.h>


//We can use this macro to limit the frames per second of the game
// EASY=60 MEDIUM=30 HARD=15
#define GAME_SPEED 60	

bool Game::run(int J, int K, int I) {	    //This is the game loop-the heart of the program.

  struct timeval tv ;

  level = new Level( &drawArea );
  
  drawArea.createBackgroundTile( TILE_EMPTY, ' ' ) ;
  drawArea.createBackgroundTile( TILE_WALL, '#' ) ; 
  
  drawArea.createSprite( SPRITE_PLAYER, '0' ) ;
  drawArea.createSprite( SPRITE_ENEMY, '$' ) ;
  drawArea.createSprite( SPRITE_FIREBALL, '*' ) ;
  
  player = new Mage( level, &drawArea, SPRITE_PLAYER ) ;
  
  level->draw() ;	
  
  level->addPlayer( player ) ;
  level->addEnemies( 3 ) ;
  
  char key = ' ' ;
  timeout(0);			// makes ncurses not wait for a keypress
  gettimeofday( &tv, 0 ) ;
  lastTime = tv.tv_sec*1000 + tv.tv_usec/1000;

  timer = 30 ;
  frameCount = 0 ;
  enemynum = 3 ;  
  levelnum = 2 ;
  mvprintw( 0, 40, "Level = 1 " );
    mvprintw( 0, 30, "Time =    " );

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

  frameCount++ ;	   // If enough time has elapsed, then update the frame
  gettimeofday( &tv, 0 ) ; // update the timer


  /*This is where I make the timer. The time is printed on the top portion of the screen. You can see that it resets itself when it hits 0, then the level is increased by one while the game gets harder. Level is also printed onto the top portion of the screen.*/

 if((frameCount%30)==0){
    timer--;
    mvprintw( 0, 30, "Time = %d ", timer );
   
 if (timer ==0){
   level->addEnemies( enemynum += 3 ) ;  // this line makes the game get harder
      timer = 30;
      mvprintw(0, 40, "Level = %d ", levelnum++ );
     }
  }

  


  //reset lastTime to current system time
  lastTime = tv.tv_sec*1000 + tv.tv_usec/1000;   
}

