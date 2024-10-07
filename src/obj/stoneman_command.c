#include "obj/stoneman_command.h"

/* 48F74 8016D774 -O2 -msoft-float */
void DO_STONEMAN_COMMAND(Obj *obj)
{
    switch (obj->cmd)
    {
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);

        SET_X_SPEED(obj);
        if (obj->main_etat == 0)
            set_main_and_sub_etat(obj, 1, 0);
        
        if (block_flags[calc_typ_travd(obj, false)] >> BLOCK_FULLY_SOLID & 1)
        {
            if (obj->cmd == GO_LEFT)
            {
                obj->flags = obj->flags | FLG(OBJ_FLIP_X);
                skipToLabel(obj, 5, true);
            }
            else
            {
                obj->flags = obj->flags & ~FLG(OBJ_FLIP_X);
                skipToLabel(obj, 4, true);
            }
            
            obj->x_pos -= obj->speed_x;
        }
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
        break;
    default:
        break;
    }
}
