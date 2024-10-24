#include "draw/draw_548CC.h"

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
        D_801E4E60[i].vx = rcos(unk_2) * 45 >> 12;
        D_801E4E60[i].vy = rsin(unk_2) * 45 >> 12;
        D_801E4EA8[i].vx = (u32) rcos(unk_2) * 5 >> 8;
        D_801E4EA8[i].vy = (u32) rsin(unk_2) * 5 >> 8;
        i++;
        unk_2 -= unk_1;
    }
}

INCLUDE_ASM("asm/nonmatchings/draw/draw_548CC", Display_and_free_luciole);

/* 55EF8 8017A6F8 -O2 -msoft-float */
void PS1_PerfectBonusDrawBg(void)
{
    s32 unk_1;
    u16 unk_2;
    u16 unk_3 = 160;
    u16 unk_4 = 120;
    u16 unk_5 = 256;
    u16 i = 0; /* couldn't move this to create for-loop */
    CVECTOR *col_1 = &D_801CF070;
    CVECTOR *col_2 = &D_801CF074;
    CVECTOR *col_3 = &D_801CF078;
    CVECTOR *col_4 = &D_801CF07C;
    
    while (i < LEN(PS1_CurrentDisplay->unk_poly_g3s))
    {
        SetPolyG3(&PS1_CurrentDisplay->unk_poly_g3s[i]);
        SetSemiTrans(&PS1_CurrentDisplay->unk_poly_g3s[i], false);
        SetShadeTex(&PS1_CurrentDisplay->unk_poly_g3s[i], true);
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
        
        D_801FAA48[0].vx = (D_801CF08A * rcos(D_801CF086) >> 12) + unk_3;
        D_801FAA48[0].vy = (D_801CF08A * rsin(D_801CF086) >> 12) + unk_4;
        unk_2 = D_801CF086 + unk_5;
        D_801FAA48[1].vx = (D_801CF08A * rcos(unk_2) >> 12) + unk_3;
        D_801FAA48[1].vy = (D_801CF08A * rsin(unk_2) >> 12) + unk_4;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->x0 = unk_3;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->y0 = unk_4;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->x1 = D_801FAA48[0].vx;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->y1 = D_801FAA48[0].vy;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->x2 = D_801FAA48[1].vx;
        (PS1_CurrentDisplay->unk_poly_g3s + i)->y2 = D_801FAA48[1].vy;
        AddPrim(PS1_CurrentDisplay->ordering_table, &PS1_CurrentDisplay->unk_poly_g3s[i]);
        D_801CF086 += unk_5;
        i++;
    }
    D_801CF088 += 10;
    D_801CF086 = D_801CF088;
}

INCLUDE_ASM("asm/nonmatchings/draw/draw_548CC", DISPLAY_FOND_MENU);

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
