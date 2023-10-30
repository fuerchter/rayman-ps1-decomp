#ifndef VRAM_H
#define VRAM_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"

s32 PS1_LoadToVRAM(s16 width, s16 height, s16 x, s16 y, u32 *data);
void PS1_LoadVRAMBlock(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 unused, u32 *data);

#endif