#include "snow.h"

/*INCLUDE_ASM("asm/nonmatchings/snow", do_flocons);*/

void do_flocons(s16 param_1, s16 param_2, s16 param_3, s16 param_4)
{
    FloconTableEntry *tab_entry;
    s16 *var_a1;
    s16 temp_a0;
    s16 temp_a1_1;
    s16 flc_i_1;
    s16 temp_v0_1;
    s16 temp_v0_2;
    s16 temp_v1_1;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 var_a2_1;
    s16 flc_i_2;
    s16 var_t9;
    s16 var_v0_1;
    s16 var_v0_15;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 temp_a2;
    s32 temp_a3;
    s32 temp_v1_2;
    s16 var_s1;
    s16 var_t8;
    s32 var_v0_10;
    s32 var_v0_11;
    s32 var_v0_12;
    s32 var_v0_13;
    s32 var_v0_14;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    s16 temp_fp;
    s16 temp_s3;
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_t2;
    s16 temp_t4;
    s16 var_s0;
    s32 new_var;
    int new_var2;
    s32 test_1;

    temp_fp = VENT_Y;
    temp_s3 = VENT_X;
    temp_v1_1 = temp_fp + 4;
    VENT_Y = temp_v1_1;
    var_s1 = temp_s3 / 4;
    var_s0 = temp_v1_1 / 4;
    test_1 = temp_s3 - ((temp_s3 / 4) * 4);
    temp_a1_1 = test_1;
    new_var2 = temp_v1_1 - ((temp_v1_1 / 4) * 4);
    temp_a2 = new_var2;
    if (__builtin_abs(temp_a1_1) == 1)
    {
        if (horloge[4] == 0)
        {
            if (VENT_X >= 0)
            {
                var_s1 = var_s1 + (new_var = VENT_X > 0);
            }
            else
            {
                var_s1 = var_s1 - 1;
            }
        }
        
    }

    if (__builtin_abs(temp_a1_1) == 2)
    {
        
        if (horloge[2] == 0)
        {
            if (VENT_X >= 0)
            {
                var_s1 = var_s1 + (new_var = VENT_X > 0);
            }
            else
            {
                var_s1 = var_s1 - 1;
            }
        }
    }

    if (__builtin_abs(temp_a1_1) == 3)
    {
        if ((u8) horloge[4] < 3U)
        {
            if (VENT_X >= 0)
            {
                var_s1 = var_s1 + (new_var = VENT_X > 0);
            }
            else
            {
                var_s1 = var_s1 - 1;
            }
        }
    }

    if (__builtin_abs(temp_a2) == 1)
    {
        if (horloge[4] == 0)
        {
            if (VENT_Y >= 0)
            {
                var_s0 = var_s0 + (new_var = VENT_Y > 0);
            }
            else
            {
                var_s0 = var_s0 - 1;
            }
        }
    }

    if (__builtin_abs(temp_a2) == 2)
    {
        if (horloge[2] == 0)
        {
            if (VENT_Y >= 0)
            {
                var_s0 = var_s0 + (new_var = VENT_Y > 0);
            }
            else
            {
                var_s0 = var_s0 - 1;
            }
        }
    }

    if ((__builtin_abs(temp_a2) == 3) && ((u8) horloge[4] < 3U))
    {
        if (VENT_Y >= 0)
        {
            var_s0 = var_s0 + (new_var = VENT_Y > 0);
        }
        else
        {
            var_s0 = var_s0 - 1;
        }
    }
    set_proj_center(0x00A0, 0x00AA);
    var_t8 = 0;
    var_t9 = -0x0040;
    do
    {
        flc_i_1 = floc_ind[var_t8];
        temp_t4 = invpy0[var_t8];
        temp_t2 = invpy200[var_t8];
        temp_t1 = invpx0[var_t8];
        temp_t0 = invpx320[var_t8];

        tab_entry = &flocon_tab[flc_i_1];
        flc_i_2 = flc_i_1;
        temp_a0 = flc_i_2 + nb_floc[var_t8];
        var_a1 = &tab_entry->field1_0x2;
        while (flc_i_2 < temp_a0)
        {
            tab_entry->field0_0x0 = var_s1 + (param_3 - param_1) + tab_entry->field0_0x0;
            *var_a1 = (param_4 - param_2) + var_s0 + *var_a1;
            if (tab_entry->field0_0x0 > temp_t0)
            {
                tab_entry->field0_0x0 = temp_t1;
            }
            else if (tab_entry->field0_0x0 < temp_t1)
            {
                tab_entry->field0_0x0 = temp_t0;
            }

            if (*var_a1 > temp_t2)
            {
                *var_a1 = temp_t4;
            }
            else if (*var_a1 < temp_t4)
            {
                *var_a1 = temp_t2;
            }
            var_a1 += 4;
            flc_i_2 = flc_i_2 + 1;
            tab_entry += 1;
        }
        var_t9 = var_t9 + 0x20;
        var_t8 += 1;
    } while (var_t9 < 0xC0);
    VENT_Y = temp_fp;
    VENT_X = temp_s3;
    if (num_world != 1)
    {
        weather_wind = temp_s3 / 8;
    }
}