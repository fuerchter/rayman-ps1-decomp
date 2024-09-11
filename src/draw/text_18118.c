#include "draw/text_18118.h"

/* 18118 8013C918 -O2 -msoft-float */
u8 PS1_deter_num_let_old(s32 param_1)
{
    s32 res;

    if ((u8) (param_1 - 'a') < 0x1a)
        res = param_1 - ']';
    else
    {
        if ((u8) (param_1 - 'A') >= 0x1a)
        {
            if ((u8) (param_1 - '0') >= 0xa)
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

/* 181A4 8013C9A4 -O2 -msoft-float */
s16 PS1_calc_let_Width(s16 sprite, u8 font)
{
    switch (font)
    {
    case 2:
        return D_801C7228[sprite];
    case 1:
        return D_801C71F8[sprite];
    default:
        return D_801C71CC[sprite];
    }
}

/* 18214 8013CA14 -O2 -msoft-float */
s32 calc_let_Width(u8 param_1, s16 param_2)
{
    return PS1_calc_let_Width(param_2, param_1);
}

/* 18244 8013CA44 -O2 -msoft-float */
s16 PS1_CalcTextWidth(u8 *str, u8 font)
{
    s16 res = 0;
    u8 i = 0;
    
    while (str[i] != 0)
    {
        res += PS1_calc_let_Width(deter_num_let(str[i]), font);
        i++;
    }
    return res;
}

/* 182D0 8013CAD0 -O2 -msoft-float */
void PS1_DisplayCenteredText(u8 *str, u8 param_2, u8 color)
{
    GetClut(color * 16 + 64, 509);
    display_text(
        str,
        (320 - PS1_CalcTextWidth(str, 0)) >> 1,
        param_2 * 36 + 4,
        0,
        color
    );
}

/* 1835C 8013CB5C -O2 -msoft-float */
void PS1_DisplayMultipleCenteredText(u8 index, MenuText *in_menus)
{
    u8 sel_row;
    u8 *count;
    s32 unk_1;
    u8 i;
    s32 unk_2;
    MenuText *menu = &in_menus[index];
    
    PS1_PolygonsCount = 0;
    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[6];
    sel_row = menu->selected_row;
    count = &menu->rows_count;
    if (sel_row < 240)
    {
        unk_1 = sel_row + 6;
        PS1_DrawSprite(&alpha.sprites[40], 39, (unk_1 - *count) * 36 + 4, 0);
    }
    PS1_DisplayCenteredText(menu->header, 1, menu->color);
    
    for (i = 0; i < *count; i++)
    {
        unk_2 = i + 7;
        PS1_DisplayCenteredText(menu->rows[i], unk_2 - *count, menu->color);
    }
}

INCLUDE_ASM("asm/nonmatchings/draw/text_18118", DrawFondBoxNormal);

INCLUDE_ASM("asm/nonmatchings/draw/text_18118", DrawBlackBoxNormal);

/* 18A1C 8013D21C -O2 -msoft-float */
void DISPLAY_BLACKBOX(u16 x, u16 y, u16 w, u16 h, u8 param_5, u8 is_fond)
{
    if (is_fond)
        DrawFondBoxNormal(x, y, w, h, 255 - param_5);
    else
        DrawBlackBoxNormal(x, y, w, h, 255 - param_5);
}

INCLUDE_ASM("asm/nonmatchings/draw/text_18118", display_text_sin);

INCLUDE_ASM("asm/nonmatchings/draw/text_18118", display_text);

/* 19990 8013E190 -O2 -msoft-float */
void display_box_text(TextToDisplay *txt)
{
    s16 x = txt->centered_x_pos;
    s16 y = txt->centered_y_pos;
    s16 w = txt->width;
    s16 h = txt->height;

    if (txt->field8_0x3d != 0 || txt->is_fond)
        DISPLAY_BLACKBOX(x - 3, y - 3, w + 6, h + 6, 254, txt->is_fond);
    
    display_text(txt->text, txt->x_pos, txt->y_pos, txt->font_size, txt->color);
}
