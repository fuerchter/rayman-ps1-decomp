#ifndef UFO_IDC_H
#define UFO_IDC_H

#include "common.h"
#include "obj_init_kill.h"

s16 test_block_chdir(Obj *obj, s16 *out_unk, s16 off_x, s16 off_y);
void DO_MOVING_WITH_INDICATOR_COMMAND(Obj *ufo_idc_obj);
void DO_IDC_COMMAND(Obj *idc_obj);
void DO_LEV_POING_COLLISION(Obj *lev_obj);
void START_UFO(Obj *ufo_idc_obj);

#endif