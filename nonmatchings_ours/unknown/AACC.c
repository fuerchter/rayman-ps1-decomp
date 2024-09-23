#include "unknown/AACC.h"

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