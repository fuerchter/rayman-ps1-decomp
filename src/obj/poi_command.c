#include "obj/poi_command.h"

/* 4EFB0 801737B0 -O2 -msoft-float */
void DO_POISSON_VERT_CMD(Obj *obj)
{
    DO_ONE_CMD(obj);
    if (
        (
            !(obj->flags & FLG(OBJ_FLIP_X)) &&
            on_block_chdir(obj, obj->offset_bx - 20, obj->offset_by - 3) &&
            (s16) test_allowed(obj, obj->offset_bx - 20, obj->offset_by - 3)
        ) ||
        (
            obj->flags & FLG(OBJ_FLIP_X) &&
            on_block_chdir(obj, obj->offset_bx + 20, obj->offset_by - 3) &&
            (s16) test_allowed(obj, obj->offset_bx + 20, obj->offset_by - 3)
        )
    )
    {
        if (obj->flags & FLG(OBJ_FLIP_X))
        {
            obj->flags &= ~FLG(OBJ_FLIP_X);
            skipToLabel(obj, 7, true);
        }
        else
        {
            obj->flags |= FLG(OBJ_FLIP_X);
            skipToLabel(obj, 8, true);
        }
    }
    DO_OBJ_COLLISIONS(obj, 4);
}

/* 4F0CC 801738CC -O2 -msoft-float */
void DO_POISSON_BLEU_CMD(Obj *obj)
{
    u8 flag_set;

    DO_ONE_CMD(obj);
    if (
        (
            !(obj->flags & FLG(OBJ_FLIP_X)) &&
            on_block_chdir(obj, obj->offset_bx - 20, obj->offset_by - 3) &&
            (s16) test_allowed(obj, obj->offset_bx - 20, obj->offset_by - 3)
        ) ||
        (
            obj->flags & FLG(OBJ_FLIP_X) &&
            on_block_chdir(obj, obj->offset_bx + 20, obj->offset_by - 3) &&
            (s16) test_allowed(obj, obj->offset_bx + 20, obj->offset_by - 3)
        )
    )
    {
        if (obj->flags & FLG(OBJ_FLIP_X))
        {
            obj->flags &= ~FLG(OBJ_FLIP_X);
            skipToLabel(obj, 13, true);
        }
        else
        {
            obj->flags |= FLG(OBJ_FLIP_X);
            skipToLabel(obj, 14, true);
        }
        obj->y_pos = obj->init_y_pos;
    }
  
    if (obj->main_etat == 2 && obj->sub_etat == 17)
    {
        if (obj->init_y_pos <= obj->y_pos)
        {
            if ((obj->flags & FLG(OBJ_FLIP_X)))
                skipToLabel(obj, 10, true);
            else
                skipToLabel(obj, 9, true);
            obj->y_pos = obj->init_y_pos;
        }
    }
    if (obj->main_etat == 2 && obj->sub_etat == 18)
    {
        flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
        if(
            ((flag_set && obj->anim_frame == 0) ||
            (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
        )
        {
            if (obj->speed_y == 5)
            {
                obj->display_prio = 0;
                obj->flags &= ~FLG(OBJ_ACTIVE);
            }
            else
            {
                obj->speed_x = 0;
                obj->speed_y = 5;
                skipToLabel(obj, 12, true);
            }
        }
    }
}