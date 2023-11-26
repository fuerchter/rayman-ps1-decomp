#ifndef FOND_10B3C_H
#define FOND_10B3C_H

#include "common.h"
#include "display.h"

typedef struct BackgroundPosition
{
    s16 x;
    s16 y;
} BackgroundPosition;

typedef struct BackgroundData
{
    BackgroundPosition sprite_positions[16];
    Sprite sprites[16];
} BackgroundData;

void PS1_LoadFond(void);

#endif