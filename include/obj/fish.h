#ifndef FISH_H
#define FISH_H

#include "common.h"
#include "obj_update.h"
#include "collision/collision_block.h"
#include "world_map_677C0.h"

void allocate_splash(Obj *baseObj);
u8 can_free_fish(Obj *fish);
void DESACTIVE_FISH_COLLIS(Obj *obj);
void DO_PYRANHA(Obj *obj);

#endif