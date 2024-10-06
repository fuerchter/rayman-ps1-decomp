#include "obj/stonedog_command.h"

/* 49090 8016D890 -O2 -msoft-float */
void DO_STONEDOG_COMMAND(Obj *obj)
{
    if (obj->sub_etat == 3)
    {
        obj->speed_y = -8;
        obj->speed_x = 0;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
        return;
    }

    switch (obj->cmd)
    {
    case GO_SPEED:
        obj->speed_x = obj->iframes_timer;
        obj->speed_y = obj->field20_0x36;
        break;
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);
        
        SET_X_SPEED(obj);
        if (obj->main_etat == 0)
            set_main_and_sub_etat(obj, 1, 0);
        
        if (block_flags[calc_typ_travd(obj, 0U)] >> BLOCK_FULLY_SOLID & 1)
        {
            if (obj->cmd == GO_LEFT)
                obj->flags |= FLG(OBJ_FLIP_X);
            else
                obj->flags &= ~FLG(OBJ_FLIP_X);
            
            skipToLabel(obj, 2, true);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
        }
        else if (
            on_block_chdir(obj, obj->offset_bx, obj->offset_by - 16) &&
            test_allowed(obj, obj->offset_bx, obj->offset_by - 16) &&
            obj->type == TYPE_STONEDOG
        )
        {
            if (obj->cmd == GO_LEFT)
                obj->flags |= FLG(OBJ_FLIP_X);
            else
                obj->flags &= ~FLG(OBJ_FLIP_X);

            if (obj->main_etat == 2)
                skipToLabel(obj, 9, true);
            else
                skipToLabel(obj, 8, true);
            
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
        }
        if (
            obj->y_pos + obj->offset_hy < 0 ||
            block_flags[obj->btypes[3]] >> BLOCK_FLAG_4 & 1
        )
            obj->speed_y++;
        
        SET_X_SPEED(obj);
        if (obj->main_etat != 2)
            CALC_MOV_ON_BLOC(obj);
        else
        {
            if (obj->sub_etat == 1 || obj->sub_etat == 3)
                obj->flags =
                    (obj->flags & ~FLG(OBJ_FLIP_X)) |
                    (((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
        }
        break;
    default:
        break;
    }
}
