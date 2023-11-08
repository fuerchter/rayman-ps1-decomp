#include "boss.h"


INCLUDE_ASM("asm/nonmatchings/boss", setBossReachingSpeeds);

/* 66EFC 8018B6FC -O2 -msoft-float */
s16 testActionEnd(Obj *obj)
{
  s16 res = false;

  if (bossXToReach == -32000 && bossYToReach == -32000)
    res = obj->nb_cmd == 0;
  else if (obj->x_pos == bossXToReach && obj->y_pos == bossYToReach)
    res = true;
  if (res)
    currentBossActionIsOver = true;
  return res;
}

/* 66F8C 8018B78C -O2 -msoft-float */
void FUN_8018b78c(s16 *param_1, s16 *param_2, s16 *param_3, s16 *param_4, u8 param_5)
{
  s16 sVar1;
  u16 sVar2;
  s16 sVar3;
  s16 sVar4;
  s32 sVar5;

  sVar1 = *param_3;
  sVar2 = *param_1;
  sVar3 = *param_4;
  sVar4 = *param_2;
  *param_3 -= param_5;
  *param_4 -= param_5;
  sVar5 = sVar2 + (sVar1 >> 1);
  sVar2 = sVar4 + (sVar3 >> 1);
  if (*param_3 < 10)
    *param_3 = 10;
  if (*param_4 < 10)
    *param_4 = 10;
  *param_1 = sVar5 -  (*param_3 >> 1);
  *param_2 = sVar2 - (*param_4 >> 1);
}

/* 6703C 8018B83C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/boss", firstFloorBelow);
#else
/*u8 PS1_BTYPAbsPos(s32 x, s32 y);*/

s16 firstFloorBelow(Obj *obj)
{
  s16 x;
  s16 y;
  u8 btyp;

  __asm__("nop");

  x = obj->offset_bx + obj->x_pos;
  y = obj->offset_by + obj->y_pos;
  btyp = PS1_BTYPAbsPos(x, y);
  while (!(block_flags[btyp] >> BLOCK_SOLID & 1) && (y <= ymapmax + 240))
  {
    y += 16;
    btyp = PS1_BTYPAbsPos(x, y);
  }
  
  return dist_to_bloc_floor(btyp, x & 0xf, 0) + (y & ~0xf);
}
#endif