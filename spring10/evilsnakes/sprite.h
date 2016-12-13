/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: sprite.h                                   */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#ifndef SPRITE_H
#define SPRITE_H

#include "drawEngine.h"
#include "level.h"

enum {

  SPRITE_CLASSID,
  CHARACTER_CLASSID,
  ENEMY_CLASSID,
  FIREBALL_CLASSID,
  MAGE_CLASSID
} ;

struct vector {

  float x ;
  float y ;
} ;

class Sprite {

 public:

  Sprite( Level *lvl, DrawEngine *de, int s_index, float x = 1, float y = 1, int i_lives = 1 ) ;
  virtual ~Sprite() ;

  vector getPosition( void ) ;
  float getX( void ) ;
  float getY( void ) ;

  virtual void addLives( int num = 1 ) ;
  int getLives( void ) ;
  bool isAlive( void ) ;

  virtual void idleUpdate( void ) ;

  virtual bool move( float x, float y ) ;

  int classID ;

 protected:

  Level *level ;
  DrawEngine *drawArea ;
  vector pos ;
  int spriteIndex ;
  int numLives ;

  vector facingDirection ;
  void draw( float x, float y ) ;
  void erase( float x, float y ) ;

  bool isValidLevelMove( int xpos, int ypos ) ;

} ;

#endif
