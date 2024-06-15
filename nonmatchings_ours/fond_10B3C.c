#include "fond_10B3C.h"

/* give m2c another go? */
/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondSprites);*/

void PS1_LoadFondSprites(void)

{
  u8 bVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;
  short sVar6;
  short sVar7;
  u_char uVar8;
  u_char uVar9;
  u_short uVar10;
  Sprite *puVar5;
  SPRT *pSVar11;
  SPRT *pSVar12;
  SPRT *p_01;
  SPRT *p_00;
  DR_ENV *dr_env;
  u8 bVar13;
  DR_ENV *local_30;
  Display *disp_1; Display *disp_2;
  
  PS1_BackgroundPositions = PS1_LevelBGBlock->sprite_positions;
  PS1_BackgroundSprites = PS1_LevelBGBlock->sprites;
  if (PS1_FondType == 6 || PS1_FondType == 7) {
    dr_env = PS1_Display1.field6_0x2b0;
    local_30 = ((Display *)&PS1_Display1 + 1)->field6_0x2b0;
    p_00 = PS1_Display1.sprites;
    p_01 = PS1_Display2.sprites;
    
    if (NbSprite != 0) {
      puVar5 = &PS1_LevelBGBlock->sprites[0]; /* this one is correct? */
      pSVar11 = PS1_Display1.sprites;
      pSVar12 = PS1_Display2.sprites;
      
      bVar13 = 0;
      do {
        bVar1 = puVar5->id;
        SetSemiTrans(p_00,(uint)(u8)(&D_801F51BF)[bVar1]);
        SetShadeTex(p_00,1);
        pSVar11[0].u0 = puVar5->page_x;
        pSVar11[0].v0 = puVar5->page_y;
        pSVar11[0].w = puVar5->width;
        pSVar11[0].h = puVar5->height;
        pSVar11[0].clut = puVar5->clut;
        __builtin_memcpy(&pSVar11[0x10], p_00, sizeof(SPRT));
        __builtin_memcpy(&pSVar11[0x20], &pSVar11[0x10], sizeof(SPRT));
        __builtin_memcpy(&pSVar11[0x10], p_00, sizeof(SPRT));
        __builtin_memcpy(&pSVar11[0x20], &pSVar11[0x10], sizeof(SPRT));
        SetSemiTrans(p_01,(uint)(u8)(&D_801F51BF)[bVar1]);
        SetShadeTex(p_01,1);
        pSVar12[0].u0 = puVar5->page_x;
        pSVar12[0].v0 = puVar5->page_y;
        pSVar12[0].w = puVar5->width;
        pSVar12[0].h = puVar5->height;
        pSVar12[0].clut = puVar5->clut;
        __builtin_memcpy(&pSVar12[0x10], p_01, sizeof(SPRT));
        __builtin_memcpy(&pSVar12[0x20], &pSVar12[0x10], sizeof(SPRT));
        __builtin_memcpy(&pSVar12[0x10], p_01, sizeof(SPRT));
        __builtin_memcpy(&pSVar12[0x20], &pSVar12[0x10], sizeof(SPRT));
        bVar13 = bVar13 + 1;
        pSVar11 = pSVar11 + 1;
        p_00 = p_00 + 1;
        pSVar12 = pSVar12 + 1;
        p_01 = p_01 + 1;
        FUN_8017b260((short)puVar5->tpage);
        PS1_Display1.drawing_environment.tpage =
             GetTPage(1,(uint)(u8)(&D_801FA55F)[bVar1],D_801F8170,D_801F8174);
        SetDrawEnv(dr_env,&PS1_Display1.drawing_environment);
        PS1_Display2.drawing_environment.tpage =
             GetTPage(1,(uint)(u8)(&D_801FA55F)[bVar1],D_801F8170,D_801F8174);
        puVar5 = puVar5 + 1;
        SetDrawEnv(local_30,&PS1_Display2.drawing_environment);
        dr_env = dr_env + 1;
        local_30 = local_30 + 1;
      } while (bVar13 < NbSprite);
    }
  }
  return;
}