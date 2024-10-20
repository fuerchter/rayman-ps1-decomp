#include "video.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/video", FUN_80132980);*/

void FUN_80132980(void)
{
    LoadImage(&PS1_CurrentVideoState.frame_rect,(u_long *)PS1_CurrentVideoState.decoded_frame);
    DrawSync(0);
    PS1_CurrentVideoState.frame_rect.x = PS1_CurrentVideoState.frame_rect.x + 0x10;
    if (PS1_CurrentVideoState.frame_rect.x < 0x140) {
        DecDCTout((u_long *)PS1_CurrentVideoState.decoded_frame,0x680);
    }
    else {
        if (PS1_CurrentDisplay == PS1_Displays) {
            PS1_CurrentDisplay = PS1_Displays + 1;
            PS1_CurrentVideoState.frame_rect.x = 0;
            PS1_CurrentVideoState.frame_rect.y = 0x114;
        }
        else {
            PS1_CurrentDisplay = PS1_Displays;
            PS1_CurrentVideoState.frame_rect.x = 0;
            PS1_CurrentVideoState.frame_rect.y = 0x14;
        }

        PS1_CurrentVideoState.has_swapped_display = 1;
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
  FUN_80132d74(&PS1_CurrentVideoState);
  DecDCToutCallback(FUN_80132980);
  PutDispEnv(&PS1_CurrentDisplay->field0_0x0);
  PS1_ReadVideoFile((u32 *)(&PS1_CurrentVideoState.encoded_frame_buffers[0])[PS1_CurrentVideoState.current_encode_buffer_index],video);
  PS1_CurrentVideoState.vsync_counter = 0;
  if ((PS1_VideoPlayState < 2) && ((u16) PS1_CurrentVideoState.frame_count < PS1_VideoLength))
  {
    do {
      PS1_CurrentVideoState.has_swapped_display = 0;
      if (temp_s3) {
        readinput();
      }
      DecDCTout((u32 *)PS1_CurrentVideoState.decoded_frame,0x680);
      DecDCTin((u32 *)(&PS1_CurrentVideoState.encoded_frame_buffers[0])[PS1_CurrentVideoState.current_encode_buffer_index],0);

      
      if (PS1_CurrentVideoState.current_encode_buffer_index) {
        PS1_CurrentVideoState.current_encode_buffer_index = 0;
        pbVar3 = PS1_CurrentVideoState.encoded_frame_buffers[0];
      }
      else
      {
        PS1_CurrentVideoState.current_encode_buffer_index = 1;
        pbVar3 = PS1_CurrentVideoState.encoded_frame_buffers[1];

      }
      PS1_ReadVideoFile(pbVar3,video);
      if ((temp_s3) &&
         ((sVar1 = but1pressed(0), sVar1 != 0 || (iVar2 = PS1_TOUCHE_0x9(0), iVar2 != 0)))) {
        PS1_VideoPlayState = 2;
      }
      while (PS1_CurrentVideoState.has_swapped_display == 0){};
      while (PS1_CurrentVideoState.vsync_counter != 0){};
    } while ((PS1_VideoPlayState < 2) && ((u16) PS1_CurrentVideoState.frame_count < PS1_VideoLength));
  }
  SsSetSerialVol('\0',0,0);
  CdControlB('\t',(u_char *)0x0,(u_char *)0x0);
  PS1_CurrentVideoState.has_swapped_display = 0;
  DecDCTout((u32 *)PS1_CurrentVideoState.decoded_frame,0x680);
  DecDCTin((u32 *)(&PS1_CurrentVideoState.encoded_frame_buffers[0])[PS1_CurrentVideoState.current_encode_buffer_index],0);
  do {
  } while (PS1_CurrentVideoState.has_swapped_display == 0);
  do {
  } while (PS1_CurrentVideoState.vsync_counter != 0);
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
/*INCLUDE_ASM("asm/nonmatchings/video", PS1_ReadVideoFile);*/

void PS1_ReadVideoFile(u32 *param_1, s16 video)
{
    u32 *usr_dat; /* also StHEADER? */
    StHEADER *header;
    u8 vol;

    while (StGetNext(&usr_dat, (u32 **) &header) != 0){};
    PS1_CurrentVideoState.frame_count = header->frameCount;
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
    PS1_CurrentVideoState.vsync_counter = PS1_CurrentVideoState.vsync_counter + 1;
    __asm__("lbu     $v0,0($v1)\nnop");
    if ((PS1_CurrentVideoState.vsync_counter > 3) && (PS1_CurrentVideoState.has_swapped_display != 0)) {
        PS1_CurrentVideoState.vsync_counter = 0;
        PutDrawEnv(&PS1_CurrentDisplay->drawing_environment);
        PutDispEnv(&PS1_CurrentDisplay->field0_0x0);
    }
}