#include "first_init.h"

/* matches, but */
/*INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019f8d0);*/

void FUN_8019f8d0(void)
{
    RECT fb_rect;
    s32 unk_1; /* TODO: remove */

    __builtin_memcpy(&fb_rect, &D_801CF0E0, sizeof(D_801CF0E0));
    ResetGraph(0);
    SetGraphDebug(0);
    SetDispMask(0);
    PS1_ClearScreen();
    SetDefDispEnv(&PS1_Displays[0].field0_0x0, 0, 0, 640, 480);
    SetDefDrawEnv(&PS1_Displays[0].drawing_environment, 0, 0, 640, 480);
    SetDefDispEnv(&PS1_Displays[1].field0_0x0, 0, 0, 640, 480);
    SetDefDrawEnv(&PS1_Displays[1].drawing_environment, 0, 0, 640, 480);
    unk_1 = 1;
    PS1_Displays[unk_1].field0_0x0.pad0 = 0;
    PS1_Displays[0].field0_0x0.pad0 = 0;
    PS1_Displays[unk_1].field0_0x0.isinter = true;
    PS1_Displays[0].field0_0x0.isinter = true;
    PS1_InitDisplay(&PS1_Displays[0]);
    PS1_InitDisplay(&PS1_Displays[unk_1]);
    ClearImage(&fb_rect, 0, 0, 0);
    PutDispEnv(&PS1_CurrentDisplay->field0_0x0);
    LOAD_SCREEN();
    playLevelMusic(0, 7);
    SetDispMask(1);
    SYNCHRO_LOOP(FUN_8019f848);
    while (FUN_80131db8() == false) {};
    DO_FADE_OUT();
}