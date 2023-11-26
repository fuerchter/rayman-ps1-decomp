#ifndef LOADING_DA64_H
#define LOADING_DA64_H

#include "common.h"
#include "display.h"
#include "obj_update.h"

typedef struct Font
{
    Sprite * sprites;
    u8 * img_buffer;
    s32 nb_sprites;
} Font;

typedef struct AllFixData
{
    Font alpha;
    Font alpha2;
    Obj objects[29];
} AllFixData;

extern AllFixData *PS1_AllFixData;

#endif