#ifndef VRAM_H
#define VRAM_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"

s32 PS1_LoadToVRAM(s16 width, s16 height, s16 x, s16 y, u8 *data);
void PS1_LoadVRAMBlock(s16 start_page, s16 start_pos, s16 end_page, s16 end_pos, s16 unused, u8 *data);

#endif