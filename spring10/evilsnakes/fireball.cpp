/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: fireball.cpp                               */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include "fireball.h"

Fireball::Fireball( Level *lev, DrawEngine *de, int s_index, float x, float y, 
		    float xDir, float yDir, int i_lives ) :
  Sprite( lev, de, s_index, x, y, i_lives )
{
  facingDirection.x = xDir ;
  facingDirection.y = yDir ;

  classID = FIREBALL_CLASSID ;
}

void Fireball::idleUpdate( void ) {

  // if we can, move in the facing direction
  if ( Sprite::move( facingDirection.x, facingDirection.y ) ) {
    
    list <Sprite *>::iterator Iter ;
    
    // Iterate throught the list of sprites to check if we are at the same x, y as one of them
    for ( Iter = level->npc.begin() ; Iter != level->npc.end() ; Iter++ ) {
      
      // if the Sprite found is not ourself, and it shares the same x and y value - then this statement is true
      if ( (*Iter)->classID != classID &&
	   (int)(*Iter)->getX() == pos.x &&
	   (int)(*Iter)->getY() == pos.y ) {
	// if we hit a sprite, take a life away from that sprite
	(*Iter)->addLives( -1 ) ;
	// then disapear ( die )
	addLives( -1 ) ;
      }
    }
  }

  // if we don't hit anything just fade out ( die )
  else addLives( -1 ) ;
}
