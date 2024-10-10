#ifndef BONUS_343EC_H
#define BONUS_343EC_H

#include "common.h"
#include "common/ray.h"
#include "common/world_map.h"
#include "psyq_3_0/LIBGPU.H"
#include "psyq_3_0/STDIO.H"
#include "world_map_95CC.h"
#include "timers.h"
#include "draw/fade.h"
#include "nova.h"

/* .data */
extern Obj *PS1_BonusNovas[2];
extern Obj *PS1_BonusOneUps[2];

/* .data */
extern u8 PS1_TimeString[24];

s16 do_perfect_bonus(void); /* TODO: return type? PS1_DemoLoop is u8 still */

#endif