#include "obj/space_mama.h"

/* 640F0 801888F0 -O2 -msoft-float */
void findMereDenisWeapon(void)
{
    Obj *cur_obj = &level.objects[0];
    s32 nb_objs = level.nb_objects;
    s16 i = 0;

    mereDenis_weapon_id = -1;
    machine_obj_id = -1;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_SMA_WEAPON)
            mereDenis_weapon_id = i;
        else if (cur_obj->type == TYPE_WASHING_MACHINE)
            machine_obj_id = i;
        cur_obj++;
        i++;
    }
}

/* 64174 80188974 -O2 -msoft-float */
void PS1_setBossScrollLimits_spacemama(Obj *obj)
{
    s16 x; s16 y;

    x = obj->offset_bx + obj->init_x_pos - 220;
    bossScrollEndX = x;
    bossScrollStartX = x;
    y = firstFloorBelow(obj);
    floorLine = y;
    bossScrollStartY = y - 256;
    bossScrollEndY = y - 224;

    MAX_2(bossScrollStartX, 0);
    MIN_2(bossScrollStartX, xmapmax);
    MAX_2(bossScrollEndX, 0);
    MIN_2(bossScrollEndX, xmapmax);
    MAX_2(bossScrollStartY, 0);
    MIN_2(bossScrollStartY, ymapmax);
    MAX_2(bossScrollEndY, 0);
    MIN_2(bossScrollEndY, ymapmax);
}

/* 642C0 80188AC0 -O2 -msoft-float */
u8 mereDenisCanAttak(Obj *obj)
{
    if (!scrollLocked)
    {
        scrollLocked =
            xmap >= bossScrollStartX - h_scroll_speed &&
            xmap <= bossScrollEndX + h_scroll_speed &&
            ymap >= bossScrollStartY - v_scroll_speed &&
            ymap <= bossScrollEndY + v_scroll_speed;
        if (scrollLocked)
        {
            scroll_start_x = bossScrollStartX;
            scroll_end_x = bossScrollEndX;
            scroll_start_y = bossScrollStartY;
            scroll_end_y = bossScrollEndY;
        }
    }
    else if (obj->timer != 0 && horloge[2] == 0)
        obj->timer--;

    return scrollLocked && obj->timer == 0;
}

/* 64418 80188C18 -O2 -msoft-float */
s32 setMereDenisAtScrollBorder(Obj *obj, u8 flip_x)
{
    s32 unk_1;
    s16 res;
    u8 offs_bx;

    unk_1 = 320; /* couldn't remove this */
    switch (flip_x)
    {
    case false:
        res = -1;
        obj->x_pos = scroll_start_x - obj->offset_bx;
        obj->flags |= FLG(OBJ_FLIP_X);
        break;
    case true:
        res = 1;
        obj->x_pos = scroll_end_x - (obj->offset_bx - unk_1);
        obj->flags &= ~FLG(OBJ_FLIP_X);
        break;
    default:
        offs_bx = obj->offset_bx;
        res = offs_bx + obj->x_pos - (scroll_start_x + scroll_end_x + 320) / 2;
        if (res > 0)
        {
            obj->x_pos = scroll_end_x - (offs_bx - unk_1);
            obj->flags &= ~FLG(OBJ_FLIP_X);
        }
        else
        {
            obj->x_pos = scroll_start_x - offs_bx;
            obj->flags |= FLG(OBJ_FLIP_X);
        }
        break;
    }
    return res;
}

/* 64514 80188D14 -O2 -msoft-float */
void setCirclePointToReach(void)
{
    bossXToReach = circleX + sinus(circleIndex) * 100 / 512;
    bossYToReach = circleY + cosinus(circleIndex) * 60 / 512;
    circleIndex += 4;
    if (circleIndex > 512)
        circleIndex = -32000;
}

