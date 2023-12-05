#ifndef OBJ_UPDATE_H
#define OBJ_UPDATE_H

#include "common.h"
#include "common/obj.h"
#include "display.h"
#include "obj_init_kill.h"

typedef struct ObjHandlers
{
    void (* do_obj)(Obj *);
} ObjHandlers;

extern LevelData level;
extern s16 id_Cling_1up;
extern s16 id_Cling_Pow;
extern u8 ray_in_fee_zone;

void DO_ANIM(Obj *obj);
void FUN_80150c5c(Obj *param_1, u8 param_2);
s32 DO_PESANTEUR(Obj *obj);

#endif