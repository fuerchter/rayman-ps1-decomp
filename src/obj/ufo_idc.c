#include "obj/ufo_idc.h"

/* 74954 80199154 -O2 -msoft-float */
s16 test_block_chdir(Obj *obj, s16 *out_unk, s16 off_x, s16 off_y)
{
    u8 res = false;
    s16 obj_x = (obj->x_pos + off_x) >> 4;
    s16 obj_y = (obj->y_pos + off_y) >> 4;
    
    *out_unk = obj_x + obj_y * mp.width;
    if (*out_unk != obj->test_block_index)
    {
        obj->test_block_index = *out_unk;
        if (
            obj_x >= 0 && (mp.width - 1 >= obj_x) &&
            obj_y >= 0 && (mp.height - 1 >= obj_y)
        )
            res = (mp.map[*out_unk] & 0xFC00) == 0x400;
    }
    return res;
}

INCLUDE_ASM("asm/nonmatchings/obj/ufo_idc", DO_MOVING_WITH_INDICATOR_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/ufo_idc", DO_IDC_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/ufo_idc", DO_LEV_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/ufo_idc", START_UFO);
