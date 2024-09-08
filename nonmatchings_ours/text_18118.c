#include "text_18118.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/text_18118", DrawFondBoxNormal);*/

void DrawFondBoxNormal(s16 x, s16 y, s16 w, s16 h, u8 brightness)
{
    s16 temp_t3;
    s16 temp_t4;
    s32 temp_s0;
    u8 var_s2;
    TILE *test_1;
    u16 test_2 = 0xFFFD;

    PS1_CurrentDisplay->fond_box_tiles[0].x0 = x + test_2;
    PS1_CurrentDisplay->fond_box_tiles[0].y0 = y + test_2;
    PS1_CurrentDisplay->fond_box_tiles[0].w = w + 6;
    PS1_CurrentDisplay->fond_box_tiles[0].h = 3;
    PS1_CurrentDisplay->fond_box_tiles[0].r0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[0].g0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[0].b0 = 0xFF;
    PS1_CurrentDisplay->fond_box_tiles[1].x0 = x + w;
    PS1_CurrentDisplay->fond_box_tiles[1].y0 = y;
    PS1_CurrentDisplay->fond_box_tiles[1].w = 3;
    PS1_CurrentDisplay->fond_box_tiles[1].h = h;
    PS1_CurrentDisplay->fond_box_tiles[1].r0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[1].g0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[1].b0 = 0xFF;
    PS1_CurrentDisplay->fond_box_tiles[2].x0 = x + test_2;
    PS1_CurrentDisplay->fond_box_tiles[2].y0 = y + h;
    PS1_CurrentDisplay->fond_box_tiles[2].w = w + 6;
    PS1_CurrentDisplay->fond_box_tiles[2].h = 3;
    PS1_CurrentDisplay->fond_box_tiles[2].r0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[2].g0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[2].b0 = 0xFF;
    PS1_CurrentDisplay->fond_box_tiles[3].x0 = x + test_2;
    PS1_CurrentDisplay->fond_box_tiles[3].y0 = y;
    PS1_CurrentDisplay->fond_box_tiles[3].w = 3;
    PS1_CurrentDisplay->fond_box_tiles[3].h = h;
    PS1_CurrentDisplay->fond_box_tiles[3].r0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[3].g0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[3].b0 = 0xFF;
    var_s2 = 0;
    while ((var_s2) < LEN(PS1_CurrentDisplay->fond_box_tiles))
    {
        SetTile(&PS1_CurrentDisplay->fond_box_tiles[var_s2]);
        SetSemiTrans(&PS1_CurrentDisplay->fond_box_tiles[var_s2], 0);
        SetShadeTex(&PS1_Display1.fond_box_tiles[var_s2], 1);
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->fond_box_tiles[var_s2]);
        var_s2 += 1;
    }
    SetTile(&PS1_CurrentDisplay->fond_box_tile);
    SetShadeTex(&PS1_CurrentDisplay->fond_box_tile, 1);
    PS1_CurrentDisplay->fond_box_tile.x0 = x;
    PS1_CurrentDisplay->fond_box_tile.y0 = y;
    PS1_CurrentDisplay->fond_box_tile.w = w;
    PS1_CurrentDisplay->fond_box_tile.h = h;
    if ((brightness & 0xFF) == 0xFF)
    {
        SetSemiTrans(&PS1_CurrentDisplay->fond_box_tile, 0);
        PS1_CurrentDisplay->fond_box_tile.r0 = 0;
        PS1_CurrentDisplay->fond_box_tile.g0 = 0;
        PS1_CurrentDisplay->fond_box_tile.b0 = 0;
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->fond_box_tile);
        return;
    }
    PS1_CurrentDisplay->fond_box_tile.r0 = brightness;
    PS1_CurrentDisplay->fond_box_tile.g0 = brightness;
    PS1_CurrentDisplay->fond_box_tile.b0 = brightness;
    AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->fond_box_tile);
    PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 2, 0, 0x00000100);
    SetDrawEnv(&PS1_CurrentDisplay->unk_dr_env, &PS1_CurrentDisplay->drawing_environment);
    AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->unk_dr_env);
}

/* matches, but some way to reduce duplication? */
/*INCLUDE_ASM("asm/nonmatchings/text_18118", DrawBlackBoxNormal);*/

void DrawBlackBoxNormal(s16 x, s16 y, s16 w, s16 h, u8 brightness)
{
    D_801F81B0++;
    SetTile(&(PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile);
    SetShadeTex(&(PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile, 1);
    (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.x0 = x;
    (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.y0 = y;
    (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.w = w;
    (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.h = h;
    if (brightness == 255)
    {
        SetSemiTrans(&(PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile, 0);
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.r0 = 0;
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.g0 = 0;
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.b0 = 0;
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[9],
            &(PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile
        );
    }
    else
    {
        SetSemiTrans(&(PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile, 1);
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.r0 = brightness;
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.g0 = brightness;
        (PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile.b0 = brightness;
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[9],
            &(PS1_CurrentDisplay->field_0x60bc_0x660b + D_801F81B0 + 7)->tile
        );
        (PS1_CurrentDisplay->drawing_environment).tpage = GetTPage(1, 2, 0, 256);
        SetDrawEnv(
            &PS1_CurrentDisplay->field_0x60bc_0x660b[D_801F81B0 + 7].drawing_environment,
            &PS1_CurrentDisplay->drawing_environment
        );
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[9],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[D_801F81B0 + 7].drawing_environment
        );
    }
}