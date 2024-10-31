#include "timers.h"

#ifdef BSS_DEFS
u8 horloge[25];
s32 map_time;
s32 left_time;
s16 allowed_time[192];
#endif

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

/* 29888 8014E088 -O2 -msoft-float */
s32 get_allowed_time(void)
{
    s16 nw = (num_world << 5) - ((1 << 5) + 1);

    return allowed_time[(s16) (nw + num_level)];
}

/* 298C4 8014E0C4 -O2 -msoft-float */
void calc_left_time(void)
{
    s32 unk_1;
    s16 nw = (num_world << 5) - ((1 << 5) + 1);
    s16 index = nw + num_level;
    
    if (map_time == 1)
    {
        left_time = allowed_time[index];
        if (left_time != -2)
            left_time *= 60;
    }
    if (allowed_time[index] != -2 && left_time != 0 && (map_time > 2 * 60))
    {
        ray.flags |= FLG(OBJ_ACTIVE);
        unk_1 = allowed_time[index] * 60 + 2 * 60;
        left_time = unk_1 - map_time;
        if (left_time == 0 && nb_wiz != 0)
        {
            status_bar.num_wiz = nb_wiz_save;
            nb_wiz_save = 0;
            departlevel = false;
            fix_numlevel(&ray);
        }
    }
}
