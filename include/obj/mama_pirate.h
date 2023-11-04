#ifndef MAMA_PIRATE_H
#define MAMA_PIRATE_H

#include "common.h"
#include "obj_update.h"

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
u32 couteau_frame(s16 speedX, s16 speedY);
void update_couteau(Obj *obj);
void get_cou_zdc(Obj *param_1, s16 *param_2, s16 *param_3, s16 *param_4, s16 *param_5);
void pma_attaque_suivante(void);
s32 convertspeed(s16 speed);
void lance_couteau_parabolique(Obj *obj);
void lance_couteau_droit(Obj *param_1);
void retour_couteau(Obj *obj);
void PS1_retour_couteau_old(Obj *obj);
void lance_couteau_lineaire(Obj *param_1);
void DO_COU_COMMAND(Obj *obj);
void calc_pma_dir(Obj *obj);
void DO_PMA_COMMAND(Obj *obj);
void init_mama_pirate(Obj *obj);
void PMA_SORT_DU_CANON(void);
void DO_PMA_POING_COLLISION(Obj *obj);
s32 pma_get_eject_sens(void);
void DO_COU_ATTER(Obj *param_1);
void DO_PMA_ATTER(Obj *param_1);

#endif