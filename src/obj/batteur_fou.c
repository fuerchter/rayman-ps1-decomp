#include "obj/batteur_fou.h"

/* .data */
extern u8 N_anim[256];

/**/
extern s16 bat_nb_frap;

void DO_REDEYE_FIRE(s16 param_1, s16 param_2, s16 param_3);

/* 71680 80195E80 -O2 -msoft-float */
void DO_BAT_FLASH(s32 in_x, s32 in_y)
{
    s16 fire_par_3;
    s16 unk_1;
    s16 unk_x = in_x;
    s16 unk_y = in_y;
    s16 diff_x = ray_zdc_x + (ray_zdc_w >> 1) - unk_x;
    s16 diff_y = ray_zdc_y + (ray_zdc_h >> 1) - unk_y;
    u8 x_gt_0 = diff_x > 0;
    u8 y_gt_0 = diff_y > 0;

    if (!x_gt_0)
        diff_x = -diff_x;
    if (!y_gt_0)
        diff_y = -diff_y;
    
    if (diff_x > 200)
    {
        diff_x = ashr16(diff_x, 1);
        diff_y = ashr16(diff_y, 1);
    }

    if (diff_y == 0)
    {
        if (x_gt_0)
            fire_par_3 = 27;
        else
        {
            if (diff_x != 0)
                fire_par_3 = 9;
            else
                fire_par_3 = -1;
        }
    }
    else
    {
        unk_1 = diff_x * 45 / diff_y;
        if (x_gt_0)
        {
            if (y_gt_0)
            {
                if (unk_1 >= (s16) LEN(N_anim))
                    fire_par_3 = 27;
                else
                    fire_par_3 = 27 + N_anim[unk_1];
            }
            else
            {
                if (unk_1 >= (s16) LEN(N_anim))
                    fire_par_3 = 0;
                else
                    fire_par_3 = 0 + N_anim[unk_1];
            }
        }
        else
        {
            if (y_gt_0)
            {
                if (unk_1 >= (s16) LEN(N_anim))
                    fire_par_3 = 18;
                else
                    fire_par_3 = 18 + N_anim[unk_1];
            }
            else
            {
                if (unk_1 >= (s16) LEN(N_anim))
                    fire_par_3 = 9;
                else
                    fire_par_3 = 9 + N_anim[unk_1];
            }
        }
    }

    DO_REDEYE_FIRE(unk_x, unk_y, fire_par_3);
}

/* 718C4 801960C4 -O2 -msoft-float */
void DO_BAT_LEFT_FLASH(Obj *obj)
{
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;

    GET_SPRITE_POS(obj, 14, &spr_x, &spr_y, &spr_w, &spr_h);
    DO_BAT_FLASH(spr_x + (spr_w >> 1), spr_y + (spr_h >> 1));
}

/* 71928 80196128 -O2 -msoft-float */
void DO_BAT_RIGHT_FLASH(Obj *obj)
{
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;

    GET_SPRITE_POS(obj, 14, &spr_x, &spr_y, &spr_w, &spr_h);
    DO_BAT_FLASH(spr_x + (spr_w >> 1), spr_y + (spr_h >> 1));
}

/* 7198C 8019618C -O2 -msoft-float */
void DO_BAT_LEFT_RIGHT_FLASH(Obj *obj)
{
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;

    GET_SPRITE_POS(obj, 15, &spr_x, &spr_y, &spr_w, &spr_h);
    DO_BAT_FLASH(spr_x + (spr_w >> 1), spr_y + (spr_h >> 1));
    GET_SPRITE_POS(obj, 14, &spr_x, &spr_y, &spr_w, &spr_h);
    DO_BAT_FLASH(spr_x + (spr_w >> 1), spr_y + (spr_h >> 1));
}

/* 71A5C 8019625C -O2 -msoft-float */
s16 bat_dir(Obj *obj)
{
    return (ray.x_pos + ray.offset_bx - obj->x_pos - obj->offset_bx) > 0;
}

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", bat_init_scroll);

