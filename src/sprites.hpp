#ifndef SPRITES_H
#define SPRITES_H

#define SPRITE_SIZE_BASE 96
#define SPRITE_SIZE_MULTIPLIER 3
#define SPRITE_SIZE (SPRITE_SIZE_BASE * SPRITE_SIZE_MULTIPLIER)
#define SPRITE_OFFSET_FROM_BORDER ((TYPE_SPRITE_WIDTH - SPRITE_SIZE) / 2)

#define TYPE_SPRITE_BASE_WIDTH 200
#define TYPE_SPRITE_BASE_HEIGHT 40
#define TYPE_SPRITE_MULTIPLIER 2
#define TYPE_SPRITE_WIDTH (TYPE_SPRITE_BASE_WIDTH * TYPE_SPRITE_MULTIPLIER)
#define TYPE_SPRITE_HEIGHT (TYPE_SPRITE_BASE_HEIGHT * TYPE_SPRITE_MULTIPLIER)

#include <M5EPD.h>

#include "pokemon.hpp"

void draw_sprites(M5EPD_Canvas* canvas, const Pokemon* poke);

#endif