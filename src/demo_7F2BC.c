#include "common.h"
#include "menu/menu_7EEE4.h"
#include "menu/menu_7F4B4.h"
#include "text_18118.h"
#include "demo_7F2BC.h"

/* 7F2BC 801A3ABC */
//? display_text(? *, ?, ?, ?, s32);                  /* extern */

void PS1_ShowDemoText() {
    display_text(&s_start_801cf118, 160, 180, 1, 144);
    display_text(&s_press_start_or_x_button_8012c468, 160, 203, 2, 10);
}

INCLUDE_ASM("asm/nonmatchings/demo_7F2BC", PS1_DemoLoop);

/* 7F450 801A3C50 */
//? DO_FADE_OUT();                                    /* extern */
//? PS1_LoadSplash();                                   /* extern */
//? INIT_FADE_IN();                                   /* extern */
//? PS1_PlayCDTrack_0_3();                            /* extern */
//? SYNCHRO_LOOP(? *);                                /* extern */

void PS1_PlayDemo(void) {
    PS1_LoadSplash();
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    PS1_MENU_RETURN2 = 0;
    MENU_RETURN = 0;
    let_shadow = 1;
    SYNCHRO_LOOP(&PS1_DemoLoop);
    DO_FADE_OUT();
}