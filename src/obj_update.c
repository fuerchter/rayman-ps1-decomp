#include "obj_update.h"

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_PESANTEUR);

/* 2C45C 80150C5C -O2 -msoft-float */
void FUN_80150c5c(Obj *obj, u8 param_2)
{
    s16 count = obj->animations[obj->anim_index].frames_count - 1;
    s32 count_capped;

    if (obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10)
    {
        /* duplicate... */
        count_capped = count;
        MIN_3(count_capped, param_2);
        obj->anim_frame = count - count_capped + 1;
    }
    else
    {
        count_capped = count;
        MIN_3(count_capped, param_2);
        obj->anim_frame = count_capped;
    }
}

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_update", DO_ANIM);
#else
void DO_ANIM(Obj *obj)
{
    Animation *new_anim;
    u8 new_frame;
    s32 changed;
    u8 old_ind = obj->anim_index;
    s16 old_frame = obj->anim_frame;
    Animation *old_anim = &obj->animations[old_ind];
    ObjState *eta = &obj->eta[obj->main_etat][obj->sub_etat];
    s32 anim_speed = eta->anim_speed & 0xF;
    
    if (anim_speed != 0 && horloge[anim_speed] == 0)
    {
        if (!(eta->flags >> 4 & 1))
            obj->anim_frame++;
        else
            obj->anim_frame--;
    }
    obj->anim_index = eta->anim_index;
    new_anim = &obj->animations[obj->anim_index];

    switch (obj->change_anim_mode)
    {
    case ANIMMODE_RESET_IF_NEW:
        if (obj->anim_index != old_ind)
        {
            if (!(eta->flags & 0x10))
                obj->anim_frame = 0;
            else
                obj->anim_frame = new_anim->frames_count - 1;
        }
        PlaySnd(obj->eta[obj->main_etat][obj->sub_etat].sound, obj->id);
        break;
    case ANIMMODE_RESET:
        if (!(eta->flags & 0x10))
            obj->anim_frame = 0;
        else
            obj->anim_frame = new_anim->frames_count - 1;
        PlaySnd(obj->eta[obj->main_etat][obj->sub_etat].sound, obj->id);
        break;
    }

    if (obj->anim_frame >= new_anim->frames_count || obj->anim_frame == 0xFF)
    {
        obj->sub_etat = eta->next_sub_etat;
        obj->main_etat = eta->next_main_etat;
        eta = &obj->eta[obj->main_etat][obj->sub_etat];

        obj->anim_index = eta->anim_index;
        new_anim = &obj->animations[obj->anim_index];
        if (
            (
                (
                    obj->type == TYPE_RAYMAN &&
                    ray_old_sub_etat == 8 && (ray_old_main_etat == 2 || ray_old_main_etat == 6) &&
                    obj->sub_etat != ray_old_sub_etat
                ) ||
                (
                    ray_old_sub_etat == 61 && ray_old_main_etat == 0 &&
                    obj->sub_etat != ray_old_sub_etat
                )
            ) && ray.iframes_timer > 60
        )
            ray.iframes_timer = 60;
        
        if (eta->flags & 0x10)
            new_frame = new_anim->frames_count - 1;
        else
            new_frame = 0;
        obj->anim_frame = new_frame;
        PlaySnd(obj->eta[obj->main_etat][obj->sub_etat].sound, obj->id);
    }
    
    obj->change_anim_mode = ANIMMODE_NONE;
    if (obj->flags & FLG(OBJ_FOLLOW_ENABLED))
        CALC_FOLLOW_SPRITE_SPEED(obj, new_anim, old_anim, old_frame);

    changed = (old_frame != obj->anim_frame || old_ind != obj->anim_index);
    obj->flags = (obj->flags & ~FLG(OBJ_FLAG_A)) | (changed << OBJ_FLAG_A);

    __asm__("nop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj_update", prof_in_bloc);

INCLUDE_ASM("asm/nonmatchings/obj_update", do_boing);

INCLUDE_ASM("asm/nonmatchings/obj_update", underSlope);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_STONEBOMB_REBOND);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_THROWN_BOMB_REBOND);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_FRUIT_REBOND);

INCLUDE_ASM("asm/nonmatchings/obj_update", Drop_Atter);

INCLUDE_ASM("asm/nonmatchings/obj_update", BadGuyAtter);

INCLUDE_ASM("asm/nonmatchings/obj_update", MiteAtter);

INCLUDE_ASM("asm/nonmatchings/obj_update", Clown_Music_Atter);

INCLUDE_ASM("asm/nonmatchings/obj_update", LidolPinkAtter);

INCLUDE_ASM("asm/nonmatchings/obj_update", stoneDogAtter);

INCLUDE_ASM("asm/nonmatchings/obj_update", stoneDogBounces);

INCLUDE_ASM("asm/nonmatchings/obj_update", Spider_Atter);

INCLUDE_ASM("asm/nonmatchings/obj_update", trompetteAtter);

INCLUDE_ASM("asm/nonmatchings/obj_update", NormalAtter);

INCLUDE_ASM("asm/nonmatchings/obj_update", OBJ_IN_THE_AIR);

INCLUDE_ASM("asm/nonmatchings/obj_update", test_fall_in_water);

INCLUDE_ASM("asm/nonmatchings/obj_update", MOVE_OBJECT);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_RAY_IN_ZONE);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_ONE_OBJECT);

INCLUDE_ASM("asm/nonmatchings/obj_update", fptr_init);

INCLUDE_ASM("asm/nonmatchings/obj_update", build_active_table);

INCLUDE_ASM("asm/nonmatchings/obj_update", Add_One_RAY_lives);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_CLING_ANIMS);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_OBJECTS_ANIMS);

INCLUDE_ASM("asm/nonmatchings/obj_update", DO_OBJECTS);

INCLUDE_ASM("asm/nonmatchings/obj_update", MOVE_OBJECTS);

INCLUDE_ASM("asm/nonmatchings/obj_update", RECALE_ALL_OBJECTS);
