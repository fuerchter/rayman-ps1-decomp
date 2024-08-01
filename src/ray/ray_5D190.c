#include "ray/ray_5D190.h"

/* TODO: flip the "_etat !=" in this file */

s32 calc_typ_trav(Obj *obj,u8 param_2);
void ChangeLevel(void);
s32 TEST_IS_ON_RESSORT_BLOC(Obj *obj);
void recale_position(Obj *param_1);

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

/* 5DF0C 8018270C -O2 -msoft-float */
void Reset_air_speed(u8 is_rolling_speed)
{
    if (is_rolling_speed)
    {
        set_air_speed(2, 17, decalage_en_cours, 48);
        set_air_speed(2, 18, decalage_en_cours, 48);
        set_air_speed(2, 19, decalage_en_cours, 48);
        set_air_speed(2, 3, decalage_en_cours, 48);
        set_air_speed(2, 5, decalage_en_cours, 48);
        set_air_speed(2, 4, decalage_en_cours, 48);
        set_air_speed(2, 32, decalage_en_cours, 48);
    }
    else
    {
        set_air_speed(2, 0, decalage_en_cours, 32);
        set_air_speed(2, 1, decalage_en_cours, 32);
        set_air_speed(2, 2, decalage_en_cours, 32);
        set_air_speed(2, 24, decalage_en_cours, 32);
        set_air_speed(2, 11, decalage_en_cours, 32);
        set_air_speed(2, 12, decalage_en_cours, 32);
        set_air_speed(2, 13, decalage_en_cours, 32);
        set_air_speed(2, 3, decalage_en_cours, 32);
        set_air_speed(2, 5, decalage_en_cours, 32);
        set_air_speed(2, 4, decalage_en_cours, 32);
    }
}

/* 5E0CC 801828CC -O2 -msoft-float */
void determineRayAirInertia(void)
{
    /* this seems more readable to me than if/elseif, etc. */
    if (ray_wind_force != 0)
    {
        ray.nb_cmd = 1;
        return;
    }
    if (ray.field20_0x36 != -1)
    {
        ray.nb_cmd = 0;
        return;
    }
    switch(ray_last_ground_btyp)
    {
    case false:
        if (__builtin_abs(decalage_en_cours) <= 256)
            ray.nb_cmd = 0;
        else
            ray.nb_cmd = 1;
        break;
    case true:
        ray.nb_cmd = 0;
        break;
    }
}

/* 5E15C 8018295C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", ray_jump);
#else
void ray_jump(void)
{
    u8 unk_1;
    s16 speed_y;
    s16 follow_y;
    s32 unk_2;
    u8 is_rolling_speed;

    unk_1 = 1;
    if ((ray.eta[ray.main_etat][ray.sub_etat].flags & 1) && (button_released & 1) == unk_1)
    {
        if (ray.main_etat == 7)
        {
            decalage_en_cours = ashl16(ray.speed_x, 7);
            ray.speed_y -= 2;
        }
        else
        {
            if (ray.main_etat == 4)
                ray.speed_y = -3;
            else
                ray.speed_y = -5;
        }
        speed_y = ray.speed_y;
        if (ray.field20_0x36 != -1)
        {
            follow_y = level.objects[ray.field20_0x36].follow_y;
            if (speed_y > follow_y)
                speed_y = follow_y;
        }
        else
        {
            switch (ray.btypes[0])
            {
            case BTYP_NONE:
                break;
            case BTYP_SOLID_RIGHT_45:
            case BTYP_SLIPPERY_RIGHT_45:
                if (ray.speed_x >= 6)
                    speed_y = ~ray.speed_x;
                break;
            case BTYP_SOLID_LEFT_45:
            case BTYP_SLIPPERY_LEFT_45:
                if (ray.speed_x < -5)
                    speed_y = ray.speed_x - 1;
                break;
            case BTYP_SOLID_RIGHT1_30:
            case BTYP_SOLID_RIGHT2_30:
            case BTYP_SLIPPERY_RIGHT1_30:
            case BTYP_SLIPPERY_RIGHT2_30:
                if (ray.speed_x > 10)
                    speed_y = ~ashr16(ray.speed_x, 1);
                break;
            case BTYP_SOLID_LEFT1_30:
            case BTYP_SOLID_LEFT2_30:
            case BTYP_SLIPPERY_LEFT1_30:
            case BTYP_SLIPPERY_LEFT2_30:
                if (ray.speed_x < -10)
                    speed_y = ~ashr16(ray.speed_x, 1);
                break;
            case BTYP_SLIPPERY:
                break;
            }
        }
        ray.speed_y = speed_y;
        determineRayAirInertia();
        if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
            unk_2 = 256;
        else
            unk_2 = 512;
        
        if (ray_on_poelle)
        {
            Reset_air_speed(false);
            if (ray.main_etat == 0 && ray.sub_etat == 40)
                set_main_and_sub_etat(&ray, 2, 25);
            else
                set_main_and_sub_etat(&ray, 2, 27);
        }
        else
        {
            is_rolling_speed = unk_2 < __builtin_abs(decalage_en_cours);
            Reset_air_speed(is_rolling_speed);
            if (is_rolling_speed)
                set_main_and_sub_etat(&ray, 2, 17);
            else
                set_main_and_sub_etat(&ray, 2, 0);
        }
        in_air_because_hit = false;
        jump_time = 0;
        helico_time = -1;
        ray.gravity_value_1 = 0;
        ray.gravity_value_2 = 0;
        ray.field20_0x36 = -1;
        button_released = 0;
        poing.is_charging = false;
        D_801E51E8 = ray.x_pos;
        D_801E51F8 = ray.y_pos;
        if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
            ray.speed_y = ashr16(ray.speed_y, 1) - 1;
    }
    __asm__("nop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", ray_inertia_speed);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_SWIP);

/* 5EF40 80183740 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_STOP);
#else
void RAY_STOP(void)
{
  u8 main_etat = ray.main_etat;

  if (main_etat == 1 || ray.field20_0x36 != -1)
  {
    switch(main_etat * 0x100 + ray.sub_etat)
    {
    case 0x108:
    case 0x10a:
      set_main_and_sub_etat(&ray, 0, 47);
      break;
    case 0x109:
    case 0x10b:
      set_main_and_sub_etat(&ray, 0, 48);
      break;
    case 0x100:
    case 0x103:
    case 0x104:
    case 0x105:
    case 0x107:
      set_main_and_sub_etat(&ray, 0, 0);
      break;
    }

    if (decalage_en_cours == 0)
    {
      ray.speed_y = 0;
      ray.speed_x = 0;
    }
  }
  else if (main_etat == 4)
  {
    ray.speed_y = 0;
    set_sub_etat(&ray, 0);
  }

  __asm__("nop");
}
#endif

/* 5F054 80183854 -O2 -msoft-float */
void RAY_HELICO(void)
{
    ObjState **eta;
    ObjState *sel_eta;

    eta = ray.eta;
    if (
        ray.eta[ray.main_etat][ray.sub_etat].flags & 4 &&
        button_released == 1 && options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e)
    )
    {
        if (
            RayEvts.flags0 & FLG(RAYEVTS0_SUPER_HELICO) &&
            !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)))
        )
        {
            button_released = 2;
            set_sub_etat(&ray, 14);
            sel_eta = &eta[ray.main_etat][ray.sub_etat];
            sel_eta->anim_speed = sel_eta->anim_speed & 0xF | 0x30;
            sel_eta = &eta[2][15];
            sel_eta->anim_speed = sel_eta->anim_speed & 0xF | 0x20;
            ray_Suphelico_bis = 0;
            helico_time = -1;
            ray.field24_0x3e = -1;
            ray.timer = 0;
            ray_clic = 0;
            D_801E62F0 = 0;
        }
        else if (
            RayEvts.flags0 & FLG(RAYEVTS0_HELICO) &&
            !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)))
        )
        {
            button_released = 2;
            set_sub_etat(&ray, 3);
            ray.anim_frame = 0;
            helico_time = 50;
            ray.field24_0x3e = -1;
        }
    }
    if (ray.sub_etat == 15)
    {
        sel_eta = &eta[ray.main_etat][ray.sub_etat];
        if ((sel_eta->anim_speed & 0xF0) == 0x20)
        {
            sel_eta->anim_speed = sel_eta->anim_speed & 0xF | 0xA0;
            ray.gravity_value_1 = 0;
            ray.gravity_value_2 = 20;
        }
    }
    if (
        (button_released == 3 && options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e)) ||
        helico_time == 0
    )
    {
        if (
            RayEvts.flags0 & FLG(RAYEVTS0_SUPER_HELICO) &&
            !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)))
        )
        {
            if (ray.sub_etat == 15 && helico_time != 0)
            {
                ray.gravity_value_1 = 0;
                ray_Suphelico_bis = 1;
                button_released = 2;
                sel_eta = &eta[ray.main_etat][ray.sub_etat];
                sel_eta->anim_speed = sel_eta->anim_speed & 0xF | 0xA0;
                ray_clic++;
                ray.gravity_value_2 = 20;
                ray.speed_y = -1;

                if (ray_clic > 1)
                {
                    if (ray_between_clic >= 0)
                    {
                        if(!(ray.flags & FLG(OBJ_FLIP_X)) && ray.speed_x < -1 && leftjoy(0))
                            ray.speed_x = -48;
                        else if(ray.flags & FLG(OBJ_FLIP_X) && ray.speed_x > 1 && rightjoy(0))
                            ray.speed_x = 48;
                        else if (ray.speed_x == 0)
                            ray.speed_y = -2;
                        
                        helico_time = 70;
                        ray_clic = 0;
                        ray_inertia_speed(0xFF, 0, ashl16(ray.speed_x, 4), ray_wind_force);
                    }
                    else
                    {
                        ray_clic = 1;
                        ray_between_clic = 20;
                    }
                }
                else
                    ray_between_clic = 20;
            }
        }
        else
        {
            button_released = 4;
            set_sub_etat(&ray, 5);
            helico_time = -1;
            ray.field24_0x3e = 0;
        }
    }
}

