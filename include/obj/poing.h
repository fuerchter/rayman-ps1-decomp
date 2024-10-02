#ifndef POING_H
#define POING_H

#include "common.h"
#include "collision/etat.h"

typedef struct Poing
{
    s32 field0_0x0;
    s16 field1_0x4;
    s16 speed_x;
    s16 charge;
    s16 field4_0xa;
    u8 sub_etat;
    u8 is_returning;
    u8 is_active;
    u8 damage;
    u8 is_charging;
    u8 is_boum;
} Poing;

/**/
extern s16 poing_obj_id;
extern Poing poing;
extern s16 id_obj_grapped;

void fist_U_turn(Obj *obj, u8 param_2);
void CALC_FIST_POS(void);
void RAY_THROW_FIST(void);
void RAY_PREPARE_FIST(void);
void RAY_GROW_FIST(void);
void fin_poing_follow(Obj *poing_obj, u8 param_2);
void POING_FOLLOW(Obj *poing_obj);
void alter_fist_speed(Obj *obj);
void switch_off_fist(Obj *obj);
void DO_POING(Obj *obj);
void allocatePoingBoum(void);

#endif