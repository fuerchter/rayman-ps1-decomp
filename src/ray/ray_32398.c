#include "ray/ray_32398.h"

extern s16 compteur_attente;
extern u8 fin_dark;
extern u8 gele;
extern u8 in_air_because_hit;
extern u8 no_ray_landing_smoke;
extern s16 pos_stack[10];
extern u8 ray_in_fee_zone;
extern u8 ray_last_ground_btyp;
extern s16 ray_mode;
extern u8 ray_pos_in_stack;
extern u8 ray_se_noie;
extern u8 ray_stack_is_full;
extern Obj rms;
extern SaveState save1;

/* 32398 80156B98 -O2 -msoft-float */
void INIT_RAY_BEGIN(void)
{
  status_bar.max_hp = 2;
  status_bar.num_wiz = 0;
  RayEvts.flags0 &= ~(FLG(RAYEVTS0_POING)|FLG(RAYEVTS0_HANG)|FLG(RAYEVTS0_HELICO));
  RayEvts.flags1 &= ~FLG(RAYEVTS1_RUN);
  RayEvts.flags0 &= ~(FLG(RAYEVTS0_POING)|FLG(RAYEVTS0_HANG)|FLG(RAYEVTS0_HELICO)|FLG(RAYEVTS0_HANDSTAND_DASH)|FLG(RAYEVTS0_HANDSTAND));
  RayEvts.flags1 &= (FLG(RAYEVTS1_DEMI)|FLG(RAYEVTS1_UNUSED_DEATH));
  RayEvts.flags0 &= (FLG(RAYEVTS0_SUPER_HELICO)|FLG(RAYEVTS0_GRAIN));
  ray.flags = ray.flags & ~FLG(OBJ_FLAG_0);
}

/* 3240C 80156C0C -O2 -msoft-float */
/*void RAY_REVERSE_COMMANDS(void);
u32 calc_btyp(Obj *obj);*/

