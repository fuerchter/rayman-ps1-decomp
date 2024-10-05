#ifndef MITE_BADGUY_H
#define MITE_BADGUY_H

#include "common.h"
#include "collision/etat.h"

void calc_esquive_poing(Obj *mit_obj, s16 *out_diff_x, s16 *out_diff_y, s16 *out_unk);
void DO_PTI_ESQUIVE(Obj *bg3_obj);
void DO_MITE2_ESQUIVE(Obj *mit2_obj);

#endif