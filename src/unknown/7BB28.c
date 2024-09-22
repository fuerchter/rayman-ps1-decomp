#include "unknown/7BB28.h"

/* 7BB28 801A0328 -O2 -msoft-float */
void PS1_StopLevelMusic(void)
{
    s16 i = 0;

    if (PS1_CurTrack == 7 || PS1_SongIsPlaying(13))
    {
        while (PS1_SongIsPlaying(13) && i < 8 * 60)
        {
            VSync(0);
            i++;
        }
    }
    PS1_CanPlayDeathMusic = true;
    stop_cd();
    PS1_StopPlayingAllSnd();
    stop_all_snd();
    FUN_80168f40();
}

INCLUDE_ASM("asm/nonmatchings/unknown/7BB28", PS1_InitDisplay);

INCLUDE_ASM("asm/nonmatchings/unknown/7BB28", FUN_801a0750);

INCLUDE_ASM("asm/nonmatchings/unknown/7BB28", PS1_itoa);

INCLUDE_ASM("asm/nonmatchings/unknown/7BB28", FUN_801a07b0);

INCLUDE_ASM("asm/nonmatchings/unknown/7BB28", PS1_PlayMapIntro);
