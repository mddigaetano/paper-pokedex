#ifndef INFO_H
#define INFO_H

#include <M5EPD.h>

#include "sprites.hpp"
#include "pokemon.hpp"

#define TITLE_X (SCREEN_WIDTH / 2)
#define TITLE_Y 10

void draw_info(M5EPD_Canvas* canvas, Pokemon* poke);

#endif