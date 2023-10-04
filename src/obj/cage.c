#include "obj/cage.h"

void DO_CAGE2(Obj *obj)
{
    obj->speed_x = 0;
    obj->speed_y = -8;
}

INCLUDE_ASM("asm/nonmatchings/obj/cage", DO_CAGE);