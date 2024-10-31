#include "unknown/29A18.h"

/* 29A18 8014E218 -O2 -msoft-float */
void fades(void)
{
    if (map_time == 0)
        INIT_FADE_IN();

    if (dead_time == 32)
        INIT_FADE_OUT();
    
    if (fade != 0)
        DO_FADE();
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/unknown/29A18", FUN_8014e27c);
#else
/* matches, but gotos */
/*INCLUDE_ASM("asm/nonmatchings/unknown/29A18", FUN_8014e27c);*/

void FUN_8014e27c(void)
{
    s32 temp_v0_1;
    s32 temp_v0_2;
    s32 var_v0;

    if (ray_old_main_etat != 2 && ray.main_etat == 2)
        ray.field24_0x3e = 0;
    
    temp_v0_1 = D_801F7C90 - ray.x_pos;
    if (temp_v0_1 < 0)
        temp_v0_1 = ray.x_pos - D_801F7C90;

    if (temp_v0_1 < 0x31)
    {
        if (D_801F7CA0 - ray.y_pos >= 0)
        {
            if (D_801F7CA0 - ray.y_pos >= 0x31)
                goto block_10;
        }
        else if (D_801F7CA0 - ray.y_pos < 0)
        {
            if (ray.y_pos - D_801F7CA0 >= 0x31)
                goto block_10;
        }
    }
    else
    {
block_10:
        ray.x_pos = D_801F7C90;
        ray.y_pos = D_801F7CA0;
        calc_obj_pos(&ray);
    }
}
#endif
