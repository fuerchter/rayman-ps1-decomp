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

/* matches, but new_var */
/*INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_COMMAND);*/

void DO_MIT_COMMAND(Obj *obj)
{
    s16 diff_x_1;
    s16 diff_x_2;
    s16 diff_y_1;
    Obj *poing_obj;
    s16 esquive_x;
    s32 prev_flip_x;
    s32 new_var;
    ObjState *obj_eta = &obj->eta[obj->main_etat][obj->sub_etat];
    
    if (!IS_MIT_PAF(obj))
    {
        if (obj->field20_0x36 >= 500)
        {
            DO_MIT_ATTAK(obj);
            return;
        }

        if (!(obj->main_etat == 0 && obj->sub_etat == 7))
        {
            if (obj->cmd == GO_LEFT)
                obj->flags &= ~FLG(OBJ_FLIP_X);
            else if (obj->cmd == GO_RIGHT)
                obj->flags |= FLG(OBJ_FLIP_X);
            
            if (obj->detect_zone_flag != 0)
            {
                diff_x_1 = (ray.x_pos + ray.offset_bx) - obj->x_pos - obj->offset_bx;
                diff_x_2 = __builtin_abs(diff_x_1) >> 1;
                diff_y_1 = (obj->y_pos + obj->offset_by) - ray.y_pos - ray.offset_by;
                obj->field20_0x36++;
                if (ray_over_mit(obj, diff_x_1))
                {
                    if (obj->main_etat == 0 && obj->sub_etat == 10)
                        set_sub_etat(obj, 12);
                    else
                        HAS_MIT_JUMP(obj);
                }
                else if (poing.is_active || poing.is_charging)
                {
                    poing_obj = &level.objects[poing_obj_id];
                    mite_esquive_poing(obj, &esquive_x);
                    /* TODO: ??? readable ??? */
                    if (
                        !(obj->flags & FLG(OBJ_FLIP_X)) ?
                            (diff_x_1 < -10 && (-diff_x_2 < esquive_x || poing_obj->speed_x >= 0)) :
                            (diff_x_1 > 10 && (diff_x_2 > esquive_x || poing_obj->speed_x <= 0))
                    )
                    {
                        if (obj->speed_y < 0)
                            HAS_MIT_JUMP(obj);
                        else if (obj_eta->flags & FLG(2))
                            set_main_and_sub_etat(obj, 0, 9);
                    }
                    else
                    {
                        if (obj->main_etat == 0 && obj->sub_etat == 10)
                            set_sub_etat(obj, 12);
                    }

                    MAX_2(obj->speed_y, -3);
                    MIN_2(obj->speed_y, 3);
                }
                else
                {
                    switch (ray.main_etat)
                    {
                    case 0:
                    case 3:
                        if (
                            obj->main_etat == 1 ||
                            (obj->main_etat == 0 && obj->sub_etat == 10)
                        )
                            set_main_and_sub_etat(obj, 0, 8);
                        
                        obj->speed_x = 0;
                        break;
                    case 1:
                        /* TODO: ??? */
                        if (
                            !(
                                obj->main_etat == 2 ||
                                (obj->main_etat == 0 && (obj->sub_etat == 9 || (obj->sub_etat == (new_var = 0x0A)) || obj->sub_etat == 0x0B))
                            )
                        )
                            set_main_and_sub_etat(obj, 1, 0);
                        break;
                    case 2:
                        if (HAS_MIT_JUMP(obj))
                        {
                            if (diff_y_1 > 0)
                            {
                                if (obj->gravity_value_1 == 1)
                                {
                                    obj->speed_y--;
                                    MAX_2(obj->speed_y, -3);
                                }
                            }
                            else
                                MIN_2(obj->speed_y, 1);
                        }
                        break;
                    }
                }

                if (
                    diff_x_2 < 40 && diff_y_1 < 10 &&
                    obj->field24_0x3e == 0 && obj_eta->flags & FLG(1)
                )
                {
                    if (obj->main_etat == 1)
                        set_main_etat(obj, 0);
                    
                    set_sub_etat(obj, 11);
                    obj->field24_0x3e = 1;
                    obj->timer = 0;
                }

                if (obj->field24_0x3e == 1)
                {
                    obj->timer++;
                    if (obj->timer > 40)
                        obj->field24_0x3e = 0;
                }

                if (obj->y_pos + obj->offset_hy < ymap - 50)
                    obj->speed_y += 2;
                
                fix_mit_Xspeed(obj, diff_x_1);
            }
            else
            {
                obj->speed_x = 0;
                if (obj->main_etat != 2)
                {
                    if (obj->main_etat == 1)
                    {
                        set_main_and_sub_etat(obj, 0, 8);
                        skipToLabel(obj, 7, true);
                    }

                    prev_flip_x = obj->flags >> OBJ_FLIP_X & 1;
                    calc_obj_dir(obj);
                    if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
                        skipToLabel(obj, 3, true);
                }
            }

            if (block_flags[obj->btypes[3]] >> BLOCK_FULLY_SOLID & 1)
                obj->speed_y = 0;
            
            if (block_flags[calc_typ_travd(obj, false)] >> BLOCK_FULLY_SOLID & 1)
                obj->speed_x = 0;
            
            if (obj->main_etat != 2)
                CALC_MOV_ON_BLOC(obj);
        }
    }
}