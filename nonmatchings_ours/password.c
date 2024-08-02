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
    PS1_CurrentPassword[9] = inline_fn(uVar1, ~1, (uVar4 >> 0) & 1);
    PS1_CurrentPassword[7] = inline_fn(PS1_CurrentPassword[7], ~1, ((uVar4 >> 1)) & 1);
    PS1_CurrentPassword[6] = inline_fn(PS1_CurrentPassword[6], ~1, ((uVar4 >> 2)) & 1);
    PS1_CurrentPassword[8] = inline_fn(PS1_CurrentPassword[8], ~1, ((uVar4 >> 3)) & 1);
    PS1_CurrentPassword[5] = inline_fn(PS1_CurrentPassword[5], ~1, ((uVar4 >> 4)) & 1);
    PS1_CurrentPassword[0] = inline_fn(PS1_CurrentPassword[0], ~1, ((uVar4 >> 5)) & 1);
    PS1_CurrentPassword[1] = inline_fn(PS1_CurrentPassword[1], ~1, ((uVar4 >> 6)) & 1);
    PS1_CurrentPassword[3] = inline_fn(PS1_CurrentPassword[3], ~1, ((uVar4 >> 7)) & 1);
    PS1_CurrentPassword[2] = inline_fn(PS1_CurrentPassword[2], ~1, ((uVar4 >> 8)) & 1);
    PS1_CurrentPassword[4] = inline_fn(PS1_CurrentPassword[4], ~1, ((uVar4 >> 9)) & 1);
    /*uVar1 = PS1_CurrentPassword[9];
    PS1_CurrentPassword[9] = (uVar1 & ~1 | (uVar4 >> 0)) & 1;
    PS1_CurrentPassword[7] = (PS1_CurrentPassword[7] & ~1 | ((uVar4 >> 1))) & 1;
    PS1_CurrentPassword[6] = (PS1_CurrentPassword[6] & ~1 | ((uVar4 >> 2))) & 1;
    PS1_CurrentPassword[8] = (PS1_CurrentPassword[8] & ~1 | ((uVar4 >> 3))) & 1;
    PS1_CurrentPassword[5] = (PS1_CurrentPassword[5] & ~1 | ((uVar4 >> 4))) & 1;
    PS1_CurrentPassword[0] = (PS1_CurrentPassword[0] & ~1 | ((uVar4 >> 5))) & 1;
    PS1_CurrentPassword[1] = (PS1_CurrentPassword[1] & ~1 | ((uVar4 >> 6))) & 1;
    PS1_CurrentPassword[3] = (PS1_CurrentPassword[3] & ~1 | ((uVar4 >> 7))) & 1;
    PS1_CurrentPassword[2] = (PS1_CurrentPassword[2] & ~1 | ((uVar4 >> 8))) & 1;
    PS1_CurrentPassword[4] = (PS1_CurrentPassword[4] & ~1 | ((uVar4 >> 9))) & 1;*/
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