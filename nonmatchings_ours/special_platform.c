#include "special_platform.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/special_platform", DO_SPECIAL_PLATFORM);*/

void DO_SPECIAL_PLATFORM(Obj *obj)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 temp_a0_1;
    s32 temp_a0_2;
    s16 temp_v0_10;
    s16 temp_v0_12;
    s16 temp_v0_14;
    s16 temp_v0_16;
    s16 temp_v0_17;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v0_8;
    s16 temp_v0_9;
    s32 var_v0;
    s32 temp_a0_3;
    s32 temp_a0_5;
    s32 temp_v1_2;
    s32 temp_v1_4;
    u8 var_s1_1;
    u8 var_s1_2;
    s32 var_v1;
    s32 temp_a0_4;
    s32 temp_a0_6;
    u16 temp_v0_11;
    u16 temp_v0_13;
    u16 temp_v0_15;
    u8 temp_s2_1;
    u8 temp_s2_2;
    u8 temp_v0_1;
    u8 temp_v1_1;
    u8 temp_v1_3;
    u8 flag_set;
    u16 test_1;

    var_v1 = 0x200;
    if (RayEvts.demi)
    {
        var_v1 = 0x100;
    }
    temp_v0_1 = var_v1 < __builtin_abs(decalage_en_cours);
    temp_v1_1 = obj->type;
    switch (temp_v1_1)
    {
    case 0x1D:
    case 0x22:
    case 0x98:
    case 0xED:
    case 0xF3:
        if (ray.field20_0x36 == obj->id)
        {
            temp_v0_2 = obj->iframes_timer;
            if ((temp_v0_2 == 0) || (temp_v0_3 = temp_v0_2 - 1, obj->iframes_timer = temp_v0_3, ((temp_v0_3 << 0x10) == 0)))
            {
                button_released = 1;
                temp_v1_2 = (ray.main_etat * 0x100) + ray.sub_etat;
                if (temp_v1_2 <= 0xC)
                {
                    if (temp_v1_2 >= 0xB)
                        RAY_THROW_FIST();
                }
                set_main_and_sub_etat(&ray, 0U, 0U);
                ray_jump();
                obj->ray_dist = 0x2710;
                jump_time = 0x000C;
                ray.speed_y -= 3;
                temp_v1_3 = obj->type;
                if (temp_v1_3 == 0xf3)
                {
                    set_main_and_sub_etat(obj, 0U, 0x11U);
                }
                else if (temp_v1_3 == 0x98)
                {
                    if ((obj->main_etat != 0) || (obj->sub_etat != 2))
                    {
                        set_main_and_sub_etat(obj, 0U, 1U);
                    }
                    else
                    {
                        set_main_and_sub_etat(obj, 0U, 3U);
                    }
                }
                else if (temp_v1_3 == 0xed)
                {
                    if ((obj->main_etat == 0) && (obj->sub_etat == 0))
                    {
                        allocatePaillette(&ray);
                        skipToLabel(obj, 1U, 1U);
                    }
                }
                GET_SPRITE_POS(obj, (s16) obj->follow_sprite, &sp18, &sp1A, &sp1C, &sp1E);
                if (((ray.x_pos + ray.offset_bx) - sp18) < ((s32) ((u16) sp1C << 0x10) >> 0x11))
                {
                    decalage_en_cours = -0x0200;
                    return;
                }
                decalage_en_cours = 0x0200;
                return;
            }
            return;
        }
        obj->iframes_timer = (s16) (u16) obj->field20_0x36;
        return;
    case 0x19:
        if (ray.field20_0x36 == obj->id)
        {
            temp_v0_4 = obj->iframes_timer;
            if ((temp_v0_4 == 0) || (temp_v0_5 = temp_v0_4 - 1, obj->iframes_timer = temp_v0_5, ((temp_v0_5 << 0x10) == 0)))
            {
                GET_SPRITE_POS(obj, (s16) obj->follow_sprite, &sp18, &sp1A, &sp1C, &sp1E);
                RAY_HIT(0U, null);
                if (((ray.x_pos + ray.offset_bx) - sp18) < ((s32) ((u16) sp1C << 0x10) >> 0x11))
                {
                    ray.flags |= 0x4000;
                    return;
                }
                ray.flags &= ~0x4000;
                return;
            }
        }
        else
        {
            obj->iframes_timer = (s16) (u16) obj->field20_0x36;
            return;
        }
        break;
    case 0xBE:
        if ((ray.field20_0x36 == obj->id) && (obj->main_etat == 0) && (obj->sub_etat == 9))
        {
            temp_v0_6 = obj->iframes_timer;
            if ((temp_v0_6 == 0) || (temp_v0_7 = temp_v0_6 - 1, obj->iframes_timer = temp_v0_7, ((temp_v0_7 << 0x10) == 0)))
            {
                button_released = 1;
                temp_v1_4 = (ray.main_etat << 8) + ray.sub_etat;
                if ((temp_v1_4 <= 0xC))
                {
                    if ((temp_v1_4 >= 0xB))
                        RAY_THROW_FIST();
                }
                set_main_and_sub_etat(&ray, 0U, 0U);
                ray_jump();
                obj->ray_dist = 0x2710;
                jump_time = 0x000C;
                ray.speed_y -= 4;
                set_main_and_sub_etat(obj, 0U, 0x0AU);
                GET_SPRITE_POS(obj, (s16) obj->follow_sprite, &sp18, &sp1A, &sp1C, &sp1E);
                if (((ray.x_pos + ray.offset_bx) - sp18) < ((s32) ((u16) sp1C << 0x10) >> 0x11))
                {
                    decalage_en_cours = -0x0200;
                    return;
                }
                decalage_en_cours = 0x0200;
                return;
            }
        }
        else
        {
            obj->iframes_timer = (s16) (u16) obj->field20_0x36;
            return;
        }
        break;
    case 0x4b:
    case 0x4c:
        if (obj->flags & 0x400)
        {
            if ((ray.field20_0x36 == obj->id) || (obj->field24_0x3e != obj->field23_0x3c))
            {
                temp_a0_1 = obj->field24_0x3e;
                if (temp_a0_1 == obj->field23_0x3c)
                {
                    set_sub_etat(obj, 0x0BU);
                    obj->field24_0x3e = obj->field24_0x3e - 1;
                }
                else if ((temp_a0_1 == 0) || (--obj->field24_0x3e == 0))
                {
                    obj_init(obj);
                    obj->flags &= ~0x400;
                    obj->flags &= ~0x800;
                    if (ray.field20_0x36 == obj->id)
                    {
                        ray.field20_0x36 = -1;
                        obj->ray_dist = 0x03E8;
                        set_main_and_sub_etat(&ray, 2U, 2U);
                        Reset_air_speed(temp_v0_1);
                        jump_time = 0;
                        ray.field24_0x3e = 0;
                    }
                }

            }
        }
        else
        {
            obj->ray_dist = 0x03E8;
            return;
        }
        break;
    case 0x1A:
        temp_a0_2 = obj->field24_0x3e;
        if (temp_a0_2 != 0)
        {
            if ((ray.field20_0x36 == obj->id) || (temp_a0_2 != 0x0014))
            {
                if (--obj->field24_0x3e == 0)
                {
                    set_sub_etat(obj, 0x0BU);
                }
            }
        }
        else
        {
            temp_v0_10 = obj->field23_0x3c;
            if (temp_v0_10 != 0)
            {
                obj->field23_0x3c = temp_v0_10 - 1;
                if (num_world == 1)
                {
                    if (horloge[2] != 0)
                    {
                        obj->display_prio = 0;
                    }
                    else
                    {
                        obj->display_prio = 4;
                    }
                }
                if (obj->field23_0x3c <= obj->iframes_timer)
                {
                    if (ray.field20_0x36 == obj->id)
                    {
                        ray.field20_0x36 = -1;
                        set_main_and_sub_etat(&ray, 2U, 1U);
                        Reset_air_speed(temp_v0_1);
                        jump_time = 0;
                        ray.field24_0x3e = 0;
                        obj->ray_dist = 0x2710;
                        ray.speed_y = 0;
                    }
                    obj->flags &= 0xFFFEFFFF;
                    return;
                }
            }
            else if (num_world != 1)
            {
                if (ray.field20_0x36 == obj->id)
                {
                    ray.field20_0x36 = -1;
                    set_main_and_sub_etat(&ray, 2U, 1U);
                    Reset_air_speed(temp_v0_1);
                    jump_time = 0;
                    ray.field24_0x3e = 0;
                    ray.speed_y = 0;
                    obj->ray_dist = 0x2710;
                }
                if (obj->sub_etat == 6)
                {
                    flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
                    if(
                        ((flag_set && obj->anim_frame == 0) ||
                        (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
                        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
                    )
                    {
                        obj_init(obj);
                    }
                }
                if (obj->sub_etat == 0x14)
                {
                    obj->flags |= 0x10000;
                    return;
                }
            }
            else
            {
                obj->flags &= ~0x800;
                obj->active_flag = 4;
                obj->display_prio = 4;
                obj->flags |= 0x10000;
                if (ray.field20_0x36 == obj->id)
                {
                    ray.field20_0x36 = -1;
                    set_main_and_sub_etat(&ray, 2U, 1U);
                    Reset_air_speed(temp_v0_1);
                    jump_time = 0;
                    ray.field24_0x3e = 0;
                    ray.speed_y = 0;
                    obj->ray_dist = 0x2710;
                    return;
                }
            }
        }
        break;
    case 0x44:
        var_s1_1 = 0;
        if (ray.field20_0x36 == obj->id)
        {
            if (obj->main_etat != 2 && obj->field20_0x36 != 0)
            {
                var_s1_1 = 1;
                set_main_and_sub_etat(obj, 2U, 4U);
                temp_v0_11 = (u16) obj->field20_0x36;
                
                obj->field24_0x3e = 0;
                obj->gravity_value_1 = 0;
                obj->gravity_value_2 = 0;
                obj->field20_0x36 = 0;
                temp_v0_12 = temp_v0_11 + 1;
                obj->iframes_timer = temp_v0_12;
                obj->speed_y = temp_v0_12;
            }
            else
            {
                if (obj->iframes_timer == (obj->field20_0x36 + 1))
                {
                    var_s1_1 = 1;
                }
            }
        }
        if (obj->main_etat == 2)
        {
            if (obj->speed_y < -obj->iframes_timer)
            {
                set_main_and_sub_etat(obj, 0U, 2U);
                obj->iframes_timer = 0;
                obj->y_pos = obj->init_y_pos;
                obj->speed_y = 0;
                
                if (ray.field20_0x36 == obj->id)
                {
                    ray.y_pos += obj->init_y_pos - obj->y_pos;
                    temp_a0_3 = (ray.main_etat << 8) + ray.sub_etat;
                    if ((temp_a0_3 <= 0xC))
                    {
                        if ((temp_a0_3 >= 0xB))
                            RAY_THROW_FIST();
                    }
                    set_main_and_sub_etat(&ray, 0U, 0U);
                    button_released = 1;
                    ray_jump();
                    obj->ray_dist = 0x2710;
                    jump_time = 0x000C;
                }
                return;
            }
            test_1 = 1;
            if (!(var_s1_1) && (ray.field20_0x36 == obj->id) && ((button_released & 1) == test_1) && ((options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e) << 0x10) != 0))
            {
                ray_jump();
                if (ray.main_etat == 2)
                {
                    obj->ray_dist = 0x2710;
                }
                temp_a0_4 = (u16) obj->speed_y;
                if (((temp_a0_4 + 2) & 0xFFFF) >= 5U)
                {
                    if ((s16) temp_a0_4 < -2)
                    {
                        ray.speed_y = ray.speed_y - 2;
                        ray.speed_y += temp_a0_4;
                    }
                }
                else
                {
                    ray.speed_y -= 2;
                }
            }
        }
        break;
    case 0x1B:
        var_s1_1 = 0;
        if (ray.field20_0x36 == obj->id)
        {
            if (obj->main_etat != 2 && obj->field20_0x36 != 0)
            {
                var_s1_1 = 1;
                set_main_and_sub_etat(obj, 2U, 3U);
                temp_v0_11 = (u16) obj->field20_0x36;
                
                obj->field24_0x3e = 0;
                obj->gravity_value_1 = 0;
                obj->gravity_value_2 = 0;
                obj->field20_0x36 = 0;
                temp_v0_12 = temp_v0_11 + 1;
                obj->iframes_timer = temp_v0_12;
                obj->speed_y = temp_v0_12;
            }
            else
            {
                if (obj->iframes_timer == (obj->field20_0x36 + 1))
                {
                    var_s1_1 = 1;
                }
            }
        }
        if (obj->main_etat == 2)
        {
            if (obj->speed_y < -obj->iframes_timer)
            {
                set_main_and_sub_etat(obj, 0U, 0x18U);
                obj->iframes_timer = 0;
                obj->speed_y = 0;
                if (ray.field20_0x36 == obj->id)
                {
                    ray.y_pos += (u16) obj->init_y_pos - (u16) obj->y_pos;
                    temp_a0_5 = (ray.main_etat << 8) + ray.sub_etat;
                    if ((temp_a0_5 < 0xD))
                    {
                        if ((temp_a0_5 >= 0xB))
                            RAY_THROW_FIST();
                    }
                    set_main_and_sub_etat(&ray, 0U, 0U);
                    button_released = 1;
                    ray_jump();
                    obj->ray_dist = 0x2710;
                    jump_time = 0x000C;
                }
                obj->y_pos = (s16) (u16) obj->init_y_pos;
                return;
            }
            test_1 = 1;
            if (!(var_s1_1) && (ray.field20_0x36 == obj->id) && ((button_released & 1) == test_1) && ((options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e) << 0x10) != 0))
            {
                ray_jump();
                if (ray.main_etat == 2)
                {
                    obj->ray_dist = 0x2710;
                }
                temp_a0_6 = (u16) obj->speed_y;
                if ((u32) ((temp_a0_6 + 2) & 0xFFFF) < 5U)
                {
                    ray.speed_y -= 2;
                    return;
                }
                if ((s16) temp_a0_6 < -2)
                {
                    ray.speed_y += temp_a0_6;
                    if (ray.speed_y < -7)
                    {
                        ray.speed_y = -7;
                    }
                }
            }
        }
        break;
    case 0x1C:
        if (obj->sub_etat == 0x14)
        {
            temp_v0_16 = obj->iframes_timer;
            if (temp_v0_16 == 0)
            {
                obj->iframes_timer = (s16) (u16) obj->field20_0x36;
                if (num_world != 1)
                {
                    set_sub_etat(obj, 7U);
                }
                else if (obj->display_prio != 0)
                {
                    obj->display_prio = 0;
                }
                else
                {
                    obj->display_prio = 3;
                }
            }
            else
            {
                obj->iframes_timer = temp_v0_16 - 1;
            }
        }

        if (
            !(num_world == 1 && obj->display_prio != 0) &&
            (num_world == 1 || obj->sub_etat != 0x14)
        )
        {
            if (ray.field20_0x36 == obj->id)
            {
                ray.field20_0x36 = -1;
                set_main_and_sub_etat(&ray, 2U, 2U);
                Reset_air_speed(temp_v0_1);
                jump_time = 0;
                ray.field24_0x3e = 0;
                ray.speed_y = 0;
            }
            obj->ray_dist = 0x03E8;
        }
        break;
    case 0x73:
        if (obj->sub_etat == 7)
        {
            if ((obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1)) && (horloge[obj->eta[obj->main_etat][7].anim_speed & 0xf] == 0))
            {
                obj->flags &= ~0x800;
                obj->flags &= ~0x400;
            }
            if (ray.field20_0x36 == obj->id)
            {
                ray.field20_0x36 = -1;
                set_main_and_sub_etat(&ray, 2U, 2U);
                Reset_air_speed(temp_v0_1);
                jump_time = 0;
                ray.field24_0x3e = 0;
                ray.speed_y = 0;
            }
            obj->ray_dist = 0x03E8;
        }
        if (obj->sub_etat == 0x14)
        {
            if ((ray.field20_0x36 == obj->id) || (obj->field24_0x3e != obj->field23_0x3c))
            {
                obj->field24_0x3e = (u16) obj->field24_0x3e - 1;
            }
            temp_v0_17 = obj->iframes_timer;
            if ((temp_v0_17 == 0) || (obj->field24_0x3e == 0))
            {
                set_sub_etat(obj, 7U);
                return;
            }
            obj->iframes_timer = temp_v0_17 - 1;
        }
        break;
    }

}