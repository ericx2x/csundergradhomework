/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: level.cpp                                  */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include <stdlib.h> //needed for rand()
#include <time.h>
#include "character.h"
#include "enemy.h"
#include "level.h"

Level::Level( DrawEngine *de ) {

  drawArea = de ;
  width = de->screenWidth;
  height = de->screenHeight;

  // initialize player to NULL
  player = 0 ;


  // allocate memory for character arrays ( Level )
  level = new tile *[width] ;

  for ( int x = 0 ; x < width ; x++ )
    level[x] = new tile[height] ;

  // call createLevel() only once
  createLevel() ;

  //set the map
  drawArea->setMap( level ) ;
}

Level::~Level() {

  // delete the array of characters first
  for ( int x = 0 ; x < width ; x++ ) 
    delete [] level[x] ;

  // now delete the array of character pointers
  delete [] level ;

  // now delete all the sprites that still exist in the level to avoid memory leaks
  for ( Iter = npc.begin() ; Iter != npc.end() ; Iter++ ) 
    delete (*Iter) ;	
}

void Level::createLevel( void ) {

  // This function initializes all the characters in the array as either a space or a wall 

  srand(time(0));

  for ( int x = 0 ; x < width ; x++ ) {

    for ( int y = 0 ; y < height ; y++ ) {

      int chance = rand() % 100 ;

      // make sure all the sides are walls ( fence in the level )
      if ( y == 0 || y == height - 1 || x == 0 || x == width - 1 ) {

	level[x][y] = TILE_WALL ;
      }

      // now fill the rest of the level based on 90% chance of empty space
      else {

	if ( chance < 80 )
	  level[x][y] = TILE_EMPTY ;
	else
	  level[x][y] = TILE_WALL ;
      }
    }
  }
}

void Level::draw( void ) {

  drawArea->drawBackground() ;
}

void Level::addPlayer( Character *p ) {

  player = p ;
}

bool Level::keyPress( char c ) {

  // this just passes on the functionality to the Character class's keyPress

  if ( player ) 
    if ( player->keyPress(c) )
      return true ;

  return false ;
}

void Level::update( void ) {

  draw() ;
  player->idleUpdate() ;

  for ( Iter = npc.begin() ; Iter != npc.end() ; Iter++ ) {

    (*Iter)->idleUpdate() ;

    if ( (*Iter)->isAlive() == false ) {

      // set temp to point to Sprite in the list
      Sprite *temp = *Iter ;

      // decrement the list iterator
      Iter-- ;

      // delete the Sprite ( free memory )
      delete temp ;

      // remove the Sprite from the list
      npc.remove( temp ) ;
    }
    else {
      drawArea->drawSprite( SPRITE_PLAYER, (int)player->getX(), (int)player->getY() ) ;
    }
  }
}

void Level::addEnemies( int num ) {

  int i = num ;

  while ( i > 0 ) {

    // give a value between 0 and 1 ( percentage ) to find an open spot to place
    int xpos = int((float(rand() % 100) / 100) * (width - 2 ) + 1 ) ;
    int ypos = int((float(rand() % 100) / 100) * (height - 2 ) + 1 ) ;

    if ( level[xpos][ypos] != TILE_WALL ) {

      // create a new Enemy
      Enemy *temp = new Enemy( this, drawArea, SPRITE_ENEMY, float(xpos), float(ypos), 1 ) ;

      temp->addGoal( player ) ;

      addNPC( temp ) ;

      i-- ;
    }
  }
}

void Level::addNPC( Sprite *spr ) {

  npc.push_back( spr ) ;
}
