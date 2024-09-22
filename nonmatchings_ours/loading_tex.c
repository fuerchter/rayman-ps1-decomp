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

/*
matches, but ...
what is any of this?
*/
/*INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_80139330);*/

void FUN_80139330(u32 param_1, s16 *param_2, s16 *param_3)
{
    s32 temp_v1_1;
    s32 temp_v1_2;
    s32 var_v0_3;
    s32 temp_a0;
    s32 test_1;

    test_1 = 0x100;
    temp_v1_1 = param_1 + 0xFFFF0000;
    if (temp_v1_1 < 0)
        *param_2 = param_1 >> 15;
    else
        *param_2 = (temp_v1_1 >> 16) + 2;
    
    if (temp_v1_1 < 0)
        *param_3 = (param_1 & 0x7FFF) >> 7;
    else
    {
        var_v0_3 = temp_v1_1 & 0xFFFF;
        if (var_v0_3 < 0)
            var_v0_3 += 0xFF;
        *param_3 = (u32) var_v0_3 >> 8;
    }

    if (*param_2 > 7)
    {
        temp_a0 = temp_v1_1 + 0xFFFA0000;
        temp_v1_2 = temp_a0 - (test_1 << 8);
        
        if (temp_v1_2 < 0)
            *param_2 = 8;
        else
            *param_2 = 9;
            
        if (temp_v1_2 < 0)
            *param_3 = (u32) temp_a0 >> 8;
        else
            *param_3 = (u32) temp_v1_2 >> 8;
    }
}