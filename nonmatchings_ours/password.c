#include "password.h"

/* inlines should also be extern? https://gcc.gnu.org/onlinedocs/gcc/Inline.html */

/* matches, but surely wrong */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_EncryptPassword);*/

inline int inline_fn(u8 arg0, int arg1, int arg2)
{
    return (arg0 & arg1) | arg2;
}

void PS1_EncryptPassword(void)
{
    uint uVar1;
    u8 bVar3;
    u16 uVar4;
    uint uVar2;

    uVar4 = 0;
    bVar3 = 0;
    while (bVar3 < 10)
    {
        PS1_CurrentPassword[bVar3] ^= PS1_PasswordXORTable[bVar3];
        uVar4 = uVar4 + ((PS1_CurrentPassword[bVar3] >> 1) * PS1_PasswordVerificationTable[bVar3]);
        bVar3 = bVar3 + 1;
    }

    uVar1 = PS1_CurrentPassword[9];
    PS1_CurrentPassword[9] = inline_fn(uVar1, 0xfe, (uVar4 >> 0) & 1);
    PS1_CurrentPassword[7] = inline_fn(PS1_CurrentPassword[7], 0xfe, ((uVar4 >> 1)) & 1);
    PS1_CurrentPassword[6] = inline_fn(PS1_CurrentPassword[6], 0xfe, ((uVar4 >> 2)) & 1);
    PS1_CurrentPassword[8] = inline_fn(PS1_CurrentPassword[8], 0xfe, ((uVar4 >> 3)) & 1);
    PS1_CurrentPassword[5] = inline_fn(PS1_CurrentPassword[5], 0xfe, ((uVar4 >> 4)) & 1);
    PS1_CurrentPassword[0] = inline_fn(PS1_CurrentPassword[0], 0xfe, ((uVar4 >> 5)) & 1);
    PS1_CurrentPassword[1] = inline_fn(PS1_CurrentPassword[1], 0xfe, ((uVar4 >> 6)) & 1);
    PS1_CurrentPassword[3] = inline_fn(PS1_CurrentPassword[3], 0xfe, ((uVar4 >> 7)) & 1);
    PS1_CurrentPassword[2] = inline_fn(PS1_CurrentPassword[2], 0xfe, ((uVar4 >> 8)) & 1);
    PS1_CurrentPassword[4] = inline_fn(PS1_CurrentPassword[4], 0xfe, ((uVar4 >> 9)) & 1);
    /*uVar1 = PS1_CurrentPassword[9];
    PS1_CurrentPassword[9] = (uVar1 & 0xfe | (uVar4 >> 0)) & 1;
    PS1_CurrentPassword[7] = (PS1_CurrentPassword[7] & 0xfe | ((uVar4 >> 1))) & 1;
    PS1_CurrentPassword[6] = (PS1_CurrentPassword[6] & 0xfe | ((uVar4 >> 2))) & 1;
    PS1_CurrentPassword[8] = (PS1_CurrentPassword[8] & 0xfe | ((uVar4 >> 3))) & 1;
    PS1_CurrentPassword[5] = (PS1_CurrentPassword[5] & 0xfe | ((uVar4 >> 4))) & 1;
    PS1_CurrentPassword[0] = (PS1_CurrentPassword[0] & 0xfe | ((uVar4 >> 5))) & 1;
    PS1_CurrentPassword[1] = (PS1_CurrentPassword[1] & 0xfe | ((uVar4 >> 6))) & 1;
    PS1_CurrentPassword[3] = (PS1_CurrentPassword[3] & 0xfe | ((uVar4 >> 7))) & 1;
    PS1_CurrentPassword[2] = (PS1_CurrentPassword[2] & 0xfe | ((uVar4 >> 8))) & 1;
    PS1_CurrentPassword[4] = (PS1_CurrentPassword[4] & 0xfe | ((uVar4 >> 9))) & 1;*/
}

/* matches, but ??? still */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_VerifyDecryptPassword);*/

inline int inline_fn(u8 arg0)
{
    return arg0 & 1;
}

