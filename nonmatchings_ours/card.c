#include "card.h"

/*
matches, but doubled counter vars...
removing cnt2_2 on decomp.me still matches, but not locally
*/
/*INCLUDE_ASM("asm/nonmatchings/card", PS1_CardFilenameChecksum);*/

s32 PS1_CardFilenameChecksum(u8 chan)
{
    struct DIRENTRY dirs[15];
    u8 name_start[8];
    s32 nbre_files;
    u8 cnt1_1; s32 cnt1_2;
    u8 cnt2_1; u32 cnt2_2;
    struct DIRENTRY *cur_dir;
    s32 sum = 0;

    sprintf(name_start, s_bu02x_801cf040, chan);
    nbre_files = PS1_GetNbreFiles(name_start, dirs);
    for (cnt1_1 = 0; cnt1_1 < nbre_files; cnt1_1++)
    {
        cnt2_1 = 0;
        cnt1_2 = cnt1_1;
        cur_dir = &dirs[cnt1_2];
        for (; cnt2_2 = cnt2_1, cnt2_2 < strlen(cur_dir->name); cnt2_1++)
            sum += (u8) cur_dir->name[cnt2_2] << cnt1_2;
    }
    return sum;
}

/* returns u8 instead? see SaveGameOnDisk and betw1 var */
/*INCLUDE_ASM("asm/nonmatchings/card", PS1_WriteSave);*/

s32 PS1_WriteSave(u8 chan_par, u8 slot_par)
{
  u8 *pbVar1;
  int event_res;
  long fd;
  s32 betw1;
  s32 betw2;
  int cnt;
  s32 betw3;
  s32 *frame_from;
  s32 *frame_to;
  u8 *devname;
  uint chan_local;
  uint slot_local;
  s32 saveicon1 [32];
  s32 saveicon2and3 [32];
  s32 saveiconpalette[8];
  s32 local_c0;
  s32 local_bc;
  s32 local_b8;
  s32 local_b4;
  s32 local_b0;
  s32 local_ac;
  s32 local_a8;
  s32 local_a4;
  CardFrame0 card_frame0;
  u8 local_20;
  u8 test_1[8];
  u8 *test_2;
  const u8 *new_var;

  new_var = PS1_SaveIconPalette;
  test_2 = test_1;
  if (((s32) test_2 | (s32) PS1_SaveIcon1) & 3) {
    __builtin_memcpy(saveicon1, PS1_SaveIcon1, sizeof(PS1_SaveIcon1));
  }
  else {
    __builtin_memcpy(saveicon1, PS1_SaveIcon1, sizeof(PS1_SaveIcon1));
  }
  frame_to = saveicon2and3;
  frame_from = PS1_SaveIcon2and3;
  if (((s32) test_2 | (s32) PS1_SaveIcon2and3) & 3) {
    __builtin_memcpy(saveicon2and3, PS1_SaveIcon2and3, sizeof(PS1_SaveIcon2and3));
  }
  else {
    __builtin_memcpy(saveicon2and3, PS1_SaveIcon2and3, sizeof(PS1_SaveIcon2and3));
  }

  __builtin_memcpy(saveiconpalette, new_var, sizeof(PS1_SaveIconPalette));
  chan_local = (uint)chan_par;
  _card_info(chan_local);
  event_res = PS1_TestSwCARD();
  if (event_res - 1U >= 2) {
    if (event_res == 3) {
      PS1_TestHwCARDOnce();
      _card_clear(chan_local);
      PS1_TestHwCARD();
    }
    slot_local = slot_par & 0xff;
    PS1_TestSwCARDOnce();
    _card_load(chan_local);
    PS1_TestSwCARD();
    FntPrint(s__Saving_file_8012add8);
    devname = &D_801F6100[slot_local * 0x20];
    if (*devname == 0) {
      sprintf(devname,s_bu02xss4u_8012ade8,chan_local,s_BISLUS00005_8012aca8,save_ray[slot_local],
              (uint)(ushort)PS1_GlobalTimer);
    }
    fd = open(devname,0x10200);
    if (fd != -1) {
      PS1_WriteWiSaveZone();
      event_res = slot_local - 1;
      loadInfoRay[event_res].num_cages = 0;
      cnt = 0;
      do {
        pbVar1 = wi_save_zone + cnt;
        cnt = cnt + 1;
        loadInfoRay[event_res].num_cages = loadInfoRay[event_res].num_cages + (*pbVar1 >> 2 & 7);
      } while (cnt < 24);
      chan_local = (uint)loadInfoRay[(slot_par & 0xff) - 1].num_cages * 100;
      card_frame0.sc_magic[0] = 'S';
      card_frame0.sc_magic[1] = 'C';
      card_frame0.icon_display_flag = 0x13;
      card_frame0.block_num = 1;
      sprintf(card_frame0.Rayman_save_ray_pct,s_Rayman_s_03d_8012adf8,save_ray[slot_par & 0xff],
              (int)(short)(chan_local / 102));
      strncpy(card_frame0.Maga,s_Maga_801cf050,0x1c);
      __builtin_memcpy(card_frame0.icon_palette, saveiconpalette, sizeof(saveiconpalette));
      write(fd,&card_frame0,0x80);
      write(fd,saveicon1,0x80);
      write(fd,saveicon2and3,0x80);
      write(fd,saveicon2and3,0x80);
      write(fd,&nb_continue,0x80);
      write(fd,wi_save_zone,0x80);
      write(fd,&RayEvts,0x80);
      write(fd,&poing,0x80);
      write(fd,&status_bar,0x80);
      write(fd,&ray.hit_points,0x80);
      write(fd,save_zone,0xa80);
      write(fd,bonus_perfect,0x80);
      write(fd,&options_jeu,0x80);
      if (dans_la_map_monde) {
        write(fd,&num_world_choice,0x80);
        write(fd,&xmap,0x80);
        write(fd,&ymap,0x80);
        local_20 = (u8)(ray.flags >> 0xe) & 1;
        write(fd,&local_20,0x80);
      }
      else {
        write(fd,&world_index,0x80);
        write(fd,&xwldmapsave,0x80);
        write(fd,&ywldmapsave,0x80);
        write(fd,&dir_on_wldmap,0x80);
      }
      write(fd,finBosslevel,0x80);
      close(fd);
      CHANGE_STAGE_NAMES();
      PS1_Checksum = PS1_CardFilenameChecksum(chan_par);
      betw1 = 1;
    }
    else {
      FntPrint(s__Cant_open_file_8012ae0c);
      betw1 = 0xfd;
    }
  }
  else {
    FntPrint(s__Cannot_create_file_8012ae20);
    betw1 = 0xfc;
  }
  return betw1;
}

