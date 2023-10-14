#include "demo_9FD4.h"

/* 9FD4 8012E7D4 -O2 */
INCLUDE_ASM("asm/nonmatchings/demo_9FD4", InitDemoJeu);

/* A228 8012EA28 -O2 */
/*? DO_FADE_OUT(s32);
? INIT_RAY(?);
? POINTEUR_BOUTONS_OPTIONS_BIS(u8 *, u8 *, OptionsJeu *, OptionsJeu *);
? PS1_PlayVideo(?);*/

void FinDemoJeu(void)
{
    if (record.repeat_index == record.repeat_length)
        RunTimeDemo = 180;
    else
        RunTimeDemo = 1800;
    ModeDemo = 0;
    TempsDemo = 0;
    INIT_RAY(1);
    RayEvts = SauveRayEvtsDemo;
    record.is_playing = FALSE;
    record.current_offset = 0;
    record.length = 0;
    record.data = 0;
    new_world = 0;
    new_level = 0;
    num_world = 0;
    num_level = 0;
    num_world_choice = 0;
    num_level_choice = 0;
    finBosslevel[1] &= 0xF5;
    __builtin_memcpy(&options_jeu, &options_jeu_save, sizeof(OptionsJeu));
    POINTEUR_BOUTONS_OPTIONS_BIS();
    NumDemo++;
    if (record.repeat_index == record.repeat_length)
    {
        DO_FADE_OUT();
        PS1_PlayVideo(VIDEO_DEMO);
        if (PS1_VideoState == VIDEOST_SKIPPED)
            RunTimeDemo = 1800;
    }
}