s32 PS1_VerifyDecryptPassword(void)
{
    u16 temp_lo;
    u8 var_a2;
    u16 var_t4;
    u16 new_var;
    s32 test_1;

    var_t4 = 0;
    var_a2 = 0;
    do
    {
        var_t4 += (PS1_CurrentPassword[var_a2] >> 1) * PS1_PasswordVerificationTable[var_a2];
        PS1_CurrentPassword[var_a2] ^= PS1_PasswordXORTable[var_a2];
        var_a2 += 1;
    } while (var_a2 < 10);
    
    new_var = inline_fn(PS1_CurrentPassword[9]) << 0;
    test_1 = 
        new_var +
        (inline_fn(PS1_CurrentPassword[7]) << 1) +
        (inline_fn(PS1_CurrentPassword[6]) << 2) +
        (inline_fn(PS1_CurrentPassword[8]) << 3) +
        (inline_fn(PS1_CurrentPassword[5]) << 4) +
        (inline_fn(PS1_CurrentPassword[0]) << 5) +
        (inline_fn(PS1_CurrentPassword[1]) << 6) +
        (inline_fn(PS1_CurrentPassword[3]) << 7) +
        (inline_fn(PS1_CurrentPassword[2]) << 8) +
        (inline_fn(PS1_CurrentPassword[4]) << 9);
    /*new_var = PS1_CurrentPassword[9] & 1 << 0;
    test_1 = 
        new_var +
        (PS1_CurrentPassword[7] & 1 << 1) +
        (PS1_CurrentPassword[6] & 1 << 2) +
        (PS1_CurrentPassword[8] & 1 << 3) +
        (PS1_CurrentPassword[5] & 1 << 4) +
        (PS1_CurrentPassword[0] & 1 << 5) +
        (PS1_CurrentPassword[1] & 1 << 6) +
        (PS1_CurrentPassword[3] & 1 << 7) +
        (PS1_CurrentPassword[2] & 1 << 8) +
        (PS1_CurrentPassword[4] & 1 << 9);*/

    temp_lo = test_1;
    return var_t4 == temp_lo;
}

/* matches, but ... */
/*INCLUDE_ASM("asm/nonmatchings/password", FUN_801a17c8);*/

inline int inline_fn(u32 arg0)
{
    return arg0 & (1 << 2);
}

void FUN_801a17c8(u8 arg0)
{
    PS1_CurrentPassword[4] = (PS1_CurrentPassword[4] & ~(1 << 2)) | ((arg0 & 1) << 2);
    PS1_CurrentPassword[2] = (PS1_CurrentPassword[2] & ~(1 << 2)) | inline_fn(arg0 << 1);
    PS1_CurrentPassword[3] = (PS1_CurrentPassword[3] & ~(1 << 2)) | inline_fn(arg0 >> 0);
    PS1_CurrentPassword[1] = (PS1_CurrentPassword[1] & ~(1 << 2)) | inline_fn(arg0 >> 1);
    PS1_CurrentPassword[0] = (PS1_CurrentPassword[0] & ~(1 << 2)) | inline_fn(arg0 >> 2);
}

/*INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword_LivesCount);*/

extern inline int inline_fn(u32 arg0)
{
    return arg0 & (1 << 3);
}

void PS1_GeneratePassword_LivesCount(u8 lives_count)
{
    int new_var = 7;
    PS1_CurrentPassword[3] = (PS1_CurrentPassword[3] & ~(1 << 3)) | ((lives_count & 1) << 3);
    PS1_CurrentPassword[2] = (PS1_CurrentPassword[2] & ~(1 << 3)) | inline_fn((lives_count << 2));
    PS1_CurrentPassword[5] = (PS1_CurrentPassword[5] & ~(1 << 3)) | inline_fn((lives_count << 1));
    PS1_CurrentPassword[1] = (PS1_CurrentPassword[1] & ~(1 << 3)) | inline_fn(lives_count);
    PS1_CurrentPassword[4] = (PS1_CurrentPassword[4] & ~(1 << 3)) | inline_fn((lives_count >> 1));
    PS1_CurrentPassword[0] = (PS1_CurrentPassword[0] & ~(1 << 3)) | inline_fn((lives_count >> 2));
    PS1_CurrentPassword[new_var] = (PS1_CurrentPassword[new_var] & ~(1 << 3)) | inline_fn((lives_count >> 3));
}

/* matches, but ... */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword_nbContinue);*/