/* 5F52C 80183D2C -O2 -msoft-float */
void Make_Ray_Hang(s16 param_1, s16 param_2)
{
    s32 unk_1;
    u8 unk_2;
    s32 unk_3;
    s32 unk_4;

    if (ray.main_etat == 2 && ray.sub_etat == 8)
        ray.iframes_timer = 90;
    set_main_and_sub_etat(&ray, 5, 0);
    unk_1 = get_proj_dist2(ray.scale, 32);
    
    if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
        unk_2 = 3;
    else
        unk_2 = 7;

    if (ray.flags & FLG(OBJ_FLIP_X))
        unk_3 = 16 - unk_2;
    else
        unk_3 = unk_2;
    
    if (ray.scale != 0)
        unk_1 += 37;
    ray.y_pos = (param_2 >> 4 << 4) - unk_1;
    ray.speed_y = 0;
    ray.speed_x = 0;
    ray.field24_0x3e = 0;
    ray.gravity_value_1 = 0;
    ray.gravity_value_2 = 0;
    ray.field20_0x36 = -1;
    decalage_en_cours = 0;
    jump_time = 0;
    unk_4 = 1;
    ray.x_pos = (param_1 >> 4 << 4) - ray.offset_bx + (unk_3 - unk_4);
}

/* 5F680 80183E80 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", AIR);
#else
u16 AIR(s32 param_1)
{
  __asm__("nop");

  return block_flags[((u16) mp.map[param_1]) >> 10] >> BLOCK_SOLID & 1 ^ 1;
}
#endif

/* 5F6C0 80183EC0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", MUR);
#else
u16 MUR(s32 param_1)
{
  __asm__("nop");

  return block_flags[(u16) mp.map[param_1] >> 10] >> BLOCK_SOLID & 1;
}
#endif

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", CAN_RAY_HANG_BLOC);


/* 5FAB8 801842B8 -O2 -msoft-float */
void RAY_TOMBE(void)
{
  if (ray_on_poelle)
  {
    if (ray.main_etat == 0 && ray.sub_etat == 40)
      set_main_and_sub_etat(&ray, 2, 26);
    else
      set_main_and_sub_etat(&ray, 2, 28);
  }
  else
  {
    if (ray.main_etat == 1 && ray.sub_etat == 11)
      ray.flags = ray.flags & ~FLG(OBJ_FLIP_X) | ((ray.flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X;
    if (ray.main_etat == 5)
      set_main_and_sub_etat(&ray, 2, 1);
    else
    {
      if (__builtin_abs(ray.speed_x) < 3)
        set_main_and_sub_etat(&ray, 2, 24);
      else
        set_main_and_sub_etat(&ray, 2, 32);
    }
  }
  jump_time = 0;
  helico_time = -1;
  ray.gravity_value_1 = 0;
  ray.gravity_value_2 = 0;
  ray.field20_0x36 = -1;
  button_released = 0;
  poing.is_charging = false;
  determineRayAirInertia();
}

/* 5FC44 80184444 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_DOWN);
#else
void RAY_RESPOND_TO_DOWN(void)
{
    u8 flag_set;
    ObjState *sel_eta_1;
    ObjState *sel_eta_2;
    s32 unk_1;

    switch (ray.main_etat)
    {
    case 4:
        if (ray.sub_etat != 11 && ray.sub_etat != 12)
        {
            ray.speed_y = 1;
            if (ray.scale != 0 && horloge[2] != 0)
                DO_ANIM(&ray);
            calc_bhand_typ(&ray);
            if (hand_btyp != BTYP_LIANE)
                RAY_TOMBE();
            else if (ray.sub_etat != 3)
                set_sub_etat(&ray, 3);
        }
        else
            ray.speed_y = 0;
        break;
    case 0:
        /* not a switch? */
        if (
            ray.sub_etat == 0 || ray.sub_etat == 1 || ray.sub_etat == 2 || ray.sub_etat == 3 ||
            ray.sub_etat == 49 || ray.sub_etat == 8 || ray.sub_etat == 43 || ray.sub_etat == 36 ||
            ray.sub_etat == 37 || ray.sub_etat == 38 || ray.sub_etat == 39 || ray.sub_etat == 40 ||
            ray.sub_etat == 41 || ray.sub_etat == 42 || ray.sub_etat == 13 || ray.sub_etat == 59 ||
            ray.sub_etat == 62 || ray.sub_etat == 63
        )
            set_main_and_sub_etat(&ray, 3, 6);
        else if (ray.sub_etat == 20)
        {
            flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
            if(
                (flag_set && ray.anim_frame == 0) || 
                (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
            )
            {
                sel_eta_1 = &ray.eta[ray.main_etat][ray.sub_etat];
                if (horloge[sel_eta_1->anim_speed & 0xF] == 0)
                {
                    /* ??? */
                    unk_1 = ((sel_eta_1->flags >> 4 ^ 1) & 1) * 0x10;
                    sel_eta_1->flags = (sel_eta_1->flags & 0xEF) | unk_1;
                    FUN_80150c5c(&ray, 1);
                    sel_eta_2 = &ray.eta[ray.main_etat][ray.sub_etat];
                    unk_1 = ((sel_eta_2->flags >> 4 ^ 1) & 1) * 0x10;
                    sel_eta_2->flags = (sel_eta_2->flags & 0xEF) | unk_1;
                }
            }
        }
        RAY_SWIP();
        break;
    case 1:
        if (
            !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))) &&
            !FUN_80133984(0) && !FUN_801339f4(0)
        )
            RAY_STOP();
        break;
    case 5:
        ray.y_pos += 14;
        RAY_TOMBE();
        break;
    case 6:
        decalage_en_cours = 0;
        ray.flags |= FLG(OBJ_FLIP_X);
        if (ray.speed_y < 3 && ray.gravity_value_1 == 0)
            ray.speed_y++;
        break;
    }

    __asm__("nop\nnop");
}
#endif

