#include "draw/fade.h"

#ifdef BSS_DEFS
s16 fade;
u8 D_801F7FF0;
u8 D_801F8480;
#endif

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
void PS1_LightningLoop(u32 param_1, s16 param_2)
{
    if (D_801CEFF6 == 2)
        PS1_LightningDraw(param_2);
    else if (param_1 & 8 && D_801CEFF6 == 0)
    {
        D_801CEFF6 = 1;
        PS1_LightningDraw(param_2);
    }
    else if (param_1 & 1)
    {
        D_801CEFF4 = 1;
        FUN_80169a3c(D_801C7D78[1], param_2);
    }
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/draw/fade", PS1_LightningDraw);
#else
/* matches, but cleanup and label stuff */
/*INCLUDE_ASM("asm/nonmatchings/draw/fade", PS1_LightningDraw);*/

void PS1_LightningDraw(s16 param_1)
{
    RGBAArray **temp_v0_1;
    s16 temp_v0_3;
    s16 i;
    s32 temp_v1;
    s32 var_a1;
    s32 var_s0;
    s32 var_t0;
    u8 *temp_a0;
    u8 temp_v0_2;
    RGBAArray *new_var;

    var_s0 = 0;
    if (D_801CEFF6 == 1)
    {
        temp_v0_1 = &D_801C7D78[D_801CEFF4];
        D_801CF008.data[0] = (*temp_v0_1)->data[0];
        D_801CF008.data[1] = (*temp_v0_1)->data[1];
        D_801CF008.data[2] = (*temp_v0_1)->data[2];
        D_801CF410 = param_1;
        D_801CEFF6 = 2;
    }
    
    switch (D_801CF014)
    {
    case 0:
        for (i = 0; i < (s16) LEN(D_801CF008.data) - 1; i++)
        {
            temp_v1 = D_801CF008.data[i] - D_801CF00E;
            temp_v0_2 = -((s16) temp_v1 > 0) & temp_v1;
            D_801CF008.data[i] = temp_v0_2;
            var_a1 = false;
            if (temp_v0_2 || (s16) var_s0)
                var_a1 = true;
            var_s0 = var_a1;
        }

        if ((s16) var_s0 && D_801CEFF4 != 0)
            (D_801C7D68[D_801CEFF4 - 1])(&D_801CF008, D_801CF410);
        else
            D_801CF014 = 1;
        break;
    case 1:
        if (D_801CF010 == 250)
            D_801CF00C = -50;
        else if (D_801CF010 == 0)
            D_801CF00C = 50;

        D_801CF010 += D_801CF00C;
        if (D_801CF010 == 0)
            D_801CF014 = 2;

        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.r0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.g0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.b0 = D_801CF010;
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile
        );
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5]
        );
        break;
    case 2:
        if (D_801CF010 == 100)
            D_801CF00C = -10;
        else if (D_801CF010 == 0)
            D_801CF00C = 10;
        
        D_801CF010 += D_801CF00C;
        if (D_801CF010 == 0)
            D_801CF014 = 3;
        
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.r0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.g0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.b0 = D_801CF010;
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile
        );
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5]
        );
        break;
    case 3:
        for (i = 0; i < (s16) LEN(D_801CF008.data) - 1; i++)
        {
            temp_v0_3 = D_801CF008.data[i] + D_801CF00E;
            new_var = D_801C7D78[D_801CEFF4];
            temp_a0 = &new_var->data[i];
            var_t0 = false;
            MIN_2(temp_v0_3, *temp_a0);
            D_801CF008.data[i] = temp_v0_3;
            if (((u8) temp_v0_3 != D_801C7D78[D_801CEFF4]->data[i]) || (s16) var_s0)
                var_t0 = true;
            var_s0 = var_t0;
        }

        if (D_801CEFF4 != 0)
            (D_801C7D68[D_801CEFF4 - 1])(&D_801CF008, D_801CF410);
        
        if (!((s16) var_s0))
        {
            D_801CF012 = 0;
            D_801CF014 = 0;
            D_801CEFF6 = 0;
        }
        break;
    default:
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.r0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.g0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.b0 = D_801CF010;
        AddPrim(&PS1_CurrentDisplay->ordering_table[D_801CF410], &PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile);
        AddPrim(&PS1_CurrentDisplay->ordering_table[D_801CF410], &PS1_CurrentDisplay->field_0x60bc_0x660b[5]);
        break;    
    }
}
#endif

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

