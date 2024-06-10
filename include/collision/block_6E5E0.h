#ifndef BLOCK_6E5E0_H
#define BLOCK_6E5E0_H

#include "common.h"
#include "common/ray.h"
#include "collision/block_22C84.h"
#include "obj_update.h"
#include "obj_init_kill.h"
#include "collision/etat.h"
#include "collision/bit_util.h"
#include "ray/ray_5D190.h"
#include "command_56AF0.h"

u8 MURDUR(s16 x, s16 y);
s16 dist_to_bloc_floor(s16 btyp, s16 x, s16 y);
s16 bloc_floor(s16 btyp, s16 x, s16 y);
s32 calc_typ_trav(Obj *obj, u8 param_2);
u8 calc_typ_travd(Obj *obj, u8 param_2);
void TEST_FIN_BLOC(Obj *obj);
s32 TEST_IS_ON_RESSORT_BLOC(Obj *obj);
s32 IS_ON_RESSORT_BLOC(Obj *obj);
void CALC_MOV_ON_BLOC(Obj *obj);
void recale_position(Obj *obj);

#endif