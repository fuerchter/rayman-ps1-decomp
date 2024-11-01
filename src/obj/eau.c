#include "obj/eau.h"

#ifdef BSS_DEFS
s16 eau_obj_id;
#endif

/* 4D908 80172108 -O2 -msoft-float */
void ACTIVE_L_EAU(Obj *eau_obj)
{
    s16 i;
    Obj *cur_obj;
    s16 nb_objs;

    eau_obj->field23_0x3c = 130;
    eau_obj->y_pos = ymapmax + 230;
    eau_obj->x_pos = xmap - eau_obj->offset_bx;
    i = 0;
    cur_obj = level.objects;
    nb_objs = level.nb_objects;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_EAU && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->flags &= ~FLG(OBJ_FLIP_X);
            cur_obj->speed_y = 0;
            cur_obj->speed_x = 0;
            cur_obj->x_pos = eau_obj->x_pos + 101 * 1;
            cur_obj->y_pos = eau_obj->y_pos;
            calc_obj_pos(cur_obj);
            cur_obj->field23_0x3c = 130;
            cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
            cur_obj->sub_etat = 1;
            break;
        }
        cur_obj++;
        i++;
    }
    cur_obj++;
    cur_obj->flags &= ~FLG(OBJ_FLIP_X);
    cur_obj->speed_y = 0;
    cur_obj->speed_x = 0;
    cur_obj->x_pos = eau_obj->x_pos + 101 * 2;
    cur_obj->y_pos = eau_obj->y_pos;
    calc_obj_pos(cur_obj);
    cur_obj->field23_0x3c = 130;
    cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
    cur_obj->sub_etat = 2;

    cur_obj++;
    cur_obj->flags &= ~FLG(OBJ_FLIP_X);
    cur_obj->speed_y = 0;
    cur_obj->speed_x = 0;
    cur_obj->x_pos = eau_obj->x_pos + 101 * 3;
    cur_obj->y_pos = eau_obj->y_pos;
    calc_obj_pos(cur_obj);
    cur_obj->field23_0x3c = 130;
    cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
    cur_obj->sub_etat = 3;
}

#ifndef NONMATCHINGS
INCLUDE_ASM("asm/nonmatchings/obj/eau", DO_EAU_QUI_MONTE);
#else
/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/obj/eau", DO_EAU_QUI_MONTE);*/

void DO_EAU_QUI_MONTE(Obj *obj)
{
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v1_1;
    s16 temp_v1_2;
    s16 temp_v1_4;
    s16 var_v0;
    s16 var_v0_2;
    u16 temp_a0;
    u16 temp_v1_3;
    u8 temp_v0_1;
    u8 temp_v0_6;
    u8 temp_v0_7;
    s16 other_1;

    #ifdef NUGGET
    printf("DO_EAU_QUI_MONTE\n");
    #endif
    if ((ray.flags & 0x400) && ((ray.main_etat != 3) || (ray.sub_etat != 0x17)))
    {
        switch (num_world)
        {
        case 1:
            if (obj->hit_points != 0)
            {
                if (obj->hit_points == 1)
                {
                    obj->hit_points--;
                    ACTIVE_L_EAU(obj);
                }
                else
                {
                    goto block_1; /* TODO: ??? */
                }
            }
            else if ((obj->field23_0x3c >= 0x29) || (level.objects[eau_obj_id].iframes_timer == 1))
            {
                if ((horloge[2] != 0) && (obj->y_pos >= 0xA1))
                {
                    obj->speed_y = -1;
                }
                else
                {
                    obj->speed_y = 0;
                }
                temp_v0_2 = obj->field23_0x3c;
                if (temp_v0_2 > 0)
                {
                    obj->field23_0x3c = temp_v0_2 - 1;
                }
            }
            else
            {
                obj->speed_y = 0;
            }
            break;
block_1:
            obj->hit_points--;
            break;
        case 3:
            if (pierreAcorde_obj_id == -1)
            {
                if (scroll_y != pierreAcorde_obj_id)
                {
                    obj->init_y_pos = ymap + 0xA0;
                    if ((obj->y_pos - 0x64) > obj->init_y_pos)
                    {
                        obj->y_pos = obj->y_pos - 3;
                    }
                    obj->y_pos = obj->y_pos - 1;
                    if (obj->y_pos > obj->init_y_pos)
                    {
                        if (horloge[2] != 0)
                        {
                            obj->y_pos = obj->y_pos - 2;
                        }
                    }
                    obj->iframes_timer = 1;
                }
                else
                {
                    if (obj->iframes_timer == 1)
                    {
                        obj->init_y_pos = (ray.offset_by + ray.y_pos) - 0x1E;
                        obj->iframes_timer = 0;
                    }
                    if (obj->init_y_pos < obj->y_pos)
                    {
                        obj->y_pos--;
                    }
                }
            }
            else if ((level.objects[pierreAcorde_obj_id].hit_points != 0) && (obj->y_pos < (ymapmax + 0xA0)))
            {
                temp_v1_3 = (u16) obj->field12_0x26;
                temp_v0_5 = temp_v1_3 + 0xE;
                obj->field12_0x26 = temp_v0_5;
                if (temp_v0_5 >= 0x11)
                {
                    obj->field12_0x26 = temp_v1_3 - 2;
                    var_v0 = (u16) obj->y_pos + 1;
                    obj->y_pos = var_v0;
                }
            }
            scroll_end_y = (u16) obj->y_pos - 0xA0;
        case 4:
        case 5:
            temp_v1_4 = obj->screen_x_pos;
            if (temp_v1_4 < -166)
            {
                obj->x_pos += 505;
                if (++obj->sub_etat >= 4)
                    obj->sub_etat = 0;
                if (num_level == 8 && num_world == 5)
                {
                    var_v0_2 = obj->init_y_pos - 5;
                    goto block_53;
                }
            }
            else if (temp_v1_4 > 366)
            {
                obj->x_pos -= 505;
                if (--obj->sub_etat >= 4)
                    obj->sub_etat = 3;
                if (num_level == 8 && num_world == 5)
                {
                    var_v0_2 = obj->init_y_pos + 5;
block_53:
                    obj->y_pos =
                    obj->init_y_pos =
                        var_v0_2;
                    if (obj->y_pos < (ymapmax + 0xA0))
                    {
                        obj->y_pos = ymapmax + 0xA0;
                    }
                }
            }
            break;
        }
    }
    else
    {
        obj->speed_y = 0;
        obj->speed_x = 0;
    }
    if (obj->y_pos < (ymap + 0xA0))
    {
        obj->y_pos = ymap + 0xA0;
    }
}
#endif
