#include "menu/menu_7F4B4.h"

extern s16 realisation_effectuee;
extern u8 s__801cf120[1];
extern u8 D_801F7F68[8]; /* size? */
extern s16 action;
extern s16 fin_saisie_nom;
extern u8 save_ray[4][4];
extern s16 sortie_save;

/* 7F4B4 801A3CB4 -O2 */
void PS1_TextBoxCardOrPassword(void)
{
  switch(menuEtape)
  {
    case 1:
      __builtin_strcpy(text_to_display[1].text, "/use memory card/");
      break;
    case 2:
      __builtin_strcpy(text_to_display[1].text, "/enter password/");
      break;
  }
  text_to_display[1].x_pos = 160;
  text_to_display[1].y_pos = 80;
  text_to_display[1].font_size = 1;
  text_to_display[1].is_fond = false;
  text_to_display[1].field8_0x3d = false;
  text_to_display[1].color = 11;
  INIT_TXT_BOX(&text_to_display[1]);
  switch(menuEtape)
  {
    case 1:
      __builtin_strcpy(text_to_display[2].text, "/use password/");
      break;
    case 2:
      __builtin_memcpy(text_to_display[2].text, s_start_801cf118, sizeof(s_start_801cf118));
      break;
  }
  text_to_display[2].x_pos = 160;
  text_to_display[2].y_pos = 140;
  text_to_display[2].font_size = 1;
  text_to_display[2].is_fond = false;
  text_to_display[2].field8_0x3d = false;
  text_to_display[2].color = 11;
  INIT_TXT_BOX(&text_to_display[2]);
  positiony = 1;
  button_released = 1;
  compteur = 0;
  max_compteur = 100;
  delai_repetition = 12;
  repetition = 6;
  PS1_SaveMode = 0;
  MENU_RETURN = false;
  PS1_MENU_RETURN2 = false;
}

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_InputCardOrPassword);

/* 7FAE8 801A42E8 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_DisplayCardOrPassword);
#else
void PS1_DisplayCardOrPassword(void)
{
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
        text_to_display[positiony].color = 144;
        display_box_text(&text_to_display[positiony]);
    }
    let_shadow = true;
    
    switch (positiony)
    {
    case 1:
        text_to_display[2].color = 10;
        display_box_text(&text_to_display[2]);
        break;
    case 2:
        text_to_display[1].color = 10;
        display_box_text(&text_to_display[1]);
        break;
    }
    display_text(s_x__validate_8012c4bc, 160, 208, 2, 10);
    display_text(s_select__return_8012c4cc, 160, 223, 2, 10);

    __asm__("nop");
}
#endif

/* 7FC58 801A4458 -O2 */
u8 PS1_MenuCardOrPassword(void)
{
    u8 done;

    if (fade == 0)
        PS1_InputCardOrPassword();

    CLRSCR();
    DISPLAY_FOND_MENU();
    DO_FADE();
    PS1_DisplayCardOrPassword();
    readinput();
    done = false;
    if ((PS1_SaveMode != 0 || MENU_RETURN == true) && button_released != 0)
        done = true;
        
    return done;
}

/* 7FCEC 801A44EC -O2 */
void PS1_InitCardOrPassword(void)
{
    LOAD_SAVE_SCREEN();
    PS1_TextBoxCardOrPassword();
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    SYNCHRO_LOOP(PS1_MenuCardOrPassword);
    DO_FADE_OUT();
}

/* 7FD3C 801A453C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", saisie_nom_prg);
#else
s32 saisie_nom_prg(void)
{
  u8 done; /* fine as u8 or s16? */

  readinput();
  __asm__("nop");
  SAISIE_NOM();
  readinput();
  AFFICHE_ECRAN_SAVE();
  if (action == 3)
    sortie_save = true;
  done = false;
  if (fin_saisie_nom || MENU_RETURN)
  {
    done = true;
    if (MENU_RETURN)
    {
      if (action == 1)
        strcpy(save_ray[fichier_selectionne], &D_801F7F68);
      else
        save_ray[fichier_selectionne][0] = s__801cf120[0];
    }
  }
  return done;
}
#endif

/* 7FE30 801A4630 -O2 -msoft-float */
s32 selection_save_option_prg(void)
{
  s32 done;
  
  readinput();
  DO_COMMANDE_SAVE();
  AFFICHE_ECRAN_SAVE();
  SELECTION_SAVE_OPTION();
  REALISATION_ACTION();
  if
  (
    (action == 1 && fichier_selectionne != 0) ||
    (action == 3 && !fichier_existant && fichier_selectionne != 0)
  )
  {
    if (!fin_saisie_nom)
      SYNCHRO_LOOP(saisie_nom_prg);
    if (!MENU_RETURN)
      SaveGameOnDisk(fichier_selectionne);
  }
  while (ValidButPressed())
    readinput();
  if (realisation_effectuee)
    INIT_SAVE_CONTINUE();
  action = 0;
  done = false;
  if (fin_du_jeu || sortie_save || MENU_RETURN)
    done = true;
  return done;
}

/* 7FF90 801A4790 -O2 -msoft-float */
void DO_SAVE_CHOICE(void)
{
    let_shadow = true;
    LOAD_SAVE_SCREEN();
    PS1_CheckCardChanged();
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    INIT_SAVE_CHOICE();
    INIT_SAVE_CONTINUE();
    TempsDemo = 0;
    SYNCHRO_LOOP(selection_save_option_prg);
    DO_FADE_OUT();
}

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", AFFICHE_ECRAN_SAVE);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_DoGameOptionsLoop);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_DoGameOptions);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", AFFICHE_PAD_SCREEN);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", INIT_SAVE_CHOICE);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", INIT_SAVE_CONTINUE);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", DO_COMMANDE_SAVE);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", SELECTION_SAVE_OPTION);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", INIT_AFFICHE_ECRAN_SAVE);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", SAISIE_NOM);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", REALISATION_ACTION);

const u8 s_x__validate_8012c4bc[] = "/x : validate/";
const u8 s_select__return_8012c4cc[] = "/select : return/";
const u8 s_choose_a_game_8012c4e0[] = "/choose a game/";
const u8 s_up__down__browse_8012c4f0[] = "/up | down : browse/";
const u8 s_x__validate_letter_8012c508[] = "/x : validate letter/";
const u8 s_press_wished_button_8012c520[] = "/press wished button/";
const u8 s_left__right__modify_options_8012c538[] = "/left | right : modify options/";
const u8 s_up__down__choose_options_8012c558[] = "/up | down : choose options/";
const u8 s_x_validate_select_quit_game_8012c578[] = "/x: validate select: quit game/";