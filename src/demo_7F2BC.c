#include "demo_7F2BC.h"

/* 7F2BC 801A3ABC -O1, -O2 */
/*? display_text(? *, ?, ?, ?, s32);*/                  /* extern */

void PS1_ShowDemoText() {
    display_text(&s_start_801cf118, 160, 180, 1, 144);
    display_text(&s_press_start_or_x_button_8012c468, 160, 203, 2, 10);
}

/* next: D_801F7FA8, then continue down demo/world_map again (short enums) */

/* 7F314 801A3B14 -O1 -O2 */
/*? DISPLAY_FOND3();
? DO_FADE();
? InitDemoJeu();
s32 StartButPressed();
s32 ValidButPressed();
? readinput();*/

u8 PS1_DemoLoop(void)
{
    u8 done;

    done = FALSE;
    DISPLAY_FOND3();
    DO_FADE();
    PS1_ShowDemoText();

    readinput();
    if (!fade && (ValidButPressed() || StartButPressed()))
        PS1_MENU_RETURN2 = TRUE;

    TempsDemo = TempsDemo + 1;
    if (TempsDemo >= RunTimeDemo && !fin_du_jeu && !PS1_MENU_RETURN2)
        InitDemoJeu();

    if (PS1_VideoState != VIDEOST_NOT_PLAYING)
        done = TRUE;
    if (fin_du_jeu || ModeDemo || PS1_MENU_RETURN2 || MENU_RETURN)
        done = TRUE;
    return done;
}

/* 7F450 801A3C50 -O1, -O2 */
/*? DO_FADE_OUT();
? PS1_LoadSplash();
? INIT_FADE_IN();
? PS1_PlayCDTrack_0_3();
? SYNCHRO_LOOP(? *);*/

void PS1_PlayDemo() {
    PS1_LoadSplash();
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    PS1_MENU_RETURN2 = FALSE;
    MENU_RETURN = FALSE;
    let_shadow = TRUE;
    SYNCHRO_LOOP(&PS1_DemoLoop);
    DO_FADE_OUT();
}