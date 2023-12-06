#ifndef BONUS_35FB4_H
#define BONUS_35FB4_H

#include "common.h"
#include "ray/ray_30A64.h"
#include "num_level_36260.h"
#include "bonus_343EC.h"
#include "moteur_init_end.h"
#include "obj_update.h"

extern u8 bonus_perfect[24];
extern s16 loop_time;
extern s32 nb_wiz_save;

u8 get_bonus_map_complete(s16 world, s16 level);
void set_bonus_map_complete(s16 world, s16 level);
void DO_PERFECT_BONUS_MAP(void);
void DO_WIZ_AFTER_BONUS_MAP(void);
void init_bonus_perfect(void);

#endif