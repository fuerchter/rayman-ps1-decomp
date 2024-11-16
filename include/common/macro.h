#ifndef MACRO_H
#define MACRO_H

#include "common/obj.h"

/*
game specific, general macros are in include/common.h
TODO: should these have PS1_ prefix? see music.c
*/

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
does not work in:
DO_POING
alter_fist_speed
allocateDard
*/
#define FLIP_X_SGN(obj) ((obj)->flags & FLG(OBJ_FLIP_X) ? 1 : -1)
#define BOOL_SGN(x) ((x) ? 1 : -1) /* more generalized version? lance_couteau_lineaire case 0*/

/*
does not work in:
DO_DARK2_TOONS_COMMAND
calc_btyp_square
*/
static inline s32 test_x_pos_1(Obj *obj)
{
    return (s16) (obj->offset_bx + obj->x_pos);
}

/*
does not work in:
DO_DARK2_TOONS_COMMAND
calc_btyp_square (x_pos and offset_bx order is flipped)
*/
static inline s32 test_x_pos_2(Obj *obj)
{
    return (obj->x_pos + obj->offset_bx);
}

/*
works in:
DO_DARK2_TOONS_COMMAND (explicitly without parens!)
calc_btyp_square
DO_SPIDER_PLAFOND

does not work in:
allocatePirateNgaweRing (cur_obj subtraction?)
*/
#define test_x_pos_3(obj) (obj)->x_pos + (obj)->offset_bx

#endif