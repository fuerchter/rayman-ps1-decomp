#ifndef DARK_729F0_H
#define DARK_729F0_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "moteur_init_end.h"
#include "boss.h"

typedef struct VitrauxInfo
{
    s16 x_pos;
    s16 y_pos;
    u8 obj_id;
    u8 index; /* 0-4 */
    u8 field4_0x6;
    u8 mode; /* 0 is inactive, 1 is getting less bright and 2 is getting brighter */
    u16 value; /* goes from 100 to 0 */
} VitrauxInfo;

/**/
extern u8 dark_phase;

void PlaceDarkPhase1et2(Obj *obj);
void dark_attaque_suivante(void);
void init_vitraux(void);
s32 poing_face_obj(s32 param_1);
void DARK_phase1(Obj *obj);
void DARK_phase3(Obj *obj);
void DO_DARK_COMMAND(Obj *obj);
void DO_DARK_POING_COLLISION(Obj *obj);
void DO_DARK_REACT(Obj *obj);
void DO_DARK_SORT_COMMAND(Obj *param_1, s16 param_2);
void DO_DARK_SORT_COLLISION(Obj *obj);
void allocate_DARK_SORT(s16 x, s16 y, u8 sub_etat, s16 param_4);
void corde_en_bas(void);
void corde_en_haut(u8 param_1);
void init_corde(Obj *obj);
void goto_phase1(Obj *obj);
void goto_phase2(Obj *obj);
void goto_phase3(Obj *param_1);
void goto_phase5(Obj *obj);

#endif