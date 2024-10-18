#include "video.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/video", FUN_80132980);*/

void FUN_80132980(void)
{
    LoadImage(&D_801CF5E0.field3_0xc,(u_long *)D_801CF5E0.field2_0x8);
    DrawSync(0);
    D_801CF5E0.field3_0xc.x = D_801CF5E0.field3_0xc.x + 0x10;
    if (D_801CF5E0.field3_0xc.x < 0x140) {
        DecDCTout((u_long *)D_801CF5E0.field2_0x8,0x680);
    }
    else {
        if (PS1_CurrentDisplay == PS1_Displays) {
            PS1_CurrentDisplay = PS1_Displays + 1;
            D_801CF5E0.field3_0xc.x = 0;
            D_801CF5E0.field3_0xc.y = 0x114;
        }
        else {
            PS1_CurrentDisplay = PS1_Displays;
            D_801CF5E0.field3_0xc.x = 0;
            D_801CF5E0.field3_0xc.y = 0x14;
        }

        D_801CF5E0.field4_0x14 = 1;
    }
}

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/video", PS1_PlayVideoFile);*/

void PS1_PlayVideoFile(s16 video)
{
  short sVar1;
  int iVar2;
  u32 *pbVar3;
  u8 temp_s3;
  u16 frame_count;
  
  ResetCallback();
  DecDCTReset(0);
  temp_s3 = 1;
  if (video == 4) {
    FUN_80132e04(&PS1_VdoFiles[video].file.pos,0x6b9);
  }
  else {
    FUN_80132e04(&PS1_VdoFiles[video].file.pos,1);
  }
  FUN_80132d74(&D_801CF5E0);
  DecDCToutCallback(FUN_80132980);
  PutDispEnv(&PS1_CurrentDisplay->field0_0x0);
  FUN_80132ea0((u32 *)(&D_801CF5E0.field0_0x0)[D_801CF5E0.field6_0x16],video);
  D_801CF5E0.field5_0x15 = 0;
  if ((PS1_VideoState < 2) && ((u16) D_801CF5E0.frame_count < PS1_VideoLength))
  {
    do {
      D_801CF5E0.field4_0x14 = 0;
      if (temp_s3) {
        readinput();
      }
      DecDCTout((u32 *)D_801CF5E0.field2_0x8,0x680);
      DecDCTin((u32 *)(&D_801CF5E0.field0_0x0)[D_801CF5E0.field6_0x16],0);

      
      if (D_801CF5E0.field6_0x16) {
        D_801CF5E0.field6_0x16 = 0;
        pbVar3 = D_801CF5E0.field0_0x0;
      }
      else
      {
        D_801CF5E0.field6_0x16 = 1;
        pbVar3 = D_801CF5E0.field1_0x4;

      }
      FUN_80132ea0(pbVar3,video);
      if ((temp_s3) &&
         ((sVar1 = but1pressed(0), sVar1 != 0 || (iVar2 = PS1_TOUCHE_0x9(0), iVar2 != 0)))) {
        PS1_VideoState = 2;
      }
      while (D_801CF5E0.field4_0x14 == 0){};
      while (D_801CF5E0.field5_0x15 != 0){};
    } while ((PS1_VideoState < 2) && ((u16) D_801CF5E0.frame_count < PS1_VideoLength));
  }
  SsSetSerialVol('\0',0,0);
  CdControlB('\t',(u_char *)0x0,(u_char *)0x0);
  D_801CF5E0.field4_0x14 = 0;
  DecDCTout((u32 *)D_801CF5E0.field2_0x8,0x680);
  DecDCTin((u32 *)(&D_801CF5E0.field0_0x0)[D_801CF5E0.field6_0x16],0);
  do {
  } while (D_801CF5E0.field4_0x14 == 0);
  do {
  } while (D_801CF5E0.field5_0x15 != 0);
  DecDCTinCallback(0);
  DecDCToutCallback(0);
  CdDataCallback(0);
  CdReadyCallback((void *)0x0);
  VSyncCallback((void *)0x0);
  iVar2 = 1;
  do {
    VSync(0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);

  while (temp_s3 != 0 && (((s16) but1pressed(0)) || (PS1_TOUCHE_0x9(0)))) {
    readinput();
  }
  return;
}

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/video", FUN_80132ea0);*/

void FUN_80132ea0(u32 *param_1, s16 video)
{
    u32 *usr_dat; /* also StHEADER? */
    StHEADER *header;
    u8 vol;

    while (StGetNext(&usr_dat, (u32 **) &header) != 0){};
    D_801CF5E0.frame_count = header->frameCount;
    if (video == 1)
        SsSetSerialVol(SS_SERIAL_A, 80, 80);
    else
    {
        vol = (options_jeu.Music * 127 / 20);
        SsSetSerialVol(SS_SERIAL_A, vol, vol);
    }
    DecDCTvlc(usr_dat, param_1);
    StFreeRing(usr_dat);
}

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/video", FUN_80132f8c);*/

void FUN_80132f8c(void)
{
    D_801CF5E0.field5_0x15 = D_801CF5E0.field5_0x15 + 1;
    __asm__("lbu     $v0,0($v1)\nnop");
    if ((D_801CF5E0.field5_0x15 > 3) && (D_801CF5E0.field4_0x14 != 0)) {
        D_801CF5E0.field5_0x15 = 0;
        PutDrawEnv(&PS1_CurrentDisplay->drawing_environment);
        PutDispEnv(&PS1_CurrentDisplay->field0_0x0);
    }
}