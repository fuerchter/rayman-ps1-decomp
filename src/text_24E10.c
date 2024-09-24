#include "text_24E10.h"

extern u8 D_801CEFA4;

s32 calc_let_Width(u8 font, s16 sprite);

/* 24E10 80149610 -O2 -msoft-float */
void INIT_TEXT_TO_DISPLAY(void)
{
    u8 *zeroth_char = &D_801CEFA4;
    s32 i = 0;
    TextToDisplay *cur = &text_to_display[i];

    while (i < (s16) LEN(text_to_display))
    {
        cur->text[0] = *zeroth_char;
        text_to_display[i].field8_0x3d = 0;
        text_to_display[i].is_fond = false;
        i++;
        cur++;
    }
}

/* 24E68 80149668 -O2 -msoft-float */
u8 deter_num_let(u8 param_1)
{
    u8 res = 0;

    if (param_1 >= 'a' && param_1 <= 'z')
        res = param_1 - 0x5D;
    if (param_1 >= '0' && param_1 <= '9')
        res = param_1 - 0x12;

    switch (param_1)
    {
    case '?':
        res = 1;
        break;
    case '!':
        res = 2;
        break;
    case '.':
        res = 3;
        break;
    case ':':
        res = 0x28;
        break;
    case '\'':
        res = 0x29;
        break;
    case 0xF8:
        res = 0x2A;
        break;
    case '*':
        res = 0x2D;
        break;
    case '|':
        res = 0x2E;
        break;
    case '~':
    case '#':
        res = 0x2C;
        break;
    case '^':
    case '%':
        res = 0x2B;
        break;
    }

    return res;
}

/* 24FB4 801497B4 -O2 -msoft-float */
void calc_num_let_spr(u8 param_1, u8 *param_2)
{
    if (param_1 == 1)
        *param_2 += 0x29;
}

/* 24FDC 801497DC -O2 -msoft-float */
s32 calc_largmax_text(u8 *param_1, s32 param_2, s16 space_width, s16 param_4, u8 param_5)
{
    s16 i;
    u8 cur_char;
    s16 num_let;
    s16 res = 0;

    for (i = param_2 + 1; param_1[i] != '\0'; i++)
    {
        cur_char = param_1[i];
        if (cur_char == '/')
            break;
        
        if (cur_char == ' ')
            res += space_width;
        else
        {
            num_let = deter_num_let(cur_char);
            if (num_let != 0)
                res += calc_let_Width(param_5, num_let) - param_4;
        }
    }
    return res;
}

INCLUDE_ASM("asm/nonmatchings/text_24E10", INIT_TXT_BOX);
