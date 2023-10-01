#ifndef BONUS_35FB4_H
#define BONUS_35FB4_H

#include "common.h"

extern u8 bonus_perfect[24];

u8 get_bonus_map_complete(s16 world, s16 level);
void set_bonus_map_complete(s16 world, s16 level);
void init_bonus_perfect(void);

#endif