#ifndef PASSWORD_H
#define PASSWORD_H

#include "common.h"
#include "num_level_36260.h"

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
s32 FUN_801a3458(void);
void FUN_801a3550(void);
void PS1_GenerateAndDisplayPassword(void);
void DEPART_INIT_LOOP(void);

#endif