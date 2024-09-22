#include "cam_scroll_29B5C.h"

extern s16 expsin2[50];

/* 29B5C 8014E35C -O2 -msoft-float */
s16 frapsol(s16 param_1)
{
    return ashr16(expsin[param_1], 7);
}

/* 29B98 8014E398 -O2 -msoft-float */
void DO_SCREEN_TREMBLE(void)
{
    s16 unk_1;

    if (screen_trembling != 0)
    {
        unk_1 = frapsol(screen_trembling);
        screen_trembling++;
        if (unk_1 == 0xFF)
        {
            unk_1 = 0;
            screen_trembling = 0;
        }
        ymap += unk_1;
    }
}

/* 29C14 8014E414 -O2 -msoft-float */
void DO_SCREEN_TREMBLE3(void)
{
    s16 unk_1 = expsin2[screen_trembling3];
    
    if (unk_1 != 0xFF)
    {
        screen_trembling3++;
        ymap += unk_1;
    }
    else
        screen_trembling3 = 0;
}

/* 29C7C 8014E47C -O2 -msoft-float */
void DO_SCREEN_TREMBLE2(void)
{
    s16 unk_1 = expsin2[screen_trembling2];
    
    if (unk_1 != 0xFF)
    {
        screen_trembling2++;
        xmap += unk_1;
    }
    else
        screen_trembling2 = 0;
}

INCLUDE_ASM("asm/nonmatchings/cam_scroll_29B5C", DO_SCROLL);
