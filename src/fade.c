#include "fade.h"

extern RGBA *D_801C7D78[11];
extern s16 D_801CEFF4;
extern s16 D_801CEFF6;

/* 44C20 80169420 -O2 -msoft-float */
void FUN_80169420(Display *disp)
{
    s16 i;
    TILE *cur_tile;
    DRAWENV *drawenv;
    
    for (i = 0; i < (s16) LEN(disp->field_0x60bc_0x660b); i++)
    {
        cur_tile = &disp->field_0x60bc_0x660b[i].tile;
        SetTile(cur_tile);
        SetSemiTrans(cur_tile, true);
        SetShadeTex(cur_tile, true);
        (disp->field_0x60bc_0x660b + i)->tile.x0 = 0;
        (disp->field_0x60bc_0x660b + i)->tile.y0 = 0;
        (disp->field_0x60bc_0x660b + i)->tile.w = disp->drawing_environment.clip.w;
        (disp->field_0x60bc_0x660b + i)->tile.h = disp->drawing_environment.clip.h;
    }
    drawenv = &disp->drawing_environment;
    disp->drawing_environment.tpage = GetTPage(1, 2, 0, 256);
    SetDrawEnv(&disp->field_0x60bc_0x660b[0].drawing_environment, drawenv);
    disp->drawing_environment.tpage = GetTPage(1, 2, 0, 256);
    SetDrawEnv(&disp->field_0x60bc_0x660b[1].drawing_environment, drawenv);
    disp->drawing_environment.tpage = GetTPage(1, 2, 0, 256);
    SetDrawEnv(&disp->field_0x60bc_0x660b[2].drawing_environment, drawenv);
    disp->drawing_environment.tpage = GetTPage(1, 1, 0, 256);
    SetDrawEnv(&disp->field_0x60bc_0x660b[5].drawing_environment, drawenv);
}

/* 44D64 80169564 -O2 -msoft-float */
void FUN_80169564(u32 param_1, s16 param_2)
{
    if (D_801CEFF6 == 2)
        FUN_801695ec(param_2);
    else if (param_1 & 8 && D_801CEFF6 == 0)
    {
        D_801CEFF6 = 1;
        FUN_801695ec(param_2);
    }
    else if (param_1 & 1)
    {
        D_801CEFF4 = 1;
        FUN_80169a3c(D_801C7D78[1], param_2);
    }
}

INCLUDE_ASM("asm/nonmatchings/fade", FUN_801695ec);

INCLUDE_ASM("asm/nonmatchings/fade", FUN_80169a3c);

INCLUDE_ASM("asm/nonmatchings/fade", FUN_80169ac8);

void FUN_80169b54(void) {}

void FUN_80169b5c(void) {}

INCLUDE_ASM("asm/nonmatchings/fade", INIT_FADE_OUT);

INCLUDE_ASM("asm/nonmatchings/fade", INIT_FADE_IN);

INCLUDE_ASM("asm/nonmatchings/fade", DO_FADE);

INCLUDE_ASM("asm/nonmatchings/fade", PS1_DO_FADE_OUT_PRG);

INCLUDE_ASM("asm/nonmatchings/fade", DO_FADE_OUT);

INCLUDE_ASM("asm/nonmatchings/fade", PS1_DO_PICTURE_IN_PICTURE);
