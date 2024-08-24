#include "config.hpp"
#include "pokemon.hpp"
#include "screen.hpp"

#include <M5EPD.h>

M5EPD_Canvas canvas(&M5.EPD);

void setup() {
    Pokemon selected;

    M5.begin(
        false,
#ifdef SD_ENABLE
        true,
#else
        false,
#endif
#ifdef SERIAL_ENABLE
        true,
#else
        false,
#endif
#ifdef BATTERY_LEVEL_ENABLE
        true,
#else
        false,
#endif
        false
    );
#ifdef SERIAL_ENABLE
    Serial.println("first begin");
#endif
#ifdef RTC_ENABLE
    M5.RTC.begin();
#endif
#ifdef SERIAL_ENABLE
    Serial.println("RTC begin");
#endif
#ifdef SD_ENABLE
    SD.begin();
#ifdef SERIAL_ENABLE
    Serial.println("SD begin");
#endif
#else
    SPIFFS.begin();
#endif

    randomSeed(analogRead(GPIO_NUM_26));
#ifdef SERIAL_ENABLE
    Serial.println("random initialized");
#endif

    M5.EPD.Clear(true);
#ifdef SERIAL_ENABLE
    Serial.println("Clear screen");
#endif
    canvas.createCanvas(SCREEN_WIDTH, SCREEN_HEIGHT, 1);
#ifdef SERIAL_ENABLE
    Serial.println("canvas created");
#endif

    canvas.useFreetypeFont(true);
    canvas.loadFont("/font.ttf",
#ifdef SD_ENABLE
    SD
#else
    SPIFFS
#endif
    );
    canvas.createRender(TITLE_TEXT_SIZE);
    canvas.createRender(DESCRIPTION_TEXT_SIZE);

    read_pokemon(&selected, random(FIRST_POKEMON, LAST_POKEMON + 1));

    draw_screen(&canvas, &selected);

    canvas.pushCanvas(0, 0, UPDATE_MODE_GC16);
#ifdef SERIAL_ENABLE
    Serial.println("canvas pushed, ready to shutdown");
#endif
    delay(2500); // without delay, it shuts down before having updated the screen

    M5.shutdown(
#ifdef RTC_ENABLE
        RTC_ENABLE
#endif
    );
}

void loop() {

}