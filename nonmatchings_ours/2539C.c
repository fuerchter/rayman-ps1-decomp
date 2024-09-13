#include "unknown/2539C.h"

/* matches, but ... yeah */
/*INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Deter_Option_Caract);*/

void Deter_Option_Caract(u8 *param_1, s16 param_2, u32 param_3)
{
    s32 temp_v1;
    s32 var_v0_1;
    s32 var_v0_2;
    u8 var_v1;
    u32 var_a3;
    u8 *var_v0_3;
    u8 var_v1_2;

    var_a3 = param_3;
    var_v0_1 = param_2 << 0x10;
    if ((s16) var_a3 == 0xff)
    {
        var_v1 = 0;
        if (param_1[var_v1] != 0)
        {
            var_v0_2 = 0;
            do
            {
                if (param_1[var_v0_2] == 0x24)
                {
                    var_a3 = var_v1;
                }
                var_v1 += 1;
                var_v0_2 = var_v1;
            } while (param_1[var_v1] != 0);
        }
        var_v0_1 = param_2 << 0x10;
    }
    temp_v1 = var_v0_1 >> 0x10;
    switch (temp_v1)
    {
    case 0:
        var_v0_3 = &param_1[(s16) var_a3];
        var_v1_2 = 0x23;
block_18:
        var_v0_3[0] = var_v1_2;
        break;
    case 1:
        var_v0_3 = &param_1[(s16) var_a3];
        var_v1_2 = 0x2A;
        goto block_18;
    case 2:
        var_v0_3 = &param_1[(s16) var_a3];
        var_v1_2 = 0x5E;
        goto block_18;
    case 3:
        var_v0_3 = &param_1[(s16) var_a3];
        var_v1_2 = 0xF8;
        goto block_18;
    }
}