#include "obj_update.h"

void DO_BALLE(Obj *obj);

void DO_BAT_COMMAND(Obj *obj);
void DO_BB1_PLAT_CMD(Obj *obj);
void DO_BLKTOON_COMMAND(Obj *obj);
void DO_BLKTOON_EYES_CMD(Obj *obj);
void DO_BOUEE_JOE_COMMAND(Obj *obj);
void DO_CLOWN_TNT2_COMMAND(Obj *obj);
void DO_CLOWN_TNT3_COMMAND(Obj *obj);
void DO_CLOWN_TNT_COMMAND(Obj *obj);
void DO_DARD_PLAFOND_ALWAYS(Obj *obj);
void DO_DARK2_SORT_COMMAND(Obj *obj);
void DO_DARK2_TOONS_COMMAND(Obj *obj);
void DO_DARK_COMMAND(Obj *obj);
void DO_DARK_PHASE2_COMMAND(Obj *obj);
void DO_DROP_COMMAND(Obj *obj);
void DO_EAU_QUI_MONTE(Obj *obj);
void DO_ECLAIR_COMMAND(Obj *obj);
void DO_ENSEIGNE_COMMAND(Obj *obj);
void DO_FLASH_COMMAND(Obj *obj);
void DO_HYB_BBF2_LAS(Obj *obj);
void DO_IDC_COMMAND(Obj *obj);
void DO_JOE_COMMAND(Obj *obj);
void DO_MITE2_COMMAND(Obj *obj);
void DO_MIT_COMMAND(Obj *obj);
void DO_MOVING_WITH_INDICATOR_COMMAND(Obj *obj);
void DO_MST_SCROLL_COMMAND(Obj *obj);
void DO_MUSICIEN(Obj *obj);
void DO_NOMOVE_STONEWOMAN_COMMAND(Obj *obj);
void DO_NOVA2_COMMAND(Obj *obj);
void DO_ONE_NGW_COMMAND(Obj *obj);
void DO_ONE_NGW_RING_COMMAND(Obj *obj);
void DO_ONE_PAR_COMMAND(Obj *obj);
void DO_ONE_PINK_CMD(Obj *obj);
void DO_ONE_STONECHIP_COMMAND(Obj *obj);
void DO_PAC_COMMAND(Obj *obj);
void DO_PAR_BOMB_COMMAND(Obj *obj);
void DO_PETIT_COUTEAU_COMMAND(Obj *obj);
void DO_PHOTOGRAPHE_CMD(Obj *obj);
void DO_PIRATE_POELLE(Obj *obj);
void DO_POELLE_COMMAND(Obj *obj);
void DO_POING(Obj *obj);
void DO_PTI_ESQUIVE(Obj *obj);
void DO_REDUCTEUR(Obj *obj);
void DO_ROLL_EYES(Obj *obj);
void DO_SPIDER_PLAFOND(Obj *obj);
void DO_SPIDER_TIR(Obj *obj);
void DO_STONEBOMB_COMMAND(Obj *obj);
void DO_STONEDOG_COMMAND(Obj *obj);
void DO_STONEMAN1_TIR(Obj *obj);
void DO_STONEMAN2_TIR(Obj *obj);
void DO_STONEWOMAN_COMMAND(Obj *obj);
void DO_TARZAN(Obj *obj);
void DO_TEN_COMMAND(Obj *obj);
void DO_TIRE_BOUCHON_COMMAND(Obj *obj);
void DO_TRP_COMMAND(Obj *obj);
void DO_VITRAIL_COMMAND(Obj *obj);
void DoFlammeCommand(Obj *obj);
void doBBF2command(Obj *obj);
void doBlackRaymanCommand(Obj *obj);
void doHerseCommand(Obj *obj);
void doMOSAMScommand(Obj *obj);
void doSTOSKOcommand(Obj *obj);
void doShipCommand(Obj *obj);

/* 2C214 80150A14 -O2 -msoft-float */
s32 DO_PESANTEUR(Obj *obj)
{
    s16 spd_y;
    s32 res = false;
    s16 y_accel = 0;
    u8 anim_speed_div = obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4;
    
    if (anim_speed_div != 0)
    {
        if (obj->type == TYPE_TAMBOUR1 || obj->type == TYPE_TAMBOUR2)
        {
            if (obj->field56_0x69 != 0)
                obj->field56_0x69--;
            else if (obj->gravity_value_1 == 0)
            {
                obj->speed_y++;
                res = true;
            }
        }
        else
        {
            switch (anim_speed_div)
            {
            case 6:
                if (horloge[2] == 0)
                {
                    y_accel = 1;
                    res = true;
                }
                break;
            case 1:
                if (obj->gravity_value_1 == 0)
                {
                    y_accel = 1;
                    res = true;
                }
                break;
            case 2:
                if (obj->gravity_value_2 == 0)
                {
                    y_accel = 1;
                    res = true;
                }
                break;
            case 3:
                spd_y = obj->speed_y;
                if (spd_y > 0)
                {
                    if (spd_y > 1)
                        y_accel = -1;
                }
                else
                    y_accel = 1;
                break;
            case 4:
                spd_y = obj->speed_y;
                if (spd_y < -1)
                {
                    if (spd_y < -2)
                        y_accel = 1;
                }
                else
                    y_accel = -1;
                break;
            case 5:
                if (obj->gravity_value_1 == 0)
                    y_accel = -1;
                break;
            case 10:
                obj->gravity_value_1++;
                if (obj->gravity_value_1 >= obj->gravity_value_2)
                {
                    obj->gravity_value_1 = 0;
                    y_accel = 1;
                    res = true;
                }
                break;
            case 11:
                obj->gravity_value_1++;
                if (obj->gravity_value_1 >= obj->gravity_value_2)
                {
                    obj->gravity_value_1 = 0;
                    y_accel = -1;
                    res = true;
                }
                break;
            }
        }
        
        if (flags[obj->type].flags1 >> OBJ1_USE_INSTANT_SPEED_Y & 1)
            y_accel = ashl16(y_accel, 4);
        obj->speed_y += y_accel;
    }
    return res;
}

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
}

/* 2C89C 8015109C -O2 -msoft-float */
s16 prof_in_bloc(Obj *obj)
{
    s32 y = obj->y_pos + obj->offset_by;
    return y - (y / 16 * 16);
}

/* 2C8D0 801510D0 -O2 -msoft-float */
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
}

/* 2CA58 80151258 -O2 -msoft-float */
u8 underSlope(Obj *obj)
{
    u8 res = false;
    if (block_flags[obj->btypes[0]] & FLG(BLOCK_FULLY_SOLID))
        res = block_flags[obj->btypes[3]] >> BLOCK_SLOPE & 1;

    return res;
}

/* 2CAAC 801512AC -O2 -msoft-float */
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
}

/* 2CBC4 801513C4 -O2 -msoft-float */
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
            DO_STONE_EXPLOSION(obj);
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
}

/* 2D008 80151808 -O2 -msoft-float */
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
}

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

    recale_position(obj);
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
        recale_position(obj);
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

