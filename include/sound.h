#ifndef SOUND_H
#define SOUND_H

#include "common.h"

typedef struct SoundTableEntry
{
    u8 note;
    u8 prog;
    u8 tone;
    u8 volume;
    u8 flags;
} SoundTableEntry;

typedef struct VoiceTableEntry
{
    s16 field0_0x0;
    s16 field1_0x2;
    s16 field2_0x4;
    u8 field3_0x6;
    u8 field4_0x7;
    u8 field5_0x8;
    u8 field6_0x9;
    u8 field7_0xa;
    u8 field8_0xb;
} VoiceTableEntry;

#endif