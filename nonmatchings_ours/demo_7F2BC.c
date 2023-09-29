#include "demo_7F2BC.h"

/*INCLUDE_ASM("asm/nonmatchings/demo_7F2BC", PS1_DemoLoop);*/

/* 7F314 801A3B14 -O1 -O2 */
/*? DISPLAY_FOND3();
? DO_FADE();
? InitDemoJeu();
s32 StartButPressed();
s32 ValidButPressed();
? readinput();*/
extern u8 D_801F7FA8;
extern u8 ModeDemo;
extern u16 RunTimeDemo;
extern s32 TempsDemo;
extern s16 fade;
extern u8 fin_du_jeu;

u8 PS1_DemoLoop(void)
{
  s16 new_var2;
  s32 temp_v0;
  u16 new_var;
  u8 var_s0;
  u32 var_v0;
  DISPLAY_FOND3();
  var_s0 = 0;
  DO_FADE();
  PS1_ShowDemoText();
  readinput();
  if ((fade == 0) && ((ValidButPressed() != 0) || (StartButPressed() != 0)))
  {
    PS1_MENU_RETURN2 = 1;
  }
  temp_v0 = TempsDemo + 1;
  TempsDemo = temp_v0;
  if (((temp_v0 >= ((s32) (new_var = RunTimeDemo))) && (fin_du_jeu == 0)) && (PS1_MENU_RETURN2 == 0))
  {
    InitDemoJeu();
  }

  if (D_801F7FA8 != 0)
  {
    var_s0 = 1;
  }
  new_var2 = var_s0;
  var_v0 = new_var2;
  if ((((fin_du_jeu != 0) || (ModeDemo != 0)) || (PS1_MENU_RETURN2 != 0)) || ((MENU_RETURN != 0)))
  {
    var_v0 = 1;
  }
  return var_v0;

}