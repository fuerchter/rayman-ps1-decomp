#include "ray/ray_32398.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", DO_RAYMAN);*/

/*s32 FUN_80133984(?);
s32 FUN_801339f4(?);*/
void setvol(ushort param_1, u8);

void DO_RAYMAN(void)
{
    s16 sp18;
    s16 sp1A;
    u16 sp1C;
    s16 sp1E;
    s16 temp_s1;
    s16 temp_v0;
    s16 temp_v1;
    s32 temp_v1_2;
    u8 temp_a1;
    u8 uVar5;
    u8 test_1;
    Obj *new_var;
    Obj *pOVar3;
    Obj *pOVar2;
    u8 test_2;
    Obj *new_var2;

    v_scroll_speed = 0;
    h_scroll_speed = 0;
    uVar5 = FUN_801473dc(&ray);
    setvol(-1, uVar5);
    if (RAY_DEAD() & 0xFF)
    {
        ray.ray_dist = ((s32) ((ray.offset_bx + (u16)ray.x_pos) << 0x10) >> 0x14) + (((s32) ((ray.offset_by + (u16)ray.y_pos) << 0x10) >> 0x14) * (u16) mp.width);
        COLL_RAY_BLK_MORTEL();
        if ((scroll_y != -1) && ((ray.screen_y_pos + ray.offset_by) < 0))
        {
            ray.speed_y = 0;
        }
        if ((ray.iframes_timer == -1) && (ray.eta[ray.main_etat][ray.sub_etat].flags & 8) && ((COLL_RAY_PIC() << 0x10) != 0))
        {
            RAY_HIT(1, 0);
        }
        joy_done = 0;
        calc_obj_pos(&ray);
        temp_s1 = ray.field20_0x36;
        if ((temp_s1 != -1) || (calc_btyp(&ray), (ray.field20_0x36 != temp_s1)))
        {
            ray.speed_x = 0;
            ray.speed_y = 0;
        }
        if (remoteRayXToReach != -0x7D00 && !(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40))
        {
            /* TODO: rewrite... */
            if (
                !((
                    (ray.main_etat != 0 || ray.sub_etat == 4 || ray.sub_etat == 5 || ray.sub_etat == 6 || ray.sub_etat == 7) ||
                    !(ray.sub_etat != 9 && ray.sub_etat != 10)
                ) &&
                (
                    (ray.main_etat != 1 || (ray.main_etat == 1 && ray.sub_etat == 1)) &&
                    (ray.main_etat != 3 || ray.sub_etat == 1 || (ray.sub_etat == 2 || ray.sub_etat == 3) || ray.sub_etat == 4)
                ))
            )
            {
                if (remoteRayXToReach != 0)
                {
                    set_main_and_sub_etat(&ray, 3U, 0x15U);
                }
                else
                {
                    set_main_and_sub_etat(&ray, 3U, 0x14U);
                }
            }
        }

        if ((ray.main_etat == 2) && ((ray.sub_etat == 8) || (ray.sub_etat == 0x1F)))
        {
            RAY_IN_THE_AIR();
        }
        else if (ray.main_etat == 3)
        {
            if (ray.sub_etat == 0x10)
            {
                DO_GROWING_PLATFORM();
                if (eau_obj_id != -1)
                {
                    level.objects[eau_obj_id].iframes_timer = 1;
                    if (D_801E64B0 == 0)
                    {
                        FUN_8013202c();
                    }
                }
            }
            else if (ray.sub_etat == 0x14 || ray.sub_etat == 0x15)
            {
                remoteControlRay();
            }
            if (ray.sub_etat != 0x16 && ray.sub_etat != 0x17 && (ray.sub_etat != 0x20))
            {
                RAY_SWIP();
            }
        }
        else
        {
            if ((ray_on_poelle == 0) && !(RayEvts.flags1 & 0x18) && (ray.main_etat == 0 || ray.main_etat == 1))
            {
                if ((FUN_801339f4(0) != 0) && (FUN_80133984(0) == 0))
                {
                    PS1_ShoulderR = 1;
                    PS1_ShoulderL = 0;
                }
                else if ((FUN_801339f4(0) == 0) && (FUN_80133984(0) != 0))
                {
                    PS1_ShoulderR = 0;
                    PS1_ShoulderL = 1;
                }
                else if ((FUN_801339f4(0) != 0) && (FUN_80133984(0) != 0))
                {
                    if (PS1_ShoulderL == 1)
                    {
                        PS1_ShoulderR = 2;
                        PS1_ShoulderL = 0;
                    }
                    else if (PS1_ShoulderR == 1)
                    {
                        PS1_ShoulderR = 0;
                        PS1_ShoulderL = 2;
                    }
                    else if ((PS1_ShoulderR == 0) && (PS1_ShoulderL == 0))
                    {
                        if (ray.flags & 0x4000)
                        {
                            PS1_ShoulderR = 2;
                        }
                        else
                        {
                            PS1_ShoulderL = 2;
                        }
                    }
                }
                else
                {
                    PS1_ShoulderR = 0;
                    PS1_ShoulderL = 0;
                }
                if (!(RayEvts.flags1 & 0x60))
                {
                    if (PS1_ShoulderR == 0)
                    {
                        if (PS1_ShoulderL != 0)
                        {
                            PS1_RespondShoulderL();
                        }
                    }
                    else
                    {
                        PS1_RespondShoulderR();
                    }
                }
                else if (PS1_ShoulderR == 0)
                {
                    if (PS1_ShoulderL != 0)
                    {
                        PS1_RespondShoulderR();
                    }
                }
                else
                {
                    PS1_RespondShoulderL();
                }
            }
            else if ((PS1_ShoulderR != 0) || (PS1_ShoulderL != 0))
            {
                PS1_ShoulderR = 0;
                PS1_ShoulderL = 0;
            }
            if ((options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e)) != 0)
            {
                RAY_RESPOND_TO_FIRE1();
            }
            if (((options_jeu.Fire0ButtonFunc)(options_jeu.field12_0x20)) != 0)
            {
                RAY_RESPOND_TO_FIRE0();
            }
            if (((options_jeu.Button3Func)(options_jeu.field14_0x24)) != 0)
            {
                RAY_RESPOND_TO_BUTTON3();
            }
            if (((options_jeu.Button4Func)(options_jeu.field13_0x22)) != 0)
            {
                RAY_RESPOND_TO_BUTTON4();
            }
            if (poing.is_charging != 0)
            {
                if (ray.sub_etat == 0x0C)
                {
                    RAY_GROW_FIST();
                }
                if (((options_jeu.Fire0ButtonFunc)(options_jeu.field12_0x20)) == 0)
                {
                    RAY_THROW_FIST();
                }
            }
            if (ray.main_etat == 7)
            {
                RAY_BALANCE();
            }
            else if (ray.main_etat == 2)
            {
                RAY_IN_THE_AIR();
            }
            else if ((options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e)) == 0)
            {
                button_released = 1;
            }
            if ((PS1_ShoulderR == 0) && (PS1_ShoulderL == 0))
            {
                RAY_RESPOND_TO_ALL_DIRS();
            }
        }
        temp_a1 = RayEvts.flags1;
        if (temp_a1 & 0x60)
        {
          GET_SPRITE_POS(&ray, 5, &sp18, &sp1A, &sp1C, &sp1E);
          star_ray_der->x_pos =
          star_ray_dev->x_pos =
              (sp18 + (((s16) sp1C) >> 0x1)) - star_ray_dev->offset_bx;
          star_ray_der->y_pos =
          star_ray_dev->y_pos =
              sp1A - star_ray_dev->offset_hy;

          star_ray_der->flags |= 0xC00;
          star_ray_der->display_prio = 3;
          star_ray_dev->flags |= 0xC00;
          star_ray_dev->display_prio = 1;
        }
        else
        {
            temp_v1_2 = temp_a1 & 0x18;
            if (temp_v1_2 != 0)
            {
                if (temp_v1_2 == 8)
                {
                    RayEvts.flags1 = (temp_a1 & 0xE7) | 0x11;
                    DO_NOVA(&ray, temp_a1);
                    set_main_and_sub_etat(&ray, 1, 3);
                }
                else if (((ray.main_etat != 1) || ((ray.sub_etat != 3) && (ray.sub_etat != 7))) && (ray.main_etat != 2))
                {
                    RayEvts.flags1 = temp_a1 | 1;
                    set_main_and_sub_etat(&ray, 1, 3);
                }
                else if (((RayEvts.flags1 & 0x18) == 0x18) && (ray.main_etat != 2))
                {
                    RayEvts.flags1 &= 0xE7;
                }
            }
        }
        if (ray.field20_0x36 != -1)
        {
            RAY_FOLLOW();
        }
        FUN_80156040();
        if ((RayEstIlBloque() << 0x10) != 0)
        {
            if (ray.main_etat == 7)
            {
                RAY_FIN_BALANCE();
            }
            ray.speed_x = 0;
            decalage_en_cours = 0;
            ray.nb_cmd = 0;
        }
        if (pierreAcorde_obj_id != -1)
        {
            RepousseRay();
        }
        RAY_SURF();
        STOPPE_RAY_EN_XY();
        if (ray.speed_y > 0)
        {
            move_down_ray();
        }
        else if (ray.speed_y < 0)
        {
            move_up_ray();
        }
        if (ray.speed_x < 0)
        {
            RAY_TO_THE_LEFT();
        }
        else if (ray.speed_x > 0)
        {
            RAY_TO_THE_RIGHT();
        }
        if ((ray.flags & 0x400) && (ray.main_etat != 7))
        {
            DO_ANIM(&ray);
            DO_SURF_CHANGE_HAIRS();
        }
        if ((new_world == 0) && (new_level == 0))
        {
            GET_RAY_ZDC(&ray, &ray_zdc_x, &ray_zdc_y, &ray_zdc_w, &ray_zdc_h);
            DO_COLLISIONS();
        }
        if (fin_boss != 0)
        {
            TEST_SIGNPOST();
        }
    }
    stackRay();
}