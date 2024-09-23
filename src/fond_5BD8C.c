#include "fond_5BD8C.h"

INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", FUN_8018058c);

extern u8 D_801E4B58;
extern u8 *D_801F4380; /* still don't know where to put this */

/* 5BF84 80180784 -O2 -msoft-float */
void DISPLAY_FOND3(void)
{
    s16 y = (240 - plan2_height) >> 1;
    s16 x = (320 - plan2_width) >> 1;    
    
    if (D_801E4B58 == true)
        y = 0;
    FUN_8018058c((u32 *) D_801F4380, 0, 0, x, y, plan2_height, plan2_width);
}

INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", FUN_80180804);

INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", FUN_801809fc);

INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", DISPLAY_FOND_CONTINUE);

INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", DISPLAY_FOND_SELECT);
