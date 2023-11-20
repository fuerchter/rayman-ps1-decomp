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

/* matches, but goto */
/*INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_InputCardOrPassword);*/

void PS1_InputCardOrPassword(void)
{
    s16 valid_pressed = ValidButPressed();
    s16 select_pressed = SelectButPressed();

    if (!valid_pressed)
    {
        if (!select_pressed)
        {
            if (PS1_MENU_RETURN2 == 0)
            {
                if (upjoy(0) && !leftjoy(0) && !rightjoy(0))
                {
                    if (
                        button_released != 0 ||
                        (compteur > delai_repetition && (compteur % repetition == 0))
                    )
                    {
                        if (positiony > 1)
                            positiony--;
                        else
                            positiony = 2;
                        TempsDemo = 0;
                        PlaySnd_old(68);
                    }
                }
                if (downjoy(0) && !leftjoy(0) && !rightjoy(0))
                {
                    if(
                        button_released != 0 ||
                        (compteur > delai_repetition && (compteur % repetition == 0))
                    )
                    {
                        if (positiony > 1)
                            positiony = 1;
                        else
                            positiony++;
                        TempsDemo = 0;
                        PlaySnd_old(68);
                    }
                }
            }
        }
        /*
        ???
        this is closest to the assembly
        flipping + else around positiony checks doesn't let me remove this either
        */
        if (!valid_pressed)
            goto block_28;
    }
    if (positiony == 1)
    {
        TempsDemo = 0;
        PS1_SaveMode = 1;
        button_released = 0;
        PS1_MENU_RETURN2 = true;
        PlaySnd_old(69);
    }
    if (positiony == 2)
    {
        TempsDemo = 0;
        PS1_SaveMode = 2;
        button_released = 0;
        PS1_MENU_RETURN2 = true;
        PlaySnd_old(69);
    }
block_28:
    if (select_pressed)
    {
        MENU_RETURN = true;
        PlaySnd_old(77);
    }
    if (menuEtape == 2 && StartButPressed())
    {
        PS1_MENU_RETURN2 = true;
        PS1_SaveMode = 2;
    }
    if (
      ((downjoy(0) || upjoy(0) || rightjoy(0) || leftjoy(0)) && !PS1_MENU_RETURN2) ||
      valid_pressed || select_pressed
    )
        button_released = 0;
    else
    {
        button_released = 1;
        compteur = 0;
    }
}