#include "obj/dark_phase2.h"

/* rodata is only thing that isn't matching */
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK_PHASE2_COMMAND);*/

void DO_DARK_PHASE2_COMMAND(Obj *obj)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    Obj *temp_v0;
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_s0;
    s16 temp_s1;
    s16 var_a0;
    s16 var_a1;
    s16 var_v0_2;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a0_6;
    u8 temp_v1;
    u8 var_a2;
    u8 var_v0;

    if ((obj->main_etat == 0) && (obj->sub_etat == 0x26))
    {
        RayEvts.flags0 &= 0xFE;
        RayEvts.flags1 &= 0x7F;
        sinus_actif = 0;
        flammes_actives = 0;
        phase_dark2 = 0;
        TextDark2_Affiche = 0;
        scroll_end_x = 0;
        scroll_start_x = 0;
        ToonJustGivePoing = 0;
        dark_obj->flags &= ~0x400;
        dark_obj->flags &= ~0x800;
    }
    switch (phase_dark2)
    {
    case 0:
        if (sinus_actif != 0)
        {
            if (sinus_actif == 2)
            {
                phase_dark2 = 1;
            }
        }
        else
        {
            sinus_actif = 1;
            set_sub_etat(obj, 0x1EU);
        }
        break;
    case 1:
        if (flammes_actives == 0)
        {
            flammes_actives = 1;
            set_sub_etat(obj, 0x1FU);
        }
        else if (flammes_actives == 2)
        {
            temp_a0_2 = level.objects[flamme_gauche_id].cmd;
            if ((temp_a0_2 == 0x1E) && (level.objects[flamme_droite_id].cmd == temp_a0_2))
            {
                skipToLabel(&level.objects[flamme_droite_id], 2U, 1U);
                skipToLabel(&level.objects[flamme_gauche_id], 2U, 1U);
                phase_dark2 = 2;
            }
        }
        break;
    case 2:
        temp_a0_3 = level.objects[flamme_gauche_id].cmd;
        if (temp_a0_3 == 0x1E)
        {
            if (level.objects[flamme_droite_id].cmd == temp_a0_3)
            {
                phase_dark2 = 3;
                sinus_actif = 0;
            }
        }
        break;
    case 3:
        if (sinus_actif != 0)
        {
            if (sinus_actif == 2)
            {
                phase_dark2 = 4;
            }
        }
        else
        {
            sinus_actif = 1;
            set_sub_etat(obj, 0x1EU);
        }
        break;
    case 4:
        skipToLabel(&level.objects[flamme_droite_id], 3U, 1U);
        skipToLabel(&level.objects[flamme_gauche_id], 3U, 1U);
        phase_dark2 = 5;
        break;
    case 5:
        temp_a0_4 = level.objects[flamme_gauche_id].cmd;
        if ((temp_a0_4 == 0x1E) && (level.objects[flamme_droite_id].cmd == temp_a0_4))
        {
            if (sinus_actif != 0)
            {
                if (sinus_actif == 2)
                {
                    phase_dark2 = 6;
                    sinus_actif = 0;
                }
            }
            else
            {
                sinus_actif = 1;
                set_sub_etat(obj, 0x1EU);
            }
        }
        else
        {
            sinus_actif = 0;
        }
        break;
    case 6:
        if (sinus_actif == 0)
        {
            skipToLabel(&level.objects[flamme_droite_id], 2U, 1U);
            skipToLabel(&level.objects[flamme_gauche_id], 2U, 1U);
            sinus_actif = 1;
            set_sub_etat(obj, 0x1EU);
        }
        else if (sinus_actif == 2)
        {
            temp_a0_5 = level.objects[flamme_gauche_id].cmd;
            if (temp_a0_5 == 0x1E)
            {
                if (level.objects[flamme_droite_id].cmd == temp_a0_5)
                {
                    phase_dark2 = 7;
                    sinus_actif = 0;
                }
            }
        }
        break;
    case 7:
        if (obj->sub_etat != 0x21)
        {
            set_sub_etat(obj, 0x21U);
            num_dark2_phrase = 0;
            TextDark2_Affiche = 1;
        }
        else if (num_dark2_phrase == 2)
        {
            set_sub_etat(obj, 0x20U);
            phase_dark2 = 8;
            TextDark2_Affiche = 0;
        }
        break;
    case 8:
        skipToLabel(&level.objects[flamme_gauche_id], 4U, 1U);
        phase_dark2 = 9;
        PosArXToon1 = -1;
        break;
    case 9:
        if (RayEvts.flags0 & 1)
        {
            phase_dark2 = 0x000A;
        }
        else if ((PosArXToon1 == -1) && (level.objects[flamme_gauche_id].speed_x == 4))
        {
            AllocateToons(level.objects);
            PosArXToon1 = (u16) level.objects[poing_obj_id].x_pos + 0x40;
            PosArYToon1 = (u16) level.objects[poing_obj_id].y_pos + 0x32;
            PosArXToon2 = (u16) level.objects[poing_obj_id].x_pos + 0x30;
            PosArYToon2 = (u16) level.objects[poing_obj_id].y_pos + 0x32;
        }
        break;
    case 10:
        set_main_and_sub_etat(&level.objects[flamme_gauche_id], 0U, 4U);
        set_main_and_sub_etat(&level.objects[flamme_droite_id], 0U, 4U);
        phase_dark2 = 0x000B;
        break;
    case 11:
        if ((ToonJustGivePoing == 1) && (((u8) block_flags[(u16) *((ray.ray_dist) + mp.map) >> 0xA] >> 1) & 1) && ((ray.main_etat != 3) || (ray.sub_etat != 0x17)))
        {
            ToonJustGivePoing = 2;
            set_main_and_sub_etat(&ray, 3U, 0x17U);
            ray.speed_x = 0;
            ray.speed_y = 0;
        }
        if (!(level.objects[flamme_gauche_id].flags & 0x800) && ((temp_a0_6 = obj->main_etat, (temp_a0_6 != 0)) || (obj->sub_etat != 0x22)) && ((temp_a0_6 != 2) || (obj->sub_etat != 1)) && ((ray.main_etat != 3) || (ray.sub_etat != 0x17)) && (ToonJustGivePoing == 2))
        {
            ToonJustGivePoing = 0;
            set_main_and_sub_etat(obj, 0U, 0x22U);
            break;
        }
        if (obj->anim_frame == 4)
        {
            if (obj->main_etat == 0)
            {
                if (obj->sub_etat == 0x22)
                {
                    obj->speed_y = -4;
                    phase_dark2 = 0x000C;
                    goto_phase3(dark_obj);
                }
            }
        }
        break;
    default:
        break;
    }

    if (obj->main_etat == 0)
    {
        temp_v1 = obj->sub_etat;
        switch (temp_v1)
        {
        case 31:
            if (obj->anim_frame == 0x16)
            {
                GET_SPRITE_POS(obj, 3, &sp18, &sp1A, &sp1C, &sp1E);
                dark2_rayon_dx_2 = 0;
                dark2_rayon_dx_1 = 0;
                dark2_rayon_dy_2 = -0x000F;
                dark2_rayon_dy_1 = -0x000F;
                temp_s1 = ((u16) sp18 + ((s32) ((u16) sp1C << 0x10) >> 0x11)) - 0x60;
                temp_s0 = ((u16) sp1A + ((s32) ((u16) sp1E << 0x10) >> 0x11)) - 0x80;
                allocate_DARK2_SORT(temp_s1, temp_s0, 0x25U, 1);
                var_a0 = temp_s1;
                var_a1 = temp_s0;
                var_a2 = 0x25;
                allocate_DARK2_SORT(var_a0, var_a1, var_a2, 0);
                return;
            }
            break;
        case 30:
            if (obj->anim_frame == 0x16)
            {
                GET_SPRITE_POS(obj, 3, &sp18, &sp1A, &sp1C, &sp1E);
                dark2_rayon_dx_2 = -0x0010;
                dark2_rayon_dx_1 = -0x0010;
                dark2_rayon_dy_1 = 0x004C;
                dark2_rayon_dy_2 = -0x004C;
                sens_sinus_1 = 0;
                sens_sinus_2 = 1;
                temp_a0 = ((u16) sp18 + ((s32) ((u16) sp1C << 0x10) >> 0x11)) - 0x60;
                PosXSin2 = temp_a0;
                PosXSin1 = temp_a0;
                temp_a1 = ((u16) sp1A + ((s32) ((u16) sp1E << 0x10) >> 0x11)) - 0x80;
                PosYSin2 = temp_a1;
                PosYSin1 = temp_a1;
                allocate_DARK2_SORT(temp_a0, temp_a1, 0x23U, 1);
                var_a0 = PosXSin2;
                var_a1 = PosYSin2;
                var_a2 = 0x23;
                allocate_DARK2_SORT(var_a0, var_a1, var_a2, 0);
                return;
            }
            break;
        case 33:
            if (num_dark2_phrase == 0)
            {
                __builtin_memcpy(txt_dark2, s_youre_doomed_rayman__8012c1e4, sizeof(s_youre_doomed_rayman__8012c1e4));
                /*txt_dark2[3] = (unaligned s32) M2C_ERROR(Unable to handle lwr; missing a corresponding lwl);
                txt_dark2[7] = (unaligned s32) M2C_ERROR(Unable to handle lwr; missing a corresponding lwl);
                txt_dark2[0xB] = (unaligned s32) M2C_ERROR(Unable to handle lwr; missing a corresponding lwl);
                txt_dark2[0xF] = (unaligned s32) M2C_ERROR(Unable to handle lwr; missing a corresponding lwl);
                txt_dark2[0x13] = (unaligned s32) M2C_ERROR(Unable to handle lwr; missing a corresponding lwl);
                txt_dark2[0x17] = (unaligned s32) M2C_ERROR(Unable to handle lwr; missing a corresponding lwl);
                txt_dark2[0x18] = (u8) s_youre_doomed_rayman__8012c1e4->unk18;
                txt_dark2[0x19] = (u8) s_youre_doomed_rayman__8012c1e4->unk19;
                txt_dark2[0x1A] = (u8) s_youre_doomed_rayman__8012c1e4->unk1A;*/
                XText = 0x00A0;
                YText = -0x000A;
                VitesseYText = 0x0028;
                temps_text = 0;
                num_dark2_phrase = 1;
                return;
            }
            if (YText < -0x14)
            {
                temps_text = 0;
                XText = 0x00A0;
                YText = -0x000A;
                VitesseYText = 0x0028;
                num_dark2_phrase += 1;
                return;
            }
            YText = (u16) YText + ashr16(VitesseYText, 4U);
            if (VitesseYText != 0)
            {
                if (horloge[4] == 0)
                {
                    VitesseYText--;
                }
            }
            else
            {
                if (horloge[6] == 0)
                {
                    VitesseYText--;
                }
            }
            break;
        }
    }
    else
    {
        return;
    }
}

