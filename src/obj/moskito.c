#include "obj/moskito.h"

/* 6F914 80194114 -O2 -msoft-float */
void getIdealStingCoords(Obj *obj, s16 *out_x, s16 *out_y)
{
  s16 x;
  s16 calc_y;
  s16 calc_x;
  
  x = ray_zdc_x;
  calc_y = ray_zdc_y + (ray_zdc_h >> 1);
  calc_x = x + (ray_zdc_w >> 1) - obj->offset_bx;
  *out_x = calc_x;
  if (obj->flags & FLG(OBJ_FLIP_X))
    calc_x -= 48;
  else
    calc_x += 48;
  *out_x = calc_x;
  *out_y = calc_y - 112;
}

/* 6F988 80194188 -O2 -msoft-float */
u8 closeEnoughToSting(Obj *obj, u16 min_x, u16 min_y)
{
    s16 sting_x; s16 sting_y;

    getIdealStingCoords(obj, &sting_x, &sting_y);
    sting_x = __builtin_abs((s16) (sting_x - obj->x_pos));
    sting_y = __builtin_abs((s16) (sting_y - obj->y_pos));
    if (sting_x < min_x && sting_y < min_y)
        return true;
    else
        return false;
}

/* 6FA3C 8019423C -O2 -msoft-float */
/*s16 firstFloorBelow();*/

void PS1_setBossScrollLimits_moskito(Obj *obj)
{
    s16 x;

    x = obj->offset_bx + obj->init_x_pos - 272;
    bossScrollStartX = x;
    bossScrollEndX = x;

    floorLine = firstFloorBelow(obj);
    bossScrollStartY = floorLine - 256;
    bossScrollEndY = floorLine - 176;
    
    if (bossScrollStartX < 0)
        bossScrollStartX = 0;
    if (bossScrollStartX > xmapmax)
        bossScrollStartX = xmapmax;
    if (bossScrollEndX < 0)
        bossScrollEndX = 0;
    if (bossScrollEndX > xmapmax)
        bossScrollEndX = xmapmax;
    if (bossScrollStartY < 0)
        bossScrollStartY = 0;
    if (bossScrollStartY > ymapmax)
        bossScrollStartY = ymapmax;
    if (bossScrollEndY < 0)
        bossScrollEndY = 0;
    if (bossScrollEndY > ymapmax)
        bossScrollEndY = ymapmax;
}

/* 6FB88 80194388 -O2 -msoft-float */
u8 moskitoCanAttak(Obj *obj)
{
    u8 locked;
    u32 res;

    if (!scrollLocked)
    {
        locked = false;
        if (
            xmap >= bossScrollStartX - h_scroll_speed &&
            xmap <= bossScrollEndX + h_scroll_speed &&
            ymap >= bossScrollStartY - v_scroll_speed
        )
            locked = (ymap <= bossScrollEndY + v_scroll_speed);
        scrollLocked = locked;

        if (scrollLocked)
        {
            scroll_start_x = bossScrollStartX;
            scroll_end_x = bossScrollEndX;
            scroll_start_y = bossScrollStartY;
            scroll_end_y = bossScrollEndY;
        }
    }
    else if (obj->timer != 0)
        obj->timer--;
    res = false;
    if (scrollLocked)
        res = (obj->timer == 0);
    return res;
}


