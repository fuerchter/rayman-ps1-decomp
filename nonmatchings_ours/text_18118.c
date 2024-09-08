#include "text_18118.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/text_18118", DrawFondBoxNormal);*/

void DrawFondBoxNormal(s16 param_1, s16 param_2, s16 param_3, s16 param_4, u8 param_5)
{
    s16 temp_t3;
    s16 temp_t4;
    s32 temp_s0;
    u8 var_s2;
    TILE *test_1;
    u16 test_2 = 0xFFFD;

    PS1_CurrentDisplay->fond_box_tiles[0].x0 = param_1 + test_2;
    PS1_CurrentDisplay->fond_box_tiles[0].y0 = param_2 + test_2;
    PS1_CurrentDisplay->fond_box_tiles[0].w = param_3 + 6;
    PS1_CurrentDisplay->fond_box_tiles[0].h = 3;
    PS1_CurrentDisplay->fond_box_tiles[0].r0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[0].g0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[0].b0 = 0xFF;
    PS1_CurrentDisplay->fond_box_tiles[1].x0 = param_1 + param_3;
    PS1_CurrentDisplay->fond_box_tiles[1].y0 = param_2;
    PS1_CurrentDisplay->fond_box_tiles[1].w = 3;
    PS1_CurrentDisplay->fond_box_tiles[1].h = param_4;
    PS1_CurrentDisplay->fond_box_tiles[1].r0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[1].g0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[1].b0 = 0xFF;
    PS1_CurrentDisplay->fond_box_tiles[2].x0 = param_1 + test_2;
    PS1_CurrentDisplay->fond_box_tiles[2].y0 = param_2 + param_4;
    PS1_CurrentDisplay->fond_box_tiles[2].w = param_3 + 6;
    PS1_CurrentDisplay->fond_box_tiles[2].h = 3;
    PS1_CurrentDisplay->fond_box_tiles[2].r0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[2].g0 = 0;
    PS1_CurrentDisplay->fond_box_tiles[2].b0 = 0xFF;
    PS1_CurrentDisplay->fond_box_tiles[3].x0 = param_1 + test_2;
    PS1_CurrentDisplay->fond_box_tiles[3].y0 = param_2;
    PS1_CurrentDisplay->fond_box_tiles[3].w = 3;
    PS1_CurrentDisplay->fond_box_tiles[3].h = param_4;
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
    PS1_CurrentDisplay->fond_box_tile.x0 = param_1;
    PS1_CurrentDisplay->fond_box_tile.y0 = param_2;
    PS1_CurrentDisplay->fond_box_tile.w = param_3;
    PS1_CurrentDisplay->fond_box_tile.h = param_4;
    if ((param_5 & 0xFF) == 0xFF)
    {
        SetSemiTrans(&PS1_CurrentDisplay->fond_box_tile, 0);
        PS1_CurrentDisplay->fond_box_tile.r0 = 0;
        PS1_CurrentDisplay->fond_box_tile.g0 = 0;
        PS1_CurrentDisplay->fond_box_tile.b0 = 0;
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->fond_box_tile);
        return;
    }
    PS1_CurrentDisplay->fond_box_tile.r0 = param_5;
    PS1_CurrentDisplay->fond_box_tile.g0 = param_5;
    PS1_CurrentDisplay->fond_box_tile.b0 = param_5;
    AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->fond_box_tile);
    PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 2, 0, 0x00000100);
    SetDrawEnv(&PS1_CurrentDisplay->unk_dr_env, &PS1_CurrentDisplay->drawing_environment);
    AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->unk_dr_env);
}