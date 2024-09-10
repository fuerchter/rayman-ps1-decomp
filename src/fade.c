#include "fade.h"

extern RGBAArray *D_801C7D78[11];
extern s16 D_801CEFF4;
extern s16 D_801CEFF6;
extern void *D_801C7D68[4];
extern RGBAArray D_801CF008;
extern s16 D_801CF00C;
extern u16 D_801CF00E;
extern s16 D_801CF010;
extern s16 D_801CF012;
extern s16 D_801CF014;
extern s16 D_801CF410;
extern s16 D_801CF016;
extern u8 D_801F8480;

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

/* 4523C 80169A3C -O2 -msoft-float */
void FUN_80169a3c(RGBAArray *param_1, s16 param_2)
{
    PS1_CurrentDisplay->field_0x60bc_0x660b[2].tile.r0 = param_1->data[0];
    PS1_CurrentDisplay->field_0x60bc_0x660b[2].tile.g0 = param_1->data[1];
    PS1_CurrentDisplay->field_0x60bc_0x660b[2].tile.b0 = param_1->data[2];
    AddPrim(
        &PS1_CurrentDisplay->ordering_table[param_2],
        &PS1_CurrentDisplay->field_0x60bc_0x660b[2].tile
    );
    AddPrim(
        &PS1_CurrentDisplay->ordering_table[param_2],
        &PS1_CurrentDisplay->field_0x60bc_0x660b[2]
    );
}

/* 452C8 80169AC8 -O2 -msoft-float */
void FUN_80169ac8(RGBAArray *param_1, s16 param_2)
{
    PS1_CurrentDisplay->field_0x60bc_0x660b[3].tile.r0 = param_1->data[0];
    PS1_CurrentDisplay->field_0x60bc_0x660b[3].tile.g0 = param_1->data[1];
    PS1_CurrentDisplay->field_0x60bc_0x660b[3].tile.b0 = param_1->data[2];
    AddPrim(
        &PS1_CurrentDisplay->ordering_table[param_2],
        &PS1_CurrentDisplay->field_0x60bc_0x660b[3].tile
    );
    AddPrim(
        &PS1_CurrentDisplay->ordering_table[param_2],
        &PS1_CurrentDisplay->field_0x60bc_0x660b[3]
    );
}

void FUN_80169b54(void) {}

void FUN_80169b5c(void) {}

/* 45364 80169B64 -O2 -msoft-float */
void INIT_FADE_OUT(void)
{
    D_801F7FF0 = 1;
    D_801F8480 = 8;
    D_801CF016 = 8;
    D_801CF018 = 1;
    fade = 32;
}

/* 453A8 80169BA8 -O2 -msoft-float */
void INIT_FADE_IN(void)
{
    D_801F7FF0 = 0;
    D_801CF018 = 0;
    D_801F8480 = 0xFF;
    D_801CF016 = -8;
    fade = 32;
}

INCLUDE_ASM("asm/nonmatchings/fade", DO_FADE);

INCLUDE_ASM("asm/nonmatchings/fade", PS1_DO_FADE_OUT_PRG);

INCLUDE_ASM("asm/nonmatchings/fade", DO_FADE_OUT);

INCLUDE_ASM("asm/nonmatchings/fade", PS1_DO_PICTURE_IN_PICTURE);
