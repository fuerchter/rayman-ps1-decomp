#include "menu/menu_7F4B4.h"

/*
matches, but goto

!valid_pressed && !select_pressed
PS1_MENU_RETURN2 == 0 ...
if (!valid_pressed) goto block_28;
if (select_pressed) no

!valid_pressed && select_pressed
if (!valid_pressed) goto block_28;
if (select_pressed) yes

valid_pressed && !select_pressed
if (positiony == ...)
if (select_pressed) no

valid_pressed && select_pressed
if (positiony == ...)
if (select_pressed) yes
*/
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
                        (compteur > delai_repetition && compteur % repetition == 0)
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
                        (compteur > delai_repetition && compteur % repetition == 0)
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

/* matches, but clean up */
/* 811C8 801A59C8 -O2 -msoft-float */
void DO_COMMANDE_SAVE(void)
{
    s16 var_v0;
    s16 var_v0_4;
    u16 var_v0_2;
    u8 var_v0_3;

    if ((rightjoy(0) != 0) && (upjoy(0) == 0) && (downjoy(0) == 0) && (fichier_a_copier == 0))
    {
        if (
            button_released != 0 ||
            (compteur > delai_repetition && compteur % repetition == 0)
        )
        {
            if (positionx2 == D_801F5498)
            {
                var_v0 = 1;
            }
            else
            {
                var_v0 = positionx2 + 1;
            }
            positionx2 = var_v0;
            TempsDemo = 0;
            PlaySnd_old(0x0044);
        }
    }
    if ((leftjoy(0) != 0) && (upjoy(0) == 0) && (downjoy(0) == 0) && (fichier_a_copier == 0))
    {
        if (
            button_released != 0 ||
            (compteur > delai_repetition && compteur % repetition == 0)
        )
        {
            if (positionx2 == 1)
            {
                var_v0_2 = (u16) D_801F5498;
            }
            else
            {
                var_v0_2 = positionx2 - 1;
            }
            positionx2 = (s16) var_v0_2;
            TempsDemo = 0;
            PlaySnd_old(0x0044);
        }
    }
    if ((upjoy(0) != 0) && (leftjoy(0) == 0) && (rightjoy(0) == 0))
    {
        if (
            button_released != 0 ||
            (compteur > delai_repetition && compteur % repetition == 0)
        )
        {
            if (positiony < 2)
            {
                positiony = NBRE_SAVE;
            }
            else
                positiony = positiony - 1;
            TempsDemo = 0;
            PlaySnd_old(0x0044);
        }
    }
    if ((downjoy(0) != 0) && (leftjoy(0) == 0) && (rightjoy(0) == 0))
    {
        if (
            button_released != 0 ||
            (compteur > delai_repetition && compteur % repetition == 0)
        )
        {
            if (positiony == NBRE_SAVE)
            {
                var_v0_4 = 1;
            }
            else
            {
                var_v0_4 = positiony + 1;
            }
            positiony = var_v0_4;
            TempsDemo = 0;
            PlaySnd_old(0x0044);
        }
    }
    if ((rightjoy(0) == 0) && (leftjoy(0) == 0) && (downjoy(0) == 0) && (upjoy(0) == 0))
    {
        button_released = 1;
        compteur = 0;
    }
    else
    {
        button_released = 0;
    }
    if ((SelectButPressed() != 0) && (button_released != 0))
    {
        MENU_RETURN = 1;
    }
}