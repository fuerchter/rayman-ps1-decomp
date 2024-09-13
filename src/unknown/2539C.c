#include "unknown/2539C.h"

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Deter_Option_Caract);

/* 25498 80149C98 -O2 -msoft-float */
void SwapAB(s16 *param_1, s16 *param_2)
{
    s16 prev_2;

    prev_2 = *param_2;
    *param_2 = *param_1;
    *param_1 = prev_2;
}

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Bresenham);

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", LOAD_CONFIG);

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", init_finBossLevel);

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Change_Wait_Anim);

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", PS1_SetSauveRayEvts);

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", PS1_RestoreSauveRayEvts);
