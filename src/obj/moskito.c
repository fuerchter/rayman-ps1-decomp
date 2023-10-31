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

INCLUDE_ASM("asm/nonmatchings/obj/moskito", moskitoDropFruitOnRay);

/* 71030 80195830 -O2 -msoft-float */
/*? calc_obj_dir(Obj *);
s32 closeEnoughToSting(Obj *, ?, ?);
? moskitoDropFruitOnRay(Obj *);
? prepareNewMoskitoAttack(Obj *);
? setBossReachingSpeeds(Obj *, u8, u8, u8);
? testActionEnd(Obj *);*/
u8 closeEnoughToSting(Obj *arg0, u16 arg1, u16 arg2);

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

INCLUDE_ASM("asm/nonmatchings/obj/moskito", doMoskitoHit);
