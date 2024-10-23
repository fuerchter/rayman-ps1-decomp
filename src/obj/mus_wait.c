#include "obj/mus_wait.h"

/* 50AC4 801752C4 -O2 -msoft-float */
void DO_MUSICIEN(Obj *obj)
{
    if (
        obj->main_etat == 0 && obj->sub_etat == 4 &&
        EOA(obj) && !(finBosslevel.helped_musician)
    )
    {
        finBosslevel.helped_musician = true;
        allocateSupHelico(&level.objects[Mus_obj_id]);
        Vignet_To_Display = 1;
    }
}
