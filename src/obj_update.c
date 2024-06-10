#include "obj_update.h"

extern u8 gerbe; /* bool? */

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

/* 2C50C 80150D0C -O2 -msoft-float */
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

/* 2C89C 8015109C -O2 -msoft-float */
s16 prof_in_bloc(Obj *obj)
{
    s32 y = obj->y_pos + obj->offset_by;
    return y - (y / 16 * 16);
}

/* 2C8D0 801510D0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_update", do_boing);
#else
void do_boing(Obj *obj, u8 main_etat, u8 sub_etat)
{
  if (obj->speed_y < 2)
  {
    obj->speed_y = 0;
    set_main_and_sub_etat(obj, main_etat, sub_etat);
    if (main_etat != 2)
      recale_position(obj);
  }
  else
  {
    if (horloge[2] == 0)
    {
        switch(obj->btypes[0])
        {
        case BTYP_NONE:
            break;
        case BTYP_SOLID_RIGHT_45:
        case BTYP_SLIPPERY_RIGHT_45:
            obj->speed_y = 1 - (obj->speed_y >> 1);
            obj->speed_x -= 2;
            break;
        case BTYP_SOLID_LEFT_45:
        case BTYP_SLIPPERY_LEFT_45:
            obj->speed_y = 1 - (obj->speed_y >> 1);
            obj->speed_x += 2;
            break;
        case BTYP_SOLID_RIGHT1_30:
        case BTYP_SOLID_RIGHT2_30:
        case BTYP_SLIPPERY_RIGHT1_30:
        case BTYP_SLIPPERY_RIGHT2_30:
            obj->speed_y = 1 - ((obj->speed_y + 1) >> 1);
            obj->speed_x--;
            break;
        case BTYP_SOLID_LEFT1_30:
        case BTYP_SOLID_LEFT2_30:
        case BTYP_SLIPPERY_LEFT1_30:
        case BTYP_SLIPPERY_LEFT2_30:
            obj->speed_y = 1 - ((obj->speed_y + 1) >> 1);
            obj->speed_x++;
            break;
        case BTYP_SOLID_PASSTHROUGH:
        case BTYP_SOLID:
        case BTYP_SLIPPERY:
            obj->speed_y = -((obj->speed_y + 1) >> 1);
            break;
        case BTYP_RESSORT:
            obj->speed_y = -((obj->speed_y + 3) >> 1);
            break;
        }
    }

    if (obj->speed_y < 0)
        set_sub_etat(obj, 0);
  }

  __asm__("nop");
}
#endif

/* 2CA58 80151258 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_update", underSlope);
#else
u8 underSlope(Obj *obj)
{
    u8 res = 0;
    if (block_flags[obj->btypes[0]] & FLG(BLOCK_FULLY_SOLID))
        res = block_flags[obj->btypes[3]] >> BLOCK_SLOPE & 1;

    __asm__("nop\nnop");
    return res;
}
#endif

/* 2CAAC 801512AC -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_update", DO_STONEBOMB_REBOND);
#else
void DO_STONEBOMB_REBOND(Obj *obj)
{
    s16 new_spd_x; s16 new_spd_y;
    ObjType obj_type = obj->type;
    
    if (obj_type == TYPE_STONEBOMB2)
    {
        new_spd_x = 32;
        new_spd_y = -4;
    }
    else if (obj_type == TYPE_STONEBOMB3)
    {
        new_spd_x = 48;
        new_spd_y = -6;
    }

    if (underSlope(obj))
        obj->btypes[0] = obj->btypes[3];

    switch (obj->btypes[0])
    {
    case BTYP_SOLID_LEFT1_30:
    case BTYP_SOLID_LEFT2_30:
    case BTYP_SLIPPERY_LEFT1_30:
    case BTYP_SLIPPERY_LEFT2_30:
        obj->speed_y = new_spd_y;
        obj->speed_x = new_spd_x;
        break;
    case BTYP_SOLID_RIGHT1_30:
    case BTYP_SOLID_RIGHT2_30:
    case BTYP_SLIPPERY_RIGHT1_30:
    case BTYP_SLIPPERY_RIGHT2_30:
        obj->speed_y = new_spd_y;
        obj->speed_x = -new_spd_x;
        break;
    case BTYP_SOLID_LEFT_45:
    case BTYP_SLIPPERY_LEFT_45:
        obj->speed_y = new_spd_y + 2;
        obj->speed_x = new_spd_x + 16;
        break;
    case BTYP_SOLID_RIGHT_45:
    case BTYP_SLIPPERY_RIGHT_45:
        obj->speed_y = new_spd_y + 2;
        obj->speed_x = -16 - new_spd_x;
        break;
    case BTYP_SOLID_PASSTHROUGH:
    case BTYP_SOLID:
    case BTYP_SLIPPERY:
        obj->speed_y = new_spd_y;
        break;
    case BTYP_RESSORT:
        obj->speed_y = new_spd_y - 3;
        break;
    }
    obj->gravity_value_1 = 0;
    obj->gravity_value_2 = 2;

    __asm__("nop");
}
#endif

/* 2CBC4 801513C4 -O2 -msoft-float */
#ifndef NONMATCHINGS /* div_nop_swap, missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_update", DO_THROWN_BOMB_REBOND);
#else
void DO_THROWN_BOMB_REBOND(Obj *obj, s16 pesanteur, s16 param_3)
{
    ObjType old_type;
    u8 under;
    u8 btyp;
    u8 anim_speed;
    s32 mul_45 = 5;
    s32 mul_30 = 3;
    u8 div_45 = 1;
    u8 div_30 = 1;
    
    if (obj->main_etat == 2)
    {
        if (obj->sub_etat == 1)
        {
            DO_STONE_EXPLOSION();
            return;
        }
        if (obj->sub_etat == 0)
        {
            old_type = obj->type;
            obj->type = TYPE_STONEBOMB2;
            DO_STONEBOMB_REBOND(obj);
            obj->type = old_type;
            return;
        }
    }

    if (obj->speed_y >= 0)
    {
        under = underSlope(obj);
        if (under)
            btyp = obj->btypes[3];
        else
            btyp = obj->btypes[0];
        
        switch (btyp)
        {
        case BTYP_NONE:
        case BTYP_SLIPPERY:
            break;
        case BTYP_SOLID_RIGHT_45:
        case BTYP_SLIPPERY_RIGHT_45:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x -= mul_45 * obj->speed_y / div_45;
            break;
        case BTYP_SOLID_LEFT_45:
        case BTYP_SLIPPERY_LEFT_45:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x += mul_45 * obj->speed_y / div_45;
            break;
        case BTYP_SOLID_RIGHT1_30:
        case BTYP_SOLID_RIGHT2_30:
        case BTYP_SLIPPERY_RIGHT1_30:
        case BTYP_SLIPPERY_RIGHT2_30:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x -= mul_30 * obj->speed_y / div_30;
            break;
        case BTYP_SOLID_LEFT1_30:
        case BTYP_SOLID_LEFT2_30:
        case BTYP_SLIPPERY_LEFT1_30:
        case BTYP_SLIPPERY_LEFT2_30:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x += mul_30 * obj->speed_y / div_30;
            break;
        case BTYP_RESSORT:
            if (obj->speed_y == 0)
                obj->speed_y++;
            break;
        }
        if (param_3 > 0)
        {
            if (obj->speed_y >= 2)
            {
                obj->speed_y = param_3 - obj->speed_y;
                if (pesanteur)
                    obj->speed_y++;
            }
            else
                obj->speed_y = 0;
        }
        else
            obj->speed_y = -3;
        
        if (under)
        {
            while (
                PS1_BTYPAbsPos(
                    obj->x_pos + obj->offset_bx,
                    obj->y_pos + obj->offset_by
                ) == obj->btypes[0]
            )
                obj->y_pos--;
            
            recale_position(obj);
            calc_btyp(obj);
        }
        else if (
            block_flags[obj->btypes[0]] & FLG(BLOCK_FULLY_SOLID) &&
            prof_in_bloc(obj) >= 4 && obj->speed_y < 3
        )
        {
            if (obj->speed_y == 0)
                obj->speed_y = 1;
        }
        else
            recale_position(obj);
    }
    obj->gravity_value_1 = 0;
    anim_speed = obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4;
    if (!(anim_speed == 10 || anim_speed == 11))
        obj->gravity_value_2 = 0;

    __asm__("nop\nnop\nnop\nnop\nnop\nnop");
}
#endif

