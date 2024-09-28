#include "obj/hyb_bbf2.h"

/*
tried doing "obj->speed_y =" assignments in place instead of through var_v0_4.
does result in different asm, but can't tell which one is correct
*/
/*INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", doBBF2command);*/

void doBBF2command(Obj *obj)
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
    s32 temp_v1_2;
    s32 temp_v1_4;
    s16 temp_v1_5;
    s16 temp_v1_6;
    s32 var_v0_2;
    s32 var_v0_4;
    s16 var_v1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0_1;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1_3;
    s32 var_v0_3;
    u16 var_a1;
    u16 var_v0_1;
    u8 temp_v1_1;
    u8 temp_v1_7;
    u8 temp_v1_8;
    s16 unk_1;

    if ((obj->main_etat != 0) || (obj->sub_etat != 2))
    {
        temp_v1_1 = obj->type;
        if (temp_v1_1 == 0xE7)
        {
            if (BBF2DEsk == 0)
            {
                unk_1 = 0x5A;
                YPosBBF2D = (NiveauSol - (ray.offset_by - ray.offset_hy)) - ((((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
            }
            else
            {
                if (BBF2DEsk == 0x64)
                {
                    temp_s0 = obj->y_pos + ((obj->offset_by + obj->offset_hy) >> 1);
                    GET_SPRITE_POS(TirBBF2G, 8, &sp18, &sp1A, &sp1C, &sp1E);
                    temp_a0 = sp1A + sp1E;
                    if ((temp_a0 < temp_s0) && (((obj->y_pos + obj->offset_hy) - 0xA) < temp_a0))
                    {
                        YPosBBF2D = YPosBBF2D + 0x32;
                    }
                    else if ((temp_s0 < sp1A) && (sp1A < (obj->y_pos + obj->offset_by + 0xA)))
                    {
                        YPosBBF2D = YPosBBF2D - 0x32;
                    }
                    else
                    {
                        temp_a1 = obj->y_pos;
                        if ((((temp_a1 + obj->offset_hy) - 0xA) < sp1A) && ((sp1A + sp1E) < (temp_a1 + obj->offset_by + 0xA)))
                        {
                            YPosBBF2D = YPosBBF2D - 0x50;
                        }
                        else
                        {
                            unk_1 = 0x5A;
                            YPosBBF2D = (NiveauSol - (ray.offset_by - ray.offset_hy)) - ((((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
                        }
                    }
                }
                BBF2DEsk--;
            }
            var_a1 = (YPosBBF2D - 0x96) - obj->y_pos;
        }
        else if (temp_v1_1 == 0xE8)
        {
            if (BBF2GEsk == 0)
            {
                unk_1 = 0x46;
                YPosBBF2G = (NiveauSol - (ray.offset_by - ray.offset_hy)) + ((((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
            }
            else
            {
                if (BBF2GEsk == 0x64)
                {
                    temp_s0_2 = obj->y_pos + ((obj->offset_by + obj->offset_hy) >> 1);
                    GET_SPRITE_POS(TirBBF2D, 8, &sp18, &sp1A, &sp1C, &sp1E);
                    temp_a0_2 = sp1A + sp1E;
                    if ((temp_a0_2 < temp_s0_2) && (((obj->y_pos + obj->offset_hy) - 0xA) < temp_a0_2))
                    {
                        YPosBBF2G = YPosBBF2G + 0x32;
                    }
                    else if ((temp_s0_2 < sp1A) && (sp1A < (obj->y_pos + obj->offset_by + 0xA)))
                    {
                        YPosBBF2G = YPosBBF2G - 0x32;
                    }
                    else
                    {
                        temp_a1_2 = obj->y_pos;
                        if ((((temp_a1_2 + obj->offset_hy) - 0xA) < sp1A) && ((sp1A + sp1E) < (temp_a1_2 + obj->offset_by + 0xA)))
                        {
                            YPosBBF2G = YPosBBF2G - 0x50;
                        }
                        else
                        {
                            unk_1 = 0x46;
                            YPosBBF2G = (NiveauSol - (ray.offset_by - ray.offset_hy)) + ((((ray.x_pos + ray.offset_bx) - xmap) >> 1) - unk_1);
                        }
                    }
                }
                BBF2GEsk--;
            }
            var_a1 = (YPosBBF2G - 0x96) - obj->y_pos;
        }

        temp_v1_2 = obj->y_pos;
        if (((ymap + 0x5A) >= temp_v1_2) || ((var_a1 << 0x10) <= 0))
        {
            if (temp_v1_2 < (ymap - 0x96))
            {
                if ((s16) var_a1 < 0)
                {
                    var_a1 = 0;
                    obj->speed_y = 0;
                }
            }
        }
        else
        {
            var_a1 = 0;
            obj->speed_y = 0;            
        }
        var_v1 = (s16) var_a1;
        
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
                if (var_v0_2 >= 0x31)
                {
                    goto block_55;
                }
                else
                    goto block_48;
                
            }
            if ((var_v0_2 - 1) < 0x31)
            {
block_48:
                temp_v1_4 = obj->speed_y;
                temp_v0_1 = (s16) var_a1 - temp_v1_4;
                if (temp_v0_1 >= 0)
                {
                    if (temp_v0_1 > 0)
                    {
                        if ((temp_v1_4 + 1) < -0x30)
                        {
                            var_v0_4 = -0x0030;
                        }
                        else
                        {
                            goto block_55;
                        }
                    }
                    else
                    {
                        var_v0_4 = -0x0030;
                        if (temp_v1_4 >= -0x30)
                            goto block_55;
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
                temp_v1_4 = obj->speed_y;
                temp_v0_1 = ((s16) var_a1) - temp_v1_4;
                if (temp_v0_1 >= 0)
                {
                    if (temp_v0_1 > 0)
                    {
                        var_v0_4 = 0x0030;
                        if ((temp_v1_4 + 1) < 0x31)
                            goto block_63;
                    }
                    else
                    {
                        var_v0_4 = 0x0030;
                        if (temp_v1_4 < 0x31)
                            goto block_63;
                    }
                }
                else
                {
                    var_v0_4 = 0x0030;
                    if ((temp_v1_4 - 1) < 0x31)
                    {
block_63:
                        /* like sgn in scorpion.c ? */
                        temp_v1_5 = obj->speed_y;
                        temp_v0_1 = (s16) var_a1 - temp_v1_5;
                        if (temp_v0_1 >= 0)
                        {
                            var_v0_4 = temp_v1_5 + (temp_v0_1 > 0);
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
    temp_a0_3 = sp20 + 0xF;
    sp20 = temp_a0_3;
    temp_v1_6 = obj->y_pos + 0x96;
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