void PS1_GeneratePassword_nbContinue(u8 param_1)
{
    int new_var5;
    int new_var4;
    s32 temp_a0;
    int new_var2;
    int new_var1;

    temp_a0 = param_1;
    PS1_CurrentPassword[5] = (PS1_CurrentPassword[5] & ~(1 << 2)) | ((param_1 & (1 << 0)) << 2);
    new_var1 = (temp_a0 << 1) & (1 << 2);
    PS1_CurrentPassword[7] = (PS1_CurrentPassword[7] & ~(1 << 2)) | new_var1;
    new_var5 = temp_a0 & (1 << 2);
    PS1_CurrentPassword[6] = (PS1_CurrentPassword[6] & ~(1 << 2)) | new_var5;
    new_var4 = ((u8) temp_a0 << 1) & (1 << 4);
    PS1_CurrentPassword[9] = (PS1_CurrentPassword[9] & ~(1 << 4)) | new_var4;
}

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_ValidatePassword);*/

u8 PS1_ValidatePassword(void)
{
    s32 temp_v0;
    u8 var_a0_1;
    u8 var_a0_2;
    u8 var_t5_4;
    s32 var_v0_2;
    u8 var_v0_3;
    u8 var_v0_4;
    u8 var_v0_5;
    s32 var_v0_6;
    u8 var_v0_7;
    u8 var_v1_1;
    u8 var_v1_3;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 var_a1;
    u8 temp_s0;
    u8 *temp_v0_4;
    u8 var_v0_1;
    u8 var_v1_2;

    temp_s0 = PS1_GetLevelFromPassword();
    temp_v0 = (temp_s0) < 0x12U;
    PS1_Password_TempCageCounts[0] = PS1_CurrentPassword[0] >> 1 & 1;
    PS1_Password_TempCageCounts[1] = PS1_CurrentPassword[2] >> 1 & 1;
    PS1_Password_TempCageCounts[2] = PS1_CurrentPassword[4] >> 1 & 1;
    PS1_Password_TempCageCounts[3] = PS1_CurrentPassword[1] >> 1 & 1;
    PS1_Password_TempCageCounts[4] = PS1_CurrentPassword[3] >> 1 & 1;
    PS1_Password_TempCageCounts[5] = PS1_CurrentPassword[5] >> 1 & 1;
    PS1_Password_TempCageCounts[6] = PS1_CurrentPassword[7] >> 1 & 1;
    PS1_Password_TempCageCounts[7] = PS1_CurrentPassword[6] >> 1 & 1;
    PS1_Password_TempCageCounts[8] = PS1_CurrentPassword[8] >> 1 & 1;
    PS1_Password_TempCageCounts[9] = PS1_CurrentPassword[9] >> 1 & 1;
    PS1_Password_TempCageCounts[10] = PS1_CurrentPassword[4] >> 4 & 1;
    PS1_Password_TempCageCounts[11] = PS1_CurrentPassword[0] >> 4 & 1;
    PS1_Password_TempCageCounts[12] = PS1_CurrentPassword[2] >> 4 & 1;
    PS1_Password_TempCageCounts[13] = PS1_CurrentPassword[1] >> 4 & 1;
    PS1_Password_TempCageCounts[14] = PS1_CurrentPassword[5] >> 4 & 1;
    PS1_Password_TempCageCounts[15] = PS1_CurrentPassword[3] >> 4 & 1;
    PS1_Password_TempCageCounts[16] = PS1_CurrentPassword[7] >> 4 & 1;
    PS1_Password_TempCageCounts[17] = PS1_CurrentPassword[6] >> 4 & 1;
    
    var_t5_4 = 0;
    if (temp_v0 != 0)
    {
        if (!(temp_s0 == 2 || temp_s0 == 3))
        {
            var_t5_4 = (temp_s0 == 6 || temp_s0 == 7) ^ 1;
        }
    }

    if (var_t5_4 != 0)
    {
        if ((PS1_GetLivesFromPassword()) < 0x64U)
        {
            if ((PS1_GetContinuesFromPassword()) < 0xAU)
            {
                if (PS1_CurrentPassword[9] & 8)
                {
                    var_t5_4 = 0;
                    if (PS1_CurrentPassword[8] & 4)
                    {
                        var_t5_4 = ((temp_s0) < 4U) ^ 1;
                    }
                }
                else
                {
                    var_t5_4 = (temp_s0) < 9U;
                }
                if (var_t5_4)
                {
                    if (PS1_CurrentPassword[8] & 8)
                    {
                        var_t5_4 = 0;
                        if (PS1_CurrentPassword[9] & 4)
                        {
                            var_t5_4 = ((temp_s0) < 8U) ^ 1;
                        }
                    }

                    if (var_t5_4 != 0)
                    {
                        if (PS1_CurrentPassword[8] & 0x10)
                        {
                            var_t5_4 = (temp_s0 < 0xAU) ^ 1;
                        }
                        else
                        {
                            var_t5_4 = 0;
                            if (temp_s0 < 0xBU)
                            {
                                var_t5_4 = PS1_Password_TempCageCounts[11] == 0;
                            }
                        }
                        if (var_t5_4)
                        {
                            if (PS1_CurrentPassword[6] & 8)
                            {
                                var_t5_4 = 0;
                                if (temp_s0 >= 0x10U)
                                {
                                    if (PS1_CurrentPassword[8] & 0x10)
                                    {
                                        var_t5_4 = ((u8) PS1_CurrentPassword[9] >> 3) & 1;
                                    }
                                }
                            }
                            else
                            {
                                var_t5_4 = 0;
                                if (temp_s0 < 0x11U)
                                {
                                    var_t5_4 = PS1_Password_TempCageCounts[17] == 0;
                                }
                            }

                            if (var_t5_4 != 0)
                            {
                                if (PS1_CurrentPassword[8] & 4)
                                {
                                    var_t5_4 = ((temp_s0) < 4U) ^ 1;
                                }
                                else
                                {
                                    var_t5_4 = 0;
                                    if (PS1_Password_TempCageCounts[3] == 0)
                                    {
                                        var_t5_4 = 8; /* TODO: ??? */
                                        var_t5_4 = (PS1_CurrentPassword[9] & var_t5_4) == 0;
                                    }
                                }
                                if (var_t5_4)
                                {
                                    if (PS1_CurrentPassword[9] & 4)
                                    {
                                        var_t5_4 = ((temp_s0) < 8U) ^ 1;
                                    }
                                    else
                                    {
                                        var_t5_4 = 0;
                                        if (PS1_Password_TempCageCounts[7] == 0)
                                        {
                                            var_t5_4 = 8; /* TODO: ??? */
                                            var_t5_4 = (PS1_CurrentPassword[8] & var_t5_4) == 0;
                                        }
                                    }
                                    if (var_t5_4)
                                    {
                                        if (PS1_Password_TempCageCounts[3] != 0)
                                        {
                                            var_t5_4 = ((u8) PS1_CurrentPassword[8] >> 2) & 1;
                                        }
                                        if (var_t5_4 != 0)
                                        {
                                            
                                            if (PS1_Password_TempCageCounts[7] != 0)
                                            {
                                                if (!(((u8) PS1_CurrentPassword[9] >> 2) & 1))
                                                {
                                                    return 0x0DU;
                                                }
                                            }

                                            
                                            var_v1_1 = 0;
                                            var_a0_1 = temp_s0 + 1;
                                            while (var_a0_1 < 0x12U)
                                            {
                                                var_v1_1 += PS1_Password_TempCageCounts[var_a0_1];
                                                var_a0_1 += 1;
                                            }
                                            var_t5_4 = (var_v1_1) == 0;
                                            if (!(var_t5_4))
                                            {
                                                return 0x0EU;
                                            }
                                            if ((temp_s0) >= 9U)
                                            {
                                                var_t5_4 = 0;
                                                if (PS1_CurrentPassword[9] & 8)
                                                {
                                                    var_t5_4 = ((u8) PS1_CurrentPassword[8] >> 2) & 1;
                                                }
                                            }

                                            if (var_t5_4 == 0)
                                            {
                                                return 9U;
                                            }
                                            if ((temp_s0) >= 0xBU)
                                            {
                                                var_t5_4 = ((u8) PS1_CurrentPassword[8] >> 4) & 1;
                                                if (!(var_t5_4))
                                                {
                                                    return 0x0AU;
                                                }
                                            }
                                            
                                            if (((temp_s0) == 0x11) || ((PS1_Password_TempCageCounts[17] != 0)))
                                            {
                                                var_v1_1 = 0;
                                                var_a0_1 = 0;
                                                while ((var_a0_1) < 0x11U)
                                                {
                                                    
                                                    var_v1_1 += PS1_Password_TempCageCounts[var_a0_1];
                                                    var_a0_1 += 1;
                                                }
                                                var_t5_4 = 0;
                                                if (((var_v1_1) == 0x11) && (PS1_CurrentPassword[6] & 8))
                                                {
                                                    var_t5_4 = 0;
                                                    if (PS1_CurrentPassword[9] & 4)
                                                    {
                                                        var_t5_4 = ((u8) PS1_CurrentPassword[8] >> 2) & 1;
                                                    }
                                                }
                                            }

                                            if (var_t5_4 == 0)
                                            {
                                                return 0x0B;
                                            }
                                            return var_t5_4;
                                        }
                                        
                                        return 0x0C;
                                    }
                                    
                                    return 0x10;
                                }
                                
                                return 0x0F;
                            }
                            
                            return 8;
                        }
                        
                        return 7;
                    }
                    
                    return 6;
                }
                
                return 5;
            }

            return 4;
        }

        return 3;
    }
    return 2;
}

