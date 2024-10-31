#include "card.h"

/* TODO:
(only once strncmp is declared)
warning: passing arg 2 of `strncmp' discards `const' from pointer target type
in functions:
PS1_InitSaveRayAndFilenames
FUN_8016b2e8

change "s_BISLUS00005_8012aca8, 12" in strncmps to use sizeof instead?
*/

const u8 s__Testing_memory_card_in_slot_d_8012ac14[] = "\nTesting memory card in slot %d\n\n";
const u8 s_Card_exist_8012ac38[] = "Card exist\n";
const u8 s_No_card_8012ac44[] = "No card\n";
const u8 s_New_card_8012ac50[] = "New card\n";
const u8 s_Formatted_8012ac5c[] = "Formatted\n";
const u8 s_Unformatted_8012ac68[] = "Unformatted\n";
const u8 s_unformat_8012ac78[] = "unformat";
const u8 s__FORMATING_8012ac84[] = "\nFORMATING";
const u8 s__Error_in_formatting_8012ac90[] = "\nError in formatting\n";
const u8 s_BISLUS00005_8012aca8[] = "BISLUS-00005";
const u8 PS1_SaveIcon1[] __attribute__((aligned(2))) =
{
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
  0xAA, 0x2A, 0x33, 0xD4, 0xAA, 0xAA, 0xAA, 0x2A, 0x11, 0xB4, 
  0x4B, 0xEB, 0xAA, 0xAA, 0xAA, 0x12, 0xB3, 0xED, 0xBD, 0x24, 
  0xAE, 0xAA, 0xAA, 0x31, 0xAB, 0xAA, 0xDE, 0xBE, 0xE2, 0xAA, 
  0xAA, 0x2A, 0xAB, 0xBA, 0x87, 0xE8, 0xEB, 0xAA, 0xAA, 0xAA, 
  0xAA, 0x0C, 0x58, 0xB5, 0xAE, 0xAA, 0xAA, 0xAA, 0xAA, 0xC0, 
  0xB8, 0x8D, 0xAF, 0xAA, 0xAA, 0xAA, 0xAA, 0xF7, 0x5B, 0xD5, 
  0xAF, 0xAA, 0xAA, 0xAA, 0x5A, 0x53, 0x87, 0xB5, 0xAF, 0xAA, 
  0xAA, 0xAA, 0x33, 0x33, 0x53, 0x8D, 0xAF, 0xAA, 0xAA, 0xAA, 
  0x33, 0x33, 0xB5, 0x89, 0xAF, 0xAA, 0xAA, 0xAA, 0x58, 0x55, 
  0xD8, 0x8B, 0xAF, 0xAA, 0xAA, 0xAA, 0x8A, 0xBB, 0x8B, 0xF8, 
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA
};
const u8 PS1_SaveIcon2and3[] __attribute__((aligned(2))) =
{
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
  0xAA, 0x2A, 0x33, 0xD4, 0xAA, 0xAA, 0xAA, 0x2A, 0x11, 0xB4, 
  0x4B, 0xEB, 0xAA, 0xAA, 0xAA, 0x12, 0xB3, 0xED, 0xBD, 0x24, 
  0xAE, 0xAA, 0xAA, 0x31, 0xAB, 0xAA, 0xBE, 0xBE, 0xE2, 0xAA, 
  0xAA, 0x2A, 0xAB, 0xBA, 0xC7, 0xE7, 0xEB, 0xAA, 0xAA, 0xAA, 
  0xAA, 0x0C, 0x00, 0xC0, 0xAE, 0xAA, 0xAA, 0xAA, 0xAA, 0xC0, 
  0x00, 0x70, 0xAF, 0xAA, 0xAA, 0xAA, 0xAA, 0x7F, 0x0F, 0xC0, 
  0xAF, 0xAA, 0xAA, 0xAA, 0x5A, 0x53, 0x67, 0xBC, 0xAF, 0xAA, 
  0xAA, 0xAA, 0x33, 0x33, 0x53, 0x8B, 0xAF, 0xAA, 0xAA, 0xAA, 
  0x33, 0x33, 0x85, 0x8D, 0xAF, 0xAA, 0xAA, 0xAA, 0x58, 0x55, 
  0xD8, 0x89, 0xAF, 0xAA, 0xAA, 0xAA, 0x8A, 0xBB, 0x8B, 0xF8, 
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA
};
const u8 PS1_SaveIconPalette[] __attribute__((aligned(2))) =
{
  0xFF, 0x7F, 0xFF, 0x63, 0xFD, 0x2A, 0xFC, 0x4E, 0x9B, 0x16, 
  0x59, 0x36, 0x78, 0x7B, 0xF7, 0x7E, 0xF7, 0x29, 0x56, 0x18, 
  0xD6, 0x77, 0x93, 0x1D, 0x72, 0x6E, 0x2F, 0x11, 0xCC, 0x0C, 
  0x00, 0x00
};
const u8 s__Saving_file_8012add8[] = "\nSaving file\n";
const u8 s_bu02xss4u_8012ade8[] = "bu%02x:%s%s%4u";
const u8 s_Rayman_s_03d_8012adf8[] = "Rayman %s %03d%%";
const u8 s__Cant_open_file_8012ae0c[] = "\nCan't open file\n";
const u8 s__Cannot_create_file_8012ae20[] = "\nCannot create file\n";
const u8 s_bu02xss_8012ae38[] = "bu%02x:%s%s";