/* 2D790 80151F90 -O2 -msoft-float */
void stoneDogAtter(Obj *obj)
{
    if (obj->sub_etat == 2)
    {
        skipToLabel(obj, 4, true);
        recale_position(obj);
    }
}

/* 2D7D0 80151FD0 -O2 -msoft-float */
void stoneDogBounces(Obj *obj)
{
    s32 x = obj->x_pos + obj->offset_bx;
    s32 y = obj->y_pos + obj->offset_by;
    s32 block_l = mp.map[((x - 2) >> 4) + ((y >> 4) * mp.width)] >> 10;
    s32 block_r = mp.map[((x + 2) >> 4) + ((y >> 4) * mp.width)] >> 10;

    if (
        obj->main_etat == 2 &&
        !(block_flags[obj->btypes[0]] >> BLOCK_SOLID & 1) &&
        (
            (block_flags[block_l] & FLG(BLOCK_FULLY_SOLID) && !(obj->flags & FLG(OBJ_FLIP_X))) ||
            (block_flags[block_r] & FLG(BLOCK_FULLY_SOLID) && obj->flags & FLG(OBJ_FLIP_X))
        )
    )
    {
        if (obj->speed_y < 0)
        {
            if (obj->flags & FLG(OBJ_FLIP_X))
                skipToLabel(obj, 6, true);
            else
                skipToLabel(obj, 7, true);
        }
        else
        {
            obj->x_pos += obj->speed_x / 16;
            skipToLabel(obj, 4, true);
            obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | ((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X;
        }
    }
}

/* 2D998 80152198 -O2 -msoft-float */
void Spider_Atter(Obj *obj)
{
    set_main_and_sub_etat(obj, 1, 0);
    if (obj->flags & FLG(OBJ_FLIP_X))
        skipToLabel(obj, 3, true);
    else
        skipToLabel(obj, 1, true);
}

/* 2D9EC 801521EC -O2 -msoft-float */
void trompetteAtter(Obj *obj)
{
    skipToLabel(obj, 8, true);
    recale_position(obj);
}

/* 2DA20 80152220 -O2 -msoft-float */
void NormalAtter(Obj *obj)
{
    set_main_and_sub_etat(obj, obj->init_main_etat, obj->init_sub_etat);
    recale_position(obj);
}

/* 2DA58 80152258 -O2 -msoft-float */
void OBJ_IN_THE_AIR(Obj *obj)
{
    s16 pesanteur;
    s16 spd_y;
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
    s16 flip_x;
    u8 anim_speed_div = obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4;

    if (!(anim_speed_div == 10 || anim_speed_div == 11))
    {
        obj->gravity_value_1++;
        if (obj->gravity_value_1 > 2)
            obj->gravity_value_1 = 0;
        
        obj->gravity_value_2++;
        if (obj->gravity_value_2 > 3)
            obj->gravity_value_2 = 0;
    }

    pesanteur = DO_PESANTEUR(obj);
    if (obj->type == TYPE_LIDOLPINK)
    {
        if (obj->speed_y >= 0 && obj->sub_etat == 0)
            set_sub_etat(obj, 1);
        
        if (!gerbe && obj->speed_y > 2 && obj->sub_etat == 1)
        {
            set_sub_etat(obj, 2);
            obj->speed_x = 0;
        }
    }
    else if (obj->type == TYPE_STONEDOG || obj->type == TYPE_STONEDOG2)
    {
        stoneDogBounces(obj);
        if (obj->main_etat == 2)
        {
            spd_y = obj->speed_y;
            if (spd_y > 0)
            {
                if (obj->sub_etat != 2)
                    set_sub_etat(obj, 2);
            }
            else if (spd_y < 0 && (block_flags[(u8) calc_typ_trav(obj, 1)] >> BLOCK_FULLY_SOLID & 1))
                obj->speed_y = 0;
        }
    }
    else if (obj->type == TYPE_NOTE1)
    {
        if (--obj->iframes_timer == 0)
            DO_EXPLOSE_NOTE1(obj);
    }

    if (
        flags[obj->type].flags3 >> OBJ3_STOP_MOVING_UP_WHEN_HIT_BLOCK & 1 &&
        obj->speed_y < 0
    )
    {
        if (obj->flags & FLG(OBJ_FOLLOW_ENABLED))
        {
            GET_SPRITE_POS(obj, obj->follow_sprite, &spr_x, &spr_y, &spr_w, &spr_h);
            spr_x = obj->x_pos + obj->offset_bx;
            spr_y = spr_y + obj->offset_hy;
        }
        else
        {
            spr_x = obj->x_pos + obj->offset_bx;
            spr_y = obj->y_pos + obj->offset_hy;
        }

        if (block_flags[PS1_BTYPAbsPos(spr_x, spr_y + obj->speed_y)] >> BLOCK_FLAG_4 & 1)
            obj->speed_y = 0;
    }
    if (
        flags[obj->type].flags2 >> OBJ2_MOVE_ON_BLOCK & 1 &&
        block_flags[obj->btypes[0]] >> BLOCK_SOLID & 1
    )
    {
        switch (obj->type)
        {
        case TYPE_TROMPETTE:
            trompetteAtter(obj);
            break;
        case TYPE_HYBRIDE_MOSAMS:
            calc_obj_dir(obj);
            recale_position(obj);
            skipToLabel(obj, 3, true);
            if (ray.main_etat != 2)
            {
                allocateLandingSmoke(obj);
                set_main_and_sub_etat(&ray, 0, 0);
                button_released = 1;
                ray_jump();
                ray.speed_y = -8;
            }
            screen_trembling = 1;
            break;
        case TYPE_BLACKTOON1:
            switch (obj->follow_sprite)
            {
            case 3:
            case 5:
            case 6:
                break;
            case 7:
                obj->field56_0x69 = 2;
                calc_obj_dir(obj);
            case 1:
            case 4:
                set_main_and_sub_etat(obj, 1, 0);
                if (obj->flags & FLG(OBJ_FLIP_X))
                    skipToLabel(obj, 3, true);
                else
                    skipToLabel(obj, 2, true);
                
                recale_position(obj);
                obj->speed_y = 0;
                break;
            case 2:
                set_main_and_sub_etat(obj, 0, 0);
                recale_position(obj);
                obj->speed_y = 0;
                break;
            }
            break;
        case TYPE_WASHING_MACHINE:
            if (obj->speed_y > 0)
            {
                recale_position(obj);
                obj->speed_y = -obj->speed_y;
            }
            break;
        case TYPE_DROP:
            Drop_Atter(obj);
            break;
        case TYPE_MITE:
        case TYPE_MITE2:
            MiteAtter(obj);
            break;
        case TYPE_STONEWOMAN:
            if (obj->speed_y >= 0)
            {
                skipToLabel(obj, 16, true);
                obj->field56_0x69 = 0;
            }
            break;
        case TYPE_TNT_BOMB:
            PlaySnd(187, obj->id);
            BombExplosion(obj);
            break;
        case TYPE_BADGUY1:
        case TYPE_BADGUY2:
        case TYPE_BADGUY3:
            BadGuyAtter(obj);
            break;
        case TYPE_STONEBOMB2:
        case TYPE_STONEBOMB3:
            if (obj->speed_y != 0)
                PlaySnd(200, obj->id);
            DO_STONEBOMB_REBOND(obj);
            break;
        case TYPE_STONEBOMB:
            if (obj->speed_y != 0)
                PlaySnd(200, obj->id);
            DO_THROWN_BOMB_REBOND(obj, pesanteur, 1);
            break;
        case TYPE_STONEDOG:
        case TYPE_STONEDOG2:
            stoneDogAtter(obj);
            break;
        case TYPE_PIRATE_BOMB:
            DO_FRUIT_REBOND(obj, pesanteur, 1);
            break;
        case TYPE_MST_SHAKY_FRUIT:
            if (obj->field23_0x3c != 0)
            {
                PlaySnd(45, obj->id);
                obj->speed_y = 6;
                DO_FRUIT_REBOND(obj, 1, 1);
                obj->field23_0x3c--;
            }
            break;
        case TYPE_MST_FRUIT1:
            if (obj->field23_0x3c != 0)
            {
                PlaySnd(45, obj->id);
                obj->speed_y = 7;
                DO_FRUIT_REBOND(obj, 1, 1);
                obj->field23_0x3c--;
            }
            break;
        case TYPE_MST_FRUIT2:
            if (obj->field23_0x3c != 0)
            {
                PlaySnd(45, obj->id);
                obj->speed_y = 6;
                DO_THROWN_BOMB_REBOND(obj, 1, 1);
                obj->field23_0x3c--;
            }
            break;
        case TYPE_FALLING_OBJ:
        case TYPE_FALLING_OBJ2:
        case TYPE_FALLING_OBJ3:
        case TYPE_FALLING_YING:
        case TYPE_FALLING_YING_OUYE:
        case TYPE_GRAINE:
        case TYPE_BLACKTOON_EYES:
            switch (obj->type)
            {
            case TYPE_FALLING_OBJ:
            case TYPE_FALLING_OBJ3:
            case TYPE_FALLING_OBJ2:
                PlaySnd(45, obj->id);
                break;
            case TYPE_FALLING_YING:
            case TYPE_FALLING_YING_OUYE:
                PlaySnd(140, obj->id);
                break;
            case TYPE_GRAINE:
            case TYPE_BLACKTOON_EYES:
                PlaySnd(0, obj->id);
                break;
            }
            DO_FRUIT_REBOND(obj, pesanteur, 0);
            break;
        case TYPE_CAGE:
            set_main_and_sub_etat(obj, 0, 11);
            obj->speed_y = 0;
            break;
        case TYPE_LIDOLPINK:
            LidolPinkAtter(obj);
            break;
        case TYPE_PIRATE_GUETTEUR:
        case TYPE_PIRATE_GUETTEUR2:
            if (obj->sub_etat == 2)
                set_main_and_sub_etat(obj, 0, 7);
            else if (obj->speed_y >= 0)
                set_main_and_sub_etat(obj, 0, 10);
            recale_position(obj);
            obj->speed_y = 0;
            obj->speed_x = 0;
            break;
        case TYPE_PIRATE_NGAWE:
            recale_position(obj);
            set_main_and_sub_etat(obj, 0, 5);
            obj->speed_y = 0;
            obj->speed_x = 0;
            break;
        case TYPE_SUPERHELICO:
            obj->speed_x = 0;
            obj->speed_y = 0;
            break;
        case TYPE_NOTE0:
        case TYPE_NOTE1:
        case TYPE_NOTE2:
        case TYPE_BONNE_NOTE:
        case TYPE_NOTE3:
            DO_NOTE_REBOND(obj);
            break;
        case TYPE_BBL:
            DO_BBL_REBOND(obj);
            break;
        case TYPE_BIG_CLOWN:
        case TYPE_WAT_CLOWN:
            Clown_Music_Atter(obj);
            break;
        case TYPE_SPIDER:
            Spider_Atter(obj);
            break;
        case TYPE_BB1:
            if (obj->iframes_timer < 10)
                DO_BBMONT_ATTER(obj);
            break;
        case TYPE_BB12:
            DO_BBMONT2_ATTER(obj);
            break;
        case TYPE_BB13:
            DO_BBMONT3_ATTER(obj);
            break;
        case TYPE_SAXO2:
            DO_SAXO2_ATTER(obj);
            break;
        case TYPE_SAXO:
            DO_SAXO_ATTER(obj);
            break;
        case TYPE_MAMA_PIRATE:
            DO_PMA_ATTER(obj);
            break;
        case TYPE_COUTEAU:
            DO_COU_ATTER(obj);
            break;
        case TYPE_BOUT_TOTEM:
            DO_TOTBT_REBOND(obj);
            break;
        case TYPE_SPIDER_PLAFOND:
            if (obj->main_etat == 2 && obj->speed_y > 0)
            {
                set_main_and_sub_etat(obj, 0, 29);
                obj->speed_x = 0;
                obj->speed_y = 0;
                flip_x = ray.x_pos > obj->x_pos;
                obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | flip_x << OBJ_FLIP_X;
            }
            break;
        case TYPE_BALLE1:
        case TYPE_BALLE2:
        case TYPE_BIG_BOING_PLAT:
        case TYPE_BLACK_FIST:
        case TYPE_BLACK_RAY:
        case TYPE_BNOTE:
        case TYPE_BOING_PLAT:
        case TYPE_BULLET:
        case TYPE_CORDEBAS:
        case TYPE_DARK_PHASE2:
        case TYPE_DARK:
        case TYPE_MARACAS_BAS:
        case TYPE_MOSKITO:
        case TYPE_MOSKITO2:
        case TYPE_MST_SCROLL:
        case TYPE_PI_BOUM:
        case TYPE_POI1:
        case TYPE_POI2:
        case TYPE_POI3:
        case TYPE_RING:
        case TYPE_SCORPION:
        case TYPE_SPACE_MAMA:
        case TYPE_SPACE_MAMA2:
        case TYPE_TAMBOUR1:
        case TYPE_TAMBOUR2:
            break;
        default:
            NormalAtter(obj);
            break;
        }
    }
    if (flags[obj->type].flags1 >> OBJ1_USE_INSTANT_SPEED_Y & 1)
    {
        MIN_2(obj->speed_y, 96);
        MAX_2(obj->speed_y, -128)
    }
    else
    {
        MIN_2(obj->speed_y, 6);
        MAX_2(obj->speed_y, -8)
    }
}

/* 2E458 80152C58 -O2 -msoft-float */
void test_fall_in_water(Obj *obj)
{
    if (obj->btypes[0] == BTYP_WATER && !(obj->type == TYPE_RAYMAN && ray.main_etat == 6))
    {
        if (obj->type == TYPE_MST_FRUIT2)
            obj->flags &= ~FLG(OBJ_ALIVE);
        else
        {
            if (flags[obj->type].flags2 >> OBJ2_FALL_IN_WATER & 1)
            {
                if (!(obj->flags & FLG(OBJ_FLAG_9)))
                {
                    allocate_splash(obj);
                    obj->speed_y = 0;
                    obj->speed_x = 0;
                }
                if (flags[obj->type].flags3 >> OBJ3_DIE_IN_WATER & 1)
                {
                    obj->flags &= ~FLG(OBJ_ACTIVE);
                    obj->y_pos = ymap + 484;
                }
            }
        }
    }
}

/* still rather difficult to read tbh? */
/* 2E55C 80152D5C -O2 -msoft-float */
void MOVE_OBJECT(Obj *obj)
{    
    s16 speed_x_1; s16 speed_y_1;
    s16 speed_x_2; s16 speed_y_2;
    s16 x_pos_1;
    s16 x_pos_2;
    s16 y_pos;
    u8 unk_1;

    if (*(s32*)&obj->speed_x != 0)
    {
        speed_x_1 = obj->speed_x;
        speed_y_1 = obj->speed_y;
        if (
            flags[obj->type].flags2 >> OBJ2_INCREASE_SPEED_X &&
            obj->field56_0x69 == 1 && horloge[20] == 0
        )
        {
            if (speed_x_1 <= 0)
                obj->speed_x = speed_x_1 + 1;
            else
                obj->speed_x = speed_x_1 - 1;
            if (obj->speed_x == 0)
                obj->field56_0x69 = 0;
        }

        if (obj->type == TYPE_POING)
        {
            poing.field0_0x0 += ashl16(speed_y_1, 4);
            obj->y_pos = poing.field0_0x0 >> 4;
            obj->x_pos = obj->x_pos + obj->speed_x;
        }
        else
        {
            if ((flags[obj->type].flags1 >> OBJ1_USE_INSTANT_SPEED_Y) & 1)
                speed_y_2 = instantSpeed(obj->speed_y);
            else
                speed_y_2 = speed_y_1;
            
            if ((flags[obj->type].flags1 >> OBJ1_USE_INSTANT_SPEED_X) & 1)
                speed_x_2 = instantSpeed(obj->speed_x);
            else
                speed_x_2 = speed_x_1;
            
            if (flags[obj->type].flags2 >> OBJ2_UTURN_ON_BLOCK & 1)
            {
                x_pos_1 = obj->x_pos + obj->offset_bx;
                x_pos_2 = x_pos_1 + speed_x_2;
                y_pos = obj->y_pos + obj->offset_by - 8;
                if
                (
                    (
                        !(block_flags[PS1_BTYPAbsPos(x_pos_1, y_pos)] >> BLOCK_FLAG_4 & 1) &&
                        block_flags[PS1_BTYPAbsPos(x_pos_2, y_pos)] >> BLOCK_FLAG_4 & 1
                    ) ||
                    x_pos_2 < 0 || (x_pos_2 > xmapmax + SCREEN_WIDTH)
                )
                {
                    speed_x_2 = -speed_x_2;
                    obj->speed_x = -obj->speed_x;
                }
            }
            obj->x_pos += speed_x_2;
            obj->y_pos += speed_y_2;
        }

        unk_1 = false;
        if (!(speed_x_2 == 0 && speed_y_2 == 0))
            unk_1 = true;
        obj->flags = obj->flags & ~FLG(OBJ_FLAG_B) | (unk_1 << OBJ_FLAG_B);
        test_fall_in_water(obj);
    }
    else
        obj->flags &= ~FLG(OBJ_FLAG_B);
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj_update", DO_RAY_IN_ZONE);
#else
/* matches, but clean up */
/*INCLUDE_ASM("asm/nonmatchings/obj_update", DO_RAY_IN_ZONE);*/

void DO_RAY_IN_ZONE(Obj *obj)
{
    s16 sp20;
    s16 sp22;
    s16 sp24;
    s16 sp26;
    s16 temp_v0;
    s16 temp_v0_3;
    s16 temp_v1_4;
    s16 var_v0;
    s16 var_v0_2;
    s32 temp_v0_2;
    s16 temp_a0;
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_t0;
    u32 temp_v0_4;
    u32 temp_v1_12;
    u8 temp_v1;
    u8 temp_v1_10;
    u8 temp_v1_11;
    u8 temp_v1_13;
    u8 temp_v1_14;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_5;
    u8 temp_v1_6;
    u8 temp_v1_7;
    u8 temp_v1_8;
    u8 temp_v1_9;
    u8 var_a1;
    u8 var_a1_2;

    if ((OBJ_IN_ZONE(obj) << 0x10) != 0)
    {
        temp_v1 = obj->type;
        switch (temp_v1)
        {
        case 0x37:
            if (obj->sub_etat == 1)
            {
                set_sub_etat(obj, 5U);
                return;
            }
            break;
        case 0x35:
            if ((obj->main_etat != 2) && (obj->sub_etat != 1))
            {
                obj->field23_0x3c = 1;
                skipToLabel(obj, 0U, 1U);
                obj->gravity_value_2 = 4;
                return;
            }
            break;
        case 0x99:
            if (obj->sub_etat == 0)
            {
                if (ray.main_etat == 2)
                {
                    ray.speed_x = 0;
                    ray.field24_0x3e = 0;
                    ray_in_fee_zone = 1;
                    decalage_en_cours = 0;
                    return;
                }
                else if (ray.main_etat == 0 || ray.main_etat == 1 || (ray.main_etat == 3 && ray.sub_etat == 0x14))
                {
                    temp_v0 = (u16) obj->x_pos - (ray.offset_bx + 2);
                    remoteRayXToReach = temp_v0;
                    if (ray.x_pos & 1)
                    {
                        remoteRayXToReach = temp_v0 | 1;
                    }
                    else
                    {
                        remoteRayXToReach = temp_v0 & 0xFFFE;
                    }
                    ray_in_fee_zone = 0;
                    return;
                }
            }
            else
            {
                ray_in_fee_zone = 0;
                return;
            }
            break;
        case 0xB7:
            DO_SAXO3_DEBUT(obj);
            return;
        case 0xB5:
            DO_SAXO_MARCHE((s16) obj->hit_points);
            return;
        case 0xC7:
            DO_BBMONT2_MARCHE((s16) obj->hit_points);
            return;
        case 0x93:
            DO_MST_CHANGE_COMMAND(obj->hit_points);
            return;
        case 0x7B:
            temp_v1_2 = obj->follow_sprite;
            switch (temp_v1_2)
            {
            case 7:
                temp_v1_3 = obj->main_etat;
                if ((temp_v1_3 == 1) && (obj->sub_etat == temp_v1_3) && (ray.main_etat != 2))
                {
                    var_a1 = 5;
block_141:
                    skipToLabel(obj, var_a1, 1U);
                    return;
                }
                break;
            case 4:
                if (ray.main_etat != 2)
                {
                    GET_ANIM_POS(obj, &sp20, &sp22, &sp24, &sp26);
                    sp22 -= (obj->detect_zone + sp26);
                    sp20 -= (sp24 >> 1);
                    sp24 += sp24;
                    sp26 += obj->detect_zone;
                    if (
                        (obj->main_etat == 1) && (obj->sub_etat == 0) &&
                        (s16) inter_box(
                            sp20, sp22, sp24, sp26,
                            ray_zdc_x, ray_zdc_y, ray_zdc_w, ray_zdc_h
                        )
                    )
                    {
                        calc_obj_dir(obj);
                        temp_v1_4 = (u16) ray_zdc_y - obj->offset_hy;
                        obj->field23_0x3c = temp_v1_4;
                        if (temp_v1_4 < (obj->y_pos - 0x10))
                        {
                            skipToLabel(obj, 4U, 1U);
                            obj->gravity_value_1 = 0;
                            obj->gravity_value_2 = 6;
                            obj->y_pos = (u16) obj->y_pos - 1;
                            return;
                        }
                    }
                }
                break;
            case 3:
                if ((obj->main_etat == 0) && (obj->sub_etat == 0) && (ray.main_etat != 2))
                {
                    calc_obj_dir(obj);
                    temp_v0_3 = (ray.offset_hy + ray.y_pos) - obj->offset_hy;
                    obj->field23_0x3c = temp_v0_3;
                    if (temp_v0_3 < (obj->y_pos - 0x10))
                    {
                        skipToLabel(obj, 4U, 1U);
                        obj->gravity_value_2 = 6;
                        obj->gravity_value_1 = 0;
                        obj->timer = 0xFF;
                        obj->y_pos = (u16) obj->y_pos - 1;
                        return;
                    }
                }
                break;
            case 2:
                if ((obj->main_etat == 0) && (obj->sub_etat == 0) && (ray.main_etat != temp_v1_2))
                {
                    calc_obj_dir(obj);
                    skipToLabel(obj, 4U, 1U);
                    obj->gravity_value_1 = 0;
                    obj->gravity_value_2 = 6;
                    obj->y_pos = (u16) obj->y_pos - 1;
                    return;
                }
                break;
            }
            break;
        case 0x39:
            if (obj->sub_etat == 4)
            {
                var_a1 = 0x63;
                skipToLabel(obj, var_a1, 1U);
                return;
            }
            break;
        case 0x3:
            if (obj->eta[obj->main_etat][obj->sub_etat].flags & 1)
            {
                var_a1 = 0;
                skipToLabel(obj, var_a1, 1U);
                return;
            }
            break;
        case 0x9:
        case 0xA5:
            if (obj->main_etat == 1)
            {
                if (obj->sub_etat == 0x0B)
                {
                    set_sub_etat(obj, 0x0EU);
                    return;
                }
                /*goto block_57;*/
            }
block_57:
            if ((obj->main_etat != 0) || (obj->sub_etat != 0)) {
                if (obj->main_etat != 1) {
                    return;
                }
                if (obj->sub_etat != 0) {
                    return;
                }
            }
            set_main_and_sub_etat(obj, 1U, 0x0BU);
            temp_v0_4 = obj->flags;
            obj->flags = temp_v0_4 & 0xFFFF7FFF;
            if (temp_v0_4 & 0x4000)
            {
                var_a1 = 3;
            }
            else
                var_a1 = 2;
            skipToLabel(obj, var_a1, 1U);
            return;
        case 0x0:
            if (((ray.flags & 0x4000) != (obj->flags & 0x4000)) && (((temp_v1_5 = obj->main_etat, (temp_v1_5 == 1)) && (obj->sub_etat == 0)) || ((temp_v1_5 == 0) && (obj->sub_etat == 0))) && (ray.main_etat == 0) && (ray.sub_etat == 0x12))
            {
                obj->speed_x = 0;
                obj->speed_y = 0;
                set_main_and_sub_etat(obj, 0U, 2U);
                if (obj->flags & 0x4000)
                {
                    skipToLabel(obj, 8, 1U);
                }
                else
                {
                    skipToLabel(obj, 7, 1U);
                }
                
                return;
            }
            break;
        case 0x46:
            if ((obj->timer == 0) && (((temp_v1_6 = obj->main_etat, (temp_v1_6 == 0)) && (obj->sub_etat == 0)) || ((temp_v1_6 == 1) && (obj->sub_etat == 0))))
            {
                var_a1 = 5;
                skipToLabel(obj, var_a1, 1U);
                return;
            }
            break;
        case 0x3C:
        case 0x3D:
            if ((obj->main_etat != 0) || (obj->sub_etat != 0)) {
                if (obj->main_etat != 1) {
                    return;
                }
                if (obj->sub_etat != 0) {
                    return;
                }
            }
            skipToLabel(obj, 5, 1U);
            break;
        case 0x74:
            if (obj->field24_0x3e == 0)
            {
                skipToLabel(obj, 7U, 1U);
                obj->timer = 0;
            case 0x14:
                obj->field24_0x3e = 1;
                return;
            }
            break;
        case 0x7A:
            if ((obj->main_etat != 0) || (obj->sub_etat != 0)) {
                if (obj->main_etat != 1) {
                    return;
                }
                if (obj->sub_etat != 0) {
                    return;
                }
            }
            skipToLabel(obj,2,true);
            obj->gravity_value_2 = 7;
            obj->gravity_value_1 = 0;
            return;
        case 0x23:
        case 0x2B:
            if ((obj->main_etat != 0) || ((!(obj->sub_etat == 1 || obj->sub_etat == 2)) && !(obj->sub_etat == 5 || obj->sub_etat == 6) && ((obj->sub_etat != 3)) && (obj->sub_etat != 7) && (obj->sub_etat != 4)))
            {
                var_a1 = 7;
                skipToLabel(obj, var_a1, 1U);
                return;
            }
            break;
        case 0x84:
            if (obj->main_etat == 2) {
                temp_v1_11 = obj->sub_etat;
                if (temp_v1_11 == 0x10) {
                    return;
                }
                if (temp_v1_11 == 0x11) {
                    return;
                }
                if (temp_v1_11 == 0x12) {
                    return;
                }
            }
            if ((((((ray.x_pos + ray.offset_bx) - obj->x_pos) - obj->offset_bx) >= 0 && (obj->flags & 0x4000)) || ((((ray.x_pos + ray.offset_bx) - obj->x_pos) - obj->offset_bx) < 0 && !(obj->flags & 0x4000))))
            {
                if (obj->flags & 0x4000)
                    obj->speed_x = 3;
                else
                    obj->speed_x = -3;
                obj->speed_y = -5;
                set_main_etat(obj, 2U);
                set_sub_etat(obj, 0x10U);
                skipToLabel(obj, 0x0B, 1U);
                return;
            }
            return;
        case 0x41:
            if ((obj->main_etat == 1) && (obj->sub_etat == 0) && (obj->field24_0x3e == 0))
            {
                temp_v1_12 = obj->flags;
                obj->anim_frame = 0;
                if (!(temp_v1_12 & 0x4000))
                {
                    obj->flags = temp_v1_12 | 0x4000;
                    skipToLabel(obj, 3, 1U);
                }
                else
                {
                    obj->flags = temp_v1_12 & ~0x4000;
                    skipToLabel(obj, 1, 1U);
                }
                
                pushToLabel(obj, 5U, 1U);
                return;
            }
            break;
        case 0xC:
        case 0xE:
            if ((obj->main_etat == 0) && ((temp_v1_13 = obj->sub_etat, (temp_v1_13 == 0)) || (temp_v1_13 == 2)))
            {
                obj->speed_x = 0;
                obj->speed_y = 0;
                set_main_and_sub_etat(obj, 0U, 2U);
                obj->flags &= 0xFFFF7FFF;
                calc_obj_dir(obj);
                if (obj->flags & 0x4000)
                {
                    obj->cmd = 1;
                    return;
                }
                obj->cmd = 0;
                return;
            }
            break;
        case 0x48:
            NGW_REACT_TO_RAY_IN_ZONE(obj);
            return;
        case 0x4D:
        case 0xEF:
            PAR_REACT_TO_RAY_IN_ZONE(obj);
            return;
        case 0x98:
            if ((obj->main_etat == 0) && (obj->sub_etat == 0))
            {
                set_main_and_sub_etat(obj, 1U, 0U);
                if (obj->flags & 0x4000)
                {
                    skipToLabel(obj, 3, 1U);
                }
                else
                {
                    skipToLabel(obj, 2, 1U);
                }
                return;
            }
            break;
        case 0x96:
            SKO_ray_in_zone(obj);
            return;
        case 0x78:
            BAT_ray_in_zone(obj);
            return;
        case 0xAE:
        case 0xB8:
        case 0xE1:
        case 0xE2:
            PIRATE_POELLE_REACT(obj);
            return;
        case 0xC3:
            SPIDER_PLAFOND_REACT(obj);
            return;
        case 0xD4:
            DO_DARK_REACT(obj);
            return;
        case 0x59:
            if (obj->main_etat == 0)
            {
                if ((obj->sub_etat == 1) && (joe_exp_probleme == 0))
                {
                    vignet_joe_affichee = 0;
                    skipToLabel(obj, 2U, 1U);
                    joe_exp_probleme = 1;
                }
                if ((obj->main_etat == 0) && (obj->sub_etat == 2))
                {
                    var_a1 = 4;
                    skipToLabel(obj, var_a1, 1U);
                return;
                }
            }
            break;
        }
    }
    else
    {
        if ((obj->detect_zone_flag == 0) && ((temp_v1_14 = obj->type, (temp_v1_14 == 0x0C)) || (temp_v1_14 == 0x0E)) && (obj->main_etat == 0) && (obj->sub_etat == 0x15) && (obj->anim_frame >= (obj->animations[obj->anim_index].frames_count - 1)))
        {
            set_main_and_sub_etat(obj, 0U, 0U);
        }
    /*default:*/
    }
}
#endif

/* 2F3B4 80153BB4 -O2 -msoft-float */
void DO_ONE_OBJECT(Obj *obj)
{
    if (flags[ot].flags0 >> OBJ0_BALLE & 1)
        DO_BALLE(obj);
    if (flags[ot].flags0 >> OBJ0_DETECT_ZONE & 1)
        SET_DETECT_ZONE_FLAG(obj);
    if (flags[ot].flags2 >> OBJ2_MOVE_ON_BLOCK & 1)
        calc_btyp(obj);
    if (flags[ot].flags1 >> OBJ1_READ_CMD & 1)
        GET_OBJ_CMD(obj);
    else
        obj->cmd = GO_NOP;
    
    ObjectsFonctions[ot].do_obj(obj);

    if (obj->main_etat == 2)
        OBJ_IN_THE_AIR(obj);
    if (obj->flags & FLG(OBJ_FOLLOW_ENABLED))
        SET_RAY_DIST(obj);
    else
        obj->ray_dist = 10000;
    if (flags[ot].flags1 >> OBJ1_SPECIAL_PLATFORM & 1)
        DO_SPECIAL_PLATFORM(obj);
    if (flags[ot].flags0 >> OBJ0_DETECT_ZONE & 1)
        DO_RAY_IN_ZONE(obj);
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj_update", fptr_init);
#else
/* matches, but insert types */
/*INCLUDE_ASM("asm/nonmatchings/obj_update", fptr_init);*/

void fptr_init(void)
{
    ObjType obj_type;
    ObjHandlers *obj_fonction;
    void (*sel_fonction)(Obj *);
    
    for (obj_type = 0; obj_type < LEN(ObjectsFonctions) - 1; obj_type++)
    {
        switch (obj_type)
        {
        case 0x5E:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_POING;
            break;
        case 0x82:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BLKTOON_EYES_CMD;
            break;
        case 0x81:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PETIT_COUTEAU_COMMAND;
            break;
        case 0x80:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_TIRE_BOUCHON_COMMAND;
            break;
        case 0x37:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MUSICIEN;
            break;
        case 0x8:
        case 0x86:
        case 0xA7:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_FALLING_OBJ_CMD;
            break;
        case 0x3E:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_DROP_COMMAND;
            break;
        case 0xC1:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = mereDenisBombCommand;
            break;
        case 0xC0:
        case 0xF4:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = mereDenisBigLaserCommand;
            break;
        case 0x59:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_JOE_COMMAND;
            break;
        case 0xD6:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BOUEE_JOE_COMMAND;
            break;
        case 0xAD:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doShipCommand;
            break;
        case 0xE7:
        case 0xE8:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doBBF2command;
            break;
        case 0xE9:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_HYB_BBF2_LAS;
            break;
        case 0xDB:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CORDE_COMMAND;
            break;
        case 0xDD:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CFUMEE_COMMAND;
            break;
        case 0xDC:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PAC_COMMAND;
            break;
        case 0xDF:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doSTOSKOcommand;
            break;
        case 0xDA:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doMOSAMScommand;
            break;
        case 0xCC:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doBlackRaymanCommand;
            break;
        case 0xB2:
        case 0xB3:
        case 0xF1:
        case 0xF2:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doHerseCommand;
            break;
        case 0xAC:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_STONEWOMAN_COMMAND;
            break;
        case 0x38:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_NOMOVE_STONEWOMAN_COMMAND;
            break;
        case 0x32:
        case 0xE3:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doMoskitoCommand;
            break;
        case 0x7B:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BLKTOON_COMMAND;
            break;
        case 0x16:
        case 0x22:
        case 0x2D:
        case 0x31:
        case 0x3F:
        case 0x4B:
        case 0x4C:
        case 0x6A:
        case 0x8A:
        case 0x8C:
        case 0x9A:
        case 0x9B:
        case 0xBD:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MOVING_PLATFORM_COMMAND;
            break;
        case 0xA2:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MOVING_WITH_INDICATOR_COMMAND;
            break;
        case 0x56:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MOVE_MARACAS_COMMAND;
            break;
        case 0x3:
        case 0x90:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ONE_PINK_CMD;
            break;
        case 0x5:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = TEST_WIZARD;
            break;
        case 0x62:
        case 0xD5:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = doMereDenisCommand;
            break;
        case 0x23:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_STONEMAN1_TIR;
            break;
        case 0x2B:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_STONEMAN2_TIR;
            break;
        case 0x28:
        case 0x7A:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_STONEDOG_COMMAND;
            break;
        case 0x24:
        case 0x2F:
        case 0x45:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_STONEBOMB_COMMAND;
            break;
        case 0x89:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_REDUCTEUR;
            break;
        case 0x9D:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_EAU_QUI_MONTE;
            break;
        case 0x41:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_SPIDER_TIR;
            break;
        case 0x92:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_FLASH_COMMAND;
            break;
        case 0x60:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_TOTEM_COMMAND;
            break;
        case 0x2E:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BBMONT_COMMAND;
            break;
        case 0xC6:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BBMONT2_COMMAND;
            break;
        case 0xC8:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BBMONT3_COMMAND;
            break;
        case 0xC9:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BBMONT4_COMMAND;
            break;
        case 0x4A:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_SAXO_COMMAND;
            break;
        case 0xB4:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_SAXO2_COMMAND;
            break;
        case 0xB7:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_SAXO3_COMMAND;
            break;
        case 0x61:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BBL_COMMAND;
            break;
        case 0x71:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BAG1_COMMAND;
            break;
        case 0x3B:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CAGE2;
            break;
        case 0x79:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ECLAIR_COMMAND;
            break;
        case 0x73:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BB1_PLAT_CMD;
            break;
        case 0x3A:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CAGE;
            break;
        case 0x48:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ONE_NGW_COMMAND;
            break;
        case 0x4D:
        case 0xEF:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ONE_PAR_COMMAND;
            break;
        case 0x49:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ONE_NGW_RING_COMMAND;
            break;
        case 0x4F:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ONE_STONECHIP_COMMAND;
            break;
        case 0x46:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_TRP_COMMAND;
            break;
        case 0x51:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CYMBAL_COMMAND;
            break;
        case 0x14:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_TEN_COMMAND;
            break;
        case 0x64:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MIT_COMMAND;
            break;
        case 0xD9:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MITE2_COMMAND;
            break;
        case 0x47:
        case 0x5C:
        case 0x5D:
        case 0xB6:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_NOTE_CMD;
            break;
        case 0x68:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_POISSON_VERT_CMD;
            break;
        case 0x84:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_POISSON_BLEU_CMD;
            break;
        case 0x55:
        case 0x91:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ROLL_EYES;
            break;
        case 0x74:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CLOWN_TNT_COMMAND;
            break;
        case 0x75:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CLOWN_TNT2_COMMAND;
            break;
        case 0x76:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CLOWN_TNT3_COMMAND;
            break;
        case 0x4E:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PAR_BOMB_COMMAND;
            break;
        case 0x93:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MST_SCROLL_COMMAND;
            break;
        case 0x98:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_CCL_COMMAND;
            break;
        case 0x9C:
        case 0xB9:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_WLKNOT_COMMAND;
            break;
        case 0x99:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_FEE;
            break;
        case 0x96:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_SKO;
            break;
        case 0xA8:
        case 0xA9:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_2_PARTS_CYMBAL;
            break;
        case 0xA5:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PTI_ESQUIVE;
            break;
        case 0xA:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PYRANHA;
            break;
        case 0x25:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_TARZAN;
            break;
        case 0x15:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PHOTOGRAPHE_CMD;
            break;
        case 0x78:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_BAT_COMMAND;
            break;
        case 0xAE:
        case 0xB8:
        case 0xE1:
        case 0xE2:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PIRATE_POELLE;
            break;
        case 0xBB:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_PMA_COMMAND;
            break;
        case 0xBE:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_COU_COMMAND;
            break;
        case 0xC5:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_MEDAILLON_TOON;
            break;
        case 0xC3:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_SPIDER_PLAFOND;
            break;
        case 0xC4:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_DARD_PLAFOND_ALWAYS;
            break;
        case 0xA3:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_IDC_COMMAND;
            break;
        case 0xCE:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = (void (*)(Obj *)) DO_PIEDS_RAYMAN;
            break;
        case 0xCF:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_POELLE_COMMAND;
            break;
        case 0xD4:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_DARK_COMMAND;
            break;
        case 0xD7:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_DARK_SORT_COMMAND;
            break;
        case 0x8F:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_NOVA2_COMMAND;
            break;
        case 0xD8:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ENSEIGNE_COMMAND;
            break;
        case 0xF7:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_VITRAIL_COMMAND;
            break;
        case 0x20:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_DARK_PHASE2_COMMAND;
            break;
        case 0x21:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_DARK2_SORT_COMMAND;
            break;
        case 0x6C:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_DARK2_TOONS_COMMAND;
            break;
        case 0xD1:
        case 0xD2:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DoFlammeCommand;
            break;
        case 0x4:
        case 0x6:
        case 0x7:
        case 0x9:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x26:
        case 0x27:
        case 0x29:
        case 0x2A:
        case 0x2C:
        case 0x30:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x39:
        case 0x3C:
        case 0x3D:
        case 0x40:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x50:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x57:
        case 0x58:
        case 0x5A:
        case 0x5B:
        case 0x5F:
        case 0x63:
        case 0x65:
        case 0x66:
        case 0x67:
        case 0x69:
        case 0x6B:
        case 0x6D:
        case 0x6E:
        case 0x6F:
        case 0x70:
        case 0x72:
        case 0x77:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
        case 0x83:
        case 0x85:
        case 0x87:
        case 0x88:
        case 0x8B:
        case 0x8D:
        case 0x8E:
        case 0x94:
        case 0x95:
        case 0x97:
        case 0x9E:
        case 0x9F:
        case 0xA0:
        case 0xA1:
        case 0xA4:
        case 0xA6:
        case 0xAA:
        case 0xAB:
        case 0xAF:
        case 0xB0:
        case 0xB1:
        case 0xB5:
        case 0xBA:
        case 0xBC:
        case 0xBF:
        case 0xC2:
        case 0xC7:
        case 0xCA:
        case 0xCB:
        case 0xCD:
        case 0xD0:
        case 0xD3:
        case 0xDE:
        case 0xE0:
        case 0xE4:
        case 0xE5:
        case 0xE6:
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xF0:
        case 0xF3:
        case 0xF5:
        case 0xF6:            
        default:
            obj_fonction = &ObjectsFonctions[obj_type];
            sel_fonction = DO_ONE_CMD;
            break;
        }
        obj_fonction->do_obj = sel_fonction;
    }
}
#endif

/* 2FF64 80154764 -O2 -msoft-float */
void build_active_table(void)
{
    Obj *last_obj;
    s32 x_left; s32 x_right;
    s32 y_top; s32 y_bottom;
    Obj *cur_obj;
    s16 *cur_actobj;
    s16 *prev_addr;

    actobj.num_active_objects = 0;
    actobj.objects[0] = -1;
    last_obj = &level.objects[level.nb_objects - 1];
    x_left = xmap - 500;
    x_right = xmap + 820;
    y_top = ymap - 500;
    y_bottom = ymap + 740;
    for (cur_obj = level.objects; cur_obj <= last_obj; cur_obj++)
        cur_obj->flags &= ~FLG(OBJ_FLAG_5);

    for (cur_obj = level.objects; cur_obj <= last_obj; cur_obj++)
    {
        if (!(cur_obj->flags & FLG(OBJ_FLAG_5)))
        {
            if (
                (flags[cur_obj->type].flags0 >> OBJ0_KEEP_ACTIVE & 1) ||
                (
                    cur_obj->x_pos > x_left && cur_obj->x_pos < x_right &&
                    cur_obj->y_pos > y_top && cur_obj->y_pos < y_bottom
                )
            )
                SET_ACTIVE_FLAG(cur_obj->x_pos - xmap, cur_obj->y_pos - ymap, cur_obj);
            else
                cur_obj->flags &= ~FLG(OBJ_ACTIVE);
        }
    }

    cur_actobj = &actobj.objects[actobj.num_active_objects];
    prev_addr = cur_actobj;
    for (cur_obj = level.objects; cur_obj <= last_obj; cur_obj++)
    {
        if (cur_obj->flags & FLG(OBJ_ACTIVE))
        {
            cur_obj->screen_x_pos = cur_obj->x_pos - xmap;
            cur_obj->screen_y_pos = cur_obj->y_pos - ymap;
            *cur_actobj = cur_obj->id;
            cur_actobj++;
        }
    }
    *cur_actobj = -1;

    actobj.num_active_objects += cur_actobj - prev_addr;
}

/* 301D4 801549D4 -O2 -msoft-float */
void Add_One_RAY_lives(void)
{
    status_bar.num_lives++;
    MIN_2(status_bar.num_lives, 99);
    
    if (status_bar.max_hp == 4)
        ray.hit_points = 4;
    else
        ray.hit_points = 2;
}

/* 3022C 80154A2C -O2 -msoft-float */
void DO_CLING_ANIMS(void)
{
    Obj *obj;

    if (id_Cling_1up != -1)
    {
        obj = &level.objects[id_Cling_1up];
        if (obj->timer != 0)
        {
            obj->anim_frame = 0;
            obj->timer--;
        }

        if(EOA(obj))
        {
            id_Cling_1up = -1;
            if (!(ray_mode == MODE_MORT_DE_RAYMAN || ray_mode == MODE_MORT_DE_RAYMAN_ON_MS))
                Add_One_RAY_lives();
            obj->flags &= ~FLG(OBJ_ALIVE);
        }
    }

    if (id_Cling_Pow != -1)
    {
        obj = &level.objects[id_Cling_Pow];
        if (obj->timer != 0)
        {
            obj->anim_frame = 0;
            obj->timer--;
        }

        if(EOA(obj))
        {
            id_Cling_Pow = -1;
            if (!(ray_mode == MODE_MORT_DE_RAYMAN || ray_mode == MODE_MORT_DE_RAYMAN_ON_MS))
            {
                ray.hit_points = 4;
                status_bar.max_hp = 4;
            }
            obj->flags &= ~FLG(OBJ_ALIVE);
        }
    }
}

/* 304D4 80154CD4 -O2 -msoft-float */
void DO_OBJECTS_ANIMS(void)
{
    s16 i = 0;
    Obj *cur_obj = &level.objects[actobj.objects[i]];

    while (i < actobj.num_active_objects)
    {
        if (!(cur_obj->type == TYPE_BLACK_RAY || cur_obj->type == TYPE_BLACK_FIST))
            DO_ANIM(cur_obj);
        i++;
        cur_obj = &level.objects[actobj.objects[i]];
    }
}

/* 30594 80154D94 -O2 -msoft-float */
void DO_OBJECTS(void)
{
    s16 i;
    Obj *cur_obj;
    u8 unk_1;
    s16 *cur_obj_id;
    
    if (!(id_Cling_1up == -1 && id_Cling_Pow == -1))
        DO_CLING_ANIMS();
    if (lidol_to_allocate != 0)
    {
        allocate_toons(lidol_source_obj, 7);
        lidol_to_allocate = 0;
    }

    i = 0;
    cur_obj = &level.objects[actobj.objects[i]];
    while (i < actobj.num_active_objects)
    {
        ot = cur_obj->type;
        unk_1 = FUN_801473dc(cur_obj);
        cur_obj_id = &actobj.objects[i];
        setvol(*cur_obj_id, unk_1);
        unk_1 = FUN_801473d4(cur_obj);
        setpan(*cur_obj_id, unk_1);
        i++;            
        cur_obj = &level.objects[actobj.objects[i]];
    }

    i = 0;
    cur_obj = &level.objects[actobj.objects[i]];
    while (i < actobj.num_active_objects)
    {
        ot = cur_obj->type;
        if (
            flags[ot].flags3 >> OBJ3_SWITCH_OFF & 1 ||
            (ot == TYPE_WIZ && cur_obj->sub_etat == 23) ||
            (ot == TYPE_EXPLOSION && cur_obj->sub_etat == 1) ||
            (ot == TYPE_DARK2_SORT && cur_obj->sub_etat != 35)
        )
            switchOff(cur_obj);
        if (ot != TYPE_WIZ)
        {
            DO_ONE_OBJECT(cur_obj);
            if (
                !(flags[ot].flags0 >> OBJ0_BOSS & 1) &&
                cur_obj->hit_points == 0 &&
                cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 8
            )
                cur_obj->hit_points++;
        }
        i++;
        cur_obj = &level.objects[actobj.objects[i]];
    }
}

/* 3088C 8015508C -O2 -msoft-float */
void MOVE_OBJECTS(void)
{
    s16 i = 0;
    Obj *cur_obj = &level.objects[actobj.objects[i]];
    
    while (i < actobj.num_active_objects)
    {
        MOVE_OBJECT(cur_obj);
        i++;
        cur_obj = &level.objects[actobj.objects[i]];
    }
}

/* 30930 80155130 -O2 -msoft-float */
void RECALE_ALL_OBJECTS(void)
{
    s16 x; s16 y; s16 w; s16 h;
    s16 i = 0;
    Obj *cur_obj = &level.objects[actobj.objects[0]];

    while (i < actobj.num_active_objects)
    {
        calc_obj_pos(cur_obj);
        i++;
        cur_obj = &level.objects[actobj.objects[i]];
    }

    if (ray.field20_0x36 != -1)
    {
        cur_obj = &level.objects[ray.field20_0x36];
        if (cur_obj->flags & FLG(OBJ_ACTIVE))
        {
            GET_SPRITE_POS(cur_obj, cur_obj->follow_sprite, &x, &y, &w, &h);
            ray.y_pos = y + cur_obj->offset_hy - ray.offset_by;
            calc_obj_pos(&ray);
        }
    }
}
