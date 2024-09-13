#include "video.h"

extern s16 PS1_VideoLength;

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
    PS1_VideoState = VIDEO_PRES;
    SsSetSerialVol(SS_SERIAL_A, 0, 0);
    PS1_PlayVideoFile(video);
    new_disp = PS1_Displays;
    if (PS1_CurrentDisplay == PS1_Displays)
        new_disp = &PS1_Displays[1];
    PS1_CurrentDisplay = new_disp;
    if (video == VIDEO_WIN)
        DO_FADE_OUT();
    D_801CF0CD = false;
}

INCLUDE_ASM("asm/nonmatchings/video", FUN_80132980);

INCLUDE_ASM("asm/nonmatchings/video", PS1_PlayVideoFile);

INCLUDE_ASM("asm/nonmatchings/video", FUN_80132d74);

INCLUDE_ASM("asm/nonmatchings/video", FUN_80132e04);

INCLUDE_ASM("asm/nonmatchings/video", FUN_80132ea0);

INCLUDE_ASM("asm/nonmatchings/video", FUN_80132f8c);

void FUN_80133010(void) {}
