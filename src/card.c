#include "card.h"

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
const u8 PS1_SaveIcon1[] =
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
const u8 PS1_SaveIcon2and3[] =
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
const u8 PS1_SaveIconPalette[] =
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

/* .data */
extern s32 D_801CF01C;
extern s32 D_801CF020;
extern u8 s_Error_801cf024[7];
extern u8 s__801cf02c[2];
extern u8 s_no_card_801cf030[8];
extern u8 s_error_801cf038[6];
extern u8 s_bu02x_801cf040[8];
extern u8 s__Done_801cf048[7];

/**/
extern u8 D_801F7F08[34];
extern u8 PS1_PadRecieveBuffer[34];
extern s32 PS1_SwCARD_EvSpERROR;
extern s32 PS1_SwCARD_EvSpIOE;
extern s32 PS1_SwCARD_EvSpNEW;
extern s32 PS1_SwCARD_EvSpTIMOUT;
extern s32 PS1_HwCARD_EvSpERROR;
extern s32 PS1_HwCARD_EvSpIOE;
extern s32 PS1_HwCARD_EvSpNEW;
extern s32 PS1_HwCARD_EvSpTIMOUT;
extern s32 PS1_Checksum;

/* 45A7C 8016A27C -O2 -msoft-float */
u8 PS1_InitPAD(void)
{
    InitPAD(PS1_PadRecieveBuffer, D_801CF01C, D_801F7F08, D_801CF020);
    VSync(0);
    VSync(0);
    VSync(0);
    VSync(0);
    return PS1_PadRecieveBuffer[0] == 0 && PS1_PadRecieveBuffer[1] == 0x41;
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
/* have not had any luck. start from gotos-only? */

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

INCLUDE_ASM("asm/nonmatchings/card", PS1_InitSaveRayAndFilenames);

INCLUDE_ASM("asm/nonmatchings/card", PS1_WriteSave);

INCLUDE_ASM("asm/nonmatchings/card", FUN_8016b2e8);

INCLUDE_ASM("asm/nonmatchings/card", SaveGameOnDisk);

INCLUDE_ASM("asm/nonmatchings/card", SaveFileRead);

INCLUDE_ASM("asm/nonmatchings/card", PS1_LoadSave);

INCLUDE_ASM("asm/nonmatchings/card", LoadGameOnDisk);

INCLUDE_ASM("asm/nonmatchings/card", LoadInfoGame);

INCLUDE_ASM("asm/nonmatchings/card", FUN_8016bbe4);

INCLUDE_ASM("asm/nonmatchings/card", PS1_GetNbreSave3);

INCLUDE_ASM("asm/nonmatchings/card", PS1_CardFilenameChecksumChanged);

INCLUDE_ASM("asm/nonmatchings/card", PS1_TestCardZero);

INCLUDE_ASM("asm/nonmatchings/card", PS1_CardUnformatted);

INCLUDE_ASM("asm/nonmatchings/card", PS1_GetNbreSave2);

INCLUDE_ASM("asm/nonmatchings/card", FUN_8016be9c);

INCLUDE_ASM("asm/nonmatchings/card", FUN_8016bec0);

/*INCLUDE_RODATA("asm/nonmatchings/card", s__Testing_memory_card_in_slot_d_8012ac14);

INCLUDE_RODATA("asm/nonmatchings/card", s_Card_exist_8012ac38);

INCLUDE_RODATA("asm/nonmatchings/card", s_No_card_8012ac44);

INCLUDE_RODATA("asm/nonmatchings/card", s_New_card_8012ac50);

INCLUDE_RODATA("asm/nonmatchings/card", s_Formatted_8012ac5c);

INCLUDE_RODATA("asm/nonmatchings/card", s_Unformatted_8012ac68);

INCLUDE_RODATA("asm/nonmatchings/card", s_unformat_8012ac78);

INCLUDE_RODATA("asm/nonmatchings/card", s__FORMATING_8012ac84);

INCLUDE_RODATA("asm/nonmatchings/card", s__Error_in_formatting_8012ac90);

INCLUDE_RODATA("asm/nonmatchings/card", s_BISLUS00005_8012aca8);

INCLUDE_RODATA("asm/nonmatchings/card", PS1_SaveIcon1);

INCLUDE_RODATA("asm/nonmatchings/card", PS1_SaveIcon2and3);

INCLUDE_RODATA("asm/nonmatchings/card", PS1_SaveIconPalette);

INCLUDE_RODATA("asm/nonmatchings/card", s__Saving_file_8012add8);

INCLUDE_RODATA("asm/nonmatchings/card", s_bu02xss4u_8012ade8);

INCLUDE_RODATA("asm/nonmatchings/card", s_Rayman_s_03d_8012adf8);

INCLUDE_RODATA("asm/nonmatchings/card", s__Cant_open_file_8012ae0c);

INCLUDE_RODATA("asm/nonmatchings/card", s__Cannot_create_file_8012ae20);

INCLUDE_RODATA("asm/nonmatchings/card", s_bu02xss_8012ae38);
*/