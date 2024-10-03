#include "obj/pirate_guetteur.h"

/* 5C304 80180B04 -O2 -msoft-float */
void FUN_80180b04(Obj *obj, u8 param_2)
{
    if (param_2)
        obj->type = TYPE_PIRATE_GUETTEUR;
    else
        obj->type = TYPE_PIRATE_GUETTEUR2;
    
    obj->zdc = type_zdc[obj->type];
}

/* 5C33C 80180B3C -O2 -msoft-float */
void guetteurFollowsShip(Obj *obj)
{
    if (bateau_obj_id != -1)
        snapToSprite(obj, &level.objects[bateau_obj_id], 1, -51, -63);
    else
    {
        obj->speed_y = 0;
        obj->speed_x = 0;
    }
}

/* 5C3A0 80180BA0 -O2 -msoft-float */
void DO_ONE_PAR_COMMAND(Obj *obj)
{
    s32 flip_x;
    u8 flag_set;

    if (obj->timer != 0)
        obj->timer--;

    flip_x = obj->flags >> OBJ_FLIP_X & 1;
    if (obj->type == TYPE_PIRATE_GUETTEUR2)
        calc_obj_dir(obj);
    else
        guetteurFollowsShip(obj);
    
    switch (obj->main_etat * 0x100 + obj->sub_etat)
    {
    case 0x3:
        obj->speed_y = -8;
        obj->speed_x = 0;
        break;
    case 0x2:
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (flip_x << OBJ_FLIP_X);
    case 0x5:
    case 0xD:
        obj->timer = 50;
        DO_PAR_TIR(obj);
        break;
    case 0x0:
    case 0x11:
        if (poing.is_active)
            set_sub_etat(obj, 15);
        break;
    case 0x8:
    case 0xB:
    case 0x14:    
        if (poing.is_active)
            set_sub_etat(obj, 18);
        break;
    case 0x10:
        if (!poing.is_active)
            set_sub_etat(obj, 17);
        break;
    case 0x13:
        if (!poing.is_active)
            set_sub_etat(obj, 20);
        break;
    case 0x6:
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (flip_x << OBJ_FLIP_X);
        flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
        if(
            ((flag_set && obj->anim_frame == 0) ||
            (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
        )
        {
            FUN_80180b04(obj, 0);
            obj->speed_x = 0;
        }
        break;
    case 0x9:
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (flip_x << OBJ_FLIP_X);
        flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
        if(
            ((flag_set && obj->anim_frame == 0) ||
            (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
        )
        {
            SET_X_SPEED(obj);
            obj->speed_y = -3;
        }
        break;
    case 0x200:
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (flip_x << OBJ_FLIP_X);
        SET_X_SPEED(obj);
        break;
    case 0xA:
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (flip_x << OBJ_FLIP_X);
        break;
    case 0x1:
        obj->iframes_timer = 100;
        break;
    }

    if (obj->iframes_timer != 0)
        obj->iframes_timer--;
}

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", hasGuetteurABomb);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", allocatePirateGuetteurBomb);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", DO_PAR_TIR);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", DO_PAR_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", PAR_REACT_TO_RAY_IN_ZONE);
