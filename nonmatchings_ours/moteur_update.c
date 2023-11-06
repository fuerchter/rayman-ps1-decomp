#include "moteur_update.h"

/* reg swaps at the end */
/*INCLUDE_ASM("asm/nonmatchings/moteur_update", DO_MOTEUR2);*/

/* 3545C 80159C5C -O2 -msoft-float */
void DO_MOTEUR2(void)
{
    Obj *temp_v1_2;
    s32 var_a0;
    s32 test_1;
    s32 test_2;
    s32 test_3;

    DO_WIZ_AFTER_BONUS_MAP();
    DO_PERFECT_BONUS_MAP();
    PS1_PhotographerCollision();
    DO_OBJECTS_ANIMS();
    if (ray.flags & FLG(OBJ_ALIVE))
    {
        if (dead_time != 64)
            ray.field20_0x36 = -1;
        switch(ray_mode)
        {
        case 1:
            DO_RAYMAN();
            break;
        case 2:
            if (ray.main_etat != 6)
                set_main_and_sub_etat(&ray, 6, 0);
            DO_RAY_ON_MS();
            break;
        case 3:
        case 4:
            DO_MORT_DE_RAY();
            break;
        default:
            DO_PLACE_RAY();
            break;
        }

        if (NumScrollObj > 0 && ray_mode > 0)
            DO_AUTO_SCROLL();
        else
        {
            scroll_x = -1;
            scroll_y = -1;
        }
        MOVE_OBJECTS();
        calc_obj_pos(&ray);
        if (scroll_y != -1 && v_scroll_speed == 0x00FF)
            v_scroll_speed = 0;
        if (gele == 0 && ray_mode > 0)
            RecaleRayPosInJumelle();
        if (ray_mode == 2)
        {
            if (scroll_x != -1)
            {
                scroll_x = ray.speed_x;
                ray.speed_x = h_scroll_speed;
                if ((s16) h_scroll_speed > 0)
                {
                    RAY_TO_THE_RIGHT(&ray.speed_x);
                }
                else if ((s16) h_scroll_speed < 0)
                {
                    RAY_TO_THE_LEFT(&ray.speed_x);
                }
                ray.speed_x = scroll_x;
            }
            if(ray.sub_etat != 14)
            {
                switch (ray.sub_etat)
                {
                case 0:
                    if (__builtin_abs(ray.speed_x) >= 2 || __builtin_abs(h_scroll_speed) >= 2)
                        set_sub_etat(&ray, 6);
                    break;
                case 1:
                    if (__builtin_abs(ray.speed_x) < 2 && __builtin_abs(h_scroll_speed) < 2)
                        set_sub_etat(&ray, 7);
                    else
                    {
                        if (__builtin_abs(h_scroll_speed) >= 5 && (xmap < xmapmax - 100))
                        {
                            set_sub_etat(&ray, 2);
                            change_audio_track_moskito_acc();
                        }
                    }
                    break;
                case 5:
                    if (__builtin_abs(h_scroll_speed) < 5)
                    {
                        set_sub_etat(&ray, 3);
                        change_audio_track_moskito_dec();
                    }
                    break;
                }
                if (xmap == xmapmax)
                    scroll_start_x = xmap;
            }
            level.objects[poing_obj_id].x_pos += h_scroll_speed;
            level.objects[poing_obj_id].y_pos += v_scroll_speed;
        }
        DO_SCROLL(&h_scroll_speed, &v_scroll_speed);
        build_active_table();
        RECALE_ALL_OBJECTS();
        if (ray.field20_0x36 != -1)
        {
            temp_v1_2 = &level.objects[ray.field20_0x36];
            oldPrio = temp_v1_2->display_prio;
            if (oldPrio >= 4)
                temp_v1_2->display_prio = 3;
        }
    }
    else
    {
        MOVE_OBJECTS();
        scroll_y = -1;
        build_active_table();
        dead_time--;
    }
    DO_FIXE();
    do_flocons(xmap, ymap, xmap_old, ymap_old);
    DO_SNOW_SEQUENCE();
    do_pix_gerbes();
    if (RayEvts.flags1 & 2)
    {
        set_zoom_mode(0);
        ray.scale = 0x0100;
        if (ray.flags & FLG(OBJ_FLIP_X))
        {
            var_a0 = ray.screen_x_pos;
            test_1 = ray.offset_bx;
            test_1 -= 8;
            test_2 = ray.screen_y_pos;
            test_3 = ray.offset_by;
        }
        else
        {
            var_a0 = ray.screen_x_pos;
            test_1 = ray.offset_bx;
            test_2 = ray.screen_y_pos;
            test_3 = ray.offset_by;
        }
        set_proj_center(var_a0 + test_1, test_2 + test_3);
    }
    FUN_8014e27c();
}