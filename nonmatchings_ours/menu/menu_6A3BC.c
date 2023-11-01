#include "menu/menu_6A3BC.h"

/* matches, but gotos */
/*INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", MAIN_CONTINUE_PRG);*/

/* 6AD14 8018F514 -O2 -msoft-float */
/* ghidra 15455 */

void start_cd_continue(void);

void MAIN_CONTINUE_PRG(void)
{
    s16 temp_v0;
    s32 var_v0;
    s32 var_v0_2;
    Obj *temp_a0;
    u8 new_var;

    horloges();
    FUN_80168f48();
    if ((ValidButPressed() != 0) || (StartButPressed() != 0) || (SelectButPressed() != 0))
    {
      new_var = ray.sub_etat;
      if(((new_var - 0x19) < 2U) || (ray.sub_etat == 0x1B))
      {

        if (mapobj->timer != 0x80)
        {
            mapobj->flags |= 0x400;
        }
        start_cd_continue();
        PlaySnd_old(0xD8);
        temp_a0 = &ray;
        if (ray.sub_etat != 0x1B)
        {
            set_main_and_sub_etat(temp_a0, 3U, 0x1FU);
        }
        else
        {
            set_main_and_sub_etat(temp_a0, 3U, 0x1DU);
            ray.flags |= 0x4000;
        }
        ray.anim_frame = 0;
        set_main_and_sub_etat(&clock_obj, 0U, 1U);
      }
    }
    SET_X_SPEED(&ray);
    ray.speed_x = instantSpeed(ray.speed_x);
    switch (ray.sub_etat)
    {
    case 25:
        if ((ray.x_pos + ray.offset_bx) < 0x46)
        {
            set_main_and_sub_etat(&ray, 3U, 0x1AU);
            ray.anim_frame = 0;
        }
        break;
    case 26:
        var_v0 = (u8) ray.anim_frame < 7U;
        if (var_v0 == 0)
        {
            ray.speed_x = 0;
        }
        break;
    case 27:
        temp_v0 = (u16) loop_nb_frames + 1;
        loop_nb_frames = temp_v0;
        if (temp_v0 == 0x003C)
        {
            loop_nb_frames = 0;
            loop_timing = (u16) loop_timing - 1;
        }
        break;
    case 31:
        if ((ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10))
        {
            if (ray.anim_frame != 0)
            {
                break;
            }
            goto block_22;
        }
        if (ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
        {
block_22:
            if (horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0)
            {
                if (horloge[2] == 0)
                {
                  break;
                }
                ray.flags |= 0x4000;
            }
        }
        break;
    case 29:
        ray.flags |= 0x4000;
        if ((ray.x_pos + ray.offset_bx) >= 0xB5)
        {
            if ((ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10))
            {
                if (ray.anim_frame != 0)
                {
                    goto block_31;
                }
                goto block_30;
            }
            if (ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
            {
block_30:
                if (horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0)
                {
                  set_sub_etat(&ray, 0x1C);
                  ray.anim_frame = 0;
                }
                else
                {
                  goto block_31;
                }

            }
            else
            {
                goto block_31;
            }
        }
        else
        {
block_31:
            var_v0_2 = (u8) ray.anim_frame < 0x40U;
            if (var_v0_2 != 0)
            {
                ray.speed_x = 0;
            }
        }
        break;
    case 30:
        if ((ray.x_pos + ray.offset_bx) >= 0xB0)
        {
            if ((ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10))
            {
                if (ray.anim_frame == 0)
                {
                    goto block_39;
                }
            }
            else if (ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
            {
block_39:
                if (horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0)
                {
                  set_sub_etat(&ray, 0x1C);
                  ray.anim_frame = 0;
                }
            }
        }
        break;
    case 28:
        if ((u8) ray.anim_frame >= 0x29U)
        {
            fin_continue = 1;
        }
        var_v0 = (u8) ray.anim_frame < 0x11U;
        if (var_v0 == 0)
        {
            ray.speed_x = 0;
        }
        break;
    default:
        break;
    }
    if (horloge[2] == 0)
    {
        ray.x_pos = (u16) ray.x_pos + (u16) ray.speed_x;
        calc_obj_pos(&ray);
        DO_ANIM(&ray);
    }
    
    calc_obj_pos(&clock_obj);
    DO_ANIM(&clock_obj);
    if (mapobj->flags & 0x400)
    {
        DO_ANIM(mapobj);
        if (mapobj->eta[mapobj->main_etat][mapobj->sub_etat].flags & 0x10)
        {
            if (mapobj->anim_frame != 0)
            {

            }
            else
            {
                goto block_53;
            }
        }
        else if (mapobj->anim_frame == (mapobj->animations[mapobj->anim_index].frames_count - 1))
        {
block_53:
            if (horloge[mapobj->eta[mapobj->main_etat][mapobj->sub_etat].anim_speed & 0xF] == 0)
            {
                if (mapobj->timer != 0x80)
                {
                    nb_continue--;
                }
                mapobj->flags &= ~0x400;
            }
        }
    }
    if (loop_timing != 0x00FF)
    {
        CHEAT_MODE_CONTINUE();
        return;
    }
    MAIN_NO_MORE_CONTINUE_PRG();
}

/*INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", DO_CREDITS);*/

/* 6BF14 80190714 -O2 -msoft-float */
void INIT_FADE_OUT(void);
void horloges(void);
extern u8 D_801F7FF0;

void DO_CREDITS(void)
{
    Credit *var_a0;
    s16 var_s0;
    s32 temp_v0;
    s32 var_a1;
    s16 temp_a0;
    u8 temp_v1;
    short saved_reg_s0;

    /*var_s0 = saved_reg_s0;*/
    if (You_Win != 0)
    {
        horloges();
        if (horloge[2] == 0)
        {
            /* have i compared this between m2c/ghidra yet? */
            /* DISPLAY_TXT_CREDITS seems to have mini version of this? */
            var_a1 = first_credit;
            if (var_a1 <= last_credit)
            {
                var_a0 = &credits[var_a1];
                do
                {
                    var_a0->y_pos = credits[first_credit].y_pos - 1;
                    var_a0 += 1;
                } while ((s32) &credits[last_credit] >= (s32) var_a0);
            }
            nb_credits_lines = nb_credits_lines + 1;
            temp_v0 = last_credit;
            temp_a0 = credits[temp_v0].cmd;
            if (temp_a0 == 0)
            {
                temp_v1 = credits[temp_v0].font;
                switch (temp_v1)
                {
                case 0:
                    var_s0 = 0x0024;
                    break;
                case 1:
                    var_s0 = 0x0017;
                    break;
                case 2:
                    var_s0 = 0x000F;
                    break;
                }
            }
            else if (temp_a0 == 0xFF)
            {
                var_s0 = 0x00A0;
            }
            else if ((s32) temp_a0 >= 0x65)
            {
                var_s0 = temp_a0 - 0x55;
            }
            else
            {
                var_s0 = temp_a0 * 0xF;
            }
            if ((nb_credits_lines >= var_s0) && ((nb_credits_lines = 0, (temp_a0 == 0xFF)) || (last_credit += 1, (((u8) last_credit % 19U) == 0))))
            {
                INIT_FADE_OUT();
            }
            if (credits[first_credit].y_pos < -4)
            {
                first_credit += 1;
            }
            if ((D_801F7FF0 == 1) && (fade == 0))
            {
                PROC_EXIT = 1;
            }
        }
    }
}