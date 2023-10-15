#ifndef CARD_H
#define CARD_H

#include "common.h"

typedef struct CardFrame0
{
    u8 sc_magic[2];
    u8 icon_display_flag;
    u8 block_num;
    u8 Rayman_save_ray_pct[64];
    u8 Maga[28];
} CardFrame0;

typedef struct LoadInfoRay {
    u8 num_lives;
    u8 num_wiz;
    u8 num_cages;
    u8 num_continues;
} LoadInfoRay;

extern LoadInfoRay loadInfoRay[6];

#endif