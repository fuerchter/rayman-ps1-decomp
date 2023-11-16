#include "depart_dead.h"

/**/
extern u8 D_801E4C20;

/* 7B850 801A0050 -O2 -msoft-float */
/*? DO_VICTOIRE();
? FUN_8019fa94(?);
? FUN_8019fb84();
? INIT_MOTEUR_WORLD();
? PS1_PlaySnd(s16, ?);
? load_world(s16);*/

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/depart_dead", DEPART_WORLD);
#else
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
            PS1_PlaySnd(D_801C7D20[num_world_choice], 1);
            FUN_8019fb84();
            load_world(num_world_choice);
            INIT_MOTEUR_WORLD();
            D_801CF0DC = true;
        }
        else
            FUN_8019fa94(1);
    }

    __asm__("nop");
}
#endif

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
        if (D_801CF0DC)
        {
            DO_FADE_OUT();
            D_801CF0DC = false;
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
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/depart_dead", FIN_DEAD_LOOP);
#else
void FIN_DEAD_LOOP(void)
{
    s16 i;

    __asm__("nop");

    if (fin_du_jeu)
    {
        for (i = 0; i < 24; i++)
            t_world_info[i].nb_cages = 0;
        D_801CEDFC = 1;
    }
}
#endif