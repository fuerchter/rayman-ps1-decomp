#include "obj/hyb_bbf2.h"

/* starting with gotos-only would only be ~40 score better */
/*INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", doBBF2command);*/

void doBBF2command(Obj *obj, u16 param_2)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 sp20;
    s16 temp_a0_3;
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_v1_2;
    s16 temp_v1_4;
    s16 temp_v1_5;
    s16 temp_v1_6;
    s16 var_v0_2;
    s16 var_v0_4;
    s16 var_v1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1_3;
    s32 var_v0_3;
    u16 var_a1;
    u16 var_v0_1;
    u8 temp_v1;
    u8 temp_v1_7;
    u8 temp_v1_8;
    s16 unk_1;

    var_a1 = param_2;
    if ((obj->main_etat != 0) || (obj->sub_etat != 2))
    {
        temp_v1 = obj->type;
        if (temp_v1 == 0xE7)
        {
            if (BBF2DEsk == 0)
            {
                unk_1 = 0x5A;
                YPosBBF2D = ((u16) NiveauSol - (ray.offset_by - ray.offset_hy)) - (((s32) ((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
            }
            else
            {
                if (BBF2DEsk == 0x64)
                {
                    temp_s0 = (u16) obj->y_pos + ((s32) (obj->offset_by + obj->offset_hy) >> 1);
                    GET_SPRITE_POS(TirBBF2G, 8, &sp18, &sp1A, &sp1C, &sp1E);
                    temp_a0 = sp1A + sp1E;
                    if ((temp_a0 < temp_s0) && (((obj->y_pos + obj->offset_hy) - 0xA) < temp_a0))
                    {
                        YPosBBF2D = (u16) YPosBBF2D + 0x32;
                    }
                    else if ((temp_s0 < sp1A) && (sp1A < (obj->y_pos + obj->offset_by + 0xA)))
                    {
                        YPosBBF2D = (u16) YPosBBF2D - 0x32;
                    }
                    else
                    {
                        temp_a1 = obj->y_pos;
                        if ((((temp_a1 + obj->offset_hy) - 0xA) < sp1A) && ((sp1A + sp1E) < (temp_a1 + obj->offset_by + 0xA)))
                        {
                            YPosBBF2D = (u16) YPosBBF2D - 0x50;
                        }
                        else
                        {
                            unk_1 = 0x5A;
                            YPosBBF2D = ((u16) NiveauSol - (ray.offset_by - ray.offset_hy)) - (((s32) ((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
                        }
                    }
                }
                BBF2DEsk--;
            }
            var_a1 = (YPosBBF2D - 0x96) - (u16) obj->y_pos;
        }
        else if (temp_v1 == 0xE8)
        {
            if (BBF2GEsk == 0)
            {
                unk_1 = 0x46;
                YPosBBF2G = ((u16) NiveauSol - (ray.offset_by - ray.offset_hy)) + (((s32) ((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
            }
            else
            {
                if (BBF2GEsk == 0x64)
                {
                    temp_s0_2 = (u16) obj->y_pos + ((s32) (obj->offset_by + obj->offset_hy) >> 1);
                    GET_SPRITE_POS(TirBBF2D, 8, &sp18, &sp1A, &sp1C, &sp1E);
                    temp_a0_2 = sp1A + sp1E;
                    if ((temp_a0_2 < temp_s0_2) && (((obj->y_pos + obj->offset_hy) - 0xA) < temp_a0_2))
                    {
                        YPosBBF2G = (u16) YPosBBF2G + 0x32;
                    }
                    else if ((temp_s0_2 < sp1A) && (sp1A < (obj->y_pos + obj->offset_by + 0xA)))
                    {
                        YPosBBF2G = (u16) YPosBBF2G - 0x32;
                    }
                    else
                    {
                        temp_a1_2 = obj->y_pos;
                        if ((((temp_a1_2 + obj->offset_hy) - 0xA) < sp1A) && ((sp1A + sp1E) < (temp_a1_2 + obj->offset_by + 0xA)))
                        {
                            YPosBBF2G = (u16) YPosBBF2G - 0x50;
                        }
                        else
                        {
                            unk_1 = 0x46;
                            YPosBBF2G = ((u16) NiveauSol - (ray.offset_by - ray.offset_hy)) + (((s32) ((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
                        }
                    }
                }
                BBF2GEsk--;
            }
            var_a1 = (YPosBBF2G - 0x96) - (u16) obj->y_pos;
        }

        temp_v1_2 = obj->y_pos;
        if (((ymap + 0x5A) >= temp_v1_2) || ((var_a1 << 0x10) <= 0))
        {
            if (temp_v1_2 < (ymap - 0x96))
            {
                var_v1 = (s16) var_a1;
                if (var_a1 & 0x8000)
                {
                    goto block_39;
                }
            }
            else
            {
                goto block_40;
            }
        }
        else
        {
block_39:
            var_a1 = 0;
            obj->speed_y = 0;
block_40:
            var_v1 = (s16) var_a1;
        }
        
        if (var_v1 != 0)
        {
            var_v0_2 = obj->speed_y;
            temp_v1_3 = var_v1 - var_v0_2;
            if (temp_v1_3 >= 0)
            {
                if (temp_v1_3 > 0)
                {
                    var_v0_2 += 1;
                }
                if (var_v0_2 < 0x31)
                {
                    goto block_48;
                }
                goto block_55;
            }
            if ((var_v0_2 - 1) < 0x31)
            {
block_48:
                temp_v1_4 = obj->speed_y;
                temp_v0 = (s16) var_a1 - temp_v1_4;
                if (temp_v0 >= 0)
                {
                    if (temp_v0 > 0)
                    {
                        var_v0_3 = var_a1 << 0x10;
                        if ((temp_v1_4 + 1) < -0x30)
                        {
                            var_v0_4 = -0x0030;
                        }
                        else
                        {
                            goto block_56;
                        }
                    }
                    else
                    {
                        var_v0_4 = -0x0030;
                        if (temp_v1_4 < -0x30)
                        {

                        }
                        else
                        {
                            goto block_55;
                        }
                    }
                }
                else
                {
                    var_v0_4 = -0x0030;
                    if ((temp_v1_4 - 1) >= -0x30)
                    {
                        goto block_55;
                    }
                }
            }
            else
            {
block_55:
                var_v0_3 = var_a1 << 0x10;
block_56:
                temp_v0_2 = (var_v0_3 >> 0x10) - obj->speed_y;
                if (temp_v0_2 >= 0)
                {
                    if (temp_v0_2 > 0)
                    {
                        var_v0_4 = 0x0030;
                        if ((obj->speed_y + 1) >= 0x31)
                        {

                        }
                        else
                        {
                            goto block_63;
                        }
                    }
                    else
                    {
                        var_v0_4 = 0x0030;
                        if (obj->speed_y >= 0x31)
                        {

                        }
                        else
                        {
                            goto block_63;
                        }
                    }
                }
                else
                {
                    var_v0_4 = 0x0030;
                    if ((obj->speed_y - 1) < 0x31)
                    {
block_63:
                        /* like sgn in scorpion.c ? */
                        temp_v1_5 = obj->speed_y;
                        temp_v0_3 = (s16) var_a1 - temp_v1_5;
                        if (temp_v0_3 >= 0)
                        {
                            var_v0_4 = temp_v1_5 + (temp_v0_3 > 0);
                        }
                        else
                        {
                            var_v0_4 = temp_v1_5 - 1;
                        }
                    }
                }
            }
            obj->speed_y = var_v0_4;
        }
    }
    GET_SPRITE_POS(&ray, 5, &sp18, &sp20, &sp1C, &sp1E);
    temp_a0_3 = (u16) sp20 + 0xF;
    sp20 = temp_a0_3;
    temp_v1_6 = (u16) obj->y_pos + 0x96;
    if ((obj->sub_etat == 0) && (temp_a0_3 > (temp_v1_6 - 0xF)) && (temp_a0_3 < (temp_v1_6 + 0xF)))
    {
        set_sub_etat(obj, 5U);
        return;
    }
    temp_v1_7 = obj->sub_etat;
    if (((temp_v1_7 == 6) || (temp_v1_7 == 4)) && ((sp20 < (temp_v1_6 - 0x14)) || ((temp_v1_6 + 0x14) < sp20)))
    {
        set_sub_etat(obj, 7U);
        return;
    }
    if (((u32) (obj->sub_etat - 5) < 2U) && ((temp_v1_6 - 7) < sp20) && (sp20 < (temp_v1_6 + 7)))
    {
        set_sub_etat(obj, 3U);
        return;
    }
    temp_v1_8 = obj->sub_etat;
    if ((temp_v1_8 == 3) && (obj->anim_frame == temp_v1_8))
    {
        AllocateTirBBF2(obj);
        if (obj->type == 0xE7)
        {
            BBF2GEsk = 0x64;
            return;
        }
        BBF2DEsk = 0x64;
    }
}

/* looks like it should be correct but somehow isn't */
/*INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", DO_HYB_BBF2_LAS);*/

void DO_HYB_BBF2_LAS(Obj *las_obj)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 sp20;
    s16 sp22;
    s16 sp24;
    s16 sp26;
    Obj *unk_obj;
    s16 unk_1;
    s16 i;
    Obj *cur_obj_1;
    s16 nb_objs;

    unk_1 = las_obj->field24_0x3e;
    if (level.objects[unk_1].type == 0xe7 || level.objects[unk_1].type == 0xe8)
    {
        unk_obj = &level.objects[unk_1];
        if ((OBJ_IN_COL_ZDC(las_obj, unk_obj) << 0x10) != 0)
        {
            cur_obj_1 = &level.objects[0];
            i = 0;
            nb_objs = level.nb_objects;
            while (i < nb_objs)
            {
                if ((cur_obj_1->type == 0x0B) && !(cur_obj_1->flags & 0x800))
                {
                    GET_ANIM_POS(las_obj, &sp18, &sp1A, &sp1C, &sp1E);
                    GET_ANIM_POS(cur_obj_1, &sp20, &sp22, &sp24, &sp26);
                    cur_obj_1->anim_frame = 0;
                    cur_obj_1->x_pos = sp18 - cur_obj_1->offset_bx;
                    if (las_obj->speed_x > 0)
                    {
                        cur_obj_1->x_pos += sp1C;
                    }
                    cur_obj_1->y_pos = ((sp1A + (sp1E >> 0x1)) - ((cur_obj_1->offset_by + cur_obj_1->offset_hy) >> 1));
                    calc_obj_pos(cur_obj_1);
                    cur_obj_1->flags |= 0xC00;
                    break;
                }
                cur_obj_1 += 1;
                i = i + 1;
            }
            DO_HYB_BBF2_POING_COLLISION(unk_obj);
            las_obj->flags &= ~0x400;
            las_obj->flags &= ~0x800;
        }
    }
    
    if (las_obj->speed_y == 0)
    {
        i = 0;
        cur_obj_1 = &level.objects[actobj.objects[i]];
        while (i < actobj.num_active_objects)
        {
            if ((cur_obj_1->type == 0xE9) && (cur_obj_1->id != las_obj->id) && (OBJ_IN_COL_ZDC(las_obj, cur_obj_1) << 0x10))
            {
                cur_obj_1->speed_x = 0;
                las_obj->speed_x = 0;
                cur_obj_1->speed_y = 3;
                las_obj->speed_y = 3;
                las_obj->field24_0x3e = cur_obj_1->id;
                cur_obj_1->field24_0x3e = las_obj->id;
                break;
            }
            i = i + 1;
            cur_obj_1 = &level.objects[actobj.objects[i]];
        }
    }
}