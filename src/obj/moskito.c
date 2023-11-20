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

INCLUDE_ASM("asm/nonmatchings/obj/moskito", closeEnoughToSting);

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
  
  width = 320;
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
      res = obj->offset_bx + obj->x_pos - ((scroll_start_x + scroll_end_x + 320) / 2);
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

INCLUDE_ASM("asm/nonmatchings/obj/moskito", prepareNewMoskitoAttack);

INCLUDE_ASM("asm/nonmatchings/obj/moskito", allocateMoskitoFruit);

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
      scroll_end_x + 320 >= x_2 &&
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

INCLUDE_ASM("asm/nonmatchings/obj/moskito", tellNextMoskitoAction);

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
#ifndef NONMATCHINGS /* div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/obj/moskito", doMoskitoHit);
#else
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

    __asm__("nop");
}
#endif