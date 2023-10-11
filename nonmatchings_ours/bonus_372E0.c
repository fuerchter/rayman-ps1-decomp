#include "bonus_372E0.h"

/*INCLUDE_ASM("asm/nonmatchings/bonus_372E0", get_next_bonus_level);*/

/* feels like subswitches should stay instead of if/else, even though worse score */
/* 374A8 8015BCA8 -O2 */
s16 get_next_bonus_level(u8 arg0)
{
    s16 var_a1;
    s16 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;

    temp_v0 = num_world - 1;
    var_a1 = 0;
    switch (temp_v0)
    {
    case 5:
        break;
    case 0:
        temp_v1 = arg0 & 0xFF;
        switch (temp_v1)
        {
        case 2:
            var_a1 = 0x15;
            break;
        case 4:
            var_a1 = 0x14;
            break;
        case 12:
            var_a1 = 0x13;
            break;
        case 11:
        case 9:
            var_a1 = 0x12;
            break;
        }
        break;
    case 1:
        temp_v1_2 = arg0 & 0xFF;
        switch (temp_v1_2)
        {
        case 4:
            var_a1 = 0x11;
            break;
        }
        break;
    case 3:
        temp_v1_3 = arg0 & 0xFF;
        if (temp_v1_3 != 3)
        {
            if (temp_v1_3 == 9)
            {
                var_a1 = 0xD;
            }
        }
        else
        {
            var_a1 = 0xC;
        }
        break;
    case 4:
        if ((arg0 & 0xFF) == 2)
        {
            var_a1 = 0xC;
        }
        break;
    }
    return var_a1;
}