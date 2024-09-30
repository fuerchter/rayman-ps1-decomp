#include "obj_init_kill.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/obj_init_kill", INIT_OBJECTS);*/

void INIT_OBJECTS(u8 newLevel)
{
    Obj *temp_a0_4;
    Obj *temp_a0;
    Obj *temp_v0_5;
    Obj *temp_v1_2;
    Obj *var_s4;
    s16 temp_v0_3;
    s32 temp_a1;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v1;
    s32 var_v1_2;
    s16 temp_lo;
    u16 temp_v0_2;
    u16 temp_v0_4;
    u16 temp_v0_6;
    s16 temp_v1_1;
    s32 test_1;
    u16 temp_v1_3;
    s16 var_s2;
    s16 var_s5;
    s16 var_s7;
    u16 var_v0_1;
    u16 var_v0_6;
    u16 var_v0_7;
    u8 temp_a0_2;
    u8 temp_fp;
    u8 temp_v0;
    u8 temp_v1_4;
    u8 temp_v1_5;
    void *temp_a0_3;

    var_s4 = level.objects;
    temp_fp = level.nb_objects;
    var_s5 = -1;
    var_s7 = -1;
    ray_on_poelle = 0;
    nb_cymbal_in_map = 0;
    PS1_SplashAlwaysObjectsCount = 0;
    IsBossThere = 0;
    PS1_AlwaysObjectsCount = 0;
    Mus_obj_id = -1;
    NumScrollObj = 0;
    rayman_obj_id = -1;
    reduced_rayman_id = -1;
    id_Cling_1up = -1;
    id_Cling_Pow = -1;
    fee_obj_id = -1;
    eau_obj_id = -1;
    mst_scroll_obj_id = -1;
    bateau_obj_id = -1;
    mama_pirate_obj_id = -1;
    black_ray_obj_id = -1;
    pierreAcorde_obj_id = -1;
    nb_wiz = 0;
    stosko_obj_id = -1;
    moskitomama_droite_obj_id = -1;
    moskitomama_gauche_obj_id = -1;
    moskitosaxo_obj_id = -1;
    corde_dark_obj_id = -1;
    var_s2 = 0;
    while ((s16) var_s2 < (s32) temp_fp)
    {
        var_s4->id = var_s2;
        if (newLevel != 0)
        {
            first_obj_init(var_s4);
        }
        var_s4->active_timer = 0;
        if (var_s4->type == 0xA3)
        {
            var_s4->main_etat = (u8) var_s4->init_main_etat;
            var_s4->sub_etat = (u8) var_s4->init_sub_etat;
        }
        obj_init(var_s4);
        if (flags[var_s4->type].flags0 & 1)
        {
            var_s4->x_pos = -0x7D00;
            var_s4->y_pos = -0x7D00;
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
        }
        else
        {
            var_s4->flags = (s32) (var_s4->flags | 0x400);
        }
        temp_v0 = var_s4->type;
        switch (temp_v0)
        {
        case 0xFD:
            var_s4->x_pos = 1U;
            break;
        case 0xFC:
            var_s4->x_pos = (u16) (var_s4->x_pos + 2);
            break;
        case 0x85:
            if (!(RayEvts.super_helico))
            {
                var_v1 = var_s4->flags & ~0x400;
                var_v0_2 = (finBosslevel[1] << 7) & 0x400;
                var_s4->flags = (s32) (var_v1 | var_v0_2);
            }
            else
            {
                var_v0_3 = var_s4->flags & ~0x400;
                var_s4->flags = var_v0_3;
            }
            break;
        case 0x60:
            var_s4->field23_0x3c = 0U;
            var_s4->iframes_timer = 0;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xF6:
            corde_dark_obj_id = (s16) var_s4->id;
            var_s4->flags |= 0x400;
            break;
        case 0xDF:
            var_s4->field23_0x3c = 0U;
            stosko_obj_id = (s16) var_s4->id;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xDA:
            var_s4->field23_0x3c = 0U;
            moskitosaxo_obj_id = (s16) var_s4->id;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xE7:
            var_s5 = var_s4->id;
            var_s4->field23_0x3c = 0U;
            moskitomama_droite_obj_id = (s16) var_s4->id;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xE8:
            var_s7 = var_s4->id;
            var_s4->field23_0x3c = 0U;
            moskitomama_gauche_obj_id = (s16) var_s4->id;
            var_s4->flags |= 0x4000;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xE0:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xDC:
            pierreAcorde_obj_id = (s16) var_s2;
            var_s4->iframes_timer = 0;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xDB:
            var_s4->hit_points = (u8) ((u8) var_s4->init_hit_points >> 2);
            var_s4->flags = (s32) (var_s4->flags | 0x400);
            if (pierreAcorde_obj_id != -1)
            {
                temp_a0 = &level.objects[pierreAcorde_obj_id];
                if ((s16) var_s4->x_pos < temp_a0->x_pos)
                {
                    var_s4->y_pos = (u16) temp_a0->y_pos + 0x70;
                }
                else
                {
                    var_s4->y_pos = (u16) temp_a0->y_pos + 0x78;
                }
                var_s4->y_pos = (u16) var_s4->init_y_pos;
            }
            break;
        case 0xCB:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xB3:
        case 0xF2:
            var_v0_4 = var_s4->flags & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x9D:
            if (var_s4->hit_points != 0)
            {
                test_1 = var_s4->offset_bx;
                temp_v1_1 = xmap - test_1;
                var_s4->x_pos = temp_v1_1;
                if (num_world == 1)
                {
                    if (RayEvts.grain)
                    {
                        var_s4->hit_points = 1U;
                    }
                    var_s4->y_pos = (u16) ((u16) ymapmax + 0xF0);
                }
                else
                {
                    var_s4->hit_points = 0U;
                    var_s4->field23_0x3c = temp_v1_1;
                    if ((num_world != 3) || (num_level != 7))
                    {
                        temp_v0_2 = (u16) ymapmax + 0xA0;
                        var_s4->y_pos = temp_v0_2;
                        var_s4->init_y_pos = temp_v0_2;
                        if (((num_world == 5) && (num_level == 8)) || (num_world == 4))
                        {
                            var_v0_7 = (u16) ymapmax + 0xAA;
                            var_s4->y_pos = var_v0_7;
                            var_s4->init_y_pos = var_v0_7;
                        }
                    }
                    else
                    {
                        var_v0_7 = var_s4->init_y_pos;
                        var_s4->field12_0x26 = 0;
                        var_s4->init_y_pos = var_v0_7;
                    }
                }
                eau_obj_id = (s16) var_s2;
                var_s4->iframes_timer = 0;
                var_s4->flags = (s32) (var_s4->flags | 0xC00);
                calc_obj_pos(var_s4);
            }
            else if ((eau_obj_id != -1) && (num_world != 1))
            {
                var_s4->speed_y = 0;
                var_s4->speed_x = 0;
                var_s4->flags = (s32) (var_s4->flags & ~0x4000);
                temp_v1_2 = &level.objects[eau_obj_id];
                temp_v0_3 = (u16) temp_v1_2->field23_0x3c + 0x65;
                temp_v1_2->field23_0x3c = temp_v0_3;
                var_s4->x_pos = (u16) temp_v0_3;
                temp_v1_3 = (u16) level.objects[eau_obj_id].y_pos;
                var_s4->y_pos = temp_v1_3;
                if ((num_world != 3) || (num_level != 7))
                {
                    var_s4->init_y_pos = (u16) ((u16) ymapmax + 0xA0);
                    if (num_world == 4)
                    {
                        var_s4->init_y_pos = (u16) ((u16) ymapmax + 0xAA);
                    }
                    if ((num_world == 5) && (num_level == 8))
                    {
                        temp_v0_4 = ((u16) level.objects[eau_obj_id].y_pos + eau_obj_id) - var_s4->id;
                        var_s4->y_pos = temp_v0_4;
                        var_s4->init_y_pos = temp_v0_4;
                    }
                }
                else
                {
                    var_s4->init_y_pos = temp_v1_3;
                    var_s4->field12_0x26 = 0;
                }
                calc_obj_pos(var_s4);
                var_s4->flags = (s32) (var_s4->flags | 0xC00);
                temp_v0_5 = &level.objects[eau_obj_id];
                temp_a0_2 = temp_v0_5->hit_points;
                temp_v1_4 = temp_a0_2 + 1;
                temp_v0_5->hit_points = temp_v1_4;
                var_s4->sub_etat = temp_v1_4;
                if ((u8) var_s4->sub_etat >= 4U)
                {
                    var_s4->sub_etat = (u8) (temp_a0_2 + 0xFD);
                }
                var_s4->iframes_timer = 0;
            }
            else
            {
                var_v0_4 = var_s4->flags & ~0x400;
                var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
            }
            break;
        case 0x25:
            var_s4->flags = (var_s4->flags & ~0x400 | (((((u8) RayEvts.grain) ^ 1) & 1) << 0xA));
            break;
        case 0x99:
            fee_obj_id = (s16) var_s2;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x93:
            if (var_s4->hit_points == 0)
            {
                temp_v0_6 = ray.x_pos - 0xC8;
                var_s4->init_x_pos = temp_v0_6;
                var_s4->x_pos = temp_v0_6;
                var_s4->y_pos = (u16) (ray.y_pos - 0x32);
                set_main_and_sub_etat(var_s4, 0U, 9U);
                var_s4->speed_x = 2;
                var_s4->speed_y = 0;
                var_s4->field23_0x3c = 0U;
                var_s4->field24_0x3e = 0U;
                var_s4->timer = 0;
                mst_scroll_obj_id = (s16) var_s2;
                var_s4->flags = (s32) (var_s4->flags | 0x4C00);
            }
            else
            {
                var_v0_3 = var_s4->flags | 0x400;
                var_s4->flags = var_v0_3; break;
            }
            break;
        case 0x88:
            reduced_rayman_id = (s16) var_s2;
            var_v0_4 = var_s4->flags & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x63:
            var_v0_4 = var_s4->flags & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x40:
            scroll_obj_id[NumScrollObj] = (s16) var_s2;
            NumScrollObj += 1;
            var_s4->y_pos = var_s4->init_y_pos;
            var_s4->x_pos = var_s4->init_x_pos;
            var_s4->flags &= ~0x400;
            break;
        case 0x6:
        case 0x8:
        case 0x86:
        case 0xA7:
        case 0xB1:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x9:
        case 0xA5:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x7A:
            var_v0_5 = var_s4->flags;
            var_s4->init_flag = 7;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x51:
            cymbal_obj_id[nb_cymbal_in_map++] = (s16) var_s2;
            /*nb_cymbal_in_map += 1;*/
            var_v1_2 = var_s4->flags | 0x400;
            var_s4->flags = var_v1_2;
            break;
        case 0x17:
            rayman_obj_id = (s16) var_s2;
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xCD:
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
            black_fist_obj_id = (s16) var_s4->id;
            break;
        case 0x5E:
            var_s4->sub_etat =
            var_s4->init_sub_etat =
                poing.sub_etat;
            poing_obj_id = var_s2;
            var_s4->init_flag = 7;
            var_s4->flags = (var_s4->flags & ~0x400);
            break;
        case 0xB:
            sbar_obj_id = (s16) var_s2;
            var_s4->init_flag = 7;
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0x91:
            var_s4->iframes_timer = 0x0028;
            var_v1_2 = var_s4->flags | 0x400;
            var_s4->flags = var_v1_2;
            break;
        case 0x15:
            var_s4->timer = 0;
            break;
        case 0x13:
            PS1_SplashAlwaysObjects[PS1_SplashAlwaysObjectsCount++] = (s16) var_s2;
            /*PS1_SplashAlwaysObjectsCount += 1;*/
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
            break;
        case 0x27:
            var_s4->iframes_timer = 0;
            
        case 0x26:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0x41:
            var_s4->field24_0x3e = 0U;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x4B:
        case 0x4C:
            /*temp_a0_3 = (var_s4->sub_etat * 8) + *((var_s4->main_etat * 4) + var_s4->unk-57);
            temp_lo = (((temp_a0_3->unk2 * 0xC) + var_s4->animations)->unkA - 1) * (temp_a0_3->unk5 & 0xF);*/
            temp_lo = (var_s4->animations
            [var_s4->eta[var_s4->main_etat][var_s4->sub_etat].anim_index].frames_count -
            1) * (var_s4->eta[var_s4->main_etat][var_s4->sub_etat].anim_speed & 0xf);
            var_s4->init_flag = 7;
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
            var_s4->field23_0x3c = temp_lo;
            var_s4->field24_0x3e = temp_lo;
            break;
        case 0x73:
            var_v0_5 = var_s4->flags;
            var_s4->init_flag = 7;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x14:
            var_s4->init_flag = 7;
            var_s4->timer = 0;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x3A:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xD:
        case 0xF:
        case 0x21:
        case 0x24:
        case 0x2C:
        case 0x33:
        case 0x34:
        case 0x3B:
        case 0x3E:
        case 0x42:
        case 0x47:
        case 0x49:
        case 0x4E:
        case 0x4F:
        case 0x53:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x61:
        case 0x66:
        case 0x6C:
        case 0x6E:
        case 0x70:
        case 0x77:
        case 0x79:
        case 0x82:
        case 0x87:
        case 0x8B:
        case 0x8F:
        case 0x92:
        case 0xBA:
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC4:
        case 0xC5:
        case 0xCE:
        case 0xD1:
        case 0xD2:
        case 0xD7:
        case 0xE9:
        case 0xF4:
            var_v0_5 = var_s4->flags;
            var_s4->init_flag = 7;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0xCC:
            var_s4->animations = ray.animations;
            var_s4->init_flag = 7;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            black_ray_obj_id = var_s4->id;
            break;
        case 0xBE:
            var_s4->field20_0x36 = 1;
            var_s4->iframes_timer = 1;
            var_s4->init_flag = 7;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0x3:
            var_s4->init_flag = 7;
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xA:
            if (var_s2 > 0)
            {
                temp_a0_4 = &level.objects[var_s2 - 1];
                var_s4->flags = var_s4->flags | 0x400;
                if ((temp_a0_4->type == 0x0A) && (temp_a0_4->x_pos == var_s4->x_pos))
                {
                    var_s4->flags &= ~0x800;
                    var_s4->flags &= ~0x400;
                }
            }
            break;
        case 0x2E:
        case 0xC6:
        case 0xC8:
            INIT_BBMONT(var_s4);
            break;
        case 0x67:
        case 0x68:
        case 0x84:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x30:
        case 0x95:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x6F:
            if (finBosslevel[1] & 8)
            {
                set_sub_etat(var_s4, 0x0AU);
                var_s4->init_sub_etat = 0x0AU;
            }
            
        case 0x6D:
            var_s4->init_flag = 7;
            PS1_AlwaysObjects[PS1_AlwaysObjectsCount] = (s16) var_s4->id;
            PS1_AlwaysObjectsCount += 1;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x37:
            var_s4->init_flag = 7;
            var_s4->flags = (s32) (var_s4->flags | 0x400);
            Mus_obj_id = (s16) var_s4->id;
            if (finBosslevel[1] & 8)
            {
                var_s4->init_sub_etat = 4U;
                set_main_and_sub_etat(var_s4, 0U, 4U);
            }
            break;
        case 0x52:
        case 0x8E:
        case 0x94:
            var_s4->init_flag = 7;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x4:
        case 0x58:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x9F:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xAD:
            var_s4->field23_0x3c = -1;
            var_s4->field24_0x3e = 0U;
            var_s4->timer = 0;
            bateau_obj_id = (s16) var_s2;
            var_v1_2 = var_s4->flags | 0x400;
            var_s4->flags = var_v1_2;
            break;
        case 0xBB:
            mama_pirate_obj_id = (s16) var_s2;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xEE:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0x20:
            var_v0_5 = var_s4->flags;
            var_s4->init_x_pos = 0U;
            var_s4->x_pos = 0U;
            var_s4->init_y_pos = 0U;
            var_s4->y_pos = 0U;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        }
        if ((t_world_info[world_index].nb_cages == 6) && (var_s4->type == 0x3A))
        {
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            take_bonus((s16) var_s4->id);
        }
        if (((bonus_map == 0) && (((u8) flags[var_s4->type].flags1 >> 1) & 1) && (bonus_taken((s16) var_s4->id) & 0xFF)) || (var_s4->type == 0x9E))
        {
            var_s4->flags &= ~0x800;
            var_s4->flags &= ~0x400;
        }
        if (bonus_map != 0)
        {
            if (var_s4->type == 0xA1)
            {
                nb_wiz += 1;
            }
        }
        var_s2 = var_s2 + 1;
        var_s4 += 1;
    }

    if (((s16) var_s5 != -1) && ((s16) var_s7 != -1))
    {
        level.objects[(s16) var_s5].field24_0x3e = (s16) var_s7;
        level.objects[(s16) var_s7].field24_0x3e = (s16) var_s5;
    }
    if (bonus_map != 0)
    {
        temp_v1_5 = status_bar.num_wiz;
        status_bar.num_wiz = 0;
        nb_wiz_save = (s32) temp_v1_5;
    }
}
const u8 rodata_INIT_OBJECTS[4] = {};

