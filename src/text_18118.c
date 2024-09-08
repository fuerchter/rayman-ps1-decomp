#include "text_18118.h"

/* 18118 8013C918 -O2 -msoft-float */
u8 PS1_deter_num_let_old(s32 param_1)
{
    s32 res;

    if ((u8) (param_1 - 'a') < 0x1a)
        res = param_1 - ']';
    else
    {
        if (((u8) (param_1 - 'A')) >= 0x1a)
        {
            
            if (((u8) (param_1 - '0')) >= 0xa)
            {
                switch ((u8) param_1)
                {
                case 0:
                case 1:
                default:
                    res = 0;
                    break;
                case '?':
                    res = 1;
                    break;
                case '!':
                    res = 2;
                    break;
                case '.':
                    res = 3;
                    break;
                }
            }
            else
                res = param_1 - 0x12;
        }
        else
            res = param_1 - 0x3D;
    }
    return res;
}

INCLUDE_ASM("asm/nonmatchings/text_18118", PS1_calc_let_Width);

INCLUDE_ASM("asm/nonmatchings/text_18118", calc_let_Width);

INCLUDE_ASM("asm/nonmatchings/text_18118", PS1_CalcTextWidth);

INCLUDE_ASM("asm/nonmatchings/text_18118", PS1_DisplayCenteredText);

INCLUDE_ASM("asm/nonmatchings/text_18118", PS1_DisplayMultipleCenteredText);

INCLUDE_ASM("asm/nonmatchings/text_18118", DrawFondBoxNormal);

INCLUDE_ASM("asm/nonmatchings/text_18118", DrawBlackBoxNormal);

INCLUDE_ASM("asm/nonmatchings/text_18118", DISPLAY_BLACKBOX);

INCLUDE_ASM("asm/nonmatchings/text_18118", display_text_sin);

INCLUDE_ASM("asm/nonmatchings/text_18118", display_text);

INCLUDE_ASM("asm/nonmatchings/text_18118", display_box_text);