void FUN_80169b54(RGBAArray *param_1, s16 param_2) {}

void FUN_80169b5c(RGBAArray *param_1, s16 param_2) {}

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

    new_disp = &PS1_Displays[0];
    if (PS1_CurrentDisplay == &PS1_Displays[0])
        new_disp = &PS1_Displays[1];
        
    MoveImage(
        &new_disp->drawing_environment.clip,
        PS1_CurrentDisplay->drawing_environment.clip.x, 
        PS1_CurrentDisplay->drawing_environment.clip.y
    );
    INIT_FADE_OUT();
    SYNCHRO_LOOP(PS1_DO_FADE_OUT_PRG);
}

/* 45650 80169E50 -O2 -msoft-float */
void PS1_DO_PICTURE_IN_PICTURE(void)
{
    Display *new_disp;
    s32 cur_comp;
    POLY_FT4 *poly_1 = &PS1_CurrentDisplay->polygons[PS1_PolygonsCount++];
    POLY_FT4 *poly_2 = &PS1_CurrentDisplay->polygons[PS1_PolygonsCount];
    PS1_PolygonsCount += 2;
    
    new_disp = &PS1_Displays[0];
    if (PS1_CurrentDisplay == &PS1_Displays[0])
        new_disp = &PS1_Displays[1];
    
    poly_1->x0 = 120;
    poly_1->y0 = 5;
    poly_1->x1 = 152;
    poly_1->y1 = 5;
    poly_1->x2 = 120;
    poly_1->y2 = 57;
    poly_1->x3 = 152;
    poly_1->y3 = 57;
    cur_comp = new_disp->drawing_environment.clip.x;
    poly_1->u0 = cur_comp - (cur_comp / 128 * 128);

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_1->v0 = cur_comp - (cur_comp / 256 * 256);

    cur_comp = new_disp->drawing_environment.clip.x;
    poly_1->u1 = cur_comp - (cur_comp / 128 * 128) - 128;

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_1->v1 = cur_comp - (cur_comp / 256 * 256);

    cur_comp = new_disp->drawing_environment.clip.x;
    poly_1->u2 = cur_comp - (cur_comp / 128 * 128);

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_1->v2 = cur_comp - (cur_comp / 256 * 256) - 48;

    cur_comp = new_disp->drawing_environment.clip.x;
    poly_1->u3 = cur_comp - (cur_comp / 128 * 128) - 128;

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_1->v3 = cur_comp - (cur_comp / 256 * 256) - 48;
    SetShadeTex(poly_1, true);
    SetSemiTrans(poly_1, false);
    AddPrim(&PS1_CurrentDisplay->ordering_table[10], poly_1);
    poly_1->tpage = GetTPage(
        2,
        0,
        new_disp->drawing_environment.clip.x,
        new_disp->drawing_environment.clip.y + 16
    );

    poly_2->x0 = 152;
    poly_2->y0 = 5;
    poly_2->x1 = 200;
    poly_2->y1 = 5;
    poly_2->x2 = 152;
    poly_2->y2 = 57;
    poly_2->x3 = 200;
    poly_2->y3 = 57;
    cur_comp = new_disp->drawing_environment.clip.x + 128;
    poly_2->u0 = cur_comp - (cur_comp / 128 * 128);

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_2->v0 = cur_comp - (cur_comp / 256 * 256);

    cur_comp = new_disp->drawing_environment.clip.x + 128;
    poly_2->u1 = cur_comp - (cur_comp / 128 * 128) - 64;

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_2->v1 = cur_comp - (cur_comp / 256 * 256);

    cur_comp = new_disp->drawing_environment.clip.x + 128;
    poly_2->u2 = cur_comp - (cur_comp / 128 * 128);

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_2->v2 = cur_comp - (cur_comp / 256 * 256) - 48;

    cur_comp = new_disp->drawing_environment.clip.x + 128;
    poly_2->u3 = cur_comp - (cur_comp / 128 * 128) - 64;

    cur_comp = new_disp->drawing_environment.clip.y + 16;
    poly_2->v3 = cur_comp - (cur_comp / 256 * 256) - 48;
    SetShadeTex(poly_2, true);
    SetSemiTrans(poly_2, false);
    AddPrim(&PS1_CurrentDisplay->ordering_table[10], poly_2);
    poly_2->tpage = GetTPage(
        2,
        0,
        new_disp->drawing_environment.clip.x + 128,
        new_disp->drawing_environment.clip.y + 16
    );
}
