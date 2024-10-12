#include "card.h"

/*
matches, but
inline with 0x4b
assigning char pointers to (s32 *)
do{}while();
*/
/*INCLUDE_ASM("asm/nonmatchings/card", PS1_GetNbreFiles);*/

extern inline u8 test_lt()
{
    return 0x4b;
}

s32 PS1_GetNbreFiles(u8 *name_start, struct DIRENTRY *file)
{
    u8 sp10[128]; /* size correct? */
    s32 temp_v1;
    s32 var_a2_1;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_s1;
    s32 var_v0;
    struct DIRENTRY *var_a3_1;
    struct DIRENTRY *var_a3_2;
    struct DIRENTRY *var_s0;
    u16 test_1;
    s32 test_3;
    s32 *test_4;
    u32 test_5;

    strcpy(sp10, name_start);
    strcat(sp10, s__801cf02c);
    
    switch (PS1_TestCard(0))
    {
    case 0:
        test_4 = s_no_card_801cf030;
        var_a3_1 = file;
        var_a2_1 = 0;
        do
        {
            __builtin_memcpy(var_a3_1->name, test_4, sizeof(s_no_card_801cf030));
            var_a3_1 += 1;
            var_a2_1 += 5;
        } while (var_a2_1 < test_lt());
      
        return 0x0000000F;
    case 1:
        test_4 = s_unformat_8012ac78;
        var_a3_1 = file;
        var_a2_1 = 0;
        do
        {
            __builtin_memcpy(var_a3_1->name, test_4, sizeof(s_unformat_8012ac78));
            var_a3_1 += 1;
            var_a2_1 += 5;
        } while (var_a2_1 < test_lt());
        
        return 0x0000000F;
    case -1:
        var_a3_1 = file;
        var_a2_1 = 0;
        do
        {
            __builtin_memcpy(var_a3_1->name, s_error_801cf038, sizeof(s_error_801cf038));
            var_a3_1 += 1;
            var_a2_1 += 5;
        } while (var_a2_1 < test_lt());

        return 0x0000000F;
    default:
        var_v0 = 0;
        if (firstfile(sp10, file) == file)
        {
            do
            {
                var_v0 += 1;
                file += 1;
            } while (nextfile(file) == file);
        }
        return var_v0;
    }
}

s32 PS1_GetNbreFiles(u8 *name_start, struct DIRENTRY *file)
{
    u8 sp10[128]; /* size correct? */
    s32 temp_v1;
    u8 *var_a2_1;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_s1;
    s32 var_v0;
    struct DIRENTRY *var_a3_1;
    struct DIRENTRY *var_a3_2;
    struct DIRENTRY *var_s0;
    u16 test_1;

    strcpy(sp10, name_start);
    strcat(sp10, s__801cf02c);
    
    switch (PS1_TestCard(0))
    {
    case 0:
        /*
        15 * 5
        tried rewriting as for()
        tried rewriting as var_a3_1 != &file[15]
        checked in debugger
        */
        var_a3_1 = file;
        var_a2_1 = 0;
        while (var_a2_1 < 0x4b)
        {
            __builtin_memcpy(var_a3_1->name, s_no_card_801cf030, sizeof(s_no_card_801cf030));
            var_a3_1 += 1;
            var_a2_1 += 5;
        }
      
        return 0x0000000F;
    case 1:
        var_a3_1 = file;
        var_a2_1 = 0;
        while (var_a2_1 < 0x4b)
        {
            __builtin_memcpy(var_a3_1->name, s_unformat_8012ac78, sizeof(s_unformat_8012ac78));
            var_a3_1 += 1;
            var_a2_1 += 5;
        }
        
        return 0x0000000F;
        break;
    case -1:
        var_a3_1 = file;
        var_a2_1 = 0;
        while (var_a2_1 < 0x4b)
        {
            __builtin_memcpy(var_a3_1->name, s_error_801cf038, sizeof(s_error_801cf038));
            var_a3_1 += 1;
            var_a2_1 += 5;
        }
        return 0x0000000F;
    default:
        var_v0 = 0;
        if (firstfile(sp10, file) == file)
        {
            do
            {
                var_v0 += 1;
                file += 1;
            } while (nextfile(file) == file);
        }
        return var_v0;
    }
}

/* matches, but doubled cnt1... */
/*INCLUDE_ASM("asm/nonmatchings/card", PS1_CardFilenameChecksum);*/

s32 PS1_CardFilenameChecksum(u8 chan)
{
    struct DIRENTRY files[15];
    u8 name_start[8];
    s32 nbre_files;
    u8 cnt1_1; s32 cnt1_2;
    u8 cnt2;
    struct DIRENTRY *cur_file;
    s32 sum = 0;

    sprintf(name_start, s_bu02x_801cf040, chan);
    nbre_files = PS1_GetNbreFiles(name_start, files);
    for (cnt1_1 = 0; cnt1_1 < nbre_files; cnt1_1++)
    {
        cnt2 = 0;
        cnt1_2 = cnt1_1;
        cur_file = &files[cnt1_2];
        for (; cnt2 < (u32) strlen(cur_file->name); cnt2++)
            sum += (u8) cur_file->name[cnt2] << cnt1_2;
    }
    return sum;
}

