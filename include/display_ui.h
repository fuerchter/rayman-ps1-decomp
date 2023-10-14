#ifndef DISPLAY_UI_H
#define DISPLAY_UI_H

#include "common.h"
#include "obj_update.h"
#include "world_map_677C0.h"
#include "obj/poing.h"

typedef struct GrpStar
{
    u8 timer;
    u8 length;
    u8 dist;
    u8 sprite_table_index;
} GrpStar;

extern GrpStar grp_stars[30];
extern s16 current_star;
extern u8 PS1_star_spr[8];

#endif