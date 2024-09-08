#include "unknown/draw_548CC.h"

typedef struct Vec2 {
    s16 x;
    s16 y;
} Vec2;

typedef struct RGB {
    u8 r;
    u8 g;
    u8 b;
} RGB;

typedef struct RGBA {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RGBA;

extern Vec2 D_801E4E60[16];
extern Vec2 D_801E4EA8[16];

extern s16 D_801CF064;
extern s16 D_801CF066;
extern s16 D_801CF068;
extern s16 D_801CF418;
extern s16 D_801CF420;
extern s16 D_801CF428;
extern s16 D_801CF430;
extern s16 x_luc;
extern s16 y_luc;

extern u16 D_801CF086;
extern s16 D_801CF088;
extern s16 D_801CF08A;
extern Vec2 D_801FAA48[2];

extern RGBA D_801CF06C; /* being treated as s32? */
extern RGBA D_801CF070;
extern RGBA D_801CF074;
extern RGBA D_801CF078;
extern RGBA D_801CF07C;
extern RGBA D_801CF080;

extern RGB D_801C7EAC[4];
extern u16 D_801CF090;
extern u16 D_801CF092; /* is this its own var? part of array or struct? see DISPLAY_FOND_MENU */
extern u16 D_801CF094;
extern s16 D_801CF096;
extern s16 D_801CF098;
extern Vec2 D_801FAA58[2];

extern s32 D_801F8168;
extern s32 D_801F816C;
extern s32 PS1_TPage_x;
extern s32 PS1_TPage_y;

/* 548CC 801790CC -O2 -msoft-float */
void FUN_801790cc(Display *display)
{
    u16 i;
    u16 unk_2;
    u16 unk_1 = 0x100;
    
    for (i = 0; i < LEN(display->field_0x66dc_0x673b); i++)
    {
        SetTile(display->field_0x66dc_0x673b + i);
        (display->field_0x66dc_0x673b + i)->r0 = 0;
        (display->field_0x66dc_0x673b + i)->g0 = 0;
        (display->field_0x66dc_0x673b + i)->b0 = 0;
    }

    i = 0;
    unk_2 = 0;
    while (i < LEN(D_801E4E60))
    {
        D_801E4E60[i].x = rcos(unk_2) * 45 >> 12;
        D_801E4E60[i].y = rsin(unk_2) * 45 >> 12;
        D_801E4EA8[i].x = (u32) rcos(unk_2) * 5 >> 8;
        D_801E4EA8[i].y = (u32) rsin(unk_2) * 5 >> 8;
        i++;
        unk_2 -= unk_1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unknown/draw_548CC", Display_and_free_luciole);

/* 55EF8 8017A6F8 -O2 -msoft-float */
void FUN_8017a6f8(void)
{
    s32 unk_1;
    u16 unk_2;
    u16 unk_3 = 160;
    u16 unk_4 = 120;
    u16 unk_5 = 256;
    u16 i = 0; /* couldn't move this to create for-loop */
    RGBA *col_1 = &D_801CF070;
    RGBA *col_2 = &D_801CF074;
    RGBA *col_3 = &D_801CF078;
    RGBA *col_4 = &D_801CF07C;
    
    while (i < LEN(PS1_CurrentDisplay->unk_poly_g3s))
    {
        SetPolyG3(&PS1_CurrentDisplay->unk_poly_g3s[i]);
        SetSemiTrans(&PS1_CurrentDisplay->unk_poly_g3s[i], 0);
        SetShadeTex(&PS1_CurrentDisplay->unk_poly_g3s[i], 1);
        unk_1 = i;
        unk_1 &= 3;
        if (unk_1 == 0)
        {
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r1 = col_1->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g1 = col_1->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b1 = col_1->b;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r2 = col_2->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g2 = col_2->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b2 = col_2->b;
        }
        else if (unk_1 == 1)
        {
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r1 = col_2->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g1 = col_2->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b1 = col_2->b;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r2 = col_3->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g2 = col_3->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b2 = col_3->b;
        }
        else if (unk_1 == 2)
        {
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r1 = col_3->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g1 = col_3->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b1 = col_3->b;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r2 = col_4->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g2 = col_4->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b2 = col_4->b;
        }
        else
        {
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r1 = col_4->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g1 = col_4->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b1 = col_4->b;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->r2 = col_1->r;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->g2 = col_1->g;
            (PS1_CurrentDisplay->unk_poly_g3s + i)->b2 = col_1->b;
        }
        (PS1_CurrentDisplay->unk_poly_g3s + i)->r0 = 0;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->g0 = 0;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->b0 = 0;
        
        D_801FAA48[0].x = (D_801CF08A * rcos(D_801CF086) >> 12) + unk_3;
        D_801FAA48[0].y = (D_801CF08A * rsin(D_801CF086) >> 12) + unk_4;
        unk_2 = D_801CF086 + unk_5;
        D_801FAA48[1].x = (D_801CF08A * rcos(unk_2) >> 12) + unk_3;
        D_801FAA48[1].y = (D_801CF08A * rsin(unk_2) >> 12) + unk_4;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->x0 = unk_3;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->y0 = unk_4;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->x1 = D_801FAA48[0].x;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->y1 = D_801FAA48[0].y;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->x2 = D_801FAA48[1].x;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->y2 = D_801FAA48[1].y;
        AddPrim(PS1_CurrentDisplay->ordering_table, &PS1_CurrentDisplay->unk_poly_g3s[i]);
        D_801CF086 += unk_5;
        i++;
    }
    D_801CF088 += 10;
    D_801CF086 = D_801CF088;
}

INCLUDE_ASM("asm/nonmatchings/unknown/draw_548CC", DISPLAY_FOND_MENU);

/* 56A60 8017B260 -O2 -msoft-float */
void FUN_8017b260(u16 param_1)
{
    if (GetGraphType() != 0)
    {
        D_801F8168 = (param_1 >> 9);
        D_801F816C = (param_1 >> 7) & 3;
        PS1_TPage_y = (param_1 << 3) & 768;
        PS1_TPage_x = (param_1 << 6) & 1023;
    }
    else
    {
        D_801F8168 = (param_1 >> 7);
        D_801F816C = (param_1 >> 5) & 3;
        PS1_TPage_y = (param_1 << 4) & 256;
        PS1_TPage_x = (param_1 << 6) & 1023;
    }
}
