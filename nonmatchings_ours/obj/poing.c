#include "poing.h"

/* matches, but */
/*INCLUDE_ASM("asm/nonmatchings/obj/poing", RAY_THROW_FIST);*/

void RAY_THROW_FIST(void)
{
    Obj *temp_a0;
    Obj *temp_s1;
    s16 temp_a0_3;
    s16 temp_v0_1;
    s16 temp_v0_3;
    s16 var_v0;
    s16 var_v0_3;
    s16 var_v1;
    s16 var_v1_3;
    s32 temp_a0_2;
    s32 var_a2;
    s32 var_v1_2;
    u16 var_v0_2;
    u8 temp_v0_2;

    temp_s1 = &level.objects[poing_obj_id];
    if (ray.main_etat == 2)
    {
        do { } while (0); /* TODO: how to replace this? */
        if (ray.sub_etat == 25 || ray.sub_etat == 26)
        {
            set_sub_etat(&ray, 0x1DU);
        }
        else if (ray.sub_etat == 27 || ray.sub_etat == 28)
        {
            set_sub_etat(&ray, 0x1EU);
        }
        else if (ray.sub_etat != 17 && ray.sub_etat != 18 && (ray.sub_etat != 19))
        {
            goto block_7;
        }
    }
    else
    {
block_7:
        set_sub_etat(&ray, 0x0DU);
    }
    
    if (ray.main_etat == 0)
    {
        if (ray.flags & 0x4000)
        {
            decalage_en_cours = decalage_en_cours - (poing.charge * 0x10);
        }
        else
        {
            decalage_en_cours = decalage_en_cours + (poing.charge * 0x10);
        }
    }
    poing.is_charging = 0;
    poing.is_active = 1;
    poing.is_boum = 0;
    poing.is_returning = 0;
    temp_s1->flags = (temp_s1->flags & ~0x4000) | (ray.flags & 0x4000) | 0xC00;
    temp_s1->speed_y = 0;
    temp_s1->anim_frame = 0;
    temp_s1->field20_0x36 = -1;
    set_main_and_sub_etat(temp_s1, temp_s1->init_main_etat, temp_s1->init_sub_etat);
    temp_s1->anim_index = temp_s1->eta[temp_s1->main_etat][temp_s1->sub_etat].anim_index;

    temp_s1->x_pos = ray_zdc_x + (ray_zdc_w >> 1) - temp_s1->offset_bx;
    temp_s1->x_pos += ray.flags & 0x4000 ? -5 : 5;
    
    poing.damage = ashr16(poing.charge, 4U) + 1;
    temp_v0_2 = temp_s1->init_sub_etat;
    switch (temp_v0_2)
    {
    case 12:
        poing.damage += 2;
        
    case 5:
        var_v0_2 = 0x000B;
        poing.speed_x = var_v0_2;
        break;
    case 10:
        poing.damage += 2;
        
    case 3:
        var_v0_2 = 8;
        poing.speed_x = var_v0_2;
        break;
    case 8:
        poing.damage += 2;
        
    case 1:
        var_v0_2 = 5;
        poing.speed_x = var_v0_2;
        break;
    }

    if (
        (ray.flags & 0x4000 && decalage_en_cours > 0) ||
        (!(ray.flags & 0x4000) && decalage_en_cours < 0)
    )
    {
        var_v1_2 = __builtin_abs(ray.speed_x) - 5;
        poing.speed_x += var_v1_2 < 0 ? 0 : var_v1_2;
    }
    poing.speed_x = poing.speed_x > 16 ? 16 : poing.speed_x;
    
    if (temp_s1->flags & 0x4000)
    {
        temp_s1->x_pos = temp_s1->x_pos + 0xB;
        temp_s1->speed_x = poing.speed_x;
    }
    else
    {
        temp_s1->x_pos = temp_s1->x_pos - 0xB;
        temp_s1->speed_x = -poing.speed_x;
    }
    temp_a0_2 = -0x28; /* tried applying pattern from fin_poing_follow */
    poing.field4_0xa = (poing.charge * 130 / 64) - ((poing.speed_x * 3) + temp_a0_2);
    temp_v0_3 = ashl16(poing.charge, 8U);
    poing.charge = temp_v0_3;
    poing.field1_0x4 = temp_v0_3;
    poing.field4_0xa = (temp_v0_3 * poing.speed_x / poing.field4_0xa);
    temp_s1->y_pos = ray_zdc_y + (ray_zdc_h >> 1) - ((temp_s1->offset_by + temp_s1->offset_hy) >> 1);
    poing.field0_0x0 = ashl16(temp_s1->y_pos, 4U);
    CALC_FIST_POS();
}