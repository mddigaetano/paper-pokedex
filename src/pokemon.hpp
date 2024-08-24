#ifndef POKEMON_H
#define POKEMON_H

#include <stdint.h>

#define BASE_STATS_SIZE 6
enum BaseStats {
    HP,
    ATTACK,
    DEFENSE,
    SPECIAL_ATTACK,
    SPECIAL_DEFENSE,
    SPEED
};

enum Types {
    NORMAL = 1,
    FIGHTING,
    FLYING,
    POISON,
    GROUND,
    ROCK,
    BUG,
    GHOST,
    STEEL,
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    PSYCHIC,
    ICE,
    DRAGON,
    DARK,
    FAIRY,
    STELLAR
};

#define NAME_SIZE 30
#define TYPE_NAME_SIZE 2
#define DESCRIPTION_SIZE 238
typedef struct s_pokemon {
    uint16_t id;
    char name[NAME_SIZE + 1];
    char type1[TYPE_NAME_SIZE + 1];
    char type2[TYPE_NAME_SIZE + 1];
    char description[DESCRIPTION_SIZE + 1];
    uint8_t base_stats[BASE_STATS_SIZE];
} Pokemon;

void read_pokemon(Pokemon* result, uint16_t id);

#endif