#include "obj/mite.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_ATTAK);*/

void DO_MIT_ATTAK(Obj *obj)
{
    s16 temp_a0_1;
    s16 temp_a1;
    s16 temp_v0_1;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v1_1;
    s16 temp_v1_2;
    s16 var_v0_1;
    s16 var_v0_2;
    s16 var_v0_4;
    s16 var_v1_1;
    s16 var_v1_2;
    s32 var_v0_3;
    s32 var_v0_5;
    u8 temp_a0_2;
    s16 new_var;

    if ((obj->main_etat == 0) && (obj->sub_etat == 0x0A))
    {
        temp_v0_1 = obj->field20_0x36;
        if (temp_v0_1 >= 0x33)
        {
            obj->field20_0x36 = temp_v0_1 - 0x32;
        }
    }
    else if (HAS_MIT_JUMP(obj) & 0xFF)
    {
        if (obj->sub_etat != 1 && obj->field20_0x36 == 0x01F4)
        {
            obj->field56_0x69 = 0x8C;
            obj->speed_y = 0;
            obj->follow_x = (s16) (u16) obj->x_pos;
            obj->field20_0x36 = (u16) obj->field20_0x36 + 1;
            set_sub_etat(obj, 3U);
        }
        else
        {
            if (obj->sub_etat == 3)
            {
                if (obj->gravity_value_2 != 0)
                {
                    temp_v0_2 = obj->speed_y;
                    if (temp_v0_2 >= 0)
                    {
                        obj->speed_y = temp_v0_2 - 1;
                        return;
                    }
                }
            }
            else if (obj->sub_etat == 4)
            {
                temp_v0_3 = obj->x_pos;
                temp_v1_1 = obj->follow_x;
                if ((temp_v0_3 - temp_v1_1) >= 0)
                {
                    var_v0_1 = temp_v0_3 - temp_v1_1;
                }
                else
                {
                    var_v0_1 = temp_v1_1 - temp_v0_3;
                }
                temp_a0_1 = obj->follow_x;
                if (((((ray.x_pos + ray.offset_bx) - temp_a0_1) - obj->offset_bx) - 0xA) >= 0)
                {
                    var_v1_1 = (((ray.x_pos + ray.offset_bx) - temp_a0_1) - obj->offset_bx) - 0xA;
                }
                else
                {
                    new_var = ray.x_pos; /* flip order of ray.x_pos and ray.offset_bx? see DO_STONEWOMAN_COMMAND */
                    var_v1_1 = 0xA - (((ray.offset_bx + new_var) - temp_a0_1) - obj->offset_bx);
                }
                temp_a0_2 = obj->field56_0x69;
                if (((s32) temp_a0_2 < var_v0_1) || ((var_v1_1 < var_v0_1) && (temp_a0_2 == 0x8C)))
                {
                    if ((temp_a0_2 == 0x8C) && (var_v1_1 < 0x8C))
                    {
                        obj->field56_0x69 = (u8) var_v1_1;
                    }
                    if (obj->gravity_value_2 == 1)
                    {
                        if (!(obj->flags & 0x4000))
                        {
                            var_v0_2 = (u16) obj->speed_x + 1;
                        }
                        else
                        {
                            var_v0_2 = (u16) obj->speed_x - 1;
                        }
                        obj->speed_x = var_v0_2;
                    }
                    if (obj->gravity_value_1 == 1)
                    {
                        temp_v0_4 = obj->speed_y;
                        if (temp_v0_4 >= -1)
                        {
                            obj->speed_y = temp_v0_4 - 1;
                        }
                    }
                }
                else
                {
                    temp_v1_2 = ((obj->offset_by + (u16) obj->y_pos) - ray.y_pos) - ray.offset_by;
                    /*
                    if
                    (obj->speed_x <= 0 && obj->flags & 0x4000 && obj->speed_x >= 0)
                    with obj->speed_x = -4: obj->speed_x <= 0 && !(obj->flags & 0x4000)
                    (obj->speed_x > 0 && obj->flags & 0x4000)

                    else
                    (obj->speed_x <= 0 && obj->flags & 0x4000 && obj->speed_x < 0)
                    (obj->speed_x > 0 && !(obj->flags & 0x4000)) ||

                    similar with DO_CLOWN_TNT3_COMMAND?
                    */
                    if (obj->speed_x <= 0)
                    {
                        if (obj->flags & 0x4000)
                        {
                            if (obj->speed_x < 0)
                            {
                                goto block_47;
                                
                            }
                            else
                                goto block_37;
                                
                        }
                        else
                        {
                            obj->speed_x = -4;
                            goto block_40;
                        }

                    }
    block_37:
                    if (obj->flags & 0x4000) 
                    {
                        obj->speed_x = 4;
    block_40:
                        if (temp_v1_2 >= 0xB)
                        {
                            obj->speed_y = -1;
                        }
                        else if (temp_v1_2 < -0x14)
                        {
                            obj->speed_y = 2;
                        }
                        else if (temp_v1_2 < -0xA)
                        {
                            obj->speed_y = 1;
                        }
                        else
                        {
                            obj->speed_y = 0;
                        }
                    }
                    else
                    {
    block_47:
                        if (((temp_v1_2) >= -9) && (ray.main_etat == 0))
                        {
                            obj->speed_y = 0;
                        }
                        else
                        {
                            obj->speed_y = 1;
                        }
                        if (
                            (var_v0_1 < 8 && ((!(obj->flags & 0x4000)))) ||
                            ((var_v0_1 > 8) && (obj->flags & 0x4000)))
                        {
                            if (--obj->speed_x < -4)
                            {
                                obj->speed_x = -4;
                            }
                        }
                        else
                        {
                            if (++obj->speed_x > 4)
                            {
                                obj->speed_x = 4;
                            }
                        }
                        if ((obj->speed_x == 0) && (var_v0_1 < 8))
                        {
                            obj->field20_0x36 = 0;
                            set_sub_etat(obj, 0U);
                        }
                    }
                }
                if (block_flags[calc_typ_travd(obj, 0U) & 0xFF] & 1)
                {
                    var_v1_2 = 1;
                    if (obj->speed_x > 0)
                    {
                        var_v1_2 = -1;
                    }
                    obj->speed_x = var_v1_2;
                }
            }
        }
    }
}

