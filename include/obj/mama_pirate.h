#ifndef MAMA_PIRATE_H
#define MAMA_PIRATE_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "common/ray.h"
#include "world_map_677C0.h"
#include "obj/bateau_command.h" /* TODO: circular? */

typedef struct CouteauxInfo
{
    s16 x_pos;
    s16 y_pos;
    s16 field2_0x4;
    s16 field3_0x6;
    s16 field4_0x8;
    s16 field5_0xa;
    s16 field6_0xc;
    u8 field7_0xe;
    u8 active;
    u8 field9_0x10;
    u8 id; /* Created by retype action */
} CouteauxInfo;

/* .data */
extern u8 pma_couteaux[6];
extern u8 pma_sequence[4][2];
extern u8 place_sequence[5];

/**/
extern CouteauxInfo CouteauxInfos[5];
extern u8 pma_attaque;
extern u8 pma_groupe;
extern s16 mama_pirate_obj_id;
extern u8 pma_type_attaque;
extern u8 cou_place;
extern s16 cou_tempo;
extern u8 pma_nb_couteau;
extern u8 pma_phase;
extern s16 pma_tempo;
extern u8 pma_touched;

void pmamaFollowsShip(Obj *obj);
void init_couteaux(void);
void reset_couteaux(void);
u8 check_couteaux(void);
u8 find_couteau(Obj *obj);
s32 x_pos(u8 param_1, u8 nb_couteau);
s32 y_pos(s16 param_1, s16 param_2);
s16 y_floor(s16 x, s16 y);
void init_move_couteau(Obj *obj);
void init_lance_couteau(u8 index);
u8 couteau_frame(s16 spd_x, s16 spd_y);
void update_couteau(Obj *obj);
void get_cou_zdc(Obj *obj, s16 *x, s16 *y, s16 *w, s16 *h);
void pma_attaque_suivante(void);
s16 convertspeed(s16 speed);
void lance_couteau_parabolique(Obj *obj);
void lance_couteau_droit(Obj *obj);
void retour_couteau(Obj *obj);
void PS1_retour_couteau_old(Obj *obj);
void lance_couteau_lineaire(Obj *in_obj);
void DO_COU_COMMAND(Obj *obj);
void calc_pma_dir(Obj *obj);
void DO_PMA_COMMAND(Obj *obj);
void init_mama_pirate(Obj *obj);
void PMA_SORT_DU_CANON(Obj *obj);
void DO_PMA_POING_COLLISION(Obj *obj);
s32 pma_get_eject_sens(Obj *obj);
void DO_COU_ATTER(Obj *obj);
void DO_PMA_ATTER(Obj *obj);

#endif