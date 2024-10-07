#include "obj/petit_couteau_command.h"

/* 50C2C 8017542C -O2 -msoft-float */
void DO_PETIT_COUTEAU_COMMAND(Obj *obj)
{
    if (obj->hit_points < 3)
        obj->anim_frame = obj->hit_points -1;
    else
        obj->anim_frame = obj->hit_points - 3;
}
