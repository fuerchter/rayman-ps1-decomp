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
    D_801F8480 = 255;
    D_801CF016 = -8;
    fade = 32;
}

/* 453E4 80169BE4 -O2 -msoft-float */
void DO_FADE(void)
{
    if (fade != 0)
    {
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801CF018)->tile.r0 = D_801F8480;
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801CF018)->tile.g0 = D_801F8480;
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801CF018)->tile.b0 = D_801F8480;
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[9],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[D_801CF018].tile
        );
        PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 2, 0, 256);
        SetDrawEnv(
            &PS1_CurrentDisplay->field_0x60bc_0x660b[D_801CF018].drawing_environment,
            &PS1_CurrentDisplay->drawing_environment
        );
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[9],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[D_801CF018]
        );

        if (D_801F8480 == 248 && D_801CF016 > 0)
            D_801F8480 = 255;
        else if (D_801F8480 == 255 && D_801CF016 < 0)
            D_801F8480 = 248;
        else
            D_801F8480 += D_801CF016;

        PS1_DisableInputs = true;
        if (--fade == 0)
            D_801CF018 = -1;
    }
}

/* 455D0 80169DD0 -O2 -msoft-float */
s16 PS1_DO_FADE_OUT_PRG(void)
{
    DO_FADE();
    return fade == 0;
}

/* 455F8 80169DF8 -O2 -msoft-float */
void DO_FADE_OUT(void)
{
    Display *new_disp;

    if (PS1_CurrentDisplay == &PS1_Display1)
        new_disp = &PS1_Display1 + 1;
    else
        new_disp = &PS1_Display1;
    MoveImage(
        &new_disp->drawing_environment.clip,
        PS1_CurrentDisplay->drawing_environment.clip.x, 
        PS1_CurrentDisplay->drawing_environment.clip.y
    );
    INIT_FADE_OUT();
    SYNCHRO_LOOP(PS1_DO_FADE_OUT_PRG);
}

INCLUDE_ASM("asm/nonmatchings/fade", PS1_DO_PICTURE_IN_PICTURE);
