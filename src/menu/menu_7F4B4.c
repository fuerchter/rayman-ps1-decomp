#include "menu/menu_7F4B4.h"

extern s16 realisation_effectuee;
extern u8 D_801F7F68[8]; /* size? */
extern s16 action;
extern s16 fin_saisie_nom;
extern u8 save_ray[4][4];
extern s16 sortie_save;
extern s16 positionx;
extern s16 compteur_clignote;
extern s16 D_801F5448;
extern s16 D_801E5748;
extern s16 positiony2;
extern s16 selection_effectuee;
extern s16 affiche_bon_ecran;

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

/* 80004 801A4804 -O2 -msoft-float */
void AFFICHE_ECRAN_SAVE(void)
{
    s16 cur_save;
    s16 cur_char;
    u8 save_ray_cpy[4];
    u8 prev_char;
    s32 c_max = 30;

    INIT_AFFICHE_ECRAN_SAVE();
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
    
    if (compteur_clignote < c_max)
        compteur_clignote++;
    else
        compteur_clignote = 0;
    DO_FADE();
    CLRSCR();
    DISPLAY_FOND_MENU();
    display_text(s_choose_a_game_8012c4e0, 160, debut_titre, 1, 11);
    display_text(s_copy_801cf124, 30, debut_sortie, 1, 8);
    display_text(s_erase_801cf12c, 125, debut_sortie, 1, 8);
    display_text(s_start_801cf134, 223, debut_sortie, 1, 8);
    
    for (cur_save = 0; cur_save < NBRE_SAVE; cur_save++)
    {
        if (strcmp(save_ray[cur_save + 1], s__801cf120) != 0)
        {
            
            for (cur_char = 1; (u32) cur_char <= strlen(save_ray[cur_save + 1]); cur_char++)
            {
                if (
                    positionx != cur_char || positiony != (cur_save + 1) ||
                    compteur_clignote <= c_max / 2 ||
                    D_801F5448 == 0
                )
                {
                    strcpy(save_ray_cpy, save_ray[cur_save + 1]);
                    save_ray_cpy[cur_char] = 0;
                    prev_char = save_ray_cpy[cur_char - 1];
                    if (prev_char == '~')
                    {
                        display_text(
                            s__801cf13c,
                            basex + (cur_char - 1) * D_801E5748 - 10,
                            debut_options + cur_save * (ecarty + 23),
                            1,
                            3
                        );
                    }
                    else if (prev_char == ' ')
                    {
                        display_text(
                            s_801cf141,
                            basex + (cur_char - 1) * D_801E5748,
                            debut_options + cur_save * (ecarty + 23),
                            1,
                            3
                        );
                    }
                    else
                    {
                        display_text(
                            save_ray_cpy + (cur_char - 1),
                            basex + (cur_char - 1) * D_801E5748,
                            debut_options + cur_save * (ecarty + 23),
                            1,
                            colour
                        );
                    }
                }
            }
            DISPLAY_SAVE_SPRITES((s16) (basex + (D_801E5748 + 11) * 3 - 30), cur_save);
        }
        else
        {
            let_shadow = true;
            display_text(s_empty_801cf144, basex, debut_options + cur_save * (ecarty + 0x17), 1, 3);
        }
    }
    DISPLAY_SAVE_POING();
    if (
        (action == 1 && fichier_selectionne != 0) ||
        (action == 3 && fichier_selectionne != 0)
    )
    {
        display_text(s_up__down__browse_8012c4f0, 160, 193, 2, 10);
        display_text(s_x__validate_letter_8012c508, 160, 208, 2, 10);
    }
    else
    {
        display_text(s_x__validate_8012c4bc, 160, 208, 2, 10);
    }
    display_text(s_select__return_8012c4cc, 160, 223, 2, 10);
}

/* 80538 801A4D38 -O2 -msoft-float*/
s32 PS1_DoGameOptionsLoop(void)
{
  s32 done;
  
  readinput();
  AFFICHE_PAD_SCREEN();
  DO_COMMANDE_PAD();
  PS1_SetSoundVolume(PS1_Settings[4]);
  PS1_SetStereoEnabled(PS1_Settings[5]);
  PS1_SetMusicVolume(PS1_Settings[3]);
  if ((ValidButPressed() && position == 7) || StartButPressed())
  {
    D_801D7A50 = true;
    PlaySnd_old(69);
  }
  if (MENU_RETURN)
  {
    while ((s16) but0pressed(0) || (s16) but1pressed(0) || (s16) but2pressed(0) || (s16) but3pressed(0))
      readinput();
  }
  done = false;
  if (fin_du_jeu || D_801D7A50 || MENU_RETURN) 
    done = true;
  return done;
}

/* 80690 801A4E90 -O2 -msoft-float */
void PS1_DoGameOptions(void)
{
  FUN_801a6808();
  FUN_8019eb30();
  INIT_FADE_IN();
  FUN_801a76e4();
  SYNCHRO_LOOP(PS1_DoGameOptionsLoop);
  FUN_801a6984();
  DO_FADE_OUT();
}

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", AFFICHE_PAD_SCREEN);

/* 81074 801A5874 -O2 -msoft-float */
void INIT_SAVE_CHOICE(void)
{
  s16 i;
  s32 unk_1;
  
  D_801F5498 = 3;
  positiony = 1;
  positionx2 = 3;
  button_released = 1;
  compteur = 0;
  max_compteur = 100;
  nouvelle_partie = false;
  delai_repetition = 12;
  repetition = 6;
  MENU_RETURN = 0;
  basex = 40;
  sortie_save = 0;
  positiony2 = NBRE_SAVE + 1;
  if (NBRE_SAVE && (unk_1 = NBRE_SAVE != false)) /* but, but why though??? */
  {
    i = 0;
    do {
      LoadInfoGame(i + 1);
      i++;
    } while (i < NBRE_SAVE);
  }
}

/* 8116C 801A596C -O2 -msoft-float */
void INIT_SAVE_CONTINUE(void)
{
  selection_effectuee = 0;
  realisation_effectuee = 0;
  fichier_selectionne = 0;
  fichier_a_copier = 0;
  action = 0;
  fin_saisie_nom = false;
  affiche_bon_ecran = 0;
  D_801F5448 = 0;
  compteur_clignote = 0;
  positionx = 1;
}

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