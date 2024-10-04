#ifndef DARK2_PINK_FLY_H
#define DARK2_PINK_FLY_H

#include "common.h"
#include "collision/bit_util.h"

/**/
extern s16 PosArXToon1;
extern s16 PosArXToon2;
extern s16 PosArYToon1;
extern s16 PosArYToon2;
extern u8 ToonJustGivePoing;

void AllocateToons(void);
void DO_DARK2_TOONS_COMMAND(Obj *d2fly_obj);
void ToonDonnePoing(Obj *obj);

#endif