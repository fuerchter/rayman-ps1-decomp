#include "draw.h"

/* idk, did not try very hard to understand the diff */
/*INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawColoredSprite);*/

void PS1_DrawColoredSprite(Sprite *sprite, s16 x, s16 y, u8 display_mode)
{
    POLY_FT4 *var_s0;
    s16 temp_a0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v1;
    s16 temp_v1_3;
    POLY_FT4 *var_v0;
    u32 temp_a3;
    u8 temp_a0;
    u8 temp_a2;
    u8 temp_a2_2;
    u8 temp_a2_3;
    u8 temp_a2_4;
    u8 temp_t0;
    u8 temp_t0_2;
    u8 temp_t0_3;
    u8 temp_t0_4;
    u8 temp_t0_5;
    u8 temp_t1;
    u8 temp_t1_2;
    u8 temp_t1_3;
    u8 temp_t1_4;
    u8 temp_t2;
    u8 temp_t2_2;
    u8 temp_t2_3;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v1_2;
    u8 var_t2;

    temp_v1 = PS1_PolygonsCount;
    if (temp_v1 < 0xC8)
    {
        PS1_PolygonsCount = temp_v1 + 1;
        var_s0 = &PS1_CurrentDisplay->polygons[temp_v1];
    }
    else
    {
        if (PS1_CurrentDisplay != &PS1_Display1)
        {
            var_v0 = 0x800E3F2C;
        }
        else
        {
            var_v0 = 0x800D772C;
        }
        var_s0 = &var_v0[temp_v1];
        SetPolyFT4(var_s0);
        PS1_PolygonsCount = (u16) PS1_PolygonsCount + 1;
    }
    temp_a3 = display_mode & 0xFF;
    if (sprite->id != 0)
    {
        temp_t0 = sprite->page_x;
        temp_t2 = sprite->page_y;
        temp_a0 = sprite->width;
        temp_v1_2 = sprite->height;
        temp_v0 = temp_t0 + temp_a0;
        var_s0->clut = sprite->clut;
        temp_v0_2 = temp_t2 + temp_v1_2;
        temp_v0_3 = x + temp_a0;
        temp_a0_2 = y + temp_a0;
        var_s0->tpage = sprite->tpage;
        temp_v0_4 = y + temp_v1_2;
        temp_v1_3 = x + temp_v1_2;
        switch (temp_a3)
        {
        case 1:
            temp_t0_2 = temp_t0 - 1;
            temp_a2 = temp_v0 - 1;
            var_s0->u0 = temp_a2;
            var_s0->v0 = temp_t2;
            var_s0->u1 = temp_t0_2;
            var_s0->v1 = temp_t2;
            var_s0->u2 = temp_a2;
            var_s0->v2 = temp_v0_2;
            var_s0->u3 = temp_t0_2;
            var_s0->v3 = temp_v0_2;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v0_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_v0_4;
            var_s0->x3 = temp_v0_3;
            var_s0->y3 = temp_v0_4;
            break;
        case 2:
            temp_t2_2 = temp_t2 - 1;
            temp_t1 = temp_v0_2 - 1;
            var_s0->u0 = temp_t0;
            var_s0->v0 = temp_t1;
            var_s0->u1 = temp_v0;
            var_s0->v1 = temp_t1;
            var_s0->u2 = temp_t0;
            var_s0->v2 = temp_t2_2;
            var_s0->u3 = temp_v0;
            var_s0->v3 = temp_t2_2;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v0_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_v0_4;
            var_s0->x3 = temp_v0_3;
            var_s0->y3 = temp_v0_4;
            break;
        case 3:
            temp_t0_3 = temp_t0 - 1;
            temp_a2_2 = temp_v0 - 1;
            temp_t2_3 = temp_t2 - 1;
            temp_t1_2 = temp_v0_2 - 1;
            var_s0->u0 = temp_a2_2;
            var_s0->v0 = temp_t1_2;
            var_s0->u1 = temp_t0_3;
            var_s0->v1 = temp_t1_2;
            var_s0->u2 = temp_a2_2;
            var_s0->v2 = temp_t2_3;
            var_s0->u3 = temp_t0_3;
            var_s0->v3 = temp_t2_3;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v0_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_v0_4;
            var_s0->x3 = temp_v0_3;
            var_s0->y3 = temp_v0_4;
            break;
        case 4:
            temp_t0_4 = temp_t0 - 1;
            temp_a2_3 = temp_v0 - 1;
            var_s0->u0 = temp_a2_3;
            var_s0->v0 = temp_t2;
            var_s0->u1 = temp_a2_3;
            var_s0->v1 = temp_v0_2;
            var_s0->u2 = temp_t0_4;
            var_s0->v2 = temp_t2;
            var_s0->u3 = temp_t0_4;
            var_s0->v3 = temp_v0_2;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v1_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_a0_2;
            var_s0->x3 = temp_v1_3;
            var_s0->y3 = temp_a0_2;
            break;
        case 5:
            var_t2 = temp_t2 - 1;
            temp_t1_3 = temp_v0_2 - 1;
            var_s0->u0 = temp_t0;
            var_s0->v0 = temp_t1_3;
            var_s0->u1 = temp_t0;
            var_s0->v1 = var_t2;
            var_s0->u2 = temp_v0;
            var_s0->v2 = temp_t1_3;
            var_s0->u3 = temp_v0;
            var_s0->v3 = var_t2;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v1_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_a0_2;
            var_s0->x3 = temp_v1_3;
            var_s0->y3 = temp_a0_2;
            break;
        case 6:
            var_s0->u0 = temp_t0;
            var_s0->v0 = temp_t2;
            var_s0->u1 = temp_t0;
            var_s0->v1 = temp_v0_2;
            var_s0->u2 = temp_v0;
            var_s0->v2 = temp_t2;
            var_s0->u3 = temp_v0;
            var_s0->v3 = temp_v0_2;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v1_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_a0_2;
            var_s0->x3 = temp_v1_3;
            var_s0->y3 = temp_a0_2;
            break;
        case 7:
            temp_t0_5 = temp_t0 - 1;
            temp_a2_4 = temp_v0 - 1;
            var_t2 = temp_t2 - 1;
            temp_t1_4 = temp_v0_2 - 1;
            var_s0->u0 = temp_a2_4;
            var_s0->v0 = temp_t1_4;
            var_s0->u1 = temp_a2_4;
            var_s0->v1 = var_t2;
            var_s0->u2 = temp_t0_5;
            var_s0->v2 = temp_t1_4;
            var_s0->u3 = temp_t0_5;
            var_s0->v3 = var_t2;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v1_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_a0_2;
            var_s0->x3 = temp_v1_3;
            var_s0->y3 = temp_a0_2;
            break;
        case 0:
        default:
            var_s0->u0 = temp_t0;
            var_s0->v0 = temp_t2;
            var_s0->u1 = temp_v0;
            var_s0->v1 = temp_t2;
            var_s0->u2 = temp_t0;
            var_s0->v2 = temp_v0_2;
            var_s0->u3 = temp_v0;
            var_s0->v3 = temp_v0_2;
            var_s0->x0 = x;
            var_s0->y0 = y;
            var_s0->x1 = temp_v0_3;
            var_s0->y1 = y;
            var_s0->x2 = x;
            var_s0->y2 = temp_v0_4;
            var_s0->x3 = temp_v0_3;
            var_s0->y3 = temp_v0_4;
            break;
        }
        SetShadeTex(var_s0, 1);
        if (PS1_DrawSpriteSemiTrans != 0)
        {
            SetSemiTrans(var_s0, 1);
        }
        else
        {
            SetSemiTrans(var_s0, 0);
        }
        AddPrim(PS1_PrevPrim, var_s0);
        PS1_PrevPrim = var_s0;
    }
}

