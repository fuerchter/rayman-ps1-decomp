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
  MENU_RETURN = 0;
  PS1_MENU_RETURN2 = 0;
}

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_InputCardOrPassword);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_DisplayCardOrPassword);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_MenuCardOrPassword);

INCLUDE_ASM("asm/nonmatchings/menu/menu_7F4B4", PS1_InitCardOrPassword);
