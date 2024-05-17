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

/* asm is functionally the same? just not matching... */
/*INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawRay);*/

void PS1_DrawRay(Sprite *sprite, s16 param_2, s16 param_3, u8 param_4, s16 angle_ind)
{
    u16 sp130;
    u16 sp138;
    u16 sp140;
    u16 sp148;
    POLY_FT4 *temp_s4;
    s16 *cur_angle;
    s16 temp_s1_3;
    s32 temp_lo;
    s32 temp_s1_2;
    s32 temp_v1_1;
    s32 temp_v1_2;
    u8 var_s0;
    s16 *psVar11;
    s32 temp_s2;
    s16 temp_s3;
    u8 bVar2;
    u8 temp_v0_2;
    u8 var_fp;
    u8 var_s5;
    s16 var_s6;
    short unk0 [16];
    short unk20 [16];
    short unk40 [16];
    short unk60 [16];
    short unk80 [16];
    short unkA0 [16];
    short unkC0 [16];
    short unkE0 [16];
    s16 test_1;

    temp_s4 = &PS1_CurrentDisplay->polygons[PS1_PolygonsCount++];
    if (sprite->id != 0)
    {
        var_s5 = sprite->page_x;
        sp140 = sprite->page_y;
        temp_v0_2 = sprite->height;
        bVar2 = sprite->width;
        var_s6 = temp_v0_2 + 1;
        if (D_801E4C20 != 0)
        {
            var_s6 = temp_v0_2;
        }
        var_fp = (var_s5 + bVar2) - 1;
        sp148 = (sp140 + var_s6) - 1;
        sp130 = (param_2 + bVar2) - 1;
        temp_s4->clut = sprite->clut;
        sp138 = (param_3 + var_s6) - 1;
        temp_s4->tpage = sprite->tpage;
        if ((D_801E4C20 == 1) && (D_801CEF78 == -1))
        {
            D_801E4C20 = 1;
            var_s0 = 0;
            do
            {
                temp_v1_1 = rand() * 2;
                test_1 = temp_v1_1;
                D_801CF600[var_s0] = test_1 - ((temp_v1_1 / 4096) * 4096);
                var_s0 += 1;
            } while (var_s0 < 16);
            D_801CEF78 = 0x0096;
        }
        if (D_801E4C20 != 0)
        {
            cur_angle = &(D_801CF600)[angle_ind];
            temp_v1_2 = *cur_angle + 0x51;
            *cur_angle = temp_v1_2 - ((temp_v1_2 / 4096) * 4096);
            if (angle_ind == 0)
            {
                D_801CEF78 = D_801CEF78 - 3;
            }
            psVar11 = &unk0[angle_ind]; /* possibility that maybe it gets all of the unk's as pointers here at the start? */
            temp_s2 = bVar2 >> 1;
            unk80[angle_ind] = (param_2 + temp_s2);
            temp_s3 = var_s6 >> 1;
            unkA0[angle_ind] = (param_3 + (temp_s3));
            unkC0[angle_ind] = (unk80[angle_ind] + (((D_801CEF78 / 2) * rcos(*cur_angle)) >> 0xC));
            temp_lo = (D_801CEF78 / 2) * rsin(*cur_angle);
            temp_s1_2 = D_801CEF78 * 4096;
            unkE0[angle_ind] = (unkA0[angle_ind] + ((temp_lo) >> 0xC));
            *psVar11 = unkC0[angle_ind] - temp_s2;
            unk20[angle_ind] = (unkE0[angle_ind] - temp_s3);
            unk40[angle_ind] = ((bVar2 + *psVar11) - 1);
            unk60[angle_ind] = ((var_s6 + unk20[angle_ind]) - 1);
            temp_s4->x0 = *psVar11;
            temp_s4->y0 = unk20[angle_ind];
            temp_s4->x1 = unk40[angle_ind];
            temp_s4->y1 = unk20[angle_ind];
            temp_s4->x2 = *psVar11;
            temp_s4->y2 = unk60[angle_ind];
            temp_s4->x3 = unk40[angle_ind];
            temp_s4->y3 = unk60[angle_ind];
            temp_s1_3 = (temp_s1_2 / 75) * 2;
            FUN_80139d5c(&temp_s4->x0, &temp_s4->y0, unkC0[angle_ind], unkE0[angle_ind], temp_s1_3);
            FUN_80139d5c(&temp_s4->x1, &temp_s4->y1, unkC0[angle_ind], unkE0[angle_ind], temp_s1_3);
            FUN_80139d5c(&temp_s4->x2, &temp_s4->y2, unkC0[angle_ind], unkE0[angle_ind], temp_s1_3);
            FUN_80139d5c(&temp_s4->x3, &temp_s4->y3, unkC0[angle_ind], unkE0[angle_ind], temp_s1_3);
        }
        if (param_4 != 0)
        {
            if (D_801E4C20 == 0)
            {
                var_s5 -= 1;
            }
            temp_s4->u0 = var_fp;
            temp_s4->v0 = sp140;
            temp_s4->u1 = var_s5;
            temp_s4->v1 = sp140;
            temp_s4->u2 = var_fp;
            temp_s4->v2 = sp148;
            temp_s4->u3 = var_s5;
            temp_s4->v3 = sp148;
        }
        else
        {
            if (D_801E4C20 == 0)
            {
                var_fp += 1;
            }
            temp_s4->u0 = var_s5;
            temp_s4->v0 = sp140;
            temp_s4->u1 = var_fp;
            temp_s4->v1 = sp140;
            temp_s4->u2 = var_s5;
            temp_s4->v2 = sp148;
            temp_s4->u3 = var_fp;
            temp_s4->v3 = sp148;
        }
        
        if (D_801E4C20 != 0)
        {
            if (D_801CEF78 <= 0)
            {
                D_801E4C20 = 0;
                D_801CEF78 = -1;
            }
        }
        else
        {
            sp130 = sp130 + 1;
            temp_s4->x0 = param_2;
            temp_s4->y0 = param_3;
            temp_s4->x1 = sp130;
            temp_s4->y1 = param_3;
            temp_s4->x2 = param_2;
            temp_s4->y2 = sp138;
            temp_s4->x3 = sp130;
            temp_s4->y3 = sp138;
        }
        SetShadeTex(temp_s4, 1);
        SetSemiTrans(temp_s4, 0);
        AddPrim(PS1_PrevPrim, temp_s4);
        PS1_PrevPrim = temp_s4;
    }
}

