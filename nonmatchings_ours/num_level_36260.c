#include "num_level_36260.h"

/* matches, but still too many gotos */
/* 36D54 8015B554 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/num_level_36260", TEST_SIGNPOST);*/

/*? ChangeLevel();
? DO_NOVA(Obj *, s32);
? PS1_RestoreSauveRayEvts();
? Reset_air_speed(?);
? fin_poing_follow(Obj *, ?);
? set_main_and_sub_etat(u8 *, ?, ?);
? set_sub_etat(u8 *, ?);
? start_cd_gagne(u8);
? test_fin_cling();*/
extern s16 NumScrollObj;
extern u8 gele;
extern u8 no_ray_landing_smoke;
extern u8 ray_on_poelle;

void TEST_SIGNPOST(void)
{
  int poingIndex;
  uint uVar1;
  
  if ((ray.main_etat == 2) && (ray.sub_etat != 8)) {
    if ((ray.speed_x != 0) && (decalage_en_cours == 0)) {
      ray.x_pos = ray.x_pos - ray.speed_x;
    }

    no_ray_landing_smoke = true;
    decalage_en_cours = 0;
    ray.speed_x = 0;
    if (-1 >= ray.speed_y) {
          ray.speed_y = 0;
    }
    return;
  }
  if (((ray.main_etat < 2) && (ray.iframes_timer == -1)) && (gele == 0)) {
    if (fin_boss) {
      set_main_and_sub_etat(&ray,3,0x34);
    }
    else {
      set_main_and_sub_etat(&ray,3,0x17);
    }
    ray.anim_frame = 0;
    if (poing.is_active != false) {
      poingIndex = (int)poing_obj_id;
      poing.is_active = false;
      level.objects[poingIndex].flags = level.objects[poingIndex].flags & ~FLG(OBJ_ALIVE);
      DO_NOVA(level.objects + poingIndex);
      fin_poing_follow(level.objects + poing_obj_id,false);
    }
    if (ray_on_poelle == true) {
      PS1_RestoreSauveRayEvts();
      decalage_en_cours = 0;
      Reset_air_speed(false);
      Reset_air_speed(true);
      ray_on_poelle = false;
    }
    test_fin_cling();
    decalage_en_cours = 0;
    ray.speed_x = 0;
    if (((fin_boss == false) && (ray_on_poelle == false)) && (num_world != 6)) {
      gele = 2;
    }
    start_cd_gagne();
    return;
  }
  if ((ray.main_etat == 3) && ((uVar1 = (uint)ray.sub_etat, uVar1 == 0x17 || (uVar1 == 0x34)))) {
block_25:
    if (!((ray.eta[3][ray.sub_etat].flags & 0x10)))
    {
        goto block_28;
    }
    if (ray.anim_frame == 0)
    {
        goto block_29;
    }
    goto block_30;
block_28:
    if (ray.anim_frame != ray.animations[ray.anim_index].frames_count - 1)
    {
        goto block_30;
    }
block_29:
    if (horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0)
    {
        goto LAB_8015babc;
    }
block_30:
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
  else {
block_32:
    if (ray.main_etat == 6)
    {
      if (ray.sub_etat == 0x0E)
      {
          goto block_35;
      }
      start_cd_gagne();
      set_sub_etat(&ray, 0xE);
      ray.anim_frame = 0;
  block_35:
      gele = 2;
      decalage_en_cours = 0;
      ray.speed_x = 0;
      ray.speed_y = 0;
      if (ray.sub_etat == 0x0E)
      {
        if (!(ray.eta[ray.main_etat][0xe].flags & 0x10))
        {
            goto block_39;
        }
        if (ray.anim_frame == 0)
        {
            goto block_40;
        }
        return;
    block_39:
        if (ray.anim_frame != ray.animations[ray.anim_index].frames_count - 1)
        {
            return;
        }
    block_40:
        if (horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] != 0)
        {
            return;
        }
    LAB_8015babc:
        ChangeLevel();
        gele = 0;
      }
    }
  }
  return;
}