#include "vram.h"

s32 PS1_LoadToVRAM(s16 w, s16 h, s16 x, s16 y, u32 *data)
{
  RECT rect;
  
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;
  LoadImage(&rect, data);
  DrawSync(0);
  return w * h * 2;
}

INCLUDE_ASM("asm/nonmatchings/vram", PS1_LoadVRAMBlock); /* ... */