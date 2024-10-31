#include "obj/bouee_joe_command.h"

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/bouee_joe_command", DO_BOUEE_JOE_COMMAND);
#else
/* matches, but test_1 */
/*INCLUDE_ASM("asm/nonmatchings/obj/bouee_joe_command", DO_BOUEE_JOE_COMMAND);*/

void DO_BOUEE_JOE_COMMAND(Obj *obj)
{
    s16 unk_1;
    s16 unk_2;
    s16 test_1 = 0x2b;
    
    obj->y_pos =
        GetY(obj->x_pos + obj->offset_bx - 12) +
        (obj->iframes_timer - test_1);
    
    if (ray.field20_0x36 == obj->id)
        obj->field23_0x3c = 13;
    else
        obj->field23_0x3c = 0;
    
    unk_1 = obj->iframes_timer;
    unk_2 = obj->field23_0x3c;
    if (unk_1 < unk_2)
        obj->iframes_timer++;
    else if (unk_1 > unk_2)
        obj->iframes_timer--;
}
#endif
