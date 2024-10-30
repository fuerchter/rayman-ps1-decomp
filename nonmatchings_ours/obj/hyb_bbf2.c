#include "obj/hyb_bbf2.h"

/*
matches, but
duplication?
var_v1?
*/
/*INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", doBBF2command);*/

void doBBF2command(Obj *bbf2_obj)
{
    s16 spr_x; s16 spr_y_1; s16 spr_w; s16 spr_h;
    s16 spr_y_2;
    s16 bbf2_y_1;
    s32 bbf2_y_2;
    s16 bbf2_y_3;
    s16 var_v1;
    u16 unk_2;
    s16 unk_1;

    if (!(bbf2_obj->main_etat == 0 && bbf2_obj->sub_etat == 2))
    {
        if (bbf2_obj->type == TYPE_HYB_BBF2_D)
        {
            if (BBF2DEsk == 0)
            {
                unk_1 = 0x5A;
                YPosBBF2D =
                    NiveauSol - (ray.offset_by - ray.offset_hy) -
                    (((ray.x_pos + ray.offset_bx - xmap) >> 1) - unk_1);
            }
            else
            {
                if (BBF2DEsk == 100)
                {
                    bbf2_y_1 = bbf2_obj->y_pos + ((bbf2_obj->offset_by + bbf2_obj->offset_hy) >> 1);
                    GET_SPRITE_POS(TirBBF2G, 8, &spr_x, &spr_y_1, &spr_w, &spr_h);
                    if (
                        (spr_y_1 + spr_h) < bbf2_y_1 &&
                        ((spr_y_1 + spr_h) > bbf2_obj->y_pos + bbf2_obj->offset_hy - 0xA)
                    )
                        YPosBBF2D += 50;
                    else if (
                        spr_y_1 > bbf2_y_1 &&
                        (spr_y_1 < (bbf2_obj->y_pos + bbf2_obj->offset_by + 0xA))
                    )
                        YPosBBF2D -= 50;
                    else if (
                        (spr_y_1 > ((bbf2_obj->y_pos + bbf2_obj->offset_hy) - 0xA)) &&
                        ((spr_y_1 + spr_h) < (bbf2_obj->y_pos + bbf2_obj->offset_by + 0xA))
                    )
                        YPosBBF2D -= 80;
                    else
                    {
                        unk_1 = 0x5A;
                        YPosBBF2D =
                            NiveauSol - (ray.offset_by - ray.offset_hy) -
                            (((ray.x_pos + ray.offset_bx - xmap) >> 1) - unk_1);
                    }
                }
                BBF2DEsk--;
            }
            unk_2 = YPosBBF2D - 150 - bbf2_obj->y_pos;
        }
        else if (bbf2_obj->type == TYPE_HYB_BBF2_G)
        {
            if (BBF2GEsk == 0)
            {
                unk_1 = 0x46;
                YPosBBF2G =
                    NiveauSol - (ray.offset_by - ray.offset_hy) +
                    (((ray.x_pos + ray.offset_bx - xmap) >> 1) - unk_1);
            }
            else
            {
                if (BBF2GEsk == 100)
                {
                    bbf2_y_1 = bbf2_obj->y_pos + ((bbf2_obj->offset_by + bbf2_obj->offset_hy) >> 1);
                    GET_SPRITE_POS(TirBBF2D, 8, &spr_x, &spr_y_1, &spr_w, &spr_h);
                    if (
                        ((spr_y_1 + spr_h) < bbf2_y_1) &&
                        ((spr_y_1 + spr_h) > ((bbf2_obj->y_pos + bbf2_obj->offset_hy) - 0xA))
                    )
                        YPosBBF2G += 50;
                    else if (
                        (spr_y_1 > bbf2_y_1) &&
                        (spr_y_1 < (bbf2_obj->y_pos + bbf2_obj->offset_by + 0xA))
                    )
                        YPosBBF2G -= 50;
                    else if (
                        (spr_y_1 > ((bbf2_obj->y_pos + bbf2_obj->offset_hy) - 0xA)) &&
                        ((spr_y_1 + spr_h) < (bbf2_obj->y_pos + bbf2_obj->offset_by + 0xA)))
                    {
                        YPosBBF2G -= 80;
                    }
                    else
                    {
                        unk_1 = 0x46;
                        YPosBBF2G =
                            NiveauSol - (ray.offset_by - ray.offset_hy) +
                            (((ray.x_pos + ray.offset_bx - xmap) >> 1) - unk_1);
                    }
                }
                BBF2GEsk--;
            }
            unk_2 = YPosBBF2G - 150 - bbf2_obj->y_pos;
        }

        bbf2_y_2 = bbf2_obj->y_pos;
        if (
            ((bbf2_y_2 > ymap + 90) && (s16) unk_2 > 0) ||
            ((bbf2_y_2 < ymap - 150) && (s16) unk_2 < 0)
        )
        {
            unk_2 = 0;
            bbf2_obj->speed_y = 0;
        }

        var_v1 = (s16) unk_2; /* TODO: ??? */
        if (var_v1 != 0)
        {
            bbf2_obj->speed_y = MAX_1(-48, MIN_1(48,
                SGN(((s16) unk_2) - bbf2_obj->speed_y) + bbf2_obj->speed_y));
        }
    }
    GET_SPRITE_POS(&ray, 5, &spr_x, &spr_y_2, &spr_w, &spr_h);
    spr_y_2 += 15;
    bbf2_y_3 = bbf2_obj->y_pos + 150;
    if (
        bbf2_obj->sub_etat == 0 &&
        (spr_y_2 > bbf2_y_3 - 15) && (spr_y_2 < bbf2_y_3 + 15)
    )
        set_sub_etat(bbf2_obj, 5);
    else if (
        (bbf2_obj->sub_etat == 6 || bbf2_obj->sub_etat == 4) &&
        ((spr_y_2 < bbf2_y_3 - 20) || (spr_y_2 > bbf2_y_3 + 20))
    )
        set_sub_etat(bbf2_obj, 7);
    else if (
        (bbf2_obj->sub_etat == 5 || bbf2_obj->sub_etat == 6) &&
        (spr_y_2 > bbf2_y_3 - 7) && (spr_y_2 < bbf2_y_3 + 7)
    )
        set_sub_etat(bbf2_obj, 3);
    else if (bbf2_obj->sub_etat == 3 && bbf2_obj->anim_frame == 3)
    {
        AllocateTirBBF2(bbf2_obj);
        if (bbf2_obj->type == TYPE_HYB_BBF2_D)
            BBF2GEsk = 100;
        else
            BBF2DEsk = 100;
    }
}
