#include "obj/dark2_pink_fly.h"

/* 78004 8019C804 -O2 -msoft-float */
void AllocateToons(void)
{
    s16 unk_1 = -1;
    s16 unk_2 = 0;
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (
            unk_2 == 0 &&
            cur_obj->type == TYPE_DARK2_PINK_FLY && !(cur_obj->flags & FLG(OBJ_ACTIVE))
        )
        {
            cur_obj->display_prio = 4;
            cur_obj->init_x_pos =
            cur_obj->x_pos =
                320;
            cur_obj->init_y_pos = 
            cur_obj->y_pos =
                ymap + 100;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->hit_points = 0;
            cur_obj->field23_0x3c = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);

            unk_1 = i;
            unk_2 = 1;
        }
        else if (
            unk_2 == 1 &&
            cur_obj->type == TYPE_DARK2_PINK_FLY && !(cur_obj->flags & FLG(OBJ_ACTIVE))
        )
        {
            cur_obj->display_prio = 4;
            cur_obj->init_x_pos = 
            cur_obj->x_pos =
                -20;
            cur_obj->init_y_pos = 
            cur_obj->y_pos =
                ymap + 100;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->hit_points = 1;
            cur_obj->field23_0x3c = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);

            cur_obj->field24_0x3e = unk_1;
            level.objects[unk_1].field24_0x3e = i;
            break;
        }
        i++;
        cur_obj++;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/dark2_pink_fly", DO_DARK2_TOONS_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark2_pink_fly", ToonDonnePoing);