/* 45A7C 8016A27C -O2 -msoft-float */
s32 PS1_InitPAD(void)
{
    InitPAD(PS1_PadReceiveBuffer, D_801CF01C, D_801F7F08, D_801CF020);
    VSync(0);
    VSync(0);
    VSync(0);
    VSync(0);
    return PS1_PadReceiveBuffer[0] == 0 && PS1_PadReceiveBuffer[1] == 0x41;
}

/* 45B04 8016A304 -O2 -msoft-float */
s32 PS1_TestSwCARD(void)
{
  while (true)
  {
    if (TestEvent(PS1_SwCARD_EvSpIOE) == 1)
      return 0;
    if (TestEvent(PS1_SwCARD_EvSpERROR) == 1)
      return 1;
    if (TestEvent(PS1_SwCARD_EvSpTIMOUT) == 1)
      return 2;
    if (TestEvent(PS1_SwCARD_EvSpNEW) == 1)
      return 3;
  }
}

/* 45B84 8016A384 -O2 -msoft-float */
void PS1_TestSwCARDOnce(void)
{
  TestEvent(PS1_SwCARD_EvSpIOE);
  TestEvent(PS1_SwCARD_EvSpERROR);
  TestEvent(PS1_SwCARD_EvSpTIMOUT);
  TestEvent(PS1_SwCARD_EvSpNEW);
}

/* 45BDC 8016A3DC -O2 -msoft-float */
s32 PS1_TestHwCARD(void)
{
  while (true)
  {
    if (TestEvent(PS1_HwCARD_EvSpIOE) == 1)
      return 0;
    if (TestEvent(PS1_HwCARD_EvSpERROR) == 1)
      return 1;
    if (TestEvent(PS1_HwCARD_EvSpTIMOUT) == 1)
      return 2;
    if (TestEvent(PS1_HwCARD_EvSpNEW) == 1)
      return 3;
  }
}

/* 45C5C 8016A45C -O2 -msoft-float */
void PS1_TestHwCARDOnce(void)
{
  TestEvent(PS1_HwCARD_EvSpIOE);
  TestEvent(PS1_HwCARD_EvSpERROR);
  TestEvent(PS1_HwCARD_EvSpTIMOUT);
  TestEvent(PS1_HwCARD_EvSpNEW);
}

/* 45CB4 8016A4B4 -O2 -msoft-float */
u8 PS1_TestCard(u8 par_chan)
{
    s32 test_res;

    _card_info(par_chan);
    test_res = PS1_TestSwCARD();
    FntPrint(s__Testing_memory_card_in_slot_d_8012ac14, par_chan >> 4);
    switch (test_res)
    {
    case 2:
        FntPrint(s_No_card_8012ac44);
        return 0;
    case 0:
    case 3:
        switch (test_res)
        {
        case 0:
            FntPrint(s_Card_exist_8012ac38);
            break;
        case 3:
            FntPrint(s_New_card_8012ac50);
            PS1_TestHwCARDOnce();
            _card_clear(par_chan);
            PS1_TestHwCARD();
            break;
        }
        PS1_TestSwCARDOnce();
        _card_load(par_chan);
        test_res = PS1_TestSwCARD();
        switch (test_res)
        {
        case 0:
            FntPrint(s_Formatted_8012ac5c);
            return 2;
        case 2:
            FntPrint(s_No_card_8012ac44);
            return 0;
        case 3:
            FntPrint(s_Unformatted_8012ac68);
            return 1;
        default:
            FntPrint(s_Error_801cf024);
            return 0xFF;
        }
        break;
    default:
        FntPrint(s_Error_801cf024);
        return 0xFF;
    }
}

INCLUDE_ASM("asm/nonmatchings/card", PS1_GetNbreFiles);

INCLUDE_ASM("asm/nonmatchings/card", PS1_CardFilenameChecksum);

