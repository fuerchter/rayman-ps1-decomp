#include "obj/spider_395B0.h"

INCLUDE_ASM("asm/nonmatchings/obj/spider_395B0", allocateDard);

/* 39738 8015DF38 -O2 -msoft-float */
void DO_SPIDER_TIR(Obj *obj)
{
    DO_SPIDER_COMMAND(obj);
    if ((obj->main_etat == 0) && (obj->sub_etat == 3) && (obj->field24_0x3e == 0))
    {
        allocateDard(obj);
        obj->field24_0x3e = 1;
    }
}
