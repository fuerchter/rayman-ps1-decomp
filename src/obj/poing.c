#include "obj/poing.h"

/* 476F0 8016BEF0 -O2 -msoft-float */
void fist_U_turn(Obj *obj, u8 param_2)
{
    switch (obj->sub_etat)
    {
    case 1:
        set_sub_etat(obj, 2);
        break;
    case 3:
        set_sub_etat(obj, 4);
        break;
    case 5:
        set_sub_etat(obj, 6);
        break;
    case 8:
        set_sub_etat(obj, 9);
        break;
    case 10:
        set_sub_etat(obj, 11);
        break;
    case 12:
        set_sub_etat(obj, 13);
        break;
    }

    if (param_2)
        obj->anim_frame = 7;
}

/* 477D4 8016BFD4 -O2 -msoft-float */
void CALC_FIST_POS(void)
{
    Obj *obj = &level.objects[poing_obj_id];

    obj->screen_y_pos = (poing.field0_0x0 >> 4) - ymap;
    obj->screen_x_pos = obj->x_pos - xmap;
}

INCLUDE_ASM("asm/nonmatchings/obj/poing", RAY_THROW_FIST);

/* 47CFC 8016C4FC -O2 -msoft-float */
void RAY_PREPARE_FIST(void)
{
    ObjState *eta_main;
    u8 anim_spd;

    if (ray.eta[ray.main_etat][ray.sub_etat].flags & 2)
    {
        if (ray.main_etat == 2)
        {
            if (ray.speed_y > 0)
            {
                eta_main = ray.eta[ray.main_etat];
                anim_spd = eta_main[2].anim_speed;
            }
            else
            {
                eta_main = ray.eta[ray.main_etat];
                anim_spd = eta_main[0].anim_speed;
            }
            eta_main[13].anim_speed =
                eta_main[13].anim_speed & 0xf |
                anim_spd & 0xf0;
            
            poing.charge = 32;
            RAY_THROW_FIST();
            helico_time = -1;
            if (RayEvts.super_helico)
                button_released = 0;
        }
        else
        {
            RAY_STOP();
            set_sub_etat(&ray, 11);
            poing.is_charging = true;
            poing.charge = 5;
        }
    }
}

/* 47E1C 8016C61C -O2 -msoft-float */
void RAY_GROW_FIST(void)
{
    poing.charge++;
    MIN_2(poing.charge, 63);
}

/* 47E54 8016C654 -O2 -msoft-float */
void fin_poing_follow(Obj *poing_obj, u8 param_2)
{
    Obj *unk_obj;
    s16 ray_y;
    s16 unk_y;

    if (poing_obj->field20_0x36 != -1)
    {
        unk_obj = &level.objects[poing_obj->field20_0x36];
        unk_obj->speed_x = 0;
        unk_obj->speed_y = 0;
        poing_obj->field20_0x36 = -1;
        if (param_2 || !(poing_obj->flags & FLG(OBJ_ALIVE)))
        {
            unk_obj->x_pos = ray.x_pos + ray.offset_bx - unk_obj->offset_bx;
            ray_y = ray_zdc_y + (ray_zdc_h >> 1);
            unk_y = ((unk_obj->offset_by + unk_obj->offset_hy) >> 1) + 5;
            unk_obj->y_pos = ray_y - unk_y;
        }
        else
        {
            unk_obj->x_pos = unk_obj->init_x_pos;
            unk_obj->y_pos = unk_obj->init_y_pos;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/poing", POING_FOLLOW);

INCLUDE_ASM("asm/nonmatchings/obj/poing", alter_fist_speed);

INCLUDE_ASM("asm/nonmatchings/obj/poing", switch_off_fist);

INCLUDE_ASM("asm/nonmatchings/obj/poing", DO_POING);

INCLUDE_ASM("asm/nonmatchings/obj/poing", allocatePoingBoum);
