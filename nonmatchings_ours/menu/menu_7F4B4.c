#include "menu/menu_7F4B4.h"

/* missing_addiu, how to insert text_to_display in positiony switch? */
/* 7FAE8 801A42E8 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_DisplayCardOrPassword);*/

/*? display_box_text(TextToDisplay *);
? display_text(? *, ?, ?, ?, s32);*/
extern u8 D_801E4F97;
extern s8 D_801E4FD7;
extern s8 D_801E5017;
extern s8 let_shadow;

void PS1_DisplayCardOrPassword(void)
{
    s8 *var_a0;

    if (compteur < max_compteur)
    {
        if (button_released == 0)
            compteur++;
        else
            compteur = 0;
    }
    else if (button_released == 0)
        compteur = delai_repetition + 1;
    else
        compteur = 0;
    
    if (positiony > 0)
    {
        text_to_display[positiony].color = 0x90;
        display_box_text(&text_to_display[positiony]);
    }
    let_shadow = TRUE;
    
    switch (positiony)
    {
    case 1:
        var_a0 = &D_801E5017;
        *var_a0 = 0x0A;
        display_box_text((TextToDisplay *) (var_a0 - 0x3F));
        break;
    case 2:
        var_a0 = &D_801E4FD7;
        *var_a0 = 0x0A;
        display_box_text((TextToDisplay *) (var_a0 - 0x3F));
        break;
    }
    display_text("/x : validate/", 160, 208, 2, 10);
    display_text("/select : return/", 160, 223, 2, 10);
}