/* matches, but gross */
/*INCLUDE_ASM("asm/nonmatchings/draw", display_bar_boss);*/

void display_bar_boss(Obj *boss_obj)
{
    u8 hp;
    Obj *poing_obj;
    u8 init_hp;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 display_mode;
    u8 sprite;

    if (scrollLocked)
    {
        hp = boss_obj->hit_points;
        if (hp != 0)
        {
            poing_obj = &level.objects[poing_obj_id];
            init_hp = boss_obj->init_hit_points;
            unk_1 = 6;
            unk_2 = (29 - init_hp) * unk_1;
            unk_3 = 20 - unk_2;
            display_mode = 1;
            display_sprite(poing_obj, 61, unk_3 - (init_hp - hp) * unk_1, 217, display_mode);
            display_sprite(poing_obj, 60, 21 - unk_2, 216, display_mode);
            switch (boss_obj->type)
            {
            case TYPE_MOSKITO:
                sprite = 0x3E;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_MOSKITO2:
                sprite = 0x3E;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_BB1:
                sprite = 0x6A;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_BB12:
                sprite = 0x6A;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_SPACE_MAMA:
                sprite = 0x6C;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_SPACE_MAMA2:
                sprite = 0x6C;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_MAMA_PIRATE:
                sprite = 0x6F;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_SCORPION:
                sprite = 0x6B;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_HYB_BBF2_D:
                sprite = 0x6E;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_HYBRIDE_STOSKO:
                sprite = 0x6E;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_HYBRIDE_MOSAMS:
                sprite = 0x6E;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_DARK:
                sprite = 0x6E;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            case TYPE_SAXO:
            case TYPE_SAXO2:
                sprite = 0x6D;
                display_sprite(poing_obj, sprite, 0, 206, display_mode);
                break;
            }
            
        }
    }
}

/* matches, but ugly and too many unknowns */
/*INCLUDE_ASM("asm/nonmatchings/draw", display_flocons_behind);*/