/* 645F4 80188DF4 -O2 -msoft-float */
void allocateMereDenisBombChips(Obj *bomb_obj)
{
    u8 i;
    Obj *cur_obj;
    s16 j;
    s32 nb_objs;
    u8 unk_1;
    u8 sub_etat_1;
    u8 sub_etat_2;

    for (i = 0; i <= 2; i += 2)
    {
        cur_obj = level.objects;
        j = 0;
        nb_objs = level.nb_objects;
        while (j < nb_objs)
        {
            unk_1 = false;
            switch (bomb_obj->sub_etat)
            {
            case 1:
                sub_etat_1 = 0;
                sub_etat_2 = 1;
                break;
            case 3:
            case 5:
                if (bomb_obj->flags & FLG(OBJ_FLIP_X))
                {
                    sub_etat_1 = 4;
                    sub_etat_2 = 5;
                }
                else
                {
                    sub_etat_1 = 2;
                    sub_etat_2 = 3;
                }
                break;
            case 7:
                if (bomb_obj->flags & FLG(OBJ_FLIP_X))
                    unk_1 = true;
                sub_etat_1 = 6;
                sub_etat_2 = 7;
                break;
            }

            if (
                cur_obj->type == TYPE_SMA_BOMB_CHIP &&
                !(cur_obj->flags & FLG(OBJ_ACTIVE)) &&
                (cur_obj->sub_etat == sub_etat_1 || cur_obj->sub_etat == sub_etat_2)
            )
            {
                cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_FLIP_X) | (bomb_obj->flags & FLG(OBJ_FLIP_X)));
                cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
                cur_obj->x_pos = bomb_obj->x_pos;
                cur_obj->y_pos = bomb_obj->y_pos;
                set_main_and_sub_etat(
                    cur_obj, 1, (i == 0 ? sub_etat_1 : sub_etat_2)
                );
                calc_obj_pos(cur_obj);
                skipToLabel(
                    cur_obj, (unk_1 ? i == 0 : i != 0), true
                );
                break;
            }
            cur_obj++;
            j++;
        }
    }

    allocateExplosion(bomb_obj);
    PlaySnd(220, bomb_obj->id);
    bomb_obj->flags &= ~FLG(OBJ_ACTIVE);
    bomb_obj->flags &= ~FLG(OBJ_ALIVE);
}

