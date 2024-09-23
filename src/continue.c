#include "continue.h"

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

INCLUDE_ASM("asm/nonmatchings/continue", DO_CONTINUE);
