/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: level.h                                    */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#ifndef LEVEL_H
#define LEVEL_H

#include <list>

using std::list ;

class Character ;
class Sprite ;

class Level {

 public:

  Level( DrawEngine* );
  virtual ~Level() ;

  void addPlayer( Character* ) ;
  void update( void ) ;
  void draw( void ) ;
  bool keyPress( char ) ;

  void addEnemies( int num ) ;
  void addNPC( Sprite* ) ;

 protected:

  void createLevel( void ) ;

 private:

  int width ;
  int height ;

  tile **level ;

  Character *player ;
  DrawEngine *drawArea ;

  friend class Sprite ;

 public:

  // make a list of Sprite pointers, along with an iterator
  list <Sprite *> npc ;
  list <Sprite *>::iterator Iter ;
} ;

#endif
