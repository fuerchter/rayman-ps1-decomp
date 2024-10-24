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

/* 47F1C 8016C71C -O2 -msoft-float */
void POING_FOLLOW(Obj *poing_obj)
{
    Obj *unk_obj = &level.objects[poing_obj->field20_0x36];

    unk_obj->speed_x = poing_obj->speed_x;
    unk_obj->speed_y = poing_obj->speed_y;
    if (!(ray.iframes_timer == -1 && unk_obj->flags & FLG(OBJ_ACTIVE)))
        fin_poing_follow(poing_obj, false);
}

INCLUDE_ASM("asm/nonmatchings/obj/poing", alter_fist_speed);

/* 48014 8016C814 -O2 -msoft-float */
void switch_off_fist(Obj *obj)
{
    poing.is_active = false;
    poing.is_boum = false;
    poing.charge = 5;
    poing.is_returning = false;
    obj->flags &= ~FLG(OBJ_ALIVE);
    obj->flags &= ~FLG(OBJ_ACTIVE);
    obj->sub_etat = obj->init_sub_etat;
    fin_poing_follow(obj, false);
}

INCLUDE_ASM("asm/nonmatchings/obj/poing", DO_POING);

/* 483C8 8016CBC8 -O2 -msoft-float */
void allocatePoingBoum(void)
{
    Obj *poing_obj;
    s16 poing_x; s16 poing_y; s16 poing_w; s16 poing_h;
    s16 boum_x; s16 boum_y; s16 boum_w; s16 boum_h;    
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    s16 nb_objs = level.nb_objects;
    
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_BOUM && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            poing_obj = &level.objects[poing_obj_id];
            GET_ANIM_POS(poing_obj, &poing_x, &poing_y, &poing_w, &poing_h);
            GET_ANIM_POS(cur_obj, &boum_x, &boum_y, &boum_w, &boum_h);
            cur_obj->anim_frame = 0;
            cur_obj->x_pos = poing_x - cur_obj->offset_bx;
            if (poing_obj->speed_x > 0)
                cur_obj->x_pos += poing_w;
            cur_obj->y_pos =
                poing_y + (poing_h >> 1) - ((cur_obj->offset_by + cur_obj->offset_hy) >> 1);
            calc_obj_pos(cur_obj);
            cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
            break;
        }
        cur_obj++;
        i++;
    }
}
