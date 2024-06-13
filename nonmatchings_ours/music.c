#include "music.h"

/*INCLUDE_ASM("asm/nonmatchings/music", FUN_801309b8);*/

u8 FUN_801309b8(u8 param_1, u8 param_2, u8 *param_3, u8 param_4)
{
    u8 temp_v1_1;
    u8 var_v0;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a1;
    u8 temp_v1_2;
    u8 var_a0;
    u8 var_v1;
    u8 temp_t0;
    u8 var_a2;
    int new_var;

    temp_v1_1 = btoi(param_1) + btoi(param_2) + btoi(*param_3);
    new_var = temp_v1_1 + 0xFF;
    if (param_4 >= temp_v1_1)
    {
        *param_3 = itob(temp_v1_1);
        var_v0 = 0;
    }
    else
    {
        temp_v1_1 = ((new_var) - param_4);
        *param_3 = itob(temp_v1_1);
        var_v0 = 1;
    }
    return var_v0;
}

/* too many nops somehow... and even worse on current maspsx/decomp.me */
/*INCLUDE_ASM("asm/nonmatchings/music", FUN_80130b18);*/

void FUN_80130b18(u32 param_1, CdlLOC *param_2)
{
    u32 temp_hi_1;
    u32 temp_hi_2;
    u32 temp_lo_1;
    u32 temp_lo_2;

    param_2->sector = itob(param_1 % 75);
    temp_lo_1 = param_1 / 75;
    param_2->second = itob(temp_lo_1 % 60);
    param_2->minute = itob(temp_lo_1 / 60);
}