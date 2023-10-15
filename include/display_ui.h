#ifndef DISPLAY_UI_H
#define DISPLAY_UI_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"
#include "obj_update.h"
#include "world_map_677C0.h"
#include "obj/poing.h"
#include "obj/fee_4DFD0.h"
#include "card.h"
#include "menu/menu_6A3BC.h"

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
extern Obj div_obj;

#endif