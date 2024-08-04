#include "collision/bit_util.h"

extern s32 saveobj[16];

/* 21D30 80146530 -O2 -msoft-float */
void set2bits(s32 *param_1, u8 pos, s32 param_3)
{
    s32 unk_1 = (0xf - pos) << 1;
    s32 unk_2 = 3 << unk_1;
    s32 unk_3 = param_3 << unk_1;
    
    *param_1 = unk_3 | (*param_1 & ~unk_2);
}

/* 21D64 80146564 -O2 -msoft-float */
void read2bits(s32 *value, u8 pos, s32 *b1, s32 *b0)
{
    s32 unk_1 = (0xF - pos) << 1;
    s32 unk_2 = *value;

    unk_2 &= 3 << unk_1;
    unk_2 >>= unk_1;
    *b1 = (unk_2 & (1 << 1)) >> 1;
    *b0 = unk_2 & 1;
}

/* asm does shift with 0xa twice instead */
/* 21DA0 801465A0 -O2 -msoft-float */
void save_objects_flags(void)
{
    s32 i = 0;
    Obj *cur_obj = &level.objects[0];
    s32 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {        
        set2bits(
            &saveobj[i >> 4],
            i & 0xF,
            (cur_obj->flags >> OBJ_ACTIVE & 1) << 1 | (cur_obj->flags >> OBJ_ALIVE & 1)
        );
        cur_obj++;
        i++;
    }
}

/* 21E34 80146634 -O2 -msoft-float */
void restore_objects_flags(void)
{
    s32 b1; s32 b0;
    s32 i = 0;
    Obj *cur_obj = &level.objects[0];
    s32 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (cur_obj->type != TYPE_CAGE)
        {
            read2bits(&saveobj[i >> 4], i & 0xF, &b1, &b0);
            cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_ACTIVE)) | ((b1 & 1) << OBJ_ACTIVE);
            cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_ALIVE)) | ((b0 & 1) << OBJ_ALIVE);
        }
        i++;
        cur_obj++;
    }
}

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
