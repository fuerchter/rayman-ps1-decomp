#include "collision/bit_util.h"

/* 21D30 80146530 -O2 -msoft-float */
void set2bits(s32 *param_1, u8 pos, s32 param_3)
{
    s32 unk_1 = (0xf - pos) << 1;
    s32 unk_2 = 3 << unk_1;
    s32 unk_3 = param_3 << unk_1;
    
    *param_1 = unk_3 | (*param_1 & ~unk_2);
}

/* 21D64 80146564 -O2 -msoft-float */
void read2bits(s32 *value, u8 pos, s32 *b1, s32 *b2)
{
    s32 unk_1 = (0xF - pos) << 1;
    s32 unk_2 = *value;

    unk_2 &= 3 << unk_1;
    unk_2 >>= unk_1;
    *b1 = (unk_2 & (1 << 1)) >> 1;
    *b2 = unk_2 & 1;
}

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", save_objects_flags);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", restore_objects_flags);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", snapToSprite);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", findfirstObject);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", findfirstInactiveObject);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", setbit);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", clearbit);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", getbit);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", cosinus);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", sinus);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", sinYspeed);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", ashl16);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", ashr16);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", ashl32);

INCLUDE_ASM("asm/nonmatchings/collision/bit_util", ashr32);
