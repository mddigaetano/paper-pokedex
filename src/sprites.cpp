#include <stdlib.h>
#include <stdio.h>
#include <M5EPD.h>

#include "layout.hpp"
#include "config.hpp"
#include "pokemon.hpp"
#include "sprites.hpp"

void draw_pokemon(M5EPD_Canvas* canvas, uint16_t pokeid);
void draw_types(M5EPD_Canvas* canvas, const char type1[], const char type2[]);

void draw_sprites(M5EPD_Canvas* canvas, Pokemon* poke) {
  draw_pokemon(canvas, poke->id);
  draw_types(canvas, poke->type1, poke->type2);
}

void draw_pokemon(M5EPD_Canvas* canvas, uint16_t pokeid) {

  char pokefile[20];

  sprintf(pokefile, "/spr/pkmn/%hu.png", pokeid);
#ifdef SERIAL_ENABLE
  Serial.println(pokefile);
#endif

#ifdef SHOW_BOUNDING_BOXES
  canvas->drawRect(
    POKEBORDER_X, POKEBORDER_Y,
    POKEBORDER_WIDTH, POKEBORDER_HEIGHT,
    PAPER_BLACK
  );
  canvas->drawRect(
    POKESPRITE_X, POKESPRITE_Y,
    POKESPRITE_SIZE, POKESPRITE_SIZE,
    PAPER_BLACK
  );
  Serial.println("pokebox drawn");
#endif
  canvas->drawPngFile(
#ifdef SD_ENABLE
    SD,
#else
    SPIFFS,
#endif
    pokefile,
    POKESPRITE_X, POKESPRITE_Y,
    POKESPRITE_SIZE, POKESPRITE_SIZE,
    0, 0,
    SPRITE_SIZE_MULTIPLIER
  );
#ifdef SERIAL_ENABLE
  Serial.println("pokesprite drawn");
#endif
}

void draw_types(M5EPD_Canvas* canvas, const char type1[], const char type2[]) {

  char typefile1[17];
  char typefile2[17];

  sprintf(typefile1, "/spr/type/%s.png", type1);
#ifdef SERIAL_ENABLE
  Serial.println(typefile1);
#endif
  sprintf(typefile2, "/spr/type/%s.png", type2);
#ifdef SERIAL_ENABLE
  Serial.println(typefile2);
#endif

#ifdef SHOW_BOUNDING_BOXES
  canvas->drawRect(
    TYPE1SPRITE_X, TYPE1SPRITE_Y,
    TYPESPRITE_WIDTH, TYPESPRITE_HEIGHT,
    PAPER_BLACK
  );
#endif
  canvas->drawPngFile(
#ifdef SD_ENABLE
    SD,
#else
    SPIFFS,
#endif
    typefile1,
    TYPE1SPRITE_X, TYPE1SPRITE_Y,
    TYPESPRITE_WIDTH, TYPESPRITE_HEIGHT,
    0, 0,
    TYPE_SPRITE_MULTIPLIER
  );
  if (strcmp(type2, "0") != 0) {
#ifdef SHOW_BOUNDING_BOXES
    canvas->drawRect(
      TYPE2SPRITE_X, TYPE2SPRITE_Y,
      TYPESPRITE_WIDTH, TYPESPRITE_HEIGHT,
      PAPER_BLACK
    );
#endif
    canvas->drawPngFile(
#ifdef SD_ENABLE
      SD,
#else
      SPIFFS,
#endif
      typefile2,
      TYPE2SPRITE_X, TYPE2SPRITE_Y,
      TYPESPRITE_WIDTH, TYPESPRITE_HEIGHT,
      0, 0,
      TYPE_SPRITE_MULTIPLIER
    );
  }
#ifdef SERIAL_ENABLE
  Serial.println("types drawn");
#endif
}