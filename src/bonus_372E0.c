#include "bonus_372E0.h"

/* 372E0 8015BAE0 -O2 */
void DO_WIZARD(Obj *obj)
{
  switch (obj->sub_etat)
  {
    case 1:
        if (status_bar.num_wiz >= 10)
        {
            obj->field24_0x3e = status_bar.num_wiz;
            set_sub_etat(obj, 2);
            set_main_and_sub_etat(&ray, 3, 9);
        }
        else
        {
            set_sub_etat(obj, 10);
            obj->flags &= ~FLG(OBJ_FLIP_X);
        }
        break;
    case 3:
        set_main_and_sub_etat(&ray, 3, 0xA);
        if (horloge[2] == 0 && (obj->field24_0x3e - status_bar.num_wiz < 10))
            status_bar.num_wiz--;
        break;
    case 5:
        if (ray.main_etat == 3 && (ray.sub_etat - 0xB >= 2U))
            set_sub_etat(&ray, 0xB);

        if (obj->anim_frame >= obj->animations[obj->anim_index].frames_count - 1)
        {
            set_sub_etat(obj, 0);
            fix_numlevel(obj);
            save_objects_flags();

            ray.flags |= FLG(OBJ_FLAG_0);
            set_main_and_sub_etat((&ray), 0, 0);
        }
        break;
  }
}

/* TODO: inserting nop caused reg swap */
/* 374A8 8015BCA8 -O2 */
s16 get_next_bonus_level(u8 level)
{
    s16 res = 0;

    switch (num_world)
    {
    case 1:
        switch (level)
        {
        case 2:
            res = 21;
            break;
        case 4:
            res = 20;
            break;
        case 11:
            res = 18;
            break;
        case 12:
            res = 19;
            break;
        }
        break;
    case 2:
        switch (level)
        {
        case 4:
            res = 17;
            break;
        case 9:
            res = 18;
            break;
        }
        break;
    case 4:
        switch (level)
        {
        case 3:
            res = 12;
            break;
        case 9:
            res = 13;
            break;
        }
        break;
    case 5:
        switch (level)
        {
        case 2:
            res = 12;
            break;
        }
    case 6:
        break;
    }

    return res;
}

/* 375BC 8015BDBC -O2 -msoft-float */
void TEST_WIZARD(Obj *obj)
{
    u8 obj_sub_etat;
    s16 obj_x; s16 obj_y; s16 obj_w; s16 obj_h;
    s16 x_diff_1;
    s16 x_diff_2;
    s16 x_diff_3;
    s32 y_diff_1;

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
        if (ray.flags & FLG(OBJ_FLAG_0))
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
    else if (!(obj_sub_etat == 0 || obj->detect_zone_flag == 0))
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
        else if (obj->sub_etat == 1)
        {
            if (
                (ray.main_etat == 0 && (ray.sub_etat == 0 || ray.sub_etat == 1 || ray.sub_etat == 2)) ||
                ray.main_etat == 1
            )
            {
                GET_ANIM_POS(obj, &obj_x, &obj_y, &obj_w, &obj_h);
                x_diff_1 = obj->x_pos + obj->offset_bx - ray.x_pos - ray.offset_bx;
                x_diff_2 = x_diff_1 - (obj_w >> 1);
                x_diff_3 = x_diff_1 + (obj_w >> 1);
                y_diff_1 = (ray.y_pos + ray.offset_by) - obj_y;
                /* TODO: still not great? */
                if (
                    y_diff_1 - obj_h >= 0 ?
                        y_diff_1 - obj_h < 9 :
                        obj_h - y_diff_1 < 9
                )
                {
                    if (
                        (__builtin_abs(x_diff_2) <= 16 && ray.flags & FLG(OBJ_FLIP_X)) ||
                        (__builtin_abs(x_diff_3) <= 16 && !(ray.flags & FLG(OBJ_FLIP_X)))
                    )
                    {
                        if (__builtin_abs(x_diff_2) <= 16 && ray.flags & FLG(OBJ_FLIP_X))
                        {
                            obj->flags &= ~FLG(OBJ_FLIP_X);
                            ray.x_pos = obj->x_pos + obj->offset_bx - ray.offset_bx - (obj_w >> 1) - 12;
                        }
                        else if (__builtin_abs(x_diff_3) <= 16 && !(ray.flags & FLG(OBJ_FLIP_X)))
                        {
                            obj->flags |= FLG(OBJ_FLIP_X);
                            ray.x_pos = obj->x_pos + obj->offset_bx - ray.offset_bx + (obj_w >> 1) + 12;
                        }
                        ray.y_pos = ((ray.y_pos + ray.offset_by) >> 4 << 4) - ray.offset_by;
                        ray.speed_x = 0;
                        decalage_en_cours = 0;
                        ray.speed_y = 0;
                        ray.field24_0x3e = 0;
                        DO_WIZARD(obj);
                    }
                }
            }
        }
        else
            DO_WIZARD(obj);
    }
    else if (!(obj_sub_etat == 10 || ray.main_etat == 3 || obj_sub_etat == 1))
        set_sub_etat(obj, 1);
}