/* 6FCCC 801944CC -O2 -msoft-float */
/* param_2 is some moskito obj flag */
s16 setMoskitoAtScrollBorder(Obj *obj, u8 param_2)
{
  s32 width;
  s16 res;
  
  width = SCREEN_WIDTH;
  switch (param_2)
  {
    case 0:
      res = -1;
      obj->x_pos = scroll_start_x - obj->offset_bx;
      obj->flags &= ~FLG(OBJ_FLIP_X);
      break;
    case 1:
      res = 1;
      obj->x_pos = scroll_end_x - (obj->offset_bx - width);
      obj->flags |= FLG(OBJ_FLIP_X);
      break;
    default:
      res = obj->offset_bx + obj->x_pos - ((scroll_start_x + scroll_end_x + SCREEN_WIDTH) / 2);
      if (res >= 1)
      {
        obj->x_pos = scroll_end_x - (obj->offset_bx - width);
        obj->flags &= ~FLG(OBJ_FLIP_X);
      }
      else
      {
        obj->x_pos = scroll_start_x - obj->offset_bx;
        obj->flags |= FLG(OBJ_FLIP_X);
      }
      break;
  }
  return res;
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/moskito", prepareNewMoskitoAttack);
#else
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
#endif

/* 70C64 80195464 -O2 -msoft-float */
Obj *allocateMoskitoFruit(Obj *mst2_obj)
{
    u8 spr_ind;
    ObjType type_check;
    s16 i;
    Obj *cur_obj;
    s16 nb_objs;
    ObjType cur_obj_type;
    s16 unk_x; s16 unk_y; s16 unk_w; s16 unk_h;
    Obj *res = null;

    switch (mst2_obj->sub_etat)
    {
    case 12:
        spr_ind = 3;
        type_check = TYPE_MST_FRUIT1;
        break;
    case 11:
        spr_ind = 3;
        type_check = TYPE_MST_FRUIT2;
        break;
    }

    i = 0;
    cur_obj = &level.objects[i];
    nb_objs = level.nb_objects;
    while (i < (nb_objs))
    {
        cur_obj_type = cur_obj->type;
        if (cur_obj_type == type_check && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            GET_SPRITE_POS(mst2_obj, spr_ind, &unk_x, &unk_y, &unk_w, &unk_h);
            cur_obj->x_pos = unk_x - cur_obj->offset_bx + (unk_w >> 1);
            cur_obj->y_pos = unk_y - cur_obj->offset_hy;
            cur_obj->init_x_pos = cur_obj->x_pos;
            cur_obj->init_y_pos = cur_obj->y_pos;
            switch (cur_obj_type)
            {
            case TYPE_MST_FRUIT1:
                cur_obj->field23_0x3c = 1;
                cur_obj->speed_x = 0;
                break;
            case TYPE_MST_FRUIT2:
                cur_obj->field23_0x3c = 3;
                cur_obj->speed_x = mst2_obj->speed_x;
                break;
            }
            cur_obj->speed_y = 0;
            cur_obj->anim_index = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_index;
            cur_obj->anim_frame = 0;
            calc_obj_pos(cur_obj);
            cur_obj->gravity_value_1 = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_FLIP_X)) | (mst2_obj->flags & FLG(OBJ_FLIP_X));
            cur_obj->flags &= ~FLG(OBJ_FLAG_9);
            res = cur_obj;
            break;
        }
        cur_obj++;
        i++;
    }

    return res;
}

/* 70E50 80195650 -O2 -msoft-float */
void moskitoDropFruitOnRay(Obj *obj)
{
    s16 x_1;
    s16 x_2;
    u8 sub_etat;
    s32 speed_x;
    s16 y_1;
    s16 cen_x;
    s16 cen_y;
    s16 unk_1;
    s32 unk_2;
    s16 unk_3;
    s16 unk_4;

    x_1 = obj->offset_bx + obj->x_pos;
    x_2 = x_1;
    sub_etat = obj->sub_etat;
    if (sub_etat != 11)
    {
        if (sub_etat == 12)
        {
            speed_x = obj->speed_x;
            if (speed_x < 0)
                speed_x += 7;
            speed_x = speed_x >> 3;
            unk_1 = speed_x;
            /* ??? */
            unk_2 = (s32) (((u32) speed_x >> 31) + speed_x) >> 1;
            x_1 -= unk_2;
        }
    }
    else
    {
        unk_2 = obj->speed_x * 120;
        unk_1 = unk_2 >> 4;
        if (unk_2 < 0)
            unk_1 = (unk_2 + 15) >> 4;
    }

    unk_3 = __builtin_abs(unk_1);
    if (unk_1 < 0)
        x_1 += unk_1;
    y_1 = obj->offset_by + obj->y_pos;
    unk_4 = scroll_end_y - scroll_start_y + 240;
    cen_x = ray_zdc_x + (ray_zdc_w >> 1);
    cen_y = ray_zdc_y + (ray_zdc_h >> 1);
    if (
      scroll_start_x <= x_2 &&
      scroll_end_x + SCREEN_WIDTH >= x_2 &&
      cen_x >= x_1 &&
      cen_y >= y_1 &&
      cen_x <= x_1 + unk_3 &&
      cen_y <= y_1 + unk_4 
    )
    {
        allocateMoskitoFruit(obj);
        set_main_and_sub_etat(obj, 0, 16);
        bossYToReach -= 64;
    }
}

/* 71030 80195830 -O2 -msoft-float */
/*? calc_obj_dir(Obj *);
s32 closeEnoughToSting(Obj *, ?, ?);
? moskitoDropFruitOnRay(Obj *);
? prepareNewMoskitoAttack(Obj *);
? setBossReachingSpeeds(Obj *, u8, u8, u8);
? testActionEnd(Obj *);*/

