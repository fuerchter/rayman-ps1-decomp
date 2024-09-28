#include "bonus_372E0.h"

/* matches, but more cleanup */
/*INCLUDE_ASM("asm/nonmatchings/bonus_372E0", TEST_WIZARD);*/

void TEST_WIZARD(Obj *obj)

{
    u8 obj_sub_etat;
    s16 obj_x; s16 obj_y; s16 obj_w; s16 obj_h;
    s16 x_diff_1;
    s16 x_diff_2;
    s16 x_diff_3;
    s32 y_diff_1;
    u8 new_var2;

    if (
        RayEvts.demi ||
        !(
            ray.flags & FLG(OBJ_FLAG_0) ||
            ((ray.main_etat == 0 || ray.main_etat == 3) && nb_wiz_collected == 0)
        )
    )
        obj->detect_zone_flag = 0;
    
    obj_sub_etat = obj->sub_etat;
    if (obj_sub_etat == 0)
    {
        if ((ray.flags & FLG(OBJ_FLAG_0)))
        {
            if (status_bar.num_wiz + nb_wiz_collected >= 10)
            {
                set_sub_etat(obj, 11);
                obj->timer = 200;
            }
            else
                ray.flags &= ~FLG(OBJ_FLAG_0);
        }
        else
        {
            if (obj->detect_zone_flag != 0)
            {
                if (obj->anim_frame < 20)
                {
                    if (status_bar.num_wiz >= 10)
                        obj->anim_frame = 20;
                    else
                    {
                        set_sub_etat(obj, 10);
                        obj->flags &= ~FLG(OBJ_FLIP_X);
                    }
                }
            }
            else
            {
                if (obj->anim_frame == 19)
                {
                    obj->anim_frame = 0;
                    if (obj->detect_zone_flag == 0)
                        ray.flags &= ~FLG(OBJ_FLAG_0);
                }
            }
        }
    }
    else if (obj_sub_etat != 0 && obj->detect_zone_flag != 0)
    {
        if(ray.flags & FLG(OBJ_FLAG_0) && obj_sub_etat == 11)
        {
            obj->timer--;
            if (obj->timer == 0)
            {
                ray.flags &= ~FLG(OBJ_FLAG_0);
                set_sub_etat(obj, 1);
            }
        }
        else
        {
            if (obj->sub_etat == 1)
            {
                if (
                    (ray.main_etat == 0 && (ray.sub_etat < 2 || /* TODO: ??? */(new_var2 = ray.sub_etat) == 2)) ||
                    ray.main_etat == 1
                )
                {
                    GET_ANIM_POS(obj, &obj_x, &obj_y, &obj_w, &obj_h);
                    x_diff_1 = obj->offset_bx + obj->x_pos - ray.x_pos - ray.offset_bx;
                    x_diff_2 = x_diff_1 - (obj_w >> 1);
                    x_diff_3 = x_diff_1 + (obj_w >> 1);
                    y_diff_1 = (ray.y_pos + ray.offset_by) - obj_y;
                    if (y_diff_1 - obj_h >= 0) /* TODO: ??? */
                    {
                        if(y_diff_1 - obj_h < 9)
                            goto block_1;
                    }
                    else if (obj_h - y_diff_1 < 9)
                    {
        block_1:
                        if (__builtin_abs(x_diff_2) > 16 || !(ray.flags & FLG(OBJ_FLIP_X)))
                        {
                            if (16 < __builtin_abs(x_diff_3))
                                return;
                            if (ray.flags & FLG(OBJ_FLIP_X))
                                return;
                        }

                        if (__builtin_abs(x_diff_2) <= 16 && ray.flags & FLG(OBJ_FLIP_X))
                        {
                            obj->flags &= ~FLG(OBJ_FLIP_X);
                            ray.x_pos = obj->offset_bx + obj->x_pos - ray.offset_bx - (obj_w >> 1) - 12;
                        }
                        else if (__builtin_abs(x_diff_3) <= 16 && !(ray.flags & FLG(OBJ_FLIP_X)))
                        {
                            obj->flags |= FLG(OBJ_FLIP_X);
                            ray.x_pos = obj->offset_bx + obj->x_pos - ray.offset_bx + (obj_w >> 1) + 12;
                        }
                        ray.y_pos = (((ray.y_pos + ray.offset_by) >> 4) << 4) - ray.offset_by;
                        ray.speed_x = 0;
                        decalage_en_cours = 0;
                        ray.speed_y = 0;
                        ray.field24_0x3e = 0;
                        DO_WIZARD(obj);
                    }
                }
            }
            else
                DO_WIZARD(obj);
        }
    }
    else if (!(obj_sub_etat == 10 || ray.main_etat == 3 || obj_sub_etat == 1))
        set_sub_etat(obj, 1);
}