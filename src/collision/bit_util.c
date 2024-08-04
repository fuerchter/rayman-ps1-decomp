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

/* 22360 80146B60 -O2 -msoft-float */
Obj *findfirstObject(ObjType obj_type)
{
    Obj *cur_obj = &level.objects[0];
    s16 i = 0;
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (cur_obj->type == obj_type)
            break;
        cur_obj++;
        i++;
    }

    return cur_obj;
}

/* 223B8 80146BB8 -O2 -msoft-float */
Obj *findfirstInactiveObject(ObjType obj_type)
{
    Obj *cur_obj = &level.objects[0];
    s16 i = 0;
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (cur_obj->type == obj_type && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
            break;
        cur_obj++;
        i++;
    }

    return cur_obj;
}

/* 2242C 80146C2C -O2 -msoft-float */
void setbit(u8 *buffer, u16 index)
{
    buffer[index >> 3] |= 1 << (index & 7);
}

/* 22454 80146C54 -O2 -msoft-float */
void clearbit(u8 *buffer, u16 index)
{
    buffer[index >> 3] &= ~(1 << (index & 7));
}

/* 22480 80146C80 -O2 -msoft-float */
u8 getbit(u8 *buffer, u16 index)
{
    return buffer[index >> 3] & (1 << (index & 7));
}

/* 224A4 80146CA4 -O2 -msoft-float */
s16 cosinus(s16 param_1)
{
    return sinus(param_1 + 128);
}

/* 224D0 80146CD0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/bit_util", sinus);
#else
s16 sinus(s16 param_1)
{
    s32 unk_1 = param_1 - (param_1 / 512 * 512);
    s16 unk_2 = unk_1;
    s16 res;

    if (unk_2 < 128)
        res = costab[128 - unk_2];
    else if (unk_2 < 256)
        res = costab[(s16) (unk_2 - 128)];
    else if (unk_2 < 384)
        res = -costab[128 - (s16) (unk_2 - 256)];
    else
        res = -costab[(s16) (unk_2 - 384)];

    __asm__("nop\nnop\nnop\nnop");
    return res;
}
#endif

/* 225B8 80146DB8 -O2 -msoft-float */
s16 sinYspeed(Obj *obj, s32 param_2, s16 param_3, s16 *param_4)
{
    s16 unk_1 = (*param_4 + param_2) & 4095;
    s16 diff_y = obj->y_pos - obj->init_y_pos;
    s32 unk_2 = sinus(unk_1 >> 3) * param_3;

    *param_4 = unk_1;
    return (unk_2 >> 9) - diff_y;
}

/* 2264C 80146E4C -O2 -msoft-float */
s32 ashl16(s16 value, u8 shift)
{
    s32 unk_1;
    s32 res;
    s16 sgn_bit = value & (1 << 15);
    s32 sh = shift;

    if (sgn_bit)
        unk_1 = -value << sh;
    else
        unk_1 = value << sh;
    
    if (sgn_bit)
        res = -unk_1;
    else
        res = unk_1;
        
    return res;
}

/* 2269C 80146E9C -O2 -msoft-float */
s32 ashr16(s16 value, u8 shift)
{
    s32 res;
    s32 unk_1;
    s16 sgn_bit = value & (1 << 15);
    s32 sh = shift;
    
    if (sgn_bit)
        res = -value >> sh;
    else
        res = value >> sh;

    if (sgn_bit)
        unk_1 = -res;
    else
        unk_1 = res;
    res = unk_1;

    return (s16) res;
}

/* 226EC 80146EEC -O2 -msoft-float */
s32 ashl32(s32 value, u8 shift)
{
    s32 res;
    s32 sgn_bit = value & (1 << 31);
    s32 sh = shift;
    
    if (sgn_bit)
        value = -value << sh;
    else
        value = value << sh;
    
    if (sgn_bit)
        res = -value;
    else
        res = value;
    
    return res;
}

/* 22720 80146F20 -O2 -msoft-float */
s32 ashr32(s32 value, u8 shift)
{
    s32 res;
    s32 sgn_bit = value & (1 << 31);
    s32 sh = shift;
    
    if (sgn_bit)
        value = -value >> sh;
    else
        value = value >> sh;
    
    if (sgn_bit)
        res = -value;
    else
        res = value;
    
    return res;
}
