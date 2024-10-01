#include "obj/mite.h"

/* 4A85C 8016F05C -O2 -msoft-float */
void mite_esquive_poing(Obj *mit_obj, s16 *out_x)
{
    s16 unk_x_1; s16 unk_y_1;
    s16 unk_y_2;    
    Obj *poing_obj = &level.objects[poing_obj_id];
    
    if (!(poing_obj->flags & FLG(OBJ_ACTIVE)))
    {
        unk_x_1 = ray.x_pos + ray.offset_bx;
        unk_y_1 = ray.y_pos + ((ray.offset_by + ray.offset_hy) >> 1) - 10;
        poing_obj->speed_x = 0;
        poing_obj->speed_y = 0;
    }
    else
    {
        unk_x_1 = poing_obj->x_pos + poing_obj->offset_bx;
        unk_y_1 = poing_obj->y_pos + ((poing_obj->offset_by + poing_obj->offset_hy) >> 1) - 3;
    }
    unk_y_2 = mit_obj->y_pos + ((mit_obj->offset_hy + mit_obj->offset_by) >> 1) - unk_y_1;
    *out_x = unk_x_1 - mit_obj->x_pos - mit_obj->offset_bx;
    
    if (unk_y_2 < 0)
    {
        if (poing_obj->speed_y > 0)
        {
            if (unk_y_2 > -30)
                mit_obj->speed_y += 2;
            else if (unk_y_2 > -48)
                mit_obj->speed_y += 1;
        }
        else
        {
            if (unk_y_2 > -30)
                mit_obj->speed_y -= 2;
            else if (unk_y_2 > -48)
                mit_obj->speed_y -= 1;
        }
    }
    else
    {
        if (poing_obj->speed_y >= 0)
        {
            if (unk_y_2 < 30)
                mit_obj->speed_y += 2;
            else if (unk_y_2 < 48)
                mit_obj->speed_y += 1;
        }
        else
        {
            if (unk_y_2 < 30)
                mit_obj->speed_y -= 2;
            else if (unk_y_2 < 48)
                mit_obj->speed_y -= 1;
        }
    }
}

/* 4AA1C 8016F21C -O2 -msoft-float */
s32 HAS_MIT_JUMP(Obj *obj)
{
    s32 res = false;
    
    if (obj->main_etat != 2)
    {
        if (obj->eta[obj->main_etat][obj->sub_etat].flags & 1)
            skipToLabel(obj, 1, true);
    }
    else
    {
        if (obj->sub_etat == 1 && obj->anim_frame == 0)
        {
            obj->speed_y = -5;
            obj->gravity_value_1 = 0;
            obj->gravity_value_2 = 0;
            obj->y_pos -= 14;
        }
        else
            res = true;
    }

    return res;
}

/* 4AACC 8016F2CC -O2 -msoft-float */
s32 ray_over_mit(Obj *obj, s16 param_2)
{
    return
        (!(obj->flags & FLG(OBJ_FLIP_X)) && param_2 > 0) ||
        (obj->flags & FLG(OBJ_FLIP_X) && param_2 < 0);
}

INCLUDE_ASM("asm/nonmatchings/obj/mite", fix_mit_Xspeed);

INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_ATTAK);

INCLUDE_ASM("asm/nonmatchings/obj/mite", IS_MIT_PAF);

INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MITE2_COMMAND);
