#ifndef UNK_48528_H
#define UNK_48528_H

#include "common.h"
#include "common/obj.h"
#include "input_ED20.h"

void PS1_DisplayVRAM(void);
u8 test_allowed(Obj *obj, s16 param_2, s16 param_3);
void obj_jump(Obj *obj);
void DO_ONE_PINK_CMD(Obj *obj);
void FUN_8016d418(Obj *obj);

#endif