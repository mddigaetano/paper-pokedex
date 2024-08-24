#include <M5EPD.h>

#include "screen.hpp"
#include "sprites.hpp"
#include "info.hpp"
#include "config.hpp"
#include "layout.hpp"

void draw_battery(M5EPD_Canvas* canvas);

void draw_screen(M5EPD_Canvas* canvas, Pokemon* poke) {
    draw_sprites(canvas, poke);
    draw_info(canvas, poke);
    draw_battery(canvas);
}

#ifdef BATTERY_LEVEL_ENABLE
//adapted from https://github.com/capi/M5Paper_Remote_Dashboard/blob/main/src/main.cpp
float readBattery() {
    uint32_t batteryVoltage = M5.getBatteryVoltage();
    float fBatteryPercent = (float)(batteryVoltage - 3300) / (float)(4350 - 3300);
    if (fBatteryPercent <= 0.01) {
        fBatteryPercent = 0.01;
    }
    if (fBatteryPercent > 1) {
        fBatteryPercent = 1;
    }
    return fBatteryPercent;
}

void draw_battery(M5EPD_Canvas* canvas) {
    float batteryPercent = readBattery();
    canvas->fillRect(
        BATTERY_SECTION_X, BATTERY_SECTION_Y,
        (size_t)(batteryPercent * BATTERY_SECTION_WIDTH), BATTERY_SECTION_HEIGHT,
        PAPER_BLACK
    );
}
#endif