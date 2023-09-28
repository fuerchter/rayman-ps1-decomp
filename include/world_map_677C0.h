#ifndef WORLD_MAP_677C0_H
#define WORLD_MAP_677C0_H

#include "common.h"
#include "obj_update.h"
#include "text_24E10.h"

struct WorldInfo {
    s16 x_pos;
    s16 y_pos;
    u8 index_up;
    u8 index_down;
    u8 index_left;
    u8 index_right;
    u8 state;
    u8 nb_cages;
    u8 world;
    u8 level;
    u8 color;
    u8 * level_name;
};

void CalcObjPosInWorldMap(Obj *obj);
void INIT_STAGE_NAME();

#endif