#include "obj/batteur_fou.h"

extern u8 N_anim[256];

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

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", DO_BAT_LEFT_FLASH);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", DO_BAT_RIGHT_FLASH);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", DO_BAT_LEFT_RIGHT_FLASH);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", bat_dir);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", bat_init_scroll);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", bat_done_scroll);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", DO_BAT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", BAT_ray_in_zone);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", DO_BAT_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", bat_get_eject_sens);
