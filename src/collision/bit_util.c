#include "collision/bit_util.h"

#ifdef BSS_DEFS
s32 saveobj[16];
#endif

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

/* 21EF8 801466F8 -O2 -msoft-float */
void snapToSprite(Obj *obj_1, Obj *obj_2, u8 obj_2_spr, s32 x_offs, u16 y_offs)
{
    u8 obj_2_frames_count;
    ObjState *obj_2_eta_2;
    u8 prev_frame;
    u8 prev_index;
    s16 obj_2_x; s16 obj_2_y; s16 obj_2_w; s16 obj_2_h;
    s16 new_spd_x; s16 new_spd_y;
    s16 obj_2_anim_frame = obj_2->anim_frame;
    ObjState *obj_2_eta_1 = &obj_2->eta[obj_2->main_etat][obj_2->sub_etat];
    u8 obj_2_anim_index = obj_2_eta_1->anim_index;

    if (horloge[obj_2_eta_1->anim_speed & 0xF] == 0)
    {
        obj_2_frames_count = obj_2->animations[obj_2_anim_index].frames_count;
        obj_2_anim_frame += (obj_2_eta_1->flags & 0x10) ? -1 : 1; /* requires ternary to match? */
        if (obj_2_anim_frame < 0 || obj_2_anim_frame > obj_2_frames_count - 1)
        {
            obj_2_eta_2 = &obj_2->eta[obj_2_eta_1->next_main_etat][obj_2_eta_1->next_sub_etat];
            obj_2_anim_index = obj_2_eta_2->anim_index;
            obj_2_frames_count = obj_2->animations[obj_2_anim_index].frames_count;
            
            obj_2_anim_frame = (obj_2_eta_2->flags & 0x10) ? (obj_2_frames_count - 1) : 0;
        }
    }
    prev_frame = obj_2->anim_frame;
    prev_index = obj_2->anim_index;
    obj_2->anim_frame = obj_2_anim_frame;
    obj_2->anim_index = obj_2_anim_index;
    GET_SPRITE_POS(obj_2, obj_2_spr, &obj_2_x, &obj_2_y, &obj_2_w, &obj_2_h);
    obj_2->anim_index = prev_index;
    obj_2->anim_frame = prev_frame;

    new_spd_x = x_offs + obj_2_x - obj_1->x_pos;
    while (__builtin_abs(new_spd_x) >= 16)
    {
        obj_1->x_pos += SGN(new_spd_x) * 16;
        new_spd_x += SGN(new_spd_x) * -16;
    }

    new_spd_y = y_offs + obj_2_y - obj_1->y_pos;
    while (__builtin_abs(new_spd_y) >= 16)
    {
        obj_1->y_pos += SGN(new_spd_y) * 16;
        new_spd_y += SGN(new_spd_y) * -16;
    }

    if (new_spd_x != 0)
    {
        switch (
            (flags[obj_1->type].flags1 >> OBJ1_USE_INSTANT_SPEED_X & 1) +
            (flags[obj_2->type].flags1 >> OBJ1_USE_INSTANT_SPEED_X & 1) * 2
        )
        {
        case 0:
            new_spd_x += obj_2->speed_x;
            break;
        case 3:
            new_spd_x = instantSpeed(obj_2->speed_x) + new_spd_x * 16;
            break;
        case 1:
            new_spd_x = (new_spd_x + obj_2->speed_x) * 16;
            break;
        case 2:
            new_spd_x += instantSpeed(obj_2->speed_x);
            break;
        }
    }

    if (new_spd_y != 0)
    {
        switch (
            (flags[obj_1->type].flags1 >> OBJ1_USE_INSTANT_SPEED_Y & 1) +
            (flags[obj_2->type].flags1 >> OBJ1_USE_INSTANT_SPEED_Y & 1) * 2
        )
        {
        case 0:
            new_spd_y += obj_2->speed_y;
            break;
        case 3:
            new_spd_y = instantSpeed(obj_2->speed_y) + new_spd_y * 16;
            break;
        case 1:
            new_spd_y = (new_spd_y + obj_2->speed_y) * 16;
            break;
        case 2:
            new_spd_y += instantSpeed(obj_2->speed_y);
            break;
        }
    }

    obj_1->speed_x = new_spd_x;
    obj_1->speed_y = new_spd_y;
}

/* 22360 80146B60 -O2 -msoft-float */
Obj *findfirstObject(ObjType obj_type)
{
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
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

    return res;
}

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
s16 ashr16(s16 value, u8 shift)
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

    return res;
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
