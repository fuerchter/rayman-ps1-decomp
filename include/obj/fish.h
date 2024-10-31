#ifndef FISH_H
#define FISH_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "world_map_677C0.h"
#include "gendoor.h"

/**/
extern s16 PS1_SplashAlwaysObjects[12];
extern u8 PS1_SplashAlwaysObjectsCount;

void allocate_splash(Obj *baseObj);
u8 can_free_fish(Obj *fish);
void DESACTIVE_FISH_COLLIS(Obj *obj);
void DO_PYRANHA(Obj *obj);

#endif