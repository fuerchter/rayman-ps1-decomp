#ifndef MACRO_H
#define MACRO_H

#include "common/obj.h"

/* game specific, general macros in include/common.h */

#define EOA(obj) \
( \
    ( \
        (obj)->eta[(obj)->main_etat][(obj)->sub_etat].flags & 0x10 ? \
        (obj)->anim_frame == 0 : \
        (obj)->anim_frame == (obj)->animations[(obj)->anim_index].frames_count - 1 \
    ) && \
    horloge[(obj)->eta[(obj)->main_etat][(obj)->sub_etat].anim_speed & 0xf] == 0 \
)

#endif