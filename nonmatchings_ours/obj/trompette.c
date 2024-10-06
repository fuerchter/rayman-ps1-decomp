#include "obj/trompette.h"

/* matches, but clean up block with test_1? */
/*INCLUDE_ASM("asm/nonmatchings/obj/trompette", trompetteWind);*/

void trompetteWind(Obj *obj, u8 param_2)
{
    s16 trp_x; s16 trp_y; s16 trp_w; s16 trp_h;
    s16 test_1;
    s16 unk_1;

    obj->timer = 100;
    GET_ANIM_POS(obj, &trp_x, &trp_y, &trp_w, &trp_h);
    if (obj->flags & FLG(OBJ_FLIP_X))
    {
        test_1 = trp_x - 16;
        trp_x = test_1 + trp_w;
        /*test_1 = test_1 + sp24;*/
    }
    else
    {
        test_1 = trp_x - 76;
        trp_x = test_1 - trp_w;
        /*test_1 = test_1 - sp24;*/
    }
    /*sp20 = test_1;*/
    trp_w += 92;
    trp_h = ashr16(trp_h, 1) + 2;
    trp_y += ashr16(trp_h, 2);
    if ((s16) inter_box(ray_zdc_x, ray_zdc_y, ray_zdc_w, ray_zdc_h, trp_x, trp_y, trp_w, trp_h))
    {
        ashr16(ray_zdc_w, 1);
        ashr16(ray_zdc_h, 1);
        unk_1 = 7;
        if (
            (!(obj->flags & FLG(OBJ_FLIP_X)) && param_2 == false) ||
            (obj->flags & FLG(OBJ_FLIP_X) && param_2 == true)
        )
            unk_1 = -unk_1;
    }
    else
        unk_1 = 0;
    
    if (unk_1 != 0)
    {
        ray_wind_force += unk_1;
        if (ray.main_etat != 5)
            decalage_en_cours = ashl16(ray_wind_force, 8);
    }
}