void doMoskitoCommand(Obj *obj)
{
    ObjFlags flags;
    Obj *poing_obj;

    if (moskitoCanAttak(obj))
    {
        if (bossSafeTimer != 0)
            bossSafeTimer--;
        flags = obj->flags;
        if (!(flags & FLG(OBJ_FLAG_0)))
        {
            if (obj->cmd == 2)
            {
                if (PS1_MsAnimIndex == 0x0E && obj->anim_index == 0x0F)
                    obj->flags = flags & ~FLG(OBJ_FLIP_X) | (((flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
                bossXToReach = -32000;
                bossYToReach = -32000;
                obj->speed_x = 0;
                obj->speed_y = 0;
            }
            else
            {
                switch (curAct)
                {
                case 10:
                case 13:
                    calc_obj_dir(obj);
                    getIdealStingCoords(obj, &bossXToReach, &bossYToReach);
                    if (closeEnoughToSting(obj, 24, 24))
                        currentBossActionIsOver = true;
                    /* fall through */
                case 4:
                    if (
                        obj->hit_points < 2 &&
                        poing.is_active &&
                        !fistAvoided &&
                        ModeDemo == 0 &&
                        !record.is_recording
                    )
                    {
                        fistAvoided = true;
                        poing_obj = &level.objects[poing_obj_id];
                        if (
                          obj->y_pos + (obj->offset_by + obj->offset_hy) / 2
                          >
                          poing_obj->y_pos + (poing_obj->offset_by + poing_obj->offset_hy) / 2
                        )
                            obj->speed_y += 80;
                        else
                            obj->speed_y -= 80;
                        
                        if ((obj->x_pos + obj->offset_bx) > (poing_obj->x_pos + poing_obj->offset_bx))
                            obj->speed_x += 80;
                        else
                            obj->speed_x -= 80;
                    }
                    break;
                }
                setBossReachingSpeeds(obj, bossReachingTimer, bossReachingAccuracyX, bossReachingAccuracyY);
                if (obj->main_etat == 0 && (u8) (obj->sub_etat - 0xB) < 2)
                    moskitoDropFruitOnRay(obj);
            }
            testActionEnd(obj);
        }
        prepareNewMoskitoAttack(obj);
    }
    obj->flags &= ~FLG(OBJ_FLAG_0);
    PS1_MsAnimIndex = obj->anim_index;
}

/* 71330 80195B30 -O2 -msoft-float */
u8 tellNextMoskitoAction(Obj *obj)
{
    u8 *actions;

    if (bossEncounter != 8)
        actions = &moskitoActionSequences[bossEncounter][currentBossAction];
    else
        actions = &moskitoActionSequences[saveBossEncounter][saveCurrentBossAction];

    switch(actions[0])
    {
    case 2:
        return moskitoActionSequences[bossEncounter][0];
    case 3:
        return moskitoActionSequences[bossEncounter + 1][0];
    case 5:
        return moskitoActionSequences[saveBossEncounter][0];
    case 12:
        return moskitoActionSequences[actions[1]][0];
    default:
        return actions[0];
    }
}

/* 7144C 80195C4C -O2 -msoft-float */
void changeMoskitoPhase(Obj *obj)
{
    u8 *enc;
    u8 *act;
    u8 enc_prev;
    u8 hp;

    if (bossEncounter == 8)
    {
        enc = &saveBossEncounter;
        act = &saveCurrentBossAction;
    }
    else
    {
        enc = &bossEncounter;
        act = &currentBossAction;
    }

    enc_prev = *enc;
    if (obj->init_hit_points == 12)
    {
        hp = obj->hit_points;
        if (hp >= 10)
            *enc = 3;
        else if (hp >= 8)
            *enc = 5;
        else if (hp >= 5)
            *enc = 6;
        else if (hp != 0)
            *enc = 7;
        else
        {
            *enc = 9;
            bossSafeTimer = 0;
        }

        if (enc_prev != *enc)
            *act = 0;
    }
}

/* 7151C 80195D1C -O2 -msoft-float */
/*? obj_hurt();*/

void doMoskitoHit(Obj *obj)
{
    s32 act_next;
    s32 act_18;
    u8 hp;
    s32 dividend;
    s32 divisor;

    if (bossSafeTimer == 0)
    {
        poing.damage = 1;
        obj_hurt(obj);
        bossSafeTimer = 0xFF;
        obj->flags |= FLG(OBJ_FLAG_0);
        changeMoskitoPhase(obj);
        act_next = tellNextMoskitoAction(obj);
        act_18 = 18;
        if (
            act_next >= 7 &&
            (act_next <= 10 || (act_next <= 21 && act_next >= act_18))
        )
            mstMustLeaveScreenToProceed = true;

        hp = obj->hit_points;
        if (hp != 0)
        {
            dividend = obj->init_hit_points * 0x1000;
            divisor = hp + obj->init_hit_points;
            bossSpeedFactor = (dividend / divisor) + 0x4000;

            if (bossEncounter != 8)
            {
                saveBossEncounter = bossEncounter;
                saveCurrentBossAction = currentBossAction;
                bossEncounter = 8;
            }
        }
        else
        {
            bossEncounter = 9;
            bossSpeedFactor = 0x4000;
        }
        currentBossAction = 0;
        currentBossActionIsOver = true;
    }
}