/* 4607C 8016A87C -O2 -msoft-float */
void PS1_InitializeCard(u8 chan)
{
    EnterCriticalSection();
    PS1_SwCARD_EvSpIOE = OpenEvent(SwCARD, EvSpIOE, EvMdNOINTR, null);
    PS1_SwCARD_EvSpERROR = OpenEvent(SwCARD, EvSpERROR, EvMdNOINTR, null);
    PS1_SwCARD_EvSpTIMOUT = OpenEvent(SwCARD, EvSpTIMOUT, EvMdNOINTR, null);
    PS1_SwCARD_EvSpNEW = OpenEvent(SwCARD, EvSpNEW, EvMdNOINTR, null);
    PS1_HwCARD_EvSpIOE = OpenEvent(HwCARD, EvSpIOE, EvMdNOINTR, null);
    PS1_HwCARD_EvSpERROR = OpenEvent(HwCARD, EvSpERROR, EvMdNOINTR, null);
    PS1_HwCARD_EvSpTIMOUT = OpenEvent(HwCARD, EvSpTIMOUT, EvMdNOINTR, null);
    PS1_HwCARD_EvSpNEW = OpenEvent(HwCARD, EvSpNEW, EvMdNOINTR, null);
    EnableEvent(PS1_SwCARD_EvSpIOE);
    EnableEvent(PS1_SwCARD_EvSpERROR);
    EnableEvent(PS1_SwCARD_EvSpTIMOUT);
    EnableEvent(PS1_SwCARD_EvSpNEW);
    EnableEvent(PS1_HwCARD_EvSpIOE);
    EnableEvent(PS1_HwCARD_EvSpERROR);
    EnableEvent(PS1_HwCARD_EvSpTIMOUT);
    EnableEvent(PS1_HwCARD_EvSpNEW);
    ExitCriticalSection();
    InitCARD(1);
    StartCARD();
    _bu_init();
    _card_auto(1);
    if (PS1_TestCard(chan) == 2)
        PS1_Checksum = PS1_CardFilenameChecksum(chan);
}

/* 46270 8016AA70 -O2 -msoft-float */
u8 PS1_FormatFs(u8 param_1)
{
  u8 fs[8];
  
  FntPrint(s__FORMATING_8012ac84);
  sprintf(fs, s_bu02x_801cf040, param_1);
  if (format(fs) == 1)
  {
    FntPrint(s__Done_801cf048);
    return 0;
  }
  else
  {
    FntPrint(s__Error_in_formatting_8012ac90);
    return 0xFF;
  }
}

