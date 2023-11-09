#include "obj_util.h"

/* too many casts, locals */
/*INCLUDE_ASM("asm/nonmatchings/obj_util", special_flags_init);*/

/* 2479C 80148F9C -O2 -msoft-float */
void special_flags_init(void)
{
    s32 var_a0;
    s32 var_v0_2;
    s32 var_v1;
    int new_var;

    var_a0 = 0;
    while ((u8) var_a0 < 255)
    {
        var_v0_2 = var_a0 - 16;
        if (!(u8) var_a0)
        {
            if (num_level == 3)
                zonediffx[0] = -120;
            else
                zonediffx[0] = 0;
            
        }
        var_v0_2 = var_a0 - 16;
        var_v1 = var_a0 & 0xFF;
        if (((u8) var_v0_2 < 2U) || (var_v1 == 24))
        {
            if (num_world == 1)
                flags[(u8) var_a0].flags1 |= 8;
            else
                flags[(u8) var_a0].flags1 &= 0xF7;

            var_v1 = (u8) var_a0;
        }
        var_a0++;
        if (var_v1 == 0xAA)
        {
            if (num_world == 4)
            {
                new_var = 170;
                zonediffx[new_var] = 150;
            }
        }
    }
}