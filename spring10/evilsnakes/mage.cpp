#include "mage.h"
/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: mage.cpp                                   */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include "fireball.h"
#include "level.h"

Mage::Mage( Level *l, DrawEngine *de, int s_index, float x, float y, 
	int lives, char spell_key, char up_key, char down_key, char left_key, char right_key )
	: Character( l, de, s_index, x, y, lives, up_key, down_key, left_key, right_key ) {

	spellKey = spell_key ;
	classID = MAGE_CLASSID ;
}

bool Mage::keyPress( char c ) {

	bool val = Character::keyPress( c ) ;

	// test if a a key was pressed ( that was not w, s, a, or d )
	if ( val == false ) {

		if ( c == spellKey ) {

			// if the key pressed was the spell key, cast spell
			castSpell() ;
			return true ;
		}
	}

	return val ;
}

void Mage::castSpell( void ) {

	Fireball *temp = new Fireball( level, drawArea, SPRITE_FIREBALL, 
		(int)pos.x + facingDirection.x, (int)pos.y + facingDirection.y, 
		facingDirection.x, facingDirection.y ) ;

	level->addNPC( (Sprite *)temp ) ;
}