/* matches, but goto */
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK2_SORT_COMMAND);*/

void DO_DARK2_SORT_COMMAND(Obj *param_1)
{
    s16 temp_v0_1;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v1;
    s32 var_a0;
    s16 var_a0_2;
    s16 var_a1;
    s16 var_a1_2;
    s16 var_a1_3;
    s16 var_a1_5;
    s16 var_s2;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 var_v1_2;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 var_a1_4;
    s32 var_v0;
    s32 var_v1;
    s16 test_1;

    if (param_1->hit_points != 0)
    {
        if (param_1->sub_etat == 0x23 || param_1->sub_etat == 0x24)
        {
            if (param_1->x_pos < -(s32) param_1->offset_bx)
            {
                sinus_actif = 2;
                param_1->hit_points = 0;
                return;
            }
            if (param_1->iframes_timer != 0)
            {
                if (sens_sinus_1 != 0)
                {
                    dark2_rayon_dy_1 = dark2_rayon_dy_1 + 3;
                    if (dark2_rayon_dy_1 >= 0x4D)
                    {
                        sens_sinus_1 = 0;
                    }
                }
                else
                {
                    dark2_rayon_dy_1 = dark2_rayon_dy_1 - 3;
                    if (dark2_rayon_dy_1 < -0x4C)
                    {
                        sens_sinus_1 = 1;
                    }
                }
                PosXSin1 = PosXSin1 + ashr16(dark2_rayon_dx_1, 4U);
                var_a1 = PosYSin1 + ashr16(dark2_rayon_dy_1, 4U);
                PosYSin1 = var_a1;
                if (param_1->anim_frame == 1)
                {
                    var_a0 = PosXSin1;
block_1:
                    allocate_DARK2_SORT(var_a0, var_a1, param_1->sub_etat, param_1->iframes_timer);
                    param_1->hit_points = 0;
                }
            }
            else
            {
                if (sens_sinus_2 != 0)
                {
                    dark2_rayon_dy_2 = dark2_rayon_dy_2 + 3;
                    if (dark2_rayon_dy_2 >= 0x4D)
                    {
                        sens_sinus_2 = 0;
                    }
                }
                else
                {
                    dark2_rayon_dy_2 = dark2_rayon_dy_2 - 3;
                    if (dark2_rayon_dy_2 < -0x4C)
                    {
                        sens_sinus_2 = 1;
                    }
                }
                PosXSin2 = PosXSin2 + ashr16(dark2_rayon_dx_2, 4U);
                var_a1 = PosYSin2 + ashr16(dark2_rayon_dy_2, 4U);
                PosYSin2 = var_a1;
                if (param_1->anim_frame == 1)
                {
                    var_a0 = PosXSin2;
goto block_1;
                }
            }
        }
        else if (param_1->sub_etat == 0x25)
        {
            if (param_1->iframes_timer != 0)
            {
                var_s2 = 0xF0 - (param_1->offset_bx + param_1->x_pos);
            }
            else
            {
                var_s2 = 5 - (param_1->offset_bx + param_1->x_pos);
            }
            temp_v0_5 = firstFloorBelow(param_1) - (param_1->offset_by + param_1->y_pos);
            var_a1_2 = temp_v0_5;
            temp_v1 = __builtin_abs(var_s2) + __builtin_abs(temp_v0_5);
            if (temp_v1 < 0xA)
            {
                param_1->hit_points = 0;
                AllocateFlammes(param_1->iframes_timer);
                return;
            }
            if (temp_v1 > 0)
            {
                temp_v0_6 = ashl16(var_s2, 4U);
                var_s2 = (s16) (temp_v0_6 / temp_v1);
                temp_v0_7 = ashl16(temp_v0_5, 4U);
                var_a1_2 = (s16) (temp_v0_7 / temp_v1);
            }
            if (param_1->anim_frame == 1)
            {
                if (param_1->iframes_timer != 0)
                {
                    temp_v0_8 = var_s2 - dark2_rayon_dx_1;
                    if (temp_v0_8 >= 0)
                    {
                        dark2_rayon_dx_1 = dark2_rayon_dx_1 + (temp_v0_8 > 0);
                    }
                    else
                    {
                        dark2_rayon_dx_1 = dark2_rayon_dx_1 - (test_1 = 1);
                    }
                    temp_v0_9 = var_a1_2 - dark2_rayon_dy_1;
                    if (temp_v0_9 >= 0)
                    {
                        var_a1_3 = dark2_rayon_dy_1 + (temp_v0_9 > 0);
                    }
                    else
                    {
                        var_a1_3 = dark2_rayon_dy_1 - (test_1 = 1);
                    }
                    dark2_rayon_dy_1 = var_a1_3;
                    var_a0_2 = dark2_rayon_dx_1;
                    allocate_DARK2_SORT(param_1->x_pos + var_a0_2, param_1->y_pos + var_a1_3, param_1->sub_etat, param_1->iframes_timer);
                    param_1->hit_points = 0;
                }
                else
                {
                    temp_v0_10 = var_s2 - dark2_rayon_dx_2;
                    if (temp_v0_10 >= 0)
                    {
                        var_v0_4 = dark2_rayon_dx_2 + (temp_v0_10 > 0);
                    }
                    else
                    {
                        var_v0_4 = dark2_rayon_dx_2 - (test_1 = 1);
                    }
                    dark2_rayon_dx_2 = var_v0_4;
                    temp_v0_11 = var_a1_2 - dark2_rayon_dy_2;
                    if (temp_v0_11 >= 0)
                    {
                        var_a1_5 = dark2_rayon_dy_2 + (temp_v0_11 > 0);
                    }
                    else
                    {
                        var_a1_5 = dark2_rayon_dy_2 - (test_1 = 1);
                    }
                    dark2_rayon_dy_2 = var_a1_5;
                    var_a0_2 = dark2_rayon_dx_2;
                    allocate_DARK2_SORT(param_1->x_pos + var_a0_2, param_1->y_pos + var_a1_5, param_1->sub_etat, param_1->iframes_timer);
                    param_1->hit_points = 0;
                }
            }
        }
    }
}

