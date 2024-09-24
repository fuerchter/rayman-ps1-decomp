#include "text_24E10.h"

/*INCLUDE_ASM("asm/nonmatchings/text_24E10", INIT_TXT_BOX);*/

void INIT_TXT_BOX(TextToDisplay *param_1)
{
    /*u8 test_1[88];*/
    TextToDisplay sp10;
    u8 test_1[40];
    s16 sp78;
    s16 sp80;
    u8 sp88;
    TextToDisplay *var_a2;
    s16 temp_a1;
    s16 temp_v0;
    s16 var_fp;
    s16 var_s0;
    s16 var_s1;
    s16 var_s4;
    s16 var_s5;
    s32 var_s3_1;
    s32 var_s3_2;
    s16 var_s6;
    s32 var_s7;
    u8 *var_a3;
    u8 cur_char;
    u8 num_let;

    var_s5 = 0;
    var_s3_1 = 0;
    var_s0 = 0;
    sp88 = param_1->font_size;
    var_fp = 0;
    var_s1 = 0;
    sp78 = 0;
    if (sp88 == 2)
    {
        sp80 = 0x000F;
        var_s7 = 1;
        var_s6 = 8;
    }
    else if (sp88 == 1)
    {
        sp80 = 0x0017;
        var_s7 = 3;
        var_s6 = 0xA;
    }
    else
    {
        sp80 = 0x0024;
        var_s7 = 3;
        var_s6 = 0xC;
    }
    __builtin_memcpy(param_1, &sp10, sizeof(sp10.text)); /* check in debugger */
    var_s4 = 0;
    if (sp10.text[0] != 0)
    {
        while (sp10.text[var_s4] != 0)
        {
            cur_char = sp10.text[var_s4];
            if (cur_char == '/')
            {
                var_s3_1 += 1;
                sp78 = 1;
                if (var_s0 > var_s5)
                {
                    var_s5 = var_s0;
                }
                var_s0 = 0;
                if (var_s1 > var_fp)
                {
                    var_fp = var_s1;
                }
                var_s1 = 0;
                num_let = 0;
            }
            else if (cur_char == ' ')
            {
                var_s0 += var_s6;
                var_s1 += 1;
                num_let = 0;
            }
            else
            {
                num_let = deter_num_let(cur_char);
            }
            
            if (num_let != 0)
            {
                var_s1 += 1;
                var_s0 += calc_let_Width(sp88, num_let) - var_s7;
            }
            var_s4 = var_s4 + 1;
        }
        
        if ((var_s3_1 << 0x10) == 0)
        {
            var_s5 = var_s0;
            var_s3_1 = var_s3_1 + 1;
        }
        else
        {
            var_s3_1 = var_s3_1 - 1;
        }
        if (sp78 != 0)
        {
            param_1->centered_x_pos = param_1->x_pos - (var_s5 >> 0x1);
        }
        else
        {
            param_1->centered_x_pos = param_1->x_pos;
        }
        param_1->width = var_s5 + 2;
        param_1->centered_y_pos = (param_1->y_pos - sp80) + 2;
        param_1->height = (var_s3_1 * sp80) - 2;
    }
}