/* 64810 80189010 -O2 -msoft-float */
void mereDenisExplodeBombs(void)
{
    s16 var_t0; s16 var_v0; /* didn't name yet, because dunno which is y, which is x, if it's spatial repr. */
    s16 id;
    Obj *obj;

    for (var_t0 = 0; var_t0 < (s16) LEN(droppedBombIds); var_t0++)
    {
        for (var_v0 = 0; var_v0 < (s16) (LEN(droppedBombIds[var_t0])); var_v0++)
        {
            id = droppedBombIds[var_t0][var_v0];
            if (id != -1)
            {
                obj = &level.objects[id];
                obj->timer = 70;
                droppedBombIds[var_t0][var_v0] = -1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisDropBomb);

/* 64D48 80189548 -O2 -msoft-float */
void snapWeaponAnimState(Obj *obj, u8 sub_etat)
{
    set_main_and_sub_etat(obj, 0, sub_etat);
    obj->anim_frame = 0;
    obj->anim_index = obj->eta[0][sub_etat].anim_index;
}

/* 64DA0 801895A0 -O2 -msoft-float */
void swapMereDenisCollZones(Obj *obj, u8 smama2)
{
    if (!smama2)
        obj->type = TYPE_SPACE_MAMA;
    else
        obj->type = TYPE_SPACE_MAMA2;
    obj->zdc = type_zdc[obj->type];
}

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", prepareNewMereDenisAttack);

/* 6619C 8018A99C -O2 -msoft-float */
void snapLaserToWeapon(Obj *laser_obj, u8 param_2)
{
    Obj *unk_obj = &level.objects[laser_obj->field20_0x36];
    s16 x; s16 y; s16 w; s16 h;
    u8 sub_etat;
    ObjState *eta;

    GET_SPRITE_POS(unk_obj, laser_obj->field24_0x3e, &x, &y, &w, &h);
    if (param_2)
    {
        sub_etat = unk_obj->sub_etat;
        eta = &unk_obj->eta[unk_obj->main_etat][sub_etat];
        switch (sub_etat)
        {
        case 17:
            eta->anim_index = 47;
            break;
        case 18:
            eta->anim_index = 46;
            break;
        case 35:
            eta->anim_index = 48;
            break;
        }
        unk_obj->anim_index = eta->anim_index;
        laser_obj->x_pos = x - laser_obj->offset_bx;
        if (unk_obj->flags & FLG(OBJ_FLIP_X))
        {
            laser_obj->cmd = GO_RIGHT;
            laser_obj->x_pos += w - 5;
        }
        else
        {
            laser_obj->cmd = GO_LEFT;
            laser_obj->x_pos += 5;
        }
    }
    laser_obj->speed_y = 0;
    laser_obj->y_pos = y + (h >> 1) - ((laser_obj->offset_by + laser_obj->offset_hy) / 2) + 2;
}

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", allocateSpaceMamaLaser);

/* 664CC 8018ACCC -O2 -msoft-float */
void doMereDenisCommand(Obj *obj)
{
    if (mere_denis_wait_time != 0)
        mere_denis_wait_time--;
    else if (mereDenisCanAttak(obj))
    {
        if (bossSafeTimer != 0)
            bossSafeTimer--;
        
        if (!(obj->flags & FLG(OBJ_FLAG_0)))
        {
            if (obj->cmd == GO_WAIT)
            {
                if (laserSourceSprNumInAnim != 0xFF)
                    allocateSpaceMamaLaser(obj);
                bossXToReach = -32000;
                bossYToReach = -32000;
                circleIndex = -32000;
                obj->speed_x = 0;
                obj->speed_y = 0;
            }
            else
            {
                laserSourceSprNumInAnim = 0xFF;
                if (circleIndex != -32000)
                    setCirclePointToReach();
                else if (
                    timerBeforeFirstBomb == 0 &&
                    currentBombSequence != 0xFF &&
                    obj->main_etat == 0 && obj->sub_etat == 15
                )
                    mereDenisDropBomb(obj);
                else if (timerBeforeFirstBomb != 0)
                    timerBeforeFirstBomb--;
                setBossReachingSpeeds(obj, bossReachingTimer, bossReachingAccuracyX, bossReachingAccuracyY);
            }
            testActionEnd(obj);
        }
        prepareNewMereDenisAttack(obj);
    }
    obj->flags &= ~FLG(OBJ_FLAG_0);
}

/* 666A4 8018AEA4 -O2 -msoft-float */
void changeMereDenisPhase(void)
{
  u8 old_encounter;
  u8 *encounter;
  u8 *action;
  
  if (bossEncounter == 8 || bossEncounter == 9)
  {
    encounter = &saveBossEncounter;
    action = &saveCurrentBossAction;
  }
  else
  {
    encounter = &bossEncounter;
    action = &currentBossAction;
  }
  old_encounter = *encounter;

  switch (*encounter)
  {
  case 1:
    if (currentPhaseHitCounter > 1 && stepsForward > 2)
    {
      *encounter = 2;
      stepsForward = 0;
    }
    break;
  case 2:
    if (currentPhaseHitCounter > 2)
      *encounter = 3;
    break;
  case 3:
  case 4:
  case 5:
  case 6: /* set to this at some point in prepareNewMereDenisAttack, not sure if max for space_mama */
    break;
  }

  if (old_encounter != *encounter)
  {
    *action = 0;
    currentPhaseHitCounter = 0;
  }
}

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", fitSaveCurrentAction);

/* 668E4 8018B0E4 -O2 -msoft-float */
void doMereDenisHit(Obj *obj, s16 sprite)
{
    s16 unk_1;
    u8 main_etat = obj->main_etat;
    u8 sub_etat = obj->sub_etat;
    
    if ((obj->eta[main_etat][sub_etat].flags & 1) && bossSafeTimer == 0)
    {
        switch (main_etat * 0x100 + sub_etat)
        {
        case 0x013:
        case 0x015:
        case 0x016:
        case 0x017:
        case 0x018:
        case 0x01e:
        case 0x01f:
        case 0x022:
            unk_1 = 0x00FF;
            break;
        case 0x002:
        case 0x006:
        case 0x00a:
        case 0x00b:
        case 0x00d:
        case 0x00f:
        case 0x025:
        case 0x02c:
            unk_1 = -1;
            break;
        default:
            unk_1 = 1;
            break;
        }

        if (unk_1 == sprite)
        {
            if (unk_1 == 1)
            {
                poing.damage = 1;
                obj_hurt(obj);
                currentPhaseHitCounter++;
                changeMereDenisPhase();
            }

            if (obj->hit_points != 0)
            {
                if (!(bossEncounter == 8 || bossEncounter == 9))
                {
                    fitSaveCurrentAction(obj);
                    if (obj->type == TYPE_SPACE_MAMA)
                        bossEncounter = 8;
                    else
                        bossEncounter = 9;
                }
            }
            else
                bossEncounter = 10;
            
            currentBossAction = 0;
            bossSafeTimer = 0xFF;
            currentBossActionIsOver = true;
            obj->flags |= FLG(OBJ_FLAG_0);
        }
    }
}

/* 66A64 8018B264 -O2 -msoft-float */
void mereDenisBigLaserCommand(Obj *laser_obj)
{
    u8 max_frame;
    Obj *unk_obj;
    ObjState *unk_eta;

    switch (laser_obj->sub_etat)
    {
    case 3:
    case 5:
        max_frame = 0;
        break;
    case 4:
        max_frame = 7;
        break;
    case 2:
        max_frame = 14;
        break;
    }

    if (laser_obj->anim_frame <= max_frame)
        snapLaserToWeapon(laser_obj, false);
    else
    {
        unk_obj = &level.objects[laser_obj->field20_0x36];
        if (unk_obj->field20_0x36 == laser_obj->id)
        {
            unk_eta = &unk_obj->eta[unk_obj->main_etat][unk_obj->sub_etat];
            switch (unk_obj->anim_index)
            {
            case 46:
                unk_eta->anim_index = 1;
                break;
            case 47:
                unk_eta->anim_index = 0;      
                break;  
            case 48:
                unk_eta->anim_index = 28;
                break;        
            }
        }
    }
    SET_X_SPEED(laser_obj);
}

/* 66B98 8018B398 -O2 -msoft-float */
void mereDenisBombCommand(Obj *bomb_obj)
{
    if (bomb_obj->timer != 0)
    {
        bomb_obj->timer--;
        if (bomb_obj->timer == 0)
            allocateMereDenisBombChips(bomb_obj);
    }
}
