#include "obj/stonebomb_command.h"

/* 4995C 8016E15C -O2 -msoft-float */
void DO_ONE_STONECHIP_COMMAND(Obj *obj)
{
    switch (obj->cmd)
    {
    case GO_LEFT:
        obj->flags &= ~FLG(OBJ_FLIP_X);
        SET_X_SPEED(obj);
        switch (obj->sub_etat)
        {
        case 9:
            obj->speed_y = obj->speed_x;
            break;
        case 11:
            obj->speed_y = 0;
            break;
        case 13:
            obj->speed_y = -obj->speed_x;
            break;
        }
        break;
    case GO_RIGHT:
        obj->flags |= FLG(OBJ_FLIP_X);
        SET_X_SPEED(obj);
        obj->flags &= ~FLG(OBJ_FLIP_X);
        switch (obj->sub_etat)
        {
        case 10:
            obj->speed_y = -obj->speed_x;
            break;
        case 12:
            obj->speed_y = 0;
            break;
        case 14:
            obj->speed_y = obj->speed_x;
            break;
        }
        break;
    default:
        obj->speed_x = 0;
        obj->speed_y = 0;
        break;
    }
}

/* 49A74 8016E274 -O2 -msoft-float */
void DO_STONEBOMB_COMMAND(Obj *obj)
{
    u8 timer_0 = false;

    if (obj->type == TYPE_STONEBOMB)
    {
        if (obj->timer == 0)
        {
            DO_STONE_EXPLOSION(obj);
            timer_0 = true;
        }
        else
        {
            if (horloge[3] == 0)
                obj->timer--;

            if (obj->timer == 0)
            {
                DO_STONE_EXPLOSION(obj);
                timer_0 = true;
            }
        }
    }

    if (!timer_0)
    {
        if (block_flags[calc_typ_travd(obj, false)] >> BLOCK_FULLY_SOLID & 1)
            DO_STONE_EXPLOSION(obj);
        else
        {
            if (obj->main_etat == 2 && obj->sub_etat == 1)
                Projectil_to_RM(obj, &obj->speed_x, &obj->speed_y, 30, 3);
        }
    }
}
