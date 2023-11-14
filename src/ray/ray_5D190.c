#include "ray/ray_5D190.h"

extern BlockType hand_btyp;
extern BlockType hand_btypd;
extern BlockType hand_btypg;

/* 5D190 80181990 -O2 -msoft-float */
void allocateRayLandingSmoke(void)
{
    Obj *obj;

    if (!no_ray_landing_smoke)
    {
        obj = allocateExplosion(&ray);
        if (obj)
        {
            set_main_and_sub_etat(obj, 0, 1);
            calc_obj_pos(obj);
        }
    }
}

/* 5D1E8 801819E8 -O2 -msoft-float */
void recale_ray_on_liane(void)
{
    s16 x;
    s32 unk_1;

    if (hand_btyp == BTYP_LIANE)
        x = (ray.offset_bx + ray.x_pos) & 0xFFF0; /* why the &? */
    else
    {
        if (hand_btypg == BTYP_LIANE)
        {
            x = (ray.offset_bx + ray.x_pos - 15) & 0xFFF0;
            hand_btyp = hand_btypg;
        }
        else if (hand_btypd == BTYP_LIANE)
        {
            x = (ray.offset_bx + ray.x_pos + 15) & 0xFFF0;
            hand_btyp = hand_btypd;
        }
    }
    unk_1 = 8;
    ray.x_pos = x - (ray.offset_bx - unk_1);
}

/* 5D2C0 80181AC0 -O2 -msoft-float */
void calc_bhand_typ(Obj *obj)
{
  s16 x;
  u8 unk_1;
  s16 y;

  x = obj->offset_bx + obj->x_pos;
  unk_1 = obj->speed_y + 22 + obj->offset_hy;
  if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
    unk_1 = 80 - ((80 - unk_1) >> 1);
  y = unk_1 + obj->y_pos;
  hand_btyp = PS1_BTYPAbsPos(x, y);
  if (hand_btyp != BTYP_LIANE)
  {
    hand_btypg = PS1_BTYPAbsPos(x - 8, y);
    hand_btypd = PS1_BTYPAbsPos(x + 8, y);
  }
  else
  {
    hand_btypd = BTYP_SOLID;
    hand_btypg = BTYP_SOLID;
  }
}


INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", IS_RAY_ON_LIANE);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", rayMayLandOnAnObject);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", set_air_speed);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", Reset_air_speed);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", determineRayAirInertia);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", ray_jump);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", ray_inertia_speed);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_SWIP);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", FUN_801835c0);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_STOP);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_HELICO);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", Make_Ray_Hang);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", AIR);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", MUR);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", CAN_RAY_HANG_BLOC);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_TOMBE);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_DOWN);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_UP);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_DIR);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_NOTHING);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", PS1_RespondShoulderR);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", PS1_RespondShoulderL);

void RAY_RESPOND_TO_BUTTON4(void) {
}

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_BUTTON3);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_FIRE0);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_FIRE1);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_BALANCE_ANIM);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", abs_sinus_cosinus);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", SET_RAY_BALANCE);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_GOING_BALANCE);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_BALANCE);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_FIN_BALANCE);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RayTestBlocSH);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", remoteControlRay);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", STOPPE_RAY_CONTRE_PAROIS);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_IN_THE_AIR);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", terminateFistWhenRayDies);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", snifRayIsDead);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", rayfallsinwater);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_DEAD);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_HURT);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RepousseRay);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RayEstIlBloque);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", stackRay);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_SURF);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", DO_SURF_CHANGE_HAIRS);

void RAY_PREPARE_PIEDS(void) {}

void DO_PIEDS_RAYMAN(void) {}

void DO_PIEDS_COLLISION(void) {}

void allocatePiedBoum(void) {}

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", DO_MORT_DE_RAY);