/* 6002C 8018482C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_UP);
#else
void RAY_RESPOND_TO_UP(void)
{
    switch (ray.main_etat)
    {
    case 4:
        if (ray.sub_etat != 11 && ray.sub_etat != 12)
        {
            calc_bhand_typ(&ray);
            if (hand_btyp == BTYP_NONE)
            {
                RAY_TOMBE();
                ray.timer = 10;
                ray.speed_y = 1;
            }
            else if (hand_btyp != BTYP_LIANE)
                ray.speed_y = 0;
            else
            {
                ray.speed_y = -1;
                if (ray.scale != 0 && horloge[2] != 0)
                    DO_ANIM(&ray);
            }

            if (ray.sub_etat != 2)
                set_sub_etat(&ray, 2);
        }
        else
            ray.speed_y = 0;
        break;
    case 1:
        if (
            !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))) &&
            !FUN_80133984(0) && !FUN_801339f4(0)
        )
            RAY_STOP();
        break;
    case 5:
        v_scroll_speed = 0xFF;
        break;
    case 0:
        if (ray.sub_etat == 37 && __builtin_abs(decalage_en_cours) <= 128)
            set_sub_etat(&ray, 38);
        RAY_SWIP();
        if (ray.field20_0x36 == -1)
            v_scroll_speed = 0xFF;
        if (
            ray.main_etat == 0 && ray.sub_etat == 15 &&
            !(block_flags[(u8) calc_typ_trav(&ray, 2)] >> BLOCK_FLAG_4 & 1)
        )
            set_main_and_sub_etat(&ray, 0, 60);
        break;
    case 6:
        decalage_en_cours = 0;
        ray.flags |= FLG(OBJ_FLIP_X);
        if (ray.speed_y > -3 && ray.gravity_value_1 == 0)
            ray.speed_y--;
        break;
    }

    __asm__("nop\nnop");
}
#endif

/* 602E8 80184AE8 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_DIR);
#else
void RAY_RESPOND_TO_DIR(s16 flip_x)
{
    Animation *sel_anim;
    s32 unk_1;
    s16 to_speed;

    switch (ray.main_etat)
    {
    case 1:
        joy_done++;
        if (
            ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40 &&
            !FUN_80133984(0) && !FUN_801339f4(0)
        )
        {
            if (!(block_flags[(u8) calc_typ_trav(&ray, 2)] >> BLOCK_FLAG_4 & 1))
            {
                if (ray.main_etat != 0 || ray.sub_etat != 60)
                    set_main_and_sub_etat(&ray, 0, 60);
            }
            else if (ray.main_etat != 0 || (ray.sub_etat != 15 && ray.sub_etat != 61))
            {
                sel_anim = &ray.animations[ray.anim_index];
                set_main_and_sub_etat(&ray, 0, 15);
                ray.anim_frame = sel_anim->frames_count - 1;
            }
        }
        else if (
            ((ray.flags >> OBJ_FLIP_X & 1) != flip_x) &&
            ray.sub_etat != 11 && ray.sub_etat != 50 && ray.sub_etat != 51 &&
            ray_last_ground_btyp != true
        )
            set_main_and_sub_etat(&ray, 1, 4);
        if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40))
            ray.flags = (ray.flags & ~FLG(OBJ_FLIP_X)) | ((flip_x & 1) << OBJ_FLIP_X);
        RAY_SWIP();
        break;
    case 0:
        joy_done++;
        if (
            ray.sub_etat == 15 &&
            !downjoy(0) &&
            !(block_flags[(u8) calc_typ_trav(&ray, 2)] >> BLOCK_FLAG_4 & 1)
        )
            set_main_and_sub_etat(&ray, 1, 0);
        else if (
            ray.sub_etat != 11 && ray.sub_etat != 12 && ray.sub_etat != 18 &&
            ray.sub_etat != 20 && ray.sub_etat != 15 && ray.sub_etat != 47 &&
            ray.sub_etat != 48 && ray.sub_etat != 50 && ray.sub_etat != 51 &&
            ray.sub_etat != 61
        )
        {
            if ((ray.flags >> OBJ_FLIP_X & 1) != flip_x)
            {
                if (ray_last_ground_btyp != true)
                    set_main_and_sub_etat(&ray, 1, 4);
                else
                    set_main_and_sub_etat(&ray, 1, 0);
                ray.flags = (ray.flags & ~FLG(OBJ_FLIP_X)) | ((flip_x & 1) << OBJ_FLIP_X);
            }
            else
            {
                set_main_etat(&ray, 1);
                set_sub_etat(&ray, 0);
            }
        }
        RAY_SWIP();
        break;
    case 2:
        joy_done++;
        if (ray.sub_etat != 15 && ray.nb_cmd == 0)
            decalage_en_cours = 0;
        RAY_SWIP();
        if (!ray_on_poelle)
            ray.flags = (ray.flags & ~FLG(OBJ_FLIP_X)) | ((flip_x & 1) << OBJ_FLIP_X);
        break;
    case 4:
        /* TODO: ctrl flow? */
        joy_done++;
        if ((ray.sub_etat == 2 && upjoy(0)) || (ray.sub_etat == 3 && downjoy(0)))
        {
            calc_bhand_typ(&ray);
            if(hand_btyp == BTYP_NONE)
            {
                if (ray.sub_etat == 2)
                {
                    RAY_TOMBE();
                    ray.timer = 10;
                    ray.speed_y = 1;
                }
                else
                    RAY_TOMBE();
            }
            else if(hand_btyp != BTYP_LIANE)
                RAY_STOP();
        }
        else if (ray.sub_etat == 2 || ray.sub_etat == 3)
            RAY_STOP();
        
        if (
            options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e) &&
            (button_released & 1) == (unk_1 = 1) &&
            ray.sub_etat != 11 && ray.sub_etat != 12 && ray.sub_etat != 13
        )
        {
            ray_jump();
            decalage_en_cours = 256;
            return;
        }
        else if (ray.sub_etat == 13)
            if (((ray.flags >> OBJ_FLIP_X) & 1) != flip_x)
                set_sub_etat(&ray, 1);
        if (ray.sub_etat != 11 && ray.sub_etat != 12)
            ray.flags = (ray.flags & ~FLG(OBJ_FLIP_X)) | ((flip_x & 1) << OBJ_FLIP_X);
        break;
    case 5:
        joy_done++;
        if (((ray.flags >> OBJ_FLIP_X) & 1) != flip_x)
            RAY_TOMBE();
        break;
    case 6:
        joy_done++;
        decalage_en_cours = 0;
        ray.flags |= FLG(OBJ_FLIP_X);
        if (flip_x == 0)
            to_speed = -1;
        else
            to_speed = flip_x;
        flip_x = to_speed;
        if ((ray.speed_x * flip_x < 3) && ray.gravity_value_1 == 0)
            ray.speed_x += flip_x;
        break;
    }

    __asm__("nop\nnop\nnop");
}
#endif

