#ifndef ETAT_H
#define ETAT_H

#include "common.h"
#include "obj_update.h"

s32 vblToEOA(Obj *param_1, u32 factor);

s32 FUN_801473dc(Obj *obj);
s16 PS1_BTYPAbsPos(s32 x, s32 y); /* see on_block_chdir() */
void set_main_and_sub_etat(Obj *obj, u8 main_etat, u8 sub_etat);
void set_main_etat(Obj *param_1, u8 main_etat);
void set_sub_etat(Obj *obj, u8 sub_etat);

#endif