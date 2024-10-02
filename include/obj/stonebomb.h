#ifndef STONEBOMB_H
#define STONEBOMB_H

#include "common.h"
#include "collision/block_22C84.h"

/**/
extern s16 D_801E51E8;
extern s16 D_801E51F8;

void setStoneChipPos(Obj *param_1, Obj *param_2, u8 *param_3);
void allocateStoneChips(Obj *in_obj); /* type? */
void DO_STONE_EXPLOSION(Obj *obj);
void DO_TIR(Obj *param_1); /* TYPE_CHASSEUR1, TYPE_CHASSEUR2 see DO_ONE_CMD_LR_ATTENTE() */
void allocateStonemanStone(Obj *stmn_obj, s16 param_2, u8 param_3);
void DO_STONEMAN1_TIR(Obj *obj);
void DO_STONEMAN2_TIR(Obj *obj);
void allocateStonewomanStone(Obj *stwmn_obj, s16 param_2);
void DO_STONEWOMAN_TIR(s32 param_1);

#endif