/* 60A58 80185258 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_NOTHING);
#else
void RAY_RESPOND_TO_NOTHING(void)
{
    u8 flag_set;
    ObjState *sel_eta_1;
    ObjState *sel_eta_2;
    s32 unk_1;
    Animation *sel_anim;

    switch (ray.main_etat)
    {
    case 1:
        if (
            !(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40 && (FUN_80133984(0) || FUN_801339f4(0))) &&
            !(ray.sub_etat == 4 || ray.sub_etat == 5) && !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))))
        {
            set_main_etat(&ray, 0);
            if (ray.sub_etat == 8 || ray.sub_etat == 10)
                set_sub_etat(&ray, 47);
            else if (ray.sub_etat == 9 || ray.sub_etat == 11)
                set_sub_etat(&ray, 48);
            else if (ray.sub_etat == 3 || ray.sub_etat == 7)
                set_sub_etat(&ray, 36);
            else if (!(FUN_80133984(0) || FUN_801339f4(0)))
                set_sub_etat(&ray, 0);
        }
        RAY_SWIP();
        break;
    case 0:
        ray.speed_x = 0;
        if (ray.field23_0x3c != -1 && ray.sub_etat == 0)
        {
            if (ray.field23_0x3c == 1)
                set_sub_etat(&ray, 49);
            else
                set_sub_etat(&ray, 3);
        }
        if (ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40 && !(FUN_801339f4(0) || FUN_80133984(0)))
        {
            if (!((block_flags[(u8) calc_typ_trav(&ray, 2)] >> BLOCK_FLAG_4) & 1))
            {
                if (!(ray.main_etat == 0 && ray.sub_etat == 60))
                    set_main_and_sub_etat(&ray, 0, 60);
            }
            else if (!(ray.main_etat == 0 && (ray.sub_etat == 15 || ray.sub_etat == 61)))
            {
                sel_anim = &ray.animations[ray.anim_index];
                set_main_and_sub_etat(&ray, 0, 15);
                ray.anim_frame = sel_anim->frames_count - 1;
            }
        }
        else
        {
            if(ray.sub_etat == 37 && __builtin_abs(decalage_en_cours) <= 128)
                set_sub_etat(&ray, 38);
            else if (
                ray.sub_etat == 20 &&
                (flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10,
                    (flag_set && ray.anim_frame == 0) ||
                    (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
                ) &&
                horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xF] == 0
            )
            {
                if (((block_flags[(u8) calc_typ_trav(&ray, 2)] >> BLOCK_FLAG_4) & 1))
                {
                    sel_eta_1 = &ray.eta[ray.main_etat][ray.sub_etat];
                    unk_1 = ((sel_eta_1->flags >> 4 ^ 1) & 1) * 0x10;
                    sel_eta_1->flags = sel_eta_1->flags & 0xEF | unk_1;
                    FUN_80150c5c(&ray, 1);
                    sel_eta_2 = &ray.eta[ray.main_etat][ray.sub_etat];
                    unk_1 = ((sel_eta_2->flags >> 4 ^ 1) & 1) * 0x10;
                    sel_eta_2->flags = sel_eta_2->flags & 0xEF | unk_1;    
                }
            }
            else if (ray.sub_etat == 59 || ray.sub_etat == 62 || ray.sub_etat == 63)
            {
                flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
                if(
                    (flag_set && ray.anim_frame == 0 ||
                    !flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1) &&
                    horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xF] == 0
                )
                {
                    compteur_attente = 0;
                    set_sub_etat(&ray, 0);
                }
            }
            else if (
                (ray.sub_etat == 0 || ray.sub_etat == 1 || ray.sub_etat == 2) &&
                ++compteur_attente >= 500
            )
                set_sub_etat(&ray, 59);
        }
        RAY_SWIP();
        break;
    case 4:
        if (ray.sub_etat == 2 || ray.sub_etat == 3)
        {
            set_sub_etat(&ray, 0);
            ray.speed_y = 0;
        }
        break;
    case 2:
        compteur_attente = 0;
        D_801F5588 = 0;
        if (ray.sub_etat != 8)
            ray.speed_x = 0;
        if (ray.sub_etat != 15 && ray.nb_cmd == 0)
            ray_inertia_speed(0, 0, 0, ray_wind_force);
        else
            ray_inertia_speed(8, 0, 0, ray_wind_force);
        break;
    case 6:
        decalage_en_cours = 0;
        joy_done++;
        ray.flags |= FLG(OBJ_FLIP_X);
        if (ray.gravity_value_1 == 0)
        {
            if (ray.speed_x > 0)
                ray.speed_x--;
            else if (ray.speed_x < 0)
                ray.speed_x++;

            if (ray.speed_y > 0)
                ray.speed_y--;
            else if (ray.speed_y < 0)
                ray.speed_y++;
        }
        break;
    }

    __asm__("nop\nnop\nnop\nnop\nnop");
}
#endif

/* 61254 80185A54 -O2 -msoft-float */
void PS1_RespondShoulderR(void)
{
  switch(ray.main_etat)
  {
  case 0:
    if (ray.sub_etat == 15 || ray.sub_etat == 47)
    {
      if (ray.flags & FLG(OBJ_FLIP_X))
        set_main_and_sub_etat(&ray,1,8);
      else
      {
        ray.flags = (ray.flags & ~FLG(OBJ_FLIP_X)) | (((1 - (ray.flags >> OBJ_FLIP_X & 1)) & 1) << OBJ_FLIP_X);
        set_main_and_sub_etat(&ray, 0, 50);
      }
    }
    else if (ray.sub_etat != 50)
    {
        if (!poing.is_active)
        {
            poing.is_charging = false;
            poing.charge = 0;
        }
        set_main_and_sub_etat(&ray,3,6);
    }
    RAY_SWIP();
    break;
  case 1:
    if (ray.sub_etat == 8 || ray.sub_etat == 10)
    {
      if (!(ray.flags & FLG(OBJ_FLIP_X)))
      {
        ray.flags |= FLG(OBJ_FLIP_X);
        set_main_and_sub_etat(&ray, 0, 50);
      }
    }
    else if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40))
        set_main_and_sub_etat(&ray,3,6);
    RAY_SWIP();
    break;
  }
}

