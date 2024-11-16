#include "obj/cymbal.h"

#ifdef BSS_DEFS
s16 cymbal_obj_id[12];
u8 nb_cymbal_in_map;
#endif

/* 49B74 8016E374 -O2 */
#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/cymbal", DO_CYMBAL_COMMAND);
#else
/* "TODO:" section */
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
        if (sub_etat == 0)
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
        else if (sub_etat == 1)
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
                    if (ABS(diff_y - 28) < 20)
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
        else if (sub_etat == 3)
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
#endif

/* 4A078 8016E878 -O2 -msoft-float */
/*s16 test_allowed(Obj *, u8, u8);
s32 on_block_chdir(Obj *obj, s16 param_2, s16 param_3);*/

void DO_2_PARTS_CYMBAL(Obj *cym_obj)
{
    s16 cym_x; s16 cym_y; s16 cym_w; s16 cym_h;
    s16 cym_offs_bx; s16 cym_offs_by;
    u8 cym_sub_etat;
    Obj *link_obj;
    s16 link_offs_bx; s16 link_offs_by;
    u8 link_sub_etat;
    s16 diff_x_1;
    s16 diff_x_2;
    s16 diff_y;
    s32 unk_1;

    cym_offs_bx = cym_obj->offset_bx;
    cym_offs_by = cym_obj->offset_by;
    if (cym_obj->field24_0x3e == 0)
    {
        cym_obj->speed_x = 0;
        cym_obj->speed_y = 0;
    }
    else if (cym_obj->field24_0x3e == 1)
    {
        if (ray.field20_0x36 == cym_obj->id)
        {
            diff_x_1 = (ray.x_pos + ray.offset_bx) - cym_obj->x_pos - cym_offs_bx;
            diff_x_2 = diff_x_1; /* ??? */
            if (diff_x_1 > 96 || diff_x_2 <= -108)
                ray.y_pos += 8;
        }
        if (
            (s16) on_block_chdir(cym_obj, cym_offs_bx, cym_offs_by) &&
            (s16) test_allowed(cym_obj, cym_offs_bx, cym_offs_by)
        )
            skipToLabel(cym_obj, 99, true);
        cym_obj->flags = cym_obj->flags & ~FLG(OBJ_FLIP_X);
        if (cym_obj->cmd == 20)
        {
            /* ??? */
            cym_obj->speed_x = cym_obj->iframes_timer;
            cym_obj->speed_y = cym_obj->field20_0x36;
        }
    }
    if (cym_obj->field24_0x3e > 0)
    {
        link_obj = &level.objects[link_init[cym_obj->id]];
        if (!(link_obj->flags & FLG(OBJ_ACTIVE)))
            link_obj->flags = link_obj->flags | FLG(OBJ_ACTIVE);

        unk_1 = -1;
        if (*(s32 *) &cym_obj->speed_x == 0)
        {
            if (cym_obj->field24_0x3e == 1)
            {
                cym_obj->field24_0x3e = 2;
                skipToLabel(link_obj, 99, true);
            }
            if (cym_obj->field24_0x3e == 2)
            {
                link_obj->field24_0x3e = 3;
                diff_x_2 = link_obj->x_pos - cym_obj->x_pos;
                diff_y = link_obj->y_pos - cym_obj->y_pos;
                if (diff_x_2 > 6)
                    link_obj->speed_x = -4;
                else if (diff_x_2 < -6)
                    link_obj->speed_x = 4;
                else if (diff_x_2 > 0)
                    link_obj->speed_x = -1;
                else if (diff_x_2 < 0)
                    link_obj->speed_x = 1;
                else
                {
                    link_obj->speed_x = 0;
                    if (diff_y < -8)
                        link_obj->speed_y = 4;
                    else if (diff_y > 8)
                        link_obj->speed_y = -4;
                    else if (diff_y > 0)
                        link_obj->speed_y = -1;
                    else if (diff_y >= 0)
                    {
                        link_obj->speed_y = 0;
                        cym_obj->field24_0x3e = 4;
                        link_obj->field24_0x3e = 4;
                        if (link_obj->type == TYPE_CYMBAL1)
                        {
                            cym_sub_etat = 9;
                            link_sub_etat = 5;
                        }
                        else
                        {
                            cym_sub_etat = 5;
                            link_sub_etat = 9;
                        }
                        set_main_and_sub_etat(link_obj, 0, link_sub_etat);
                        set_main_and_sub_etat(cym_obj, 0, cym_sub_etat);
                    }
                    else
                        link_obj->speed_y = 1;
                }
            }
            else
            {
                if (cym_obj->field24_0x3e == 4)
                {
                    if (cym_obj->type == TYPE_CYMBAL1)
                        cym_sub_etat = 7;
                    else
                        cym_sub_etat = 11;

                    if (
                        cym_obj->main_etat == 0 && cym_obj->sub_etat == cym_sub_etat &&
                        cym_obj->anim_frame == 0
                    )
                    {
                        cym_obj->field24_0x3e = 5;
                        if (
                            (ray.flags & FLG(OBJ_ACTIVE)) == 0 && ray.field20_0x36 == cym_obj->id &&
                            ray.iframes_timer == unk_1 && cym_obj->type == TYPE_CYMBAL2
                        )
                        {
                            ray.x_pos -= 4;
                            ray.flags = ray.flags | FLG(OBJ_ACTIVE);
                            GET_SPRITE_POS(cym_obj, 1, &cym_x, &cym_y, &cym_w, &cym_h);
                            ray.y_pos = cym_obj->offset_hy + cym_y - ray.offset_by;
                            set_main_and_sub_etat(&ray, 0, 8);
                        }
                    }
                }
                else if (cym_obj->field24_0x3e == 5)
                {
                    link_offs_bx = link_obj->offset_bx;
                    link_offs_by = link_obj->offset_by;
                    /* ??? */
                    cym_x = on_block_chdir(cym_obj, cym_offs_bx, cym_offs_by);
                    cym_y = on_block_chdir(link_obj, link_offs_bx, link_offs_by);
                    cym_w = test_allowed(cym_obj, cym_offs_bx, cym_offs_by);
                    cym_h = test_allowed(link_obj, link_offs_bx, link_offs_by);
                    if (
                        (s16) on_block_chdir(cym_obj, cym_offs_bx, cym_offs_by) &&
                        (s16) on_block_chdir(link_obj, link_offs_bx, link_offs_by)
                    )
                    {
                        cym_obj->field24_0x3e = 1;
                        link_obj->field24_0x3e = 1;
                        test_allowed(cym_obj, cym_offs_bx, cym_offs_by);
                        test_allowed(link_obj, link_offs_bx, link_offs_by);
                        skipToLabel(cym_obj, 99, true);
                        skipToLabel(link_obj, 99, true);
                    }
                    else if (!(s16) on_block_chdir(link_obj, link_offs_bx, link_offs_by))
                    {
                        if (link_obj->type == TYPE_CYMBAL1)
                            link_obj->speed_y = -1;
                        else
                            link_obj->speed_y = 1;
                    }
                }
            }
        }
    }
}