/* don't even know where to start. WorldInfo.state, permuter found some inline score improvement again... */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword);*/

u8 PS1_GeneratePassword(void)
{
    s32 temp_v0_2;
    u8 var_t8;
    s32 var_v1;
    u32 temp_v1;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_a3;
    u8 temp_t0;
    u8 temp_t1;
    u8 temp_t2;
    u8 temp_t3;
    u8 temp_t4;
    u8 temp_t5;
    u8 temp_t6;
    u8 temp_v0;
    u8 temp_v0_3;
    u8 var_a0;

    memset(PS1_CurrentPassword, 0, 0xA);
    temp_t5 = (*PS1_CurrentPassword & 0xFD) | ((t_world_info[0].nb_cages == 6) * 2);
    *PS1_CurrentPassword = temp_t5;
    temp_t6 = (PS1_CurrentPassword[2] & 0xFD) | ((t_world_info[1].nb_cages == 6) * 2);
    PS1_CurrentPassword[2] = temp_t6;
    temp_a1 = (PS1_CurrentPassword[4] & 0xFD) | ((t_world_info[2].nb_cages == 6) * 2);
    PS1_CurrentPassword[4] = temp_a1;
    temp_a3 = (PS1_CurrentPassword[9] & 0xFD) | ((t_world_info[9].nb_cages == 6) * 2);
    PS1_CurrentPassword[9] = temp_a3;
    temp_t3 = (PS1_CurrentPassword[1] & 0xFD) | ((t_world_info[3].nb_cages == 6) * 2);
    PS1_CurrentPassword[1] = temp_t3;
    temp_t4 = (PS1_CurrentPassword[3] & 0xFD) | ((t_world_info[4].nb_cages == 6) * 2);
    PS1_CurrentPassword[3] = temp_t4;
    temp_a2 = (PS1_CurrentPassword[5] & 0xFD) | ((t_world_info[5].nb_cages == 6) * 2);
    PS1_CurrentPassword[5] = temp_a2;
    temp_t2 = (PS1_CurrentPassword[7] & 0xFD) | ((t_world_info[6].nb_cages == 6) * 2);
    PS1_CurrentPassword[7] = temp_t2;
    temp_t1 = (PS1_CurrentPassword[6] & 0xFD) | ((t_world_info[7].nb_cages == 6) * 2);
    PS1_CurrentPassword[6] = temp_t1;
    temp_t0 = (PS1_CurrentPassword[8] & 0xFD) | ((t_world_info[8].nb_cages == 6) * 2);
    PS1_CurrentPassword[8] = temp_t0;
    PS1_CurrentPassword[4] = (temp_a1 & 0xEF) | ((t_world_info[10].nb_cages == 6) * 0x10);
    *PS1_CurrentPassword = (temp_t5 & 0xEF) | ((t_world_info[11].nb_cages == 6) * 0x10);
    PS1_CurrentPassword[2] = (temp_t6 & 0xEF) | ((t_world_info[12].nb_cages == 6) * 0x10);
    PS1_CurrentPassword[1] = (temp_t3 & 0xEF) | ((t_world_info[13].nb_cages == 6) * 0x10);
    PS1_CurrentPassword[6] = (temp_t1 & 0xEF) | (((u8) *finBosslevel >> 7) * 0x10);
    PS1_CurrentPassword[5] = (temp_a2 & 0xEF) | ((t_world_info[14].nb_cages == 6) * 0x10);
    PS1_CurrentPassword[3] = (temp_t4 & 0xEF) | ((t_world_info[15].nb_cages == 6) * 0x10);
    PS1_CurrentPassword[7] = (temp_t2 & 0xEF) | ((t_world_info[16].nb_cages == 6) * 0x10);
    PS1_CurrentPassword[8] = (temp_t0 & 0xFB) | (((t_world_info[3].state & 5) != 0) * 4);
    PS1_CurrentPassword[9] = (temp_a3 & 0xFB) | (((t_world_info[7].state & 5) != 0) * 4);
    var_t8 = 0x12 + 0xff;
loop_1:
    if ((var_t8 == 3) || ((var_t8 == 7)))
    {
        var_t8 = var_t8 - 2;
    }
    temp_v1 = t_world_info[var_t8].state;
    if ((temp_v1 & 1) != 1)
    {
        var_t8 = var_t8 + 0xFF;
        if (((temp_v1 >> 2) & 1) != 1)
        {
            goto loop_1;
        }
    }
    FUN_801a17c8(var_t8);
    PS1_CurrentPassword[9] = (PS1_CurrentPassword[9] & 0xF7) | ((*finBosslevel * 4) & 8);
    PS1_CurrentPassword[6] = (PS1_CurrentPassword[6] & 0xF7) | (((u8) *finBosslevel >> 3) & 8);
    temp_v0_3 = (PS1_CurrentPassword[8] & 0xEF) | ((finBosslevel[1] * 2) & 0x10);
    PS1_CurrentPassword[8] = temp_v0_3;
    PS1_CurrentPassword[8] = (temp_v0_3 & 0xF7) | ((*finBosslevel * 2) & 8);
    PS1_GeneratePassword_LivesCount(status_bar.num_lives);
    PS1_GeneratePassword_nbContinue(nb_continue);
    PS1_IsPasswordValid = PS1_ValidatePassword();
    temp_v0 = PS1_IsPasswordValid;
    if (temp_v0 == 1)
    {
        PS1_EncryptPassword();
    }
    return temp_v0;
}

