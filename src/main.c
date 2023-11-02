#include "main.h"

/* B438 8012FC38 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/main", main);
#else
/* TODO: still to figure out */
extern s32 *D_801F4380;
extern s32 D_8005866C; /* data from PS1_LoadFiles seems to end up in here */
extern u8 D_801E4D48;
extern s32 PS1_CurrentDisplay;
extern u8 PS1_Display1;
extern u8 PS1_Display2;

extern u8 PS1_Ingame; /* TODO: put near PS1_CheckPauseAndCheatInputs */

void main(void)
{
  s32 *next_display;
  RaymanEvents default_evts;
  
  __asm__("nop");

  default_evts = PS1_DefaultRayEvts;
  ResetCallback();
  _96_remove();
  D_801E4D48 = 0;
  FIRST_INIT();
  INIT_MOTEUR_BEGIN();
  DEPART_INIT_LOOP();
  while (!PS1_InitPAD())
    PS1_PromptPad();
  StartPAD();
  ChangeClearPAD(0);
  D_801F4380 = 0x8005866C;
  do {
    if (menuEtape != 4)
      INIT_WORLD_INFO();
    
    PS1_LoadFont();
    DO_MENU();
    if (!fin_du_jeu)
    {
      if (status_bar.num_lives > -1 && new_world && ModeDemo == 0)
        PS1_PlayMapIntro();
      
      while (!fin_du_jeu && status_bar.num_lives > -1 && new_world)
      {
        SPECIAL_INIT();
        PS1_LoadFont();
        DO_WORLD_MAP();
        DEPART_WORLD();
        while (!fin_du_jeu && !new_world && new_level)
        {
          DEPART_LEVEL();
          INIT_MOTEUR_LEVEL(new_level);
          init_fee();
          init_moustique();
          PS1_StopPlayingSnd(D_801C7D20[num_world]);
          while (!fin_du_jeu && !new_level && !new_world)
          {
            DEPART_DEAD_LOOP();
            INIT_MOTEUR_DEAD();
            INIT_RAY_ON_MS(&NewMs);
            if (num_world == 6 && num_level == 2)
              RayEvts = default_evts;
            
            while(dead_time != 0 && !new_level && !new_world && ModeDemo != 2)
              DO_MAIN_LOOP();

            if (PS1_CurrentDisplay == &PS1_Display1)
              next_display = &PS1_Display1 + 0x6CBC;
            else
              next_display = &PS1_Display1;
            PS1_CurrentDisplay = next_display;
            
            PS1_Ingame = false;
            PS1_StopLevelMusic();
            DO_CONTINUE();
            DO_VICTOIRE();
          }
          DONE_MOTEUR_LEVEL();
          FIN_DEAD_LOOP();
        }
        if (ModeDemo != 0)
          fin_du_jeu = true;
      }
    }
    if (ModeDemo != 0)
      FinDemoJeu();
  } while( true );
}
#endif