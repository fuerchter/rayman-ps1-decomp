#include "loading_tex.h"

/*
matches, but...
not sure how to interpret any of the constants/vars/types
*/
/*INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_801392d8);*/

void FUN_801392d8(s32 param_1, s16 *param_2, s16 *param_3)
{
    s32 unk_1;

    unk_1 = param_1 >> 7;
    if (param_1 > 0x8DFFF)
        unk_1 += 0x40;
    
    if (unk_1 < 0x100)
        *param_2 = 0;
    else
        *param_2 = (unk_1 >> 9) + 1;
    
    if (*param_2 < 2)
        *param_3 = unk_1 & 0xFF;
    else
        *param_3 = (unk_1 >> 1) & 0xFF;
}