#include "obj/cymbal.h"

/* matches, but too many unk_* locals */
/* 49B74 8016E374 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/cymbal", DO_CYMBAL_COMMAND);*/

s32 on_block_chdir(Obj *obj,short param_2,short param_3);

void DO_CYMBAL_COMMAND(Obj *obj)
{
    s16 speed_x;
    s16 spr_x;
    s16 spr_y;
    s16 spr_w;
    s16 spr_h;
    s16 diff_x;
    s32 diff_y;
    s16 unk_1;
    s32 unk_2;
    s32 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 sub_etat;
    u8 y_ge_0;

    speed_x = obj->speed_x;
    diff_x = ray.offset_bx + ray.x_pos - obj->x_pos - obj->offset_bx;
    if (ray.field20_0x36 == obj->id)
    {
        obj->gravity_value_2 = 5;
        if (diff_x > 0)
        {
            if (diff_x >= 99)
                ray.y_pos += 8;
            else
            {
                if (diff_x >= 71)
                    unk_1 = 4;
                else if (diff_x >= 61)
                    unk_1 = 3;
                else if (diff_x >= 41)
                    unk_1 = 2;
                else
                    unk_1 = !(diff_x < 21);
            }

            if (speed_x < unk_1 && obj->gravity_value_1-- == 0)
            {
                speed_x++;
                obj->gravity_value_1 = 5;
            }
            else if (speed_x > unk_1 && obj->gravity_value_1-- == 0)
            {
                speed_x--;
                obj->gravity_value_1 = 5;
            }
        }
        else
        {
            diff_x = -diff_x;
            unk_2 = 510;
            unk_3 = 255;
            if (diff_x >= 106)
                ray.y_pos += 8;
            else
            {
                if (diff_x >= 71)
                    unk_1 = -4;
                else if (diff_x >= 61)
                    unk_1 = -3;
                else if (diff_x >= 41)
                    unk_1 = -2;
                else
                    unk_1 = (diff_x < 21) - 1;
            }
            if (speed_x > unk_1)
            {
                unk_4 = obj->gravity_value_1;
                unk_5 = unk_4 + unk_3;
                obj->gravity_value_1 = unk_5;
                if (unk_4 == 0 || (obj->gravity_value_1 = unk_4 + unk_2, unk_5 == 0))
                {
                    speed_x--;
                    obj->gravity_value_1 = 5;
                }
            }
        }

    }
    else
    {
        unk_6 = obj->gravity_value_2;
        obj->gravity_value_2 = unk_6 + 255;
        if (unk_6 == 0)
        {
            obj->gravity_value_2 = 5;
            if (speed_x != 0)
            {
                if (speed_x > 0)
                    speed_x--;
                else
                    speed_x++;
            }
        }
    }
    if ((s16) on_block_chdir(obj, obj->offset_bx + speed_x * 2, obj->offset_by))
        speed_x = 0;
    obj->speed_x = speed_x;
    if (obj->main_etat == 0)
    {
        sub_etat = obj->sub_etat;
        if(sub_etat == 0)
        {
            if (obj->field24_0x3e == 0 && ray.field20_0x36 == obj->id)
            {
                if (obj->timer >= 101)
                {
                    obj->field24_0x3e = 1;
                    obj->timer = 0;
                    skipToLabel(obj, 2, 1);
                }
                else
                    obj->timer++;
            }
        }
        else if(sub_etat == 1)
        {
            obj->field24_0x3e = 0;
            if (ray.main_etat == 2 && ray.iframes_timer == -1 && ((u32) (obj->anim_frame - 20) < 3))
            {
                GET_SPRITE_POS(obj, 1, &spr_x, &spr_y, &spr_w, &spr_h);
                if (__builtin_abs(diff_x) < 100)
                {
                    diff_y = ray.y_pos + ray.offset_by - spr_y - obj->offset_hy;
                    y_ge_0 = diff_y - 28 >= 0;
                    if ((y_ge_0 && diff_y - 28 < 20) || (!y_ge_0 && 28 - diff_y < 20))
                    {
                        if (diff_x < 0)
                            ray.flags |= FLG(OBJ_FLIP_X);
                        else
                            ray.flags &= ~FLG(OBJ_FLIP_X);
                        RAY_HIT(1, obj);
                    }
                }
            }
        }
        else if(sub_etat == 3)
        {
            if (!(ray.flags & FLG(OBJ_ACTIVE)) && obj->anim_frame == 0 && ray.field20_0x36 == obj->id)
            {
                ray.flags |= FLG(OBJ_ACTIVE);
                ray.iframes_timer = -1;
                ray.x_pos -= 4;
                GET_SPRITE_POS(obj, 1, &spr_x, &spr_y, &spr_w, &spr_h);
                ray.y_pos = obj->offset_hy + spr_y - ray.offset_by;
                set_main_and_sub_etat(&ray, 0, 8);
            }
        }
    }
}