#include "obj/pi_boum.h"

/* matches, but clean up*/
/*INCLUDE_ASM("asm/nonmatchings/obj/pi_boum", DO_PI_EXPLOSION);*/

void DO_PI_EXPLOSION(Obj *obj)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    Obj *var_s0;
    Obj *var_s2_1;
    Obj *var_s2_2;
    Obj *var_s3;
    s16 temp_v0;
    s16 var_s4;
    s16 var_v0_1;
    s16 var_v0_3;
    s16 var_v1;
    s32 var_v0_2;
    s16 nb_objs;

    /*var_s2_1 = saved_reg_s2;*/
    PlaySnd_old(0x0054);
    var_s3 = level.objects;
    var_v1 = 0;
    nb_objs = level.nb_objects;
    while (var_v1 < nb_objs)
    {
        if (var_s3->type == 0x6E)
        {
            var_s2_2 = var_s3;
            do
            {
                var_s2_2 += 1;
            } while (var_s2_2->type == 0x6E);
            break;
        }
        var_v1 = var_v1 + 1;
        var_s3 += 1;
    }
    
    var_s4 = 0;
    if (var_s3->type == 0x6E)
    {
        while (var_s4 < 5)
        {
            var_s0 = var_s3;
            if (var_s2_2 >= var_s0)
            {
                while (var_s2_2 >= var_s0)
                {
                    if (!(var_s0->flags & 0x800))
                        break;
                        
                    var_s0++;
                }

                if (var_s2_2 >= var_s0)
                {
                    set_main_and_sub_etat(var_s0, 2U, var_s4);
                    var_s0->flags &= ~0x4000;
                    switch (var_s4)
                    {
                    case 0:
                        var_s0->speed_y = 0;
                        var_s0->speed_x = 4;
                        break;
                    case 1:
                        var_s0->speed_y = 0;
                        var_v0_3 = -2;
                        var_s0->speed_x = var_v0_3;
                        break;
                    case 2:
                        var_s0->speed_y = -4;
                        var_s0->speed_x = -4;
                        break;
                    case 3:
                        var_s0->speed_y = -4;
                        var_v0_3 = 2;
                        var_s0->speed_x = var_v0_3;
                        break;
                    case 4:
                        var_s0->speed_y = -6;
                        var_v0_3 = -1;
                        var_s0->speed_x = var_v0_3;
                        break;
                    }
                    GET_SPRITE_POS(obj, var_s4, &sp18, &sp1A, &sp1C, &sp1E);
                    var_s0->x_pos = (s16) (u16) sp18;
                    var_s0->y_pos = (s16) (u16) sp1A;
                    skipToLabel(var_s0, 1U, 1U);
                    calc_obj_pos(var_s0);
                    var_s0->flags |= 0xC00;
                }
            }
            var_s4 = var_s4 + 1;
        }
    }
}
const u8 rodata_DO_PI_EXPLOSION[4] = {};
