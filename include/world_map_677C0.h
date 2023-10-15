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
#include "timers.h"

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
extern Obj *mapobj;

extern s16 xmap;
extern s16 ymap;
extern Obj raylittle;
extern u8 chemin_percent;
extern u8 *PTR_s_game_saved_801c3540;
extern u8 dir_on_wldmap;
extern s16 xmapinit;
extern s16 ymapinit;
extern s16 xwldmapsave;
extern s16 ywldmapsave;

void CalcObjPosInWorldMap(Obj *obj);

void PS1_DisplayPts(s16 from, s16 to, s16 from_x, s16 from_y);



void INIT_LEVEL_STAGE_NAME(void);

void INIT_STAGE_NAME(void);
void CHANGE_STAGE_NAMES(void);
void PS1_CardDisplayPassword(void);
void PS1_WorldMapMoveText(void);

void INIT_LITTLE_RAY(void);
void RESTORE_RAY(void);

void RESPOND_TO_UP(void);
void RESPOND_TO_DOWN(void);
void RESPOND_TO_RIGHT(void);
void RESPOND_TO_LEFT(void);
void MoveRayInWorldMap(void);

void DO_CHEMIN(void);

void PASTILLES_SAUVE_SAVED(s16 wld);
void FIN_WORLD_CHOICE(void);


#endif