#include "demo_7F2BC.h"

/* 7F2BC 801A3ABC -O1, -O2 */
/*? display_text(? *, ?, ?, ?, s32);*/

void PS1_ShowDemoText(void)
{
    display_text(&s_start_801cf118, 160, 180, 1, 144);
    display_text("/press start or x button/", 160, 203, 2, 10);
}

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

    done = false;
    DISPLAY_FOND3();
    DO_FADE();
    PS1_ShowDemoText();

    readinput();
    if (!fade && (ValidButPressed() || StartButPressed()))
        PS1_MENU_RETURN2 = true;

    TempsDemo++;
    if (TempsDemo >= RunTimeDemo && !fin_du_jeu && !PS1_MENU_RETURN2)
        InitDemoJeu();

    if (PS1_VideoState != VIDEOST_NOT_PLAYING)
        done = true;
    if (fin_du_jeu || ModeDemo || PS1_MENU_RETURN2 || MENU_RETURN)
        done = true;
    return done;
}

/* 7F450 801A3C50 -O1, -O2 */
/*? DO_FADE_OUT();
? PS1_LoadImaSplash();
? INIT_FADE_IN();
? PS1_PlayCDTrack_0_3();
? SYNCHRO_LOOP(? *);*/

void PS1_PlayDemo(void)
{
    PS1_LoadImaSplash();
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    PS1_MENU_RETURN2 = false;
    MENU_RETURN = false;
    let_shadow = true;
    SYNCHRO_LOOP(&PS1_DemoLoop);
    DO_FADE_OUT();
}