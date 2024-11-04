#include "num_level_36260.h"

#ifdef BSS_DEFS
s16 departlevel;
FinBosslevel finBosslevel;
u8 fin_boss;
#endif

/* 36260 8015AA60 -O2 -msoft-float */
void new_level_init(void)
{
  departlevel = true;
  ray_X_main_pos_init = ray.x_pos;
  ray_Y_main_pos_init = ray.y_pos;
  xmapsave = xmap;
  ymapsave = ymap;
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/num_level_36260", fix_numlevel);
#else
/* matches, but clean up */
/*INCLUDE_ASM("asm/nonmatchings/num_level_36260", fix_numlevel);*/

void fix_numlevel(Obj *obj)
{
    s16 temp_v0_1;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 var_v0_2;
    s32 *var_a0;
    s32 temp_v1;
    s16 var_s0;
    s32 var_v0;

    var_s0 = 0;
    if (departlevel != 0)
    {
        new_level_init();
        if (obj->type != 5)
        {
            switch (num_world)
            {
            case 1:
                if ((num_level == 2) && (RayEvts.poing))
                {
                    num_level_choice = (u16) num_level_choice + 1;
                }
                if ((num_level == 5) && finBosslevel.bzzit)
                {
                    num_level_choice = (u16) num_level_choice + 1;
                }
                if (num_level == 7)
                {
                    if (RayEvts.hang)
                    {
                        new_world = 1;
                    }
                }
                if ((num_level == 0x000D) && finBosslevel.moskito)
                {
                    num_level_choice = (u16) num_level_choice + 1;
                }
                if (num_level == 0x000F)
                {
                    if (finBosslevel.moskito)
                    {
                        new_world = 1;
                    }
                }
                if (num_level == 0x0010)
                {
                    if (RayEvts.grap)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 2:
                if (num_level == 5)
                {
                    if (finBosslevel.crazy_drummer)
                    {
                        new_world = 1;
                    }
                }
                if ((num_level == 9) && finBosslevel.mr_sax)
                {
                    new_world = 1;
                }
                if (num_level == 0x000A)
                {
                    if (RayEvts.helico)
                    {
                        new_world = 1;
                    }
                }
                if (num_level == 0x000E)
                {
                    if (finBosslevel.mr_sax != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 3:
                if (num_level == 1)
                {
                    if (finBosslevel.mr_stone)
                    {
                        new_world = 1;
                    }
                }
                if ((num_level == 9) && (finBosslevel.mr_stone))
                {
                    new_world = 1;
                }
                if (num_level == 0x000A)
                {
                    var_v0 = RayEvts.run;
                    if (var_v0 != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 4:
                if (num_level == 3)
                {
                    if (finBosslevel.viking_mama)
                    {
                        new_world = 1;
                    }
                }
                if (num_level == 0x000A)
                {
                    if (finBosslevel.space_mama != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 5:
                if (num_level == 9)
                {
                    if (finBosslevel.mr_skops != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 6:
                if (num_level == 1)
                {
                    if (finBosslevel.mr_dark != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            }
        }
    }
    switch (num_world)
    {
    case 1:
        switch (num_level)
        {
        case 2:
            if (obj->type == 5)
            {
                num_level_choice = 0x0015;
                var_s0 = 1;
            }
            break;
        case 4:
            if (obj->type == 5)
            {
                num_level_choice = 0x0014;
                var_s0 = 1;
                break;
            }
            new_world = 1;
            if (!(t_world_info[1].is_unlocked))
            {
                t_world_info[1].is_unlocking = true;
                t_world_info[18].is_unlocking = true;
            }
            break;
        case 8:
            new_world = 1;
            if (!(t_world_info[2].is_unlocked))
            {
                t_world_info[2].is_unlocking = true;
            }
            if (!(t_world_info[4].is_unlocked))
            {
                t_world_info[4].is_unlocking = true;
            }
            break;
        case 11:
            if (obj->type != 5)
            {
                new_world = 1;
                if (!(t_world_info[3].is_unlocked))
                {
                    t_world_info[3].is_unlocking = true;
                }
            }
            else
            {
                num_level_choice = 0x0012;
                var_s0 = 1;
                break;
            }
            break;
        case 12:
            if (obj->type == 5)
            {
                num_level_choice = 0x0013;
                var_s0 = 1;
                break;
            }
            break;
        case 17:
            new_world = 1;
            break;
        case 18:
            num_level_choice = 0x000B;
            var_s0 = 1;
            break;
        case 19:
            num_level_choice = 0x000C;
            var_s0 = 1;
            break;
        case 20:
            num_level_choice = 4;
            var_s0 = 1;
            break;

        case 21:
            num_level_choice = 2;
            var_s0 = 1;
            break;
        }
        break;
    case 2:
        switch (num_level)
        {
        case 4:
            if (obj->type == 5)
            {
                num_level_choice = 0x0011;
                var_s0 = 1;
                break;
            }
            break;
        case 6:
            new_world = 1;
            if (!(t_world_info[5].is_unlocked))
            {
                t_world_info[5].is_unlocking = true;
                t_world_info[19].is_unlocking = true;
            }
            break;
        case 9:
            if (obj->type == 5)
            {
                num_level_choice = 0x0012;
                var_s0 = 1;
                break;
            }
            break;
        case 11:
            new_world = 1;
            if (!(t_world_info[6].is_unlocked))
            {
                t_world_info[6].is_unlocking = true;
            }
            if (!(t_world_info[8].is_unlocked))
            {
                t_world_info[8].is_unlocking = true;
            }
            break;
        case 13:
            new_world = 1;
            if (!(t_world_info[7].is_unlocked))
            {
                t_world_info[7].is_unlocking = true;
                t_world_info[20].is_unlocking = true;
            }
            break;
        case 16:
            new_world = 1;
            break;
        case 17:
            num_level_choice = 4;
            var_s0 = 1;
            break;
        case 18:
            num_level_choice = 9;
            var_s0 = 1;
            break;
        }
        break;
    case 3:
        switch (num_level)
        {
        case 2:
            new_world = 1;
            if (!(t_world_info[9].is_unlocked))
            {
                t_world_info[9].is_unlocking = true;
            }
            break;
        case 4:
            if (obj->type == 5)
            {
                num_level_choice = 0x000C;
                var_s0 = 1;
                break;
            }
            break;
        case 5:
            new_world = 1;
            if (!(t_world_info[10].is_unlocked))
            {
                t_world_info[10].is_unlocking = true;
                t_world_info[21].is_unlocking = true;
            }
            break;
        case 9:
            if (obj->type == 5)
            {
                num_level_choice = 0x000D;
                var_s0 = 1;
                break;
            }
            break;
        case 11:
            new_world = 1;
            if (!(t_world_info[11].is_unlocked))
            {
                t_world_info[11].is_unlocking = true;
            }
            break;
        case 12:
            num_level_choice = 4;
            var_s0 = 1;
            break;
        case 13:
            num_level_choice = 9;
            var_s0 = 1;
            break;
        }
        break;
    case 4:
        switch (num_level)
        {
        case 3:
            if (obj->type == 5)
            {
                num_level_choice = 0x000C;
                var_s0 = 1;
                break;
            }
            break;
        case 4:
            new_world = 1;
            if (!(t_world_info[12].is_unlocked))
            {
                t_world_info[12].is_unlocking = true;
            }
            break;
        case 7:
            new_world = 1;
            if (!(t_world_info[13].is_unlocked))
            {
                t_world_info[13].is_unlocking = true;
            }
            break;
        case 9:
            if (obj->type == 5)
            {
                num_level_choice = 0x000D;
                var_s0 = 1;
                break;
            }
            break;
        case 11:
            new_world = 1;
            if (!(t_world_info[14].is_unlocked))
            {
                Vignet_To_Display = 1;
                t_world_info[14].is_unlocking = true;
block_132:
                t_world_info[22].is_unlocking = true;
            }
            break;
        case 12:
            num_level_choice = 3;
            var_s0 = 1;
            break;
        case 13:
            num_level_choice = 9;
            var_s0 = 1;
            break;
        }
        break;
    case 5:
        switch (num_level)
        {
        case 2:
            if (obj->type == 5)
            {
                num_level_choice = 0x000C;
                var_s0 = 1;
                break;
            }
            new_world = 1;
            if (!(t_world_info[15].is_unlocked))
            {
                t_world_info[15].is_unlocking = true;
                t_world_info[22].is_unlocking = true;
            }
            break;
        case 8:
            new_world = 1;
            if (!(t_world_info[16].is_unlocked))
            {
                t_world_info[16].is_unlocking = true;
                t_world_info[23].is_unlocking = true;
            }
            break;
        case 11:
            new_world = 1;
            Vignet_To_Display = 1;
            break;
        case 12:
            num_level_choice = 2;
            var_s0 = 1;
            break;
        }
        break;
    case 6:
        if (num_level == 4)
        {
            new_world = 1;
            You_Win = 1;
            fin_du_jeu = 1;
            fin_dark = 1;
        }
        break;
    }
    if (!(t_world_info[17].is_unlocked) && (Nb_total_cages >= 102))
    {
        t_world_info[17].is_unlocking = true;
    }
    if ((new_world == 0) && (var_s0 == 0))
    {
        num_level_choice++;
    }
    new_level = 1;
}
const u8 rodata_fix_numlevel[4] = {};
#endif

/* 36D54 8015B554 -O2 -msoft-float */
void TEST_SIGNPOST(void)
{
  s32 poing_id;
  u32 sub_etat;

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
    FUN_80131cc0();
  }
  else if (ray.main_etat == 3 && (sub_etat = ray.sub_etat, sub_etat == 23 || sub_etat == 52))
  {
    if(EOA(&ray))
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
      FUN_80131cc0();
      set_sub_etat(&ray, 14);
      ray.anim_frame = 0;
    }
    gele = 2;
    decalage_en_cours = 0;
    ray.speed_x = 0;
    ray.speed_y = 0;
    if (ray.sub_etat == 14)
    {
      if (EOA(&ray))
      {
        ChangeLevel();
        gele = 0;
      }
    }
  }
}