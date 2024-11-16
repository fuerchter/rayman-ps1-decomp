#include "obj/bouee_joe_command.h"

/* 504E8 80174CE8 -O2 -msoft-float */
#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/bouee_joe_command", DO_BOUEE_JOE_COMMAND);
#else
/* unk_1? */
void DO_BOUEE_JOE_COMMAND(Obj *obj)
{
    s16 unk_1 = 43;

    obj->y_pos =
        obj->iframes_timer - unk_1 +
        GetY(obj->x_pos + obj->offset_bx - 12);

    if (ray.field20_0x36 == obj->id)
        obj->field23_0x3c = 13;
    else
        obj->field23_0x3c = 0;

    if (obj->iframes_timer < obj->field23_0x3c)
        obj->iframes_timer++;
    else if (obj->iframes_timer > obj->field23_0x3c)
        obj->iframes_timer--;
}
#endif
