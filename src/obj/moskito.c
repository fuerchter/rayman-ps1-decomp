#include "obj/moskito.h"

extern s16 ray_zdc_h;
extern s16 ray_zdc_w;
extern s16 ray_zdc_x;
extern s16 ray_zdc_y;
extern s16 bossScrollEndX;
extern s16 bossScrollEndY;
extern s16 bossScrollStartX;
extern s16 bossScrollStartY;
extern s16 floorLine;
extern s16 xmapmax;
extern s16 ymapmax;
extern s16 h_scroll_speed;
extern u8 scrollLocked;
extern s16 scroll_end_x;
extern s16 scroll_end_y;
extern s16 scroll_start_x;
extern s16 scroll_start_y;
extern s16 v_scroll_speed;
extern s16 xmap;
extern s16 ymap;
extern s32 alternateBossSpeedFactor;
extern u8 bossEncounter;
extern u8 bossReachingAccuracyX;
extern u8 bossReachingAccuracyY;
extern u8 bossReachingTimer;
extern s8 bossSafeTimer;
extern s16 bossXToReach;
extern s16 bossYToReach;
extern u8 curAct;
extern u8 currentBossAction;
extern u8 currentBossActionIsOver;
extern u8 fin_boss;
extern s8 fistAvoided;
extern u8 *moskitoActionSequences[10];
extern u8 mstMustLeaveScreenToProceed;
extern Obj ray;
extern s16 remoteRayXToReach;
extern u8 saveBossEncounter;
extern u8 saveCurrentBossAction;

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
  if (obj->flags & OBJ_FLIP_X)
    calc_x -= 48;
  else
    calc_x += 48;
  *out_x = calc_x;
  *out_y = calc_y - 112;
}

/* 6F988 80194188 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/moskito", closeEnoughToSting);

/* 6FA3C 8019423C -O2 -msoft-float */
/*s16 firstFloorBelow();*/

void PS1_setBossScrollLimits_moskito(Obj *obj)
{
    s16 x;

    x = obj->offset_bx + obj->init_x_pos - 272;
    bossScrollStartX = x;
    bossScrollEndX = x;

    floorLine = firstFloorBelow();
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
s32 moskitoCanAttak(Obj *obj)
{
    u8 locked;
    s16 one;
    s32 res;

    if (!scrollLocked)
    {
        locked = FALSE;
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
    {
        one = 1;
        obj->timer -= one;
    }
    res = FALSE;
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
      obj->flags &= ~OBJ_FLIP_X;
      break;
    case 1:
      res = 1;
      obj->x_pos = scroll_end_x - (obj->offset_bx - width);
      obj->flags |= OBJ_FLIP_X;
      break;
    default:
      res = obj->offset_bx + obj->x_pos - ((scroll_start_x + scroll_end_x + 320) / 2);
      if (res >= 1)
      {
        obj->x_pos = scroll_end_x - (obj->offset_bx - width);
        obj->flags &= ~OBJ_FLIP_X;
      }
      else
      {
        obj->x_pos = scroll_start_x - obj->offset_bx;
        obj->flags |= OBJ_FLIP_X;
      }
      break;
  }
  return res;
}

/* 6FDC8 801945C8 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/moskito", prepareNewMoskitoAttack);

/* 70C64 80195464 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/moskito", allocateMoskitoFruit);

/* 70E50 80195650 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/moskito", moskitoDropFruitOnRay);

INCLUDE_ASM("asm/nonmatchings/obj/moskito", doMoskitoCommand);

INCLUDE_ASM("asm/nonmatchings/obj/moskito", tellNextMoskitoAction);

INCLUDE_ASM("asm/nonmatchings/obj/moskito", changeMoskitoPhase);

INCLUDE_ASM("asm/nonmatchings/obj/moskito", doMoskitoHit);
