#ifndef BLACKTOON1_H
#define BLACKTOON1_H

#include "common.h"
#include "collision/block_22C84.h"

void allocateBlacktoonEyes(Obj *bt1_obj);
void DO_BLK_SPEED_COMMAND(Obj *obj);
void DO_BLK_LR_COMMAND(Obj *obj);
void DO_BLK_NOP_COMMAND(Obj *obj);
void DO_BLKTOON_COMMAND(Obj *obj);

#endif