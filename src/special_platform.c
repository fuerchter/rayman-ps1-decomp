#include "special_platform.h"

void allocatePaillette(Obj *obj);

/* 3FFAC 801647AC -O2 -msoft-float */
#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/special_platform", DO_SPECIAL_PLATFORM);
#else
/* clean up further */
void DO_SPECIAL_PLATFORM(Obj *plat_obj)
{
    ObjType obj_type;
    s16 plat_x; s16 plat_y; s16 plat_w; s16 plat_h;
    u8 unk_2;
    u16 test_1;
    s32 temp_a0_4;
    s32 temp_a0_6;
    s32 unk_1 = RayEvts.demi ? 0x0100 : 0x0200;
    u8 is_rolling_speed = unk_1 < __builtin_abs(decalage_en_cours);

    switch (plat_obj->type)
    {
    case TYPE_AUTOJUMP_PLAT:
    case TYPE_MOVE_AUTOJUMP_PLAT:
    case TYPE_CAISSE_CLAIRE:
    case TYPE_GOMME:
    case TYPE_MARK_AUTOJUMP_PLAT:
        if (ray.field20_0x36 == plat_obj->id)
        {
            if (plat_obj->iframes_timer == 0 || --plat_obj->iframes_timer == 0)
            {
                button_released = 1;
                switch (ray.main_etat * 0x100 + ray.sub_etat)
                {
                case 0xb:
                case 0xc:
                    RAY_THROW_FIST();
                    break;
                }

                set_main_and_sub_etat(&ray, 0, 0);
                ray_jump();
                plat_obj->ray_dist = 10000;
                jump_time = 12;
                ray.speed_y -= 3;
                obj_type = plat_obj->type;
                if (obj_type == TYPE_MARK_AUTOJUMP_PLAT)
                    set_main_and_sub_etat(plat_obj, 0, 17);
                else if (obj_type == TYPE_CAISSE_CLAIRE)
                {
                    if (!(plat_obj->main_etat == 0 && plat_obj->sub_etat == 2))
                        set_main_and_sub_etat(plat_obj, 0, 1);
                    else
                        set_main_and_sub_etat(plat_obj, 0, 3);
                }
                else if (obj_type == TYPE_GOMME)
                {
                    if (plat_obj->main_etat == 0 && plat_obj->sub_etat == 0)
                    {
                        allocatePaillette(&ray);
                        skipToLabel(plat_obj, 1, true);
                    }
                }
                GET_SPRITE_POS(plat_obj, plat_obj->follow_sprite, &plat_x, &plat_y, &plat_w, &plat_h);
                if (ray.x_pos + ray.offset_bx - plat_x < plat_w >> 1) /* TODO: ternary? */
                    decalage_en_cours = -0x0200;
                else
                    decalage_en_cours = 0x0200;
            }
        }
        else
            plat_obj->iframes_timer = plat_obj->field20_0x36;
        break;
    case TYPE_INST_PLAT:
        if (ray.field20_0x36 == plat_obj->id)
        {
            if (plat_obj->iframes_timer == 0 || --plat_obj->iframes_timer == 0)
            {
                GET_SPRITE_POS(plat_obj, plat_obj->follow_sprite, &plat_x, &plat_y, &plat_w, &plat_h);
                RAY_HIT(false, null);
                if (ray.x_pos + ray.offset_bx - plat_x < plat_w >> 1)
                    ray.flags |= FLG(OBJ_FLIP_X);
                else
                    ray.flags &= ~FLG(OBJ_FLIP_X);
            }
        }
        else
            plat_obj->iframes_timer = plat_obj->field20_0x36;
        break;
    case TYPE_COUTEAU:
        if (
            ray.field20_0x36 == plat_obj->id &&
            plat_obj->main_etat == 0 && plat_obj->sub_etat == 9
        )
        {
            if (plat_obj->iframes_timer == 0 || --plat_obj->iframes_timer == 0)
            {
                button_released = 1;
                switch (ray.main_etat * 0x100 + ray.sub_etat)
                {
                case 0xb:
                case 0xc:
                    RAY_THROW_FIST();
                    break;
                }

                set_main_and_sub_etat(&ray, 0, 0);
                ray_jump();
                plat_obj->ray_dist = 10000;
                jump_time = 12;
                ray.speed_y -= 4;
                set_main_and_sub_etat(plat_obj, 0, 10);
                GET_SPRITE_POS(plat_obj, plat_obj->follow_sprite, &plat_x, &plat_y, &plat_w, &plat_h);
                if (ray.x_pos + ray.offset_bx - plat_x < plat_w >> 1)
                    decalage_en_cours = -0x0200;
                else
                    decalage_en_cours = 0x0200;
            }
        }
        else
            plat_obj->iframes_timer = plat_obj->field20_0x36;
        break;
    case TYPE_PAILLETTE:
    case TYPE_DESTROYING_DOOR:
        if (plat_obj->flags & FLG(OBJ_ALIVE))
        {
            if (ray.field20_0x36 == plat_obj->id || plat_obj->field24_0x3e != plat_obj->field23_0x3c)
            {
                if (plat_obj->field24_0x3e == plat_obj->field23_0x3c)
                {
                    set_sub_etat(plat_obj, 11);
                    plat_obj->field24_0x3e--;
                }
                else if (plat_obj->field24_0x3e == 0 || --plat_obj->field24_0x3e == 0)
                {
                    obj_init(plat_obj);
                    plat_obj->flags &= ~FLG(OBJ_ALIVE);
                    plat_obj->flags &= ~FLG(OBJ_ACTIVE);
                    if (ray.field20_0x36 == plat_obj->id)
                    {
                        ray.field20_0x36 = -1;
                        plat_obj->ray_dist = 1000;
                        set_main_and_sub_etat(&ray, 2, 2);
                        Reset_air_speed(is_rolling_speed);
                        jump_time = 0;
                        ray.field24_0x3e = 0;
                    }
                }
            }
        }
        else
            plat_obj->ray_dist = 1000;
        break;
    case TYPE_CRUMBLE_PLAT:
        if (plat_obj->field24_0x3e != 0)
        {
            if (
                (ray.field20_0x36 == plat_obj->id || plat_obj->field24_0x3e != 0x0014) &&
                --plat_obj->field24_0x3e == 0
            )
                set_sub_etat(plat_obj, 11);
        }
        else
        {
            if (plat_obj->field23_0x3c != 0)
            {
                plat_obj->field23_0x3c--;
                if (num_world == 1)
                {
                    if (horloge[2] != 0) /* TODO: ternary? */
                        plat_obj->display_prio = 0;
                    else
                        plat_obj->display_prio = 4;
                }

                if (plat_obj->field23_0x3c <= plat_obj->iframes_timer)
                {
                    if (ray.field20_0x36 == plat_obj->id)
                    {
                        ray.field20_0x36 = -1;
                        set_main_and_sub_etat(&ray, 2, 1);
                        Reset_air_speed(is_rolling_speed);
                        jump_time = 0;
                        ray.field24_0x3e = 0;
                        plat_obj->ray_dist = 10000;
                        ray.speed_y = 0;
                    }
                    plat_obj->flags &= ~FLG(OBJ_FOLLOW_ENABLED);
                }
            }
            else if (num_world != 1) /* this? or else{} then nest? */
            {
                if (ray.field20_0x36 == plat_obj->id)
                {
                    ray.field20_0x36 = -1;
                    set_main_and_sub_etat(&ray, 2, 1);
                    Reset_air_speed(is_rolling_speed);
                    jump_time = 0;
                    ray.field24_0x3e = 0;
                    ray.speed_y = 0;
                    plat_obj->ray_dist = 10000;
                }

                if (plat_obj->sub_etat == 6 && EOA(plat_obj))
                    obj_init(plat_obj);

                if (plat_obj->sub_etat == 20)
                    plat_obj->flags |= FLG(OBJ_FOLLOW_ENABLED);
            }
            else
            {
                plat_obj->flags &= ~FLG(OBJ_ACTIVE);
                plat_obj->active_flag = ACTIVE_SPECIAL;
                plat_obj->display_prio = 4;
                plat_obj->flags |= FLG(OBJ_FOLLOW_ENABLED);
                if (ray.field20_0x36 == plat_obj->id)
                {
                    ray.field20_0x36 = -1;
                    set_main_and_sub_etat(&ray, 2, 1);
                    Reset_air_speed(is_rolling_speed);
                    jump_time = 0;
                    ray.field24_0x3e = 0;
                    ray.speed_y = 0;
                    plat_obj->ray_dist = 10000;
                }
            }
        }
        break;
    case TYPE_BIG_BOING_PLAT:
        unk_2 = false;
        if (ray.field20_0x36 == plat_obj->id)
        {
            if (!(plat_obj->main_etat == 2 || plat_obj->field20_0x36 == 0))
            {
                unk_2 = true;
                set_main_and_sub_etat(plat_obj, 2, 4);
                plat_obj->field24_0x3e = 0;
                plat_obj->gravity_value_1 = 0;
                plat_obj->gravity_value_2 = 0;
                plat_obj->speed_y =
                plat_obj->iframes_timer =
                    plat_obj->field20_0x36 + 1;
                plat_obj->field20_0x36 = 0;
            }
            else if (plat_obj->iframes_timer == plat_obj->field20_0x36 + 1)
                unk_2 = true;
        }
        if (plat_obj->main_etat == 2)
        {
            if (plat_obj->speed_y < -plat_obj->iframes_timer)
            {
                set_main_and_sub_etat(plat_obj, 0, 2);
                plat_obj->iframes_timer = 0;
                plat_obj->y_pos = plat_obj->init_y_pos;
                plat_obj->speed_y = 0;

                if (ray.field20_0x36 == plat_obj->id)
                {
                    ray.y_pos += plat_obj->init_y_pos - plat_obj->y_pos;
                    switch (ray.main_etat * 0x100 + ray.sub_etat)
                    {
                    case 0xb:
                    case 0xc:
                        RAY_THROW_FIST();
                        break;
                    }

                    set_main_and_sub_etat(&ray, 0, 0);
                    button_released = 1;
                    ray_jump();
                    plat_obj->ray_dist = 10000;
                    jump_time = 12;
                }
            }
            else
            {
                test_1 = 1; /* TODO: remove? */
                if (
                    !unk_2 && ray.field20_0x36 == plat_obj->id &&
                    (button_released & 1) == test_1 &&
                    options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e)
                )
                {
                    ray_jump();
                    if (ray.main_etat == 2)
                        plat_obj->ray_dist = 10000;

                    /* TODO: ??? */
                    temp_a0_4 = (u16) plat_obj->speed_y;
                    if ((u16) (temp_a0_4 + 2) >= 5U)
                    {
                        if ((s16) temp_a0_4 < -2)
                        {
                            ray.speed_y -= 2;
                            ray.speed_y += temp_a0_4;
                        }
                    }
                    else
                    {
                        ray.speed_y -= 2;
                    }
                }
            }
        }
        break;
    case TYPE_BOING_PLAT:
        unk_2 = false;
        if (ray.field20_0x36 == plat_obj->id)
        {
            if (!(plat_obj->main_etat == 2 || plat_obj->field20_0x36 == 0))
            {
                unk_2 = true;
                set_main_and_sub_etat(plat_obj, 2, 3);
                plat_obj->field24_0x3e = 0;
                plat_obj->gravity_value_1 = 0;
                plat_obj->gravity_value_2 = 0;
                plat_obj->speed_y =
                plat_obj->iframes_timer =
                    plat_obj->field20_0x36 + 1;
                plat_obj->field20_0x36 = 0;
            }
            else if (plat_obj->iframes_timer == plat_obj->field20_0x36 + 1)
                unk_2 = true;
        }

        if (plat_obj->main_etat == 2)
        {
            if (plat_obj->speed_y < -plat_obj->iframes_timer)
            {
                set_main_and_sub_etat(plat_obj, 0, 24);
                plat_obj->iframes_timer = 0;
                plat_obj->speed_y = 0;
                if (ray.field20_0x36 == plat_obj->id)
                {
                    ray.y_pos += plat_obj->init_y_pos - plat_obj->y_pos;
                    switch (ray.main_etat * 0x100 + ray.sub_etat)
                    {
                    case 0xb:
                    case 0xc:
                        RAY_THROW_FIST();
                        break;
                    }

                    set_main_and_sub_etat(&ray, 0, 0);
                    button_released = 1;
                    ray_jump();
                    plat_obj->ray_dist = 10000;
                    jump_time = 12;
                }
                plat_obj->y_pos = plat_obj->init_y_pos;
            }
            else
            {
                test_1 = 1;
                if (
                    !unk_2 && ray.field20_0x36 == plat_obj->id &&
                    (button_released & 1) == test_1 &&
                    options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e)
                )
                {
                    ray_jump();
                    if (ray.main_etat == 2)
                        plat_obj->ray_dist = 10000;

                    temp_a0_6 = (u16) plat_obj->speed_y;
                    if ((u16) ((temp_a0_6 + 2)) < 5U)
                    {
                        ray.speed_y -= 2;
                    }
                    else if ((s16) temp_a0_6 < -2)
                    {
                        ray.speed_y += temp_a0_6;
                        MAX_2(ray.speed_y, -7);
                    }
                }
            }
        }
        break;
    case TYPE_ONOFF_PLAT:
        if (plat_obj->sub_etat == 20)
        {
            if (plat_obj->iframes_timer == 0)
            {
                plat_obj->iframes_timer = plat_obj->field20_0x36;
                if (num_world != 1)
                    set_sub_etat(plat_obj, 7);
                else
                {
                    if (plat_obj->display_prio != 0)
                        plat_obj->display_prio = 0;
                    else
                        plat_obj->display_prio = 3;
                }
            }
            else
                plat_obj->iframes_timer--;
        }

        if (
            (num_world != 1 || plat_obj->display_prio == 0) &&
            (num_world == 1 || plat_obj->sub_etat != 20)
        )
        {
            if (ray.field20_0x36 == plat_obj->id)
            {
                ray.field20_0x36 = -1;
                set_main_and_sub_etat(&ray, 2, 2);
                Reset_air_speed(is_rolling_speed);
                jump_time = 0;
                ray.field24_0x3e = 0;
                ray.speed_y = 0;
            }
            plat_obj->ray_dist = 1000;
        }
        break;
    case TYPE_BB1_PLAT:
        if (plat_obj->sub_etat == 7)
        {
            if (
                plat_obj->anim_frame == plat_obj->animations[plat_obj->anim_index].frames_count - 1 &&
                horloge[plat_obj->eta[plat_obj->main_etat][plat_obj->sub_etat].anim_speed & 0xf] == 0
            )
            {
                plat_obj->flags &= ~FLG(OBJ_ACTIVE);
                plat_obj->flags &= ~FLG(OBJ_ALIVE);
            }

            if (ray.field20_0x36 == plat_obj->id)
            {
                ray.field20_0x36 = -1;
                set_main_and_sub_etat(&ray, 2, 2);
                Reset_air_speed(is_rolling_speed);
                jump_time = 0;
                ray.field24_0x3e = 0;
                ray.speed_y = 0;
            }
            plat_obj->ray_dist = 1000;
        }

        if (plat_obj->sub_etat == 20)
        {
            if (ray.field20_0x36 == plat_obj->id || plat_obj->field24_0x3e != plat_obj->field23_0x3c)
                plat_obj->field24_0x3e--;

            if (plat_obj->iframes_timer == 0 || plat_obj->field24_0x3e == 0)
                set_sub_etat(plat_obj, 7);
            else
                plat_obj->iframes_timer--;
        }
        break;
    }
}
#endif