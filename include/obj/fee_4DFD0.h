#ifndef FEE_4DFD0_H
#define FEE_4DFD0_H

#include "common.h"
#include "obj_update.h"
#include "text_24E10.h"
#include "timers.h"
#include "ray/ray_5D190.h"
#include "world_map_95CC.h"
#include "ray/ray_32398.h"

extern u8 display_txt_fee;
extern u8 old_txt_fee;
extern s16 png_or_fee_id;

void wait_for_dialogue_fee(Obj *obj, s16 time);
void DO_FEE_ETAPE(Obj *obj);
void fee_gives_super_evts(void);
void DO_FEE(Obj *obj);

#endif