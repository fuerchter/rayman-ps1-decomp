#ifndef FOND_10B3C_H
#define FOND_10B3C_H

#include "common.h"
#include "display.h"

typedef struct {
    s16 x;
    s16 y;
} BackgroundPosition;

typedef struct {
    BackgroundPosition sprite_positions[16];
    Sprite sprites[16];
} BackgroundData;

#endif