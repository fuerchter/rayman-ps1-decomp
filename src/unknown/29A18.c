#include "unknown/29A18.h"

/* 29A18 8014E218 -O2 -msoft-float */
void fades(void)
{
    if (map_time == 0)
        INIT_FADE_IN();

    if (dead_time == 32)
        INIT_FADE_OUT();
    
    if (fade != 0)
        DO_FADE();
}

INCLUDE_ASM("asm/nonmatchings/unknown/29A18", FUN_8014e27c);
