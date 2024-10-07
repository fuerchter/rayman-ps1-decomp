#include "obj/big_clown.h"

/* 39CD8 8015E4D8 -O2 -msoft-float */
void DO_BIG_CLOWN_ATTAK(Obj *bc_obj)
{
    if (
        bc_obj->main_etat == 0 && bc_obj->sub_etat == 2 &&
        bc_obj->field24_0x3e == 0 && bc_obj->anim_frame > 15
    )
    {
        bc_obj->field24_0x3e = 1;
        screen_trembling = 1;

        if (ray.main_etat == 0 || ray.main_etat == 1)
            ray.field56_0x69 = 1;
        else if (ray.main_etat == 4 || ray.main_etat == 5)
        {
            ray.main_etat = 2;
            ray.sub_etat = 1;
        }
    }
    else if (bc_obj->main_etat == 0 && bc_obj->sub_etat == 11)
        bc_obj->field24_0x3e = 0;
    else if (bc_obj->main_etat == 0 && bc_obj->sub_etat == 22)
        skipToLabel(bc_obj, 6, true);
}
