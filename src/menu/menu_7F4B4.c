#include "menu/menu_7F4B4.h"

u8 s_start_801cf118[] = "/start/";

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
  text_to_display[1].is_fond = FALSE;
  text_to_display[1].field8_0x3d = FALSE;
  text_to_display[1].color = 11;
  INIT_TXT_BOX(text_to_display + 1);
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
  text_to_display[2].is_fond = FALSE;
  text_to_display[2].field8_0x3d = FALSE;
  text_to_display[2].color = 11;
  INIT_TXT_BOX(text_to_display + 2);
  positiony = 1;
  button_released = 1;
  compteur = 0;
  max_compteur = 100;
  delai_repetition = 12;
  repetition = 6;
  PS1_SaveMode = 0;
  MENU_RETURN = FALSE;
  PS1_MENU_RETURN2 = FALSE;
}

/* 7F754 801A3F54 -O2 */
/* m2c: 4602 ghidra: 9437 */
INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_InputCardOrPassword);

/* 7FAE8 801A42E8 -O2 */
INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_DisplayCardOrPassword);

/* 7FC58 801A4458 -O2 */
/*? CLRSCR();
? DISPLAY_FOND_MENU();
? DO_FADE();
? PS1_DisplayCardOrPassword();
? PS1_InputCardOrPassword();
? readinput();*/

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
    done = FALSE;
    if ((PS1_SaveMode != 0 || MENU_RETURN == TRUE) && button_released != 0)
        done = TRUE;
        
    return done;
}

/* 7FCEC 801A44EC -O2 */
/*? DO_FADE_OUT();
? INIT_FADE_IN();
? LOAD_SAVE_SCREEN();
? PS1_PlayCDTrack_0_3();
? SYNCHRO_LOOP(u8 (*)());*/

void PS1_InitCardOrPassword(void)
{
    LOAD_SAVE_SCREEN();
    PS1_TextBoxCardOrPassword();
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    SYNCHRO_LOOP(PS1_MenuCardOrPassword);
    DO_FADE_OUT();
}
