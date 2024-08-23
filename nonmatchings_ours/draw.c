#include "draw.h"

/*INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawColoredSprite);*/

void PS1_DrawColoredSprite(Sprite *sprite, s16 x, s16 y, u8 display_mode)
{
    POLY_FT4 *var_s0;
    s16 temp_a0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v1_1;
    s16 temp_v1_3;
    s16 width;
    s16 page_x;
    s16 page_y;
    s16 page_x_end;
    s16 page_y_end;
    s16 height;
    Display *new_var;
    POLY_FT4 *new_var2;

    temp_v1_1 = PS1_PolygonsCount;
    if (temp_v1_1 < 0xC8)
    {
        PS1_PolygonsCount = temp_v1_1 + 1;
        new_var = PS1_CurrentDisplay;
        var_s0 = &new_var->polygons[temp_v1_1];
    }
    else
    {
        new_var = PS1_CurrentDisplay;
        if (new_var != &PS1_Display1)
        {
            var_s0 = &(((POLY_FT4*)0x800E3F2C)[temp_v1_1]);
        }
        else
        {
            var_s0 = &(((POLY_FT4*)0x800D772C)[temp_v1_1]);
        }
        SetPolyFT4(var_s0);
        PS1_PolygonsCount = PS1_PolygonsCount + 1;
    }
    
    if (sprite->id != 0)
    {
        page_x = sprite->page_x;
        page_y = sprite->page_y;
        width = sprite->width;
        height = sprite->height;
        page_x_end = page_x + width;
        page_y_end = page_y + height;
        temp_v0_3 = x + width;
        temp_v0_4 = y + height;
        temp_v1_3 = x + height;
        temp_a0_2 = y + width;
        var_s0->clut = sprite->clut;
        var_s0->tpage = sprite->tpage;
        switch (display_mode)
        {
        case 1:
            page_x = page_x - 1;
            page_x_end = page_x_end - 1;
            var_s0->u0 = page_x_end;
            var_s0->v0 = page_y;
            var_s0->u1 = page_x;
            var_s0->v1 = page_y;
            var_s0->u2 = page_x_end;
            var_s0->v2 = page_y_end;
            var_s0->u3 = page_x;
            var_s0->v3 = page_y_end;
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
            page_y = page_y - 1;
            page_y_end = page_y_end - 1;
            var_s0->u0 = page_x;
            var_s0->v0 = page_y_end;
            var_s0->u1 = page_x_end;
            var_s0->v1 = page_y_end;
            var_s0->u2 = page_x;
            var_s0->v2 = page_y;
            var_s0->u3 = page_x_end;
            var_s0->v3 = page_y;
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
            page_x = page_x - 1;
            page_x_end = page_x_end - 1;
            page_y = page_y - 1;
            page_y_end = page_y_end - 1;
            var_s0->u0 = page_x_end;
            var_s0->v0 = page_y_end;
            var_s0->u1 = page_x;
            var_s0->v1 = page_y_end;
            var_s0->u2 = page_x_end;
            var_s0->v2 = page_y;
            var_s0->u3 = page_x;
            var_s0->v3 = page_y;
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
            page_x = page_x - 1;
            page_x_end = page_x_end - 1;
            var_s0->u0 = page_x_end;
            var_s0->v0 = page_y;
            var_s0->u1 = page_x_end;
            var_s0->v1 = page_y_end;
            var_s0->u2 = page_x;
            var_s0->v2 = page_y;
            var_s0->u3 = page_x;
            var_s0->v3 = page_y_end;
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
            page_y = page_y - 1;
            page_y_end = page_y_end - 1;
            var_s0->u0 = page_x;
            var_s0->v0 = page_y_end;
            var_s0->u1 = page_x;
            var_s0->v1 = page_y;
            var_s0->u2 = page_x_end;
            var_s0->v2 = page_y_end;
            var_s0->u3 = page_x_end;
            var_s0->v3 = page_y;
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
            var_s0->u0 = page_x;
            var_s0->v0 = page_y;
            var_s0->u1 = page_x;
            var_s0->v1 = page_y_end;
            var_s0->u2 = page_x_end;
            var_s0->v2 = page_y;
            var_s0->u3 = page_x_end;
            var_s0->v3 = page_y_end;
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
            page_x = page_x - 1;
            page_x_end = page_x_end - 1;
            page_y = page_y - 1;
            page_y_end = page_y_end - 1;
            var_s0->u0 = page_x_end;
            var_s0->v0 = page_y_end;
            var_s0->u1 = page_x_end;
            var_s0->v1 = page_y;
            var_s0->u2 = page_x;
            var_s0->v2 = page_y_end;
            var_s0->u3 = page_x;
            var_s0->v3 = page_y;
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
            var_s0->u0 = page_x;
            var_s0->v0 = page_y;
            var_s0->u1 = page_x_end;
            var_s0->v1 = page_y;
            var_s0->u2 = page_x;
            var_s0->v2 = page_y_end;
            var_s0->u3 = page_x_end;
            var_s0->v3 = page_y_end;
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

/* matches, but didn't feel like cleaning up */
/*INCLUDE_ASM("asm/nonmatchings/draw", display_pix_gerbes);*/

void display_pix_gerbes(void)
{
    TILE_1 *var_s3;
    s16 var_s5;
    s16 var_s7;
    s32 temp_v1_1;
    u8 var_v0_3;
    PixGerbeItem *var_s2;
    s16 temp_v0_2;
    u8 temp_v1_2;

    var_s3 = &PS1_CurrentDisplay->tile1s[(u16) D_801FA690];
    for (var_s7 = 0; var_s7 < (s16) LEN(pix_gerbe); var_s7++)
    {
        temp_v1_1 = var_s7;
        if (pix_gerbe[temp_v1_1].is_active)
        {
            var_s2 = pix_gerbe[temp_v1_1].items;
            var_s5 = 0;
            while (var_s5 < (s16) LEN(pix_gerbe[temp_v1_1].items))
            {
                temp_v1_2 = var_s2->unk_1;
                if (temp_v1_2 >= 0x80 && (var_s2->y_pos > 0))
                {
                    temp_v0_2 = (u8) var_s2->speed_y;
                    if (temp_v0_2 >= 0x80)
                    {
                        var_v0_3 = 0x58;
                    }
                    else
                    {
                        var_v0_3 = (temp_v1_2 & 0x7F) + ((temp_v0_2 >> 5) + 4);
                    }

                    switch (var_v0_3)
                    {
                        case 4:
                            var_s3->r0 = 0x7b;
                            var_s3->g0 = 0x87;
                            var_s3->b0 = 0xbb;
                            break;
                        case 5:
                            var_s3->r0 = 0x97;
                            var_s3->g0 = 0x9f;
                            var_s3->b0 = 0xdb;
                            break;
                        case 6:
                            var_s3->r0 = 0xbb;
                            var_s3->g0 = 0xbb;
                            var_s3->b0 = 0xfb;
                            break;
                        case 7:
                            var_s3->r0 = 0xc7;
                            var_s3->g0 = 0xd5;
                            var_s3->b0 = 0xfb;
                            break;
                        case 0x58:
                            var_s3->r0 = 0xff;
                            var_s3->g0 = 0xbf;
                            var_s3->b0 = 0xa7;
                            break;
                        default:
                            var_s3->r0 = 0xbb;
                            var_s3->g0 = 0xbb;
                            var_s3->b0 = 0xfb;
                            break;
                    }
                    var_s3->x0 = var_s2->x_pos >> 6;
                    var_s3->y0 = var_s2->y_pos >> 6;
                    if (D_801FA690 < 0xF0U)
                    {
                        AddPrim(PS1_PrevPrim, var_s3);
                        var_s3++;
                        D_801FA690++;
                    }
                }
                var_s2++;
                var_s5++;
            }
        }
    }
}

/*INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_ALL_OBJECTS);*/

void DISPLAY_ALL_OBJECTS(void)

{
  short sVar1;
  Display *pDVar2;
  Display *pDVar3;
  s16 uVar4;
  u_short uVar5;
  s16 iVar6;
  ObjType OVar7;
  uint uVar8;
  short var_s1;
  Obj *obj;
  s16 iVar10;
  s16 prio;
  Obj *new_var;
  s16 test_1;
  s16 *test_2;
  ActiveObjects *new_var2;
  
  PS1_BossObj = null;
  prio = 7;
  PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[6];
  do {
    var_s1 = 0;
    obj = &level.objects[actobj.objects[0]];
    while (var_s1 < actobj.num_active_objects) {
        if (prio == 1 && (flags[obj->type].flags0 >> OBJ0_BOSS & 1)) {
            PS1_BossObj = obj;
        }
        if (obj->display_prio == prio) {
            if (num_world == 5 && num_level == 4 && obj->type == TYPE_MEDAILLON_TOON) {
                PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[10];
                display2(obj);
                PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[6];
            }
            else
            {
                if (obj->type == TYPE_EAU && num_world == 5 && num_level == 8) {
                    PS1_DrawSpriteSemiTrans = 1;
                    if (300 <= obj->x_pos) {
                        display2(obj);
                    }
                    PS1_DrawSpriteSemiTrans = 0;
                }
                else {
                    OVar7 = obj->type;
                    if (OVar7 == TYPE_CYMBALE) {
                        DISPLAY_CYMBALE(obj,true);
                    }
                    else if (((((OVar7 != TYPE_NEIGE) && (OVar7 != TYPE_PALETTE_SWAPPER)) &&
                            ((OVar7 != TYPE_GENERATING_DOOR &&
                            ((OVar7 != TYPE_MST_SCROLL || (obj->hit_points == 0)))))) &&
                            (OVar7 != TYPE_SCROLL_SAX)) && (OVar7 != TYPE_BB1_VIT)) {
                        if (OVar7 == TYPE_LAVE) {
                            if (D_801E4DF8 != D_801CEF7A) {
                                SetPolyG4(&PS1_CurrentDisplay->field5325_0x6094);
                                SetSemiTrans(&PS1_CurrentDisplay->field5325_0x6094,1);
                                SetShadeTex(&PS1_CurrentDisplay->field5325_0x6094,1);
                                pDVar2 = PS1_CurrentDisplay;
                                (PS1_CurrentDisplay->field5325_0x6094).x0 = 0;
                                sVar1 = obj->screen_y_pos;
                                (pDVar2->field5325_0x6094).x1 = 0x140;
                                (pDVar2->field5325_0x6094).y0 = sVar1 + 0x19;
                                sVar1 = obj->screen_y_pos;
                                (pDVar2->field5325_0x6094).x2 = 0;
                                (pDVar2->field5325_0x6094).y1 = sVar1 + 0x19;
                                sVar1 = obj->screen_y_pos;
                                (pDVar2->field5325_0x6094).x3 = 0x140;
                                (pDVar2->field5325_0x6094).y2 = sVar1 + 0x5a;
                                sVar1 = obj->screen_y_pos;
                                (pDVar2->field5325_0x6094).r0 = 0;
                                pDVar3 = PS1_CurrentDisplay;
                                (pDVar2->field5325_0x6094).y3 = sVar1 + 0x5a;
                                (pDVar3->field5325_0x6094).g0 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).b0 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).r1 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).g1 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).b1 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).r2 = 0xad;
                                (PS1_CurrentDisplay->field5325_0x6094).g2 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).b2 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).r3 = 0xb0;
                                (PS1_CurrentDisplay->field5325_0x6094).g3 = 0;
                                (PS1_CurrentDisplay->field5325_0x6094).b3 = 0;
                                AddPrim(PS1_CurrentDisplay->ordering_table + 9,&PS1_CurrentDisplay->field5325_0x6094
                                    );
                                (PS1_CurrentDisplay->drawing_environment).tpage = GetTPage(1,1,0x100,0);
                                pDVar2 = PS1_CurrentDisplay;
                                
                                SetDrawEnv(
                                    &pDVar2->map_drawing_environment_primitives[(u16) D_801E4BE0],
                                    &pDVar2->drawing_environment
                                );
                                AddPrim(
                                    &PS1_CurrentDisplay->ordering_table[9],
                                    &PS1_CurrentDisplay->map_drawing_environment_primitives[(u16) D_801E4BE0]
                                );
                                D_801E4BE0 = D_801E4BE0 + 1;
                                D_801CEF7A = D_801E4DF8;
                            }
                            PS1_DrawSpriteSemiTrans = 0;
                            display2(obj);
                        }
                        else
                        {
                            PS1_DrawSpriteSemiTrans = 0;
                            display2(obj);
                            PS1_DrawSpriteSemiTrans = 0;
                        }
                    }
                }
            }
        }
        var_s1 = var_s1 + 1;
        obj = level.objects + actobj.objects[var_s1];
    }
    if (prio == 3) {
      if (((u8) ray.iframes_timer & 1 || (0x5a < ray.iframes_timer)) &&
         ((ray.flags & (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE))) == (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE)))) {
        display2(&ray);
      }
      DISPLAY_POING();
    }
    else if (prio == 2 && nb_cymbal_in_map != 0 && nb_cymbal_in_map != 0) {
      for (iVar6 = 0; iVar6 < nb_cymbal_in_map; iVar6++)
      {
        if (level.objects[cymbal_obj_id[iVar6]].flags & FLG(OBJ_ACTIVE))
          DISPLAY_CYMBALE(&level.objects[cymbal_obj_id[iVar6]], false);
      }
    }
    prio = prio + -1;
    if (prio < 1) {
        iVar10 = 0;
        new_var2 = &actobj;
        test_2 = &actobj.objects[iVar10];
        obj = level.objects + *test_2;
        while (iVar10 < new_var2->num_active_objects) {
            iVar10 = iVar10 + 1;
            if (obj->display_prio == 0 && (obj->type == TYPE_DUNE)) {
                display2(obj);
                PS1_DrawSpriteSemiTrans = 0;
                return;
            }
            test_2 = &actobj.objects[iVar10];
            obj = level.objects + *test_2;
        }
        PS1_DrawSpriteSemiTrans = 0;
        return;
    }
  } while( true );
}