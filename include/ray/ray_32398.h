#ifndef RAY_32398_H
#define RAY_32398_H

#include "common.h"
#include "common/rayevts.h"
#include "ray/ray_30A64.h"
#include "moteur_init_end.h"
#include "continue.h"
#include "collision/collision.h"
#include "save.h"

/**/
extern u8 PS1_ShoulderL;
extern u8 PS1_ShoulderR;
extern u8 RAY_MODE_SPEED;

void INIT_RAY_BEGIN(void);
void INIT_RAY(u8 new_level);
s16 is_icy_pente(u8 block);
void STOPPE_RAY_EN_XY(void);
void RAY_RESPOND_TO_ALL_DIRS(void);
void DO_RAYMAN(void);
void DO_RAY_ON_MS(void);
void DO_PLACE_RAY(void);

#endif