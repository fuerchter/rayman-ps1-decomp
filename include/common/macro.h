#ifndef MACRO_H
#define MACRO_H

#include "common/obj.h"

/* game specific, general macros are in include/common.h */

#define EOA(obj) \
( \
    ( \
        (obj)->eta[(obj)->main_etat][(obj)->sub_etat].flags & 0x10 ? \
        (obj)->anim_frame == 0 : \
        (obj)->anim_frame == (obj)->animations[(obj)->anim_index].frames_count - 1 \
    ) && \
    horloge[(obj)->eta[(obj)->main_etat][(obj)->sub_etat].anim_speed & 0xf] == 0 \
)

/*
issues applying in: DO_POING, alter_fist_speed
TODO: apply
*/
#define FLIP_X_SGN(obj) ((obj)->flags & FLG(OBJ_FLIP_X) ? 1 : -1)

#endif