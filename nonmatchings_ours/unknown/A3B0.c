#include "unknown/A3B0.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/unknown/A3B0", FUN_8012eda4);*/

s32 FUN_8012eda4(s16 param_1, s16 param_2)
{
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    s32 test_1;

    test_1 = param_2;
    if (param_1 >> 1 > 0)
    {
        var_v1 = (param_1 >> 1);
        var_v1 = (((var_v1 - 1) << 7) + 0x40) << 0xA;
    }
    else
    {
        var_v1 = 0;
    }
    
    var_v0 = test_1 << 8;
    if ((param_1 >> 0x1) != 0)
    {
        var_v0 = test_1 << 9;
    }
    return var_v1 + var_v0;
}