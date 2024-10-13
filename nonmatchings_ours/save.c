#include "save.h"

/* score of 385 */
/*INCLUDE_ASM("asm/nonmatchings/save", restoreGameState);*/

void restoreGameState(SaveState *save_param)
{
    Obj *temp_a2;
    s16 temp_v1_1;
    s16 var_a3_2;
    s16 var_v0_3;
    u8 temp_a0;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_a2_2;
    u8 var_a2_3;
    s32 var_a2_4;
    s32 var_v1_2;
    Obj *cur_obj;
    u32 var_v0_4;
    u32 var_v1;
    u8 temp_a1;
    u8 temp_a1_2; /* being used for two different save_param fields */
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v1_3;
    u8 var_v0_2;
    s16 nb_objs;
    u8 test_1;
    s16 test_2;
    u8 test_3;
    Obj *new_var;

    if (save_param->has_saved)
    {
        if (RayEvts.demi)
        {
            __builtin_memcpy(&ray, &rms, sizeof(Obj));
            RayEvts.demi = false;
        }
        status_bar.num_wiz = save_param->num_wiz;
        xmap = save_param->x_map;
        ymap = save_param->y_map;
        temp_a1_2 = save_param->time;
        PS1_MoteurTime = temp_a1_2;
        ray.x_pos = save_param->ray_x_pos;
        ray.y_pos = save_param->ray_y_pos;
        ray.screen_x_pos = save_param->ray_screen_x;
        ray.screen_y_pos = save_param->ray_screen_y;
        /*PS1_MoteurTime = save->unk38;*/
        
        var_v0_2 = 1;
        ray.flags = (ray.flags & ~0x4000) | ((save_param->ray_flip_x & var_v0_2) << 0xE);
        RayEvts.super_helico = save_param->rayevts_1;
        if ((num_world == 6) && (num_level == 3))
        {
            RayEvts.poing = save_param->rayevts_2;
            RayEvts.reverse = save_param->rayevts_0;
        }
        /* tried using cur_obj */
        temp_v1_1 = save_param->save_obj_id;
        if (temp_v1_1 != -1)
        {
            temp_a2 = &level.objects[temp_v1_1];
            temp_a2->x_pos = save_param->save_obj_x_pos;
            temp_a2->y_pos = save_param->save_obj_y_pos;
            temp_a2->detect_zone_flag = save_param->save_obj_detect_zone_flag;
            var_v0_3 = ((save_param->field18_0x14b & 1) << 8);
            temp_a2->flags = (temp_a2->flags & ~0x100) | var_v0_3;
        }
        if (save_param == &save1)
        {
            var_a2_3 = 0;
            while (var_a2_3 < level.nb_objects) /* not saved into s16 var? */
            {
                temp_a0 = save_param->link_init[var_a2_3];
                link_init[var_a2_3] = temp_a0;
                if (temp_a0 != var_a2_3)
                {
                    level.objects[var_a2_3].flags |= 0x1000;
                }
                else
                {
                    level.objects[temp_a0].flags &= ~0x1000;
                }
                var_a2_3 += 1;
            }
        }
        var_a2_3 = 0;
        do
        {
            ray.btypes[var_a2_3] = save_param->ray_btypes[var_a2_3];
            var_a2_3 += 1;
        } while (var_a2_3 < 5U);
        ray.anim_index = save_param->ray_anim_index;
        ray.anim_frame = save_param->ray_anim_frame;
        ray.main_etat = save_param->ray_main_etat;
        ray.sub_etat = save_param->ray_sub_etat;
        if (save_param == &save1)
        {
            switch (save1.poing_sub_etat)
            {
            case 5:
            case 12:
                save_param->poing_sub_etat = 3;
                break;
            case 1:
            case 3:
            case 8:
            case 10:
                save_param->poing_sub_etat = 1;
                break;
            }
        }
        temp_a1_2 = save_param->poing_sub_etat;
        poing.sub_etat = temp_a1_2;
        level.objects[poing_obj_id].init_sub_etat = temp_a1_2;
        dead_time = save_param->dead_time;
        decalage_en_cours = 0;
        ray_wind_force = 0;

        var_a2_3 = 0;
        do
        {
            nb_floc[var_a2_3] = save_param->nb_floc[var_a2_3];
            var_a2_3 += 1;
        } while (var_a2_3 < 8U);

        VENT_X = save_param->vent_x;
        VENT_Y = save_param->vent_y;
        ray.speed_x = 0;
        ray.speed_y = 0;
        ray.iframes_timer = -1;

        /* ??? */
        var_a3_2 = 0; /* this is s16, while var_a2_3 is u8 */
        cur_obj = &level.objects[var_a3_2];
        ray.flags |= 0xC00;
        nb_objs = level.nb_objects;
        /* ???*/

        h_scroll_speed = 0;
        v_scroll_speed = 0;

        while (var_a3_2 < nb_objs)
        {
            temp_v1_3 = cur_obj->type;
            if (temp_v1_3 == 0x3 || temp_v1_3 == 0xD || temp_v1_3 == 0xF || temp_v1_3 == 0x3B || temp_v1_3 == 0x24 || temp_v1_3 == 0x42 || temp_v1_3 == 0x3E)
            {
                cur_obj->flags = cur_obj->flags & ~0x400;
            }
            else if (temp_v1_3 == 0x8D || temp_v1_3 == 0xA4)
            {
                if ((1 << (var_a3_2 & 0x1F)) & save_param->triggered_objects[var_a3_2 >> 5])
                {
                    cur_obj->flags = cur_obj->flags | 0x400;
                }
                else
                {
                    cur_obj->flags = cur_obj->flags & ~0x400;
                }
            }
            var_a3_2 = var_a3_2 + 1;
            cur_obj += 1;
        }
        gerbe = 0;
    }
}