#ifndef WORLD_MAP_95CC_H
#define WORLD_MAP_95CC_H

#include "common.h"
#include "common/text_to_display.h"
#include "draw/text_18118.h"
#include "world_map_677C0.h"
#include "unknown/7BB28.h"

/* .data */
extern u8 s_level_801cedf4[7];

/**/
extern s16 new_world;
extern s16 new_level;
extern s16 num_world_choice;
extern s16 num_level_choice;
extern u8 old_num_world;
extern u8 world_index;

extern s16 inter_select;
extern s16 level_select;

s16 select_level_prg(void);
s16 SELECT_LEVEL(s16 sel);
s16 WORLD_CHOICE(void);
void DISPLAY_STAGE_NAMES(void);
void DO_WORLD_MAP(void);

#endif