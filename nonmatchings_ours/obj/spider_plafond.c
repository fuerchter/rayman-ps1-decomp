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