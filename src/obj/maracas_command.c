#include "obj/maracas_command.h"

/* 4CB88 80171388 -O2 -msoft-float */
s16 MarCoince(Obj *obj, s16 dir)
{    
    s32 map_ind;
    s32 pos_to_check;
    s16 res = false;
    s16 x_pos = obj->x_pos + obj->offset_bx - 25;
    s16 y_pos = obj->y_pos + obj->offset_hy;

    switch (dir)
    {
    case 2:
        pos_to_check = y_pos - (y_pos / 16 * 16);
        if ((s16) pos_to_check < 3)
        {
            map_ind = (x_pos >> 4) + mp.width * (y_pos >> 4);
            if (block_flags[mp.map[map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
        }
        break;
    case 3:
        pos_to_check = y_pos - (y_pos / 16 * 16);
        if ((s16) pos_to_check > 12)
        {
            map_ind = (x_pos >> 4) + mp.width * ((y_pos + 16 * 3) >> 4);
            if (block_flags[mp.map[map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
        }
        break;
    case 0:
        pos_to_check = x_pos - (x_pos / 16 * 16);
        if ((s16) pos_to_check < 3)
        {
            map_ind = ((x_pos >> 4) + mp.width * ((y_pos + 16) >> 4)) - 1;
            if (block_flags[mp.map[map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] >> BLOCK_SOLID & 1)
                res = true;
        }
        break;
    case 1:
        pos_to_check = x_pos - (x_pos / 16 * 16);
        if ((s16) pos_to_check > 12)
        {
            map_ind = ((x_pos >> 4) + mp.width * ((y_pos + 16) >> 4)) + 3;
            if (block_flags[mp.map[map_ind] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] >> BLOCK_SOLID & 1)
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] >> BLOCK_SOLID & 1)
                res = true;
        }
        break;
    }

    return res;
}

/* 4CF4C 8017174C -O2 */
/*? DO_NOVA(Obj *);
? PlaySnd(?, s16);
? allocateExplosion(Obj *);
s16 get_center_x();
s16 get_center_y(Obj *);
s32 on_block_chdir(Obj *, s16, s16);
? set_main_and_sub_etat(Obj *, ?, ?);
? skipToLabel(Obj *, ?, ?);
s32 test_allowed(Obj *, s16, s16);*/

void DO_MOVE_MARACAS_COMMAND(Obj *obj)
{
    s16 cen_x;
    s16 cen_y;
    s16 speed_x;
    s16 diff_x;
    s16 diff_x_inv;
    s32 diff_x_less;
    
    if (obj->main_etat == 0 && obj->sub_etat == 0x0C)
    {
        cen_x = get_center_x(obj);
        cen_y = get_center_y(obj);
        if ((s16)on_block_chdir(obj, cen_x, cen_y) && (s16)test_allowed(obj, cen_x, cen_y))
            skipToLabel(obj, 99, true);
        
        obj->flags &= ~FLG(OBJ_FLIP_X);
        speed_x = 0;
        if (obj->cmd == 0x14)
            obj->speed_y = obj->field20_0x36;
        
        if (ray.field20_0x36 == obj->id)
        {
            diff_x = (ray.offset_bx + ray.x_pos) - (obj->offset_bx + obj->x_pos);
            if (diff_x > 0)
            {
                if (diff_x >= 11)
                    speed_x = 1;
                if (diff_x >= 16)
                    speed_x += 1;
                if (diff_x >= 19)
                    speed_x += 1;
                diff_x_less = diff_x < 43;
            }
            else
            {
                diff_x_inv = -1;
                diff_x_inv = diff_x * diff_x_inv;
                if (diff_x_inv >= 11)
                    speed_x = -1;
                if (diff_x_inv >= 16)
                    speed_x -= 1;
                if (diff_x_inv >= 19)
                    speed_x -= 1;
                diff_x_less = diff_x_inv < 42;
            }
            if (!diff_x_less)
                speed_x = 0;
        }
        obj->speed_x = speed_x;
        if (obj->speed_y < 0)
        {
            if (MarCoince(obj, 2))
            {
                obj->speed_y = 0;
                obj->field23_0x3c++;
                if (obj->field23_0x3c >= 0xF1)
                {
                    obj->y_pos -= 80;
                    allocateExplosion(obj);
                    PlaySnd(0x73, obj->id);
                    obj->x_pos = obj->init_x_pos;
                    obj->y_pos = obj->init_y_pos;
                    set_main_and_sub_etat(obj, 0, 4);
                    obj->speed_x = 0;
                    obj->speed_y = 0;
                    DO_NOVA(obj);
                }
            }
            else
                obj->field23_0x3c = 0;
        }
        if (obj->speed_x > 0)
        {
            if (MarCoince(obj, 1))
                obj->speed_x = 0;
        }
        else if (obj->speed_x < 0)
        {
            if (MarCoince(obj, 0))
                obj->speed_x = 0;
        }
    }
}