#include "unknown/A3B0.h"

const u8 s_game_pausedpress_start_to_p_80125000[] = "/game paused.../press start to play/";

/* A3B0 8012EBB0 -O2 -msoft-float */
s16 loader_anim_prg(void)
{
    s16 done;

    readinput();
    if (joy_done == 1 && fade == 0)
        joy_done = 0;
    
    if ((ValidButPressed() || StartButPressed()) && joy_done == 0)
        PROC_EXIT = true;
    
    horloges();
    DO_FADE();
    CLRSCR();
    display2(&bigray);
    DO_LOADER_ANIM();

    done = PROC_EXIT && fade == 0;
    return done;
}

/* A494 8012EC94 -O2 -msoft-float */
void DO_GROS_RAYMAN(void)
{
    LOAD_BIG_RAYMAN();
    joy_done = 1;
    start_cd_gros_rayman();
    INIT_FADE_IN();
    INIT_LOADER_ANIM();
    SYNCHRO_LOOP(loader_anim_prg);
}

void FUN_8012ece8(void) {}

/* A4F0 8012ECF0 -O2 -msoft-float */
void FUN_8012ecf0(void)
{
    if (PS1_InitPAD())
        readinput();
    if (PS1_InitPAD() && PS1_IsInputtingCheatCode(0))
        DO_GROS_RAYMAN();
    PROC_EXIT = false;
    LOAD_ALL_FIX();
    FUN_8012ece8();
}

/* A560 8012ED60 -O2 -msoft-float */
void DO_AFFICHE_PAUSE(void)
{
    if (!PS1_IsInputtingCheatCode(0))
    {
        display_text(s_game_pausedpress_start_to_p_80125000, 160, 120, 2, 224);
    }
}

INCLUDE_ASM("asm/nonmatchings/unknown/A3B0", FUN_8012eda4);
