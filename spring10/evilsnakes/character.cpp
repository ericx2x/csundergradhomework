/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: character.cpp                              */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include "character.h"

Character::Character( Level *lvl, DrawEngine *de,
		      int s_index, float x, float y,
		      int lives, char u, char d, char l, char r )
  : Sprite( lvl, de, s_index, x, y, lives ) {

	upKey = u ;
	downKey = d ;
	leftKey = l ;
	rightKey = r ;

	classID = CHARACTER_CLASSID ;
}

bool Character::keyPress( char c ) {

	if ( c == upKey ) {

		return move( 0, -1 ) ;
	}

	else if ( c == downKey ) {

		return move( 0, 1 ) ;
	}

	else if ( c == rightKey ) {

		return move( 1, 0 ) ;
	}

	else if ( c == leftKey ) {

		return move( -1, 0 ) ;
	}

	return false ;
}

void Character::addLives( int num ) {

	Sprite::addLives( num ) ;

	if ( Sprite::isAlive() ) {

		pos.x = 1 ;
		pos.y = 1 ;

		move( 0, 0 ) ;
	}
}
