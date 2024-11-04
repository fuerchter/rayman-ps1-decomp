#ifndef MITE_H
#define MITE_H

#include "common.h"
#include "obj/mite_badguy.h"

void mite_esquive_poing(Obj *mit_obj, s16 *out_diff_x);
u8 HAS_MIT_JUMP(Obj *obj);
u8 ray_over_mit(Obj *obj, s16 param_2);
void fix_mit_Xspeed(Obj *obj, s16 param_2);
void DO_MIT_ATTAK(Obj *obj);
u8 IS_MIT_PAF(Obj *obj);
void DO_MIT_COMMAND(Obj *obj);
void DO_MITE2_COMMAND(Obj *obj);

#endif