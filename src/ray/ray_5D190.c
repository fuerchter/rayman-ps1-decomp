#include "ray/ray_5D190.h"

extern BlockType hand_btyp;
extern BlockType hand_btypd;
extern BlockType hand_btypg;
extern s16 jump_time;
extern s16 helico_time;
extern s16 D_801E51E8;
extern s16 D_801E51F8;
extern u8 ray_Suphelico_bis;
extern u8 ray_clic;
extern s16 D_801E62F0;
extern s16 ray_between_clic;

void DO_ANIM(Obj *obj);
void FUN_80150c5c(Obj *param_1,u8 param_2);

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
    case 0:
        if (__builtin_abs(decalage_en_cours) <= 256)
            ray.nb_cmd = 0;
        else
            ray.nb_cmd = 1;
        break;
    case 1:
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
        if (ray.sub_etat - 11 >= 2U) /* don't understand these fully yet */
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
        if (ray.sub_etat - 11 >= 2U)
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

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_DIR);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_RESPOND_TO_NOTHING);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", PS1_RespondShoulderR);

INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", PS1_RespondShoulderL);

void RAY_RESPOND_TO_BUTTON4(void) {}

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
