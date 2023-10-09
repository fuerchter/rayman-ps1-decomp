#ifndef WORLD_MAP_677C0_H
#define WORLD_MAP_677C0_H

#include "common.h"
#include "world_map_95CC.h"
#include "obj_update.h"
#include "text_24E10.h"
#include "ray/ray_32398.h"
#include "ray/ray_5D190.h"
#include "moteur_update.h"
#include "cam_scroll.h"
#include "menu/menu_card_7C028.h"

/* TODO: does padding (between color, level_name) matter? */
typedef struct WorldInfo
{
    s16 x_pos;
    s16 y_pos;
    u8 index_up;
    u8 index_down;
    u8 index_left;
    u8 index_right;
    u8 state; /* TODO: bitfield */
    u8 nb_cages;
    u8 world;
    u8 level;
    u8 color;
    u8 * level_name;
} WorldInfo;

extern WorldInfo t_world_info[24];

extern s16 xmap;
extern s16 ymap;
extern s16 new_world;
extern u8 old_num_world;
extern Obj raylittle;
extern u8 chemin_percent;

void CalcObjPosInWorldMap(Obj *obj);
void INIT_STAGE_NAME(void);
void RESTORE_RAY(void);
void MoveRayInWorldMap(void);
void DO_CHEMIN(void);

#endif