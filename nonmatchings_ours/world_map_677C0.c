#include "world_map_677C0.h"

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_UP);*/
/* https://decomp.me/scratch/6ivxi PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O1 */
/* 698B4 8018E0B4 */
extern s16 num_world_choice;
extern WorldInfo t_world_info[24];

void RESPOND_TO_UP(void)
{
    num_world_choice = t_world_info[num_world_choice].index_up;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_PASTILLES_SAUVE);*/
/* https://decomp.me/scratch/Y1VKk PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O2 */
/* 6A0C8 8018E8C8 */
extern s32 D_801C34D4;
extern s32 D_801C34E8;
extern s32 D_801C34FC;
extern s32 D_801C3510;
extern s32 D_801C3524;
extern s32 D_801C3538;
extern u8 *D_801C353C;
extern u8 *D_801C3544;
extern u8 NBRE_SAVE;

void INIT_PASTILLES_SAUVE(void)
{
 u8 *test;
  
  if (NBRE_SAVE != 0) {
    test = D_801C353C;
  }
  else
  {
    test = D_801C3544;
  }
  __asm__("nop"); /* ... */
  t_world_info[18].level_name = test;
  t_world_info[19].level_name = test;
  t_world_info[20].level_name = test;
  t_world_info[21].level_name = test;
  t_world_info[22].level_name = test;
  t_world_info[23].level_name = test;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_INFO);*/

/* 692CC 8018DACC -O2 */
/*? INIT_PASTILLES_SAUVE(s32, s16, s32);*/
extern u8 D_801C3364;
extern u8 D_801F3EA0;
extern s8 You_Win;
extern s8 dir_on_wldmap;
extern s8 fin_du_jeu;
extern s16 new_level;
extern s16 num_level;
extern s16 num_world;
extern s8 world_index;
extern s16 xwldmapsave;
extern s16 ywldmapsave;

void INIT_WORLD_INFO(void)
{
  s16 var_a1;
  s32 var_a0;
  s32 var_a2;
  if (D_801F3EA0 != 0)
  {
    var_a1 = 0;
    var_a2 = 0xfffffffb;
    do
    {
      var_a0 = var_a1;
      var_a0 = var_a0 * 0x14;
      *(s32 *) (&D_801C3364 + var_a0) = (*(s32 *) (&D_801C3364 + var_a0) | 1) & var_a2;
      var_a1 = var_a1 + 1;
    }
    while (var_a1 < 0x18);

  }
  num_world = 0;
  num_level = 0;
  new_world = 1;
  new_level = 1;
  world_index = 0;
  xwldmapsave = 0;
  ywldmapsave = 0x9E;
  dir_on_wldmap = 1;
  You_Win = 0;
  fin_du_jeu = 0;
  INIT_PASTILLES_SAUVE(var_a0);
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PASTILLES_SAUVE_SAVED);*/

/* 6A130 8018E930 -O2 */
/*? INIT_PASTILLES_SAUVE();*/
extern s32 D_801C336C;
extern s32 D_801C3540;

void PASTILLES_SAUVE_SAVED(s16 arg0)
{
    u8 *test;

    INIT_PASTILLES_SAUVE();
    test = &(t_world_info[0].level_name);
    *(u32*)(test + arg0 * sizeof(WorldInfo)) = D_801C3540;
}

/* missing_addiu match, but nicer way to match without test/test2? */
/* 6A224 8018EA24 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DETER_WORLD_AND_LEVEL);*/

extern u8 D_801C3366;
extern u8 D_801C3367;
extern u8 D_801F43D1;
extern u8 D_801F4EE9;
extern s8 You_Win;
extern u8 finBosslevel[2];
extern s8 fin_dark;
extern RaymanEvents RayEvts;

