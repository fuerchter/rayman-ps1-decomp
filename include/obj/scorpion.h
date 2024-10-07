#ifndef SCORPION_H
#define SCORPION_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "common/mapdata.h"
#include "common/record.h"
#include "cam_scroll_29B5C.h"
#include "moteur_init_end.h"
#include "command_56AF0.h"
#include "command_494FC.h"
#include "collision/etat.h"

/* .data */
extern u8 ecroule_rubis_order[24];

/* .data */
extern s16 D_801C83A4[8];
extern s16 D_801C83B4[8];

/**/
extern u8 ecroule_rubis_list[8];
extern u8 ecroule_plat_index;
extern s16 rubis_list_calculated;
extern s32 sko_ecran_tremble;
extern s16 sko_ecroule_plat;
extern u8 sko_enfonce_enable;
extern u8 sko_lave_obj[20];
extern u8 sko_nb_lave;
extern s16 sko_pince_obj_id;
extern s16 D_801E4E10;
extern s16 sko_rayon_on;
extern s16 sko_rayon_x;
extern s16 sko_rayon_y;
extern s16 sko_rayon_dx;
extern s16 sko_rayon_dy;
extern s16 sko_final_x;
extern s16 sko_final_y;
extern s32 pixels_enfonce;
extern s16 sko_last_action;
extern s16 sko_nb_frap;
extern s16 sko_nb_hit;
extern s16 sko_phase;

void swap(s32 ind_1, s32 ind_2);
void set_rubis_list(void);
void allocate_rayon(s16 x, s16 y);
void allocate_8_petits_rayons(s16 x, s16 y);
void do_sko_rayon(void);
void do_sko_rayon2(void);
void start_sko_rayon(s16 obj_x, s16 obj_y);
void start_sko_rayon2(s16 obj_x, s16 obj_y);
void lance_pince(Obj *sko_obj);
s32 sko_get_eject_sens(void);
void DO_SOL_ENFONCE(void);
void DO_SKO_PHASE_0(Obj *sko_obj);
void DO_SKO_PHASE_1(Obj *obj);
void DO_SKO_PHASE_2(Obj *obj);
void DO_SKO_PHASE_3(Obj *obj);
void DO_SKO_PINCE(Obj *obj);
void DO_SCORPION_COLLISION(Obj *obj);
void DO_SCORPION_MORT(Obj *obj);
void DO_SKO(Obj *obj);
void SKO_ray_in_zone(Obj *obj);
void DO_SKO_HIT(Obj *obj);

#endif