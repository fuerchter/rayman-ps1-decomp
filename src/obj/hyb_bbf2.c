#include "obj/hyb_bbf2.h"

extern Obj *TirBBF2D;
extern Obj *TirBBF2G;

INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", doBBF2command);

/* 76300 8019AB00 -O2 -msoft-float */
void DO_HYB_BBF2_POING_COLLISION(Obj *obj)
{
    /* TODO: ??? switch instead didn't work */
    if (obj->sub_etat == 2)
    {}
    else if (obj->sub_etat == 1)
    {}
    else
    {
        if (level.objects[obj->field24_0x3e].sub_etat != 1)
        {
            obj->hit_points--;
            level.objects[obj->field24_0x3e].hit_points = obj->hit_points;
            if (obj->hit_points != 0)
                set_main_and_sub_etat(obj, 0, 1);
            else
            {
                set_main_and_sub_etat(obj, 0, 2);
                obj->speed_y = -128;
                obj->speed_x = 0;
                obj->flags &= ~FLG(OBJ_READ_CMDS);
                obj->field23_0x3c = 1;

                set_main_and_sub_etat(&level.objects[obj->field24_0x3e], 0, 2);
                level.objects[obj->field24_0x3e].speed_y = -128;
                level.objects[obj->field24_0x3e].speed_x = 0;
                level.objects[obj->field24_0x3e].flags &= ~FLG(OBJ_READ_CMDS);
                level.objects[obj->field24_0x3e].field23_0x3c = 1;
            }
        }
    }
}

/*INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", AllocateTirBBF2);*/

void AllocateTirBBF2(Obj *bbf2_obj)
{
    Obj *cur_obj = &level.objects[0];
    s16 i = 0;
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_HYB_BBF2_LAS && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->display_prio = 4;
            cur_obj->init_x_pos = cur_obj->x_pos = bbf2_obj->x_pos;
            cur_obj->init_y_pos = cur_obj->y_pos = bbf2_obj->y_pos;
            if (bbf2_obj->type == TYPE_HYB_BBF2_D)
            {
                cur_obj->speed_x = -5;
                TirBBF2D = cur_obj;
                cur_obj->flags &= ~FLG(OBJ_FLIP_X);
            }
            else
            {
                cur_obj->speed_x = 5;
                TirBBF2G = cur_obj;
                cur_obj->flags |= FLG(OBJ_FLIP_X);
            }
            cur_obj->speed_y = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            cur_obj->field24_0x3e = bbf2_obj->field24_0x3e;
            break;
        }
        cur_obj++;
        i++;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", DO_HYB_BBF2_LAS);

/* 76870 8019B070 -O2 -msoft-float */
s32 OBJ_IN_COL_ZDC(Obj *obj1, Obj *obj2)
{
    s16 x1; s16 y1; s16 w1;
    s16 x2; s16 y2; s16 w2;
    s16 h;
    ZDC *zdc1 = get_zdc(obj1, 0);
    ZDC *zdc2 = get_zdc(obj2, 0);

    GET_SPRITE_POS(obj1, zdc1->sprite, &x1, &y1, &w1, &h);
    GET_SPRITE_POS(obj2, zdc2->sprite, &x2, &y2, &w2, &h);

    if (!(obj1->flags & FLG(OBJ_FLIP_X)))
        x1 += zdc1->x_pos;
    else
        x1 = (x1 + w1) - (zdc1->x_pos + zdc1->width);
    
    if (!(obj2->flags & FLG(OBJ_FLIP_X)))
        x2 += zdc2->x_pos;
    else
        x2 = (x2 + w2) - (zdc2->width + zdc2->x_pos);
    y1 += zdc1->y_pos;
    y2 += zdc2->y_pos;

    return (s16) inter_box(x1, y1, zdc1->width, zdc1->height, x2, y2, zdc2->width, zdc2->height);
}
