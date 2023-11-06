#include "moteur_update.h"

/* 35314 80159B14 -O2 -msoft-float */
void PS1_SetWindForce(void)
{
    if (num_world == 3)
        ray_wind_force = 0;
    else
        ray_wind_force = weather_wind;
}

/* 35354 80159B54 -O2 -msoft-float */
void DO_MOTEUR(void)
{
  fades();
  horloges();
  calc_left_time();
  ray_old_main_etat = ray.main_etat;
  ray_old_sub_etat = ray.sub_etat;
  D_801F7C90 = ray.x_pos;
  D_801F7CA0 = ray.y_pos;
  PS1_MoteurTime++;
  xmap_old = xmap;
  ymap_old = ymap;
  if (ray.field20_0x36 != -1)
    level.objects[ray.field20_0x36].display_prio = oldPrio;
  if (RayEvts.flags1 & FLG(RAYEVTS1_LUCIOLE))
    DO_LUCIOLE();
  PS1_SetWindForce();
  DO_OBJECTS();
}

INCLUDE_ASM("asm/nonmatchings/moteur_update", DO_MOTEUR2);

/* 35A58 8015A258 -O2 -msoft-float */
void RAY_REVERSE_COMMANDS(void)
{
  if (!(RayEvts.flags1 & (FLG(RAYEVTS1_REVERSE)|FLG(RAYEVTS1_FLAG6))))
  {
    RayEvts.flags1 &=
        (FLG(RAYEVTS1_RUN)|FLG(RAYEVTS1_DEMI)|FLG(RAYEVTS1_LUCIOLE)|
        FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)|FLG(RAYEVTS1_UNUSED_DEATH));
    RayEvts.flags1 |= FLG(RAYEVTS1_REVERSE);
    if (star_ray_der != null)
    {
      star_ray_der->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
      star_ray_der->display_prio = 3;
    }
    if (star_ray_dev != null)
    {
      star_ray_dev->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
      star_ray_dev->display_prio = 1;
    }
  }
  else
  {
    RayEvts.flags1 &=
        (FLG(RAYEVTS1_RUN)|FLG(RAYEVTS1_DEMI)|FLG(RAYEVTS1_LUCIOLE)|
        FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)|FLG(RAYEVTS1_UNUSED_DEATH));
    if (star_ray_der != null)
    {
      star_ray_der->flags &= ~FLG(OBJ_ALIVE);
      star_ray_der->flags &= ~FLG(OBJ_ACTIVE);
      star_ray_der->display_prio = 3;
    }
    if (star_ray_dev != null)
    {
      star_ray_dev->flags &= ~FLG(OBJ_ALIVE);
      star_ray_dev->flags &= ~FLG(OBJ_ACTIVE);
      star_ray_dev->display_prio = 3;

    }
  }
}

/* 35B30 8015A330 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/moteur_update", RAY_DEMIRAY);
#else
void RAY_DEMIRAY(void)
{
  ObjFlags demi;
  
  __asm__("nop");

  demi = ((RayEvts.flags1 >> RAYEVTS1_DEMI ^ 1) & 1) << RAYEVTS1_DEMI;
  RayEvts.flags1 =
    RayEvts.flags1 & (FLG(RAYEVTS1_RUN)|FLG(RAYEVTS1_LUCIOLE)|FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)|
                      FLG(RAYEVTS1_REVERSE)|FLG(RAYEVTS1_FLAG6)|FLG(RAYEVTS1_UNUSED_DEATH)) | demi;
  if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
  {
    __builtin_memcpy(&rms, &ray, sizeof(ray));
    __builtin_memcpy(&ray, &level.objects[reduced_rayman_id], sizeof(Obj));
    ray.animations = rms.animations;
    PlaySnd(206, -1);
  }
  else
  {
    __builtin_memcpy(&raytmp, &rms, sizeof(rms));
    __builtin_memcpy(&rms, &ray, sizeof(ray));
    __builtin_memcpy(&ray, &raytmp, sizeof(raytmp));
    PlaySnd(207,-1);
  }
  ray.type = TYPE_RAYMAN;
  ray.screen_x_pos = rms.screen_x_pos;
  ray.screen_y_pos = rms.screen_y_pos;
  ray.speed_x = rms.speed_x;
  ray.speed_y = rms.speed_y;
  ray.x_pos = rms.x_pos;
  ray.y_pos = rms.y_pos;
  ray.offset_bx = rms.offset_bx;
  ray.offset_by = rms.offset_by;
  ray.offset_hy = rms.offset_hy;
  ray.anim_index = rms.anim_index;
  ray.anim_frame = rms.anim_frame;
  ray.flags = ray.flags & ~FLG(OBJ_FLIP_X) | rms.flags & FLG(OBJ_FLIP_X);
  ray.field23_0x3c = rms.field23_0x3c;
  ray.main_etat = rms.main_etat;
  ray.sub_etat = rms.sub_etat;
  ray.field20_0x36 = rms.field20_0x36;
  ray.flags = ray.flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
  ray.field24_0x3e = rms.field24_0x3e;
  ray.iframes_timer = rms.iframes_timer;
  ray.field56_0x69 = rms.field56_0x69;
  ray.timer = rms.timer;
  ray.hit_points = rms.hit_points;
  ray.init_hit_points = rms.init_hit_points;
  ray.hit_sprite = rms.hit_sprite;

  if (block_flags[(u8) calc_typ_trav(&ray, 2)] >> BLOCK_FLAG_4 & 1)
    set_main_and_sub_etat(&ray, 0, 15);
}
#endif

/* 35EF0 8015A6F0 -O2 -msoft-float */
void DO_MOTEUR_GELE(void)
{
  if (gele != 3)
  {
    if (gele == 2)
    {
      horloges();
      TEST_SIGNPOST();
      h_scroll_speed = 0;
      v_scroll_speed = 0;
      DO_ANIM(&ray);
    }
    else
      DO_MEDAILLON_TOON_GELE();
  }
}

/* 35F64 8015A764 -O2 -msoft-float */
void FUN_8015a764(void)
{
    if (gele != 3)
    {
        D_801F57F0 = gele;
        gele = 3;
    }
    else
        gele = D_801F57F0;
}