void DETER_WORLD_AND_LEVEL(void)
{
  RayEvts_1 *test;
  RayEvts_1 *test2;

  world_index = num_world_choice;
  if (ModeDemo == 0)
  {
    num_level_choice = t_world_info[num_world_choice].level;
    num_world_choice = t_world_info[num_world_choice].world;
  }
  if (num_world_choice == 5)
  {
    if (num_level_choice == 3 && finBosslevel[1] & 2)
    {
      num_level_choice += 1;
      test2 = &RayEvts.flags1;
      *test2 |= 4;
      return;
    }
    if (num_world_choice == 5)
    {
      if (num_level_choice == 4 && finBosslevel[1] & 2 && ModeDemo != 0)
      {
        test = &RayEvts.flags1;
        *test |= 4;
        return;
      }
    }
  }
  if (num_world_choice == 6 && finBosslevel[0] & 0x80)
  {
    You_Win = 1;
    fin_du_jeu = 1;
    fin_dark = 1;
    new_world = 1;
  }
}

/* matches, but WorldInfo state casts... */
/* 679D4 8018C1D4 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DISPLAY_PLAT_WAY);*/

void DISPLAY_PLAT_WAY(void)
{
  s16 i;
  WorldInfo *cur;
  s16 x_pos;
  s16 y_pos;
  s8 flag;
  
  i = 0;
  cur = &t_world_info[i];
  do
  {
    flag = 0xfd;
    *(u32*)&cur->state = *(u32*)&cur->state & flag;
    i++;
    cur++;
  } while (i < 24);

  i = 0;
  cur = &t_world_info[i];
  do
  {
    x_pos = cur->x_pos;
    y_pos = cur->y_pos;
    if (*(u32*)&cur->state & 1)
    {
      PS1_DisplayPts(i, cur->index_up, x_pos, y_pos);
      PS1_DisplayPts(i, cur->index_down, x_pos, y_pos);
      PS1_DisplayPts(i, cur->index_right, x_pos, y_pos);
      PS1_DisplayPts(i, cur->index_left, x_pos, y_pos);
      *(u32*)&cur->state = *(u32*)&cur->state | 2;
    }
    i++;
    cur++;
  } while (i < 24);
}

/* matches, but WorldInfo state casts... */
/* 67B0C 8018C30C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_DisplayPlateau);*/

extern Obj *mapobj;

void PS1_DisplayPlateau(void)
{
  Obj *obj;
  WorldInfo *wi;
  s16 i;
  s16 test;
  
  i = 0;
  wi = t_world_info;
  obj = mapobj;
  do
  {
    if ((*(u32*)&wi->state & 1 || (i == 17)) &&
        ((obj->screen_x_pos + (u32)obj->offset_bx) - 0x25 < 0x101) &&
       ((obj->screen_y_pos + (u32)obj->offset_by) - 0x2e < 0x97))
    {
      DISPLAY_PLATEAU(obj);
    }
    wi = wi + 1;
    obj = obj + 1;
    i = i + 1;
  } while (i < 24);
}

/* matches, but gotos, WorldInfo state casts... */
/* 67BE8 8018C3E8 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DO_MEDAILLONS);*/

