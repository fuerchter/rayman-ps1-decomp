#include "obj/spider_plafond.h"

/* matches, but clean up */
/*INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_SPIDER_PLAFOND);*/

void DO_SPIDER_PLAFOND(Obj *obj)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    Obj *temp_v0;
    Obj *var_s2;
    Obj *var_s0;
    s16 temp_a0_2;
    s16 temp_a1_3;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 temp_a3;
    s16 temp_s2_1;
    s16 temp_s3;
    s16 temp_t0;
    s16 temp_v0_2;
    s16 temp_v0_5;
    s16 temp_v1_3;
    s16 var_a0;
    s32 temp_s2_2;
    s32 var_v0;
    u16 temp_a1_1;
    u16 temp_v1_2;
    u32 temp_v0_3;
    u32 temp_v0_4;
    u8 temp_a0;
    u8 temp_a1_2;
    u8 temp_s0_1;
    u8 temp_s0_2;
    u8 temp_v1;
    u8 temp_v1_4;
    s16 nb_objs;
    u8 test_1;

    temp_s2_1 = get_center_x(obj);
    temp_s3 = get_center_y(obj);
    if (
        (
            (obj->main_etat == 0) &&
            ((temp_v1 = obj->sub_etat,
            (temp_v1 == 0x1B)) || (temp_v1 == 0x18) || (temp_v1 == 0x1E) || (temp_v1 == 0x0B))
        ) ||
        ((obj->main_etat == 1) && (obj->sub_etat == 2))
    )
    {
        if (
            (poing.is_active != 0)
        )
        {
            temp_v0 = &level.objects[poing_obj_id];
            temp_t0 = temp_v0->offset_bx + temp_v0->x_pos;
            temp_a0_2 = temp_v0->offset_by + temp_v0->y_pos;
            temp_a3 = temp_v0->offset_hy + temp_v0->y_pos;

            temp_a2 = obj->offset_bx + obj->x_pos;
            temp_v0_2 = obj->offset_by + obj->y_pos + 5;
            temp_v1_3 = (obj->offset_hy + obj->y_pos) - 5;
            if (
                ((((temp_v0_2 < temp_a0_2) == 0)) || (temp_v0_2 >= temp_a3)) &&
                ((temp_a0_2 >= temp_v1_3) || (temp_a3 >= temp_v1_3)) &&
                (temp_t0 <= temp_a2 + 0x3C) && (temp_t0 >= temp_a2 - 0x3C))
            {
                obj->speed_x = 0;
                obj->speed_y = 0;
                set_main_and_sub_etat(obj, 0U, 0x19U);
            }
        }
    }
    else if ((obj->main_etat == 0) && (obj->sub_etat == 0x1A) && (poing.is_active == 0))
    {
        set_sub_etat(obj, 0x1BU);
    }
    temp_s0_1 = obj->main_etat;
    if (temp_s0_1 == 1)
    {
        if (obj->sub_etat == 2)
        {
            SET_X_SPEED(obj);
            if (block_flags[calc_typ_travd(obj, 0U) & 0xFF] & 1)
            {
                temp_v0_3 = obj->flags;
                obj->flags = (temp_v0_3 & ~0x4000) | (((temp_s0_1 - ((temp_v0_3 >> 0xE) & 1)) & 1) << 0xE);
                set_main_and_sub_etat(obj, 0U, 0x18U);
                SET_X_SPEED(obj);
            }
            CALC_MOV_ON_BLOC(obj);
        }
    }

    if (
        ((on_block_chdir(obj, (s16) temp_s2_1, temp_s3)) != 0) &&
        ((test_allowed(obj, (s16) temp_s2_1, temp_s3)) != 0)
    )
    {
        temp_s0_2 = obj->main_etat;
        if ((temp_s0_2 == 1) && (obj->sub_etat == 2))
        {
            set_main_and_sub_etat(obj, 0U, 0x15U);
            temp_v0_4 = obj->flags;
            obj->speed_x = 0;
            obj->speed_y = 0;
            obj->flags = (temp_v0_4 & ~0x4000) | (((temp_s0_2 - ((temp_v0_4 >> 0xE) & 1)) & 1) << 0xE);
        }
        else if ((obj->main_etat == 2) && ((obj->sub_etat == 3) || (obj->sub_etat == 1 || obj->sub_etat == 2)))
        {
            set_main_and_sub_etat(obj, 0U, 0x0CU);
            obj->speed_x = 0;
            obj->speed_y = 0;
        }
    }
    else if ((obj->main_etat == 2) && (obj->sub_etat == 1) && (obj->anim_frame == 0))
    {
        obj->speed_x = 0;
        obj->speed_y = -0x000A;
    }
    else if (obj->main_etat == 0 && (obj->sub_etat == 0x14) && (obj->anim_frame == 0x1B))
    {
        var_s2 = level.objects;
        var_a0 = 0;
        nb_objs = level.nb_objects;
        while (var_a0 < nb_objs)
        {
            if ((var_s2->type == 0xC4) && !(var_s2->flags & 0x800))
            {
                GET_SPRITE_POS(obj, 2, &sp18, &sp1A, &sp1C, &sp1E);
                var_s2->speed_x = 0;
                var_s2->speed_y = 0x0020;
                var_s2->cmd_offset = -1;
                
                var_s2->flags = (s32) (var_s2->flags & ~0x4000);
                temp_a2_2 = ((u16) sp18 - var_s2->offset_bx) + ((s32) ((u16) sp1C << 0x10) >> 0x11);
                var_s2->x_pos = temp_a2_2;
                var_s2->init_x_pos = temp_a2_2;
                temp_a1_3 = ((u16) sp1A - var_s2->offset_by) + ((s32) ((u16) sp1E << 0x10) >> 0x11);
                var_s2->y_pos = temp_a1_3;
                var_s2->init_y_pos = temp_a1_3;
                var_s2->flags = (s32) (var_s2->flags | 0x8C00);
                var_s2->nb_cmd = 0;
                if (ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40)
                {
                    D_801F55D0 = 1;
                }
                else
                {
                    D_801F55D0 = 0;
                }
                DO_DARD_PLAFOND_ALWAYS(var_s2);
                break;
            }
            var_s2++;
            var_a0++;
        }
    }

    if (
        (obj->main_etat == 0) &&
        ((temp_v1_4 = obj->sub_etat, (temp_v1_4 == 0x14)) || (temp_v1_4 == 0x0D) || (temp_v1_4 == 0x17)))
    {
        test_1 = ray.x_pos > obj->x_pos;
        obj->flags = (obj->flags & ~0x4000) | ((test_1) << 0xE);
    }
}

