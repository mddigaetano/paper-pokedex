#ifndef CONFIG_H
#define CONFIG_h

#define PAPER_WHITE 0
#define PAPER_BLACK 15

#define FIRST_POKEMON 1
#define LAST_POKEMON 1025

// #define SHOW_BOUNDING_BOXES

//#define SERIAL_ENABLE

#define RTC_ENABLE (1 * 60 * 60)

// if disabled it defaults to SPIFFS, but much slower font rendering
// #define SD_ENABLE 

#define BATTERY_LEVEL_ENABLE

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

#define TITLE_TEXT_SIZE 55
#define DESCRIPTION_TEXT_SIZE 30

#endif