#ifndef RAY_32398_H
#define RAY_32398_H

#include "common.h"
#include "obj_update.h"
#include "ray/ray_5D190.h"
#include "ray/ray_30A64.h"
#include "demo_9FD4.h"
#include "world_map_95CC.h"
#include "world_map_677C0.h"
#include "moteur_init_end.h"
#include "save.h"

/* .data */
extern u8 joy_done;

/**/
extern Obj ray;
extern Obj raytmp;

void INIT_RAY_BEGIN(void);
void INIT_RAY(u8 newLevel);
u8 is_icy_pente(u32 param_1);
void STOPPE_RAY_EN_XY(void);
void RAY_RESPOND_TO_ALL_DIRS(void);
void DO_RAYMAN(void);
void DO_RAY_ON_MS(void);
void DO_PLACE_RAY(void);

#endif