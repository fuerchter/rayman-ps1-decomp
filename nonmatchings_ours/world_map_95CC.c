#include "world_map_95CC.h"

/*INCLUDE_ASM("asm/nonmatchings/world_map_95CC", DO_WORLD_MAP);*/

/* 98D4 8012E0D4 */
/* single instruction is incorrect */
/*? DETER_WORLD_AND_LEVEL();
? FIN_WORLD_CHOICE();
? FUN_8019e770();
? INIT_CHEMIN();
? INIT_FADE_IN();
? INIT_FADE_OUT();
? INIT_RAY(s16);
? PS1_PlayCDTrack_0_3();
? PlaySnd_old(?, u16, u16);
? SYNCHRO_LOOP(? *);
? readinput();
? stop_cd();*/
extern u8 ModeDemo;
extern u8 PROC_EXIT;
/*extern ? WORLD_CHOICE;*/
extern s8 fin_du_jeu;
extern s8 menuEtape;
extern s16 new_level;
extern u16 num_level;
extern u16 num_level_choice;
extern u16 num_world;
extern s16 num_world_choice;
extern u8 world_index;

void DO_WORLD_MAP(void)
{
    u16 temp_a1;
    u16 nlev;

    if (ModeDemo == 0)
    {
        FUN_8019e770();
    }
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    INIT_RAY(new_level);
    INIT_CHEMIN();
    if (ModeDemo == 0)
    {
        readinput();
        if (ModeDemo == 0)
        {
            SYNCHRO_LOOP(&WORLD_CHOICE);
        }
    }
    if (PROC_EXIT != 0)
    {
        world_index = num_world_choice;
        temp_a1 = num_world;
        fin_du_jeu = 1;
        menuEtape = 4;
        num_world = 0;
        num_world_choice = temp_a1;
        nlev = num_level;
        num_level_choice = nlev;
        PlaySnd_old(0x4D, temp_a1, nlev);
    }
    else
    {
        DETER_WORLD_AND_LEVEL();
        if (ModeDemo == 0)
        {
            PlaySnd_old(0x45);
        }
    }
    INIT_FADE_OUT();
    FIN_WORLD_CHOICE();
    stop_cd();
}