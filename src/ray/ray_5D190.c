#include "ray/ray_5D190.h"

extern BlockType hand_btyp;
extern BlockType hand_btypd;
extern BlockType hand_btypg;
extern s16 jump_time;

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

/* 5D3AC 80181BAC -O2 -msoft-float */
void IS_RAY_ON_LIANE(void)
{
    s16 speed_y;

    if (ray.main_etat != 2 || ray.timer == 0)
    {
        if (jump_time > 10)
        {
            speed_y = ray.speed_y;
            ray.speed_y = 0;
            calc_bhand_typ(&ray);
            ray.speed_y = speed_y;
            if(
                (hand_btyp == BTYP_LIANE || hand_btypg == BTYP_LIANE || hand_btypd == BTYP_LIANE) &&
                !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)))
            )
            {
                if (ray.main_etat == 2 && ray.sub_etat == 8)
                    ray.iframes_timer = 90;
                recale_ray_on_liane();
                set_main_and_sub_etat(&ray, 4, 1);
                ray.speed_y = 0;
                ray.speed_x = 0;
                ray.field24_0x3e = 0;
                decalage_en_cours = 0;
                PlaySnd(9, -1);
            }
        }
    }
    else
        ray.timer--;
}

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", rayMayLandOnAnObject);

/* unknowns... */
/* 5DE3C 8018263C -O2 -msoft-float */
void set_air_speed(u8 main_etat, u8 sub_etat, s16 param_3, u8 param_4)
{
  s32 unk_1;
  ObjState *eta;
  s8 unk_2;
  s32 right;
  s32 left;
  
  unk_1 = __builtin_abs(param_3) << 0x14 >> 0x18;
  eta = &ray.eta[main_etat][sub_etat];
  if (unk_1 > 112)
    unk_1 = 112;
  
  unk_2 = -unk_1;
  if (ray.speed_x > 0)
  {
    eta->speed_x_left = -16;
    right = param_4;
    if (param_4 < unk_1)
      right = unk_1;
    eta->speed_x_right = right;
  }
  else if (ray.speed_x < 0)
  {
    left = -param_4;
    if (unk_2 < left)
      left = unk_2;
    eta->speed_x_left = left;
    eta->speed_x_right = 16;
  }
  else
  {
    eta->speed_x_left = -param_4;
    eta->speed_x_right = param_4;
  }
}



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
