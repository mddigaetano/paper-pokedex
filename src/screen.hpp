#ifndef SCREEN_H
#define SCREEN_H

#include <M5EPD.h>

#include "pokemon.hpp"

void draw_screen(M5EPD_Canvas* canvas, Pokemon* poke);

#endif