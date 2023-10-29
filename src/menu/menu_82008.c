#include "menu/menu_82008.h"

extern s16 D_801D7A50;
extern s16 D_801D7AA0;
extern s16 D_801F5498;
extern s16 D_801F9A38;
extern s16 D_801FA580;
extern s16 PS1_Setting_Action;
extern s16 PS1_Setting_Fist;
extern s16 PS1_Setting_Jump;
extern s16 PS1_Setting_Soundfx;
extern s16 basex;
extern s16 debut_titre;
extern s16 delai_barre;
extern s16 delai_stereo;
extern s16 ecart_barre;

extern s16 fichier_existant;
extern s16 fichier_selectionne;
extern u8 nouvelle_partie;

typedef struct Test {
 s16 test_1;
} Test;

extern s16 PS1_Setting_StereoEnabled;
extern s16 PS1_Setting_Music;

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
  options_jeu.Jump = PS1_Setting_Jump;
  options_jeu.Fist = PS1_Setting_Fist;
  options_jeu.Action = PS1_Setting_Action;
  options_jeu.Music = PS1_Setting_Music;
  options_jeu.Soundfx = PS1_Setting_Soundfx;
  options_jeu.StereoEnabled = PS1_Setting_StereoEnabled;
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

INCLUDE_ASM("asm/nonmatchings/menu/menu_82008", FUN_801a76e4);