/*
score of 985
returns u8 instead? see SaveGameOnDisk and betw1 var
*/
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
  s32 chan_local;
  s32 slot_local;
  u8 test_4[32];
  u8 saveicon1 [128];
  u8 saveicon2and3 [128];
  u8 saveiconpalette[32];
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
  u8 *test_2;
  u8 *new_var;
  s32 test_3;

  new_var = PS1_SaveIcon1;
  __builtin_memcpy(saveicon1, new_var, sizeof(PS1_SaveIcon1));
  new_var = PS1_SaveIcon2and3;
  __builtin_memcpy(saveicon2and3, new_var, sizeof(PS1_SaveIcon2and3));
  new_var = PS1_SaveIconPalette;
  __builtin_memcpy(saveiconpalette, new_var, sizeof(PS1_SaveIconPalette));
  _card_info(chan_par);
  event_res = PS1_TestSwCARD();
  if (event_res - 1U >= 2) {
    if (event_res == 3) {
      PS1_TestHwCARDOnce();
      _card_clear(chan_par);
      PS1_TestHwCARD();
    }
    PS1_TestSwCARDOnce();
    _card_load(chan_par);
    PS1_TestSwCARD();
    FntPrint(s__Saving_file_8012add8);
    devname = &PS1_SaveFilenames[slot_par - 1][0];
    if (devname[0] == 0) {
      sprintf(devname,s_bu02xss4u_8012ade8,chan_par,s_BISLUS00005_8012aca8,save_ray[slot_par],
              (ushort)PS1_GlobalTimer);
    }
    fd = open(devname,0x10200);
    if (fd != -1) {
      PS1_WriteWiSaveZone();
      loadInfoRay[slot_par - 1].num_cages = 0;
      cnt = 0;
      do {
        loadInfoRay[slot_par - 1].num_cages = loadInfoRay[slot_par - 1].num_cages + (wi_save_zone[cnt] >> 2 & 7);
        cnt = cnt + 1;
      } while (cnt < 24);
      chan_local = loadInfoRay[slot_par - 1].num_cages * 100;
      card_frame0.sc_magic[0] = 'S';
      card_frame0.sc_magic[1] = 'C';
      card_frame0.icon_display_flag = 0x13;
      card_frame0.block_num = 1;
      sprintf(card_frame0.Rayman_save_ray_pct,s_Rayman_s_03d_8012adf8,save_ray[slot_par],
              (short)(chan_local / 102));
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

/* matches, but options_jeu as memcpy somehow? */
/*INCLUDE_ASM("asm/nonmatchings/card", PS1_LoadSave);*/

void PS1_LoadSave(s32 param_1, u8 *param_2)
{
    s32 file = open(param_2, 1);
    u16 file_buffer[64];
    
    if (file != -1)
    {
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&nb_continue, file_buffer, sizeof(nb_continue));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&wi_save_zone, file_buffer, sizeof(wi_save_zone));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&RayEvts, file_buffer, sizeof(RayEvts));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&poing, file_buffer, sizeof(poing));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&status_bar, file_buffer, sizeof(status_bar));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&ray.hit_points, file_buffer, sizeof(ray.hit_points));
        SaveFileRead(file, save_zone, sizeof(save_zone));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(bonus_perfect, file_buffer, sizeof(bonus_perfect));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        /*__builtin_memcpy(&options_jeu.Jump, &file_buffer[8], 22);*/
        /* also tried assigning to another local with OptionsJeu * or u16 * type beforehand */
        options_jeu.Jump = file_buffer[8];
        options_jeu.Fist = file_buffer[9];
        options_jeu.field6_0x14 = file_buffer[10];
        options_jeu.Action = file_buffer[11];
        options_jeu.Music = file_buffer[12];
        options_jeu.Soundfx = file_buffer[13];
        options_jeu.StereoEnabled = file_buffer[14];
        options_jeu.field11_0x1e = file_buffer[15];
        options_jeu.field12_0x20 = file_buffer[16];
        options_jeu.field13_0x22 = file_buffer[17];
        options_jeu.field14_0x24 = file_buffer[18];
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&world_index, file_buffer, sizeof(world_index));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&xwldmapsave, file_buffer, sizeof(xwldmapsave));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&ywldmapsave, file_buffer, sizeof(ywldmapsave));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(&dir_on_wldmap, file_buffer, sizeof(dir_on_wldmap));
        SaveFileRead(file, file_buffer, sizeof(file_buffer));
        __builtin_memcpy(finBosslevel, file_buffer, sizeof(finBosslevel));
        close(file);
        PS1_LoadWiSaveZone();
        POINTEUR_BOUTONS_OPTIONS_BIS();
    }
    else
        FntPrint(s__Cant_open_file_8012ae0c);
}