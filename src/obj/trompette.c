#include "obj/trompette.h"

/* 3A004 8015E804 -O2 -msoft-float */
void trompetteWind(Obj *obj, u8 param_2)
{
    s16 trp_x; s16 trp_y; s16 trp_w; s16 trp_h;
    s16 unk_1;

    obj->timer = 100;
    GET_ANIM_POS(obj, &trp_x, &trp_y, &trp_w, &trp_h);
    if (obj->flags & FLG(OBJ_FLIP_X))
        trp_x -= 16 - trp_w;
    else
        trp_x -= 76 + trp_w;
    
    trp_w += 92;
    trp_h = ashr16(trp_h, 1) + 2;
    trp_y += ashr16(trp_h, 2);
    if (inter_box(ray_zdc_x, ray_zdc_y, ray_zdc_w, ray_zdc_h, trp_x, trp_y, trp_w, trp_h))
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
