#ifndef TIMERS_H
#define TIMERS_H

#include "common.h"
#include "common/world_map.h"
#include "num_level_36260.h"

/**/
extern u8 horloge[25];
extern s32 map_time;
extern s32 left_time;
extern s16 allowed_time[192];

void INIT_HORLOGES(void);
void horloges(void);
void PS1_InitAllowedTime(void);
s32 get_allowed_time(void);
void calc_left_time(void);

#endif