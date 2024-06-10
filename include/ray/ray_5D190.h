#ifndef RAY_5D190_H
#define RAY_5D190_H

#include "common.h"
#include "common/obj.h"
#include "common/rayevts.h"
#include "collision/block_22C84.h"
#include "main_moteur.h"
#include "obj_init_kill.h"
#include "obj/stonebomb.h"
#include "collision/bit_util.h"
#include "obj_util.h"
#include "obj/black_ray_command.h"
#include "collision/collision.h"
#include "obj/corde.h"

typedef s16 RayMode;
#define MODE_NONE 0
#define MODE_RAYMAN 1
#define MODE_RAY_ON_MS 2
#define MODE_MORT_DE_RAYMAN 3
#define MODE_MORT_DE_RAYMAN_ON_MS 4

/* .data */
extern RaymanEvents PS1_DefaultRayEvts; /* originally in include/main.h */

/**/
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
extern BlockType hand_btyp;
extern BlockType hand_btypd;
extern BlockType hand_btypg;
extern s16 jump_time;
extern s16 helico_time;
extern u8 ray_Suphelico_bis;
extern u8 ray_clic;
extern s16 D_801E62F0;
extern s16 ray_between_clic;
extern s16 D_801F5588;

void allocateRayLandingSmoke(void);
void recale_ray_on_liane(void);
void calc_bhand_typ(Obj *obj);
void IS_RAY_ON_LIANE(void);
void rayMayLandOnAnObject(u8 *param_1, s16 param_2);
void set_air_speed(u8 main_etat, u8 sub_etat, s16 param_3, u8 param_4);
void Reset_air_speed(u8 is_rolling_speed);
void determineRayAirInertia(void);
void ray_jump(void);
void ray_inertia_speed(u8 param_1, s16 param_2, s16 prev_speed_x, s16 param_4);
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
void snifRayIsDead(Obj *ray_obj);
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