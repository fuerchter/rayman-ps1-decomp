#include "demo_9FD4.h"

#ifdef BSS_DEFS
Record record;

u8 ModeDemo;
u16 RunTimeDemo;
s16 NumDemo;
#endif

/* 9FD4 8012E7D4 -O2 -msoft-float */
void InitDemoJeu(void)
{
    if (NumDemo == 6)
    {
        NumDemo = 0;
        PS1_VideoPlayState = VIDEOST_PLAYING;
        ModeDemo = 0;
        TempsDemo = 0;
        DO_FADE_OUT();
        PS1_PlayVideo(VIDEO_INTRO);
        return;
    }

    PS1_VideoPlayState = VIDEOST_NOT_PLAYING;
    ModeDemo = 1;
    TempsDemo = 0;

    SauveRayEvtsDemo = RayEvts;
    RayEvts.poing = true;
    RayEvts.hang = true;
    RayEvts.helico = true;
    RayEvts.super_helico = true;
    RayEvts.handstand_dash = false;
    RayEvts.handstand = false;
    RayEvts.grain = false;
    RayEvts.grap = true;
    RayEvts.run = true;
    RayEvts.demi = false;
    RayEvts.luciole = false;
    RayEvts.force_run = 0;
    RayEvts.reverse = 0;

    __builtin_memcpy(&options_jeu_save, &options_jeu, sizeof(OptionsJeu));
    options_jeu.Jump = 1;
    options_jeu.Fist = 0;
    options_jeu.Action = 3;
    options_jeu.field6_0x14 = 3;
    options_jeu.field11_0x1e = 0;
    options_jeu.field12_0x20 = 0;
    options_jeu.field14_0x24 = 0;
    options_jeu.field13_0x22 = 0;
    POINTEUR_BOUTONS_OPTIONS_BIS();
    finBosslevel.helped_joe_1 = true;
    finBosslevel.helped_musician = true;
    num_world_choice = DemoRecordWolrd[NumDemo];
    num_level_choice = DemoRecordMap[NumDemo];
    new_world = true;
    new_level = true;
    num_world = 0;
    num_level = 0;
    ray.hit_points = 2;
    status_bar.max_hp = 2;
    status_bar.num_lives = 3;
    record.is_playing = true;
    record.current_offset = 0;
    record.length = DemoRecordSize[NumDemo];
    record.data = DemoRecord[NumDemo];
    INIT_HORLOGES();
}

/* A228 8012EA28 -O2 */
void FinDemoJeu(void)
{
    if (record.repeat_index == record.repeat_length)
        RunTimeDemo = 180;
    else
        RunTimeDemo = 1800;
    ModeDemo = 0;
    TempsDemo = 0;
    INIT_RAY(true);
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
    finBosslevel.helped_joe_1 = false;
    finBosslevel.helped_musician = false;
    __builtin_memcpy(&options_jeu, &options_jeu_save, sizeof(OptionsJeu));
    POINTEUR_BOUTONS_OPTIONS_BIS();
    NumDemo++;
    if (record.repeat_index == record.repeat_length)
    {
        DO_FADE_OUT();
        PS1_PlayVideo(VIDEO_DEMO);
        if (PS1_VideoPlayState == VIDEOST_SKIPPED)
            RunTimeDemo = 1800;
    }
}