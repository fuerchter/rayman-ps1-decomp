#include "continue.h"

#ifdef BSS_DEFS
u8 fin_dark;
#endif

/* 9424 8012DC24 -O2 -msoft-float */
s16 continue_fonction(void)
{
    s16 done = false;

    DO_FADE();
    CLRSCR();
    DISPLAY_FOND_CONTINUE();
    DISPLAY_CONTINUE_SPR();
    MAIN_CONTINUE_PRG();
    readinput();
    
    if (loop_timing == -1 || fin_continue)
        done = true;
    return done;
}

/* 949C 8012DC9C -O2 -msoft-float */
void DO_CONTINUE(void)
{
    if (status_bar.num_lives == 0 && fin_du_jeu == true && !fin_dark)
    {
        if (ray_mode == MODE_MORT_DE_RAYMAN_ON_MS || RayEvts.demi)
        {
            NewMs = true;
            __builtin_memcpy(&ray, &rms, sizeof(Obj));
            ray_mode = MODE_RAYMAN;
            RayEvts.demi = false;
        }
        LOAD_CONTINUE_SCREEN();
        start_cd_gameover();
        INIT_FADE_IN();
        INIT_CONTINUE();
        SYNCHRO_LOOP(continue_fonction);
        DO_FADE_OUT();
        FIN_CONTINUE_PRG();
        stop_cd();
        stop_all_snd();
    }
}
