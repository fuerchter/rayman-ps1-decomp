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

INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_SPIDER_PLAFOND);

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

INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", SPIDER_PLAFOND_REACT);

INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_DARD_PLAFOND_ALWAYS);