/* 2D008 80151808 -O2 -msoft-float */
#ifndef NONMATCHINGS /* div_nop_swap, missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_update", DO_FRUIT_REBOND);
#else
void DO_FRUIT_REBOND(Obj *obj, s16 pesanteur, s16 param_3)
{
    u8 under;
    u8 btyp;
    ObjType obj_type;
    u8 anim_speed;
    s16 accel_x;
    s16 speed_x_bnd;
    s32 mul_45;
    s32 mul_30;
    u8 div_45;
    u8 div_30;

    if (obj->type == TYPE_GRAINE)
    {
        accel_x = 1;
        speed_x_bnd = 1;
        mul_45 = 1;
        mul_30 = 1;
        div_45 = 1;
        div_30 = 2;
    }
    else
    {
        accel_x = 5;
        speed_x_bnd = 4;
        mul_45 = 5;
        mul_30 = 3;
        div_45 = 1;
        div_30 = 1;
    }

    if (obj->speed_y >= 0)
    {
        if (obj->speed_x > 0)
            obj->speed_x -= accel_x;
        else if (obj->speed_x < 0)
            obj->speed_x += accel_x;
        
        if (obj->speed_x >= -speed_x_bnd && obj->speed_x <= speed_x_bnd)
            obj->speed_x = 0;

        under = underSlope(obj);
        if (under)
            btyp = obj->btypes[3];
        else
            btyp = obj->btypes[0];

        switch (btyp)
        {
        case BTYP_NONE:
        case BTYP_SLIPPERY:
            break;
        case BTYP_SOLID_RIGHT_45:
        case BTYP_SLIPPERY_RIGHT_45:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x -= mul_45 * obj->speed_y / div_45;
            break;
        case BTYP_SOLID_LEFT_45:
        case BTYP_SLIPPERY_LEFT_45:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x += mul_45 * obj->speed_y / div_45;
            break;
        case BTYP_SOLID_RIGHT1_30:
        case BTYP_SOLID_RIGHT2_30:
        case BTYP_SLIPPERY_RIGHT1_30:
        case BTYP_SLIPPERY_RIGHT2_30:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x -= mul_30 * obj->speed_y / div_30;
            break;
        case BTYP_SOLID_LEFT1_30:
        case BTYP_SOLID_LEFT2_30:
        case BTYP_SLIPPERY_LEFT1_30:
        case BTYP_SLIPPERY_LEFT2_30:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x += mul_30 * obj->speed_y / div_30;
            break;
        case BTYP_RESSORT:
            if (obj->speed_y == 0)
                obj->speed_y++;
            break;
        }

        if (param_3 > 0)
        {
            if (obj->speed_y >= 2)
            {
                obj->speed_y = param_3 - obj->speed_y;
                if (pesanteur)
                    obj->speed_y++;
            }
            else
            {
                obj->speed_y = 0;
                obj->hit_points = 2;
            }
        }
        else
        {
            obj_type = obj->type;
            if (
                obj_type == TYPE_FALLING_OBJ || obj_type == TYPE_FALLING_OBJ2 || obj_type == TYPE_FALLING_OBJ3 ||
                obj_type == TYPE_FALLING_YING || obj_type == TYPE_FALLING_YING_OUYE
            )
            {
                if (ray.field20_0x36 == obj->id)
                {
                    if (ray.scale == 0)
                        obj->speed_y = -3;
                    else
                        obj->speed_y = -4;
                }
                else
                    obj->speed_y = -5;
                
                if (obj->type == TYPE_FALLING_YING_OUYE)
                    obj->speed_y++;
            }
            else
                obj->speed_y = -3;
        }

        if (under)
        {
            while (
                PS1_BTYPAbsPos(
                    obj->x_pos + obj->offset_bx,
                    obj->y_pos + obj->offset_by
                ) == obj->btypes[0]
            )
                obj->y_pos--;
            
            calc_btyp(obj);
            recale_position(obj);
        }
        else if (
            block_flags[obj->btypes[0]] & FLG(BLOCK_FULLY_SOLID) &&
            prof_in_bloc(obj) >= 4 && obj->speed_y < 3
        )
        {
            if (obj->speed_y == 0)
                obj->speed_y = 1;
        }
        else
            recale_position(obj);
    }

    obj->gravity_value_1 = 0;
    anim_speed = obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4;
    if (!(anim_speed == 10 || anim_speed == 11))
        obj->gravity_value_2 = 0;

    __asm__("nop\nnop\nnop\nnop\nnop\nnop");
}
#endif