/* matches, but gotos and other cleanup */
/*INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_COMMAND);*/

void DO_MIT_COMMAND(Obj *obj)
{
    s16 sp10;
    Obj *temp_s3_2;
    ObjState *temp_s4;
    s16 temp_s3_1;
    s16 temp_v0;
    s16 temp_v1_2;
    s16 var_v0_3;
    s16 var_v1;
    s32 temp_s0;
    s16 temp_s2;
    s32 var_v0_2;
    u32 var_v0;
    u8 temp_v1;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 temp_v1_5;
    u8 temp_v1_6;
    int new_var;

    temp_s4 = &obj->eta[obj->main_etat][obj->sub_etat];
    if (!(IS_MIT_PAF(obj) & 0xFF))
    {
        if (obj->field20_0x36 >= 0x1F4)
        {
            DO_MIT_ATTAK(obj);
            return;
        }
        if ((obj->main_etat != 0) || (obj->sub_etat != 7))
        {
            temp_v1 = obj->cmd;
            if (temp_v1 == 0)
            {
                obj->flags = obj->flags & ~0x4000;
            }
            else if (temp_v1 == 1)
            {
                obj->flags = obj->flags | 0x4000;
            }
            if (obj->detect_zone_flag != 0)
            {
                
                temp_v1_2 = ((ray.offset_bx + ray.x_pos) - (u16) obj->x_pos) - obj->offset_bx;
                temp_s2 = __builtin_abs(temp_v1_2) >> 1;
                temp_s3_1 = ((obj->offset_by + (u16) obj->y_pos) - ray.y_pos) - ray.offset_by;
                obj->field20_0x36++;
                if (ray_over_mit(obj, temp_v1_2) & 0xFF)
                {
                    if ((obj->main_etat == 0) && (obj->sub_etat == 0x0A))
                    {
                        set_sub_etat(obj, 0x0CU);
                    }
                    else
                    {
                        HAS_MIT_JUMP(obj);
                    }
                }
                else if ((poing.is_active != 0) || (poing.is_charging != 0))
                {
                    temp_s3_2 = &level.objects[poing_obj_id];
                    mite_esquive_poing(obj, &sp10);
                    if (!(obj->flags & 0x4000))
                    {
                        if (temp_v1_2 < -0xA)
                        {
                            if (-(s16) temp_s2 >= sp10)
                            {
                                if (temp_s3_2->speed_x >= 0)
                                {
                                    goto block_28;
                                }
                                goto block_32;
                            }
                            goto block_28;
                        }
                        goto block_32;
                    }

                    if ((temp_v1_2 >= 0xB) && ((sp10 < (s16) temp_s2) || (temp_s3_2->speed_x <= 0)))
                    {
block_28:
                        if (obj->speed_y < 0)
                        {
                            HAS_MIT_JUMP(obj);
                        }
                        else if (temp_s4->flags & 4)
                        {
                            set_main_and_sub_etat(obj, 0U, 9U);
                        }
                    }
                    else
                    {
block_32:
                        if ((obj->main_etat == 0) && (obj->sub_etat == 0x0A))
                        {
                            set_sub_etat(obj, 0x0CU);
                        }
                    }

                    if (obj->speed_y < -3)
                    {
                        obj->speed_y = -3;
                    }
                    if (obj->speed_y > 3)
                    {
                        obj->speed_y = 3;
                    }
                }
                else
                {
                    /* TODO: switch */
                    switch (ray.main_etat)
                    {
                    case 0:
                    case 3:
                        temp_v1_3 = obj->main_etat;
                        if ((temp_v1_3 == 1) || ((temp_v1_3 == 0) && (obj->sub_etat == 0x0A)))
                        {
                            set_main_and_sub_etat(obj, 0U, 8U);
                        }
                        obj->speed_x = 0;
                        break;
                    case 1:
                        if (obj->main_etat != 2)
                        {
                            if (obj->main_etat == 0)
                            {
                                /* TODO: ??? */
                                if (!((obj->sub_etat == 9) || (obj->sub_etat == (new_var = 0x0A)) || obj->sub_etat == 0x0B))
                                    set_main_and_sub_etat(obj, 1U, 0U);
                            }
                            else
                            {
                                set_main_and_sub_etat(obj, 1U, 0U);
                            }
                        }
                        break;
                    case 2:
                        if (HAS_MIT_JUMP(obj) & 0xFF)
                        {
                            if ((temp_s3_1 << 0x10) > 0)
                            {
                                if (obj->gravity_value_1 == 1)
                                {
                                    if (--obj->speed_y < -3)
                                    {
                                        obj->speed_y = -3;
                                    }
                                    break;
                                }
                            }
                            else
                            {
                                if (obj->speed_y > 1)
                                {
                                    obj->speed_y = 1;
                                }
                            }
                        }
                        break;
                    }
                }

                if (((temp_s2) < 0x28) && (temp_s3_1 < 0xA) && (obj->field24_0x3e == 0) && (temp_s4->flags & 2))
                {
                    if (obj->main_etat == 1)
                    {
                        set_main_etat(obj, 0U);
                    }
                    set_sub_etat(obj, 0x0BU);
                    obj->field24_0x3e = 1;
                    obj->timer = 0;
                }
                if (obj->field24_0x3e == 1)
                {
                    obj->timer += 1;
                    if ((u8) obj->timer >= 0x29U)
                    {
                        obj->field24_0x3e = 0;
                    }
                }
                if ((obj->y_pos + obj->offset_hy) < (ymap - 0x32))
                {
                    obj->speed_y = (u16) obj->speed_y + 2;
                }
                fix_mit_Xspeed(obj, temp_v1_2);
            }
            else
            {
                obj->speed_x = 0;
                if (obj->main_etat != 2)
                {
                    if (obj->main_etat == 1)
                    {
                        set_main_and_sub_etat(obj, 0U, 8U);
                        skipToLabel(obj, 7U, 1U);
                    }
                    temp_s0 = ((u32) obj->flags >> 0xE) & 1;
                    calc_obj_dir(obj);
                    if ((((u32) obj->flags >> 0xE) & 1) != temp_s0)
                    {
                        skipToLabel(obj, 3U, 1U);
                    }
                }
            }
            if (block_flags[obj->btypes[3]] & 1)
            {
                obj->speed_y = 0;
            }
            if (block_flags[calc_typ_travd(obj, 0U) & 0xFF] & 1)
            {
                obj->speed_x = 0;
            }
            if (obj->main_etat != 2)
            {
                CALC_MOV_ON_BLOC(obj);
            }
        }
    }
}