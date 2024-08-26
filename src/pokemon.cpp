#include <stdlib.h>
#include <stdio.h>
#include <M5EPD.h>
#include <FFat.h>

#include "config.hpp"
#include "pokemon.hpp"

void read_pokemon(Pokemon* result, uint16_t id) {

#ifdef SERIAL_ENABLE
    Serial.printf("poke number: %hu\n", id);
#endif

    fs::File pokedat;

#ifdef SD_ENABLE
    pokedat = SD.open("/poke.dat");
#else
    pokedat = SPIFFS.open("/poke.dat");
#endif
    pokedat.seek(sizeof(Pokemon) * (id - 1));
    pokedat.read((uint8_t*)result, sizeof(Pokemon));
    pokedat.close();
}