/* 2D4F8 80151CF8 -O2 -msoft-float */
void Drop_Atter(Obj *obj)
{
    set_main_and_sub_etat(obj, 2, 3);
    obj->speed_y = 0;
    obj->speed_x = 0;
}

/* 2D52C 80151D2C -O2 -msoft-float */
void BadGuyAtter(Obj *obj)
{
    u8 sub_etat;
    u8 label;

    recale_position();
    if (obj->hit_points != obj->init_hit_points)
    {
        if (obj->eta[obj->main_etat][obj->sub_etat].flags & 0x40)
            sub_etat = 2;
        else
            sub_etat = 11;
        set_main_and_sub_etat(obj, 1, sub_etat);
    }
    else
    {
        set_main_and_sub_etat(obj, 1, 0);
        obj->flags |= FLG(OBJ_READ_CMDS);
    }

    calc_obj_dir(obj);
    if (obj->flags & FLG(OBJ_FLIP_X))
        label = 3;
    else
        label = 2;
    skipToLabel(obj, label, true);
}

/* 2D5F8 80151DF8 -O2 -msoft-float */
void MiteAtter(Obj *obj)
{
    if (obj->speed_y > 0)
    {
        recale_position();
        skipToLabel(obj, 2, true);
        if (obj->field20_0x36 > 500)
            obj->field20_0x36 = 0;
    }
}

/* 2D658 80151E58 -O2 -msoft-float */
void Clown_Music_Atter(Obj *obj)
{
    if (obj->hit_points != obj->init_hit_points)
    {
        if (obj->main_etat == 2 && obj->sub_etat == 1)
        {
            set_main_and_sub_etat(obj, 0, 2);
            obj->speed_x = 0;
            obj->flags |= FLG(OBJ_READ_CMDS);
        }
    }
    else
    {
        set_main_etat(obj, 1);
        set_sub_etat(obj, 0);
        obj->flags |= FLG(OBJ_READ_CMDS);
    }

    obj->speed_y = 0;
    if (!(obj->flags & FLG(OBJ_FLIP_X)))
        skipToLabel(obj, 2, true);
    else
        skipToLabel(obj, 3, true);
}

/* 2D71C 80151F1C -O2 -msoft-float */
void LidolPinkAtter(Obj *obj)
{
    if (gerbe && obj->sub_etat == 1)
        do_boing(obj, 1, 0);
    else if (obj->sub_etat != 0)
    {
        skipToLabel(obj, 1, true);
        obj->speed_y = 0;
        recale_position(obj);
    }
}

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
