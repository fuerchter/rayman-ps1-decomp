#include "demo_9FD4.h"

/* matches, but do{}while(0); */
/* 9FD4 8012E7D4 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/demo_9FD4", InitDemoJeu);*/

/*? DO_FADE_OUT();
? INIT_HORLOGES(s16, s32, u16, u16);
? POINTEUR_BOUTONS_OPTIONS_BIS(u8 *, u8 *, OptionsJeu *, OptionsJeu *);
? PS1_PlayVideo(?);*/

void InitDemoJeu(void)
{
    s32 temp_a0_2;
    u16 temp_a2;
    u16 temp_a3;
    s16 *new_var;
    
    RaymanEvents new_var4;

    if (NumDemo == 6)
    {
        NumDemo = 0;
        PS1_VideoState = VIDEOST_PLAYING;
        ModeDemo = 0;
        TempsDemo = 0;
        DO_FADE_OUT();
        PS1_PlayVideo(VIDEO_INTRO);
        return;
    }
    PS1_VideoState = VIDEOST_NOT_PLAYING;
    ModeDemo = 1;
    TempsDemo = 0;
    do { SauveRayEvtsDemo = RayEvts; } while (0);
    RayEvts.poing = true;
    RayEvts.hang = true;
    RayEvts.helico = true;
    RayEvts.super_helico = true;
    RayEvts.grap = true;
    RayEvts.run = true;
    RayEvts.demi = false;
    RayEvts.luciole = false;
    RayEvts.force_run = 0;
    RayEvts.reverse = 0;
    /*RayEvts.flags0 = FLG(RAYEVTS0_POING)|FLG(RAYEVTS0_HANG)|FLG(RAYEVTS0_HELICO)|FLG(RAYEVTS0_SUPER_HELICO)|FLG(RAYEVTS0_GRAP);
    RayEvts.flags1 |= FLG(RAYEVTS1_RUN);
    RayEvts.flags1 &= FLG(RAYEVTS1_RUN)|FLG(RAYEVTS1_UNUSED_DEATH);*/
    __builtin_memcpy(&options_jeu_save, &options_jeu, sizeof(OptionsJeu));
    options_jeu.Jump = 1;
    options_jeu.Fist = 0;
    options_jeu.Action = 3;
    options_jeu.field6_0x14 = 3;
    options_jeu.field11_0x1e = 0;
    options_jeu.field14_0x24 = 0;
    options_jeu.field12_0x20 = 0;
    options_jeu.field13_0x22 = 0;
    POINTEUR_BOUTONS_OPTIONS_BIS();
    new_var = &DemoRecordWolrd[NumDemo];
    finBosslevel[1] = finBosslevel[1] | 10;
    temp_a3 = (u16) (*new_var);
    temp_a2 = (u16) DemoRecordMap[NumDemo];
    new_world = 1;
    new_level = 1;
    num_world = 0;
    num_level = 0;
    ray.hit_points = 2;
    status_bar.max_hp = 2;
    status_bar.num_lives = 3;
    record.is_playing = true;
    record.current_offset = 0;
    temp_a0_2 = DemoRecordSize[NumDemo];
    record.data = DemoRecord[NumDemo];
    num_world_choice = temp_a3;
    num_level_choice = temp_a2;
    record.length = temp_a0_2;
    INIT_HORLOGES();
}