#ifndef SCORPION_H
#define SCORPION_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "demo_9FD4.h"
#include "cam_scroll_29B5C.h"
#include "moteur_init_end.h"

void swap(s32 ind_1, s32 ind_2);
void set_rubis_list(void);
void allocate_rayon(s16 x, s16 y);
void allocate_8_petits_rayons(s16 x, s16 y);
void do_sko_rayon(void);
void do_sko_rayon2(void);
void start_sko_rayon(s32 x, s16 y);
void start_sko_rayon2(s32 param_1, s16 param_2);
void lance_pince(Obj *param_1);
s32 sko_get_eject_sens(void);
void DO_SOL_ENFONCE(void);
void DO_SKO_PHASE_0(Obj *param_1);
void DO_SKO_PHASE_1(Obj *obj);
void DO_SKO_PHASE_2(Obj *obj);
void DO_SKO_PHASE_3(Obj *obj);
void DO_SKO_PINCE(Obj *obj);
void DO_SCORPION_COLLISION(Obj *param_1);
void DO_SCORPION_MORT(s32 param_1);
void DO_SKO(Obj *obj);
void SKO_ray_in_zone(Obj *obj);
void DO_SKO_HIT(Obj *obj);

#endif