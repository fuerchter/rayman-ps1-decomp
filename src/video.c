#include "video.h"

extern s16 PS1_VideoLength;

/* based on FUN_80132d74 */
typedef struct Unk_801cf5e0 {
    u8 * field0_0x0;
    u8 * field1_0x4;
    u8 * field2_0x8;
    RECT field3_0xc;
    u8 field4_0x14;
    u8 field5_0x15;
    u8 field6_0x16;
    u8 field7_0x17;
    s16 frame_count;
} Unk_801cf5e0;

extern Unk_801cf5e0 D_801CF5E0;

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
