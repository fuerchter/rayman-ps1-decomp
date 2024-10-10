#ifndef PASSWORD_H
#define PASSWORD_H

#include "common.h"
#include "num_level_36260.h"

typedef struct PasswordTables
{
    u8 xor_table[10];
    u8 verification_table[10];
    u8 display_table[32];
    u8 translate_table[32];
    u8 temp_cage_counts[18];
} PasswordTables;

/* .data */
extern PasswordTables PS1_PasswordTables;

/* .data */
extern u8 PS1_IsPasswordValid;
extern u8 s_ok_801cf108[5];
extern u8 s_s_801cf110[5];

/**/
extern u8 PS1_ShouldClearPassword; /* don't understand its use in FUN_8019ebc0 */
extern u8 PS1_CurrentPassword[10];
extern u8 PS1_CurrentTypingPassword[10];
extern s16 D_801E4E40;
extern s16 D_801E4E48;
extern u8 D_801E57A8;
extern u8 PS1_ValidPassword;

void PS1_EncryptPassword(void);
s32 PS1_VerifyDecryptPassword(void);
void FUN_801a17c8(u8 arg0);
u8 PS1_GetLevelFromPassword(void);
void PS1_GeneratePassword_LivesCount(u8 lives_count);
u8 PS1_GetLivesFromPassword(void);
void PS1_GeneratePassword_nbContinue(u8 param_1);
u8 PS1_GetContinuesFromPassword(void);
u8 PS1_ValidatePassword(void);
u8 PS1_GeneratePassword(void);
void PS1_LoadSaveFromPassword(void);
u8 PS1_AttemptLoadSaveFromPassword(void);
void PS1_UnusedGenerateAndPrintPassword(s16 param_1, s16 param_2, u8 param_3, u8 param_4);
void PS1_ClearPassword(void);
void FUN_801a2c78(void);
void FUN_801a2d40(void);
void FUN_801a3064(void);
s16 PS1_MenuPassword(void);
void FUN_801a3550(void);
void PS1_GenerateAndDisplayPassword(void);
void DEPART_INIT_LOOP(void);

#endif