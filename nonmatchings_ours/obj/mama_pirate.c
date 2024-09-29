#include "obj/mama_pirate.h"

/* matches, but how to remove/clean up locals? */
/* 26F08 8014B708 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_parabolique);*/

void lance_couteau_parabolique(Obj *obj)
{
    u8 cout_ind;
    s16 diff_x;
    s16 diff_y;
    s16 speed_x;
    s16 speed_y;
    s32 dividend;
    s32 divisor;

    s16 test_1;
    int new_var3;

    cout_ind = find_couteau(obj);
    if (cout_ind != 0xFF)
    {
        diff_x = (xmap + CouteauxInfos[cout_ind].x_pos) - (obj->offset_bx + obj->x_pos);
        diff_y = (ymap + CouteauxInfos[cout_ind].y_pos) - (obj->offset_by + obj->y_pos);
        if (CouteauxInfos[cout_ind].field2_0x4 != 0)
        {
            CouteauxInfos[cout_ind].field2_0x4 = 0;
            if (diff_x == 0)
            {
                obj->speed_x = convertspeed(0);
                obj->speed_y = convertspeed(-1);
            }
            else
            {
                if (diff_x >= 0)
                    speed_x = 2;
                else
                    speed_x = -2;
                test_1 = 0x10;
                new_var3 = diff_x * 8;
                dividend = -(diff_y * (speed_x * test_1) * 8 + diff_x * new_var3);
                divisor = diff_x * speed_x * 8;
                speed_y = dividend / divisor;
                obj->speed_x = convertspeed(speed_x) - 10;
                obj->speed_y = speed_y;
            }
            update_couteau(obj);
            obj->display_prio = 3;
            return;
        }
        obj->speed_y += 4;
        if (obj->speed_x * diff_x < 0)
            obj->speed_x = 0;
        update_couteau(obj);
    }
    __asm__("nop\nnop\nnop\nnop\nnop");
}

/* missing_addiu, div_nop_swap. matches, but... clean up */
/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_lineaire);*/

