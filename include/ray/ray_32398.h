#ifndef RAY_32398_H
#define RAY_32398_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "ray/ray_5D190.h"
#include "ray/ray_30A64.h"
#include "demo_9FD4.h"
#include "world_map_95CC.h"
#include "moteur_init_end.h"
#include "save.h"
#include "obj/corde.h"
#include "collision/collision.h"
#include "continue.h"
#include "main_moteur.h"
#include "obj/eau.h"

/**/
extern Obj ray;
extern Obj raytmp;
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