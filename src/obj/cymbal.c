#include "obj/cymbal.h"

INCLUDE_ASM("asm/nonmatchings/obj/cymbal", DO_CYMBAL_COMMAND);

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
        if (*(s32 *)&cym_obj->speed_x == 0)
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