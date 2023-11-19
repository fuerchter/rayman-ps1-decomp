#ifndef RAY_5D190_H
#define RAY_5D190_H

#include "common.h"
#include "psyq_3_0/MEMORY.H"
#include "obj_update.h"
#include "ray/ray_32398.h"

/* TODO: bitfields? */
typedef u8 RayEvts_0;
#define RAYEVTS0_POING 0
#define RAYEVTS0_HANG 1
#define RAYEVTS0_HELICO 2
#define RAYEVTS0_SUPER_HELICO 3
#define RAYEVTS0_HANDSTAND_DASH 4
#define RAYEVTS0_HANDSTAND 5
#define RAYEVTS0_GRAIN 6
#define RAYEVTS0_GRAP 7

#define FLG_RAYEVTS0_NONE 0

typedef u8 RayEvts_1;
#define RAYEVTS1_RUN 0
#define RAYEVTS1_DEMI 1
#define RAYEVTS1_LUCIOLE 2
#define RAYEVTS1_FORCE_RUN_TOGGLE 3
#define RAYEVTS1_FORCE_RUN 4
#define RAYEVTS1_REVERSE 5
#define RAYEVTS1_FLAG6 6
#define RAYEVTS1_UNUSED_DEATH 7

#define FLG_RAYEVTS1_NONE 0

typedef struct RaymanEvents
{
    RayEvts_0 flags0;
    RayEvts_1 flags1;
} RaymanEvents;

typedef s16 RayMode;
#define MODE_NONE 0
#define MODE_RAYMAN 1
#define MODE_RAY_ON_MS 2
#define MODE_MORT_DE_RAYMAN 3
#define MODE_MORT_DE_RAYMAN_ON_MS 4

/* .data */
extern RaymanEvents PS1_DefaultRayEvts; /* originally in include/main.h */

/**/
extern RaymanEvents RayEvts;
extern RaymanEvents SauveRayEvtsDemo; /* originally in include/demo_9FD4.h */
extern u8 ray_on_poelle;
extern s16 decalage_en_cours;
extern s16 remoteRayXToReach;
extern u8 dead_time;
extern s16 compteur_attente;
extern u8 no_ray_landing_smoke;
extern s16 pos_stack[10];
extern RayMode ray_mode;
extern u8 ray_pos_in_stack;
extern u8 ray_stack_is_full;
extern u8 ray_se_noie;

void allocateRayLandingSmoke(void);
void recale_ray_on_liane(void);
void calc_bhand_typ(Obj *obj);
void IS_RAY_ON_LIANE(void);
void rayMayLandOnAnObject(u8 *param_1, s16 param_2);
void set_air_speed(u8 main_etat, u8 sub_etat, s16 param_3, u8 param_4);
void Reset_air_speed(u8 is_rolling_speed);
void determineRayAirInertia(void);
void ray_jump(void);
void ray_inertia_speed(u32 param_1, s16 param_2, s16 prevSpeedX, s16 param_4);
void RAY_SWIP(void);
void RAY_STOP(void);
void RAY_HELICO(void);
void Make_Ray_Hang(s16 param_1, s16 param_2);
u16 AIR(s32 param_1); /* u16 vs s16 for CAN_RAY_HANG_BLOC? */
u16 MUR(s32 param_1);
void CAN_RAY_HANG_BLOC(void);
void RAY_TOMBE(void);
void RAY_RESPOND_TO_DOWN(void);
void RAY_RESPOND_TO_UP(void);
void RAY_RESPOND_TO_DIR(s16 flip_x);
void RAY_RESPOND_TO_NOTHING(void);
void PS1_RespondShoulderR(void);
void PS1_RespondShoulderL(void);
void RAY_RESPOND_TO_BUTTON4(void);
void RAY_RESPOND_TO_BUTTON3(void);
void RAY_RESPOND_TO_FIRE0(void);
void RAY_RESPOND_TO_FIRE1(void);
s32 RAY_BALANCE_ANIM(s16 param_1);
void abs_sinus_cosinus(s16 tab_index, s16 *param_2, s16 *param_3);
void SET_RAY_BALANCE(void);
void RAY_GOING_BALANCE(Obj *obj);
void RAY_BALANCE(void);
void RAY_FIN_BALANCE(void);
void RayTestBlocSH(void);
void remoteControlRay(void);
void STOPPE_RAY_CONTRE_PAROIS(u8 block);
void RAY_IN_THE_AIR(void);
void terminateFistWhenRayDies(void);
void snifRayIsDead(Obj *rayObj);
void rayfallsinwater(void);
u8 RAY_DEAD(void);
void RAY_HURT(void);
void RepousseRay(void);
s32 RayEstIlBloque(void);
void stackRay(void);
void RAY_SURF(void);
void DO_SURF_CHANGE_HAIRS(void);
void RAY_PREPARE_PIEDS(void);
void DO_PIEDS_RAYMAN(void);
void DO_PIEDS_COLLISION(void);
void allocatePiedBoum(void);
void DO_MORT_DE_RAY(void);

#endif