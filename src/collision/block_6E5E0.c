#include "collision/block_6E5E0.h"

/* 6E5E0 80192DE0 -O2 -msoft-float */
u8 MURDUR(s16 x, s16 y)
{
    return PS1_BTYPAbsPos(x, y) == BTYP_SOLID;
}

/* 6E618 80192E18 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", dist_to_bloc_floor);
#else
s16 dist_to_bloc_floor(s16 btyp, s16 x, s16 y)
{
    __asm__("nop");

    switch (btyp)
    {
    case BTYP_SOLID_RIGHT_45:
    case BTYP_SLIPPERY_RIGHT_45:
        x = 15 - x;
        break;
    case BTYP_SOLID_LEFT_45:
    case BTYP_SLIPPERY_LEFT_45:
        break;
    case BTYP_SOLID_RIGHT1_30:
    case BTYP_SLIPPERY_RIGHT1_30:
        x = 15 - (x >> 1);
        break;
    case BTYP_SOLID_RIGHT2_30:
    case BTYP_SLIPPERY_RIGHT2_30:
        x = 7 - (x >> 1);
        break;
    case BTYP_SOLID_LEFT1_30:
    case BTYP_SLIPPERY_LEFT1_30:
        x = x >> 1;
        break;
    case BTYP_SOLID_LEFT2_30:
    case BTYP_SLIPPERY_LEFT2_30:
        x = 8 + (x >> 1);
        break;
    case BTYP_RESSORT:
    case BTYP_SOLID_PASSTHROUGH:
    case BTYP_SOLID:
    case BTYP_SLIPPERY:
        x = 0;
        break;
    case BTYP_NONE:
    case BTYP_CHDIR:
    default:
        x = y;
        break;
    }
    return x - y;
}
#endif

/* 6E6BC 80192EBC -O2 -msoft-float */
s16 bloc_floor(s16 btyp, s16 x, s16 y)
{
    s16 lt_z = -(dist_to_bloc_floor(btyp, x, y) <= 0);
    return btyp & lt_z;
}

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", calc_typ_trav);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", calc_typ_travd);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", TEST_FIN_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", TEST_IS_ON_RESSORT_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", IS_ON_RESSORT_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", CALC_MOV_ON_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", recale_position);