void INIT_RAY(u8 new_level)
{
  s16 j;
  Animation *pAVar2;
  u8 *puVar3;
  ObjState **ppOVar4;
  s16 i;
  Obj *cur_obj;
  Obj *pOVar6;
  Obj *pOVar7;
  s16 nb_objs;
  ObjFlags flag_9;
  RayEvts_1 temp_a1;
  
  gele = 0;
  if (ray.main_etat == 6)
    ray_mode = MODE_RAY_ON_MS;
  else
    ray_mode = MODE_RAYMAN;
  compteur_attente = 0;
  if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
  {
    rms.hit_points = ray.hit_points;
    __builtin_memcpy(&ray, &rms, sizeof(rms));
  }
  xmap = 0;
  ymap = 0;
  ray.type = TYPE_RAYMAN;
  ray.screen_x_pos = 0;
  ray.screen_y_pos = 0;
  ray.speed_x = 0;
  ray.speed_y = 0;
  ray.x_pos = 100;
  ray.y_pos = 10;
  ray.offset_bx = 80;
  ray.offset_by = 78;
  ray.offset_hy = 20;
  ray.anim_index = 0;
  ray.anim_frame = 0;
  ray.main_etat = 2;
  ray.sub_etat = 2;
  ray.field20_0x36 = -1;
  ray.field24_0x3e = -1;
  ray.iframes_timer = -1;
  ray.field56_0x69 = 0;
  ray.timer = 0;
  flag_9 = ~FLG(OBJ_FLAG_9);
  ray.flags |= FLG(OBJ_FLIP_X);
  ray_last_ground_btyp = 1;
  remoteRayXToReach = 33536;
  ray_stack_is_full = 0;
  ray_pos_in_stack = 0;
  ray_se_noie = false;
  ray_in_fee_zone = false;
  no_ray_landing_smoke = false;
  ray.flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
  decalage_en_cours = 0;
  ray.flags = ray.flags & flag_9;
  fin_dark = false;
  in_air_because_hit = false;

  i = 0;
  while (i < 10)
  {
    pos_stack[i] = ray.x_pos;
    i++;
  }
  poing.is_active = false;
  poing.is_charging = false;
  if (new_level)
    RayEvts.flags0 &=
      FLG(RAYEVTS0_POING)|FLG(RAYEVTS0_HANG)|FLG(RAYEVTS0_HELICO)|FLG(RAYEVTS0_HANDSTAND_DASH)|
      FLG(RAYEVTS0_HANDSTAND)|FLG(RAYEVTS0_GRAIN)|FLG(RAYEVTS0_GRAP);
  if ((num_level != 9 || num_world != 1) && ModeDemo == 0)
    RayEvts.flags0 &=
      FLG(RAYEVTS0_POING)|FLG(RAYEVTS0_HANG)|FLG(RAYEVTS0_HELICO)|FLG(RAYEVTS0_SUPER_HELICO)|
      FLG(RAYEVTS0_HANDSTAND_DASH)|FLG(RAYEVTS0_HANDSTAND)|FLG(RAYEVTS0_GRAP);
  RayEvts.flags1 &=
    FLG(RAYEVTS1_RUN)|FLG(RAYEVTS1_LUCIOLE)|FLG(RAYEVTS1_REVERSE)|
    FLG(RAYEVTS1_FLAG6)|FLG(RAYEVTS1_UNUSED_DEATH);
  if (save1.rayevts_0 != 0 && save1.save_obj_id != -1)
  {
    RayEvts.flags1 &= FLG(RAYEVTS1_RUN)|FLG(RAYEVTS1_LUCIOLE)|FLG(RAYEVTS1_UNUSED_DEATH);
    if ((num_world == 6) && (num_level == 3))
      RAY_REVERSE_COMMANDS();
  }
  else
  {
    RayEvts.flags1 = RayEvts.flags1 & ~(FLG(RAYEVTS1_REVERSE)|FLG(RAYEVTS1_FLAG6)) | FLG(RAYEVTS1_REVERSE);
    RAY_REVERSE_COMMANDS();
  }
  
  cur_obj = level.objects;
  j = 0;
  nb_objs = level.nb_objects;
  if (nb_objs != 0)
  {
    do {
      if (cur_obj->type == TYPE_RAY_POS)
      {
        xmap = cur_obj->offset_bx + cur_obj->x_pos - 160;
        ymap = cur_obj->y_pos - 10;
        if (xmapmax <= xmap)
          xmap = xmapmax;
        if (ymapmax <= ymap)
          ymap = ymapmax;
        if (xmap < 0)
          xmap = 0;
        if (ymap < 0)
          ymap = 0;
        ray.x_pos = cur_obj->x_pos;
        ray.y_pos = cur_obj->y_pos;
        break;
      }
      cur_obj++;
      j++;
    } while (j < nb_objs);
  }
  calc_btyp(&ray);
}

