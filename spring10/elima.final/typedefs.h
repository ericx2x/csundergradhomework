#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum {
  
  SPRITE_PLAYER,
  SPRITE_ENEMY,
  SPRITE_FIREBALL
  
} tsprite;

typedef enum {
  
  TILE_EMPTY,
  TILE_WALL
  
} tile;

typedef enum {

  SPRITE_CLASSID,
  CHARACTER_CLASSID,
  ENEMY_CLASSID,
  FIREBALL_CLASSID,
  MAGE_CLASSID

} spriteclass;

#endif
