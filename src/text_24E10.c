#include "text_24E10.h"

#ifdef BSS_DEFS
TextToDisplay text_to_display[10];
#endif

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
s16 calc_largmax_text(u8 *param_1, s32 param_2, s16 space_width, s16 param_4, u8 param_5)
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

/*thanks! https://decomp.me/scratch/9zSXY */
/* 250C8 801498C8 -O2 -msoft-float */
void INIT_TXT_BOX(TextToDisplay *out_txt)
{
    TextToDisplay unk_txt;
    u8 unused_stack[40];
    s16 unk_3;
    s16 height_font;
    s32 unk_4;
    s16 space_width;
    u8 font_size;
    s16 i;
    u8 cur_char;
    u8 num_let;
    s16 width_1 = 0;
    s16 height_mul = 0;
    s16 width_2 = 0;
    s16 unk_1 = 0;
    s16 unk_2 = 0;

    unk_3 = false;
    font_size = out_txt->font_size;
    if (font_size == 2)
    {
        height_font = 15;
        unk_4 = 1;
        space_width = 8;
    }
    else if (font_size == 1)
    {
        height_font = 23;
        unk_4 = 3;
        space_width = 10;
    }
    else
    {
        height_font = 36;
        unk_4 = 3;
        space_width = 12;
    }

    __builtin_memcpy(&unk_txt, out_txt->text, sizeof(out_txt->text));
    i = 0;
    if (unk_txt.text[0] != '\0')
    {
        while (unk_txt.text[i] != '\0')
        {
            cur_char = unk_txt.text[i];
            if (cur_char == '/')
            {
                height_mul++;
                unk_3 = true;
                MAX_3(width_1, width_2);
                MAX_3(unk_1, unk_2);
                width_2 = 0;
                unk_2 = 0;
                num_let = 0;
            }
            else if (cur_char == ' ')
            {
                width_2 += space_width;
                unk_2++;
                num_let = 0;
            }
            else
                num_let = deter_num_let(cur_char);

            if (num_let != 0)
            {
                unk_2++;
                width_2 += calc_let_Width(font_size, num_let) - unk_4;
            }

            i++;
        }

        if (height_mul == 0)
        {
            width_1 = width_2;
            height_mul++;
        }
        else
            height_mul--;

        if (unk_3)
            out_txt->centered_x_pos = out_txt->x_pos - (width_1 >> 1);
        else
            out_txt->centered_x_pos = out_txt->x_pos;

        out_txt->width = width_1 + 2;
        out_txt->height = height_mul * height_font - 2;
        out_txt->centered_y_pos = out_txt->y_pos - height_font + 2;
    }
}
