#ifndef UFO_IDC_H
#define UFO_IDC_H

#include "common.h"
#include "obj_init_kill.h"

u8 test_block_chdir(Obj *obj, s16 *param_2, s16 off_x, s16 off_y);
void DO_MOVING_WITH_INDICATOR_COMMAND(Obj *obj);
void DO_IDC_COMMAND(Obj *obj);
void DO_LEV_POING_COLLISION(Obj *obj);
void START_UFO(Obj *obj);

#endif