/* 71D18 80196518 -O2 -msoft-float */
void bat_done_scroll(void)
{
    scroll_start_x = 0;
    special_ray_mov_win_x_left = 0;
    special_ray_mov_win_x_right = 0;
    scroll_end_x = xmapmax;
}

/* 71D48 80196548 -O2 -msoft-float */
void DO_BAT_COMMAND(Obj *obj)
{
    u8 offs_bx; u8 offs_by;
    s16 spd_y;
    u8 flag_set;
    s16 obj_sub_etat = obj->sub_etat;
    u8 horl_0 = horloge[obj->eta[obj->main_etat][obj_sub_etat].anim_speed & 0xF] == 0;

    switch (obj_sub_etat)
    {
    case 2:
        if (obj->anim_frame == 14 && horl_0)
            DO_BAT_LEFT_RIGHT_FLASH(obj);
        break;
    case 5:
        if (obj->anim_frame == 22)
        {
            if (obj->hit_points == 0)
                skipToLabel(obj, 8, true);
            else if ((s16) myRand(1) == 0)
                skipToLabel(obj, 2, true);
            else
                skipToLabel(obj, 3, true);
            return;
        }
        break;
    case 3:
    case 4:
        if (obj->anim_frame == 19 && horl_0)
        {
            bat_nb_frap++;
            if (obj_sub_etat == 4)
                DO_BAT_RIGHT_FLASH(obj);
            if (obj_sub_etat == 3)
                DO_BAT_LEFT_FLASH(obj);
        }
        break;
    case 6:
    case 7:
        if (obj->anim_frame == 20)
        {
            if (obj->hit_points == 0)
                skipToLabel(obj, 8, true);
            else
            {
                switch (bat_nb_frap)
                {
                case 1:
                    set_sub_etat(obj, 11);
                    break;
                case 3:
                    set_sub_etat(obj, 11);
                    bat_nb_frap = 0;
                    break;
                default:
                    if (obj_sub_etat == 6)
                        skipToLabel(obj, 3, true);
                    else
                        skipToLabel(obj, 2, true);
                    break;
                }
            }
        }
        break;
    case 8:
        if (bat_dir(obj))
            skipToLabel(obj, 4, true);
        else
            skipToLabel(obj, 5, true);
        break;
    case 11:
        if (bat_dir(obj))
            skipToLabel(obj, 6, true);
        else
            skipToLabel(obj, 7, true);
        break;
    case 9:
    case 10:
    case 12:
    case 13:
        if (obj->cmd == GO_SPEED)
        {
            switch (obj_sub_etat)
            {
            case 10:
            case 13:
                obj->speed_x = -__builtin_abs(obj->iframes_timer);
                break;
            case 12:
            case 9:
                obj->speed_x = __builtin_abs(obj->iframes_timer);
                break;
            }
            obj->speed_y = obj->field20_0x36;
        }

        offs_bx = obj->offset_bx;
        offs_by = obj->offset_by;
        if (
            test_allowed(obj, offs_bx, offs_by) &&
            on_block_chdir(obj, offs_bx, offs_by)
        )
        {
            switch (obj_sub_etat)
            {
            case 10:
                obj->sub_etat = 9;
                break;
            case 9:
                obj->sub_etat = 10;
                break;
            case 13:
                obj->sub_etat = 12;
                break;
            case 12:
                obj->sub_etat = 13;
                break;
            }
        }
        break;
    case 14:
        obj->speed_x = 0;
        obj->speed_y = 0;
        break;
    case 15:
        obj->speed_x = 0;
        if (obj->anim_frame < 29)
            spd_y = -4;
        else
            spd_y = -8;
        obj->speed_y = spd_y;
        break;
    case 16:
        obj->speed_y = -8;
        flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
        if(
            ((flag_set && obj->anim_frame == 0) ||
            (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
        )
        {
            if (obj->y_pos + obj->offset_by < ymap)
            {
                obj->flags &= ~FLG(OBJ_ACTIVE);
                obj->flags &= ~FLG(OBJ_ALIVE);
                fix_numlevel(&ray);
                new_level = true;
            }
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", BAT_ray_in_zone);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", DO_BAT_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", bat_get_eject_sens);
