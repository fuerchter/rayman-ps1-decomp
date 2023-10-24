#include "boss.h"

/* 66BE8 8018B3E8 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/boss", setBossReachingSpeeds);*/

/*s32 ashl16(s32, ?, s16);*/

void setBossReachingSpeeds(Obj *obj, u8 param_2, u8 param_3, u8 param_4)
{
    s16 temp_s3;
    s16 temp_s4;
    s32 var_a0;
    s32 var_v1;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_lo_2;
    s16 temp_lo_3;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_s1;
    s32 var_v1_2;
    u8 var_s5;

    var_s5 = param_4;
    if ((bossXToReach != -0x7D00) && (bossYToReach != -0x7D00))
    {
        var_s1 = (s8) obj->eta[obj->main_etat][obj->sub_etat].speed_x_right * (bossSpeedFactor + alternateBossSpeedFactor);
        if (var_s1 < 0)
        {
            var_s1 += 0x3FFF;
        }
        temp_s1 = var_s1 >> 0xE;
        temp_s3 = (bossXToReach - obj->x_pos) * 0x10;
        temp_v1 = (bossYToReach - obj->y_pos) * 0x10;
        if (((temp_s3 != 0) || (((s16)temp_v1) != 0)) && (temp_s1 != 0))
        {
            var_a0 = temp_s3;
            if (temp_s3 < 0)
            {
                var_a0 = -var_a0;
            }
            temp_s4 = (s16)temp_v1;
            var_v1 = temp_s4;
            if (temp_s4 < 0)
            {
                var_v1 = -var_v1;
            }
            var_a0_2 = var_a0;
            if (var_a0 < var_v1)
            {
                var_a0_2 = var_v1;
            }
            var_v1_2 = (s16)var_a0_2;
            if (temp_s1 < var_v1_2)
            {
                var_v1_2 = temp_s1;
            }
            temp_v0 = ashl16((s16)var_a0_2, 4);
            temp_lo = temp_v0 / var_v1_2;
            temp_v0_2 = ashl16(temp_s3, 4);
            temp_lo_2 = temp_v0_2 / temp_lo;
            temp_v0_3 = ashl16(temp_s4, 4);
            temp_lo_3 = temp_v0_3 / temp_lo;
            if (horloge[param_2] == 0)
            {
                temp_a1 = param_3;
                temp_v1_2 = (obj->speed_x * (0xFF - temp_a1)) + ((s16) temp_lo_2 * temp_a1);
                obj->speed_x = (s16) (temp_v1_2 / 255);
                if (obj->main_etat == 2)
                {
                    var_a1 = var_s5;
                    if (var_v1_2 >= temp_s4)
                    {
                        var_s5 = 0x000000FF;
                        goto block_31;
                    }
                }
                else
                {
block_31:
                    var_a1 = var_s5;
                }
                temp_v1_3 = (obj->speed_y * (0xFF - var_a1)) + ((s16) temp_lo_3 * var_a1);
                obj->speed_y = (s16) (temp_v1_3 / 255);
            }
        }
        else
        {
            goto block_36;
        }
    }
    else
    {
block_36:
        obj->speed_x = 0;
        obj->speed_y = 0;
    }
}

/* 6703C 8018B83C -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/boss", firstFloorBelow);*/

/*s32 PS1_BTYPAbsPos(s16, s16);
s32 dist_to_bloc_floor(s32, s32, ?);*/
u8 PS1_BTYPAbsPos(s32 x, s32 y);

s16 firstFloorBelow(Obj *obj)
{
  s16 uVar1;
  u8 uVar2;
  int new_var3;
  s32 uVar3;
  int iVar4;
  s16 iVar5;
  int new_var;
  
  uVar1 = obj->offset_by + (u16)obj->y_pos;
  uVar3 = obj->offset_bx + (u16)obj->x_pos;
  iVar4 = (s16) uVar3;
  iVar5 = (s16) uVar1;
  new_var3 = iVar4;
  uVar2 = PS1_BTYPAbsPos(new_var3, iVar5);
  while ((((block_flags[uVar2] >> 1) & 1) == 0) && (iVar5 <= (ymapmax + 0xf0)))
  {
    uVar1 = uVar1 + 0x10;
    iVar5 = uVar1;
    uVar2 = PS1_BTYPAbsPos(new_var3 >> 0x10, iVar5);
  }

  iVar4 = dist_to_bloc_floor(uVar2, uVar3 & 0xf, 0);
  new_var = 0xfffffff0;
  return iVar4 + (uVar1 & new_var);
}