void display_flocons_behind(void)
{
    DR_ENV *dr_env;
    FloconTableEntry *entry;
    s16 max_ind;
    s16 ind;
    s16 temp_a3;
    s16 temp_t2;
    s16 unk_2;
    s16 j;
    s16 unk_offs;
    s16 temp_lo_1;
    s32 var_a0;
    s32 var_a1;
    s16 var_s7;
    u8 **ot_1;
    s16 old_pcx;
    s16 old_pcy;

    ot_1 = &PS1_CurrentDisplay->ordering_table[1];
    PS1_PrevPrim = ot_1;
    dr_env = &PS1_CurrentDisplay->field4_0x230;
    AddPrim(ot_1, dr_env);
    PS1_PrevPrim = dr_env;

    old_pcx = PROJ_CENTER_X;
    old_pcy = PROJ_CENTER_Y;
    set_proj_center(160, 170);
    
    unk_2 = 6;
    var_s7 = 3;
    unk_offs = 32;
    while (unk_offs < 192) /* 32 - 160 (incl.) in steps of 32 */
    {
        unk_2--;
        temp_lo_1 = 0x10000 / (unk_offs + 0x100);
        var_a0 = temp_lo_1 * PROJ_CENTER_X;
        temp_t2 = PROJ_CENTER_X - (var_a0 / 256);
        var_a1 = temp_lo_1 * PROJ_CENTER_Y;
        temp_a3 = PROJ_CENTER_Y - (var_a1 / 256);

        ind = floc_ind[var_s7];
        entry = &flocon_tab[ind];
        max_ind = ind + nb_floc[var_s7];
        if (num_world != 1)
        {
            if (unk_2 == 5)
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_flocon5_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
            else if (unk_2 == 4)
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_flocon4_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
            else if (unk_2 == 3)
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_flocon3_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
            else if (unk_2 == 2)
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_flocon2_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
            else
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_flocon1_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
        }
        else
        {
            if (unk_2 == 5)
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_pluie6_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
            else if (unk_2 >= 3)
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_pluie5_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
            else
            {
                for (j = ind; j < max_ind; j++)
                {
                    draw_pluie4_Normal(
                        (temp_lo_1 * entry->field0_0x0 >> 8) + temp_t2,
                        (temp_lo_1 * entry->field1_0x2 >> 8) + temp_a3
                    );
                    entry++;
                }
            }
        }
        unk_offs += 32;
        var_s7++;
    }
    PROJ_CENTER_X = old_pcx;
    PROJ_CENTER_Y = old_pcy;
}

/*
matches, but just as ugly
oops, didn't remove unused locals yet
*/
/*INCLUDE_ASM("asm/nonmatchings/draw", display_flocons_before);*/

void display_flocons_before(void)
{
    DR_ENV *dr_env;
    FloconTableEntry *entry;
    s16 temp_a1;
    s16 ind;
    s16 temp_s4;
    s16 temp_s5;
    s16 temp_t1;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 max_ind;
    s16 j;
    s16 var_s1_2;
    s16 var_s1_3;
    s16 var_s6;
    s16 var_s7;
    s16 var_v0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s16 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s32 temp_v0;
    s32 var_a1;
    s32 var_v0_2;
    u16 temp_fp;
    u8 **ot_7;
    s16 old_pcx;
    s16 old_pcy;

    ot_7 = &PS1_CurrentDisplay->ordering_table[7];
    PS1_PrevPrim = ot_7;
    dr_env = &PS1_CurrentDisplay->field3_0x1f0;
    AddPrim(ot_7, dr_env);
    PS1_PrevPrim = dr_env;
    
    old_pcx = PROJ_CENTER_X;
    old_pcy = PROJ_CENTER_Y;
    set_proj_center(160, 170);

    var_s7 = 0;
    var_s6 = -64;
    while (var_s6 < 32)
    {
        ind = floc_ind[var_s7];
        entry = &flocon_tab[ind];
        temp_lo = 0x10000 / (var_s6 + 0x100);
        var_v0_2 = temp_lo * PROJ_CENTER_X;
        temp_t1 = PROJ_CENTER_X - (var_v0_2 / 256);
        var_a1 = temp_lo * PROJ_CENTER_Y;
        temp_a1 = PROJ_CENTER_Y - (var_a1 / 256);
        max_ind = ind + nb_floc[var_s7];
        if (num_world != 1)
        {
            if (var_s7 == 0)
            {
                for (j = ind; j < max_ind; j++)
                {
                    FUN_8013b304(
                        (temp_lo * entry->field0_0x0 >> 8) + temp_t1,
                        (temp_lo * entry->field1_0x2 >> 8) + temp_a1
                    );
                    entry++;
                }
            }
            else
            {
                for (j = ind; j < max_ind; j++)
                {
                    FUN_8013b294(
                        (temp_lo * entry->field0_0x0 >> 8) + temp_t1,
                        (temp_lo * entry->field1_0x2 >> 8) + temp_a1
                    );
                    entry++;
                }
            }
        }
        else
        {
            for (j = ind; j < max_ind; j++)
            {
                FUN_8013b4d4(
                    (temp_lo * entry->field0_0x0 >> 8) + temp_t1,
                    (temp_lo * entry->field1_0x2 >> 8) + temp_a1
                );
                entry++;
            }
        }
        var_s6 += 32;
        var_s7++;
    }
    PROJ_CENTER_X = old_pcx;
    PROJ_CENTER_Y = old_pcy;
}