#include "boss.h"

/* 66BE8 8018B3E8 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/boss", setBossReachingSpeeds);

/* 66EFC 8018B6FC -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/boss", testActionEnd);

/* well, we got the unused function, so i did something today :) */
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
INCLUDE_ASM("asm/nonmatchings/boss", firstFloorBelow);