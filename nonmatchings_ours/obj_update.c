#include "obj_update.h"

/* matches, but case 3 and 4??? */
/*INCLUDE_ASM("asm/nonmatchings/obj_update", DO_PESANTEUR);*/

s32 DO_PESANTEUR(Obj *obj)
{
    s16 temp_v0;
    s16 y_accel;
    s32 res;
    u8 temp_v1_1;

    res = 0;
    y_accel = 0;
    temp_v1_1 = obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4;
    if (temp_v1_1 != 0)
    {
        if (obj->type == TYPE_TAMBOUR1 || obj->type == TYPE_TAMBOUR2)
        {
            if (obj->field56_0x69 != 0)
                obj->field56_0x69--;
            else if (obj->gravity_value_1 == 0)
            {
                obj->speed_y++;
                res = 1;
            }
        }
        else
        {
            switch (temp_v1_1)
            {
            case 6:
                if (horloge[2] == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 1:
                if (obj->gravity_value_1 == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 2:
                if (obj->gravity_value_2 == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 3:
                temp_v0 = obj->speed_y;
                if (temp_v0 > 0)
                {
                    if (temp_v0 > 1)
                    {
                        y_accel = -1;
                    }
                }
                else
                {
                    y_accel = 1;
                }
                break;
            case 4:
                temp_v0 = obj->speed_y;
                if (temp_v0 < -1)
                {
                    if (temp_v0 < -2)
                    {
                        y_accel = 1;
                    }
                }
                else
                {
                    y_accel = -1;
                }
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
                    res = 1;
                }
                break;
            case 11:
                obj->gravity_value_1++;
                if (obj->gravity_value_1 >= obj->gravity_value_2)
                {
                    obj->gravity_value_1 = 0;
                    y_accel = -1;
                    res = 1;
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

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/obj_update", OBJ_IN_THE_AIR);*/

void OBJ_IN_THE_AIR(Obj *obj)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_v0;
    s32 temp_s1;
    u8 temp_v0_3;
    u8 temp_v1_1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 var_a1;

    if ((u32) (((u8) obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4) - 0xA) >= 2U)
    {
        obj->gravity_value_1 += 1;
        if ((u8) obj->gravity_value_1 >= 3U)
        {
            obj->gravity_value_1 = 0;
        }
        obj->gravity_value_2 += 1;
        if ((u8) obj->gravity_value_2 >= 4U)
        {
            obj->gravity_value_2 = 0;
        }
    }
    temp_s1 = DO_PESANTEUR(obj);
    if (obj->type == 0x3)
    {
        if ((obj->speed_y >= 0) && (obj->sub_etat == 0))
        {
            set_sub_etat(obj, 1U);
        }
        if ((gerbe == 0) && (obj->speed_y >= 3) && (obj->sub_etat == 1))
        {
            set_sub_etat(obj, 2U);
            obj->speed_x = 0;
        }
    }
    else if (obj->type == 0x28 || obj->type == 0x7A)
    {
        stoneDogBounces(obj);
        temp_v1_2 = obj->main_etat;
        if (temp_v1_2 == 2)
        {
            temp_v0 = obj->speed_y;
            if (temp_v0 > 0)
            {
                if (obj->sub_etat != temp_v1_2)
                {
                    set_sub_etat(obj, 2U);
                }
            }
            else if ((temp_v0 < 0) && (block_flags[calc_typ_trav(obj, 1U) & 0xFF] & 1))
            {
                obj->speed_y = 0;
            }
        }
    }
    else if (obj->type == 0x5B)
    {
        if (--obj->iframes_timer == 0)
        {
            DO_EXPLOSE_NOTE1(obj);
        }
    }

    if ((((u8) flags[obj->type].flags3 >> 2) & 1) && (obj->speed_y < 0))
    {
        if (obj->flags & 0x10000)
        {
            GET_SPRITE_POS(obj, (s16) obj->follow_sprite, &sp18, &sp1A, &sp1C, &sp1E);
            sp18 = obj->offset_bx + (u16) obj->x_pos;
            sp1A = obj->offset_hy + (u16) sp1A;
        }
        else
        {
            sp18 = obj->offset_bx + (u16) obj->x_pos;
            sp1A = obj->offset_hy + (u16) obj->y_pos;
        }
        if (((u8) block_flags[PS1_BTYPAbsPos((s32) sp18, sp1A + obj->speed_y)] >> 4) & 1)
        {
            obj->speed_y = 0;
        }
    }
    if ((flags[obj->type].flags2 & 1) && (((u8) block_flags[obj->btypes[0]] >> 1) & 1))
    {
        switch (obj->type)
        {
        case 0x46:
            trompetteAtter(obj);
            break;
        case 0xDA:
            calc_obj_dir(obj);
            recale_position(obj);
            skipToLabel(obj, 3U, 1U);
            if (ray.main_etat != 2)
            {
                allocateLandingSmoke(obj);
                set_main_and_sub_etat((Obj *) (&ray.main_etat - 0x56), 0U, 0U);
                button_released = 1;
                ray_jump();
                ray.speed_y = -8;
            }
            screen_trembling = 1;
            break;
        case 0x7B:
            temp_v0_3 = obj->follow_sprite;
            switch (temp_v0_3)
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
                set_main_and_sub_etat(obj, 1U, 0U);
                if (obj->flags & 0x4000)
                {
                    skipToLabel(obj, 3, 1U);
                }
                else
                {
                    skipToLabel(obj, 2, 1U);
                }
                
                recale_position(obj);
                obj->speed_y = 0;
                break;
            case 2:
                set_main_and_sub_etat(obj, 0U, 0U);
                recale_position(obj);
                obj->speed_y = 0;
                break;
            }
            break;
        case 0x70:
            if (obj->speed_y > 0)
            {
                recale_position(obj);
                obj->speed_y = -(s16) (u16) obj->speed_y;
            }
            break;
        case 0x3E:
            Drop_Atter(obj);
            break;
        case 0x64:
        case 0xD9:
            MiteAtter(obj);
            break;
        case 0xAC:
            if (obj->speed_y >= 0)
            {
                skipToLabel(obj, 0x10U, 1U);
                obj->field56_0x69 = 0;
            }
            break;
        case 0x77:
            PlaySnd(0x00BB, obj->id);
            BombExplosion(obj);
            break;
        case 0x0:
        case 0x9:
        case 0xA5:
            BadGuyAtter(obj);
            break;
        case 0x2F:
        case 0x45:
            if (obj->speed_y != 0)
            {
                PlaySnd(0x00C8, obj->id);
            }
            DO_STONEBOMB_REBOND(obj);
            break;
        case 0x24:
            if (obj->speed_y != 0)
            {
                PlaySnd(0x00C8, obj->id);
            }
            DO_THROWN_BOMB_REBOND(obj, (s16) temp_s1, 1);
            break;
        case 0x28:
        case 0x7A:
            stoneDogAtter(obj);
            break;
        case 0x4E:
            DO_FRUIT_REBOND(obj, (s16) temp_s1, 1);
            break;
        case 0x35:
            if (obj->field23_0x3c != 0)
            {
                PlaySnd(0x002D, obj->id);
                obj->speed_y = 6;
                DO_FRUIT_REBOND(obj, 1, 1);
                obj->field23_0x3c = (u16) obj->field23_0x3c - 1;
            }
            break;
        case 0x33:
            if (obj->field23_0x3c != 0)
            {
                PlaySnd(0x002D, obj->id);
                obj->speed_y = 7;
                DO_FRUIT_REBOND(obj, 1, 1);
                obj->field23_0x3c = (u16) obj->field23_0x3c - 1;
            }
            break;
        case 0x34:
            if (obj->field23_0x3c != 0)
            {
                PlaySnd(0x002D, obj->id);
                obj->speed_y = 6;
                DO_THROWN_BOMB_REBOND(obj, 1, 1);
                obj->field23_0x3c = (u16) obj->field23_0x3c - 1;
            }
            break;
        case 0x6:
        case 0x8:
        case 0x26:
        case 0x82:
        case 0x86:
        case 0xA7:
        case 0xB1:
            temp_v1_4 = obj->type;
            switch (temp_v1_4)
            {
            case 0xA7:
            case 0x86:
            case 0x8:
                PlaySnd(0x002D, obj->id);
                break;
            case 0xB1:
            case 0x6:
                PlaySnd(0x008C, obj->id);
                break;
            case 0x82:
            case 0x26:
                PlaySnd(0, obj->id);
                break;
            }
            DO_FRUIT_REBOND(obj, (s16) temp_s1, 0);
            break;
        case 0x3A:
            set_main_and_sub_etat(obj, 0U, 0x0BU);
            obj->speed_y = 0;
            break;
        case 0x3:
            LidolPinkAtter(obj);
            break;
        case 0x4D:
        case 0xEF:
            if (obj->sub_etat == 2)
            {
                set_main_and_sub_etat(obj, 0U, 7U);
            }
            else if (obj->speed_y >= 0)
            {
                set_main_and_sub_etat(obj, 0U, 0x0AU);
            }
            recale_position(obj);
            obj->speed_y = 0;
            obj->speed_x = 0;
            break;
        case 0x48:
            recale_position(obj);
            set_main_and_sub_etat(obj, 0U, 5U);
            obj->speed_y = 0;
            obj->speed_x = 0;
            break;
        case 0x85:
            obj->speed_x = 0;
            obj->speed_y = 0;
            break;
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0xB6:
            DO_NOTE_REBOND(obj);
            break;
        case 0x61:
            DO_BBL_REBOND(obj);
            break;
        case 0x3C:
        case 0x3D:
            Clown_Music_Atter(obj);
            break;
        case 0x41:
            Spider_Atter(obj);
            break;
        case 0x2E:
            if (obj->iframes_timer < 0xA)
            {
                DO_BBMONT_ATTER(obj);
            }
            break;
        case 0xC6:
            DO_BBMONT2_ATTER(obj);
            break;
        case 0xC8:
            DO_BBMONT3_ATTER(obj);
            break;
        case 0xB4:
            DO_SAXO2_ATTER(obj);
            break;
        case 0x4A:
            DO_SAXO_ATTER(obj);
            break;
        case 0xBB:
            DO_PMA_ATTER(obj);
            break;
        case 0xBE:
            DO_COU_ATTER(obj);
            break;
        case 0xD3:
            DO_TOTBT_REBOND(obj);
            break;
        case 0xC3:
            if ((obj->main_etat == 2) && (obj->speed_y > 0))
            {
                set_main_and_sub_etat(obj, 0U, 0x1DU);
                obj->speed_x = 0;
                obj->speed_y = 0;
                temp_v0_2 = ray.x_pos > obj->x_pos;
                obj->flags = (obj->flags & ~0x4000) | ((temp_v0_2) << 0xE);
            }
            break;
        case TYPE_BALLE1:
        case TYPE_BALLE2:
        case TYPE_BOING_PLAT:
        case TYPE_DARK_PHASE2:
        case TYPE_MOSKITO:
        case TYPE_BIG_BOING_PLAT:
        case TYPE_RING:
        case TYPE_TAMBOUR1:
        case TYPE_TAMBOUR2:
        case TYPE_SPACE_MAMA:
        case TYPE_BNOTE:
        case TYPE_POI1:
        case TYPE_POI2:
        case TYPE_PI_BOUM:
        case TYPE_POI3:
        case TYPE_MARACAS_BAS:
        case TYPE_MST_SCROLL:
        case TYPE_SCORPION:
        case TYPE_BULLET:
        case TYPE_BLACK_RAY:
        case TYPE_BLACK_FIST:
        case TYPE_DARK:
        case TYPE_SPACE_MAMA2:
        case TYPE_CORDEBAS:
        case TYPE_MOSKITO2:
            break;
        default:
            NormalAtter(obj);
            break;
        }
    }
    if (((u8) flags[obj->type].flags1 >> 5) & 1)
    {
        if (obj->speed_y >= 0x61)
        {
            obj->speed_y = 0x0060;
        }
        if (obj->speed_y < -0x80)
        {
            obj->speed_y = -0x0080;
        }
    }
    else
    {
        if (obj->speed_y >= 7)
        {
            obj->speed_y = 6;
        }
        if (obj->speed_y < -8)
        {
            obj->speed_y = -8;
        }
    }
}

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