/* 613D8 80185BD8 -O2 -msoft-float */
void PS1_RespondShoulderL(void)
{
  switch(ray.main_etat)
  {
  case 0:
    if (ray.sub_etat == 15 || ray.sub_etat == 47)
    {
      if (!(ray.flags & FLG(OBJ_FLIP_X)))
        set_main_and_sub_etat(&ray,1,8);
      else
      {
        ray.flags = (ray.flags & ~FLG(OBJ_FLIP_X)) | (((1 - (ray.flags >> OBJ_FLIP_X & 1)) & 1) << OBJ_FLIP_X);
        set_main_and_sub_etat(&ray, 0, 50);
      }
    }
    else if (ray.sub_etat != 50)
    {
        if (!poing.is_active)
        {
            poing.is_charging = false;
            poing.charge = 0;
        }
        set_main_and_sub_etat(&ray,3,6);
    }
    RAY_SWIP();
    break;
  case 1:
    if (ray.sub_etat == 8 || ray.sub_etat == 10)
    {
      if (ray.flags & FLG(OBJ_FLIP_X))
      {
        ray.flags &= ~FLG(OBJ_FLIP_X);
        set_main_and_sub_etat(&ray, 0, 50);
      }
    }
    else if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40))
        set_main_and_sub_etat(&ray,3,6);
    RAY_SWIP();
    break;
  }
}

void RAY_RESPOND_TO_BUTTON4(void) {}

/* 61568 80185D68 -O2 -msoft-float */
void RAY_RESPOND_TO_BUTTON3(void)
{
    if (ray.main_etat != 2)
    {
        if (ray.main_etat != 1)
        {
            RAY_STOP();
            if (
                ray.main_etat == 0 &&
                (ray.sub_etat == 0 || ray.sub_etat == 1 || ray.sub_etat == 2 ||
                ray.sub_etat == 63 || ray.sub_etat == 59 || ray.sub_etat == 62 ||
                ray.sub_etat == 3 || ray.sub_etat == 8)
            )
            {
                if (RayEvts.flags0 & FLG(RAYEVTS0_GRAIN))
                {
                    if (ray.field20_0x36 == -1)
                    {
                        set_main_and_sub_etat(&ray, 3, 16);
                        ray.speed_x = 0;
                        ray.speed_y = 0;
                    }
                }
                else if (
                    !ray_on_poelle &&
                    ray.sub_etat != 18 &&
                    !(RayEvts.flags1 & (FLG(RAYEVTS1_RUN)|FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))) &&
                    ray.sub_etat != 8
                )
                    set_sub_etat(&ray, 18);
            }
        }
        else if (
            !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))) &&
            RayEvts.flags1 & 1 &&
            ray.sub_etat == 0
        )
            set_sub_etat(&ray, 3);
    }
}

/* 61704 80185F04 -O2 -msoft-float */
void RAY_RESPOND_TO_FIRE0(void)
{
  if (
    !poing.is_active &&
    RayEvts.flags0 & FLG(RAYEVTS0_POING) &&
    !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)))
  )
    RAY_PREPARE_FIST();
}

/* 61760 80185F60 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_FIRE1);
#else
void RAY_RESPOND_TO_FIRE1(void)
{
    if (!fin_boss)
    {
        switch (ray.main_etat)
        {
        case 0:
        case 1:
        case 2:
        case 5:
        case 7:
            ray_jump();
            break;
        case 3:
        case 4:
        case 6:
            break;
        }
    }

    __asm__("nop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_BALANCE_ANIM);

/* 61870 80186070 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", abs_sinus_cosinus);
#else
void abs_sinus_cosinus(s16 tab_index, s16 *param_2, s16 *param_3)
{
    if (tab_index <= 256)
    {
        *param_3 = costab[tab_index];
        if (tab_index < 128)
            *param_2 = costab[tab_index + 128];
        else
            *param_2 = -costab[tab_index - 128];
    }
    else
    {
        *param_3 = costab[512 - tab_index];
        if (tab_index > 384)
            *param_2 = costab[tab_index - 384];
        else
            *param_2 = -costab[tab_index - 128];
    }

    __asm__("nop\nnop");
}
#endif

/* 6191C 8018611C -O2 -msoft-float */
void SET_RAY_BALANCE(void)
{
  if (ray.main_etat == 2 && ray.sub_etat == 8)
    ray.iframes_timer = 90;
  set_main_and_sub_etat(&ray, 7, 0);
  PlaySnd(0, -1);
  ray.field24_0x3e = 0;
  ray.gravity_value_1 = 0;
  ray.gravity_value_2 = 0;
  ray.field20_0x36 = -1;
  decalage_en_cours = 0;
  button_released = 1;
  ray.speed_y = 0;
}

/* 619C0 801861C0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_GOING_BALANCE);
#else
void RAY_GOING_BALANCE(Obj *obj)
{
    s16 unk_1;
    s16 unk_2;
    s32 unk_3;
    s32 unk_4;
    s16 follow_x;
    s16 follow_y;
    s16 diff_x = (ray.x_pos + ray.offset_bx) - obj->x_pos - obj->offset_bx;
    s16 diff_y = (ray.y_pos + ray.offset_by) - obj->y_pos - obj->offset_by;
    s32 dist = diff_x * diff_x + diff_y * diff_y;

    if (ray.sub_etat == 0)
    {
        if (dist > 4512U)
        {
            set_sub_etat(&ray, 1);
            obj->timer = 0;
            ray.speed_y = 0;
            ray.speed_x = 0;
            decalage_en_cours = 0;
            follow_x = ANGLE_RAYMAN(obj);
            obj->follow_x = follow_x;
            if (follow_x > 256 || (follow_x == 256 && !(ray.flags & FLG(OBJ_FLIP_X))))
                obj->field24_0x3e = -1;
            else
                obj->field24_0x3e = 1;
            
            abs_sinus_cosinus(follow_x, &unk_1, &unk_2);
            if (__builtin_abs(unk_2) > 2)
            {
                if (__builtin_abs(unk_1) > 2)
                {
                    unk_3 = (diff_x << 9) / unk_1;
                    unk_4 = (diff_y << 9) / unk_2;
                    follow_y = (__builtin_abs(unk_3) + __builtin_abs(unk_4)) >> 1;
                }
                else
                    follow_y = __builtin_abs(diff_y);
            }
            else
                follow_y = __builtin_abs(diff_x);
            obj->follow_y = follow_y;
        }
        else
        {
            ray.speed_x = 0;
            ray.gravity_value_1++;
            ray.speed_y -= obj->speed_y;
            if (ray.gravity_value_1 > 2)
            {
                ray.speed_y++;
                ray.gravity_value_1 = 0;
            }
        }
    }

    __asm__("nop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_BALANCE);

/* 62144 80186944 -O2 -msoft-float */
void RAY_FIN_BALANCE(void)
{
  s16 should_flip = level.objects[id_obj_grapped].follow_x < 256;
  
  ray.flags = ray.flags & ~FLG(OBJ_FLIP_X) | (should_flip << OBJ_FLIP_X);
  set_main_and_sub_etat(&ray, 2, 2);
  ray.speed_y = 0;
  ray.gravity_value_1 = 0;
  ray.gravity_value_2 = 0;
  helico_time = -1;
  ray.field24_0x3e = -1;
  ray.x_pos -= ray.speed_x;
}

