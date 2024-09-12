#include "first_init.h"

const u8 s_loading_8012c368[] = "/loading.../";

extern u8 D_801CF438;
extern u8 D_801CF440;
extern RECT D_801CF0E0;

void PS1_InitDisplay(Display *display);

/* 7B048 8019F848 -O2 -msoft-float */
s16 FUN_8019f848(void)
{
    D_801CF438++;
    FUN_801809fc();
    return (D_801CF438 <= 60) ^ 1;
}

/* 7B08C 8019F88C -O2 -msoft-float */
s16 FUN_8019f88c(void)
{
    D_801CF440++;
    FUN_801809fc();
    return (D_801CF440 <= 60) ^ 1;
}

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019f8d0);

INCLUDE_ASM("asm/nonmatchings/first_init", PS1_OldLoadingScreen);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fa94);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fb84);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fd40);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fda0);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fdd0);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fe8c);

INCLUDE_ASM("asm/nonmatchings/first_init", PS1_SetLevelto_4_1);

INCLUDE_ASM("asm/nonmatchings/first_init", FIRST_INIT);
