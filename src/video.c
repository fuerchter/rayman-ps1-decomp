#include "video.h"

/* E098 80132898 -O2 -msoft-float */
void PS1_PlayVideo(Video video)
{
    Display *new_disp;

    switch (video)
    {
    case VIDEO_PRES:
    case VIDEO_INTRO:
    case VIDEO_MAP_INTRO:
        PS1_VideoLength = 1806;
        break;
    case VIDEO_DEMO:
        PS1_VideoLength = 144;
        break;
    case VIDEO_WIN:
        PS1_VideoLength = 244;
        break;
    }
    PS1_LoadVideoTables();
    PS1_VideoPlayState = VIDEO_PRES;
    SsSetSerialVol(SS_SERIAL_A, 0, 0);
    PS1_PlayVideoFile(video);
    new_disp = &PS1_Displays[0];
    if (PS1_CurrentDisplay == &PS1_Displays[0])
        new_disp = &PS1_Displays[1];
    PS1_CurrentDisplay = new_disp;
    if (video == VIDEO_WIN)
        DO_FADE_OUT();
    D_801CF0CD = false;
}

INCLUDE_ASM("asm/nonmatchings/video", FUN_80132980);

INCLUDE_ASM("asm/nonmatchings/video", PS1_PlayVideoFile);

/* E574 80132D74 -O2 -msoft-float */
void PS1_InitVideoState(Unk_801cf5e0 *param_1)
{
    param_1->field6_0x16 = 0;
    param_1->frame_count = 1;
    param_1->field3_0xc.w = 16;
    param_1->field3_0xc.h = 200;
    param_1->field0_0x0 = (u8 *) D_801CEEDC;
    param_1->field1_0x4 = (u8 *) D_801CEEE0;
    param_1->field2_0x8 = (u8 *) D_801CEEE8;
    if (PS1_CurrentDisplay == PS1_Displays)
        param_1->field3_0xc.y = 20;
    else
        param_1->field3_0xc.y = 276;
    param_1->field3_0xc.x = 0;
    VSyncCallback(FUN_80132f8c);
}

/* E604 80132E04 -O2 -msoft-float */
void PS1_LoadVideoFile(CdlLOC *lba, u32 param_2)
{
    CdlLOC unk_1;

    CdIntToPos(CdPosToInt(lba) + (param_2 - 5) * 10, &unk_1);
    StSetRing(D_801CEEE4, 32);
    StSetStream(0, param_2, 0x0FFFFFFF, null, null);
    while (!CdControl(CdlSeekL, &unk_1.minute, null)){};
    CdSync(1, null);
    while (!CdRead2(CdlModeStream|CdlModeSpeed|CdlModeRT)){};
}

INCLUDE_ASM("asm/nonmatchings/video", PS1_ReadVideoFile);

INCLUDE_ASM("asm/nonmatchings/video", FUN_80132f8c);

void FUN_80133010(void) {}
