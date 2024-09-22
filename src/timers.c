#include "timers.h"

/* 293C4 8014DBC4 -O2 -msoft-float */
void INIT_HORLOGES(void)
{
    u8 i;

    for (i = 0; i < LEN(horloge); i++)
        horloge[i] = 0;
}

/* 293F8 8014DBF8 -O2 -msoft-float */
void horloges(void)
{
    u8 i;

    for (i = 0; i < LEN(horloge); i++)
    {
        horloge[i]++;
        if (horloge[i] >= i)
            horloge[i] = 0;
    }
    map_time++;
}

INCLUDE_ASM("asm/nonmatchings/timers", PS1_InitAllowedTime);

INCLUDE_ASM("asm/nonmatchings/timers", get_allowed_time);

INCLUDE_ASM("asm/nonmatchings/timers", calc_left_time);
