#include "victoire.h"

/* 9C90 8012E490 -O2 -msoft-float */
void DISPLAY_TXT_CREDITS(void)
{
    u32 i;
    
    for (i = first_credit; i <= last_credit; i++)
        display_text(
            credits[i].text,
            credits[i].x_pos, credits[i].y_pos,
            credits[i].font,
            credits[i].color
        );
}

/* 9D4C 8012E54C -O2 -msoft-float */
s16 display_credits_prg(void)
{
    s16 done;
    u8 prev_exit;

    readinput();
    DO_FADE();
    DO_CREDITS();
    DISPLAY_FOND3();
    DISPLAY_TXT_CREDITS();
    prev_exit = PROC_EXIT;
    PROC_EXIT = false;

    if (ValidButPressed() || SelectButPressed())
    {
        PROC_EXIT = true;
        display_Vignet = 5;
    }

    done = false;
    if (PROC_EXIT || prev_exit)
        done = true;
    return done;
}

/* 9DF4 8012E5F4 -O2 -msoft-float */
void DISPLAY_CREDITS(void)
{
    start_cd_credits();
    INIT_CREDITS();
    let_shadow = false;
    while (display_Vignet < 6)
    {
        LOAD_CREDITS_VIGNET();
        if (display_Vignet == 0)
            FUN_80131c94();
        INIT_FADE_IN();
        SYNCHRO_LOOP(display_credits_prg);
        PROC_EXIT = false;
        display_Vignet++;
    }
    INIT_FADE_IN();
}

INCLUDE_ASM("asm/nonmatchings/victoire", DISPLAY_PROTOON_BACK);

INCLUDE_ASM("asm/nonmatchings/victoire", DO_VICTOIRE);