void DO_MEDAILLONS(void)
{
    s16 iVar3;
    Obj *mapObj_0;
    WorldInfo *pbVar2;
    u8 bVar1;
    u8 flag_set;

    if ((chemin_percent < 100) && (horloge[2] != 0)) {
        chemin_percent = chemin_percent + 1;
    }
    iVar3 = 0;
    mapObj_0 = mapobj;
    pbVar2 = t_world_info;
    do
    {
        CalcObjPosInWorldMap(mapObj_0);
        if (((*(u32 *)(&pbVar2->state) & 4) != 0) && (0x62 < chemin_percent))
        {
            *(u32 *)(&pbVar2->state) = *(u32 *)(&pbVar2->state) & 0xfffffffb | 1;
            set_sub_etat(mapObj_0,0x2e);
        }
        if (
            (s16)iVar3 == 0x11 &&
            mapObj_0->sub_etat != 0x3b &&
            mapObj_0->sub_etat != 0x2e &&
            (*(u32 *)(&pbVar2->state) & 1) != 0
        )
        {
            set_sub_etat(mapObj_0,0x3b);
        }
        else if (
            ((((u16)(iVar3 - 0x12) < 2 ||
            (u16)(iVar3 - 0x14) < 2) ||
            (u16)(iVar3 - 0x16) < 2) &&
            ((mapObj_0->sub_etat != 0x3a && (mapObj_0->sub_etat != 0x2e)))) &&
            ((*(u32 *)(&pbVar2->state) & 1) != 0)
        )
        {
            set_sub_etat(mapObj_0,0x3a);
        }
        else
        {
            bVar1 = pbVar2->nb_cages;
            if ((5 < bVar1) && (mapObj_0->sub_etat == 0x33))
            {
                flag_set = mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].flags & 0x10;
                if(
                    (!flag_set || mapObj_0->anim_frame == 0) &&
                    (flag_set || (u32)mapObj_0->anim_frame == mapObj_0->animations[mapObj_0->anim_index].frames_count - 1)
                )
                {
                    if (horloge[mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].anim_speed & 0xf] == 0) {
                        set_sub_etat(mapObj_0,0x34);
                        goto LAB_8018c9d8;
                    }
                }

            }
            if ((4 < bVar1) && (mapObj_0->sub_etat == 0x32)) {
                flag_set = mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].flags & 0x10;
                if(
                    (!flag_set || mapObj_0->anim_frame == 0) &&
                    (flag_set || (u32)mapObj_0->anim_frame == mapObj_0->animations[mapObj_0->anim_index].frames_count - 1)
                )
                {
                    if (horloge[mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].anim_speed & 0xf] == 0) {
                        set_sub_etat(mapObj_0,0x33);
                        goto LAB_8018c9d8;
                    }
                }
            }
            if ((3 < bVar1) && (mapObj_0->sub_etat == 0x31)) {
                flag_set = mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].flags & 0x10;
                if(
                    (!flag_set || mapObj_0->anim_frame == 0) &&
                    (flag_set || (u32)mapObj_0->anim_frame == mapObj_0->animations[mapObj_0->anim_index].frames_count - 1)
                )
                {
                    if (horloge[mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].anim_speed & 0xf] == 0) {
                        set_sub_etat(mapObj_0,0x32);
                        goto LAB_8018c9d8;
                    }
                }
            }
            if ((2 < bVar1) && (mapObj_0->sub_etat == 0x30)) {
                flag_set = mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].flags & 0x10;
                if(
                    (!flag_set || mapObj_0->anim_frame == 0) &&
                    (flag_set || (u32)mapObj_0->anim_frame == mapObj_0->animations[mapObj_0->anim_index].frames_count - 1)
                )
                {
                    if (horloge[mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].anim_speed & 0xf] == 0) {
                        set_sub_etat(mapObj_0,0x31);
                        goto LAB_8018c9d8;
                    }
                }
            }
            if ((1 < bVar1) && (mapObj_0->sub_etat == 0x2f)) {
                flag_set = mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].flags & 0x10;
                if(
                    (!flag_set || mapObj_0->anim_frame == 0) &&
                    (flag_set || (u32)mapObj_0->anim_frame == mapObj_0->animations[mapObj_0->anim_index].frames_count - 1)
                )
                {
                    if (horloge[mapObj_0->eta[mapObj_0->main_etat][mapObj_0->sub_etat].anim_speed & 0xf] == 0) {
                        set_sub_etat(mapObj_0,0x30);
                        goto LAB_8018c9d8;
                    }
                }
            }
        }
    LAB_8018c9d8:
        DO_ANIM(mapObj_0);
        mapObj_0 = mapObj_0 + 1;
        iVar3 = iVar3 + 1;
        pbVar2 = pbVar2 + 1;
    } while(0x17 >= iVar3);
}

/* based on ghidra */
/* 683FC 8018CBFC -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_STAGE_NAME);*/

