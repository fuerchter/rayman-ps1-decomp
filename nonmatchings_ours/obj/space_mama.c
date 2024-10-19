
#include "obj/space_mama.h"

/* matches, but __builtin_abs section */
/*INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisDropBomb);*/

void mereDenisDropBomb(Obj *smama_obj)
{
    s16 ray_x;
    s16 smama_x_1; s16 smama_x_2;
    Obj *cur_obj;
    s16 j; u8 i;
    s16 nb_objs;
    u8 new_sub_etat;
    u8 new_flip_x;
    
    if (currentBombSequence == 0xfe && lastDroppedBombXCenterPos == -32000)
    {
        ray_x = ray.x_pos + ray.offset_bx;
        smama_x_1 = smama_obj->x_pos + smama_obj->offset_bx;
        if ((ray_x >= smama_x_1 - 8) && (ray_x <= smama_x_1 + 8))
        {
            cur_obj = level.objects;
            j = 0;
            nb_objs = level.nb_objects;
            while (j < nb_objs)
            {
                if (cur_obj->type == TYPE_SMA_BOMB && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
                {
                    cur_obj->sub_etat = 0;
                    cur_obj->flags &= ~FLG(OBJ_FLIP_X);
                    cur_obj->x_pos = smama_x_1 - cur_obj->offset_bx;
                    cur_obj->y_pos = smama_obj->y_pos + smama_obj->offset_by - cur_obj->offset_by - 33;
                    cur_obj->timer = 50;
                    cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
                    break;
                }
                cur_obj++;
                j++;
            }
            currentBombSequence = 0xff;
            lastDroppedBombXCenterPos = smama_x_1;
        }
    }
    else
    {
        for (i = 0; i < sizeof(lastDroppedBombIdInSequence); i++)
        {
            if (lastDroppedBombIdInSequence[i] == 7)
            {
                currentBombSequence = 0xff;
                lastDroppedBombIdInSequence[i] = 0xff;
                lastDroppedBombXCenterPos = -32000;
            }
            else
            {
                smama_x_2 = smama_obj->x_pos + smama_obj->offset_bx;
                if (i == 0)
                {

                    /* tried __builtin_abs. pc also does abs */
                    #define OPT_2
                    #ifdef OPT_0
                    /* ABS_LT, see DO_POING_COLLISION */
                    if (
                        (smama_x_2 - lastDroppedBombXCenterPos < 0 ?
                            -(smama_x_2 - lastDroppedBombXCenterPos) < 0x25 :
                            (smama_x_2 - lastDroppedBombXCenterPos < 0x25)
                        )
                    )
                        return;
                    #endif
                    #ifdef OPT_1
                    if (__builtin_abs(smama_x_2 - lastDroppedBombXCenterPos) < 0x25) {
                        return;
                    }
                    #endif
                    #ifdef OPT_2
                    if (smama_x_2 - lastDroppedBombXCenterPos < 0) {
                        if (-(smama_x_2 - lastDroppedBombXCenterPos) < 0x25) {
                        return;
                        }
                    }
                    else
                    {
                        if (smama_x_2 - lastDroppedBombXCenterPos < 0x25) {
                        do {} while (0);
                        return;
                        }
                    }
                    #endif
                    #ifdef OPT_3 /* ghidra unmodified */
                    iVar2 = smama_x_2 - lastDroppedBombXCenterPos;
                    if (iVar2 < 0) {
                        iVar2 = lastDroppedBombXCenterPos - smama_x_2;
                    }
                    if (iVar2 < 0x25) {
                        return;
                    }
                    #endif
                }
                lastDroppedBombIdInSequence[i]++;
                switch(bombSequences[currentBombSequence][i][lastDroppedBombIdInSequence[i]])
                {
                case 0:
                case 4:
                    new_sub_etat = 0;
                    new_flip_x = 0;
                    break;
                case 1:
                case 5:
                    new_sub_etat = 2;
                    new_flip_x = smama_obj->flags >> OBJ_FLIP_X & 1;
                    break;
                case 2:
                    new_sub_etat = 6;
                    new_flip_x = smama_obj->flags >> OBJ_FLIP_X & 1;
                    break;
                case 6:
                    new_sub_etat = 6;
                    new_flip_x = (smama_obj->flags >> OBJ_FLIP_X ^ 1) & 1;
                    break;
                case 3:
                case 7:
                    new_sub_etat = 4;
                    new_flip_x = (smama_obj->flags >> OBJ_FLIP_X ^ 1) & 1;
                    break;
                case 8:
                    smama_x_2 = 0;
                    droppedBombIds[i][lastDroppedBombIdInSequence[i]] = -1;
                    break;
                default:
                    break;
                }

                if (smama_x_2 != 0)
                {
                    cur_obj = level.objects;
                    j = 0;
                    nb_objs = level.nb_objects;
                    while (j < nb_objs)
                    {
                        if (cur_obj->type == TYPE_SMA_BOMB && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
                        {
                            cur_obj->sub_etat = new_sub_etat;
                            cur_obj->flags = cur_obj->flags & ~FLG(OBJ_FLIP_X) | (new_flip_x & 1) << OBJ_FLIP_X;
                            droppedBombIds[i][lastDroppedBombIdInSequence[i]] = j;
                            cur_obj->anim_frame = 0;
                            cur_obj->x_pos = smama_x_2 - cur_obj->offset_bx;
                            cur_obj->y_pos = (smama_obj->y_pos + smama_obj->offset_by - cur_obj->offset_by) + (i - 6) * 11;
                            cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
                            break;
                        }
                        cur_obj++;
                        j++;
                    }
                    if (j >= nb_objs)
                        droppedBombIds[i][lastDroppedBombIdInSequence[i]] = -1;
                }
                lastDroppedBombXCenterPos = smama_obj->x_pos + smama_obj->offset_bx;
            }
        }
    }
}

/*
matches, but gotos
might have actually written gotos like this?
*/
/*INCLUDE_ASM("asm/nonmatchings/obj/space_mama", prepareNewMereDenisAttack);*/

u8 prepareNewMereDenisAttack(Obj *smama_obj)
{
    u8 cur_act = 0xFF;
    Obj *wep_obj = &level.objects[mereDenis_weapon_id];
    Obj *mach_obj = &level.objects[machine_obj_id];
    Obj *poing_obj;
    s32 old_flip_x;
    s16 i;
    
    if (circleIndex == -32000)
    {
        while (currentBossActionIsOver)
        {
            cur_act = mereDenisActionSequences[bossEncounter][currentBossAction++];
            switch (cur_act)
            {
            case 0:
                bossEncounter++;
            case 1:
                currentBossAction = 0;
                currentBossActionIsOver = true;
                break;
            case 2:
                currentBossAction = saveCurrentBossAction;
                bossEncounter = saveBossEncounter;
                if (currentBossAction == 0xFF)
                    currentBossAction = saveCurrentBossAction + 1;
                currentBossActionIsOver = true;
                saveBossEncounter = 0xFF;
                break;
            case 46:
                remoteRayXToReach = -32000;
                fin_boss = true;
                smama_obj->nb_cmd = vblToEOA(smama_obj, 1) - 4;
                currentBossActionIsOver = false;
                break;
            case 42:
                set_main_and_sub_etat(smama_obj, 0, 3);
                remoteRayXToReach = ray.x_pos;
                skipToLabel(smama_obj, 0, true);
                smama_obj->nb_cmd = 0;
                fin_boss = true;
                currentBossActionIsOver = true;
                break;
            case 44:
                switch (mach_obj->sub_etat)
                {
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                    set_main_and_sub_etat(smama_obj, 0, 16);
                    snapWeaponAnimState(wep_obj, 43);
                    set_sub_etat(mach_obj, mach_obj->sub_etat + 1);
                    skipToLabel(smama_obj, 0, true);
                    mach_obj->x_pos = smama_obj->x_pos;
                    mach_obj->y_pos = smama_obj->y_pos;
                    mach_obj->anim_frame = 0;
                    currentBossActionIsOver = false;
                    break;
                case 42:
                    wep_obj->flags &= ~FLG(OBJ_ALIVE);
                    currentBossAction = 0;
                    bossEncounter = 6;
                    currentBossActionIsOver = true;
                    mach_obj->flags &= ~FLG(OBJ_ALIVE);
                    break;
                }
                laserSourceSprNumInAnim = 0xFF;
                break;
            case 40:
                poing_obj = &level.objects[poing_obj_id];
                set_main_and_sub_etat(smama_obj, 0, 2);
                bossYToReach = smama_obj->y_pos;
                if (poing_obj->speed_x != 0) /* couldn't make this a var */
                {
                    skipToLabel(smama_obj, 0, true);
                    bossXToReach = smama_obj->eta[0][2].speed_x_right * smama_obj->nb_cmd / 16;
                    if (poing_obj->speed_x < 0)
                        bossXToReach = smama_obj->x_pos + bossXToReach;
                    else if (poing_obj->speed_x > 0)
                        bossXToReach = smama_obj->x_pos - bossXToReach;
                    
                    bossReachingAccuracyX = 0xFF;
                    bossReachingAccuracyY = 0xFF;
                    bossReachingTimer = 1;
                    setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                    skipToLabel(smama_obj, 1, true);
                }
                else
                    skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 5:
                fix_numlevel(smama_obj);
                new_level = true;
                currentBossActionIsOver = false;
                finBosslevel[0] |= FLG(5);
                break;
            case 41:
                old_flip_x = smama_obj->flags >> OBJ_FLIP_X & 1;
                calc_obj_dir(smama_obj);
                if ((smama_obj->flags >> OBJ_FLIP_X & 1) != old_flip_x)
                {
                    set_main_and_sub_etat(smama_obj, 0, 4);
                    skipToLabel(smama_obj, 0, true);
                    currentBossActionIsOver = false;
                }
                else
                    currentBossActionIsOver = true;
                break;
            case 7:
                stepsForward = 0;
                currentPhaseHitCounter = 0;
                smama_obj->display_prio = 3;
                swapMereDenisCollZones(smama_obj, true);
                set_main_and_sub_etat(smama_obj, 0, 44);
                setMereDenisAtScrollBorder(smama_obj, 0);
                smama_obj->flags &= ~FLG(OBJ_FLIP_X);
                smama_obj->x_pos = smama_obj->x_pos - 144;
                smama_obj->y_pos = (floorLine - smama_obj->offset_by) - 32;
                bossXToReach = (scroll_start_x - smama_obj->offset_bx) + 50;
                bossYToReach = smama_obj->y_pos;
                bossReachingTimer = 1;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                break;
            case 8:
                swapMereDenisCollZones(smama_obj, true);
                circleIndex = 4;
                circleX = smama_obj->x_pos;
                circleY = smama_obj->y_pos - 60;
                setCirclePointToReach();
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                bossReachingTimer = 1;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                break;
            case 12:
                swapMereDenisCollZones(smama_obj, true);
                bossXToReach = smama_obj->x_pos + 110;
                bossYToReach = (floorLine - smama_obj->offset_by) - 124;
                bossReachingTimer = 1;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                break;
            case 38:
                swapMereDenisCollZones(smama_obj, true);
                set_main_and_sub_etat(smama_obj, 2, 1);
                bossYToReach = floorLine - smama_obj->offset_by;
                bossXToReach = smama_obj->x_pos;
                bossReachingTimer = 1;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0);
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                break;
            case 13:
                swapMereDenisCollZones(smama_obj, true);
                set_main_and_sub_etat(smama_obj, 0, 10);
                wep_obj->x_pos = smama_obj->x_pos;
                wep_obj->y_pos = smama_obj->y_pos;
                mach_obj->x_pos = smama_obj->x_pos;
                mach_obj->y_pos = smama_obj->y_pos;
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 14:
                swapMereDenisCollZones(smama_obj, false);
                set_main_and_sub_etat(mach_obj, 0, 37);
                mach_obj->flags |= FLG(OBJ_ALIVE);
                calc_obj_pos(mach_obj);
                currentBossActionIsOver = true;
                break;
            case 36:
                swapMereDenisCollZones(smama_obj, true);
                mach_obj->flags |= FLG(OBJ_ALIVE);
                smama_obj->display_prio = 6;
                wep_obj->flags |= FLG(OBJ_ALIVE);
                set_main_and_sub_etat(smama_obj, 0, 19);
                snapWeaponAnimState(wep_obj, 36);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 15:
                swapMereDenisCollZones(smama_obj, false);
                if ((s16) myRand(1))
                    set_main_and_sub_etat(smama_obj, 0, 0);
                else
                    set_main_and_sub_etat(smama_obj, 0, 9);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 16:
                swapMereDenisCollZones(smama_obj, false);
                stepsForward++;
                set_main_and_sub_etat(smama_obj, 1, 1);
                skipToLabel(smama_obj, 0, true);
                bossYToReach = smama_obj->y_pos;
                bossXToReach = smama_obj->eta[1][1].speed_x_right * smama_obj->nb_cmd / 16;
                if (smama_obj->flags & FLG(OBJ_FLIP_X))
                    bossXToReach = smama_obj->x_pos + bossXToReach;
                else
                    bossXToReach = smama_obj->x_pos - bossXToReach;
                bossReachingTimer = 1;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                break;
            case 26:
                swapMereDenisCollZones(smama_obj, false);
                set_main_and_sub_etat(smama_obj, 0, 5);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 18:
                swapMereDenisCollZones(smama_obj, false);
                laserSourceSprNumInAnim = 5;
                currentLaserSize = 4;
                set_main_and_sub_etat(smama_obj, 0, 7);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 34:
                switch (smama_obj->sub_etat)
                {
                case 34:
                    set_sub_etat(smama_obj, 31);
                    snapWeaponAnimState(wep_obj, 33);
                    break;
                case 21:
                case 31:
                case 19:
                    set_sub_etat(smama_obj, 24);
                    snapWeaponAnimState(wep_obj, 25);
                    break;
                }
                goto block_123;
            case 35:
                switch (smama_obj->sub_etat)
                {
                case 22:
                    set_sub_etat(smama_obj, 23);
                    snapWeaponAnimState(wep_obj, 26);
                    break;
                case 21:
                case 23:
                case 19:
                    set_sub_etat(smama_obj, 30);
                    snapWeaponAnimState(wep_obj, 32);
                    break;
                }
block_123:
                swapMereDenisCollZones(smama_obj, true);
                wep_obj->flags |= FLG(OBJ_ALIVE);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 32:
            case 33:
            case 43:
                swapMereDenisCollZones(smama_obj, true);
                laserSourceSprNumInAnim = 8;
                /* data format? */
                currentLaserSize = mereDenisActionSequences[bossEncounter][currentBossAction++];
                switch (cur_act)
                {
                case 33:
                    set_main_and_sub_etat(smama_obj, 0, 22);
                    snapWeaponAnimState(wep_obj, 18);
                    break;
                case 32:
                    set_main_and_sub_etat(smama_obj, 0, 21);
                    snapWeaponAnimState(wep_obj, 17);
                    break;
                case 43:
                    set_main_and_sub_etat(smama_obj, 0, 34);
                    snapWeaponAnimState(wep_obj, 35);
                    break;
                }
                wep_obj->flags |= FLG(OBJ_ALIVE);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 19:
                swapMereDenisCollZones(smama_obj, false);
                set_main_and_sub_etat(smama_obj, 0, 8);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 21:
                swapMereDenisCollZones(smama_obj, false);
                set_main_and_sub_etat(smama_obj, 0, 11);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 39:
                swapMereDenisCollZones(smama_obj, false);
                mach_obj->flags |= FLG(OBJ_ALIVE);
                smama_obj->display_prio = 3;
                mach_obj->speed_y = -6;
                set_main_and_sub_etat(mach_obj, 2, 1);
                mach_obj->speed_x = mach_obj->eta[mach_obj->main_etat][mach_obj->sub_etat].speed_x_left;
                level.objects[machine_obj_id].flags |= FLG(OBJ_ALIVE);
                set_main_and_sub_etat(smama_obj, 0, 14);
                smama_obj->x_pos += 100;
                goto block_90;
            case 22:
                swapMereDenisCollZones(smama_obj, false);
                set_main_and_sub_etat(smama_obj, 0, 13);
block_90:
                bossXToReach = smama_obj->x_pos;
                bossYToReach = scroll_end_y - smama_obj->offset_by - 16;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                if (cur_act == 22)
                {
                    bossReachingAccuracyX = 32;
                    bossReachingAccuracyY = 32;
                    bossReachingTimer = 2;
                    if (smama_obj->flags & FLG(OBJ_FLIP_X))
                        bossXToReach += 80;
                    else
                        bossXToReach -= 80;
                }
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                break;
            case 30:
                smama_obj->flags =
                    smama_obj->flags & ~FLG(OBJ_FLIP_X) |
                    ((smama_obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X;
                goto block_98;
            case 25:
                smama_obj->flags |= FLG(OBJ_FLIP_X);
                goto block_98;
            case 23:
            case 45:
block_98:
                mere_denis_wait_time = 60;
                swapMereDenisCollZones(smama_obj, false);
                setMereDenisAtScrollBorder(smama_obj, smama_obj->flags >> OBJ_FLIP_X & 1);
                if (cur_act == 45)
                {
                    bossXToReach = ray.offset_bx + ray.x_pos - smama_obj->offset_bx;
                    smama_obj->x_pos = bossXToReach;
                }
                else if (cur_act == 25)
                {
                    bossXToReach = level.objects[machine_obj_id].x_pos + 100;
                    smama_obj->x_pos = bossXToReach + 80;
                }
                else /* cur_act == 30 || cur_act == 23 */
                {
                    if (smama_obj->flags & FLG(OBJ_FLIP_X))
                    {
                        bossXToReach = smama_obj->x_pos + 48;
                        smama_obj->x_pos = bossXToReach + 80;
                    }
                    else
                    {
                        bossXToReach = smama_obj->x_pos - 160;
                        smama_obj->x_pos = bossXToReach - 80;
                    }
                }
                smama_obj->y_pos = scroll_end_y - smama_obj->offset_by - 16;
                bossYToReach = smama_obj->y_pos;
                bossReachingAccuracyX = 24;
                bossReachingAccuracyY = 24;
                bossReachingTimer = 1;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                bossYToReach = floorLine - smama_obj->offset_by;
                set_main_and_sub_etat(smama_obj, 0, 14);
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                break;
            case 24:
                calc_obj_dir(smama_obj);
                swapMereDenisCollZones(smama_obj, false);
                set_main_and_sub_etat(smama_obj, 0, 1);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 37:
                swapMereDenisCollZones(smama_obj, true);
                wep_obj->flags &= ~FLG(OBJ_ALIVE);
                mach_obj->flags &= ~FLG(OBJ_ALIVE);
                set_main_and_sub_etat(smama_obj, 0, 6);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 31:
                swapMereDenisCollZones(smama_obj, true);
                smama_obj->x_pos -= 100;
                mach_obj->flags &= ~FLG(OBJ_ALIVE);
                set_main_and_sub_etat(smama_obj, 0, 20);
                skipToLabel(smama_obj, 0, true);
                currentBossActionIsOver = false;
                break;
            case 27:
                swapMereDenisCollZones(smama_obj, false);
                set_main_and_sub_etat(smama_obj, 0, 15);
                bossXToReach = smama_obj->x_pos;
                bossYToReach = scroll_end_y - smama_obj->offset_by - 16;
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                skipToLabel(smama_obj, 1, true);
                currentBossActionIsOver = false;
                currentBombSequence = 0xFF;
                break;
            case 28:
                swapMereDenisCollZones(smama_obj, false);
                setMereDenisAtScrollBorder(smama_obj, (smama_obj->flags >> OBJ_FLIP_X ^ 1) & 1);
                if (smama_obj->flags & FLG(OBJ_FLIP_X))
                {
                    smama_obj->x_pos -= 144;
                    bossXToReach = scroll_end_x - smama_obj->offset_bx + 464;
                }
                else
                {
                    smama_obj->x_pos += 144;
                    bossXToReach = scroll_start_x - smama_obj->offset_bx - 144;
                }
                smama_obj->y_pos = 
                    floorLine - smama_obj->offset_by -
                    (mereDenisActionSequences[bossEncounter][currentBossAction++] + 32);
                bossYToReach = smama_obj->y_pos;
                set_main_and_sub_etat(smama_obj, 0, 15);
                bossReachingAccuracyX = 0xFF;
                bossReachingAccuracyY = 0xFF;
                bossReachingTimer = 1;
                setBossReachingSpeeds(smama_obj, 1, 0xFF, 0xFF);
                skipToLabel(smama_obj, 1, true);
                timerBeforeFirstBomb = 41;
                currentBombSequence = mereDenisActionSequences[bossEncounter][currentBossAction++];
                
                if (currentBombSequence == 0xFF)
                {
                    do {
                        do {
                            currentBombSequence = myRand(6);
                        } while (currentBombSequence == 1);
                    } while (currentBombSequence == 6);
                }
                
                for (i = 0; i < (s16) sizeof(lastDroppedBombIdInSequence); i++)
                    lastDroppedBombIdInSequence[i] = 0xFF;
                
                lastDroppedBombXCenterPos = -32000;
                currentBossActionIsOver = false;
                break;
            case 29:
                swapMereDenisCollZones(smama_obj, false);
                smama_obj->flags =
                    smama_obj->flags & ~FLG(OBJ_FLIP_X) |
                    ((smama_obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X;
                set_main_and_sub_etat(smama_obj, 0, 0);
                skipToLabel(smama_obj, 0, true);
                mereDenisExplodeBombs();
                currentBossActionIsOver = false;
                break;
            }
        }
    }
    
    return cur_act;
}

/* matches, but wtf even */
/*INCLUDE_ASM("asm/nonmatchings/obj/space_mama", fitSaveCurrentAction);*/

void fitSaveCurrentAction(Obj *obj)
{
    u8 unk_1;

    do
    {
        unk_1 = false;
        switch (mereDenisActionSequences[bossEncounter][currentBossAction])
        {
        case 1:
            currentBossAction = 0;
            unk_1 = true;
            break;
        case 29:
            unk_1 = true;
            break;
        case 0:
            currentBossAction = 0;
            bossEncounter++;
            unk_1 = true;
            break;
        case 15:
        case 18:
        case 19:
        case 24:
        case 26:
            currentBossAction++;
            unk_1 = true;
            break;            
        case 33:
        case 43:
            currentBossAction++;
        case 34:
        case 35:
        case 36:
            currentBossAction++;
            unk_1 = true;
            break;
        case 28:
            currentBossAction += 2;
            /* ??? prevents jump into case 22 (target 0x27b8) */
            if (currentBossAction && currentBossAction){}
            unk_1 = true;
            break;
        case 22:
            if (currentBossAction != 0)
            {
                currentBossAction--;
                unk_1 = true;
            }
            break;
        default:
            break;
        }
    } while (unk_1 != 0);
    saveCurrentBossAction = currentBossAction;
    saveBossEncounter = bossEncounter;
}
