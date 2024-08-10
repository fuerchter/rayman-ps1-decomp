#include "num_level_36260.h"

/* 36260 8015AA60 -O2 -msoft-float */
void new_level_init(void)
{
  departlevel = true;
  ray_X_main_pos_init = ray.x_pos;
  ray_Y_main_pos_init = ray.y_pos;
  xmapsave = xmap;
  ymapsave = ymap;
}

INCLUDE_ASM("asm/nonmatchings/num_level_36260", fix_numlevel);

/* 36D54 8015B554 -O2 -msoft-float */
void TEST_SIGNPOST(void)
{
  s32 poing_id;
  u32 sub_etat;
  u8 flag_set;

  if (ray.main_etat == 2 && ray.sub_etat != 8)
  {
    if (ray.speed_x != 0 && decalage_en_cours == 0)
      ray.x_pos -= ray.speed_x;

    no_ray_landing_smoke = true;
    ray.speed_x = 0;
    decalage_en_cours = 0;
    if (ray.speed_y <= -1)
      ray.speed_y = 0;
  }
  else if (ray.main_etat < 2 && ray.iframes_timer == -1 && gele == 0)
  {
    if (fin_boss)
      set_main_and_sub_etat(&ray, 3, 52);
    else
      set_main_and_sub_etat(&ray, 3, 23);
    ray.anim_frame = 0;
    if (poing.is_active)
    {
      poing_id = poing_obj_id;
      poing.is_active = false;
      level.objects[poing_id].flags &= ~FLG(OBJ_ALIVE);
      DO_NOVA(&level.objects[poing_id]);
      fin_poing_follow(&level.objects[poing_obj_id], false);
    }
    if (ray_on_poelle == true)
    {
      PS1_RestoreSauveRayEvts();
      decalage_en_cours = 0;
      Reset_air_speed(false);
      Reset_air_speed(true);
      ray_on_poelle = false;
    }
    test_fin_cling();
    decalage_en_cours = 0;
    ray.speed_x = 0;
    if (!fin_boss && !ray_on_poelle && num_world != 6)
      gele = 2;
    start_cd_gagne();
  }
  else if (ray.main_etat == 3 && (sub_etat = ray.sub_etat, sub_etat == 23 || sub_etat == 52))
  {
    flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
    if(
      ((flag_set && ray.anim_frame == 0) ||
      (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)) &&
      horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0
    )
    {
      ChangeLevel();
      gele = 0;
    }
    else
    {
      ray.speed_x = 0;
      ray.speed_y = 0;
      decalage_en_cours = 0;
      NumScrollObj = 0;
      if (ray.field20_0x36 != -1) {
        level.objects[ray.field20_0x36].speed_y = 0;
        level.objects[ray.field20_0x36].speed_x = 0;
        level.objects[ray.field20_0x36].gravity_value_1 = 0;
        level.objects[ray.field20_0x36].gravity_value_2 = 0;
      }
    }
  }
  else if (ray.main_etat == 6) /* on moskito, al3? */
  {
    if (ray.sub_etat != 14)
    {
      start_cd_gagne();
      set_sub_etat(&ray, 14);
      ray.anim_frame = 0;
    }
    gele = 2;
    decalage_en_cours = 0;
    ray.speed_x = 0;
    ray.speed_y = 0;
    if (ray.sub_etat == 14)
    {
      flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
      if (
        ((flag_set && ray.anim_frame == 0) ||
        (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)) &&
        horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0
      )
      {
        ChangeLevel();
        gele = 0;
      }
    }
  }
}