/* TODO: unknown locals... */
/* 621FC 801869FC -O2 -msoft-float */
void RayTestBlocSH(void)
{
    s16 x_1;
    s16 y_1;
    s16 temp_v1_2;
    s16 var_a1;
    s32 var_v0;
    s32 temp_v1;
    s32 var_a0;
    u32 var_v0_2;

    x_1 = ray.x_pos + ray.offset_bx;
    var_a1 = x_1;
    y_1 = ray.y_pos + ray.offset_hy;
    var_v0 = x_1;
    if (x_1 < 0)
        var_v0 = x_1 + 15;
    temp_v1 = x_1 - (var_v0 >> 4 << 4);
    if (
        decalage_en_cours > 0 ||
        (decalage_en_cours == 0 && (ray.flags & FLG(OBJ_FLIP_X)))
    )
    {
        var_a0 = 16;
        if ((u8) temp_v1 >= 14)
            var_a1 = x_1 + 16;
    }
    else
    {
        var_a0 = -16;
        if ((u8) temp_v1 < 4)
            var_a1 -= 16;
    }
    temp_v1_2 = var_a1 + var_a0;
    if (
        decalage_en_cours != 0 &&
        ((s16) MURDUR(temp_v1_2, y_1 + 16) ||
        (s16) MURDUR(temp_v1_2, y_1 + 32) ||
        (s16) MURDUR(temp_v1_2, y_1 + 48))
    )
    {
        ray.speed_x = 0;
        decalage_en_cours = 0;
    }
    if (ray.speed_y < 0 && (s16) MURDUR(x_1, y_1 + 16))
        ray.speed_y = 0;
}

/* 62384 80186B84 -O2 -msoft-float */
void remoteControlRay(void)
{
    s16 diff = ray.x_pos - remoteRayXToReach;

    if (diff > 1)
    {
        ray.flags &= ~FLG(OBJ_FLIP_X);
        set_sub_etat(&ray, 21);
    }
    else if (diff < -1)
    {
        ray.flags |= FLG(OBJ_FLIP_X);
        set_sub_etat(&ray, 21);
    }
    else
    {
        ray.speed_x = 0;
        set_sub_etat(&ray, 20);
        remoteRayXToReach = ray.x_pos;
    }
}

/* 62440 80186C40 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", STOPPE_RAY_CONTRE_PAROIS);
#else
void STOPPE_RAY_CONTRE_PAROIS(u8 block)
{
  if (
    ray_mode != MODE_MORT_DE_RAYMAN && (block_flags[block] >> BLOCK_FLAG_4 & 1) &&
    ray.sub_etat != 7 && ray.sub_etat != 9 && ray.speed_y < 1
  )
  {
    if (ray.sub_etat != 8)
    {
      set_sub_etat(&ray, 1);
      button_released = 0;
    }
    ray.field24_0x3e = 0;
    ray.speed_y = 0;
  }

  __asm__("nop");
}
#endif

/* 624EC 80186CEC -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_IN_THE_AIR);
#else
void RAY_IN_THE_AIR(void)
{
    u8 may_land_obj;
    u8 anim_speed;
    u8 block;
    ObjState **ray_eta;
    s16 snd;
    u8 i;
    s32 new_decalage;
    s32 new_timer;

    ray_eta = ray.eta;
    if (ray_wind_force != 0)
        ray.nb_cmd = 1;
    memmove(&pos_stack[1], &pos_stack[0], sizeof(pos_stack) - sizeof(s16));
    *pos_stack = ray.x_pos;
    if (ray.sub_etat == 7)
        ray.field20_0x36 = -1;
    may_land_obj = true;
    if (helico_time != -1)
        helico_time--;
    if (ray_between_clic != -1)
        ray_between_clic--;
    jump_time++;
    anim_speed = ray.eta[ray.main_etat][ray.sub_etat].anim_speed >> 4;
    if (anim_speed != 10 && anim_speed != 11)
    {
        ray.gravity_value_1++;
        if (ray.gravity_value_1 >= 3)
            ray.gravity_value_1 = 0;
        ray.gravity_value_2++;
        if (ray.gravity_value_2 >= 4)
            ray.gravity_value_2 = 0;
    }
    if (jump_time == 23)
        ray.speed_y++;
    if (
        !options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e) ||
        jump_time >= 13 || in_air_because_hit || ray.timer != 0 || ray.sub_etat == 2
    )
    {
        DO_PESANTEUR(&ray);
        if (((button_released & 1) == 0) && !options_jeu.Fire1ButtonFunc(options_jeu.field11_0x1e))
            button_released++;
    }
    if (jump_time == 6)
    {
        if (ray.sub_etat == 24 || ray.sub_etat == 33)
            set_sub_etat(&ray, 2);
        else if (ray.sub_etat == 32)
            set_sub_etat(&ray, 17);
    }
    if (ray.field24_0x3e != -1)
        ray.field24_0x3e += ray.speed_y;
    block = calc_typ_trav(&ray, 2);
    if (ray.sub_etat != 8 && ray.sub_etat != 31)
    {
        RAY_HELICO();
        if (ray.sub_etat == 15)
            RayTestBlocSH();
    }
    STOPPE_RAY_CONTRE_PAROIS(block);
    if (ray.speed_y < -3 && ray.sub_etat == 15 && (s16) anim_speed == 11)
    {
        /* ??? */
        ray_eta[ray.main_etat][ray.sub_etat].anim_speed = (ray_eta[ray.main_etat][ray.sub_etat].anim_speed & 0xF) | 0x10;
        ray.gravity_value_1 = 0;
        ray.gravity_value_2 = 0;
    }
    if ((s16) ray.speed_y >= 0)
    {
        if (ray.sub_etat == 0)
        {
            set_sub_etat(&ray, 1);
            ray.field24_0x3e = 0;
        }
        else if (ray.sub_etat == 17 || ray.sub_etat == 18)
        {
            set_sub_etat(&ray, 19);
            ray.field24_0x3e = 0;
        }
    }
    
    if (
        (ray.sub_etat != 17 && ray.sub_etat != 0 && ray.sub_etat != 9 && ray.sub_etat != 31) &&
        (ray.sub_etat != 13 || ray.speed_y > -1) && jump_time > 2 
    )
    {
        if (ray_mode != MODE_MORT_DE_RAYMAN)
        {
            if (block_flags[ray.btypes[0]] >> BLOCK_SOLID & 1)
            {
                recale_position(&ray);
                ray.y_pos += ray.speed_y;
                ray.speed_y = 0;
                ray.timer = 0;
                in_air_because_hit = 0;
                
                if (!((u8) TEST_IS_ON_RESSORT_BLOC(&ray)))
                {
                    
                    if (num_world == 6 && num_level == 1)
                        snd = 242;
                    else
                        snd = 19;
                    PlaySnd(snd, -1);
                }

                if (ray.nb_cmd == 0)
                {
                    for (i = 1; i < 10; i++)
                        if (pos_stack[i - 1] != pos_stack[i]) break;
                    if (i != 10)
                    {
                        if (pos_stack[i - 1] < pos_stack[i])
                        {
                            new_decalage = decalage_en_cours;
                            if (new_decalage > -256)
                                new_decalage = -256;
                        }
                        else
                        {
                            new_decalage = decalage_en_cours;
                            if (new_decalage < 256)
                                new_decalage = 256;
                        }
                        decalage_en_cours = new_decalage;
                    }
                    else
                        decalage_en_cours = 0;

                }
                helico_time = -1;
                if (ray.sub_etat == 3)
                {
                    if (ray.anim_frame == 0)
                        button_released = 1;
                }
                else if (ray.sub_etat == 8)
                {
                    new_timer = ray.iframes_timer;
                    if (new_timer > 90)
                        new_timer = 90;
                    ray.iframes_timer = new_timer;
                }
                if (ray.sub_etat == 17 || ray.sub_etat == 18 || ray.sub_etat == 19)
                {
                    if (
                        RayEvts.flags1 & FLG(RAYEVTS1_RUN) &&
                        __builtin_abs(ray.speed_x) >= (s16) ashr16(ray.eta[1][3].speed_x_right, 4)
                    )
                        set_main_and_sub_etat(&ray, 1, 7);
                    else
                        set_main_and_sub_etat(&ray, 0, 43);
                }
                else if (ray.sub_etat == 25 || ray.sub_etat == 26)
                    set_main_and_sub_etat(&ray, 0, 52);
                else if (ray.sub_etat == 27 || ray.sub_etat == 28)
                    set_main_and_sub_etat(&ray, 0, 53);
                else
                    set_main_and_sub_etat(&ray, 0, 8);
                if (ray.field24_0x3e >= 200)
                    allocateRayLandingSmoke();
                ray.field24_0x3e = -1;
            }
            else
            {
                if (ray.sub_etat != 7)
                {
                    if (ray.sub_etat == 8)
                    {
                        if (ray.speed_y > -1)
                            rayMayLandOnAnObject(&may_land_obj, -1);
                        if (ray.main_etat != 2 || ray.sub_etat != 8)
                            ray.iframes_timer = 90;
                    }
                    else
                        rayMayLandOnAnObject(&may_land_obj, -1);
                }
            }
        }
    }
    if (ray_mode != MODE_MORT_DE_RAYMAN && ray.main_etat == 2 && ray.sub_etat != 31)
    {
        IS_RAY_ON_LIANE();
        CAN_RAY_HANG_BLOC();
    }

    if (may_land_obj == true)
    {
        if (ray.speed_y > 4)
            ray.speed_y = 4;
        if (ray.speed_y < -10)
            ray.speed_y = -10;
    }
    if (
        num_world == 2 && num_level == 15 &&
        (xmapmax < ray.x_pos + 150) && (mp.height * 16 - 100 < ray.y_pos) &&
        ray.hit_points != 0xff
    )
        ChangeLevel();

    __asm__("nop");
}
#endif

