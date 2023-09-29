#ifndef WORLD_MAP_95CC_H
#define WORLD_MAP_95CC_H

#include "common.h"
#include "text_24E10.h"
#include "text_18118.h"
#include "menu/menu_7EEE4.h"
#include "ray/ray_32398.h"
#include "world_map_677C0.h"

extern s16 inter_select;
extern s16 level_select;

s32 select_level_prg();
s16 SELECT_LEVEL(s16 sel);
s32 WORLD_CHOICE();

#endif