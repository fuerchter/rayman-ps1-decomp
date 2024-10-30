#include "obj/mama_pirate.h"

/* matches, but... clean up (see TODO:) */
/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_lineaire);*/

/* 279B8 8014C1B8 -O2 -msoft-float */
void lance_couteau_lineaire(Obj *in_obj)
{
    Obj *cout_obj;
    u8 cout_ind;
    s16 unk_1;
    s16 cout_x;
    s16 cout_y;
    s16 unk_2;
    ObjState *temp_v1_6;
    s16 diff_x;
    s16 diff_y;
    s32 unk_3;
    u8 unk_sub_etat;
    s32 var_v1;
    s16 unk_4;
    s16 var_s2;
    s16 var_s3;
    s32 var_a0;
    u8 var_s0;
    u8 temp_v1_4;
    ObjState *temp_v1_7;
    s16 var_v0_3;

    cout_ind = find_couteau(in_obj);
    if (cout_ind != 0xFF && (cout_ind == 0 || CouteauxInfos[cout_ind - 1].field2_0x4 == 0))
    {
        unk_1 = CouteauxInfos[cout_ind].field2_0x4;
        if (unk_1 == 0)
        {
            if (!CouteauxInfos[cout_ind].active)
            {
                cout_obj = &level.objects[CouteauxInfos[cout_ind].id];
                cout_x = cout_obj->x_pos + cout_obj->offset_bx;
                cout_y = cout_obj->y_pos + cout_obj->offset_by;
                if (
                    cout_x < -20 || (cout_x > xmapmax + 340) ||
                    cout_y < -20 || (cout_y > ymapmax + 260)
                )
                {
                    CouteauxInfos[cout_ind].active = true;
                    level.objects[CouteauxInfos[cout_ind].id].flags &= ~FLG(OBJ_ACTIVE);
                    level.objects[CouteauxInfos[cout_ind].id].flags &= ~FLG(OBJ_ALIVE);
                    if (check_couteaux())
                    {
                        pma_phase = 4;
                        if (level.objects[mama_pirate_obj_id].hit_points == 0)
                        {
                            fin_boss = true;
                            finBosslevel.viking_mama = true;
                        }
                    }
                }
            }
        }
        else if (unk_1 == 1)
        {
            unk_2 = CouteauxInfos[cout_ind].field4_0x8;
            if (unk_2 == 0x000F)
            {
                CouteauxInfos[cout_ind].x_pos = ray.x_pos + ray.offset_bx;
                CouteauxInfos[cout_ind].y_pos = ray.y_pos + ray.offset_by;
                diff_x = CouteauxInfos[cout_ind].x_pos - (in_obj->x_pos + in_obj->offset_bx);
                diff_y = CouteauxInfos[cout_ind].y_pos - (in_obj->y_pos + in_obj->offset_by);
                switch(CouteauxInfos[cout_ind].field9_0x10) /* TODO: continue cleaning up from here*/
                {
                case 1:
                    unk_sub_etat = 11;
                    unk_3 = MAX_1(__builtin_abs(diff_x), __builtin_abs(diff_y));
                    unk_4 = 4;
                    unk_4 = ashl16(unk_3, 4U) / unk_4;
                    var_s3 = convertspeed(ashl16(diff_x, 4U) / unk_4);
                    var_s2 = convertspeed(ashl16(diff_y, 4U) / unk_4);
                    var_s0 = couteau_frame(var_s3, var_s2);
                    break;
                case 3:
                    unk_sub_etat = 11;
                    var_s3 = convertspeed(0);
                    var_s2 = convertspeed(3);
                    var_s0 = couteau_frame(var_s3, var_s2);
                    break;
                case 0:
                    unk_sub_etat = 11;
                    var_a0 = -3;
                    if (diff_x >= 0)
                    {
                        var_a0 = 3;
                    }
                    var_s3 = convertspeed(var_a0);
                    var_s2 = convertspeed(0);
                    var_s0 = couteau_frame(var_s3, var_s2);
                    break;
                case 2:
                    unk_sub_etat = 14;
                    var_s3 = convertspeed(-1);
                    var_s2 = convertspeed(5);
                    var_s0 = couteau_frame(0, 1);
                    break;
                }
                temp_v1_4 = CouteauxInfos[cout_ind].field9_0x10;
                if (temp_v1_4 == 2)
                {
                    in_obj->sub_etat = unk_sub_etat;
                    in_obj->anim_frame = var_s0;
                    in_obj->eta[in_obj->main_etat][in_obj->sub_etat].anim_speed &= 0xF0;
                    CouteauxInfos[cout_ind].field5_0xa = var_s3;
                    CouteauxInfos[cout_ind].field7_0xe = var_s0;
                    CouteauxInfos[cout_ind].field6_0xc = var_s2;
                    CouteauxInfos[cout_ind].field4_0x8 = CouteauxInfos[cout_ind].field4_0x8 - 1;
                    in_obj->speed_x = (s16) CouteauxInfos[cout_ind].field5_0xa;
                    in_obj->speed_y = (s16) CouteauxInfos[cout_ind].field6_0xc;
                    CouteauxInfos[cout_ind].field4_0x8 = 0x000F;
                    CouteauxInfos[cout_ind].field2_0x4 = 0;
                    CouteauxInfos[cout_ind].active = 0;
                    temp_v1_6 = &in_obj->eta[in_obj->main_etat][in_obj->sub_etat];
                    temp_v1_6->anim_speed = (temp_v1_6->anim_speed & 0xF0) | 2;
                    in_obj->gravity_value_1 = 0;
                    in_obj->gravity_value_2 = 8;
                    return;
                }
                if (temp_v1_4 == 3)
                {
                    in_obj->sub_etat = unk_sub_etat;
                    in_obj->anim_frame = var_s0;
                    CouteauxInfos[cout_ind].field5_0xa = var_s3;
                    CouteauxInfos[cout_ind].field7_0xe = var_s0;
                    CouteauxInfos[cout_ind].field6_0xc = var_s2;
                    CouteauxInfos[cout_ind].field4_0x8 = CouteauxInfos[cout_ind].field4_0x8 - 1;
                    in_obj->speed_x = (s16) CouteauxInfos[cout_ind].field5_0xa;
                    in_obj->speed_y = (s16) CouteauxInfos[cout_ind].field6_0xc;
                    CouteauxInfos[cout_ind].field4_0x8 = 0x000F;
                    CouteauxInfos[cout_ind].field2_0x4 = 0;
                    CouteauxInfos[cout_ind].active = 0;
                    return;
                }
                if (in_obj->anim_frame == (var_s0 & 0xFF))
                {
                    in_obj->sub_etat = unk_sub_etat;
                    in_obj->anim_frame = var_s0;
                    CouteauxInfos[cout_ind].field7_0xe = var_s0;
                    CouteauxInfos[cout_ind].field5_0xa = var_s3;
                    CouteauxInfos[cout_ind].field6_0xc = var_s2;
                    CouteauxInfos[cout_ind].field4_0x8 = CouteauxInfos[cout_ind].field4_0x8 - 1;
                }
            }
            else if (unk_2 == 0)
            {
                in_obj->speed_x = (s16) CouteauxInfos[cout_ind].field5_0xa;
                in_obj->speed_y = (s16) CouteauxInfos[cout_ind].field6_0xc;
                if (CouteauxInfos[cout_ind].field9_0x10 == 2)
                {
                    temp_v1_7 = &in_obj->eta[in_obj->main_etat][in_obj->sub_etat];
                    temp_v1_7->anim_speed = (temp_v1_7->anim_speed & 0xF0) | 2;
                    in_obj->gravity_value_1 = 0;
                    in_obj->gravity_value_2 = 8;
                }
                CouteauxInfos[cout_ind].field4_0x8 = 0x000F;
                CouteauxInfos[cout_ind].field2_0x4 = 0;
                CouteauxInfos[cout_ind].active = 0;

            }
            else
            {
                in_obj->speed_x = 0;
                in_obj->speed_y = 0;
                in_obj->anim_frame = CouteauxInfos[cout_ind].field7_0xe;
                if (CouteauxInfos[cout_ind].field4_0x8 & 1)
                {
                    var_v0_3 = in_obj->y_pos + 2;
                }
                else
                {
                    var_v0_3 = in_obj->y_pos - 2;
                }
                in_obj->y_pos = var_v0_3;
                if (CouteauxInfos[cout_ind].field4_0x8 > 0)
                {
                    CouteauxInfos[cout_ind].field4_0x8--;
                }
            }
        }
        else
        {
            if (unk_1 > 1)
            {
                CouteauxInfos[cout_ind].field2_0x4--;
            }
            if (CouteauxInfos[cout_ind].field2_0x4 == 1)
            {
                CouteauxInfos[cout_ind].field4_0x8 = 0x000F;
            }
        }
    }
}