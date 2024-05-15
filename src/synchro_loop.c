#include "synchro_loop.h"

void FUN_801802d8(void) {}

/* 5BAE0 801802E0 -O2 -msoft-float */
extern s32 PS1_PrevPrim;

/* belongs to 548CC? used as array index for map_drawing_environment_primitives? (0x70 in Display struct) */
extern s16 D_801E4BE0;

void SYNCHRO_LOOP(s16 (*func)())
{
  u8 *new_disp_1;
  RECT *new_rect;
  u8 *new_disp_2;
  s16 i;
  s16 func_done;

  do
  {
    if (PS1_MemoryUsageDisplayMode != 0)
      ClearImage(PTR_PS1_MemoryUsageRect_801cee70, 0, 0, 0);
    
    new_disp_1 = &PS1_Display1;
    if (PS1_CurrentDisplay == (&PS1_Display1))
      new_disp_1 = &PS1_Display1 + 1;
    PS1_CurrentDisplay = new_disp_1;
    DrawSync(0);
    VSync(0);
    PutDispEnv(&PS1_CurrentDisplay->field0_0x0);
    PutDrawEnv(&PS1_CurrentDisplay->drawing_environment);
    
    if (PTR_PS1_MemoryUsageRect_801cee70 == &PS1_MemoryUsageRect)
      new_rect = &PS1_MemoryUsageRect + 1;
    else
      new_rect = &PS1_MemoryUsageRect;
    PTR_PS1_MemoryUsageRect_801cee70 = new_rect;
    
    if (PS1_MemoryUsageDisplayMode != 0)
      ClearImage(PTR_PS1_MemoryUsageRect_801cee70, 0, 0, 128);
    ClearOTag(PS1_CurrentDisplay->field327_0x7f0, 11);
    
    if (PS1_CurrentDisplay == &PS1_Display1)
      new_disp_2 = &PS1_Display1 + 1;
    else
      new_disp_2 = &PS1_Display1;
    
    for (i = 0; i < PS1_PolygonIndexTableCount; i++)
    {
      SetPolyFT4(new_disp_2 + ((PS1_PolygonIndexTable[i] * 0x28) + 0x4144));
      SetSemiTrans(new_disp_2 + ((PS1_PolygonIndexTable[i] * 0x28) + 0x4144), 0);
      SetShadeTex(new_disp_2 + ((PS1_PolygonIndexTable[i] * 0x28) + 0x4144), 1);
    }
    PS1_PolygonIndexTableCount = 0;
    D_801E4BE0 = 0x0019;
    D_801F4A28 = 0;
    D_801FA690 = 0;
    PS1_PolygonsCount = 0;
    D_801F81B0 = 0;
    PS1_PrevPrim = PS1_CurrentDisplay->field327_0x7f0 + 6;
    func_done = func();
    if (PS1_MemoryUsageDisplayMode == 2)
      ClearImage(PTR_PS1_MemoryUsageRect_801cee70, 128, 0, 128);
    PS1_CheckPauseAndCheatInputs();
    if (PS1_MemoryUsageDisplayMode == 2)
      ClearImage(PTR_PS1_MemoryUsageRect_801cee70, 128, 0, 128);
    DrawOTag(PS1_CurrentDisplay->field327_0x7f0);
  }
  while (!func_done);
}
