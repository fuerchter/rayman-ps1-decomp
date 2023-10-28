#ifndef BB1_H
#define BB1_H

#include "common.h"
#include "obj_update.h"
#include "obj/poing.h"
#include "timers.h"
#include "ray/ray_32398.h"
#include "boss.h"
#include "cam_scroll.h"
#include "num_level_36260.h"

typedef struct BB1Data
{
    s16 speed_x;
    s16 field1_0x2;
    u8 field2_0x4;
    u8 saved_main_etat;
    u8 saved_sub_etat;
    s16 saved_cmd;
    s16 sprite6_x;
    s16 sprite6_y;
    u8 field8_0xe;
} BB1Data;

typedef struct BBAttackEntry
{
    s16 attack;
    u8 wait_for_fin_atan;
} BBAttackEntry;

void DO_TOTEM_TOUCHE(Obj *obj, s16 sprite);
void DO_TOTEM_COMMAND(Obj *param_1);
void DO_TOTBT_REBOND(Obj *obj);
void DO_PI_EXPLOSION2(Obj *obj);
void DO_BBL_REBOND(Obj *obj);
void allocateDog(Obj *bb1Obj);
void allocateTir(Obj *param_1, s16 param_2);
void CreateFirstBBL(void);
void INIT_BBMONT(Obj *obj);
void DO_BBL_COMMAND(Obj *obj);
void BBMONT_ECLAIR(Obj *obj);
void BBMONT_ETINCELLES(Obj *param_1);
void BBMONT_TIRE(Obj *obj);
void Cree_BBL(Obj *obj);
void BB_Attaque(Obj *obj);
void Fin_BB_Attaque(Obj *obj);
void BB_Atan(Obj *obj);
void DO_BBMONT_ATTER(Obj *obj);
void DO_BBMONT_COMMAND(Obj *obj);
void DO_BBMONT_TOUCHE(Obj *obj);
void DO_BBMONT2_COMMAND(Obj *obj);
void DO_BBMONT2_MARCHE(s16 hp);
void DO_BBMONT2_ATTER(Obj *obj);
void DO_BBMONT3_COMMAND(Obj *obj);
void DO_BBMONT3_ATTER(Obj *obj);
void DO_BBMONT4_COMMAND(Obj *obj);

#endif