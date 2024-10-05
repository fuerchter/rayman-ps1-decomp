#include "obj/stonewoman.h"

/* score of 30 */
/*INCLUDE_ASM("asm/nonmatchings/obj/stonewoman", DO_STONEWOMAN_COMMAND);*/

void DO_STONEWOMAN_COMMAND(Obj *obj)
{
    s32 prev_flip_x;
    s16 diff_x; s16 diff_y;
    s16 unk_1;

    if (IS_STONEWOMAN_WAIT(obj))
    {
        obj->speed_x = 0;
        prev_flip_x = obj->flags >> OBJ_FLIP_X & 1;
        calc_obj_dir(obj);
        if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
            skipToLabel(obj, 11, false);
    }

    /* TODO: closest to a "proof" that this was macro? */
    if ((ray.x_pos + ray.offset_bx) - obj->x_pos - obj->offset_bx >= 0)
        diff_x = (ray.x_pos + ray.offset_bx) - obj->x_pos - obj->offset_bx;
    else
        diff_x = -((ray.x_pos + ray.offset_bx) - obj->x_pos - obj->offset_bx);

    if ((ray.y_pos + ray.offset_by) - obj->y_pos - obj->offset_by >= 0)
        diff_y = (ray.y_pos + ray.offset_by) - obj->y_pos - obj->offset_by;
    else
        diff_y = -((ray.y_pos + ray.offset_by) - obj->y_pos - obj->offset_by);
    
    switch (obj->main_etat)
    {
    case 1:
        break;
    case 2:
        break;
    default:
        if (obj->main_etat == 0 && obj->sub_etat == 11 && EOA(obj))
        {
            set_main_and_sub_etat(obj, 2, 3);
            obj->speed_y = -7;
            obj->gravity_value_1 = 0;
            obj->gravity_value_2 = 4;
            obj->y_pos -= 14;
            break;
        }
        unk_1 = 0;
        if (obj->detect_zone_flag != 0)
        {
            if (diff_x < 170 && diff_y < 38)
                obj->field56_0x69 = 1;
            
            if (IS_STONEWOMAN_WAIT(obj))
            {
                if (diff_x < 95 && diff_y < 50 && obj->timer == 0)
                {
                    unk_1 = 1;
                    obj->timer = 100;
                }
                else if (obj->field56_0x69 != 0 && obj->timer == 0)
                {
                    unk_1 = -1;
                    obj->field56_0x69 = 0;
                }
            }
        }
        if (obj->speed_x == 0)
            DO_STONEWOMAN_TIR(obj);
        break;
    }
    if (obj->timer != 0)
        obj->timer--;

    if (!(obj->speed_x == 0 && unk_1 == 0))
    {
        if (on_block_chdir(obj, (s16) obj->offset_bx, (s16) (obj->offset_by - 16)))
            skipToLabel(obj, 14, true);
        else
        {
            if (
                !((
                    !(block_flags[calc_typ_travd(obj, 0)] >> BLOCK_FULLY_SOLID & 1) &&
                    obj->x_pos + obj->offset_bx >= 32 && obj->x_pos + obj->offset_bx <= xmapmax + 268
                ) || obj->main_etat == 2)
            )
            {
                obj->x_pos -= obj->speed_x;
                if (obj->detect_zone_flag != 0)
                {
                    skipToLabel(obj, 7, true);
                    obj->anim_frame = 0;
                }
                else
                    skipToLabel(obj, 12, true);
                obj->speed_x = 0;
            }
            else if (!(obj->main_etat == 1 || obj->main_etat == 2))
            {
                if (unk_1 < 0)
                    skipToLabel(obj, 13, true);
                else
                    skipToLabel(obj, 17, true);                
            }
        }

    }

    SET_X_SPEED(obj);
    if (obj->main_etat != 2)
        CALC_MOV_ON_BLOC(obj);
}