extern s16 fichier_selectionne;
extern u8 s___801cf0a4[4];
extern u8 s__801cf0a8[2];
extern u8 save_ray[4][4];

void INIT_WORLD_STAGE_NAME(void)
{
    u8 bVar1;
    u8 local_60[48];

    switch(t_world_info[num_world_choice].world) {
        case 1:
            __builtin_strcpy(text_to_display[2].text, "/the dream forest/");
            bVar1 = 7;
            break;
        case 2:
            __builtin_strcpy(text_to_display[2].text, "/band land/");
            bVar1 = 4;
            break;
        case 3:
            __builtin_strcpy(text_to_display[2].text, "/blue mountains/");
            bVar1 = 0xd;
            break;
        case 4:
            __builtin_strcpy(text_to_display[2].text, "/picture city/");
            bVar1 = 0;
            break;
        case 5:
            __builtin_strcpy(text_to_display[2].text, "/the cave of skops/");
            bVar1 = 2;
            break;
        case 6:
            __builtin_strcpy(text_to_display[2].text, "/candy chateau/");
            bVar1 = 1;
            break;
        case 7:
            bVar1 = t_world_info[num_world_choice].color;
            if (fichier_selectionne == 1)
            {
                /*local_60._0_2_ = s_/_801cf0a8;*/
                strcat(local_60, save_ray[1]);
                strcat(local_60, s__801cf0a8);
                __builtin_strcpy(text_to_display[2].text, local_60);
            }
            else if (fichier_selectionne < 2)
            {
                if (fichier_selectionne == 0)
                {
                    if (NBRE_SAVE == 0)
                    {
                        __builtin_strcpy(text_to_display[2].text, "/password/");
                    }
                    else
                    {
                        __builtin_strcpy(text_to_display[2].text, s___801cf0a4);
                    }
                }
            }
            else if (fichier_selectionne == 2)
            {
                /*local_60._0_2_ = s_/_801cf0a8;*/
                strcat(local_60, save_ray[2]);
                strcat(local_60, s__801cf0a8);
                __builtin_strcpy(text_to_display[2].text, local_60);
            }
            else if (fichier_selectionne == 3)
            {
                /*local_60._0_2_ = s_/_801cf0a8;*/
                strcat(local_60, save_ray[3]);
                strcat(local_60, s__801cf0a8);
                __builtin_strcpy(text_to_display[2].text, local_60);
            }
            break;
    }
    text_to_display[2].color = bVar1;
    text_to_display[2].font_size = 1;
    text_to_display[2].x_pos = 0x1c2;
    text_to_display[2].y_pos = 0x28;
    text_to_display[2].is_fond = FALSE;
    text_to_display[2].field8_0x3d = TRUE;
    INIT_TXT_BOX(text_to_display + 2);
    text_to_display[2].width = text_to_display[2].width + 10;
    text_to_display[2].height = text_to_display[2].height + 2;
}

/* pretty close */
/* 69468 8018DC68 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_CHEMIN);*/

/*? INIT_PASTILLES_SAUVE(s32, s32 *, u16);
? SaveGameOnDisk(s16);
? obj_init(Obj *);
? set_main_and_sub_etat(Obj *, ?, ?);
? set_zoom_mode(?, u8);*/
extern u8 Nb_total_cages;
extern s8 dans_la_map_monde;
extern u8 dir_on_wldmap;
extern s16 fichier_selectionne;
extern s8 gele;
extern Obj *mapobj;
extern u8 nouvelle_partie;
extern s16 scroll_end_x;
extern s16 scroll_end_y;
extern s16 scroll_start_x;
extern s16 scroll_start_y;
extern s16 scroll_x;
extern s16 scroll_y;
extern s16 special_ray_mov_win_x_left;
extern s16 special_ray_mov_win_x_right;
extern u16 xmapinit;
extern u16 xwldmapsave;
extern u16 ymapinit;
extern u16 ywldmapsave;

