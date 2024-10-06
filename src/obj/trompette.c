#include "obj/trompette.h"

INCLUDE_ASM("asm/nonmatchings/obj/trompette", trompetteWind);

/* 3A1CC 8015E9CC -O2 -msoft-float */
void DO_TRP_ATTAK(Obj *obj)
{
    u8 sub_etat;

    if (obj->timer != 0)
        obj->timer--;
    
    if (obj->main_etat == 0)
    {
        sub_etat = obj->sub_etat;
        if (
            (sub_etat == 2 && obj->anim_frame >= 10) ||
            sub_etat == 4
        )
            trompetteWind(obj, false);
        else if (
            (sub_etat == 6 && obj->anim_frame >= 10) ||
            sub_etat == 7
        )
            trompetteWind(obj, true);
    }
}
