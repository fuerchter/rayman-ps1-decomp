#include "menu/menu_6A3BC.h"

/* .data */
extern s32 PS1_Button_Text_Square;
extern s32 PS1_Button_Text_Cross;
extern s32 PS1_Button_Text_Triangle;
extern s32 PS1_Button_Text_Circle;

u8 but0pressed();
u8 but1pressed();
u8 but2pressed();
u8 but3pressed();

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_NEW_GAME); /* skipping for now due to WorldInfo.state */

/* 6A5F0 8018EDF0 -O2 -msoft-float */
void POINTEUR_BOUTONS_OPTIONS_BIS(void)
{
  u8 (*but0)() = &but0pressed;
  s32 val0 = 0;
  u8 (*but1)() = &but1pressed;
  s32 val1 = 0;
  u8 (*but2)() = &but2pressed;
  s32 val2 = 0;
  u8 (*but3)() = &but3pressed;
  s32 val3 = 0;

  switch (options_jeu.Jump)
  {
    case 0:
      options_jeu.Fire1ButtonFunc = but0;
      options_jeu.field11_0x1e = val0;
      break;
    case 1:
      options_jeu.Fire1ButtonFunc = but1;
      options_jeu.field11_0x1e = val1;
      break;
    case 2:
      options_jeu.Fire1ButtonFunc = but2;
      options_jeu.field11_0x1e = val2;
      break;
    case 3:
      options_jeu.Fire1ButtonFunc = but3;
      options_jeu.field11_0x1e = val3;
      break;
  }

  switch (options_jeu.Fist)
  {
    case 0:
      options_jeu.Fire0ButtonFunc = but0;
      options_jeu.field12_0x20 = val0;
      break;
    case 1:
      options_jeu.Fire0ButtonFunc = but1;
      options_jeu.field12_0x20 = val1;
      break;
    case 2:
      options_jeu.Fire0ButtonFunc = but2;
      options_jeu.field12_0x20 = val2;
      break;
    case 3:
      options_jeu.Fire0ButtonFunc = but3;
      options_jeu.field12_0x20 = val3;
      break;
    default:
      break;
  }

  switch (options_jeu.field6_0x14)
  {
    case 0:
      options_jeu.Button4Func = but0;
      options_jeu.field13_0x22 = val0;
      break;
    case 1:
      options_jeu.Button4Func = but1;
      options_jeu.field13_0x22 = val1;
      break;
    case 2:
      options_jeu.Button4Func = but2;
      options_jeu.field13_0x22 = val2;
      break;
    case 3:
      options_jeu.Button4Func = but3;
      options_jeu.field13_0x22 = val3;
      break;

  }

  switch (options_jeu.Action)
  {
    case 0:
      options_jeu.Button3Func = but0;
      options_jeu.field14_0x24 = val0;
      break;
    case 1:
      options_jeu.Button3Func = but1;
      options_jeu.field14_0x24 = val1;
      break;
    case 2:
      options_jeu.Button3Func = but2;
      options_jeu.field14_0x24 = val2;
      break;
    case 3:
      options_jeu.Button3Func = but3;
      options_jeu.field14_0x24 = val3;
      break;
  }
}

/* 6A890 8018F090 -O2 -msoft-float */
/*? display_text(? *, s16, s16, s32);*/

void PS1_DisplayPadButton(s16 button, s16 x, s16 y, u8 font_size)
{
    switch (button)
    {
    case 0:
        display_text(&PS1_Button_Text_Square, x, y, font_size, 0);
        return;
    case 1:
        display_text(&PS1_Button_Text_Cross, x, y, font_size, 14);
        return;
    case 2:
        display_text(&PS1_Button_Text_Triangle, x, y, font_size, 8);
        return;
    case 3:
        display_text(&PS1_Button_Text_Circle, x, y, font_size, 2);
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_CONTINUE);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", CHEAT_MODE_CONTINUE);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", MAIN_CONTINUE_PRG);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", FIN_CONTINUE_PRG);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", MAIN_NO_MORE_CONTINUE_PRG);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_VIGNET);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_CREDITS);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", DO_CREDITS);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_LOADER_ANIM);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", DO_LOADER_ANIM);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", SPECIAL_INIT);
