#include "info.hpp"
#include "config.hpp"
#include "layout.hpp"

//counted by hand based on text size and space costraints
#define CHARACTERS_PER_LINE 30 

void draw_title(M5EPD_Canvas* canvas, uint16_t id, const char name[]);
void draw_description(M5EPD_Canvas* canvas, const char description[]);
void draw_stats(M5EPD_Canvas* canvas, const uint8_t stats[]);

void draw_info(M5EPD_Canvas* canvas, Pokemon* poke) {
    draw_title(canvas, poke->id, poke->name);
    draw_description(canvas, poke->description);
    draw_stats(canvas, poke->base_stats);
}

void draw_title(M5EPD_Canvas* canvas, uint16_t id, const char name[]) {
    char title[4 + 2 + NAME_SIZE + 1];

    sprintf(title, "%hu: %s", id, name);
    canvas->setTextSize(TITLE_TEXT_SIZE);
    canvas->setTextDatum(TC_DATUM);
    canvas->drawString(title, TITLE_X, TITLE_Y);
}

// TODO: missing check for words longer than CHARCTERS_PER_LINE
// will loop indefinitely if found
void string_word_wrap(char string[]) {
    
    Serial.println("Siamo dentro");
    size_t last_space = 0;
    size_t index = 0;
    size_t counter = 0;
    while (string[index] != '\0') {
        Serial.println(index);
        counter++;
        if (string[index] == ' ') {
            last_space = index;
        }
        index++;
        if(counter > CHARACTERS_PER_LINE) {
            string[last_space] = '\n';
            index = last_space + 1;
            counter = 0;
        }
    }
    Serial.println("siamo fuori");
}

void draw_description(M5EPD_Canvas* canvas, const char description[]) {

    char wrapped[DESCRIPTION_SIZE];
    strcpy(wrapped, description);
    
    canvas->setTextWrap(true);
    canvas->setTextSize(DESCRIPTION_TEXT_SIZE);
    canvas->setTextDatum(TL_DATUM);
    canvas->setTextArea(
        SECTION_INFO_X, SECTION_INFO_Y,
        SECTION_INFO_WIDTH, SECTION_INFO_HEIGHT
    );
    string_word_wrap(wrapped);
    canvas->printf("%s", wrapped);
}

void draw_stats(M5EPD_Canvas* canvas, const uint8_t stats[]) {
    char first_row[CHARACTERS_PER_LINE + 1];
    char second_row[CHARACTERS_PER_LINE + 1];

    sprintf(first_row,
        "HP :%3hhu    Att:%3hhu    Def:%3hhu",
        stats[HP],
        stats[ATTACK],
        stats[DEFENSE]
    );
    sprintf(second_row,
        "Spe:%3hhu    SpA:%3hhu    SpD:%3hhu",
        stats[SPEED],
        stats[SPECIAL_ATTACK],
        stats[SPECIAL_DEFENSE]
    );
    canvas->setTextSize(DESCRIPTION_TEXT_SIZE);
    canvas->setTextDatum(TL_DATUM);
    canvas->drawString(first_row,
        SECTION_SPRITES_WIDTH + 10, TYPE1SPRITE_Y + 10);
    canvas->drawString(second_row,
        SECTION_SPRITES_WIDTH + 10, TYPE1SPRITE_Y + 10 + 40);
}
