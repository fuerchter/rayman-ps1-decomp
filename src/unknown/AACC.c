#include "unknown/AACC.h"

void FUN_8012f2cc(void) {}

INCLUDE_ASM("asm/nonmatchings/unknown/AACC", PouvoirsParMap);

/* AD40 8012F540 -O2 -msoft-float */
void PS1_ResetSaveZone(void)
{
    s32 i;
    s32 len = LEN(save_zone);

    for (i = 0; i < len; i++)
        save_zone[i] = 0;
}

/* AD70 8012F570 -O2 -msoft-float */
void FUN_8012f570(void)
{
    D_801CEEA0++;
}