void INIT_CHEMIN(void)
{
  WorldInfo *wld_inf;
  u8 init_sub_etat;
  u32 state;
  Obj *_obj;
  u8 worldIndex;
  Obj *obj;
  s16 i;
  s16 sVar3;
  u16 frames_count;
  
  PROC_EXIT = FALSE;
  dans_la_map_monde = TRUE;
  gele = 0;
  i = 0;
  if (ModeDemo == 0) {
    new_world = 0;
    num_world_choice = (s16)world_index;
  }
  old_num_world = (u8)num_world_choice;
  worldIndex = 0;
  INIT_LITTLE_RAY();
  set_main_and_sub_etat(&ray,0,0);
  ray.x_pos = (t_world_info[num_world_choice].x_pos - ray.offset_bx) + 4;
  ray.y_pos = t_world_info[num_world_choice].y_pos - ray.offset_by + 8;
  ray.speed_x = 0;
  ray.speed_y = 0;
  set_zoom_mode(0);
  chemin_percent = 0;
  Nb_total_cages = 0;
  _obj = mapobj; /* 0x55 */
  do {
    _obj->type = TYPE_MEDAILLON;
    _obj->init_x_pos = t_world_info[worldIndex].x_pos + -0x4e;
    _obj->init_y_pos = t_world_info[worldIndex].y_pos + -0x40;
    _obj->init_main_etat = 5;
    wld_inf = &t_world_info[worldIndex];
    state = *(u32*)&wld_inf->state; /* u32? */
    init_sub_etat = 0x2e;
    if ((state >> 2 & 1) == 0) {
      if (t_world_info[worldIndex].nb_cages != 0) {
        Nb_total_cages = Nb_total_cages + t_world_info[worldIndex].nb_cages;
        init_sub_etat = 0x2f;
        if (t_world_info[worldIndex].nb_cages == 6) {
          init_sub_etat = 0x34;
        }

      }
      else {
        init_sub_etat = 0x27;
        if (i == 17) {
          init_sub_etat = 0x3b;
          _obj->sub_etat = 0x3b;
        }
      }
    }
    _obj->init_sub_etat = init_sub_etat;
    _obj->scale = 0;
    _obj->offset_bx = 0x50;
    _obj->offset_by = 0x40;
    obj_init(_obj);
    CalcObjPosInWorldMap(_obj);
    frames_count = _obj->animations[_obj->eta[_obj->main_etat][_obj->sub_etat].anim_index].frames_count;
    if (frames_count == 0) {
      /*trap_if(0x1c00);*/
    }
    if ((frames_count == 0xffffffff) && (i == -0x80000000)) {
      /*trap_if(0x5d);*/
    }
    worldIndex = worldIndex + 1;
    _obj->anim_frame = i % frames_count;
    if (worldIndex > 24) {
      worldIndex = 24;
    }
    _obj = _obj + 1;
    i = i + 1;
  } while (i < 24);
  if (((*(u32*)&t_world_info[17].state & 1) == 0) && (0x65 < Nb_total_cages)) {
    *(u32*)&t_world_info[17].state = *(u32*)&t_world_info[17].state | 4;
  }
  scroll_end_x = 0x9c;
  scroll_end_y = 0x9e;
  scroll_x = 0xffff;
  scroll_y = 0xffff;
  special_ray_mov_win_x_left = 0x1e;
  special_ray_mov_win_x_right = 0x1e;
  scroll_start_x = 0;
  scroll_start_y = 0;
  xmapinit = xmap;
  ymapinit = ymap;
  xmap = xwldmapsave;
  ymap = ywldmapsave;
  ray.flags = ray.flags & ~OBJ_FLIP_X | (dir_on_wldmap & 1) << 0xe;
  INIT_PASTILLES_SAUVE();
  INIT_STAGE_NAME();
  if (nouvelle_partie != FALSE) {
    if (NBRE_SAVE != 0) {
      SaveGameOnDisk(fichier_selectionne);
    }
    nouvelle_partie = FALSE;
  }
}