/* matches, but */
/*INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", SPIDER_PLAFOND_REACT);*/

void SPIDER_PLAFOND_REACT(Obj *obj)
{
    s32 prev_flip;
    u8 new_flip;

    if (obj->main_etat == 0 && (obj->sub_etat == 12 || obj->sub_etat == 13))
        set_sub_etat(obj, 20);
    else if (
        (obj->main_etat == 0 && (obj->sub_etat == 11 || obj->sub_etat == 30)) ||
        (obj->main_etat == 1 && obj->sub_etat == 2)
    )
    {
        prev_flip = obj->flags >> OBJ_FLIP_X;
        prev_flip &= 1;
        if (
            (ray.x_pos > obj->x_pos && prev_flip != true) || /* ??? */
            (ray.x_pos <= obj->x_pos && prev_flip != false)
        )
        {
            new_flip = ray.x_pos > obj->x_pos;
            obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | ((new_flip) << OBJ_FLIP_X);
            obj->speed_x = 0;
            obj->speed_y = 0;
            set_main_and_sub_etat(obj, 0, 24);
        }
    }
}

/* completely clueless rn. look at similar functions */
/*INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_DARD_PLAFOND_ALWAYS);*/

void DO_DARD_PLAFOND_ALWAYS(Obj *obj)
{
    s16 temp_a1_3;
    s16 temp_a3;
    s16 temp_v1_1;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 temp_v1_5;
    s16 temp_v1_6;
    s16 temp_v1_7;
    s16 temp_v1_8;
    s16 var_s2;
    s16 var_s3;
    s16 var_v0_1;
    s16 var_v0_11;
    s32 var_v0_4;
    s16 var_v0_6;
    s16 var_v1_1;
    s16 var_v1_2;
    s16 var_v1_3;
    s16 var_v1_4;
    s16 var_v1_5;
    s32 temp_a0_1;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1_1;
    s32 temp_a1_2;
    s32 temp_v0_1;
    s32 temp_v0_10;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_9;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_5;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    u32 temp_v1_10;
    u32 temp_v1_11;
    u32 var_v0_10;
    u32 var_v0_13;
    u8 var_v0_12;

    if (obj->cmd != 1)
    {
        var_s3 = (ray.offset_bx + ray.x_pos) - (obj->offset_bx + (u16) obj->x_pos);
        if (D_801F55D0 != 0)
        {
            var_s2 = (ray.offset_by + ray.y_pos) - (obj->offset_by + (u16) obj->y_pos);
        }
        else
        {
            var_s2 = (((u8) ray.offset_by >> 1) + ray.y_pos) - (obj->offset_by + (u16) obj->y_pos);
        }
        var_v1_1 = __builtin_abs(var_s3);
        var_v0_1 = __builtin_abs(var_s2);
        temp_a3 = var_v1_1 + var_v0_1;
        if (
            (ray.y_pos + ray.offset_by > obj->y_pos + (obj->offset_by - obj->offset_hy)) &&
            (
                temp_a1_1 = ray.x_pos + ray.offset_bx,
                temp_a0_1 = obj->x_pos + obj->offset_bx,
                var_v0_2 = temp_a1_1 < temp_a0_1,
                (
                    temp_a0_1 < temp_a1_1 &&
                    (var_v0_2 = temp_a1_1 < temp_a0_1, !(obj->flags & 0x4000))
                ) ||
                (var_v0_2 && obj->flags & 0x4000)
            )
        )
        {
            if (temp_a3 > 0)
            {
                var_s3 = ashl16(var_s3, 5U) / temp_a3;
                var_s2 = ashl16(var_s2, 5U) / temp_a3;
            }
            temp_v1_1 = obj->speed_y;
            temp_v0_3 = var_s2 - temp_v1_1;
            if (temp_v0_3 >= 0)
            {
                if (temp_v0_3 > 0)
                {
                    var_v0_3 = var_s2 << 0x10;
                    if ((temp_v1_1 + 1) >= 0x20)
                    {
                        goto block_37;
                    }
                    goto block_29;
                }
                if (temp_v1_1 < 0x20)
                {
                    goto block_28;
                }
                goto block_36;
            }
            if ((temp_v1_1 - 1) < 0x20)
            {
block_28:
                var_v0_3 = var_s2 << 0x10;
block_29:
                /*temp_v0_4 = (var_v0_3 >> 0x10) - obj->speed_y;*/
                temp_v0_4 = (var_s2) - obj->speed_y; /* pattern 1 */
                if (temp_v0_4 >= 0)
                {
                    if (temp_v0_4 > 0)
                    {
                        var_v0_4 = 0; /* pattern 2 */
                        if ((obj->speed_y + 1) > 0)
                        {
                            goto block_36;
                        }
                    }
                    else
                    {
                        var_v0_4 = 0;
                        if (obj->speed_y > 0)
                        {
                            goto block_36;
                        }
                    }
                }
                else
                {
                    var_v0_4 = 0;
                    if ((obj->speed_y - 1) > 0)
                    {
                        goto block_36;
                    }
                }
            }
            else
            {
block_36:
block_37:
                temp_v0_4 = var_s2 - obj->speed_y;
                if (temp_v0_4 >= 0)
                {
                    if (temp_v0_4 > 0)
                    {
                        var_v0_4 = 0x0020;
                        if ((obj->speed_y + 1) < 0x20)
                        {
                            goto block_44;
                        }
                    }
                    else
                    {
                        var_v0_4 = 0x0020;
                        if (obj->speed_y < 0x20)
                        {
                            goto block_44;
                        }
                    }
                }
                else
                {
                    var_v0_4 = 0x0020;
                    if ((obj->speed_y - 1) < 0x20)
                    {
block_44:
                        /* had temp_v1_2 */
                        temp_v0_6 = var_s2 - obj->speed_y;
                        if (temp_v0_6 >= 0)
                        {
                            var_v0_4 = obj->speed_y + (temp_v0_6 > 0);
                        }
                        else
                        {
                            var_v0_4 = obj->speed_y - 1;
                        }
                    }
                }
            }
            obj->speed_y = var_v0_4;
            if (((s16) var_v0_4) != 0)
            {
                temp_v1_1 = obj->speed_x;
                temp_v0_3 = var_s3 - temp_v1_1;
                if (temp_v0_3 >= 0)
                {
                    if (temp_v0_3 > 0)
                    {
                        var_v0_5 = var_s3 << 0x10;
                        if ((temp_v1_1 + 1) >= 0x20)
                        {
                            goto block_64;
                        }
                        goto block_56;
                    }
                    if (temp_v1_1 < 0x20)
                    {
                        goto block_55;
                    }
                    goto block_63;
                }
                if ((temp_v1_1 - 1) < 0x20)
                {
block_55:
                    var_v0_5 = var_s3 << 0x10;
block_56:
                    /*temp_v0_4 = (var_v0_5 >> 0x10) - obj->speed_x;*/
                    temp_v0_4 = (var_s3) - obj->speed_x;
                    if (temp_v0_4 >= 0)
                    {
                        if (temp_v0_4 > 0)
                        {
                            var_v0_4 = -0x0020;
                            if ((obj->speed_x + 1) >= -0x1F)
                            {
                                goto block_63;
                            }
                        }
                        else
                        {
                            var_v0_4 = -0x0020;
                            if (obj->speed_x < -0x1F)
                            {

                            }
                            else
                            {
                                goto block_63;
                            }
                        }
                    }
                    else
                    {
                        var_v0_4 = -0x0020;
                        if ((obj->speed_x - 1) >= -0x1F)
                        {
                            goto block_63;
                        }
                    }
                }
                else
                {
block_63:
block_64:
                    temp_v0_4 = var_s3 - obj->speed_x;
                    if (temp_v0_4 >= 0)
                    {
                        if (temp_v0_4 > 0)
                        {
                            var_v0_4 = 0x0020;
                            if ((obj->speed_x + 1) < 0x20)
                            {
                                goto block_71;
                            }
                        }
                        else
                        {
                            var_v0_4 = 0x0020;
                            if (obj->speed_x < 0x20)
                            {
                                goto block_71;
                            }
                        }
                    }
                    else
                    {
                        var_v0_4 = 0x0020;
                        if ((obj->speed_x - 1) < 0x20)
                        {
block_71:
                            temp_v1_2 = obj->speed_x;
                            temp_v0_6 = var_s3 - temp_v1_2;
                            if (temp_v0_6 >= 0)
                            {
                                var_v0_4 = temp_v1_2 + (temp_v0_6 > 0);
                            }
                            else
                            {
                                var_v0_4 = temp_v1_2 - 1;
                            }
                        }
                    }
                }
                obj->speed_x = var_v0_4;
            }
            else
            {
                /* start */
                if (obj->flags & 0x4000)
                {
                    temp_v1_1 = obj->speed_x;
                    if (temp_v1_1 < var_s3)
                    {
                        var_v0_7 = var_s3 << 0x10;
                        if ((temp_v1_1 - 1) >= 0x20)
                        {
                            goto block_86;
                        }
                        goto block_81;
                    }
                    var_v0_7 = var_s3 << 0x10;
                    if (temp_v1_1 < 0x20)
                    {
block_81:
                        /*if (obj->speed_x < (var_v0_7 >> 0x10))*/
                        if (obj->speed_x < var_s3)
                        {
                            var_v0_4 = -0x0020;
                            if ((obj->speed_x - 1) >= -0x1F)
                            {
                                goto block_85;
                            }
                        }
                        else
                        {
                            var_v0_4 = -0x0020;
                            if (obj->speed_x >= -0x1F)
                            {
                                goto block_85;
                            }
                        }
                    }
                    else
                    {

block_85:
block_86:
                        if (obj->speed_x < var_s3 && (obj->speed_x - 1) >= 0x20)
                        {
                            var_v0_4 = 0x0020;

                        }
                        else if (obj->speed_x < var_s3 || obj->speed_x < 0x20)
                        {
block_90:
                            var_v0_4 = obj->speed_x - (obj->speed_x < var_s3);
                        }
                        else
                        {
                            var_v0_4 = 0x0020;
                        }
                    }
                }
                else
                {
                    
                    /*if (
                        (
                            (var_s3 < obj->speed_x && (obj->speed_x + 1) < 0x20) ||
                            (var_s3 >= obj->speed_x && obj->speed_x < 0x20)
                        ) &&
                        (
                            ((var_s3) < obj->speed_x && (obj->speed_x + 1) >= -0x1F) ||
                            ((var_s3) >= obj->speed_x && obj->speed_x >= -0x1F)
                        )
                    )
                    {
block_100:
                        if (var_s3 < obj->speed_x && (obj->speed_x + 1) >= 0x20)
                        {
                            var_v0_4 = 0x0020;
                        }
                        else if (!(var_s3 >= obj->speed_x && obj->speed_x >= 0x20))
                        {
                            var_v0_4 = obj->speed_x + (var_s3 < obj->speed_x);
                        }
                        else
                        {
                            var_v0_4 = 0x0020;
                        }
                    }
                    else
                    {
                        var_v0_4 = -0x0020;
                    }*/
                    temp_v1_1 = obj->speed_x;
                    if (var_s3 < temp_v1_1)
                    {
                        var_v0_8 = var_s3 << 0x10;
                        if ((temp_v1_1 + 1) < 0x20)
                        {
                            goto block_96;
                        }
                        else
                            goto block_101;
                        
                    }
                    var_v0_8 = var_s3 << 0x10;
                    if (temp_v1_1 < 0x20)
                    {
block_96:
                        /*if ((var_v0_8 >> 0x10) < obj->speed_x)*/
                        if ((var_s3) < obj->speed_x)
                        {
                            var_v0_4 = -0x0020;
                            if ((obj->speed_x + 1) >= -0x1F)
                            {
                                goto block_100;
                            }
                        }
                        else
                        {
                            var_v0_4 = -0x0020;
                            if (obj->speed_x >= -0x1F)
                            {
                                goto block_100;
                            }
                        }
                    }
                    else
                    {
block_100:
block_101:
                        if (var_s3 < obj->speed_x && (obj->speed_x + 1) >= 0x20)
                        {
                            var_v0_4 = 0x0020;
                        }
                        else if (!(var_s3 >= obj->speed_x && obj->speed_x >= 0x20))
                        {
                            var_v0_4 = obj->speed_x + (var_s3 < obj->speed_x);
                        }
                        else
                        {
                            var_v0_4 = 0x0020;
                        }
                    }
                }
                obj->speed_x = var_v0_4;
            }
        }
        else
        {
            var_v1_3 = obj->speed_x * 2;
            var_v0_9 = var_v1_3 < -0x20;
            if (var_v1_3 >= 0x21)
            {
                var_v1_3 = 0x0020;
                var_v0_9 = 0x20 < -0x20;
            }
            if (var_v0_9 != 0)
            {
                var_v1_3 = -0x0020;
            }
            obj->speed_x = var_v1_3;
            var_v1_4 = obj->speed_y * 2;
            if (var_v1_4 >= 0x21)
            {
                var_v1_4 = 0x0020;
            }
            obj->speed_y = var_v1_4;
        }
    }
    else
    {
        temp_a1_2 = (s16) ray.x_pos + ray.offset_bx;
        temp_a0_2 = obj->x_pos + obj->offset_bx;
        if (temp_a0_2 < temp_a1_2)
        {
            var_v0_10 = obj->flags & ~0x4000;
            goto block_119;
        }
        if (temp_a1_2 < temp_a0_2)
        {
            var_v0_10 = obj->flags | 0x4000;
block_119:
            obj->flags = var_v0_10;
        }
    }
    if ((s32) obj->speed_x == 0)
    {
        var_v1_5 = 1;
        if (obj->flags & 0x4000)
        {
            var_v1_5 = -1;
        }
        obj->speed_x = var_v1_5;
    }
    var_v0_11 = obj->speed_x;
    temp_a1_3 = obj->speed_y;
    if (var_v0_11 < 0)
    {
        var_v0_11 = -var_v0_11;
    }
    temp_a0_3 = var_v0_11 * 3;
    if ((temp_a0_3 < temp_a1_3) || (temp_v1_9 = temp_a1_3 * 3, (((var_v0_11 * 4) < temp_v1_9) != 0)))
    {
        obj->anim_frame = 0;
    }
    else
    {
        var_v0_12 = 0x0B;
        if (temp_a0_3 >= (temp_a1_3 * 4))
        {
            var_v0_12 = 0x0A;
            if (var_v0_11 >= temp_v1_9)
            {
                var_v0_12 = 9;
            }
        }
        obj->anim_frame = var_v0_12;
    }
    if (obj->speed_x > 0)
    {
        temp_v1_10 = obj->flags;
        if (temp_v1_10 & 0x4000)
        {
            var_v0_13 = temp_v1_10 & ~0x4000;
            goto block_139;
        }
        goto block_137;
    }
block_137:
    if (obj->speed_x < 0)
    {
        temp_v1_11 = obj->flags;
        var_v0_13 = temp_v1_11 | 0x4000;
        if (!(temp_v1_11 & 0x4000))
        {
block_139:
            obj->flags = var_v0_13;
        }
    }
}