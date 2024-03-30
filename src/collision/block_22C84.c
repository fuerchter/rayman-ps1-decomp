#include "collision/block_22C84.h"

s16 PS1_BTYPAbsPos(s32, s32); /* see on_block_chdir() */

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_x);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_y);

/* 22F80 80147780 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", on_block_chdir);
#else
u8 on_block_chdir(Obj *obj, s16 offs_bx, s16 offs_by)
{
    __asm__("nop");

    return block_flags[PS1_BTYPAbsPos(obj->x_pos + offs_bx, obj->y_pos + offs_by)] >> BLOCK_CH_DIR & 1;
}
#endif

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", CALC_FOLLOW_SPRITE_SPEED);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", GET_SPRITE_POS);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", GET_RAY_ZDC);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", GET_BB1_ZDCs);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", myRand);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_obj_dir);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", OBJ_IN_ZONE);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_obj_pos);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", makeUturn);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", BTYP);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp_square);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", DO_OBJ_REBOND_EN_X);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp);