/* 279B8 8014C1B8 -O2 -msoft-float */
void lance_couteau_lineaire(Obj *param_1)
{
    Obj *temp_v0_3;
    u8 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 temp_a1;
    s16 temp_v1_2;
    ObjState *temp_v1_6;
    s16 temp_a1_3;
    s16 temp_a2;
    s32 var_a0_2;
    u8 var_s5;
    s32 var_v1;
    s32 temp_lo;
    s16 var_s2;
    s16 var_s3;
    s32 var_a0;
    u8 var_s0;
    u8 temp_v1_4;
    ObjState *temp_v1_7;
    s16 var_v0_3;

    temp_v0 = find_couteau(param_1);
    if ((temp_v0 != 0xFF) && ((temp_v0 == 0) || (CouteauxInfos[temp_v0 - 1].field2_0x4 == 0)))
    {
        temp_v0_2 = CouteauxInfos[temp_v0].field2_0x4;
        if (temp_v0_2 == 0)
        {
            if (!CouteauxInfos[temp_v0].active)
            {
                temp_v0_3 = &level.objects[CouteauxInfos[temp_v0].id];
                temp_v1 = temp_v0_3->offset_bx + temp_v0_3->x_pos;
                temp_a1 = temp_v0_3->offset_by + temp_v0_3->y_pos;
                if (temp_v1 >= -0x14)
                {
                    if (((xmapmax + 0x154) >= temp_v1) && (((temp_a1 < -0x14) == 0)))
                    {
                        if ((ymapmax + 0x104) >= temp_a1)
                        {
                            return;
                        }
                    }
                }
                CouteauxInfos[temp_v0].active = true;
                level.objects[CouteauxInfos[temp_v0].id].flags &= ~0x800;
                level.objects[CouteauxInfos[temp_v0].id].flags &= ~0x400;
                if (check_couteaux())
                {
                    pma_phase = 4;
                    if (level.objects[mama_pirate_obj_id].hit_points == 0)
                    {
                        fin_boss = 1;
                        finBosslevel[0] |= 0x10;
                    }
                }
            }
        }
        else if (temp_v0_2 == 1)
        {
            temp_v1_2 = CouteauxInfos[temp_v0].field4_0x8;
            if (temp_v1_2 == 0x000F)
            {
                CouteauxInfos[temp_v0].x_pos = ray.offset_bx + ray.x_pos;
                CouteauxInfos[temp_v0].y_pos = ray.offset_by + ray.y_pos;
                temp_a1_3 = CouteauxInfos[temp_v0].x_pos - (param_1->offset_bx + param_1->x_pos);
                temp_a2 = CouteauxInfos[temp_v0].y_pos - (param_1->offset_by + param_1->y_pos);
                switch(CouteauxInfos[temp_v0].field9_0x10)
                {
                case 1:
                    var_a0_2 = __builtin_abs(temp_a1_3);
                    var_v1 = __builtin_abs(temp_a2);
                    var_s5 = 0x0B;
                    if (var_a0_2 < var_v1)
                    {
                        var_a0_2 = var_v1;
                    }
                    temp_lo = 4;
                    temp_lo = ashl16(var_a0_2, 4U) / temp_lo;
                    var_s3 = convertspeed(ashl16(temp_a1_3, 4U) / (s16) temp_lo);
                    var_s2 = convertspeed(ashl16(temp_a2, 4U) / (s16) temp_lo);
                    var_s0 = couteau_frame(var_s3, var_s2);
                    break;
                case 3:
                    var_s5 = 0x0B;
                    var_s3 = convertspeed(0);
                    var_s2 = convertspeed(3);
                    var_s0 = couteau_frame(var_s3, var_s2);
                    break;
                case 0:
                    var_s5 = 0x0B;
                    var_a0 = -3;
                    if (temp_a1_3 >= 0)
                    {
                        var_a0 = 3;
                    }
                    var_s3 = convertspeed(var_a0);
                    var_s2 = convertspeed(0);
                    var_s0 = couteau_frame(var_s3, var_s2);
                    break;
                case 2:
                    var_s5 = 0x0E;
                    var_s3 = convertspeed(-1);
                    var_s2 = convertspeed(5);
                    var_s0 = couteau_frame(0, 1);
                    break;
                }
                temp_v1_4 = CouteauxInfos[temp_v0].field9_0x10;
                if (temp_v1_4 == 2)
                {
                  param_1->sub_etat = var_s5;
                  param_1->anim_frame = var_s0;
                  param_1->eta[param_1->main_etat][param_1->sub_etat].anim_speed &= 0xF0;
                  CouteauxInfos[temp_v0].field5_0xa = var_s3;
                  CouteauxInfos[temp_v0].field7_0xe = var_s0;
                  CouteauxInfos[temp_v0].field6_0xc = var_s2;
                  CouteauxInfos[temp_v0].field4_0x8 = CouteauxInfos[temp_v0].field4_0x8 - 1;
                  param_1->speed_x = (s16) CouteauxInfos[temp_v0].field5_0xa;
                  param_1->speed_y = (s16) CouteauxInfos[temp_v0].field6_0xc;
                  CouteauxInfos[temp_v0].field4_0x8 = 0x000F;
                  CouteauxInfos[temp_v0].field2_0x4 = 0;
                  CouteauxInfos[temp_v0].active = 0;
                  temp_v1_6 = &param_1->eta[param_1->main_etat][param_1->sub_etat];
                  temp_v1_6->anim_speed = (temp_v1_6->anim_speed & 0xF0) | 2;
                  param_1->gravity_value_1 = 0;
                  param_1->gravity_value_2 = 8;
                  return;
                }
                if (temp_v1_4 == 3)
                {
                  param_1->sub_etat = var_s5;
                  param_1->anim_frame = var_s0;
                  CouteauxInfos[temp_v0].field5_0xa = var_s3;
                  CouteauxInfos[temp_v0].field7_0xe = var_s0;
                  CouteauxInfos[temp_v0].field6_0xc = var_s2;
                  CouteauxInfos[temp_v0].field4_0x8 = CouteauxInfos[temp_v0].field4_0x8 - 1;
                  param_1->speed_x = (s16) CouteauxInfos[temp_v0].field5_0xa;
                  param_1->speed_y = (s16) CouteauxInfos[temp_v0].field6_0xc;
                  CouteauxInfos[temp_v0].field4_0x8 = 0x000F;
                  CouteauxInfos[temp_v0].field2_0x4 = 0;
                  CouteauxInfos[temp_v0].active = 0;
                  return;
                }
                if (param_1->anim_frame == (var_s0 & 0xFF))
                {
                  param_1->sub_etat = var_s5;
                  param_1->anim_frame = var_s0;
                  CouteauxInfos[temp_v0].field7_0xe = var_s0;
                  CouteauxInfos[temp_v0].field5_0xa = var_s3;
                  CouteauxInfos[temp_v0].field6_0xc = var_s2;
                  CouteauxInfos[temp_v0].field4_0x8 = CouteauxInfos[temp_v0].field4_0x8 - 1;
                }
            }
            else
            {
                if (temp_v1_2 == 0)
                {
                    param_1->speed_x = (s16) CouteauxInfos[temp_v0].field5_0xa;
                    param_1->speed_y = (s16) CouteauxInfos[temp_v0].field6_0xc;
                    if (CouteauxInfos[temp_v0].field9_0x10 == 2)
                    {
                      temp_v1_7 = &param_1->eta[param_1->main_etat][param_1->sub_etat];
                      temp_v1_7->anim_speed = (temp_v1_7->anim_speed & 0xF0) | 2;
                      param_1->gravity_value_1 = 0;
                      param_1->gravity_value_2 = 8;
                    }
                    CouteauxInfos[temp_v0].field4_0x8 = 0x000F;
                    CouteauxInfos[temp_v0].field2_0x4 = 0;
                    CouteauxInfos[temp_v0].active = 0;
                    return;
                }
                param_1->speed_x = 0;
                param_1->speed_y = 0;
                param_1->anim_frame = CouteauxInfos[temp_v0].field7_0xe;
                if (CouteauxInfos[temp_v0].field4_0x8 & 1)
                {
                    var_v0_3 = param_1->y_pos + 2;
                }
                else
                {
                    var_v0_3 = param_1->y_pos - 2;
                }
                param_1->y_pos = var_v0_3;
                if (CouteauxInfos[temp_v0].field4_0x8 > 0)
                {
                    CouteauxInfos[temp_v0].field4_0x8--;
                }
            }
        }
        else
        {
            if (temp_v0_2 >= 2)
            {
                CouteauxInfos[temp_v0].field2_0x4--;
            }
            if (CouteauxInfos[temp_v0].field2_0x4 == 1)
            {
                CouteauxInfos[temp_v0].field4_0x8 = 0x000F;
            }
        }
    }
}