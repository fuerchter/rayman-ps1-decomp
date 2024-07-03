#ifndef DARK_PHASE2_H
#define DARK_PHASE2_H

#include "common.h"
#include "common/obj.h"
#include "collision/etat.h"

void AllocateDarkPhase2(Obj *obj);
void DO_DARK2_AFFICHE_TEXT(void);
void DO_DARK_PHASE2_COMMAND(Obj *obj);
void DO_DARK2_SORT_COMMAND(Obj *param_1);
void allocate_DARK2_SORT(s16 param_1, s16 param_2, u8 param_3, s16 param_4);

#endif