#include "first_init.h"

const u8 s_loading_8012c368[] = "/loading.../";

extern u8 D_801CF438;
extern u8 D_801CF440;
extern RECT D_801CF0E0;
extern RECT D_801CF0E8;
extern u32 *D_801F4380;

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
    RECT fb_rect;

    __builtin_memcpy(&fb_rect, &D_801CF0E8, sizeof(D_801CF0E8));
    StoreImage(&fb_rect, D_801C438C[num_world - 1]);
    MoveImage(&PS1_CurrentDisplay->field0_0x0.disp, fb_rect.x, fb_rect.y);
    DrawSync(0);
    if (param_1)
    {
        FUN_8012d2b0(0);
        SYNCHRO_LOOP(PS1_RollUpRToL);
    }
    LoadImage(&fb_rect, D_801C438C[num_world - 1]);
    DrawSync(0);
}

/* 7B384 8019FB84 -O2 -msoft-float */
void FUN_8019fb84(void)
{
    u32 *unk_1;
    RECT fb_rect_1;
    RECT fb_rect_2;

    unk_1 = D_801F4380;
    __builtin_memcpy(&fb_rect_1, &D_801CF0E8, sizeof(D_801CF0E8));
    D_801F4380 = (u32 *)((u8 *)D_801C438C[num_world - 1] + 0x45000);
    FUN_8019df1c(num_world_choice);
    StoreImage(&fb_rect_1, D_801C438C[num_world - 1]);
    MoveImage(&PS1_CurrentDisplay->field0_0x0.disp, fb_rect_1.x, fb_rect_1.y);
    DrawSync(0);
    FUN_8012d2b0(0);
    SYNCHRO_LOOP(PS1_RollUpRToL);
    ClearImage(&fb_rect_1, 0, 0, 0);
    fb_rect_2.x = (320 - plan2_width) / 2 + 704;
    fb_rect_2.y = (240 - plan2_height) / 2;
    fb_rect_2.w = plan2_width;
    fb_rect_2.h = plan2_height;
    LoadImage(&fb_rect_2, D_801F4380);
    DrawSync(0);
    FUN_8012d2b0(100);
    SYNCHRO_LOOP(PS1_RollUpLToR);
    LoadImage(&fb_rect_1, D_801C438C[num_world - 1]);
    DrawSync(0);
    D_801F4380 = unk_1;
}

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fd40);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fda0);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fdd0);

INCLUDE_ASM("asm/nonmatchings/first_init", FUN_8019fe8c);

INCLUDE_ASM("asm/nonmatchings/first_init", PS1_SetLevelto_4_1);

INCLUDE_ASM("asm/nonmatchings/first_init", FIRST_INIT);
