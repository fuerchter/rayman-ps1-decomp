#include "obj/ufo_idc.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/ufo_idc", DO_MOVING_WITH_INDICATOR_COMMAND);*/

void DO_MOVING_WITH_INDICATOR_COMMAND(Obj *ufo_idc_obj)
{
    s16 sp10;
    Obj *var_a3;
    s16 spd_x;
    s32 var_a0_2;
    s16 spd_y;
    s16 var_a2_2;
    s32 var_v1;
    s32 temp_a0;
    s32 temp_a1;
    s32 var_a0_1;
    s16 var_a2;
    s32 var_a3_2;
    s32 var_a3_3;
    s32 var_v0_7;
    u8 temp_s1;
    u8 temp_v1;

    ufo_idc_obj->flags &= ~0x4000;
    if (
        (ufo_idc_obj->main_etat == 0) && (ufo_idc_obj->sub_etat == 0x0E) &&
        ((test_block_chdir(ufo_idc_obj, &sp10, ufo_idc_obj->offset_bx, ufo_idc_obj->offset_by)) != 0)
    )
    {
        var_a2 = 0;
        var_a3 = &level.objects[actobj.objects[var_a2]];
        while ((var_a2 < actobj.num_active_objects) != 0)
        {
            if (var_a3->type == 0xA3)
            {
                if (
                    (s16) (((var_a3->x_pos + var_a3->offset_bx) >> 4) +
                    (((var_a3->y_pos + var_a3->offset_by) >> 4) * mp.width))
                    == sp10
                )
                {
                    var_v1 = ufo_idc_obj->speed_y;
                    spd_x = ufo_idc_obj->speed_x;
                    spd_y = var_v1;
                    var_a0_2 = __builtin_abs(spd_x);
                    var_v1 = __builtin_abs(var_v1);
                    if (var_a0_2 < var_v1)
                    {
                        var_a0_2 = var_v1;
                    }
                    switch (var_a3->sub_etat)
                    {
                    case 8:
                        if (spd_x == 0)
                        {
                            if (spd_y > 0)
                            {
                                spd_y = -var_a0_2;
                            }
                            else if (spd_y < 0)
                            {
                                spd_y = var_a0_2;
                            }
                        }
                        else if (spd_y == 0)
                        {
                            if (spd_x > 0)
                            {
                                spd_x = -var_a0_2;
                            }
                            else if (spd_x < 0)
                            {
                                spd_x = var_a0_2;
                            }
                        }
                        else
                        {
                            spd_x = -spd_x;
                            spd_y = -spd_y;
                        }
                        break;
                    case 9:
                    case 10:
                        var_a3_2 = -1;
                        if (var_a3->sub_etat == 9)
                        {
                            var_a3_2 = 1;
                        }
                        if (spd_y == 0)
                        {
                            if (spd_x > 0)
                            {
                                spd_x = var_a0_2 + var_a3_2;
                                if (spd_x > 4)
                                {
                                    spd_x = 4;
                                }
                                if (spd_x < 2)
                                {
                                    spd_x = 2;
                                }
                            }
                            else
                            {
                                if (spd_x < 0)
                                {
                                    spd_x = var_a3_2 + -var_a0_2;
                                    if (spd_x >= -1)
                                    {
                                        spd_x = -2;
                                    }
                                    if (spd_x < -4)
                                    {
                                        spd_x = -4;
                                    }
                                }
                            }
                        }
                        if (spd_x != 0)
                        {
                            spd_y = 0;
                        }
                        break;
                    case 11:
                    case 12:
                        var_a3_2 = -1;
                        if (var_a3->sub_etat == 0x0B)
                        {
                            var_a3_2 = 1;
                        }
                        if (spd_x == 0)
                        {
                            if (spd_y > 0)
                            {
                                spd_y = var_a0_2 + var_a3_2;
                                if (spd_y > 4)
                                {
                                    spd_y = 4;
                                }
                                if (spd_y < 2)
                                {
                                    spd_y = 2;
                                }
                            }
                            else
                            {
                                if (spd_y < 0)
                                {
                                    spd_y = var_a3_2 + -var_a0_2;
                                    if (spd_y > -2)
                                    {
                                        spd_y = -2;
                                    }
                                    if (spd_y < -4)
                                    {
                                        spd_y = -4;
                                    }
                                }
                            }
                        }
                        if (spd_y != 0)
                        {
                            spd_x = 0;
                        }
                        break;
                    case 4:
                        if ((spd_x) != 0)
                        {
                            if (spd_y == 0)
                            {
                            case 3: /* ??? */
                                spd_x = 0;
                                spd_y = -var_a0_2;
                            }
                        }
                        else
                        {
                            spd_x = var_a0_2;
                            spd_y = 0;
                        }
                        break;
                    case 5:
                        if (spd_x == 0)
                        {
                            spd_x = var_a0_2;
                            spd_y = 0;
                        }
                        else if (spd_y == 0)
                        {
                            spd_x = 0;
                            spd_y = var_a0_2;
                        }
                        break;
                    case 0:
                        spd_x = var_a0_2;
                        spd_y = 0;
                        break;
                    case 6:
                        if (spd_x != 0)
                        {
                            if (spd_y == 0)
                            {
                                spd_x = 0;
                                spd_y = -var_a0_2;
                            }
                        }
                        else
                        {
                            spd_x = -var_a0_2;
                            spd_y = 0;
                        }
                        break;

                    case 7:
                        if (spd_x == 0)
                        {
                            spd_x = -var_a0_2;
                            spd_y = 0;
                            break;
                        }
                        if (spd_y == 0)
                        {
                            spd_x = 0;
                            spd_y = var_a0_2;
                        }
                        break;
                    case 2:
                        spd_x = -var_a0_2;
                        spd_y = 0;
                        break;
                    case 1:
                        spd_x = 0;
                        spd_y = var_a0_2;
                        break;

                    }
                    ufo_idc_obj->speed_x = spd_x;
                    ufo_idc_obj->speed_y = spd_y;
                    return;
                }
            }
            var_a2 = var_a2 + 1;
            var_a3 = &level.objects[actobj.objects[var_a2]];
        }

    }
}

/* matches, but */
/*INCLUDE_ASM("asm/nonmatchings/obj/ufo_idc", DO_IDC_COMMAND);*/

void DO_IDC_COMMAND(Obj *idc_obj)
{
    s32 temp_v1 = idc_obj->sub_etat;
    s32 new_var2 = temp_v1;
    
    if ((temp_v1 < 4) && (new_var2 >= 0))
    {
        idc_obj->display_prio = 4;
        idc_obj->flags &= ~0x4000;
        return;
    }
    idc_obj->display_prio = 0;
}