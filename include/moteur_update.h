#ifndef MOTEUR_UPDATE_H
#define MOTEUR_UPDATE_H

#include "common.h"
#include "common/obj.h"
#include "obj_update.h"
#include "world_map_95CC.h"

extern Obj *star_ray_der;
extern Obj *star_ray_dev;
extern s16 ray_wind_force;
extern s16 weather_wind;
extern s16 D_801F7C90; /* related with ray position but didn't look into yet */
extern s16 D_801F7CA0;
extern u8 PS1_MoteurTime;
extern u8 oldPrio;
extern s16 ray_old_main_etat;
extern s16 ray_old_sub_etat;
extern s16 xmap_old;
extern s16 ymap_old;
extern s16 reduced_rayman_id;
extern u8 D_801F57F0;

void PS1_SetWindForce(void);
void DO_MOTEUR(void);
void DO_MOTEUR2(void);
void RAY_REVERSE_COMMANDS(void);
void RAY_DEMIRAY(void);
void DO_MOTEUR_GELE(void);
void FUN_8015a764(void);

#endif