/* ??? */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_LoadSaveFromPassword);*/

void PS1_LoadSaveFromPassword(void)
{
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a3;
    s32 var_v0;
    s8 temp_a3;
    s8 temp_a3_2;
    u32 temp_a1;
    u32 temp_s3;
    u8 temp_s0;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v1_2;

    INIT_NEW_GAME();
    var_a0 = 0;
    temp_s0 = PS1_GetLevelFromPassword();
    temp_a1 = temp_s0 & 0xFF;
    var_v0 = 0 & 0xFF;
    do
    {
        temp_v1 = var_v0;
        var_a0 += 1;
        t_world_info[temp_v1].state = t_world_info[temp_v1].state | 1;
        var_v0 = var_a0 & 0xFF;
    } while (temp_a1 >= (u32) (var_a0 & 0xFF));
    temp_s3 = temp_s0 & 0xFF;
    temp_s0_2 = temp_s3 != 0;
    t_world_info[7].state = (t_world_info[7].state & ~1) | (((u8) PS1_CurrentPassword[9] >> 2) & 1);
    t_world_info[3].state = (t_world_info[3].state & ~1) | (((u8) PS1_CurrentPassword[8] >> 2) & 1);
    t_world_info[18].state = (t_world_info[18].state & ~1) | temp_s0_2;
    t_world_info[19].state = (t_world_info[19].state & ~1) | ((temp_s3 < 5U) ^ 1);
    var_a3 = 0;
    if (temp_s3 >= 7U)
    {
        var_a3 = (PS1_CurrentPassword[9] & 4) != 0;
    }
    temp_s2 = (temp_s3 < 0xEU) ^ 1;
    t_world_info[20].state = (t_world_info[20].state & ~1) | var_a3;
    t_world_info[21].state = (t_world_info[21].state & ~1) | ((temp_s3 < 0xAU) ^ 1);
    t_world_info[22].state = (t_world_info[22].state & ~1) | temp_s2;
    t_world_info[23].state = (t_world_info[23].state & ~1) | ((temp_s3 < 0x10U) ^ 1);
    t_world_info[0].nb_cages = ((s32) (*PS1_CurrentPassword << 0x1E) >> 0x1F) & 6;
    t_world_info[1].nb_cages = ((s32) (PS1_CurrentPassword[2] << 0x1E) >> 0x1F) & 6;
    t_world_info[2].nb_cages = ((s32) (PS1_CurrentPassword[4] << 0x1E) >> 0x1F) & 6;
    /*D_801C33A1 = ((s32) (PS1_CurrentPassword[1] << 0x1E) >> 0x1F) & 6;*/
    t_world_info[3].nb_cages = ((s32) (PS1_CurrentPassword[1] << 0x1E) >> 0x1F) & 6;
    t_world_info[4].nb_cages = ((s32) (PS1_CurrentPassword[3] << 0x1E) >> 0x1F) & 6;
    t_world_info[5].nb_cages = ((s32) (PS1_CurrentPassword[5] << 0x1E) >> 0x1F) & 6;
    t_world_info[6].nb_cages = ((s32) (PS1_CurrentPassword[7] << 0x1E) >> 0x1F) & 6;
    /*D_801C33F1 = ((s32) (PS1_CurrentPassword[6] << 0x1E) >> 0x1F) & 6;*/
    t_world_info[7].nb_cages = ((s32) (PS1_CurrentPassword[6] << 0x1E) >> 0x1F) & 6;
    t_world_info[10].nb_cages = ((s32) (PS1_CurrentPassword[4] << 0x1B) >> 0x1F) & 6;
    t_world_info[11].nb_cages = ((s32) (*PS1_CurrentPassword << 0x1B) >> 0x1F) & 6;
    t_world_info[12].nb_cages = ((s32) (PS1_CurrentPassword[2] << 0x1B) >> 0x1F) & 6;
    t_world_info[13].nb_cages = ((s32) (PS1_CurrentPassword[1] << 0x1B) >> 0x1F) & 6;
    t_world_info[14].nb_cages = ((s32) (PS1_CurrentPassword[5] << 0x1B) >> 0x1F) & 6;
    temp_a3 = ((s32) (PS1_CurrentPassword[8] << 0x1E) >> 0x1F) & 6;
    t_world_info[8].nb_cages = temp_a3;
    t_world_info[9].nb_cages = ((s32) (PS1_CurrentPassword[9] << 0x1E) >> 0x1F) & 6;
    t_world_info[15].nb_cages = ((s32) (PS1_CurrentPassword[3] << 0x1B) >> 0x1F) & 6;
    t_world_info[16].nb_cages = ((s32) (PS1_CurrentPassword[7] << 0x1B) >> 0x1F) & 6;
    t_world_info[17].nb_cages = 0;
    memset(&RayEvts, 0, 2, temp_a3);
    temp_s1 = (temp_s3 < 4U) ^ 1;
    temp_v1_2 = (RayEvts.flags0 & 0xFC) | temp_s0_2 | (temp_s1 * 2);
    RayEvts.flags0 = temp_v1_2;
    temp_a3_2 = (PS1_CurrentPassword[9] * 0x10) & 0x80;
    RayEvts.flags0 = (temp_v1_2 & 0x7B) | temp_a3_2 | (((temp_s3 < 8U) ^ 1) * 4);
    temp_s0_3 = (temp_s3 < 0xBU) ^ 1;
    RayEvts.flags1 = (RayEvts.flags1 & 0xFE) | temp_s0_3;
    memset((RaymanEvents *) finBosslevel, 0, 2, temp_a3_2);
    temp_v0 = (*finBosslevel & 0xFE) | temp_s1;
    *finBosslevel = temp_v0;
    temp_v0_2 = (temp_v0 & 0xFD) | (((u8) PS1_CurrentPassword[9] >> 2) & 2);
    *finBosslevel = temp_v0_2;
    temp_v0_3 = (((temp_v0_2 & 0xF3) | (((u8) PS1_CurrentPassword[8] >> 1) & 4) | (temp_s0_3 * 8)) & 0xCF) | (((temp_s3 < 0xCU) ^ 1) * 0x10) | (temp_s2 << 5);
    *finBosslevel = temp_v0_3;
    *finBosslevel = (temp_v0_3 & 0x3F) | ((PS1_CurrentPassword[6] * 8) & 0x40) | ((PS1_CurrentPassword[6] * 8) & 0x80);
    finBosslevel[1] = (finBosslevel[1] & 0xF7) | (((u8) PS1_CurrentPassword[8] >> 1) & 8);
    status_bar.num_lives = PS1_GetLivesFromPassword() & 0xFF;
    nb_continue = PS1_GetContinuesFromPassword();
    world_index = 0;
    xwldmapsave = 0;
    ywldmapsave = 0x009E;
    dir_on_wldmap = 1;
}