/*INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_ACTIVE_FLAG);*/

void SET_ACTIVE_FLAG(s16 x, s16 y, Obj *obj)
{
    Obj *temp_s0_2;
    Obj *temp_s0_4;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u32 temp_a0;
    u32 temp_v1_1;
    u8 temp_s0_1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 var_a0;
    u8 var_a0_2;
    u8 var_a0_3;
    u8 var_a1;
    u8 var_a1_2;
    Obj *temp_s0_3;

    temp_v1_1 = obj->flags;
    ot = obj->type;
    temp_s0_1 = (temp_v1_1 >> 0xB) & 1;
    obj->flags = temp_v1_1 & ~0x800;
    if (temp_v1_1 & 0x400)
    {
        if ((in_action_zone(x, y, obj, temp_s0_1)) != 0)
        {
            if (obj->active_timer == 0)
            {
                if (
                    (flags[ot].flags1 & 1) ||
                    ((temp_v1_2 = obj->active_flag, (temp_v1_2 != 2)) && ((temp_v1_2 != 4) || (ot == 0x0A)))
                )
                {
                    temp_a0 = (obj->flags & ~0x800) | (temp_s0_1 << 0xB);
                    obj->flags = temp_a0;
                    if (flags[ot].flags0 & 1)
                    {
                        var_a1 = 0;
                        if (!(temp_a0 & 0x800))
                        {
                            var_a1 = flags[obj->type].flags1 & 1;
                        }
                        make_active(obj, var_a1);
                    }
                    else
                    {
                        var_a0 = obj->id;
                        var_v0 = var_a0 * 8;
                        do
                        {
                            temp_s0_2 = &level.objects[((var_v0 - var_a0))];
                            var_a1_2 = 0;
                            if (!(temp_s0_2->flags & 0x800))
                            {
                                var_a1_2 = flags[obj->type].flags1 & 1;
                            }
                            make_active(temp_s0_2, var_a1_2);
                            var_a0 = link_init[temp_s0_2->id];
                            var_v0 = var_a0 * 8;
                        } while ((var_a0 & 0xFF) != obj->id);
                    }

                    return;
                }
            }

            if (obj->active_timer > 0)
            {
                obj->active_timer -= 1;
            }
        }
        else
        {
            obj->active_timer = 0;
            if (((u8) flags[ot].flags2 >> 5) & 1)
            {
                kill_obj(obj);
            }
            else
            {
                temp_v1_3 = obj->active_flag;
                if (temp_v1_3 == 2)
                {
                    obj->active_flag = 1;
                }
                else if (temp_v1_3 == 0 || temp_v1_3 == 4)
                {
                    if (flags[ot].flags0 & 1)
                    {
                        REINIT_OBJECT(obj);
                    }
                    else
                    {
                        obj->active_flag = 4;
                        var_a0_2 = obj->id;
                        obj->flags |= 0x800;
                        var_t0 = 0;
                        if (ot != 0x0A)
                        {
                            var_v0_2 = var_a0_2 * 8;
                            while (true)
                            {
                                temp_s0_3 = &level.objects[((var_v0_2 - var_a0_2))];
                                if (temp_s0_3->active_flag == 4)
                                {
                                    var_a0_2 = link_init[temp_s0_3->id];
                                    var_v0_2 = var_a0_2 * 8;
                                    if ((var_a0_2 & 0xFF) == obj->id)
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    var_t0 = 1;
                                    break;
                                }
                            }

                        }
                        if ((obj->y_pos + obj->offset_by) < -0x1E)
                        {
                            obj->flags &= ~0x800;
                        }
                        if (!(var_t0 & 0xFF))
                        {
                            var_a0_3 = obj->id;
                            var_v0_3 = var_a0_3 * 8;
                            do
                            {
                                temp_s0_4 = &level.objects[((var_v0_3 - var_a0_3))];
                                REINIT_OBJECT(temp_s0_4);
                                var_a0_3 = link_init[temp_s0_4->id];
                                var_v0_3 = var_a0_3 * 8;
                            } while ((var_a0_3 & 0xFF) != obj->id);
                        }
                    }

                }
            }

        }
    }
}