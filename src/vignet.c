#include "vignet.h"

/* 9A14 8012E214 -O2 -msoft-float */
void DISPLAY_TXT_VIGNET(void)
{
    u32 i;

    for (
        i = new_txt_fee;
        text_to_display[i].text[0] != null && (i <= new_txt_fee + 1);
        i++
    )
        display_box_text(&text_to_display[i]);
}

INCLUDE_ASM("asm/nonmatchings/vignet", display_vignet_prg);

INCLUDE_ASM("asm/nonmatchings/vignet", DISPLAY_GAME_VIGNET);
