#include "obj/pirate_ngawe.h"

/* 78988 8019D188 -O2 -msoft-float */
void ngaweFollowsShip(Obj *obj)
{
    if (bateau_obj_id != -1)
        snapToSprite(obj, &level.objects[bateau_obj_id], 2, 21, -51);
}

/* 789DC 8019D1DC -O2 -msoft-float */
void ngaweTriesToGrabShip(Obj *obj)
{
    s16 ship_x; s16 ship_y; s16 ship_w; s16 ship_h;

    if (bateau_obj_id != -1)
    {
        GET_SPRITE_POS(&level.objects[bateau_obj_id], 2, &ship_x, &ship_y, &ship_w, &ship_h);
        obj->x_pos = ship_x + 21;
        ship_h = ship_y - 67;
        if ((obj->y_pos >= ship_h - obj->speed_y) && (obj->y_pos <= ship_h + obj->speed_y))
            set_main_and_sub_etat(obj, 2, 2);
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", allocatePirateNgaweRing);

/* 78CA4 8019D4A4 -O2 -msoft-float */
void DO_NGW_TIR(Obj *obj)
{
    if (obj->anim_frame < 26)
        obj->field24_0x3e = 0;
    
    if (
        obj->field24_0x3e == 0 && obj->anim_frame == 26 &&
        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
    )
    {
        allocatePirateNgaweRing(obj, 0, 1);
        obj->field24_0x3e = 1;
    }
}

/* 78D58 8019D558 -O2 -msoft-float */
void NGW_REACT_TO_RAY_IN_ZONE(Obj *obj)
{
    if (
        (
            (obj->main_etat == 0 && obj->sub_etat == 0) ||
            (obj->main_etat == 1 && obj->sub_etat == 0)
        ) && obj->field56_0x69 != 0
    )
        set_main_and_sub_etat(obj, 0, 2);
}

INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", DO_ONE_NGW_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", DO_NGW_POING_COLLISION);