/* 32898 80157098 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", is_icy_pente);
#else
s16 is_icy_pente(u8 block)
{
  u8 res;

  __asm__("nop");

  res = 0;
  if (block_flags[block] >> BLOCK_SLOPE & 1)
    res = block_flags[block] >> BLOCK_SLIPPERY & 1;
  return res;
}
#endif

/* 328D0 801570D0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", STOPPE_RAY_EN_XY);
#else
void STOPPE_RAY_EN_XY(void)
{
  s16 x;
  s16 y;
  u8 btyp_1;
  u8 btyp_2;
  u8 btyp_3;
  u8 btyp_4;
  s16 stop;

  x = ray.offset_bx + ray.x_pos;
  y = ray.offset_by + ray.y_pos;
  if (block_flags[ray.btypes[0]] >> BLOCK_SLOPE & 1)
    y -= 8;
  
  x += ray.speed_x * 2;
  btyp_1 = PS1_BTYPAbsPos(x, y - 8);
  btyp_2 = PS1_BTYPAbsPos(x, y - 24);
  btyp_3 = PS1_BTYPAbsPos(x, y - 40);
  btyp_4 = PS1_BTYPAbsPos(x, y - 56);

  stop = false;
  if (block_flags[btyp_1] >> BLOCK_FLAG_4 & 1)
    stop = !is_icy_pente(btyp_2);
  if (
    !(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40) &&
    !(RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
  )
  {
    if (
      (!stop) &&
      (
        ((block_flags[btyp_2] >> BLOCK_FLAG_4 & 1) && !is_icy_pente(btyp_3)) ||
        ((block_flags[btyp_3] >> BLOCK_FLAG_4 & 1) && !is_icy_pente(btyp_4))
      )
    )
      stop = true;
  }

  if (stop)
  {
    ray.speed_x = 0;
    decalage_en_cours = 0;
    ray.nb_cmd = 0;
    Reset_air_speed(true);
    Reset_air_speed(false);
  }

  __asm__("nop\nnop\nnop\nnop");
}
#endif

/* 32AF8 801572F8 -O2 -msoft-float */
/* control flow not great? */
void RAY_RESPOND_TO_ALL_DIRS(void)
{
    if (ray_on_poelle == true)
    {
        if (decalage_en_cours == 0 && ray.speed_y == 0)
        {
          if (!rightjoy(0) || ray.flags & FLG(OBJ_FLIP_X))
          {
            if (leftjoy(0) && ray.flags & FLG(OBJ_FLIP_X))
              RAY_RESPOND_TO_DIR(0);
          }
          else
            RAY_RESPOND_TO_DIR(1);
        }
        else if (decalage_en_cours > 0 && !(ray.flags & FLG(OBJ_FLIP_X)))
          RAY_RESPOND_TO_DIR(1);
        else if (decalage_en_cours < 0 && ray.flags & FLG(OBJ_FLIP_X))
          RAY_RESPOND_TO_DIR(0);
        
        if (joy_done == 0)
        {
          RAY_RESPOND_TO_NOTHING();
          return;
        }
        else
        {
          compteur_attente = 0;
          return;
        }
    }

    if (!(RayEvts.flags1 & (FLG(RAYEVTS1_REVERSE)|FLG(RAYEVTS1_FLAG6))))
    {
        if (rightjoy(0) || RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)))
          RAY_RESPOND_TO_DIR(1);
        if (leftjoy(0) && !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))))
          RAY_RESPOND_TO_DIR(0);
        if (downjoy(0) && joy_done == 0 && !(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))))
        {
          RAY_RESPOND_TO_DOWN();
          joy_done++;
        }
        if (upjoy(0))
        {
          if (joy_done == 0)
          {
            if (!(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))))
            {
              RAY_RESPOND_TO_UP();
              joy_done++;
            }
          }
          else
          {
            compteur_attente = 0;
            return;
          }
        }
        if (joy_done != 0)
        {
          compteur_attente = 0;
          return;
        }
        if (!(RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))))
        {
          RAY_RESPOND_TO_NOTHING();
          return;
        }
        else
        {
          compteur_attente = 0;
          return;
        }
    }
    if (rightjoy(0))
      RAY_RESPOND_TO_DIR(0);
    if (leftjoy(0))
      RAY_RESPOND_TO_DIR(1);
    if (downjoy(0) && joy_done == 0)
    {
      RAY_RESPOND_TO_DOWN();
      joy_done++;
    }
    if (upjoy(0))
    {
      if (joy_done == 0)
      {
        RAY_RESPOND_TO_UP();
        joy_done++;
      }
      else
      {
        compteur_attente = 0;
        return;
      }
    }

    if (joy_done == 0)
      RAY_RESPOND_TO_NOTHING();
    else
      compteur_attente = 0;
}

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", DO_RAYMAN);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", DO_RAY_ON_MS);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", DO_PLACE_RAY);
