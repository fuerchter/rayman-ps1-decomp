#include "obj/stonewoman.h"

/* 4E7DC 80172FDC -O2 -msoft-float */
u8 IS_STONEWOMAN_WAIT(Obj *obj)
{
    return
        obj->main_etat == 0 &&
        (obj->sub_etat == 0 || obj->sub_etat == 14 || obj->sub_etat == 8);
}

INCLUDE_ASM("asm/nonmatchings/obj/stonewoman", DO_STONEWOMAN_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/stonewoman", DO_NOMOVE_STONEWOMAN_COMMAND);
