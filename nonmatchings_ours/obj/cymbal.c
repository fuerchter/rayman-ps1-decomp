#include "obj/cymbal.h"

/* matches, but the "TODO:"" section */
/* 49B74 8016E374 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/cymbal", DO_CYMBAL_COMMAND);*/

void DO_CYMBAL_COMMAND(Obj *obj)
{
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
    s32 diff_y;
    s16 unk_1;
    s32 unk_2;
    s32 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 sub_etat;
    s16 spd_x = obj->speed_x;
    s16 diff_x = ray.x_pos + ray.offset_bx - obj->x_pos - obj->offset_bx;
    
    if (ray.field20_0x36 == obj->id)
    {
        obj->gravity_value_2 = 5;
        if (diff_x > 0)
        {
            if (diff_x > 98)
                ray.y_pos += 8;
            else
            {
                if (diff_x > 70)
                    unk_1 = 4;
                else if (diff_x > 60)
                    unk_1 = 3;
                else if (diff_x > 40)
                    unk_1 = 2;
                else if (diff_x > 20)
                    unk_1 = 1;
                else
                    unk_1 = 0;
            }

            if (spd_x < unk_1 && obj->gravity_value_1-- == 0)
            {
                spd_x++;
                obj->gravity_value_1 = 5;
            }
            else if (spd_x > unk_1 && obj->gravity_value_1-- == 0)
            {
                spd_x--;
                obj->gravity_value_1 = 5;
            }
        }
        else
        {
            diff_x = -diff_x;
            unk_2 = 510;
            unk_3 = 255;
            if (diff_x > 105)
                ray.y_pos += 8;
            else
            {
                if (diff_x > 70)
                    unk_1 = -4;
                else if (diff_x > 60)
                    unk_1 = -3;
                else if (diff_x > 40)
                    unk_1 = -2;
                else if (diff_x > 20)
                    unk_1 = -1;
                else
                    unk_1 = 0;
            }

            if (spd_x > unk_1)
            {
                /* TODO: ??? */
                unk_4 = obj->gravity_value_1;
                unk_5 = unk_4 + unk_3;
                obj->gravity_value_1 = unk_5;
                if (unk_4 == 0 || (obj->gravity_value_1 = unk_4 + unk_2, unk_5 == 0))
                {
                    spd_x--;
                    obj->gravity_value_1 = 5;
                }
            }
        }

    }
    else
    {
        if (obj->gravity_value_2-- == 0)
        {
            obj->gravity_value_2 = 5;
            if (spd_x != 0)
            {
                if (spd_x > 0)
                    spd_x--;
                else
                    spd_x++;
            }
        }
    }
    if (on_block_chdir(obj, obj->offset_bx + spd_x * 2, obj->offset_by))
        spd_x = 0;
    
    obj->speed_x = spd_x;
    if (obj->main_etat == 0)
    {
        sub_etat = obj->sub_etat;
        if(sub_etat == 0)
        {
            if (obj->field24_0x3e == 0 && ray.field20_0x36 == obj->id)
            {
                if (obj->timer > 100)
                {
                    obj->field24_0x3e = 1;
                    obj->timer = 0;
                    skipToLabel(obj, 2, true);
                }
                else
                    obj->timer++;
            }
        }
        else if(sub_etat == 1)
        {
            obj->field24_0x3e = 0;
            if (
                ray.main_etat == 2 && ray.iframes_timer == -1 &&
                obj->anim_frame >= 20 && obj->anim_frame <= 22
            )
            {
                GET_SPRITE_POS(obj, 1, &spr_x, &spr_y, &spr_w, &spr_h);
                if (__builtin_abs(diff_x) < 100)
                {
                    diff_y = ray.y_pos + ray.offset_by - spr_y - obj->offset_hy;
                    #define ABS_LT(x, y) (x >= 0 ? x < y : -(x) < y)
                    if (ABS_LT(diff_y - 28, 20))
                    {
                        if (diff_x < 0)
                            ray.flags |= FLG(OBJ_FLIP_X);
                        else
                            ray.flags &= ~FLG(OBJ_FLIP_X);
                        RAY_HIT(true, obj);
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