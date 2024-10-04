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

/* 78DC0 8019D5C0 -O2 -msoft-float */
void DO_ONE_NGW_COMMAND(Obj *obj)
{
    s32 prev_flip_x = obj->flags >> OBJ_FLIP_X & 1;
    
    calc_obj_dir(obj);
    switch (obj->main_etat * 0x100 + obj->sub_etat)
    {
    case 0x3:
        obj->speed_y = -8;
        obj->speed_x = 0;
        break;
    case 0x205:
    case 0x5:
        obj->speed_x = 0;
        break;
    case 0x0:
        obj->speed_x = 0;
        if (!poing.is_active)
        {
            if (obj->field56_0x69 == 1)
            {
                if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
                    set_sub_etat(obj, 6);
                else
                    set_main_and_sub_etat(obj, 1, 0);
            }
            else
                obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        }
        else
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x2:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        if (!poing.is_active)
            DO_NGW_TIR(obj);
        else
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x100:
        if (!poing.is_active)
        {
            if (obj->field56_0x69 == 1)
            {
                if (
                    (block_flags[calc_typ_travd(obj, 1)] >> BLOCK_FULLY_SOLID & 1) ||
                    !((u8) block_flags[
                        PS1_BTYPAbsPos(obj->x_pos + obj->offset_bx + obj->speed_x, obj->y_pos + obj->offset_by)
                    ] >> BLOCK_SOLID & 1)
                )
                    if (prev_flip_x == (obj->flags >> OBJ_FLIP_X & 1))
                        prev_flip_x = (obj->flags >> OBJ_FLIP_X ^ 1) & 1;
                
                if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
                    set_main_and_sub_etat(obj, 0, 6);
                
                SET_X_SPEED(obj);
                CALC_MOV_ON_BLOC(obj);
            }
            else
                set_main_and_sub_etat(obj, 0, 0);
        }
        else
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x207:
        ngaweTriesToGrabShip(obj);
        break;
    case 0x202:
    case 0x203:
    case 0x204:
        ngaweFollowsShip(obj);
        break;
    case 0x6:
    case 0x4:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        if (poing.is_active)
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x8:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        if (!poing.is_active)
            set_sub_etat(obj, 4);
        break;
    case 0x7:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        break;
    case 0x1:
        obj->timer = 100;
        obj->speed_x = 0;
        break;
    }

    if (obj->timer != 0)
        obj->timer--;
}

INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", DO_NGW_POING_COLLISION);
