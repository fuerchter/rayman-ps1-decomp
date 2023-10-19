#ifndef COLLISION_H
#define COLLISION_H

#include "common.h"

typedef struct ZDC
{
    s16 x_pos;
    s16 y_pos;
    u8 width;
    u8 height;
    u8 flags;
    u8 sprite;
} ZDC;

extern s16 ray_zdc_x;
extern s16 ray_zdc_y;
extern s16 ray_zdc_w;
extern s16 ray_zdc_h;
extern u8 nb_wiz_collected;

#endif