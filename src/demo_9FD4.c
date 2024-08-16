#include "demo_9FD4.h"

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
    record.is_playing = false;
    record.current_offset = 0;
    record.length = 0;
    record.data = 0;
    new_world = false;
    new_level = false;
    num_world = 0;
    num_level = 0;
    num_world_choice = 0;
    num_level_choice = 0;
    finBosslevel[1] &= ~(FLG(1)|FLG(3));
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