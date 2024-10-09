#include "fond_5BD8C.h"
#include "rayconst.h"

extern u8 D_801E4B58;
extern u8 *D_801F4380; /* still don't know where to put this */

INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", FUN_8018058c);

/* 5BF84 80180784 -O2 -msoft-float */
void DISPLAY_FOND3(void)
{
    s16 y = (SCREEN_HEIGHT - plan2_height) >> 1;
    s16 x = (SCREEN_WIDTH - plan2_width) >> 1;
    
    if (D_801E4B58 == true)
        y = 0;
    FUN_8018058c((u32 *) D_801F4380, 0, 0, x, y, plan2_height, plan2_width);
}

INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", FUN_80180804);

/* 5C1FC 801809FC -O2 -msoft-float */
void FUN_801809fc(void)
{
    s16 y = (SCREEN_HEIGHT * 2 - plan2_height) >> 1;
    s16 x = (SCREEN_WIDTH * 2 - plan2_width) >> 1;

    if (D_801E4B58 == true)
        y = 0;
    FUN_80180804((u32 *) D_801F4380, 0, 0, x, y, plan2_height, plan2_width);
}

/* 5C27C 80180A7C -O2 -msoft-float */
void DISPLAY_FOND_CONTINUE(void)
{
    DISPLAY_FOND3();
}

/* 5C29C 80180A9C -O2 -msoft-float */
void DISPLAY_FOND_SELECT(void)
{
    CLRSCR();
}
