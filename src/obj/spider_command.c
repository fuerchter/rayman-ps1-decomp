#include "obj/spider_command.h"

/* 48D74 8016D574 -O2 -msoft-float */
void DO_SPIDER_COMMAND(Obj *obj)
{
    if (obj->sub_etat == 7)
    {
        obj->speed_y = -8;
        obj->speed_x = 0;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
        return;
    }

    if ((obj->main_etat == 0) && (obj->sub_etat == 0))
        obj->field24_0x3e = 0;

    switch (obj->cmd)
    {
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);
        
        SET_X_SPEED(obj);
        obj->field23_0x3c = 1;
        if (obj->main_etat == 0)
            set_main_and_sub_etat(obj, 1, 0);
        
        if (obj->main_etat == 1)
        {
            if (block_flags[calc_typ_travd(obj, false)] & 1)
            {
                if (obj->cmd == GO_LEFT)
                {
                    obj->flags = obj->flags | FLG(OBJ_FLIP_X);
                    skipToLabel(obj, 2, true);
                }
                else
                {
                    obj->flags = obj->flags & ~FLG(OBJ_FLIP_X);
                    skipToLabel(obj, 0, true);
                }
            }
            SET_X_SPEED(obj);
            CALC_MOV_ON_BLOC(obj);
        }
        break;
    case GO_WAIT:
        switch (obj->main_etat)
        {
        case 0:
            if (obj->sub_etat == 4)
                obj->field24_0x3e = 0;
            
            if (obj->sub_etat == 8)
                TEST_FIN_BLOC(obj);
            break;
        case 1:
            if (!(block_flags[calc_typ_travd(obj, false)] >> BLOCK_FULLY_SOLID & 1))
                SET_X_SPEED(obj);
            else
                obj->speed_x = 0;
            
            CALC_MOV_ON_BLOC(obj);
        }
        break;
    }
}
