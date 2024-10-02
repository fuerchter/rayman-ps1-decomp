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

INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_SPIDER_PLAFOND_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", SPIDER_PLAFOND_REACT);

INCLUDE_ASM("asm/nonmatchings/obj/spider_plafond", DO_DARD_PLAFOND_ALWAYS);
