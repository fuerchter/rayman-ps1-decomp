#ifndef HYB_BBF2_H
#define HYB_BBF2_H

#include "common.h"
#include "common/obj.h"
#include "collision/block_22C84.h"
#include "collision/etat.h"

/**/
extern u8 BBF2DEsk;
extern u8 BBF2GEsk;
extern s16 NiveauSol;
extern s16 YPosBBF2D;
extern s16 YPosBBF2G;

void doBBF2command(Obj *obj, u16 param_2);
void DO_HYB_BBF2_POING_COLLISION(Obj *obj);
void AllocateTirBBF2(Obj *bbf2_obj);
void DO_HYB_BBF2_LAS(Obj *param_1);
int OBJ_IN_COL_ZDC(Obj *obj1, Obj *obj2);

#endif