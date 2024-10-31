#include "depart_dead.h"

/* 7B850 801A0050 -O2 -msoft-float */
void DEPART_WORLD(void)
{
    if (num_world_choice != num_world)
    {
        num_level = 0;
        new_world = true;
        new_level = true;
    }
    else
    {
        new_world = false;
        new_level = true;
    }

    if (You_Win == true && num_world_choice == 6)
    {
        DO_VICTOIRE();
        return;
    }
    if (!fin_du_jeu)
    {
        if (new_world)
        {
            D_801CEDFC = 1;
            PS1_PlaySnd(PS1_NewWorldMusic[num_world_choice], 1);
            FUN_8019fb84();
            load_world(num_world_choice);
            INIT_MOTEUR_WORLD();
            PS1_ShouldFadeOutWorldIntro = true;
        }
        else
            FUN_8019fa94(1);
    }
}

/* 7B978 801A0178 -O2 -msoft-float */
/*? DO_FADE_OUT();
? LOAD_FND(s16);
? LOAD_VIGNET_GAME();
? PS1_OnPauseOff();
? load_level();*/

void DEPART_LEVEL(void)
{
    if (num_level_choice != num_level || PS1_HasLoadedFont)
    {
        num_world = num_world_choice;
        num_level = num_level_choice;
        new_world = false;
        new_level = true;
    }
    else
    {
        new_world = false;
        new_level = false;
    }
    if (!fin_du_jeu && new_level)
    {
        D_801E4C20 = 1;
        LOAD_FND();
        load_level();
        LOAD_VIGNET_GAME();
        if (PS1_ShouldFadeOutWorldIntro)
        {
            DO_FADE_OUT();
            PS1_ShouldFadeOutWorldIntro = false;
        }
    }
    in_pause = false;
    PS1_OnPauseOff();
}

/* 7BA7C 801A027C -O2 -msoft-float */
/*? FUN_80168f38(s16);
? playLevelMusic(s16, s16);*/

void DEPART_DEAD_LOOP(void)
{
    playLevelMusic(num_world, num_level);
    FUN_80168f38(num_world);
}

/* 7BABC 801A02BC -O2 -msoft-float */
void FIN_DEAD_LOOP(void)
{
    s16 i;

    if (fin_du_jeu)
    {
        for (i = 0; i < (s16) LEN(t_world_info); i++)
            t_world_info[i].nb_cages = 0;
        D_801CEDFC = 1;
    }
}