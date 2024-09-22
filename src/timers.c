#include "timers.h"

extern s16 allowed_time[192];

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

/* 29488 8014DC88 -O2 -msoft-float */
void PS1_InitAllowedTime(void)
{
    s16 cnt_1;
    s16 cnt_2;
    s16 *cur;
    
    for (cnt_1 = 1; cnt_1 <= (s16) LEN(allowed_time) >> 5; cnt_1++)
    {
        cnt_2 = (cnt_1 - 1);
        cur = &allowed_time[(s16) (cnt_2 << 5)];
        switch (cnt_2)
        {
        case 0:
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = 30;
            *cur++ = 45;
            *cur++ = 35;
            *cur++ = 25;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            break;
        case 1:
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = 40;
            *cur++ = 25;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            break;
        case 2:
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = 45;
            *cur++ = 20;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            break;
        case 3:
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = 35;
            *cur++ = 50;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            break;
        case 4:
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = 35;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            break;
        case 5:
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            *cur++ = -2;
            break;
        }
    }
}



INCLUDE_ASM("asm/nonmatchings/timers", get_allowed_time);

INCLUDE_ASM("asm/nonmatchings/timers", calc_left_time);
