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

/* matches, but PS1_CurrentDisplay accesses, duplication */
/*INCLUDE_ASM("asm/nonmatchings/text_18118", display_text_sin);*/

void display_text_sin(u8 *text, s16 in_x, s16 in_y, s16 temps, u8 font, u8 param_6)
{
    s16 let_width;
    u8 sprite_ind;
    s16 unk_y_1;
    s16 unk_1;
    s16 space_width;
    s16 unk_x; s16 unk_y_2;
    s16 i; u8 let;
    Sprite *sprite;
    s16 unk_y_3;

    sprite_ind = 0;
    if (font == 2)
    {
        unk_y_1 = 15;
        unk_1 = 1;
        space_width = 8;
    }
    else if (font == 1)
    {
        unk_y_1 = 23;
        unk_1 = 3;
        space_width = 10;
    }
    else
    {
        unk_y_1 = 36;
        unk_1 = 3;
        space_width = 12;
    }

    unk_x = in_x;
    unk_y_2 = in_y;
    if (text[0] != 0) /* couldn't make this a while loop */
    {
        i = 0;
        do
        {
            let = text[i];
            if (let == '/')
            {
                unk_x = in_x - ((s16) calc_largmax_text(text, i, space_width, unk_1, font) >> 1);
                if (i > 1)
                    unk_y_2 += unk_y_1;
                sprite_ind = 0;
            }
            else if (let == ' ')
            {
                unk_x += space_width;
                sprite_ind = 0;
            }
            else
                sprite_ind = deter_num_let(let);

            if (sprite_ind != 0)
            {
                let_width = calc_let_Width(font, sprite_ind);
                calc_num_let_spr(font, &sprite_ind);
                switch (font)
                {
                case 0:
                case 1:
                    sprite = &alpha2.sprites[sprite_ind];
                    sprite->clut = GetClut(param_6 * 16 + 768, 492);
                    unk_y_3 = costab[(temps + (i << 5)) % ((s16) LEN(costab) - 1)];
                    PS1_DrawSprite(sprite, unk_x, (unk_y_2 - sprite->height) + ashr16(__builtin_abs(unk_y_3), 5), 0);
                    break;
                case 2:
                    sprite = &alpha.sprites[sprite_ind];
                    sprite->clut = GetClut(param_6 * 16 + 768, 492);
                    unk_y_3 = costab[(temps + (i << 5)) % ((s16) LEN(costab) - 1)];
                    PS1_DrawSprite(sprite, unk_x, (unk_y_2 - sprite->height) + ashr16(__builtin_abs(unk_y_3), 5), 0);
                    break;
                }

                if (let_shadow)
                {
                    PS1_PolygonIndexTable[PS1_PolygonIndexTableCount] = PS1_PolygonsCount;
                    PS1_PolygonIndexTableCount++;
                    SetSemiTrans(PS1_CurrentDisplay->polygons + PS1_PolygonsCount, true);
                    SetShadeTex(PS1_CurrentDisplay->polygons + PS1_PolygonsCount, false);
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->r0 = 20;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->g0 = 20;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->b0 = 20;

                    PS1_CurrentDisplay->polygons[PS1_PolygonsCount].clut = sprite->clut;
                    FUN_8017b260(*(s16 *)&sprite->tpage); /* TODO: sprite tpage s16 maybe? */
                    PS1_CurrentDisplay->polygons[PS1_PolygonsCount].tpage = GetTPage(0, 0, PS1_TPage_x, PS1_TPage_y);

                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->u0 = sprite->page_x;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->v0 = sprite->page_y;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->u1 = sprite->page_x + sprite->width;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->v1 = sprite->page_y;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->u2 = sprite->page_x;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->v2 = sprite->page_y + sprite->height;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->u3 = sprite->page_x + sprite->width;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->v3 = sprite->page_y + sprite->height;

                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->x0 = unk_x + 5;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->y0 =
                        unk_y_2 - sprite->height + 5 +
                        ashr16(__builtin_abs(costab[(temps + (i << 5)) % ((s16) LEN(costab) - 1)]), 5);
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->x1 = unk_x + 5 + sprite->width;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->y1 =
                        unk_y_2 - sprite->height + 5 +
                        ashr16(__builtin_abs(costab[(temps + (i << 5)) % ((s16) LEN(costab) - 1)]), 5);
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->x2 = unk_x + 5;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->y2 =
                        sprite->height +
                        (unk_y_2 - sprite->height + 5 +
                        ashr16(__builtin_abs(costab[(temps + (i << 5)) % ((s16) LEN(costab) - 1)]), 5));
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->x3 = unk_x + 5 + sprite->width;
                    (PS1_CurrentDisplay->polygons + PS1_PolygonsCount)->y3 =
                        sprite->height +
                        (unk_y_2 - sprite->height + 5 +
                        ashr16(__builtin_abs(costab[(temps + (i << 5)) % ((s16) LEN(costab) - 1)]), 5));
                    AddPrim(
                        &PS1_CurrentDisplay->ordering_table[5],
                        PS1_CurrentDisplay->polygons + PS1_PolygonsCount
                    );
                    PS1_PolygonsCount++;
                }
                unk_x += let_width - unk_1;
            }
            i++;
        } while (text[i] != 0);
    }
}