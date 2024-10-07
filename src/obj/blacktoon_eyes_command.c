#include "obj/blacktoon_eyes_command.h"

/* 50C60 80175460 -O2 -msoft-float */
void DO_BLKTOON_EYES_CMD(Obj *obj)
{
    s16 prev_spd_x = obj->speed_x;
    
    SET_X_SPEED(obj);
    if (prev_spd_x * obj->speed_x < 0)
    {
        obj->speed_x = prev_spd_x;
        obj->flags =
            (obj->flags & ~FLG(OBJ_FLIP_X)) |
            (((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
    }
}
