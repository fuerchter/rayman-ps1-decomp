#include "obj/stonebomb.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/obj/stonebomb", DO_TIR);*/

void DO_TIR(Obj *param_1)
{
    Obj *var_s2;
    Obj *var_s0;
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_v0_1;
    s16 temp_v0_4;
    s16 var_a0;
    s16 var_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    u32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    u16 var_v1;
    s16 var_a2;
    u8 temp_v1_1;
    u8 temp_v1_2;
    u8 var_a1;
    s16 test_1;
    s32 test_2;
    u32 test_3;
    u32 test_4;

    if (param_1->main_etat == 0)
    {
        if (param_1->sub_etat == 11)
        {
            if (param_1->field24_0x3e == 0)
            {
                var_s2 = level.objects;
                var_a0 = 0;
                test_1 = level.nb_objects;
                while (var_a0 < test_1)
                {
                    temp_v1_2 = var_s2->type;
                    if (((temp_v1_2 == 0x0D) || (temp_v1_2 == 0x0F)) && (((var_s2->flags & 0x800) == 0)))
                    {
                        var_s2->flags = ((var_s2->flags & ~0x4000) | (param_1->flags & 0x4000) | 0xC00);
                        set_main_and_sub_etat(var_s2, 2U, 2U);
                        var_s2->anim_frame = 0;
                        var_s2->anim_index = (u8) var_s2->eta[2][2].anim_index;
                        temp_v1_4 = (param_1->x_pos + param_1->offset_bx) - var_s2->offset_bx;
                        if (var_s2->flags & 0x4000)
                        {
                            temp_v1_4 = temp_v1_4 + 0x40;
                        }
                        else
                        {
                            temp_v1_4 = temp_v1_4 - 0x40;
                        }
                        var_s2->x_pos = temp_v1_4;
                        var_s2->y_pos = param_1->y_pos;
                        var_s2->init_x_pos = var_s2->x_pos;
                        var_s2->init_y_pos = var_s2->y_pos;
                        calc_obj_pos(var_s2);
                        PlaySnd(0x0018, var_s2->id);
                        if (var_s2->flags & 0x4000)
                        {
                            skipToLabel(var_s2, 3, 1U);
                        }
                        else
                        {
                            skipToLabel(var_s2, 1, 1U);
                        }

                        if (param_1->type == 0x0E)
                        {
                            
                            if (param_1->x_pos - ray.x_pos < 0)
                            {
                                var_a2 = (ray.x_pos - param_1->x_pos) >> 5;
                            }
                            else
                                var_a2 = (param_1->x_pos - ray.x_pos) >> 5;
                            var_s2->type = 0x0FU;
                            temp_v1_6 = (ray.y_pos - param_1->y_pos) * 2;
                            test_3 = (s16) var_a2;
                            temp_v0_2 = param_1->x_pos - ray.x_pos;
                            
                            if (temp_v0_2 >= 0)
                            {
                                var_v0 = (temp_v1_6 / temp_v0_2) - test_3;
                            }
                            else
                            {
                                temp_v0_3 = ray.x_pos - param_1->x_pos;
                                var_v0 = (temp_v1_6 / temp_v0_3) - test_3;
                            }
                            var_s2->speed_y = var_v0;
                            var_s2->gravity_value_2 = 0x0A;
                        }
                        else
                        {
                            var_s2->type = 0x0DU;
                            var_s2->speed_y = 0;
                        }
                        calc_obj_pos(var_s2);
                        break;
                    }
                    var_s2 += 1;
                    var_a0 = var_a0 + 1;
                }
                param_1->field24_0x3e = 1;
                return;
            }
        }
        else if (param_1->sub_etat == 2)
        {
            param_1->field24_0x3e = 0;
        }
    }
}
