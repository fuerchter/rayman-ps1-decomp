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

INCLUDE_ASM("asm/nonmatchings/obj/poing", RAY_PREPARE_FIST);

INCLUDE_ASM("asm/nonmatchings/obj/poing", RAY_GROW_FIST);

INCLUDE_ASM("asm/nonmatchings/obj/poing", fin_poing_follow);

INCLUDE_ASM("asm/nonmatchings/obj/poing", POING_FOLLOW);

INCLUDE_ASM("asm/nonmatchings/obj/poing", alter_fist_speed);

INCLUDE_ASM("asm/nonmatchings/obj/poing", switch_off_fist);

INCLUDE_ASM("asm/nonmatchings/obj/poing", DO_POING);

INCLUDE_ASM("asm/nonmatchings/obj/poing", allocatePoingBoum);
