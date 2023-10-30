#include "menu/menu_82008.h"

/*
generates division checks if:
-function arg is involved
-global is involved
-uninitialized local var is involved

still to see more
*/
/* 82008 801A6808 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/menu/menu_82008", FUN_801a6808);

/* 82184 801A6984 -O2 -msoft-float */
void FUN_801a6984(void)
{
  options_jeu.Jump = PS1_Settings[0];
  options_jeu.Fist = PS1_Settings[1];
  options_jeu.Action = PS1_Settings[2];
  options_jeu.Music = PS1_Settings[3];
  options_jeu.Soundfx = PS1_Settings[4];
  options_jeu.StereoEnabled = PS1_Settings[5];
  POINTEUR_BOUTONS_OPTIONS_BIS();
}

/* 82204 801A6A04 -O2 -msoft-float */
void FUN_801a6a04(u8 param_1)
{
    fichier_existant = false;
    fichier_selectionne = 0;
    NBRE_SAVE = 0;
    TempsDemo = 0;
    nouvelle_partie = true;
    INIT_NEW_GAME();
    if (param_1)
        FUN_801a3550();
}

/* 82268 801A6A68 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/menu/menu_82008", DO_COMMANDE_PAD);

/* 82EE4 801A76E4 -O2 -msoft-float */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/menu/menu_82008", FUN_801a76e4);
#else
void FUN_801a76e4(void)
{
    s16 i;
    u8 seven;

    i = 0;
    if ((D_801F5498 + 2) > 0)
    {
        do
        {
            strcpy(&text_to_display[i], PS1_SettingStrings[i]);
            seven = 7;
            if (i == seven)
            {
                text_to_display[seven].x_pos = 0x00A0;
                text_to_display[seven].font_size = 2;
                text_to_display[seven].y_pos = PS1_display_y1;
            }
            else
            {
                text_to_display[i].x_pos = basex;
                if (i >= 6)
                    text_to_display[i].y_pos = debut_sortie + (PS1_display_y2 + 15) * (i - 1);
                else
                    text_to_display[i].y_pos = debut_sortie + (PS1_display_y2 + 15) * i;
                
                text_to_display[i].font_size = 2;
            }
            text_to_display[i].is_fond = 1;
            text_to_display[i].field8_0x3d = 0;
            INIT_TXT_BOX(&text_to_display[i].text);
            i++;
        } while (i < (D_801F5498 + 2));
    }

    __asm__("nop\nnop\nnop\nnop\nnop\nnop");
}
#endif