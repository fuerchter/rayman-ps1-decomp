#include "unknown/AACC.h"

void FUN_8012f2cc(void) {}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/unknown/AACC", PouvoirsParMap);
#else
/* matches, but more cleanup/labelling */
/*INCLUDE_ASM("asm/nonmatchings/unknown/AACC", PouvoirsParMap);*/

void PouvoirsParMap(void)
{
    RaymanEvents sp0 = D_801CEE84;
    RaymanEvents sp8 = D_801CEE88;
    RaymanEvents sp10 = D_801CEE8C;
    RaymanEvents sp18 = D_801CEE90;
    RaymanEvents sp20 = D_801CEE94;
    RaymanEvents sp28 = PS1_DefaultRayEvts;

    switch (num_world)
    {
    case 1:
        if (num_level < 4)
        {
            RayEvts = sp0;
        }
        if ((u16) num_level - 4 < 5U)
        {
            RayEvts = sp8;
        }
        if ((u16) num_level - 9 < 7U)
        {
            RayEvts = sp10;
        }
        if (num_level >= 16)
        {
            RayEvts = sp18;
        }
        break;
    case 2:
        if ((num_level >= 0xC) || (RayEvts = sp18, ((num_level >= 0xC))))
        {
            RayEvts = sp20;
        }
        break;
    case 3:
        if ((num_level >= 0xC) || (RayEvts = sp20, ((num_level >= 0xC))))
        {
            RayEvts = sp28;
        }
        break;
    default:
        RayEvts = sp28;
    }
}
#endif

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