/* matches, but second counter/gross loop */
/*INCLUDE_ASM("asm/nonmatchings/card", SaveFileRead);*/

s32 SaveFileRead(s32 fd, void *buf, s16 n)
{
  s32 num_read;
  s32 cnt_1 = 0;
  u8 cnt_2;
  
  while (true)
  {
    num_read = (s16) read(fd, buf, n);
    cnt_2 = cnt_1;
    if (num_read != -1 || cnt_2 >= 10)
      break;
    cnt_1++;
  }
  return num_read;
}

/*
matches, but options_jeu is not very clean
write the others as memcpys also...
*/
/*INCLUDE_ASM("asm/nonmatchings/card", PS1_LoadSave);*/

void PS1_LoadSave(s32 param_1, u8 *param_2)
{
    s32 file = open(param_2, 1);
    u8 file_buffer[128];
    
    if (file != -1)
    {
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        nb_continue = file_buffer[0];
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&wi_save_zone, file_buffer, sizeof(wi_save_zone));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&RayEvts, file_buffer, sizeof(RayEvts));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&poing, file_buffer, sizeof(poing));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&status_bar, file_buffer, sizeof(status_bar));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        ray.hit_points = file_buffer[0];
        SaveFileRead(file, save_zone, sizeof(save_zone));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(bonus_perfect, file_buffer, sizeof(bonus_perfect));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        /*__builtin_memcpy(&options_jeu.Jump, &fileBuffer[16], 22);*/
        /* also tried assigning to another local with OptionsJeu * or u16 * type beforehand */
        options_jeu.Jump = *(u16 *)(file_buffer + 16);
        options_jeu.Fist = *(u16 *)(file_buffer + 18);
        options_jeu.field6_0x14 = *(u16 *)(file_buffer + 20);
        options_jeu.Action = *(u16 *)(file_buffer + 22);
        options_jeu.Music = *(u16 *)(file_buffer + 24);
        options_jeu.Soundfx = *(u16 *)(file_buffer + 26);
        options_jeu.StereoEnabled = *(u16 *)(file_buffer + 28);
        options_jeu.field11_0x1e = *(u16 *)(file_buffer + 30);
        options_jeu.field12_0x20 = *(u16 *)(file_buffer + 32);
        options_jeu.field13_0x22 = *(u16 *)(file_buffer + 34);
        options_jeu.field14_0x24 = *(u16 *)(file_buffer + 36);
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        world_index = file_buffer[0];
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&xwldmapsave, file_buffer, sizeof(xwldmapsave));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&ywldmapsave, file_buffer, sizeof(ywldmapsave));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        dir_on_wldmap = file_buffer[0];
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(finBosslevel, file_buffer, sizeof(finBosslevel));
        close(file);
        PS1_LoadWiSaveZone();
        POINTEUR_BOUTONS_OPTIONS_BIS();
    }
    else
        FntPrint(s__Cant_open_file_8012ae0c);
}