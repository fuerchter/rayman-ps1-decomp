#ifndef RAY_30A64_H
#define RAY_30A64_H

#include "common.h"

typedef struct StatusBar
{
    s16 num_lives;
    u8 lives_digits[2];
    u8 hp_sprites[2];
    u8 num_wiz;
    u8 wiz_digits[2];
    u8 max_hp;
} StatusBar;

extern StatusBar status_bar;

#endif