/* 62E90 80187690 -O2 -msoft-float */
void terminateFistWhenRayDies(void)
{
  Obj *obj;
  
  if (poing.is_active)
  {
    obj = &level.objects[poing_obj_id];
    DO_NOVA(obj);
    switch_off_fist(obj);
  }
}

/* 62EE8 801876E8 -O2 -msoft-float */
void snifRayIsDead(Obj *ray_obj)
{
    status_bar.num_lives--;
    RayEvts.flags0 &=
        (FLG(RAYEVTS0_POING)|FLG(RAYEVTS0_HANG)|FLG(RAYEVTS0_HELICO)|FLG(RAYEVTS0_HANDSTAND_DASH)|
        FLG(RAYEVTS0_HANDSTAND)|FLG(RAYEVTS0_GRAIN)|FLG(RAYEVTS0_GRAP));
    status_bar.num_wiz = 0;
    if (
        !ray_se_noie &&
        !(ray.main_etat == 3 && ray.sub_etat == 32) &&
        !(RayEvts.flags1 & FLG(RAYEVTS1_UNUSED_DEATH))
    )
    {
        lidol_to_allocate = 5;
        lidol_source_obj = ray_obj;
        gerbe = true;
    }
    terminateFistWhenRayDies();
}

/* 62FA4 801877A4 -O2 -msoft-float */
void rayfallsinwater(void)
{
  set_main_and_sub_etat(&ray, 3, 22);
  ray.anim_frame = 0;
  ray.speed_y = 0;
  ray.speed_x = 0;
  decalage_en_cours = 0;
  if (ray_on_poelle)
    ray.x_pos -= h_scroll_speed;
  h_scroll_speed = 0;
  dead_time = 1;
  ray.iframes_timer = 120;
  ray_se_noie = true;
  allocate_splash(&ray);
  terminateFistWhenRayDies();
}

/* 6305C 8018785C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_DEAD);
#else
u8 RAY_DEAD(void)
{
    u8 flag_set;
    u8 unk_1; /* true if he is alive? */

    if (
        ray.x_pos < xmap - ray.offset_bx + 10 ||
        ((ray.screen_y_pos + ray.offset_by < -20) && scroll_y == -1) ||
        ray.x_pos > -ray.offset_bx + xmap + 310
    )
    {
        ray.hit_points = 0;
        RAY_HIT(1, 0);
    }
    else if (ray.screen_y_pos > 220)
    {
        ray.hit_points = 0;
        RAY_HURT();
    }
    else
    {
        if (
            !(ray.main_etat == 2 && ray.sub_etat == 9) &&
            !(ray.main_etat == 3 && ray.sub_etat == 22) &&
            ray.flags & FLG(OBJ_ALIVE)
        )
        {
            if (ray.btypes[0] == BTYP_WATER && ray.field20_0x36 == -1 && ray.main_etat != 6)
                rayfallsinwater();
            else if (ray.y_pos + ray.offset_by > (mp.height + 1) * 16)
            {
                set_main_and_sub_etat(&ray, 2, 9);
                if (ray.speed_y < 0)
                    ray.speed_y = 0;
            }
        }
        if (
            (ray.main_etat == 2 && ray.sub_etat == 9) ||
            (
                !(ray.main_etat == 2 && ray.sub_etat == 9) &&
                (ray.main_etat == 3 && (ray.sub_etat == 22 || ray.sub_etat == 32 || ray.sub_etat == 38)) &&
                (flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10,
                    (flag_set && ray.anim_frame == 0) ||
                    (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
                ) &&
                horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0
            )
        )
        {
            if (--dead_time == 0 && !fin_du_jeu)
            {
                ray.hit_points = 2;
                if (ray.flags & FLG(OBJ_ACTIVE))
                {
                    ray.flags &= ~FLG(OBJ_ACTIVE);
                    ray.flags &= ~FLG(OBJ_ALIVE);
                    dead_time = 64;
                    snifRayIsDead(&ray);
                    if (status_bar.num_lives < 0)
                    {
                        fin_du_jeu = true;
                        status_bar.num_lives = 0;
                        ray.hit_points = 0;
                    }
                }
                ray.iframes_timer = 90;
                status_bar.max_hp = ray.hit_points;
            }
            else
                ray.field20_0x36 = -1;
        }
    }
    unk_1 = false;
    if ((ray.flags & (FLG(OBJ_ACTIVE)|FLG(OBJ_ALIVE))) == (FLG(OBJ_ACTIVE)|FLG(OBJ_ALIVE)))
        unk_1 = !(ray_mode == MODE_MORT_DE_RAYMAN || ray_mode == MODE_MORT_DE_RAYMAN_ON_MS);

    __asm__("nop");
    return unk_1;
}
#endif

