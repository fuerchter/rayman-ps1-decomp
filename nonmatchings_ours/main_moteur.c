#include "main_moteur.h"

/* reg swaps, not sure if due to unfinished Display struct */
/* AE28 8012F628 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/main_moteur", DO_MAIN_LOOP);*/

/*? DISPLAY_ALL_OBJECTS();
? DISPLAY_FIXE(s32);
? DISPLAY_GAME_VIGNET();
? DISPLAY_TEXT_FEE();
? DO_AFFICHE_PAUSE();
? DRAW_MAP();
? Display_and_free_luciole();
? FUN_8013045c();
? FUN_80168f48();
? FUN_80169564(?, ?);
? PS1_CheckPauseAndCheatInputs();
? PS1_DO_PICTURE_IN_PICTURE();
? PS1_DisplayFondSprites();
? PS1_PlayDeathMusic();
? PlaySnd_old(?);
? change_audio_track_puit();
? display_flocons_before();
? display_flocons_behind();
? display_grp_stars();
? display_pix_gerbes();
? display_time(s32);
s32 myRand(?);
? readinput();*/

extern s32 PS1_CurrentDisplay;
extern u8 PS1_Display1;
extern u8 PS1_Display2;

void DO_MAIN_LOOP(void)
{
  RECT *rect;
  int iVar1;
  u8 *pDVar3;
  s16 iVar4;
  
  if (PS1_CurrentDisplay == &PS1_Display1) {
    pDVar3 = &PS1_Display1 + 0x6cbc;
  }
  else
    pDVar3 = &PS1_Display1;
  iVar4 = 0;
  if (0 < PS1_PolygonIndexTableCount) {
    do {
      SetPolyFT4(pDVar3 + ((*&PS1_PolygonIndexTable[iVar4] * 0x28) + 0x4144));
      SetSemiTrans(pDVar3 + ((*&PS1_PolygonIndexTable[iVar4] * 0x28) + 0x4144), 0);
      SetShadeTex(pDVar3 + ((*&PS1_PolygonIndexTable[iVar4] * 0x28) + 0x4144), 1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < PS1_PolygonIndexTableCount);
  }
  PS1_PolygonIndexTableCount = 0;
  
  if (PS1_CurrentDisplay == &PS1_Display1) {
    pDVar3 = &PS1_Display1 + 0x6cbc;
  }
  else
    pDVar3 = &PS1_Display1;
  PS1_CurrentDisplay = pDVar3;
  ClearOTag(pDVar3 + 0x7F0,0xb);
  D_801E4BE0 = 0x19;
  D_801F4A28 = 0;
  D_801FA690 = 0;
  PS1_PolygonsCount = 0;
  D_801F81B0 = 0;
  if (PS1_MemoryUsageDisplayMode == 2) {
    ClearImage(PTR_PS1_MemoryUsageRect_801cee70,0x80,0x80,0x80);
  }
  readinput();
  if (PS1_MemoryUsageDisplayMode == 2) {
    ClearImage(PTR_PS1_MemoryUsageRect_801cee70,0x80,0,0);
  }
  D_801CEEA0 = 0;
  DO_GROS_MOTEUR_NORMAL();
  PS1_Ingame = true;
  D_801CEEA0 = 0;
  if (xmap < 0) {
    xmap = 0;
  }
  if (ymap < 0) {
    ymap = 0;
  }
  if (xmapmax < 0) {
    xmapmax = 0;
  }
  if (ymapmax < 0) {
    ymapmax = 0;
  }
  if (in_pause != false) {
    DO_AFFICHE_PAUSE();
  }
  if (PS1_MemoryUsageDisplayMode == 2) {
    ClearImage(PTR_PS1_MemoryUsageRect_801cee70,0,0x80,0);
  }
  if ((num_world == 5) && (num_level == 4)) {
    Display_and_free_luciole();
  }
  if (PS1_MemoryUsageDisplayMode == 2) {
    ClearImage(PTR_PS1_MemoryUsageRect_801cee70,0,0x80,0x80);
  }
  display_flocons_behind();
  DISPLAY_ALL_OBJECTS();
  display_grp_stars();
  display_pix_gerbes();
  display_flocons_before();
  if (((num_world == 2) && (num_level == 4)) || ((num_world == 4 && (num_level == 9)))) {
    if (((PS1_GlobalTimer & 0x3f) == 0) && (0x80 < myRand(0x100))) {
      PlaySnd_old(0xc3);
      FUN_80169564(8,9);
      D_801CEEA2 = 0;
    }
    else {
      FUN_80169564(1,9);
    }
  }
  if (is_fee) {
    DISPLAY_TEXT_FEE();
  }
  else {
    DISPLAY_FIXE(left_time);
  }
  display_time(left_time);
  DRAW_MAP();
  if (PS1_PictureInPicture != '\0') {
    PS1_DO_PICTURE_IN_PICTURE();
  }
  if (PS1_MemoryUsageDisplayMode != 0) {
    ClearImage(PTR_PS1_MemoryUsageRect_801cee70,0,0,0);
  }
  DrawSync(0);
  VSync(0);
  if (PS1_15fps != false) {
    VSync(0);
    VSync(0);
    VSync(0);
  }
    PutDispEnv((DISPENV *) PS1_CurrentDisplay);
    PutDrawEnv(PS1_CurrentDisplay + 0x14);
  rect = &PS1_MemoryUsageRect;
  if (PTR_PS1_MemoryUsageRect_801cee70 == &PS1_MemoryUsageRect) {
    rect = &PS1_MemoryUsageRect + 1;
  }
  PTR_PS1_MemoryUsageRect_801cee70 = rect;
  if (PS1_MemoryUsageDisplayMode != 0) {
    ClearImage(rect,0,0,0x80);
  }
  PS1_DisplayFondSprites();
  DrawSync(0);
  if (PS1_MemoryUsageDisplayMode == 2) {
    ClearImage(PTR_PS1_MemoryUsageRect_801cee70,0x80,0,0x80);
  }
  DrawOTag(PS1_CurrentDisplay + 0x7F0);
  PS1_CheckPauseAndCheatInputs();
  if ((dead_time != 0x40) && (D_801CEE9E != 0)) {
    PS1_PlayDeathMusic();
    D_801CEE9E = 0;
  }
  FUN_80168f48();
  CdSync(1,(u_char *)0x0);
  FUN_8013045c();
  if ((scrollLocked != false) && (PS1_ScrollLockedAudio == 0)) {
    change_audio_track_puit();
  }
  if (Vignet_To_Display != '\0') {
    PS1_Ingame = false;
    DISPLAY_GAME_VIGNET();
    PS1_Ingame = true;
  }
  return;
}

