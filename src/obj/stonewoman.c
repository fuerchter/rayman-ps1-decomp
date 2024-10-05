#include "obj/stonewoman.h"

/* 4E7DC 80172FDC -O2 -msoft-float */
u8 IS_STONEWOMAN_WAIT(Obj *obj)
{
    return
        obj->main_etat == 0 &&
        (obj->sub_etat == 0 || obj->sub_etat == 14 || obj->sub_etat == 8);
}

INCLUDE_ASM("asm/nonmatchings/obj/stonewoman", DO_STONEWOMAN_COMMAND);

/* 4ECB0 801734B0 -O2 -msoft-float */
void DO_NOMOVE_STONEWOMAN_COMMAND(Obj *obj)
{
    s32 prev_flip_x;

    if (IS_STONEWOMAN_WAIT(obj))
    {
        obj->speed_x = 0;
        prev_flip_x = obj->flags >> OBJ_FLIP_X & 1;
        calc_obj_dir(obj);
        if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
            skipToLabel(obj, 11, false);
        
        if (obj->timer == 0)
            DO_STONEWOMAN_TIR(obj);
        else
            obj->timer--;
    }
    else
    {
        DO_STONEWOMAN_TIR(obj);
        if (obj->main_etat == 0 && obj->sub_etat == 9)
            obj->timer = 250;
    }
    CALC_MOV_ON_BLOC(obj);
}
