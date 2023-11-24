#include "menu/menu_7F4B4.h"

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

/* only the marked sections still bad */
/* 806E8 801A4EE8 -O2 -msoft-float */
void AFFICHE_PAD_SCREEN(void)
{
    s16 var_s1;
    s16 var_v0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_a2;
    u8 *var_a0;
    u8 *var_a0_2;
    u8 *var_a0_3;
    int new_var;

    DO_FADE();
    CLRSCR();
    DISPLAY_FOND_MENU();
    DISPLAY_OPTIONS_POING();
    if (compteur < max_compteur)
    {
        if (button_released == 0)
        {
            compteur += 1;
        }
        else
        {
            compteur = 0;
        }
    }
    else if (button_released == 0)
    {
        compteur = (u16) delai_repetition + 1;
    }
    else
    {
        compteur = 0;
    }
    let_shadow = 0;
    if (PS1_Settings[5] == 0 && position == 5)
    {
        display_text(PS1_SettingStrings[6], basex, debut_sortie + (PS1_display_y2 + 0xF) * 5, 2, 0x90);
    }
    else if (position == 7)
    {
        display_text(s_start_801cf134, 0x0087, PS1_display_y1, 2, 0x00000090);
    }
    else
    {
        display_text(PS1_SettingStrings[position], basex, debut_sortie + position * (PS1_display_y2 + 0xF), 2, 0x90);
    }
    display_text(s_options_801cf14c, 0x0076, debut_titre, 1, 0x0000000B);
    display_text(s_start_801cf134, 0x0087, PS1_display_y1, 2, 8);
    display_text(PS1_SettingStrings[0], basex, debut_sortie, 2, 7);
    display_text(PS1_SettingStrings[1], basex, debut_sortie + (PS1_display_y2 + 0xF), 2, 8);
    display_text(PS1_SettingStrings[2], basex, debut_sortie + ((PS1_display_y2 + 0xF) * 2), 2, 9);
    display_text(PS1_SettingStrings[3], basex, debut_sortie + ((PS1_display_y2 + 0xF) * 3), 2, 0x0000000A);
    display_text(PS1_SettingStrings[4], basex, debut_sortie + ((PS1_display_y2 + 0xF) * 4), 2, 0x0000000B);
    if (PS1_Settings[5] == 1)
    {
        display_text(PS1_SettingStrings[5], basex, debut_sortie + ((PS1_display_y2 + 0xF) * 5), 2, 0xc);
    }
    else
    {
        display_text(PS1_SettingStrings[6], basex, debut_sortie + ((PS1_display_y2 + 0xF) * 5), 2, 0xc);
    }
    PS1_DisplayPadButton(PS1_Settings[0], 0x96, debut_sortie, 2, 0);
    PS1_DisplayPadButton(PS1_Settings[1], 0x96, debut_sortie + (PS1_display_y2 + 0xF), 2, 0);
    PS1_DisplayPadButton(PS1_Settings[2], 0x96, debut_sortie + ((PS1_display_y2 + 0xF) * 2), 2, 0);
    var_s1 = 0;
    if (PS1_Settings[3] > 0)
    {
        do
        {
            if (var_s1 < ((s16) PS1_Music_Max / 3))
            {
                display_text(s__801cf154, basex + (ecart_barre * var_s1) + 0x64, debut_sortie + ((PS1_display_y2 + 0xF) * 3), 2, 6);
            }
            if (var_s1 < (PS1_Music_Max * 2 / 3))
            {
                if (var_s1 >= ((s16) PS1_Music_Max / 3))
                {
                    display_text(s__801cf154, basex + (ecart_barre * var_s1) + 0x64, debut_sortie + ((PS1_display_y2 + 0xF) * 3), 2, 4);
                }
            }
            /**/
            var_v0 = var_s1 + 1;
            if (var_s1 < PS1_Music_Max)
            {
                var_v0 = var_s1 + 1;
                if (var_s1 >= (PS1_Music_Max * 2 / 3))
                {
                    display_text(s__801cf154, basex + (ecart_barre * var_s1) + 0x64, debut_sortie + ((PS1_display_y2 + 0xF) * 3), 2, 1);
                    var_v0 = var_s1 + 1;
                }
            }
            var_s1 = var_v0;
        } while (var_v0 < PS1_Settings[3]);
    }
    var_s1 = 0;
    if (PS1_Settings[4] > 0)
    {
        do
        {
            if (var_s1 < ((s16) PS1_Soundfx_Max / 3))
            {
                display_text(s__801cf154, basex + (ecart_barre * var_s1) + 0x64, debut_sortie + ((PS1_display_y2 + 0xF) * 4), 2, 6);
            }
            if (var_s1 < (PS1_Soundfx_Max * 2 / 3))
            {
                if (var_s1 >= ((s16) PS1_Soundfx_Max / 3))
                {
                    display_text(s__801cf154, basex + (ecart_barre * var_s1) + 0x64, debut_sortie + ((PS1_display_y2 + 0xF) * 4), 2, 4);
                }
            }
            /**/
            var_v0 = var_s1 + 1;
            if (var_s1 < PS1_Soundfx_Max)
            {
                var_v0 = var_s1 + 1;
                if (var_s1 >= (PS1_Soundfx_Max * 2 / 3))
                {
                    display_text(s__801cf154, basex + (ecart_barre * var_s1) + 0x64, debut_sortie + ((PS1_display_y2 + 0xF) * 4), 2, 1);
                    var_v0 = var_s1 + 1;
                }
            }
            var_s1 = var_v0;
        } while (var_v0 < PS1_Settings[4]);
    }
    if (position < 3)
    {
        display_text(s_press_wished_button_8012c520, 0x00A0, 0x00C3, 2, 10);
    }
    else if (position < 7)
    {
        display_text(s_left__right__modify_options_8012c538, 0x00A0, 0x00C3, 2, 10);
    }
    display_text(s_up__down__choose_options_8012c558, 0x00A0, 0x00D1, 2, 0x0000000A);
    display_text(s_x_validate_select_quit_game_8012c578, 0x00A0, 0x00DF, 2, 0x0000000A);
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