#ifndef SCORPION_H
#define SCORPION_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "demo_9FD4.h"
#include "cam_scroll_29B5C.h"
#include "moteur_init_end.h"
#include "command_56AF0.h"
#include "command_494FC.h"

void swap(s32 ind_1, s32 ind_2);
void set_rubis_list(void);
void allocate_rayon(s16 x, s16 y);
void allocate_8_petits_rayons(s16 x, s16 y);
void do_sko_rayon(void);
void do_sko_rayon2(void);
void start_sko_rayon(s16 obj_x, s16 obj_y);
void start_sko_rayon2(s16 obj_x, s16 obj_y);
void lance_pince(Obj *sko_obj);
s32 sko_get_eject_sens(void);
void DO_SOL_ENFONCE(void);
void DO_SKO_PHASE_0(Obj *sko_obj);
void DO_SKO_PHASE_1(Obj *obj);
void DO_SKO_PHASE_2(Obj *obj);
void DO_SKO_PHASE_3(Obj *obj);
void DO_SKO_PINCE(Obj *obj);
void DO_SCORPION_COLLISION(Obj *obj);
void DO_SCORPION_MORT(Obj *obj);
void DO_SKO(Obj *obj);
void SKO_ray_in_zone(Obj *obj);
void DO_SKO_HIT(Obj *obj);

#endif