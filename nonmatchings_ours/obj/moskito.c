#include "obj/moskito.h"

/* matches, but block_52 */
/* 6FDC8 801945C8 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/moskito", prepareNewMoskitoAttack);*/

/*? ChangeLevel(s32);
? calc_obj_dir(Obj *);
? setBossReachingSpeeds(Obj *, ?, ?, ?);
? set_main_and_sub_etat(Obj *, ?, ?, u16);
? skipToLabel(Obj *, ?, ?);
s32 vblToEOA(Obj *, ?);*/

void prepareNewMoskitoAttack(Obj *arg0)
{
    Obj *cur_obj;
    s16 floor_1;
    s16 floor_2;
    s32 new_x;
    s32 new_y;
    s16 temp_v0_7;
    s16 i;
    s16 var_v0;
    s16 new_x_2;
    s16 flag_before;
    s32 temp_s0_2;
    u16 x_pos;
    u32 temp_s7;
    u32 temp_v0;
    u32 flag_after;
    u8 **seq_2;
    u8 *seq_1;
    u8 curAct_tmp_1;
    u8 curAct_tmp_2;
    u8 temp_v0_5;
    u8 temp_v1;
    u8 act_ind_1;
    u8 act_0x1A;
    u8 act_ind_2;
    u8 curAct_tmp_3;
    u8 curAct_tmp_4;
    u8 curAct_tmp_5;
    s32 act_0x0E;
    u8 nb_obj;
    s32 half_wid;
    u8 *seq_2_tmp_2;
    u8 *seq_2_tmp_3;
    u8 **seq_2_tmp_1;
    
    temp_v0 = scroll_start_x + scroll_end_x + 0x140;
    temp_s7 = (temp_v0 + (temp_v0 >> 0x1F)) >> 1;
    if (currentBossActionIsOver != 0)
    {
        do
        {
            temp_v1 = currentBossAction;
            seq_1 = moskitoActionSequences[bossEncounter];
            currentBossAction = temp_v1 + 1;
            curAct = seq_1[temp_v1];
            alternateBossSpeedFactor = 0;
            switch (curAct)
            {
            case 3:
                bossEncounter += 1;
            case 2:
                currentBossAction = 0;
                currentBossActionIsOver = 1;
                break;
            case 5:
                bossEncounter = saveBossEncounter;
                currentBossAction = saveCurrentBossAction;
                seq_2 = &moskitoActionSequences[bossEncounter];
                curAct_tmp_1 = (*seq_2)[currentBossAction];
                curAct = curAct_tmp_1;
                if (curAct == 0x1A || curAct == 0x0E)
                {
                    while (curAct == 0x1A || curAct == 0x0E)
                    {
                        curAct = moskitoActionSequences[bossEncounter][++currentBossAction];
                    }
                }
                else if ((curAct_tmp_1 - 0x12) < 2U || (curAct == 0x15))
                {
                    if (curAct == 0x15)
                    {
                        currentBossAction = saveCurrentBossAction + 1;
                    }
                    seq_2_tmp_3 = *seq_2;

                    currentBossAction = currentBossAction + 1;
                    temp_v0_5 = currentBossAction & 0xFF;
                    curAct_tmp_2 = seq_2_tmp_3[temp_v0_5];
                    curAct = curAct_tmp_2;
                    if ((u8)(curAct_tmp_2 - 0x14) < 2)
                    {
                        seq_2_tmp_1 = seq_2;
                        do
                        {
                            if (curAct == 0x15)
                            {
                                currentBossAction += 1;
                            }
                            temp_v0_5 = currentBossAction + 1;
                            seq_2_tmp_2 = *seq_2_tmp_1;
                            currentBossAction = temp_v0_5;
                            curAct_tmp_2 = seq_2_tmp_2[temp_v0_5 & 0xFF];
                            curAct = curAct_tmp_2;
                        } while ((u32) (curAct_tmp_2 - 0x14) < 2U);
                    }
                }
block_19:
                saveBossEncounter = 0xFF;
                currentBossActionIsOver = 1;
                mstMustLeaveScreenToProceed = 0;
                break;
            case 12:
                act_ind_2 = currentBossAction;
                currentBossAction = act_ind_2 + 1;
                curAct_tmp_3 = moskitoActionSequences[bossEncounter][act_ind_2];
                currentBossAction = 0;
                if (curAct_tmp_3 == bossEncounter)
                {
                    bossEncounter += 1;
                }
                else
                {
                    bossEncounter = curAct_tmp_3;
                }
                currentBossActionIsOver = 0;
                break;
            case 25:
                if (arg0->init_hit_points == 5)
                {
                    ChangeLevel();
                    finBosslevel.bzzit = true;
                }
                else
                {
                    remoteRayXToReach = -0x7D00;
                    finBosslevel.moskito = true;
                    set_main_and_sub_etat(&ray, 3, 0x34);
                    arg0->nb_cmd = vblToEOA(&ray, 1) + 1;
                    fin_boss = 1;
                }
                currentBossActionIsOver = 0;
                break;
            case 22:
                if (arg0->init_hit_points == 0x0C)
                {
                    set_main_and_sub_etat(arg0, 0, 0x13);
                }
                else
                {
                    cur_obj = level.objects;
                    i = 0;
                    nb_obj = level.nb_objects;
                    if (nb_obj != 0)
                    {
                        do {
                            if (cur_obj->type == 0xAB)
                            {
                                arg0->sprites = cur_obj->sprites;
                                arg0->animations = cur_obj->animations;
                                arg0->img_buffer = cur_obj->img_buffer;
                                arg0->eta = cur_obj->eta;
                                arg0->main_etat = cur_obj->main_etat;
                                arg0->sub_etat = cur_obj->sub_etat;
                                arg0->anim_index = cur_obj->anim_index;
                                arg0->anim_frame = 0;
                                arg0->offset_by += 4;
                                arg0->flags &= ~0x4000;
                                
                                ray.flags &= ~0x800;
                                break;
                            }
                            i = i + 1;
                            cur_obj += 1;
                        } while(i < nb_obj);
                    }
                }
                skipToLabel(arg0, 1, 1);
                currentBossActionIsOver = 0;
                arg0->nb_cmd = arg0->nb_cmd + 0x80;
                break;
            case 24:
                if (arg0->init_hit_points == 0x0C)
                {
                    arg0->offset_by += 0xF0;
                }
                half_wid = 160;
                new_x = (u16)scroll_start_x - (arg0->offset_bx - half_wid);
                bossXToReach = new_x;
                arg0->x_pos = new_x;
                arg0->flags &= ~0x4000;
                bossYToReach = floorLine - arg0->offset_by;
                set_main_and_sub_etat(arg0, 2, 1);
                skipToLabel(arg0, 2, 1);
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0;
                bossReachingTimer = 1;
                currentBossActionIsOver = 0;
                break;
            case 17:
                half_wid = 160;
                bossXToReach = scroll_start_x - (arg0->offset_bx - half_wid);
                new_y = (u16)floorLine - 0xE6;
                bossYToReach = new_y;
                set_main_and_sub_etat(arg0, 0, 6);
block_88:
                skipToLabel(arg0, 2, 1);
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                setBossReachingSpeeds(arg0, 1, 0xFF, 0xFF);
                currentBossActionIsOver = 0;
                break;
            case 16:
                set_main_and_sub_etat(arg0, 0, 5);
                skipToLabel(arg0, 1, 1);
                currentBossActionIsOver = 0;
                break;
            case 6:
                set_main_and_sub_etat(arg0, 0, 0xD);
                skipToLabel(arg0, 1, 1);
                currentBossActionIsOver = 0;
                break;
            case 26:
                temp_s0_2 = arg0->main_etat == 0;
                if (temp_s0_2 && (arg0->sub_etat == 0x14))
                {
                    calc_obj_dir(arg0);
                    set_main_and_sub_etat(arg0, 0, 0x15);
                    skipToLabel(arg0, 1, 1);
                    currentBossActionIsOver = 0;
                    break;
                }
                flag_before = (arg0->flags >> 0xE) & 1;
                calc_obj_dir(arg0);
                flag_after = arg0->flags;
                if (((flag_after >> 0xE) & 1) != flag_before)
                {
                    arg0->flags = (flag_after & ~0x4000) | (flag_before << 0xE);
                    set_main_and_sub_etat(arg0, 0, 0x15);
                    temp_s0_2 = vblToEOA(arg0, 1);
                    set_main_and_sub_etat(arg0, 0, 0x16);
                    skipToLabel(arg0, 1, 1);
                    currentBossActionIsOver = 0;
                    arg0->nb_cmd = temp_s0_2 + arg0->nb_cmd;
                }
                break;
            case 23:
                /* nop here somewhere */
                temp_v0_7 = scroll_start_x - arg0->offset_bx + 0x70;
                remoteRayXToReach = temp_v0_7;
                if (ray.x_pos & 1)
                {
                    remoteRayXToReach = temp_v0_7 | 1;
                }
                else
                {
                    remoteRayXToReach = temp_v0_7 & 0xFFFE;
                }
                goto block_52;
            case 11:
                bossSafeTimer = 0;
                arg0->display_prio = 3;
                if (mstMustLeaveScreenToProceed == 0)
                {
                    currentBossActionIsOver = 1;
                }
                else
                {
                    mstMustLeaveScreenToProceed = 0;
                    curAct = 4;
                    goto block_52;
                }
                break;
            case 4:
block_52:
                bossXToReach = arg0->x_pos;
                bossYToReach = scroll_start_y - 0x80;
                if (curAct == 4)
                {
                    set_main_and_sub_etat(arg0, 0, 8);
                }
                else
                {
                    set_main_and_sub_etat(arg0, 0, 6);
                }
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                setBossReachingSpeeds(arg0, 1, 0xFF, 0xFF);
                skipToLabel(arg0, 2, 1);
                currentBossActionIsOver = 0;
                break;
            case 15:
                set_main_and_sub_etat(arg0, 0, 0x14);
                skipToLabel(arg0, 1, 1);
                currentBossActionIsOver = 0;
                break;
            case 14:
                set_main_and_sub_etat(arg0, 0, 0xF);
                skipToLabel(arg0, 1, 1);
                currentBossActionIsOver = 0;
                break;
            case 10:
                calc_obj_dir(arg0);
                setMoskitoAtScrollBorder(arg0, ((arg0->flags >> 0xE) ^ 1) & 1);
                arg0->y_pos = scroll_start_y - 0x80;
                if (arg0->flags & 0x4000)
                {
                    arg0->x_pos = arg0->x_pos - 0x30;
                    flag_after = arg0->flags & ~0x4000;
                }
                else
                {
                    arg0->x_pos = arg0->x_pos + 0x30;
                    flag_after = arg0->flags | 0x4000;
                }
                arg0->flags = flag_after;
                
            case 13:
                fistAvoided = 0;
                flag_before = (arg0->flags >> 0xE) & 1;
                calc_obj_dir(arg0);
                getIdealStingCoords(arg0, &bossXToReach, &bossYToReach);
                set_main_and_sub_etat(arg0, 0, 8);
                bossReachingAccuracyX = 0x10;
                bossReachingAccuracyY = 0x10;
                bossReachingTimer = 2;
                setBossReachingSpeeds(arg0, 1, 0xFF, 0xFF);
                if (curAct == 0x0D)
                {
                    arg0->speed_y = -0x0040;
                }
                else
                {
                    arg0->speed_x = 0;
                }
                arg0->flags = (arg0->flags & ~0x4000) | (flag_before << 0xE);
                skipToLabel(arg0, 2, 1);
                currentBossActionIsOver = 0;
                break;
            case 7:
                set_main_and_sub_etat(arg0, 0, 0xC);
                
            case 8:
                if (curAct == 8)
                {
                    set_main_and_sub_etat(arg0, 0, 0xB);
                }
                if ((setMoskitoAtScrollBorder(arg0, 2U) << 0x10) > 0)
                {
                    arg0->flags &= ~0x4000;
                    arg0->x_pos = (temp_v0_7 = arg0->x_pos + 0x30); /* gross, undo? */
                    bossXToReach = (scroll_start_x - arg0->offset_bx) - 0x30;
                }
                else
                {
                    arg0->flags |= 0x4000;
                    arg0->x_pos = arg0->x_pos - 0x30;
                    bossXToReach = (scroll_end_x - arg0->offset_bx) + 0x170;
                }
                curAct_tmp_4 = currentBossAction;
                floor_1 = floorLine - 0xE6;
                arg0->y_pos = floor_1;
                bossYToReach = floor_1;
                currentBossAction = curAct_tmp_4 + 1;
                alternateBossSpeedFactor = moskitoActionSequences[bossEncounter][curAct_tmp_4] << 0xA;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                setBossReachingSpeeds(arg0, 1, 0xFF, 0xFF);
                skipToLabel(arg0, 2, 1);
                currentBossActionIsOver = 0;
                break;
            case 9:
                set_main_and_sub_etat(arg0, 0, 9);
                if ((setMoskitoAtScrollBorder(arg0, 2U) << 0x10) > 0)
                {
                    arg0->flags &= ~0x4000;
                    arg0->x_pos = (temp_v0_7 = arg0->x_pos + 0x50); /* gross, undo? */
                    bossXToReach = (scroll_start_x - arg0->offset_bx) - 0x50;
                }
                else
                {
                    arg0->flags |= 0x4000;
                    arg0->x_pos = arg0->x_pos - 0x60;
                    bossXToReach = (scroll_end_x - arg0->offset_bx) + 0x180;
                }
                curAct_tmp_5 = currentBossAction;
                floor_2 = floorLine - 0xB4;
                arg0->y_pos = floor_2;
                bossYToReach = floor_2;
                currentBossAction = curAct_tmp_5 + 1;
                alternateBossSpeedFactor = moskitoActionSequences[bossEncounter][curAct_tmp_5] << 0xA;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                setBossReachingSpeeds(arg0, 1, 0xFF, 0xFF);
                skipToLabel(arg0, 2, 1);
                currentBossActionIsOver = 0;
                break;
            case 18:
            case 19:
                arg0->y_pos = floorLine - 0x48;
                if (curAct == 0x13)
                {
                    arg0->y_pos = floorLine - 0x78;
                }
                if ((setMoskitoAtScrollBorder(arg0, 2U) << 0x10) > 0)
                {
                    x_pos = arg0->x_pos;
                    arg0->flags &= ~0x4000;
                    arg0->x_pos = x_pos + 0x44;
                    new_x_2 = x_pos + 0x2C;
                }
                else
                {
                    x_pos = arg0->x_pos;
                    arg0->flags |= 0x4000;
                    arg0->x_pos = x_pos - 0x4C;
                    new_x_2 = x_pos - 0x3C;
                }
                bossXToReach = new_x_2;
                set_main_and_sub_etat(arg0, 0, 0xE);
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                bossYToReach = arg0->y_pos;
                setBossReachingSpeeds(arg0, 1, 0xFF, 0xFF);
                skipToLabel(arg0, 2, 1);
                currentBossActionIsOver = 0;
                break;
            case 21:
                set_main_and_sub_etat(arg0, 0, 0xE);
                skipToLabel(arg0, 1, 1);
                act_ind_1 = currentBossAction;
                currentBossAction = act_ind_1 + 1;
                arg0->nb_cmd *= moskitoActionSequences[bossEncounter][act_ind_1];
                currentBossActionIsOver = 0;
                break;
            case 20:
                if ((arg0->x_pos + arg0->offset_bx) > (s16) temp_s7)
                {
                    arg0->flags &= ~0x4000;
                    new_x_2 = (scroll_start_x - arg0->offset_bx) - 0x38;
                }
                else
                {
                    arg0->flags |= 0x4000;
                    new_x_2 = (scroll_end_x - arg0->offset_bx) + 0x170;
                }
                bossXToReach = new_x_2;
                bossYToReach = arg0->y_pos;
                set_main_and_sub_etat(arg0, 0, 4);
                /* goto block_88; */
                skipToLabel(arg0, 2, 1);
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                setBossReachingSpeeds(arg0, 1, 0xFF, 0xFF);
                currentBossActionIsOver = 0;
                break;
            }
        } while (currentBossActionIsOver != 0);
    }
}
