#ifndef FEE_4DFD0_H
#define FEE_4DFD0_H

#include "common.h"
#include "common/obj.h"
#include "common/rayevts.h"
#include "common/text_to_display.h"
#include "timers.h"
#include "world_map_95CC.h"

/**/
extern u8 display_txt_fee;
extern u8 old_txt_fee;
extern u8 new_txt_fee;
extern s16 png_or_fee_id;
extern s16 fee_obj_id;

void wait_for_dialogue_fee(Obj *obj, s16 time);
void DO_FEE_ETAPE(Obj *obj);
void fee_gives_super_evts(void);
void DO_FEE(Obj *obj);

#endif