/*INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawScaledSprite);*/

void PS1_DrawScaledSprite(Sprite *sprite, s16 x, s16 y, u8 is_flipped, s16 param_5)
{
    POLY_FT4 *temp_s1;
    s16 temp_a3;
    s16 temp_s0_2;
    s16 height;
    s32 temp_s0;
    s32 temp_v0_2;
    u16 temp_v0;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a2;
    u8 page_x;
    u8 temp_s3_2;
    u8 page_y;
    s16 width;

    temp_s1 = &PS1_CurrentDisplay->polygons[PS1_PolygonsCount++];
    if (sprite->id != 0)
    {
        page_x = sprite->page_x;
        page_y = sprite->page_y;
        if (param_5 > 0)
        {
            width = sprite->width;
            height = sprite->height + 1;
        }
        else
        {
            width = sprite->width + 0xFFFF;
            height = sprite->height + 0xFFFF;
        }
        temp_s0 = get_proj_dist(param_5, width);
        temp_v0_2 = get_proj_dist(param_5, height);
        temp_a0 = page_x + width;
        temp_v0 = (x + temp_s0) - 1;
        temp_a2 = (page_y + height) - 1;
        temp_a1 = temp_a0 - 1;
        temp_s1->clut = sprite->clut;
        temp_a3 = (y + temp_v0_2) - 1;
        temp_s1->tpage = sprite->tpage;
        if (is_flipped != 0)
        {
            temp_s3_2 = page_x - 1;
            temp_s1->u0 = temp_a1;
            temp_s1->v0 = page_y;
            temp_s1->u1 = temp_s3_2;
            temp_s1->v1 = page_y;
            temp_s1->u2 = temp_a1;
            temp_s1->v2 = temp_a2;
            temp_s1->u3 = temp_s3_2;
        }
        else
        {
            temp_s1->u0 = page_x;
            temp_s1->v0 = page_y;
            temp_s1->u1 = temp_a0;
            temp_s1->v1 = page_y;
            temp_s1->u2 = page_x;
            temp_s1->v2 = temp_a2;
            temp_s1->u3 = temp_a0;
        }
        temp_s1->v3 = temp_a2;
        temp_s0_2 = temp_v0 + 1;
        temp_s1->x0 = x;
        temp_s1->y0 = y;
        temp_s1->x1 = temp_s0_2;
        temp_s1->y1 = y;
        temp_s1->x2 = x;
        temp_s1->y2 = temp_a3;
        temp_s1->x3 = temp_s0_2;
        temp_s1->y3 = temp_a3;
        SetShadeTex(temp_s1, 1);
        SetSemiTrans(temp_s1, 0);
        AddPrim(PS1_PrevPrim, temp_s1);
        PS1_PrevPrim = temp_s1;
    }
}