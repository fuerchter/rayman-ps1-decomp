#include "demo_9FD4.h"

/* reg swap, missing addiu */
/* 9FD4 8012E7D4 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/demo_9FD4", InitDemoJeu);*/

/*? DO_FADE_OUT();
? INIT_HORLOGES(s16, s32, u16, u16);
? POINTEUR_BOUTONS_OPTIONS_BIS(u8 *, u8 *, OptionsJeu *, OptionsJeu *);
? PS1_PlayVideo(?);*/
extern u8 DemoRecord[6][300];
extern s16 DemoRecordMap[6];
extern s16 DemoRecordSize[6];
extern s16 DemoRecordWorld[16];
extern s16 NumDemo;
extern VideoState PS1_VideoState;
extern RaymanEvents RayEvts;
extern RaymanEvents SauveRayEvtsDemo;
extern s32 TempsDemo;
extern s16 new_level;
extern s16 new_world;
extern s16 num_level;
extern u16 num_level_choice;
extern s16 num_world;
extern u16 num_world_choice;
extern OptionsJeu options_jeu;
extern OptionsJeu options_jeu_save;
extern u8 finBosslevel[2];

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
    SauveRayEvtsDemo = RayEvts;
    temp_a2 = RAYEVTS0_POING|RAYEVTS0_HANG|RAYEVTS0_HELICO|RAYEVTS0_SUPER_HELICO|RAYEVTS0_GRAP;
    RayEvts.flags0 = temp_a2;
    RayEvts.flags1 |= RAYEVTS1_RUN;
    RayEvts.flags1 &= RAYEVTS1_RUN|RAYEVTS1_UNUSED_DEATH;
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
    record.is_playing = TRUE;
    record.current_offset = 0;
    temp_a0_2 = DemoRecordSize[NumDemo];
    record.data = DemoRecord[NumDemo];
    num_world_choice = temp_a3;
    num_level_choice = temp_a2;
    record.length = temp_a0_2;
    INIT_HORLOGES();
}