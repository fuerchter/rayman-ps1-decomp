#include "menu/menu_82008.h"

/*INCLUDE_ASM("asm/nonmatchings/menu/menu_82008", FUN_801a6808);*/
/*
INIT_OPTIONS_CHOICE on android?

generates division checks if:
-function arg is involved
-global is involved
-uninitialized local var is involved

still to see more

PS1_display_y2 is vert spacing on options screen
*/

void FUN_801a6808(void)
{
    s32 test_1;
    s32 temp_lo;
    /*s32 test_4[2];*/
    volatile long long test_4;
    s32 test_3 = 0x64;

    if (test_4)
    {
        test_1 = 0x5a;
    }
    position = 7;
    temp_lo = (test_3 - test_1) / position;
    PS1_Music_Max = 0x0014;
    PS1_Soundfx_Max = 0x0014;
    D_801F5498 = 6;
    ecart_barre = 4;
    button_released = 1;
    compteur = 0;
    max_compteur = 0x0064;
    delai_repetition = 0x000C;
    repetition = 6;
    delai_stereo = 8;
    delai_barre = 3;
    D_801D7AA0 = 0x0037;
    basex = 0x0032;
    debut_titre = 0x001D;
    test_3 = test_3 + 0x3b;
    PS1_display_y1 = test_3;
    PS1_display_y2 = temp_lo;
    PROC_EXIT = 0;
    D_801D7A50 = 0;
    PS1_Settings[0] = options_jeu.Jump;
    PS1_Settings[1] = options_jeu.Fist;
    PS1_Settings[2] = options_jeu.Action;
    PS1_Settings[3] = options_jeu.Music;
    PS1_Settings[4] = options_jeu.Soundfx;
    PS1_Settings[5] = options_jeu.StereoEnabled;
    debut_sortie = temp_lo + 0x33;
}