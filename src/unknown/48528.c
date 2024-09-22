#include "unknown/48528.h"

extern s16 PS1_VRAMDisplayXPos;
extern s16 PS1_VRAMDisplayYPos;

/* 48528 8016CD28 -O2 -msoft-float */
void PS1_DisplayVRAM(void)
{
    s32 l1_pressed;
    DISPENV prev_disp_env;

    TOUCHE(INPUT_READ);
    l1_pressed = 0;
    prev_disp_env = PS1_Displays[0].field0_0x0;
    while (l1_pressed == 0)
    {
        if (FUN_80133714(0))
            PS1_VRAMDisplayXPos -= 32;
        if (FUN_80133764(0))
            PS1_VRAMDisplayXPos += 32;
        if (FUN_801336c4(0))
            PS1_VRAMDisplayYPos -= 32;
        if (FUN_801337b4(0))
            PS1_VRAMDisplayYPos += 32;
        
        if (FUN_80134080(0))
            l1_pressed = 0xFF;
        
        if (PS1_VRAMDisplayYPos > 304)
            PS1_VRAMDisplayYPos = 280;
        if (PS1_VRAMDisplayYPos < 0)
            PS1_VRAMDisplayYPos = 0;
        if (PS1_VRAMDisplayXPos > 736)
            PS1_VRAMDisplayXPos = 712;
        if (PS1_VRAMDisplayXPos < 0)
            PS1_VRAMDisplayXPos = 0;
        
        SetDefDispEnv(
            &PS1_Displays[0].field0_0x0,
            PS1_VRAMDisplayXPos, PS1_VRAMDisplayYPos,
            320, 240
        );
        PS1_Displays[0].field0_0x0.pad0 =
        PS1_Displays[1].field0_0x0.pad0 = 1;
        PutDispEnv(&PS1_Displays[0].field0_0x0);
        TOUCHE(INPUT_READ);
    }

    while (FUN_80133fe0(0) == 0)
        TOUCHE(INPUT_READ);

    PS1_Displays[0].field0_0x0 = prev_disp_env;
}

INCLUDE_ASM("asm/nonmatchings/unknown/48528", test_allowed);

INCLUDE_ASM("asm/nonmatchings/unknown/48528", obj_jump);

INCLUDE_ASM("asm/nonmatchings/unknown/48528", DO_ONE_PINK_CMD);

INCLUDE_ASM("asm/nonmatchings/unknown/48528", FUN_8016d418);
