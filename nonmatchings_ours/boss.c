#include "boss.h"

/* see mama_pirate also */
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

    if ((bossXToReach != -0x7D00) && (bossYToReach != -0x7D00))
    {
        /*var_s1 = (s8) obj->eta[obj->main_etat][obj->sub_etat].speed_x_right * (bossSpeedFactor + alternateBossSpeedFactor);*/
        var_v1_2 = obj->eta[obj->main_etat][obj->sub_etat].speed_x_right;
        var_s1 = ((s8) var_v1_2) * (bossSpeedFactor + alternateBossSpeedFactor);
        if (var_s1 < 0)
        {
            var_s1 += 0x3FFF;
        }
        temp_s1 = var_s1 >> 0xE;
        temp_s3 = (bossXToReach - obj->x_pos) * 0x10;
        temp_v1 = (bossYToReach - obj->y_pos) * 0x10;
        if (((temp_s3 != 0) || (((s16)temp_v1) != 0)) && (temp_s1 != 0))
        {
            var_a0 = __builtin_abs(temp_s3);
            temp_s4 = (s16)temp_v1;
            var_v1 = __builtin_abs(temp_s4);
            if (var_a0 < var_v1)
            {
                var_a0 = var_v1;
            }
            var_v1_2 = (s16)var_a0;
            if (temp_s1 < var_v1_2)
            {
                var_v1_2 = temp_s1;
            }    
            temp_lo = ashl16((s16)var_a0, 4) / var_v1_2;
            temp_lo_2 = ashl16(temp_s3, 4) / temp_lo;
            temp_lo_3 = ashl16(temp_s4, 4) / temp_lo;
            if (horloge[param_2] == 0)
            {
                temp_v1_2 = (obj->speed_x * (0xFF - param_3)) + ((s16) temp_lo_2 * param_3);
                obj->speed_x = (s16) (temp_v1_2 / 255);
                if (obj->main_etat == 2)
                {
                    if (var_v1_2 >= temp_s4)
                    {
                        param_4 = 0x000000FF;
                    }
                }
                temp_v1_3 = (obj->speed_y * (0xFF - param_4)) + ((s16) temp_lo_3 * param_4);
                obj->speed_y = (s16) (temp_v1_3 / 255);
            }
        }
        else
        {
          obj->speed_x = 0;
          obj->speed_y = 0;
        }
    }
    else
    {
        obj->speed_x = 0;
        obj->speed_y = 0;
    }
}