/* 6346C 80187C6C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_HURT);
#else
void RAY_HURT(void)
{
  u8 flag_set;
  s16 new_iframes;

  __asm__("nop");

  test_fin_cling();
  ray.hit_points--;
  if (ray.iframes_timer == -1)
  {
    flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40;
    if (
        (flag_set && !(block_flags[(u8) calc_typ_trav(&ray, 2)] >> BLOCK_FLAG_4 & 1)) ||
        !flag_set
    )
      new_iframes = 120;
    else
      new_iframes = 60;
    ray.iframes_timer = new_iframes;
  }

  if (ray.hit_points == 0xFF)
  {
    if (ray_mode == MODE_RAY_ON_MS)
      ray_mode = MODE_MORT_DE_RAYMAN_ON_MS;
    else
      ray_mode = MODE_MORT_DE_RAYMAN;
    jump_time = 0;
  }
}
#endif

/* 6356C 80187D6C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RepousseRay);
#else
void RepousseRay(void)
{
    Obj *pa_obj = &level.objects[pierreAcorde_obj_id];

    if (pa_obj->flags & FLG(OBJ_ACTIVE))
    {
        if ((ray.x_pos > pa_obj->x_pos - 82) && (ray.x_pos < pa_obj->x_pos + 150))
        {
            if (ray.y_pos < pa_obj->y_pos + 96)
            {
                ray.y_pos = pa_obj->y_pos + 96;
                if (ray.main_etat != 2)
                {
                    set_main_and_sub_etat(&ray, 2, 1);
                    ray.speed_y = instantSpeed(pa_obj->speed_y);
                    jump_time = 0;
                    helico_time = -1;
                    ray.gravity_value_1 = 0;
                    ray.gravity_value_2 = 0;
                    button_released = 0;
                }
                else
                    ray.speed_y = pa_obj->speed_y;
            }
        }
        if (ymap + 208 < pa_obj->y_pos)
            pa_obj->flags &= ~FLG(OBJ_ALIVE);
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RayEstIlBloque);

/* 63A6C 8018826C -O2 -msoft-float */
void stackRay(void)
{
    RayStack *cur;
    u8 active;
    Obj *poing_obj;

    cur = &rayStack[ray_pos_in_stack];
    cur->x_pos = ray.x_pos;
    cur->y_pos = ray.y_pos;
    cur->main_etat = ray.main_etat;
    cur->sub_etat = ray.sub_etat;
    cur->anim_index = ray.anim_index;
    cur->anim_frame = ray.anim_frame;
    cur->flip_x = (ray.flags >> OBJ_FLIP_X) & 1;
    cur->scale = ray.scale;
    active = poing.is_active;
    cur->poing_is_active = active;
    if (active)
    {
        poing_obj = &level.objects[poing_obj_id];
        cur->poing_x_pos = poing_obj->x_pos;
        cur->poing_y_pos = poing_obj->y_pos;
        cur->poing_anim_index = poing_obj->anim_index;
        cur->poing_anim_frame = poing_obj->anim_frame;
        cur->poing_flip_x = poing_obj->flags >> OBJ_FLIP_X & 1;
    }
    ray_pos_in_stack++;
    if (ray_pos_in_stack > 100)
    {
        ray_pos_in_stack = 0;
        ray_stack_is_full = true;
    }
}

/* 63BD0 801883D0 -O2 -msoft-float */
void RAY_SURF(void)
{
    if (
        (
            ray.field20_0x36 == -1 ||
            (u8) (level.objects[ray.field20_0x36].type + 0x61) >= 2U /* TODO: how to split this into each case? */
        ) &&
        ray.main_etat == 0 && !(ray.sub_etat == 13 || ray.sub_etat == 11 || ray.sub_etat == 12)
    )
    {
        if (__builtin_abs(ray.speed_x) > 3 && ray.sub_etat != 40)
        {
            if (
                !(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40) &&
                !(ray.sub_etat == 8 || ray.sub_etat == 52 || ray.sub_etat == 53)
            )
                set_main_and_sub_etat(&ray, 0, 41);
        }
        else if (__builtin_abs(ray.speed_x) < 3 && ray.sub_etat == 40)
        {
            if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40))
                set_main_and_sub_etat(&ray, 0, 42);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", DO_SURF_CHANGE_HAIRS);

void RAY_PREPARE_PIEDS(void) {}

void DO_PIEDS_RAYMAN(void) {}

void DO_PIEDS_COLLISION(void) {}

void allocatePiedBoum(void) {}

/* 63E30 80188630 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", DO_MORT_DE_RAY);
#else
void DO_MORT_DE_RAY(void)
{
    u8 flag_set;

    __asm__("nop");

    ray.iframes_timer = -1;
    v_scroll_speed = 0;
    h_scroll_speed = 0;
    calc_obj_pos(&ray);
    calc_btyp(&ray);
    RAY_IN_THE_AIR();
    RAY_SWIP();
    STOPPE_RAY_EN_XY();
    if (ray.speed_y > 0)
        move_down_ray();
    else if (ray.speed_y < 0)
        move_up_ray();
    if (ray.speed_x < 0)
        RAY_TO_THE_LEFT();
    else if (ray.speed_x > 0)
        RAY_TO_THE_RIGHT();
    
    fin_poing_follow(&level.objects[poing_obj_id], 0);
    if (ray_on_poelle == true)
    {
        PS1_RestoreSauveRayEvts();
        ray_on_poelle = false;
    }
    flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
    if (
        (
            (
                (flag_set && ray.anim_frame == 0) ||
                (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
            ) &&
            horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0
        ) ||
        !(ray.main_etat == 2 && ray.sub_etat == 8)
    )
    {
        snifRayIsDead(&ray);
        dead_time = 128;
        gerbe = true;
        ray.flags &= ~FLG(OBJ_ALIVE);
        if (status_bar.num_lives >= 0)
        {
            ray.hit_points = 2;
            status_bar.max_hp = 2;
        }
        else
        {
            ray.hit_points = 0;
            status_bar.num_lives = 0;
            fin_du_jeu = true;
        }
    }
    DO_ANIM(&ray);
    stackRay();
}
#endif