/*INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", allocate_DARK2_SORT);*/

void allocate_DARK2_SORT(s32 param_1, s16 param_2, s16 param_3, s16 param_4)
{
    Obj *temp_t6;
    Obj *var_a0_1;
    Obj *var_a0_2;
    Obj *var_a0_3;
    Obj *var_a0_4;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 var_t2;
    s32 var_t1;
    s32 var_t1_2;
    s32 var_t1_3;
    Obj *var_v1_1;
    Obj *var_v1_2;
    Obj *var_v1_3;
    s16 nb_objs;
    int new_var;

    var_t1 = 0;
    var_t2 = 0;
    var_a0_1 = level.objects;
    nb_objs = level.nb_objects;
loop_1:
    do
    {
        if ((var_a0_1->type == 0x21) && !(var_a0_1->flags & 0x800))
        {
            var_t1 = 1;
        }
        var_a0_1 += 1;
        var_t2 = var_t2 + 1;
    } while ((var_t1 == 0) && (var_t2 < nb_objs));
    
    var_a0_2 = var_a0_1 - 1;
    if (var_t1 != 0)
    {
        temp_t6 = var_a0_2;
        var_t1_2 = 0;
        new_var = 0;
loop_8:
        do
        {
            if ((var_a0_2->type == 0x21) && (var_a0_2->flags & 0x800))
            {
                var_t1_2 = 1;
            }
            var_a0_2 += 1;
            var_t2 = var_t2 + 1;
        } while ((var_t1_2 == 0) && (var_t2 < nb_objs));
        var_a0_3 = var_a0_2 - 1;
        if (var_t1_2 != 0)
        {
            var_t1_3 = 0;
loop_15:
            do
            {
                if ((var_a0_3->type == 0x21) && !(var_a0_3->flags & 0x800))
                {
                    var_t1_3 = 1;
                }
                var_a0_3 += 1;
                temp_v0_3 = var_t2 + 1;
                var_t2 = temp_v0_3;
            } while ((var_t1_3 == 0) && (temp_v0_3 < nb_objs));
            var_a0_4 = var_a0_3 - 1;
            if (var_t1_3 == 0)
            {
                goto block_21;
            }
            goto block_22;
        }
block_21:
        var_a0_4 = temp_t6;
        if (1 != 0)
        {
block_22:
            var_a0_4->x_pos = (s16) param_1;
            var_a0_4->y_pos = param_2;
            var_a0_4->hit_points = 1;
            var_a0_4->iframes_timer = param_4;
            var_a0_4->field23_0x3c = 0;
            var_a0_4->flags |= 0xC00;
            set_main_and_sub_etat(var_a0_4, 0, param_3);
        }
    }
}
