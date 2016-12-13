/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: sprite.cpp                                 */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include "sprite.h"
#include "character.h"

Sprite::Sprite( Level *lvl, DrawEngine *de, tsprite s_index,
		float x, float y, int i_lives )
{
  drawArea = de ;
  
  pos.x = x ;
  pos.y = y ;
  
  spriteIndex = s_index ;
  
  numLives = i_lives ;
  
  classID = SPRITE_CLASSID ;
  
  level = lvl ;
}

Sprite::~Sprite() {
  
  //erase sprite
  erase( pos.x, pos.y ) ;
}

vector Sprite::getPosition( void ) {
  
  return pos ;
}

float Sprite::getX( void ) {
  
  return pos.x ;
}

float Sprite::getY( void ) {
  
  return pos.y ;
}

void Sprite::addLives( int num ) {

  numLives += num ;
}

int Sprite::getLives( void ) {

  return numLives ;
}

bool Sprite::isAlive( void ) {

  return ( numLives > 0 ) ;
}

void Sprite::idleUpdate( void ) {

  // this is for the inherited classes...

}
bool Sprite::move( float x, float y ) {

  int xpos = (int)(pos.x + x) ;
  int ypos = (int)(pos.y + y) ;

  if ( isValidLevelMove( xpos, ypos ) ) {

    // erase sprite at current location
    erase( pos.x, pos.y ) ;

    // update location
    pos.x += x ;
    pos.y += y ;

    // update the facing direction
    facingDirection.x = x ;
    facingDirection.y = y ;

    // redraw at updated location
    draw( pos.x, pos.y ) ;
    return true ;
  }

  return false ;
}

// the draw() and erase() functions utilizes 
// the functionality of the DrawEngine class's draw and erase functions

void Sprite::draw( float x, float y ) {

  drawArea->drawSprite( spriteIndex, (int)x, (int)y ) ;
}

void Sprite::erase( float x, float y ) {

  drawArea->eraseSprite( (int)x, (int)y ) ;
}

bool Sprite::isValidLevelMove( int xpos, int ypos ) {

  if ( level->level[xpos][ypos] != TILE_WALL )
    return true ;

  return false ;
}
