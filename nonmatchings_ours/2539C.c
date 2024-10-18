#include "unknown/2539C.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Bresenham);*/

void Bresenham(void (*param_1)(s16, s16), s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7)
{
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;
    void (*sp18)(s16, s16);
    s16 sp20;
    s32 var_s0_2;
    s16 var_s0_3;
    s16 var_s0_4;
    s16 var_s0_5;
    s32 var_s1_1;
    s16 var_s1_2;
    s16 var_s1_3;
    s16 var_s1_4;
    s16 var_s3;
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_lo_1;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s32 temp_s6_1;
    s32 temp_s6_2;
    s32 temp_s6_3;
    s32 temp_s6_4;
    s16 var_s0_1;
    s32 var_s2_1;
    s32 var_s2_2;
    s32 var_s4;
    s32 var_s5;
    s32 var_s7_1;
    s32 var_s7_2;
    s32 var_v0;
    s32 test_1;
    s32 test_2;

    /*sp18 = param_1;*/
    sp10 = param_2;
    sp14 = param_3;
    sp12 = param_4;
    var_s0_1 = 0;
    var_s5 = param_4 - param_2;
    sp16 = param_5;
    var_s4 = param_5 - param_3;
    test_1 = param_6;
    sp20 = test_1;
    temp_s6_1 = param_7;
    if (var_s5 == 0)
    {
        var_s3 = 0;
    }
    else
    {
        var_s3 = __builtin_abs(var_s4 / var_s5) < 1;
    }
    if (var_s3 == 1)
    {
        if (var_s5 < 0)
        {
            var_s0_1 = 1;
            SwapAB(&sp10, &sp12);
            SwapAB(&sp14, &sp16);
            var_s5 = -var_s5;
            var_s4 = -var_s4;
        }
        else if ((var_s5 == 0) && (var_s4 < 0))
        {
            var_s0_1 = 1;
            SwapAB(&sp14, &sp16);
            var_s4 = -var_s4;
        }

        
        if (var_s4 <= 0)
        {
            var_s7_1 = var_s4 >> 0x1F;
        }
        else
            var_s7_1 = 1;

        var_s4 = __builtin_abs(var_s4);
        var_s2_1 = (var_s4 * 2) - var_s5;
        temp_a3 = var_s4 - var_s5;
        if (var_s0_1 != 0)
        {
            var_s0_2 = sp12;
            temp_s6_1 = var_s0_2 + ((sp10 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2++;
            var_s1_1 = sp16;
            
            var_s7_1 = -var_s7_1;
            while (var_s0_2 >= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a3 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s4 * 2);
                }
                
                if (sp20 < var_s3)
                {
                    param_1(var_s0_2, var_s1_1);
                    var_s3 = 0;
                }
                var_s0_2 -= 1;
            }
        }
        else
        {
            var_s0_2 = sp10;
            temp_s6_1 = var_s0_2 + ((sp12 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2 = var_s0_2 + 1;
            var_s1_1 = sp14;
            
            while (var_s0_2 <= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a3 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s4 * 2);
                }
                if (sp20 < var_s3)
                {
                    param_1(var_s0_2, var_s1_1);
                    var_s3 = 0;
                }
                var_s0_2 += 1;
            }
        }
    }
    else
    {
        if (var_s4 < 0)
        {
            var_s0_1 = 1;
            SwapAB(&sp10, &sp12);
            SwapAB(&sp14, &sp16);
            var_s5 = -var_s5;
            var_s4 = -var_s4;
        }
        else if ((var_s4 == 0) && (var_s5 < 0))
        {
            var_s0_1 = 1;
            SwapAB(&sp10, &sp12);
            var_s5 = -var_s5;
        }
        
        if (var_s5 <= 0)
        {
            var_s7_1 = var_s5 >> 0x1F;
        }
        else
            var_s7_1 = 1;
        var_s5 = __builtin_abs(var_s5);
        var_s2_1 = (var_s5 * 2) - var_s4;
        temp_a0 = var_s5 - var_s4;
        if (var_s0_1 != 0)
        {
            var_s0_2 = sp16;
            temp_s6_1 = var_s0_2 + ((sp14 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2++;
            var_s1_1 = sp12;
            var_s7_1 = -var_s7_1;
            while (var_s0_2 >= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a0 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s5 * 2);
                }
                if (sp20 < var_s3)
                {
                    param_1(var_s1_1, var_s0_2);
                    var_s3 = 0;
                }
                var_s0_2 -= 1;
            }
        }
        else
        {
            var_s0_2 = sp14;
            temp_s6_1 = var_s0_2 + ((sp16 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2++;
            var_s1_1 = sp10;
            while (var_s0_2 <= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a0 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s5 * 2);
                }
                if (sp20 < var_s3)
                {
                    param_1(var_s1_1, var_s0_2);
                    var_s3 = 0;
                }
                var_s0_2 += 1;
            }
        }
    }
}