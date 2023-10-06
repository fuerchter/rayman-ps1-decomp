#ifndef WORLD_MAP_95CC_H
#define WORLD_MAP_95CC_H

#include "common.h"
#include "world_map_677C0.h"
#include "text_24E10.h"
#include "text_18118.h"
#include "menu/menu_7EEE4.h"
#include "ray/ray_32398.h"
#include "demo_9FD4.h"
#include "main.h"

extern s16 new_level;
extern s16 num_level;
extern s16 num_level_choice;
extern s16 num_world;
extern s16 num_world_choice;
extern u8 world_index;

extern s16 inter_select;
extern s16 level_select;
extern u8 s_level_801cedf4[7];

s32 select_level_prg(void);
s16 SELECT_LEVEL(s16 sel);
s32 WORLD_CHOICE(void);
void DISPLAY_STAGE_NAMES(void);
void DO_WORLD_MAP(void);

#endif