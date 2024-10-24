#include "poing.h"

/* matches, but the unk_1 thing? */
/*INCLUDE_ASM("asm/nonmatchings/obj/poing", RAY_THROW_FIST);*/

void RAY_THROW_FIST(void)
{
    s32 unk_1;
    s16 unk_2;
    Obj *poing_obj = &level.objects[poing_obj_id];
    
    if (ray.main_etat == 2 && (ray.sub_etat == 25 || ray.sub_etat == 26))
        set_sub_etat(&ray, 29);
    else if (ray.main_etat == 2 && (ray.sub_etat == 27 || ray.sub_etat == 28))
        set_sub_etat(&ray, 30);
    else if (!(ray.main_etat == 2 && (ray.sub_etat == 17 || ray.sub_etat == 18 || ray.sub_etat == 19)))
        set_sub_etat(&ray, 13);
    
    if (ray.main_etat == 0)
    {
        if (ray.flags & FLG(OBJ_FLIP_X))
            decalage_en_cours -= poing.charge * 0x10; /* TODO: fixed point? */
        else
            decalage_en_cours += poing.charge * 0x10;
    }
    poing.is_charging = false;
    poing.is_active = true;
    poing.is_boum = false;
    poing.is_returning = false;
    poing_obj->flags = (poing_obj->flags & ~FLG(OBJ_FLIP_X)) | (ray.flags & FLG(OBJ_FLIP_X));
    poing_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
    poing_obj->speed_y = 0;
    poing_obj->anim_frame = 0;
    poing_obj->field20_0x36 = -1;
    set_main_and_sub_etat(poing_obj, poing_obj->init_main_etat, poing_obj->init_sub_etat);
    poing_obj->anim_index = poing_obj->eta[poing_obj->main_etat][poing_obj->sub_etat].anim_index;
    poing_obj->x_pos = ray_zdc_x + (ray_zdc_w >> 1) - poing_obj->offset_bx;
    poing_obj->x_pos -= 5 * FLIP_X_SGN(&ray);
    poing.damage = ashr16(poing.charge, 4) + 1;

    switch (poing_obj->init_sub_etat)
    {
    case 12:
        poing.damage += 2;
    case 5:
        poing.speed_x = 11;
        break;
    case 10:
        poing.damage += 2;
    case 3:
        poing.speed_x = 8;
        break;
    case 8:
        poing.damage += 2;
    case 1:
        poing.speed_x = 5;
        break;
    }

    if (
        ray.flags & FLG(OBJ_FLIP_X) ?
            decalage_en_cours > 0 :
            decalage_en_cours < 0
    )
        poing.speed_x += MAX_1(__builtin_abs(ray.speed_x) - 5, 0);
    
    poing.speed_x = MIN_1(poing.speed_x, 16);
    
    if (poing_obj->flags & FLG(OBJ_FLIP_X))
    {
        poing_obj->x_pos += 11;
        poing_obj->speed_x = poing.speed_x;
    }
    else
    {
        poing_obj->x_pos -= 11;
        poing_obj->speed_x = -poing.speed_x;
    }
    unk_1 = -40; /* tried applying pattern from fin_poing_follow */
    poing.field4_0xa = (poing.charge * 130 / 64) - (poing.speed_x * 3 + unk_1);
    unk_2 = ashl16(poing.charge, 8);
    poing.charge = unk_2;
    poing.field1_0x4 = unk_2;
    poing.field4_0xa = unk_2 * poing.speed_x / poing.field4_0xa;
    poing_obj->y_pos = ray_zdc_y + (ray_zdc_h >> 1) - ((poing_obj->offset_by + poing_obj->offset_hy) >> 1);
    poing.field0_0x0 = ashl16(poing_obj->y_pos, 4);
    CALC_FIST_POS();
}
