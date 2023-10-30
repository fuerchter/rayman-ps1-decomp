#include "menu/menu_82008.h"

/*
missing addiu, div nop swap
matches, but clean up to do (no gotos left)
*/
/* 82268 801A6A68 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/menu/menu_82008", DO_COMMANDE_PAD);*/

void DO_COMMANDE_PAD(void)
{
  s16 bVar1;
  short sVar2;
  int iVar3;
  s16 iVar4;
  s16 var_v1;
  
  iVar3 = SelectButPressed();
  if (iVar3 != 0) {
    while (iVar3 = SelectButPressed(), iVar3 != 0) {
      readinput();
    }
    MENU_RETURN = 1;
  }
  iVar3 = upjoy(0);
  if (((iVar3 != 0) && (iVar3 = rightjoy(0), iVar3 == 0)) && (iVar3 = leftjoy(0), iVar3 == 0)) {
    if (button_released != 0 || (compteur > delai_repetition && compteur % repetition == 0)) {
      PlaySnd_old(0x44);
      if (position == 0)
      {
          bVar1 = 7;
      }
      else
      {
          if (position == 7)
          {
              bVar1 = position - 2;
          }
          else
          {
              bVar1 = position - 1;
          }
      }
      position = bVar1;
    }
  }
  iVar3 = downjoy(0);
  if (((iVar3 != 0) && (iVar3 = rightjoy(0), iVar3 == 0)) && (iVar3 = leftjoy(0), iVar3 == 0)) {
    if (button_released != 0 || (compteur > delai_repetition && compteur % repetition == 0)) {
      PlaySnd_old(0x44);
      if (position == 7)
      {
          position = 0;
      }
      else
      {
          
          if (position == 5)
          {
              sVar2 = position + 2;
          }
          else
          {
              sVar2 = position + 1;
          }
          position = sVar2;
      }
    }
  }
  iVar3 = rightjoy(0);
  if (((iVar3 != 0) && (iVar3 = downjoy(0), iVar3 == 0)) && (iVar3 = upjoy(0), iVar3 == 0)) {
    if (position == 5) {
      if (button_released != 0 || (compteur > delai_repetition && compteur % delai_stereo == 0)) {
        PlaySnd_old(0x44);
        if (PS1_Settings[5] == 1) {
          PS1_Settings[5] = 0;
        }
        else {
          PS1_Settings[5] = 1;
        }
      }
    }
    if ((position == 3) && (PS1_Settings[3] < PS1_Music_Max)) {
      if (button_released != 0 || (compteur > delai_repetition && compteur % delai_barre == 0)) {
        PlaySnd_old(0x44);
        PS1_Settings[3] = PS1_Settings[3] + 1;
      }
    }
    if ((position == 4) && (PS1_Settings[4] < PS1_Soundfx_Max)) {
      if (button_released != 0 || (compteur > delai_repetition && compteur % delai_barre == 0)) {
        PlaySnd_old(0x44);
        PS1_Settings[4] = PS1_Settings[4] + 1;
      }
    }
  }
  iVar3 = leftjoy(0);
  if (((iVar3 != 0) && (iVar3 = downjoy(0), iVar3 == 0)) && (iVar3 = upjoy(0), iVar3 == 0))
  {
    if (position == 5) {
      if (button_released != 0 || (compteur > delai_repetition && compteur % delai_stereo == 0)) {
        PlaySnd_old(0x44);
        if (PS1_Settings[5] == 1) {
          PS1_Settings[5] = 0;
        }
        else {
          PS1_Settings[5] = 1;
        }
      }
    }
    if ((position == 3) && (0 < PS1_Settings[3])) {
      if (button_released != 0 || (compteur > delai_repetition && compteur % delai_barre == 0)) {
        PlaySnd_old(0x44);
        PS1_Settings[3] = PS1_Settings[3] + -1;
      }
    }
    if ((position == 4) && (PS1_Settings[4] >= 1))
    {
      if (button_released != 0 || (compteur > delai_repetition && compteur % delai_barre == 0)) {
        PlaySnd_old(0x44);
        PS1_Settings[4] = PS1_Settings[4] + -1;
      }
    }
  }
  if ((position == 5) && (iVar3 = ValidButPressed(), iVar3 != 0)) {
    PlaySnd_old(0x44);
    if (PS1_Settings[5] == 1) {
      PS1_Settings[5] = 0;
    }
    else {
      PS1_Settings[5] = 1;
    }
    while (iVar3 = ValidButPressed(), iVar3 != 0) {
      readinput();
    }
  }
  if ((ushort)position < 3) {
    sVar2 = but0pressed(0);
    if (((sVar2 != 0) && (PS1_Settings[position] != 0)) && (button_released != 0)) {
        PlaySnd_old(0x44);
        var_v1 = 0;
        if (PS1_Settings[0] != 0)
        {
          do {
            var_v1 += 1;
            if (PS1_Settings[var_v1] == 0)
              break;
          } while(var_v1 < 3);
        }
        if (var_v1 < 3)
            PS1_Settings[var_v1] = PS1_Settings[position];
        PS1_Settings[position] = 0;
    }
    if ((ushort)position < 3) {
      sVar2 = but1pressed(0);
      if (((sVar2 != 0) && (PS1_Settings[position] != 1)) && (button_released != 0)) {
        PlaySnd_old(0x44);
        var_v1 = 0;
        if (PS1_Settings[0] != 1)
        {
          do {
            var_v1 += 1;
            if (PS1_Settings[var_v1] == 1)
              break;
          } while(var_v1 < 3);
        }
        if (var_v1 < 3)
            PS1_Settings[var_v1] = PS1_Settings[position];
        PS1_Settings[position] = 1;
      }
      if ((ushort)position < 3) {
        sVar2 = but2pressed(0);
        if (((sVar2 != 0) && (PS1_Settings[position] != 2)) && (button_released != 0)) {
          PlaySnd_old(0x44);
          var_v1 = 0;
          if (PS1_Settings[0] != 2)
          {
            do {
              var_v1 += 1;
              if (PS1_Settings[var_v1] == 2)
                break;
            } while(var_v1 < 3);
          }
          if (var_v1 < 3)
              PS1_Settings[var_v1] = PS1_Settings[position];
          PS1_Settings[position] = 2;
        }
        if (((((ushort)position < 3) && (sVar2 = but3pressed(0), sVar2 != 0)) &&
            (PS1_Settings[position] != 3)) && (button_released != 0)) {
          PlaySnd_old(0x44);
          var_v1 = 0;
          if (PS1_Settings[0] != 3)
          {
            do {
              var_v1 += 1;
              if (PS1_Settings[var_v1] == 3)
                break;
            } while(var_v1 < 3);
          }
          if (var_v1 < 3)
              PS1_Settings[var_v1] = PS1_Settings[position];
          PS1_Settings[position] = 3;
        }
      }
    }
  }
  iVar3 = upjoy(0);
  if (((iVar3 == 0) && (iVar3 = downjoy(0), iVar3 == 0)) &&
     ((((iVar3 = rightjoy(0), iVar3 == 0 &&
        ((iVar3 = leftjoy(0), iVar3 == 0 && (sVar2 = but0pressed(0), sVar2 == 0)))) &&
       (sVar2 = but1pressed(0), sVar2 == 0)) &&
      ((sVar2 = but2pressed(0), sVar2 == 0 && (sVar2 = but3pressed(0), sVar2 == 0)))))) {
    button_released = 1;
    compteur = 0;
  }
  else {
    button_released = 0;
  }
  return;
}