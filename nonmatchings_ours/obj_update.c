#include "obj_update.h"

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