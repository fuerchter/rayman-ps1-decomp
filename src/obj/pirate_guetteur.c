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

/* 5C820 80181020 -O2 -msoft-float */
s32 hasGuetteurABomb(Obj *obj, s32 param_2)
{
    Animation *anim;
    AnimationLayer *unk_2;
    s16 unk_1 = param_2;

    if (obj->eta[obj->main_etat][obj->sub_etat].flags & 4)
    {
        anim = &obj->animations[obj->anim_index];
        unk_1 = obj->type != TYPE_PIRATE_GUETTEUR ? 5 : 0;
        unk_2 = &anim->layers[(anim->layers_count & 0x3fff) * obj->anim_frame];
        if (unk_2[unk_1].sprite == 0)
            unk_1 = -1;
    }

    return unk_1;
}

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", allocatePirateGuetteurBomb);

/* 5CC64 80181464 -O2 -msoft-float */
void DO_PAR_TIR(Obj *obj)
{
    u8 sub_etat;

    if (obj->main_etat == 0)
    {
        sub_etat = obj->sub_etat;
        if (
            !(sub_etat == 2 && obj->anim_frame > 20) &&
            !(sub_etat == 5 && obj->anim_frame > 17) &&
            !(sub_etat == 13 && obj->anim_frame > 1)
        )
            obj->field24_0x3e = 0;
        
        if (obj->field24_0x3e == 0)
        {
            sub_etat = obj->sub_etat;
            if (
                (sub_etat == 2 && obj->anim_frame == 21) ||
                (sub_etat == 5 && obj->anim_frame == 18) ||
                (sub_etat == 13 && obj->anim_frame == 2)
            )
            {
                sub_etat = obj->sub_etat;
                if (horloge[obj->eta[obj->main_etat][sub_etat].anim_speed & 0xf] == 0)
                {
                    if (sub_etat == 5)
                        allocatePirateGuetteurBomb(obj, 2, 1, 40);
                    else if (sub_etat == 2)
                        allocatePirateGuetteurBomb(obj, -1, 1, 40);
                    else
                    {
                        allocatePirateGuetteurBomb(obj, -3, 1, 100);
                        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
                        allocatePirateGuetteurBomb(obj, -3, 1, 100);
                        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
                        allocatePirateGuetteurBomb(obj, -3, 1, 100);
                        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
                        allocatePirateGuetteurBomb(obj, -3, 1, 100);
                        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
                    }
                    obj->field24_0x3e = 1;
                }
            }
        }
    }
    else
        obj->field24_0x3e = 0;
}

/* 5CEBC 801816BC -O2 -msoft-float */
void DO_PAR_POING_COLLISION(Obj *obj, s16 param_2)
{
    u8 eta_flags = obj->eta[obj->main_etat][obj->sub_etat].flags;
    
    if (
        eta_flags & 1 && obj->iframes_timer == 0 &&
        (obj->type == TYPE_PIRATE_GUETTEUR || param_2 == 3)
    )
    {
        if (obj->type == TYPE_PIRATE_GUETTEUR2 && eta_flags & 4)
            allocatePirateGuetteurBomb(obj, 1, 0, 20);

        poing.damage = true;
        obj_hurt(obj);
        
        if (obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 3);
        else
        {
            if (obj->type == TYPE_PIRATE_GUETTEUR)
            {
                if (obj->init_hit_points - obj->hit_points > 2)
                {
                    set_sub_etat(obj, 6);
                    if (bateau_obj_id != -1)
                    {
                        skipOneCommand(&level.objects[bateau_obj_id]);
                        level.objects[bateau_obj_id].nb_cmd = 0;
                    }
                }
                else
                    set_sub_etat(obj, 12);
            }
            else
                set_main_and_sub_etat(obj, 0, 1);
        }

    }
}

/* 5D044 80181844 -O2 -msoft-float */
void PAR_REACT_TO_RAY_IN_ZONE(Obj *obj)
{
    u8 sub_etat;

    if (obj->timer == 0 && obj->main_etat == 0)
    {
        sub_etat = obj->sub_etat;
        if (sub_etat == 11)
            set_sub_etat(obj, 2);
        else if (sub_etat == 0)
        {
            obj->field12_0x26 = (obj->x_pos + obj->offset_bx) - (ray.x_pos + ray.offset_bx);
            if (__builtin_abs(obj->field12_0x26) > obj->detect_zone + 16)
                set_sub_etat(obj, 8);
            else
                set_sub_etat(obj, 9);
        }
        else if (sub_etat == 4)
            set_sub_etat(obj, 5);
    }
}
