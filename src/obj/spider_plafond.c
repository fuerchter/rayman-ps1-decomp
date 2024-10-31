#include "obj/spider_plafond.h"

extern u8 D_801F55D0;

/* 537C0 80177FC0 -O2 -msoft-float */
void get_spi_zdc(Obj *param_1, s16 *param_2, s16 *param_3, s16 *param_4, s16 *param_5)
{
    u8 eta_flags = param_1->eta[param_1->main_etat][param_1->sub_etat].flags;
    
    if (eta_flags & 0x40)
    {
        *param_2 = param_1->x_pos + 69;
        *param_3 = param_1->y_pos + 38;
        *param_4 = 21;
        *param_5 = 30;
    }
    else if (eta_flags & 0x80)
    {
        *param_2 = param_1->x_pos + 69;
        *param_3 = param_1->y_pos + 86;
        *param_4 = 34;
        *param_5 = 10;
    }
    else
    {
        *param_2 = param_1->x_pos + 71;
        *param_3 = param_1->y_pos + 71;
        *param_4 = 29;
        *param_5 = 19;
    }
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_SPIDER_PLAFOND);
#else
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
#endif

/* 53E40 80178640 -O2 -msoft-float */
void DO_SPIDER_PLAFOND_POING_COLLISION(Obj *obj)
{
    s32 main_etat;

    if (--obj->hit_points == 0)
    {
        if (
            (
                obj->main_etat == 0 &&
                (obj->sub_etat == 12 || obj->sub_etat == 13 ||
                obj->sub_etat == 23 || obj->sub_etat == 20)
            ) ||
            (
                obj->main_etat == 2 &&
                (obj->sub_etat == 2 || obj->sub_etat == 3 ||
                obj->sub_etat == 28 || obj->sub_etat == 7)
            )
        )
            set_main_and_sub_etat(obj, 0, 19);
        else
            set_main_and_sub_etat(obj, 0, 18);
        obj->speed_y = -8;
        obj->speed_x = 0;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
    }
    else
    {
        main_etat = obj->main_etat;
        if (main_etat == 1 && obj->sub_etat == 2)
        {
            /* this, or goto? */
            set_main_and_sub_etat(obj, 0, 14);
            obj->speed_y = 0;
            obj->speed_x = 0;
        }
        else if (main_etat == 0)
        {
            /*
            using a switch would generate rodata
            using a var for obj->sub_etat doesn't seem to work either
            */
            if (
                obj->sub_etat == 11 || obj->sub_etat == 29 ||
                obj->sub_etat == 25 || obj->sub_etat == 26 ||
                obj->sub_etat == 27 || obj->sub_etat == 24 ||
                obj->sub_etat == 30
            )
            {
                set_main_and_sub_etat(obj, 0, 14);
                obj->speed_y = 0;
                obj->speed_x = 0;
            }
            else if (
                obj->sub_etat == 12 || obj->sub_etat == 13 ||
                obj->sub_etat == 23 || obj->sub_etat == 20
            )
            {
                if (obj->x_pos < ray.x_pos)
                    obj->flags |= FLG(OBJ_FLIP_X);
                else
                    obj->flags &= ~FLG(OBJ_FLIP_X);
                set_main_and_sub_etat(obj, 0, 17);
            }
        }
    }
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", SPIDER_PLAFOND_REACT);
#else
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
#endif

INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_DARD_PLAFOND_ALWAYS);
