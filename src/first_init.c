#include "first_init.h"

const u8 s_loading_8012c368[] = "/loading.../";

extern u8 D_801CF438;
extern u8 D_801CF440;
extern RECT D_801CF0E0;
extern RECT D_801CF0E8;

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

/* 7B244 8019FA44 -O2 -msoft-float */
u8 PS1_OldLoadingScreen(void)
{
    DO_FADE();
    DISPLAY_FOND3();
    display_text(s_loading_8012c368, 160, 215, 2, 1);
    return fade == 0;
}

/* 7B294 8019FA94 -O2 -msoft-float */
void FUN_8019fa94(u8 param_1)
{
    RECT dest;

    __builtin_memcpy(&dest, &D_801CF0E8, sizeof(D_801CF0E8));
    StoreImage(&dest, D_801C438C[num_world - 1]);
    MoveImage(&PS1_CurrentDisplay->field0_0x0.disp, dest.x, dest.y);
    DrawSync(0);
    if (param_1)
    {
        FUN_8012d2b0(0);
        SYNCHRO_LOOP(PS1_RollUpRToL);
    }
    LoadImage(&dest, D_801C438C[num_world - 1]);
    DrawSync(0);
}

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fb84);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fd40);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fda0);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fdd0);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fe8c);

INCLUDE_ASM("asm/nonmatchings/first_init", PS1_SetLevelto_4_1);

INCLUDE_ASM("asm/nonmatchings/first_init", FIRST_INIT);