/* 462F4 8016AAF4 -O2 -msoft-float */
void PS1_InitSaveRayAndFilenames(u8 param_1)
{
    struct DIRENTRY files[15];
    struct DIRENTRY *cur_file;
    u8 name_start[8];
    s32 nbre_files;
    u8 cnt1;
    u8 cnt2 = 0;
    
    sprintf(name_start, s_bu02x_801cf040, param_1);
    nbre_files = PS1_GetNbreFiles(name_start, files);
    for (cnt1 = 0; cnt1 < nbre_files; cnt1++)
    {
        cur_file = &files[cnt1];
        if (strncmp(cur_file->name, s_BISLUS00005_8012aca8, 12) == 0)
        {
            strncpy(save_ray[cnt2 + 1], &cur_file->name[12], 3);
            strncpy(&PS1_SaveFilenames[cnt2][0], name_start, 6);
            strncpy(&PS1_SaveFilenames[cnt2][5], cur_file->name, 21);
            cnt2++;
            if (cnt2 > 2)
                break;
        }
    }
    for (; cnt1 = cnt2, cnt2 < 3; cnt2++)
        *PS1_SaveFilenames[cnt2] = *save_ray[cnt2 + 1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/card", PS1_WriteSave);

/* 46AE8 8016B2E8 -O2 -msoft-float */
u8 *FUN_8016b2e8(u8 param_1, u8 param_2, u8 *param_3)
{
  struct DIRENTRY files[15];
  struct DIRENTRY *cur_file;
  u8 name_start[8];
  s32 nbre_files;
  u8 cnt1;
  u8 cnt2 = 0;

  sprintf(name_start, s_bu02x_801cf040, param_1);
  nbre_files = PS1_GetNbreFiles(name_start, files);
  for (cnt1 = 0; cnt1 < nbre_files; cnt1++)
  {
    cur_file = &files[cnt1];
    if (strncmp(cur_file->name, s_BISLUS00005_8012aca8, 12) == 0)
    {
      cnt2++;
      if (cnt2 == param_2)
      {
        sprintf(param_3, s_bu02xss_8012ae38, param_1, s_BISLUS00005_8012aca8, &cur_file->name[12]);
        return param_3;
      }
    }
  }
  return null;
}

/* 46BFC 8016B3FC -O2 -msoft-float */
s32 SaveGameOnDisk(u8 slot)
{
    u8 filename[32];
    s32 res = NBRE_SAVE;

    if (res != 0)
    {
        PS1_CheckCardChanged();
        strcpy(filename, PS1_SaveFilenames[slot - 1]);
        if (filename[0] != '\0')
            delete(&filename);
        strncpy(&PS1_SaveFilenames[slot - 1][17], save_ray[slot], 3);
        res = (u8) PS1_WriteSave(0, slot);
    }
    return res;
}

/* 46CA0 8016B4A0 -O2 -msoft-float */
s32 SaveFileRead(s32 fd, void *buf, s16 n)
{
    s16 num_read;
    u8 i = 0;

    do
    {
        num_read = read(fd, buf, n);
    } while (num_read == -1 && i++ < 10);
    return num_read;
}

INCLUDE_ASM("asm/nonmatchings/card", PS1_LoadSave);

/* 470E4 8016B8E4 -O2 -msoft-float */
void LoadGameOnDisk(u8 slot)
{
  if (NBRE_SAVE != 0)
  {
    PS1_CheckCardChanged();
    PS1_LoadSave(0, PS1_SaveFilenames[slot - 1]);
  }
}

/* 47134 8016B934 -O2 -msoft-float */
s32 LoadInfoGame(u8 slot)
{
    u8 unk_1[32];
    s32 file = open(PS1_SaveFilenames[slot - 1], O_RDONLY); /* TODO: slot - 1 macro? */
    u8 file_buffer[128];
    s32 i;

    if (file == -1)
        return 1;
    else
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
        close(file);

        loadInfoRay[slot - 1].num_continues = nb_continue;
        loadInfoRay[slot - 1].num_cages = 0;
        for (i = 0; i < 24; i++)
            loadInfoRay[slot - 1].num_cages += wi_save_zone[i].nb_cages;
        loadInfoRay[slot - 1].num_lives = status_bar.num_lives;
        loadInfoRay[slot - 1].num_wiz = status_bar.num_wiz;
        return 0;
    }
}

/* 473E4 8016BBE4 -O2 -msoft-float */
void FUN_8016bbe4(void)
{
    u8 *filename;

    if (NBRE_SAVE != 0)
    {
        PS1_CheckCardChanged();
        filename = PS1_SaveFilenames[fichier_selectionne - 1];
        if (filename[0] != '\0')
            delete(filename);
        PS1_Checksum = PS1_CardFilenameChecksum(0);
        *save_ray[fichier_selectionne] = '\0';
        *PS1_SaveFilenames[fichier_selectionne - 1] = '\0';
    }
}

/* 47488 8016BC88 -O2 -msoft-float */
u8 PS1_GetNbreSave3(u8 param_1)
{
  u8 saves_found = 0;
  u8 blocks_used = 0;
  s32 nbre_files;
  struct DIRENTRY files[15];
  u8 name_start[8];
  u8 i;
  u8 buf[128];
  u8 dev_name[32];
  s32 fd;
  u8 res;

  sprintf(name_start, s_bu02x_801cf040, param_1);
  nbre_files = PS1_GetNbreFiles(name_start, files);
  for (i = 0; i < nbre_files; i++)
  {
    sprintf(dev_name, s_ss_801cf058, name_start, files[i].name);
    fd = open(dev_name, O_RDONLY);
    SaveFileRead(fd, buf, sizeof(buf));
    blocks_used += buf[3];
    close(fd);
    if (strncmp(files[i].name, s_BISLUS00005_8012aca8, 12) == 0)
      saves_found++;
  }
  res = saves_found - (u8) (blocks_used - 15); /* underflow? couldn't retype */
  MIN_2(res, 3);
  return res;
}

/* 475C4 8016BDC4 -O2 -msoft-float */
s32 PS1_CardFilenameChecksumChanged(void)
{
  return PS1_Checksum != PS1_CardFilenameChecksum(0);
}

/* 475F4 8016BDF4 -O2 -msoft-float */
s32 PS1_TestCardZero(void)
{
  return PS1_TestCard(0) == 0;
}

/* 47618 8016BE18 -O2 -msoft-float */
s16 PS1_CardUnformatted(void)
{
  s32 unk_1 = true; /* least ugly permuter suggestion imo */
  if (unk_1 && PS1_TestCard(0) != 2)
  {
    VSync(0);
    VSync(0);
    VSync(0);
    return PS1_TestCard(0) != 2;
  }
  else
    return false;
}

/* 4767C 8016BE7C -O2 -msoft-float */
u8 PS1_GetNbreSave2(void)
{
  return PS1_GetNbreSave3(0);
}

/* 4769C 8016BE9C -O2 -msoft-float */
s32 FUN_8016be9c(void)
{
  return (s16) PS1_CardFilenameChecksumChanged();
}

/* 476C0 8016BEC0 -O2 -msoft-float */
void FUN_8016bec0(void)
{
  PS1_FormatFs(0);
  PS1_Checksum = PS1_CardFilenameChecksum(0);
}