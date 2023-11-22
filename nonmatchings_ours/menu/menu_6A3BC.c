#include "menu/menu_6A3BC.h"

/* matches, but gotos */
/*INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", MAIN_CONTINUE_PRG);*/

/* 6AD14 8018F514 -O2 -msoft-float */
void MAIN_CONTINUE_PRG(void)
{
    s16 temp_v0;
    s32 var_v0;
    s32 var_v0_2;
    Obj *temp_a0;
    u8 flag_set;

    horloges();
    FUN_80168f48();
    if (ValidButPressed() || StartButPressed() || SelectButPressed())
    {
        if(ray.sub_etat == 25 || ray.sub_etat == 26 || ray.sub_etat == 27)
        {
            if (mapobj->timer != 128)
                mapobj->flags |= FLG(OBJ_ALIVE);
            start_cd_continue();
            PlaySnd_old(216);
            if (ray.sub_etat != 27)
                set_main_and_sub_etat(&ray, 3, 31);
            else
            {
                set_main_and_sub_etat(&ray, 3, 29);
                ray.flags |= FLG(OBJ_FLIP_X);
            }
            ray.anim_frame = 0;
            set_main_and_sub_etat(&clock_obj, 0, 1);
        }
    }
    SET_X_SPEED(&ray);
    ray.speed_x = instantSpeed(ray.speed_x);
    switch (ray.sub_etat)
    {
    case 25:
        if (ray.x_pos + ray.offset_bx < 70)
        {
            set_main_and_sub_etat(&ray, 3, 26);
            ray.anim_frame = 0;
        }
        break;
    case 26:
        if (ray.anim_frame >= 7)
            ray.speed_x = 0;
        break;
    case 27:
        if (++loop_nb_frames == 60)
        {
            loop_nb_frames = 0;
            loop_timing--;
        }
        break;
    case 31:
        flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
        if (
            (
                (flag_set && ray.anim_frame == 0) ||
                (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
            ) &&
            horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0
        )
        {
            if (horloge[2] != 0)
                ray.flags |= FLG(OBJ_FLIP_X);
        }
        break;
    case 29:
        /* pre-loading 0x40 between anim_frame and horloge checks somehow (8018f8c8) */
        ray.flags |= FLG(OBJ_FLIP_X);
        if (ray.x_pos + ray.offset_bx > 180)
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
        if (ray.x_pos + ray.offset_bx > 175)
        {
            flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
            if (
                (
                    (flag_set && ray.anim_frame == 0) ||
                    (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
                ) &&
                horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0
            )
            {
                set_sub_etat(&ray, 28);
                ray.anim_frame = 0;
            }
        }
        break;
    case 28:
        if (ray.anim_frame > 40)
            fin_continue = 1;
        if (ray.anim_frame > 16)
            ray.speed_x = 0;
        break;
    default:
        break;
    }
    if (horloge[2] == 0)
    {
        ray.x_pos = ray.x_pos + ray.speed_x;
        calc_obj_pos(&ray);
        DO_ANIM(&ray);
    }
    
    calc_obj_pos(&clock_obj);
    DO_ANIM(&clock_obj);
    if (mapobj->flags & FLG(OBJ_ALIVE))
    {
        DO_ANIM(mapobj);
        flag_set = mapobj->eta[mapobj->main_etat][mapobj->sub_etat].flags & 0x10;
        if (
            (
                (flag_set && mapobj->anim_frame == 0) ||
                (!flag_set && mapobj->anim_frame == mapobj->animations[mapobj->anim_index].frames_count - 1)
            ) &&
            horloge[mapobj->eta[mapobj->main_etat][mapobj->sub_etat].anim_speed & 0xf] == 0
        )
        {
            if (mapobj->timer != 128)
                nb_continue--;
            mapobj->flags &= ~FLG(OBJ_ALIVE);
        }
    }
    if (loop_timing != 0xFF)
        CHEAT_MODE_CONTINUE();
    else
        MAIN_NO_MORE_CONTINUE_PRG();
}